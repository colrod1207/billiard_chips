#pragma once
#include"Circulo.h"
class Fichadecolor:public Circulo {
private:
	int aux;
	int color;

public:
	Fichadecolor(Graphics^ g, int x, int y) :Circulo(x, y, dx, dy) {
		aux = rand() % 2;

		if (aux == 0)
			dx = -5;
		else dx = 5;

		aux = rand() % 2;

		if (aux == 0)
			dy = -5;
		else dy = 5;

		this->x = x;
		this->y =y;

		color = rand() % 7;
	}
	~Fichadecolor(){}

	void dibujar(Graphics^ g) {
		if(color==0)
			g->FillEllipse(Brushes::Blue, x, y, radio, radio);
		else if(color==1)
			g->FillEllipse(Brushes::Aqua, x, y, radio, radio);
		else if (color == 2)
			g->FillEllipse(Brushes::Yellow, x, y, radio, radio);
		else if (color == 3)
			g->FillEllipse(Brushes::Red, x, y, radio, radio);
		else if (color == 4)
			g->FillEllipse(Brushes::Purple, x, y, radio, radio);
		else if (color == 5)
			g->FillEllipse(Brushes::White, x, y, radio, radio);
		else if (color == 6)
			g->FillEllipse(Brushes::Orange, x, y, radio, radio);
	}

	void mover(Graphics^ g) {
		x += dx;
		y += dy;
		if (x + radio > g->VisibleClipBounds.Width || x < 0) dx *= -1;
	}

	int getY() { return y; }

	void cambiardx() {
		dx = dx * -1;
	}
	void cambiardy() {
		dy = dy * -1;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, radio, radio);
	}
};