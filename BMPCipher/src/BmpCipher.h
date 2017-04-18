#pragma once
#include <Windows.h>
#include <string>
#include <vector>

class BmpCipher
{
private:
	BITMAPFILEHEADER fileHeader_;
	BITMAPINFOHEADER infoHeader_;
	std::vector<std::vector<RGBTRIPLE>> rgb_;
	bool isLoad_;
	std::string fileName_;
public:
	BmpCipher() :isLoad_(false){};
	BmpCipher(const std::string);
	void loadFile(const std::string);
	void saveFile();
	void saveFile(const std::string);
	void encrypt(const std::string);
	void decrypt(const std::string);
	bool isLoad();
	~BmpCipher(){};
};

