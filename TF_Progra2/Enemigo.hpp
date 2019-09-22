#pragma once

#include "Objeto.hpp"

class Enemigo : public Objeto
{
private:
	int salud2;
	int clase;
	int velocidad;

	int cadencia;

	int contador;

public:
	Enemigo()
	{
		//Diferentes clases de enemigos, las clases son aleatorias
		clase = 1 + rand() % 3;
		contador = 0;
		switch (clase)
		{

		case 1:
			x = 2 + rand() % (MAX_X - 100);
			y = 2 + rand() % (MAX_Y - 100);
			dx = 1 * (-1 + 2 * (rand() % 2));
			dy = 1 * (-1 + 2 * (rand() % 2));
			ancho = 50;
			alto = 50;
			salud2 = 40;
			break;

		case 2:
			x = 2 + rand() % (MAX_X - 100);
			y = 2 + rand() % (MAX_Y - 100);
			dx = 1 * (-1 + 2 * (rand() % 2));
			dy = 1 * (-1 + 2 * (rand() % 2));
			ancho = 80;
			alto = 80;
			salud2 = 100;

			cadencia = 100;
			break;
		case 3:
			x = 2 + rand() % (MAX_X - 100);
			y = 2 + rand() % (MAX_Y - 100);
			dx = 1 * (-1 + 2 * (rand() % 2));
			dy = 1 * (-1 + 2 * (rand() % 2));
			ancho = 70;
			alto = 70;
			salud2 = 80;

			cadencia = 200;
			break;

		default:		break;
		}

		c = f = 0;

	}

	Enemigo(int n)
	{
		clase = 1 + rand() % 3;
		contador = 0;
		switch (clase)
		{
			//Determina parametros segun la clase
		case 1:
			x = 1 + rand() % (MAX_X - 100);
			y = 1 + rand() % (MAX_Y - 100);
			dx = 5 * (-1 + 2 * (rand() % 2));
			dy = 5 * (-1 + 2 * (rand() % 2));
			ancho = 50;
			alto = 50;
			salud2 = 40 + (4 * n);
			break;

		case 2:
			x = 1 + rand() % (MAX_X - 100);
			y = 1 + rand() % (MAX_Y - 100);
			dx = 2 * (-1 + 2 * (rand() % 2));
			dy = 2 * (-1 + 2 * (rand() % 2));
			ancho = 80;
			alto = 80;
			salud2 = 100 + (10 * n);

			cadencia = 300;
			break;
		case 3:
			x = 1 + rand() % (MAX_X - 100);
			y = 1 + rand() % (MAX_Y - 100);
			dx = 4 * (-1 + 2 * (rand() % 2));
			dy = 4 * (-1 + 2 * (rand() % 2));
			ancho = 70;
			alto = 70;
			salud2 = 80 + (8 * n);

			cadencia = 500;
			break;

		default:		break;
		}

		c = f = 0;

	}

	void DibujarE(BufferedGraphics^ bg, Bitmap^ sprite)
	{

		switch (clase)
		{
		case 1:

			bg->Graphics->DrawEllipse(gcnew Pen(Color::Black, 4), x, y, ancho, alto);
			bg->Graphics->FillEllipse(Brushes::Green, x, y, ancho, alto);
			break;


		default:	bg->Graphics->DrawImage(sprite, x, y, ancho, alto); 	break;
		}

		String^ a = salud2.ToString();

		//Dibuja vida de enemigos

		System::Drawing::Font^ f = gcnew System::Drawing::Font("Consolas", 12);

		bg->Graphics->DrawString(a, f, Brushes::GreenYellow, x + ancho / 2 - 10, y + alto / 2 - 10);

	}

	//Mueve a los enemigos

	void MoverE(function<int(int, int)> sumar = [](int a, int b) {return a + b; })
	{
		if (sumar(x, dx) > MAX_X - 30 || sumar(x, dx) < 0)
		{
			dx *= -1;
		}
		if (sumar(y, dy) > MAX_Y - 30 || sumar(y, dy) < 0)
		{
			dy *= -1;
		}

		x = sumar(x, dx);
		y = sumar(y, dy);
	}



	int getsalud2() { return salud2; }
	int getclase() { return clase; }
	int getcontador() { return contador; }
	int getcadencia() { return contador; }

	void setsalud2(int salud2) { this->salud2 = salud2; }
	void setcontador(int contador) { this->contador = contador; }
};