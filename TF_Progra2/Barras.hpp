#pragma once

////Esto seria las pilas y colas


#include "Objeto.hpp"
#include "Bala.hpp"
#include "Municion.hpp"
#include "ColeccionBala.hpp"

class BarraMunicion : public Municion
{
private:
	vector <Municion> Barra1;
	int X;
	int Y;

public:

	BarraMunicion()
	{
		X = 0;
		Y = 0;

	}


	void Push(int T)
	{

		Barra1.push_back(Municion(X, Y, T));

		X += 30;


	}


	int Pop()
	{
		return Barra1[0].gettipo();

	}

	void PopErase()
	{
		Barra1.erase(Barra1.begin());

		for (int i = 0; i < Barra1.size(); ++i)
		{
			Barra1[i].setx(Barra1[i].getx() - 30);
		}

		if (Barra1.size() == 0)
		{
			X = 0;
		}

	}

	void DibujarBarra1(BufferedGraphics^ bg)
	{
		Bitmap^ sprite;


		bg->Graphics->DrawRectangle(Pens::DarkBlue, 0, 0, MAX_X, 30);
		bg->Graphics->FillRectangle(Brushes::Aqua, 0, 0, MAX_X, 29);


		for (int i = 0; i < Barra1.size(); ++i)
		{
			switch (Barra1[i].gettipo())
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

			Barra1[i].dibujarMun(bg, sprite);
		}
	}


	int TamañoBarra()
	{
		return Barra1.size();
	}



};


class BarraColeccion : public Municion
{
private:
	vector <Municion> Barra2;
	int X;
	int Y;

public:

	BarraColeccion()
	{
		X = 0;
		Y = 30;

	}


	void Push(int T, int V)
	{

		Barra2.push_back(Municion(X, Y, T, V));

		X += 30;


	}


	int Pop()
	{
		if (Barra2.size() != 0)
		{
			cout << Barra2[Barra2.size() - 1].getvida();
			return Barra2[Barra2.size() - 1].getvida();

		}


	}

	void PopErase()
	{
		Barra2.erase(Barra2.end() - 1);

		for (int i = 0; i > Barra2.size(); --i)
		{
			Barra2[i].setx(Barra2[i].getx() - 30);
		}

		if (Barra2.size() == 0)
		{
			X = 0;
		}

	}

	void DibujarBarra2(BufferedGraphics^ bg)
	{
		Bitmap^ sprite;

		bg->Graphics->DrawRectangle(Pens::DarkBlue, 0, 30, MAX_X, 40);
		bg->Graphics->FillRectangle(Brushes::Turquoise, 0, 30, MAX_X, 39);

		for (int i = 0; i < Barra2.size(); ++i)
		{
			switch (Barra2[i].gettipo())
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

			Barra2[i].dibujarMun(bg, sprite);
		}
	}


	int TamañoBarra2()
	{
		return Barra2.size();
	}



};