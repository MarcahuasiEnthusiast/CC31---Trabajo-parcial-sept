#pragma once

#include "Objeto.hpp"

class Bala : public Objeto
{
private:
	int tipo;
	double angulo;
	int daño;
	int choque;



public:
	Bala()
	{

	}

	///Diferentes clases de bala

	Bala(int type, int X, int Y, int nivel)
	{
		x = X;
		y = Y;
		tipo = type;
		angulo = 0;
		choque = 0;

		if (type == 1)
		{
			dx = 7;
			dy = 7;
			ancho = 25;
			alto = 25;
			daño = 1000;
		}
		else if (type == 2)
		{
			dx = 9;
			dy = 9;
			ancho = 20;
			alto = 20;
			daño = 1000;
		}
		else if (type == 3)
		{
			dx = 12;
			dy = 12;
			ancho = 15;
			alto = 15;
			daño = 1000;
		}
		else if (type == 4)
		{
			//balaparaenemigo
			dx = 10;
			dy = 10;
			ancho = 20;
			alto = 20;
			daño = 1000;
		}
		else if (type == 5)
		{
			//balaparaenemigo
			dx = 8;
			dy = 8;
			ancho = 30;
			alto = 30;
			daño = 1000;
		}
		hitbox = Rectangle(x, y, ancho, alto);
	}

	int getdaño() { return daño; }
	int gettipo() { return tipo; }
	int getchoque() { return choque; }

	void setdaño(int daño) { this->daño = daño; }
	void setchoque(int cho) { this->choque = cho; }

	void dibujarBala(BufferedGraphics^ bg, Bitmap^ sprite)
	{


		bg->Graphics->DrawImage(sprite, x, y, ancho, alto);


	}


	void mover()
	{

		x += dx;
		y += dy;
	}


	//AVERIGUA EL ANGULO DE DIRECCIÓN

	void setAngulo(int nx, int ny, function<int(int, int)> comparar = [](int a, int b) {return a - b; })
	{
		if (comparar(nx, x) != 0)
		{
			if (comparar(nx, x) > 0)
			{

				angulo = atan((double)(ny - y) / (double)(nx - x));
				dx = dx;

			}
			else
			{
				angulo = atan((double)(ny - y) / (double)(nx - x));
				dx = -dx;
			}

			//cout << angulo << endl;

			dy = dx * tan(angulo);
		}
		else
		{
			if (comparar(nx, x) > 0)
			{

				angulo = 90;
				dx = dx - 1;

			}
			else
			{
				angulo = 270;
				dx = -dx + 1;
			}

			dy = dx * angulo;
		}



	}

	int getclase() { return tipo; }

};