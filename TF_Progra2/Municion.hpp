#pragma once

#include "Objeto.hpp"

class Municion : public Objeto
{
protected:
	int tipo;
	int choque;
	int enbarra;

public:



	///Diferentes clases de muncion

	Municion()
	{
		tipo = 1 + rand() % 3;;
		choque = 0;
		enbarra = 0;
		x = 2 + rand() % (MAX_X - 100);
		y = 2 + rand() % (MAX_Y - 100);

		if (tipo == 1)
		{
		
			ancho = 25;
			alto = 25;

		}
		else if (tipo == 2)
		{
		
			ancho = 20;
			alto = 20;

		}
		else if (tipo == 3)
		{
	
			ancho = 15;
			alto = 15;

		}


		hitbox = Rectangle(x, y, ancho, alto);
	}


	Municion(int X, int Y, int t)
	{
		tipo = t;
		choque = 2;
		enbarra = 1;
		ancho = 25;
		alto = 25;
		x = X;
		y = Y;

	}

	int gettipo() { return tipo; }
	int getchoque() { return choque; }
	int getbarra() { return enbarra; }

	void setchoque(int cho) { this->choque = cho; }
	void setenbarra(int enbarr) { this->enbarra = enbarr; }

	void dibujarMun(BufferedGraphics^ bg, Bitmap^ sprite)
	{

		bg->Graphics->DrawImage(sprite, x, y, ancho, alto);

	}


};