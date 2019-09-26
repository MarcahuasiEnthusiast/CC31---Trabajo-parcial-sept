#pragma once

////Esto seria las pilas y colas


#include "Objeto.hpp"
#include "Bala.hpp"
#include "Municion.hpp"
#include "ColeccionBala.hpp"
#include "Pilas.hpp"

class BarraMunicion : public Municion
{
private:
	Pila <Municion*>* Barra1 = new Pila<Municion*>;
	int X;
	int Y;

public:

	BarraMunicion()
	{
		X = 0;
		Y = 0;

	}

	Pila <Municion*>* returnB1()
	{
		return Barra1;
	}

	void DibujarBarra1(BufferedGraphics^ bg)
	{
		Bitmap^ sprite;


		bg->Graphics->DrawRectangle(Pens::DarkBlue, 0, 0, 50, 30);
		bg->Graphics->FillRectangle(Brushes::Aqua, 0, 0, 50, 29);


		for (int i = 0; i < Barra1->getLen(); ++i)
		{
			switch (Barra1->top()->gettipo())
			{
			case 1:
				sprite = gcnew Bitmap("bala1.png");
				break;
			case 2:
				sprite = gcnew Bitmap("bala2.png");
				break;
			case 3:
				sprite = gcnew Bitmap("bala3.png");
				break;

			default:		break;
			}

			Barra1->top()->dibujarMun(bg, sprite);
		}
	}


	int TamañoBarra()
	{
		return Barra1->getLen();
	}



};


class BarraColeccion : public Municion
{
private:
	Pila <Municion*>* Barra2 = new Pila<Municion*>;
	int X;
	int Y;

public:

	BarraColeccion()
	{
		X = 0;
		Y = 30;

	}

	Pila <Municion*> * returnB2()
	{
		return Barra2;
	}


	void DibujarBarra2(BufferedGraphics^ bg)
	{
		Bitmap^ sprite;

		bg->Graphics->DrawRectangle(Pens::DarkBlue, 0, 30, 50, 40);
		bg->Graphics->FillRectangle(Brushes::Turquoise, 0, 30, 50, 39);

		for (int i = 0; i < Barra2->getLen(); ++i)
		{
			switch (Barra2->top()->gettipo())
			{
			case 4:
				sprite = gcnew Bitmap("cora.png");
				break;
			case 5:
				sprite = gcnew Bitmap("burguer.png");
				break;
			case 6:
				sprite = gcnew Bitmap("pocion.png");
				break;

			default:		break;
			}

			Barra2->top()->dibujarMun(bg, sprite);
		}
	}


	int TamañoBarra2()
	{
		return Barra2->getLen();
	}



};