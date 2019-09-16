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


	void dibujarBala(BufferedGraphics^ bg, Bitmap^ sprite)
	{


		bg->Graphics->DrawImage(sprite, x, y, ancho, alto);


	}

	void Push(int T)
	{

		Barra1.push_back(Municion(X, Y,	T));

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

	}

	void DibujarBarra1(BufferedGraphics^ bg)
	{
		Bitmap^ sprite;
		


		for (int i = 0; i < Barra1.size(); ++i)
		{
			switch(Barra1[i].gettipo())
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
