#pragma once
#include <iostream>

using namespace std;

class Rectangle {
	int width;
	int length;
public:
	int getWidth();
	int getLength();
	void setLength();
	void setWidth();
	void getArea();
	void rotateRectangle(Rectangle obj);
	void draw();
};
