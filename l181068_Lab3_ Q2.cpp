#include <iostream>
#include "Rectangle.h"

using namespace std;

void Rectangle::setLength() { // Declaring function from header file
	cout << "Enter the length for your rectangle: ";
	cin >> length;
	cout << endl;
}

int Rectangle::getLength() {
	return length;
}

void Rectangle::setWidth() {
	cout << "Enter the width for your rectangle:";
	cin >> width;
	cout << endl;
}

int Rectangle::getWidth() {
	return width;
}


void Rectangle::getArea() {
	cout << "The area for your rectangle is :" << width * length;
}

void Rectangle::rotateRectangle(Rectangle obj) {
	//Making a Swap Function
	int temp;
	temp = obj.width;
	obj.width = obj.length;
	obj.length = temp;

	cout << "New width is :" << obj.length;
	cout << "New length is :" << obj.width;
}

void Rectangle::draw() {
	for (int i = 0; i < length; i++) { 
		for (int j = 0; j < width; j++) {
			cout << "*";
		}
		cout << endl;
	}
}


int main() {

	// Making the Menu in main 
	int key = 0;
	for (int i = 0; key != -1; i++) {
		Rectangle obj; // Declaring Object to Class
		cout << "Press 1 to Enter length" << endl;
		cout << "Press 2 to Enter width" << endl;
		cout << "Press 3 to see your current length and Width" << endl;
		cout << "Press 4 to Rotate your rectangle" << endl;
		cout << "Press 5 to calculate area for your rectangle" << endl;
		cout << "Press 6 to Draw your rectangle" << endl;
		cout << "Press -1 to exit" << endl;
		cin >> key;
		// Declaring different conditions for different values given by the user

		if (key == 1) {
			obj.setLength();
			cout << endl;
			cout << endl;
		}
		else if (key == 2) {
			obj.setWidth();
			cout << endl;
			cout << endl;
		}
		else if (key == 3) {
			int w = obj.getWidth();
			cout << "The width for your rectangle is: " << w << endl;
			int l = obj.getLength();
			cout << "The length for your rectangle is: " << l << endl;
		}
		else if (key == 4) {
			obj.rotateRectangle(obj);
			cout << endl;
			cout << endl;
		}
		else if (key == 5) {
			obj.getArea();
			cout << endl;
			cout << endl;
		}
		else if (key == 6) {
			obj.draw();
			cout << endl;
			cout << endl;
		}
	}
	system("pause");
}