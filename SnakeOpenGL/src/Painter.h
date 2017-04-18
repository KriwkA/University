#pragma once
class Painter
{
public:
	enum Color {RED,GREEN,BLUE};
	void drowRect(double, double, double, double); 
	void SetColor(Color);
};

