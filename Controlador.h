#pragma once
#include"Agujeronegro.h"
#include"Fichadecolor.h"
#include<vector>
class Controlador {
private:
	vector<Agujeronegro*>agujero;
	vector<Fichadecolor*>ficha;
	int max;
public:
	Controlador(Graphics^ g,int a) {
		crearagujero(g);
		max = a;
	}
	~Controlador() {};

	void crearagujero(Graphics^ g) {

		/*Agujeronegro* a = new Agujeronegro(0, 0);
		agujero.push_back(a);*/

		//Creo 6 agujeros negros
		agujero.push_back(new Agujeronegro(0, 0));
		agujero.push_back(new Agujeronegro(0, (g->VisibleClipBounds.Height / 2) - 25));
		agujero.push_back(new Agujeronegro(0, g->VisibleClipBounds.Height - 50));
		agujero.push_back(new Agujeronegro(g->VisibleClipBounds.Width - 50, 0));
		agujero.push_back(new Agujeronegro(g->VisibleClipBounds.Width - 50, (g->VisibleClipBounds.Height / 2) - 25));
		agujero.push_back(new Agujeronegro(g->VisibleClipBounds.Width - 50, g->VisibleClipBounds.Height - 50));
	}

	void crearficha(Graphics^ g,int x,int y) {

		ficha.push_back(new Fichadecolor(g, x, y));
		max--;

		for (int i = 0; i < ficha.size()-1; i++) {
			if (ficha[ficha.size() - 1]->getRectangle().IntersectsWith(ficha[i]->getRectangle())) {
				ficha.erase(ficha.begin() + ficha.size() - 1);
				max++;
			}
			
		}
	}

	void eliminarficha(Graphics^ g) {
		for (int i = 0; i < ficha.size(); i++) {
			if (ficha[i]->getY() > g->VisibleClipBounds.Height || ficha[i]->getY() < 0) {
				ficha.erase(ficha.begin() + i);
			}
		}

	}

	void colision() {

		//colision con los 6 agujeros
		for (int i = 0; i < ficha.size(); i++) {
			
			
				if (ficha[i]->getRectangle().IntersectsWith(agujero[0]->getRectangle())) {
					ficha.erase(ficha.begin() + i);
				}
				else if (ficha[i]->getRectangle().IntersectsWith(agujero[1]->getRectangle())) {
					ficha.erase(ficha.begin() + i);
				}
				else if (ficha[i]->getRectangle().IntersectsWith(agujero[2]->getRectangle())) {
					ficha.erase(ficha.begin() + i);
				}
				else if (ficha[i]->getRectangle().IntersectsWith(agujero[3]->getRectangle())) {
					ficha.erase(ficha.begin() + i);
				}
				else if (ficha[i]->getRectangle().IntersectsWith(agujero[4]->getRectangle())) {
					ficha.erase(ficha.begin() + i);
				}
				else if (ficha[i]->getRectangle().IntersectsWith(agujero[5]->getRectangle())) {
					ficha.erase(ficha.begin() + i);
				}
		}
	}

	void rebotar() {
		for (int i = 0; i < ficha.size(); i++) {
			for (int j = 0; j < ficha.size(); j++) {
				if (i != j) {
					if (ficha[i]->getRectangle().IntersectsWith(ficha[j]->getRectangle())) {
						ficha[i]->cambiardy();
						ficha[i]->cambiardx();
					}
				}
			}
		}
		
	}
	void movertodo(Graphics^ g) {
		for (int i = 0; i < ficha.size(); i++) {
			ficha[i]->mover(g);
		}
	}

	void dibujartodo(Graphics^ g) {
		for (int i = 0; i < ficha.size(); i++) {
			ficha[i]->dibujar(g);
		}
		for (int i = 0; i < agujero.size(); i++) {
			agujero[i]->dibujar(g);
		}
		Font^ lapiz = gcnew Font("Cooper Black", 13);
		g->DrawString("Fichas disponibles: ", lapiz, Brushes::SkyBlue, 300, g->VisibleClipBounds.Height-30);
		g->DrawString(Convert::ToString(max), lapiz, Brushes::SkyBlue, 500, g->VisibleClipBounds.Height - 30);
	}

	vector<Fichadecolor*> getficha() {
		return ficha;
	}
	int getmax() { return max; }
};