#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <functional>

#define MAX_X 1280
#define MAX_Y 840

#define MIN_X 2
#define MIN_Y 60

using namespace std;
using namespace System;
using namespace System::Drawing;

//TODOS HEREDAN DE LA CLASE OBJETO

//ESTO ES UNA PRUEBA DE GITHUB PAPA

class Objeto

{
protected:
	int		x;
	int		y;
	float		dx;
	float		dy;
	int		ancho;
	int		alto;
	Rectangle	hitbox;

	int c;
	int f;
	int anchoI;
	int altoI;

public:

	int		getx() { return x; }
	int		gety() { return y; }
	int		getdx() { return dx; }
	int		getdy() { return dy; }
	int		getancho() { return ancho; }
	int		getalto() { return alto; }
	Rectangle	gethitbox() { return hitbox; }


	void setx(int		x) { this->x = x; }
	void sety(int		y) { this->y = y; }
	void setdx(int		dx) { this->dx = dx; }
	void setdy(int		dy) { this->dy = dy; }
	void setancho(int		ancho) { this->ancho = ancho; }
	void setalto(int		alto) { this->alto = alto; }
	void sethitbox(Rectangle		hitbox) { this->hitbox = hitbox; }

	int getc() { return c; }
	int getf() { return	f; }
	int getanchoI() { return	anchoI; }
	int getaltoI() { return	altoI; }

	void setc(int c) { this->c = c; }
	void setf(int f) { this->f = f; }
	void setanchoI(int anchoI) { this->anchoI = anchoI; }
	void setaltoI(int altoI) { this->altoI = altoI; }
};