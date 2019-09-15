#pragma once

#include "Objeto.hpp"
#include "Municion.hpp"

class ColeccionMunicion : public Municion
{
private:
	vector <Municion> Mu;

public:

	ColeccionMunicion()
	{
		for (int i = 0; i < 6; ++i)
		{
			Mu.push_back(Municion());
		}
	}

	void crearColeccionEnemigos(int niv)
	{
		if (niv == 1)
		{
			for (int i = 0; i < 8; ++i)
			{
				Mu.push_back(Municion());
			}
		}
		else if (niv == 2)
		{
			for (int i = 0; i < 10; ++i)
			{
				Mu.push_back(Municion());
			}
		}
		else if (niv == 3)
		{
			for (int i = 0; i < 12; ++i)
			{
				Mu.push_back(Municion());
			}
		}


	}


	void DibujarMunicion(BufferedGraphics^ bg)
	{
		Bitmap^ sprite;

		for (int i = 0; i < Mu.size(); ++i)
		{
			switch (Mu[i].gettipo())
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

			Mu[i].dibujarMun(bg, sprite);
		}

	}


	int cantidadMunicion()
	{
		return Mu.size();

	}

	void EliminarMun(int k)
	{
		Mu.erase(Mu.begin() + k);
	}

	Rectangle RectanguloMun(int l)
	{
		return Rectangle(Mu[l].getx(), Mu[l].gety(), Mu[l].getancho(), Mu[l].getalto());
	}

	Municion ReturnMun(int l)
	{
		return Mu.at(l);
	}


};