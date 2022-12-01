#pragma once
#include <iostream>
using namespace System;
using namespace System::Drawing;
using namespace std;
class Circulo {
protected:
	int x, y, dx, dy,radio;
public:
	Circulo(int x, int y, int dx, int dy) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		radio = 50;
	}

	~Circulo() {}

	
};