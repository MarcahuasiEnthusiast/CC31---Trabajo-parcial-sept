#pragma once

#include "Objeto.hpp"

class Jugador : public Objeto
{
private:
	int nivel;
	int salud;
	int vidas;

	int tamaño;




	Rectangle sVisible;
	Rectangle C;

public:

	Jugador()
	{
		Bitmap^ sprite = gcnew Bitmap("Goku1.png");

		x = MAX_X / 2;
		y = MAX_Y / 2;

		dx = 5;
		dy = 5;

		salud = 1000;

		ancho = sprite->Width;
		alto = sprite->Height;

		anchoI = sprite->Width / 4;
		altoI = sprite->Height / 4;



		c = f = 0;


	}

	void DibujarJ(BufferedGraphics^ bg)
	{
		Bitmap^ sprite;

		//Cambia de sprite por nivel

		sprite = gcnew Bitmap("Goku1.png");


		sVisible = Rectangle(anchoI * c, altoI * f, anchoI, altoI);


		C = Rectangle(x, y, anchoI, altoI);
		bg->Graphics->DrawImage(sprite, C, anchoI * c, altoI * f, anchoI, altoI, GraphicsUnit::Pixel);



		//Imprime la vida del personaje

		String^ a = salud.ToString();

		System::Drawing::Font^ f = gcnew System::Drawing::Font("Consolas", 12);

		bg->Graphics->DrawString(a, f, Brushes::Red, x + anchoI / 2 - 6, y + altoI / 2 - 20);

	}

	Rectangle RectanguloJu()
	{
		return Rectangle(x, y, anchoI, altoI);
	}

	int getsalud() { return salud; }
	int getancho() { return ancho; }
	int getalto() { return alto; }

	void setancho(int ancho) { this->ancho = ancho; }
	void setalto(int alto) { this->alto = alto; }

	void setsalud(int salud) { this->salud = salud; }

};