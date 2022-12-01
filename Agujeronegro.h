#pragma once
#include"Circulo.h"
class Agujeronegro :public Circulo {
private:

public:
	Agujeronegro(int x,int y) :Circulo(x, y, dx, dy) {
		dx = dy = 0;
		this->x = x;
		this->y = y;
	}
	~Agujeronegro() {}

	void dibujar(Graphics^ g) {
		g->FillEllipse(Brushes::Black, x, y, radio, radio);
	}
	Rectangle getRectangle() {
		return Rectangle(x, y, radio, radio);
	}
};