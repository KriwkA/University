#include "BmpCipher.h"
#include <fstream>

BmpCipher::BmpCipher(const std::string _fileName) : isLoad_(false), fileName_(_fileName)
{
	int err = 0;
	std::ifstream fin(fileName_,std::ios::in | std::ios::binary);
	fin.read(reinterpret_cast<char*>(&fileHeader_), sizeof(BITMAPFILEHEADER));
	fin.read(reinterpret_cast<char*>(&infoHeader_), sizeof(BITMAPINFOHEADER));
	rgb_.resize(infoHeader_.biHeight);
	std::ios::pos_type pos = fin.tellg();
	for (size_t i = 0; i < infoHeader_.biHeight; i++)
	{
		rgb_[i].resize(infoHeader_.biWidth + 1);
		for (size_t j = 0; j <= infoHeader_.biWidth; j++)
			fin.read((char*)(&rgb_[i][j]), sizeof(RGBTRIPLE));
	}
	isLoad_ = true;
	fin.close();
}

void BmpCipher::loadFile(const std::string _fileName)
{
	this->BmpCipher::BmpCipher(_fileName);
}

void BmpCipher::saveFile(const std::string _fileName)
{
	std::ofstream fout(_fileName, std::ios::out | std::ios::binary);
	fout.write(reinterpret_cast<char*>(&fileHeader_), sizeof(BITMAPFILEHEADER));
	fout.write(reinterpret_cast<char*>(&infoHeader_), sizeof(BITMAPINFOHEADER));
	for (size_t i = 0; i < infoHeader_.biHeight; i++)
		for (size_t j = 0; j <= infoHeader_.biWidth; j++)
			fout.write((char*)(&rgb_[i][j]), sizeof(RGBTRIPLE));
	fout.close();
}

void BmpCipher::saveFile()
{
	this->BmpCipher::saveFile(fileName_);
}

bool BmpCipher::isLoad()
{
	return isLoad_;
}

RGBTRIPLE charToColor(const char& c, const RGBTRIPLE& rgb)
{
	int r = (rgb.rgbtRed / 10) * 10 + (c / 100) % 10;
	int g = (rgb.rgbtGreen / 10) * 10 + (c / 10) % 10;
	int b = (rgb.rgbtBlue / 10) * 10 + c % 10;
	if (r > 255) r -= 10;
	if (g > 255) g -= 10;
	if (b > 255) b -= 10;
	RGBTRIPLE color;
	color.rgbtRed = r;
	color.rgbtGreen = g;
	color.rgbtBlue = b;
	return color;
}

char colorToChar(const RGBTRIPLE& rgb)
{
	return rgb.rgbtRed % 10 * 100 + rgb.rgbtGreen % 10 * 10 + rgb.rgbtBlue % 10;
}

void BmpCipher::encrypt(const std::string _textFileName)
{
	std::ifstream fin(_textFileName);
	char c;
	for (size_t i = 0; i < infoHeader_.biHeight; i++)
		for (size_t j = 0; j < infoHeader_.biWidth; j++)
		{
			fin.get(c);
			if (fin.eof())
			{
				rgb_[i][j] = charToColor(27, rgb_[i][j]);
				return;
			}
			rgb_[i][j] = charToColor(c, rgb_[i][j]);
		}
}

void BmpCipher::decrypt(const std::string _textFileName)
{
	std::ofstream fout(_textFileName);
	char c;
	for (size_t i = 0; i < infoHeader_.biHeight; i++)
		for (size_t j = 0; j < infoHeader_.biWidth; j++)
		{
			c = colorToChar(rgb_[i][j]);
			if (c == 27)
			{
				fout.close();
				return;
			}
			fout.put(c);
		}
	fout.close();
}