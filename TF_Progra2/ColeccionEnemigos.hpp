#pragma once

#include "Objeto.hpp"
#include "Enemigo.hpp"
#include "Personaje.hpp"
#include "Listas.hpp"

class ColeccionEnemigos : public Enemigo
{
private:
	vector <Enemigo> En;


public:

	ColeccionEnemigos()
	{
		for (int i = 0; i < 6; ++i)
		{
			En.push_back(Enemigo());
		}
	}

	void crearColeccionEnemigos(int niv)
	{
		if (niv == 1)
		{
			for (int i = 0; i < 8; ++i)
			{
				En.push_back(Enemigo(niv));
			}
		}
		else if (niv == 2)
		{
			for (int i = 0; i < 10; ++i)
			{
				En.push_back(Enemigo(niv));
			}
		}
		else if (niv == 3)
		{
			for (int i = 0; i < 12; ++i)
			{
				En.push_back(Enemigo(niv));
			}
		}


	}


	void DibujarEnemigos(BufferedGraphics^ bg)
	{
		Bitmap^ sprite;

		for (int i = 0; i < En.size(); ++i)
		{
			switch (En[i].getclase())
			{
			case 2:
				sprite = gcnew Bitmap("enemigo2.png");
				break;
			case 3:
				sprite = gcnew Bitmap("enemigo1.png");
				break;

			default:		break;
			}

			En[i].DibujarE(bg, sprite);
		}

	}


	int cantidadEnemigos()
	{
		return En.size();

	}

	void MoverEnemigos()
	{
		for (int i = 0; i < En.size(); ++i)
		{
			En[i].MoverE();
		}
	}

	void EliminarE(int k)
	{
		En.erase(En.begin() + k);
	}

	int TamañoE()
	{
		return En.size();
	}

	Rectangle RectanguloEn(int l)
	{
		return Rectangle(En[l].getx(), En[l].gety(), En[l].getancho(), En[l].getalto());
	}

	Enemigo ReturnEnemigo(int l)
	{
		return En.at(l);
	}

	void destruir(Jugador* Ju)
	{
		for (int i = 0; i < En.size(); ++i)
		{
			if (En[i].getsalud2() <= 0)
			{
				En.erase(En.begin() + i);
				Ju->setsalud(Ju->getsalud() + 50);

			}
		}
	}

	void SetSalud(int i, int nuevo)
	{
		En[i].setsalud2(nuevo);
	}

	int GetSalud(int i)
	{
		return En[i].getsalud2();
	}

	void SetContador(int i, int nuevo)
	{
		En[i].setcontador(nuevo);
	}

	int GetCademcia(int i)
	{
		return En[i].getcadencia();
	}

	int GetContador(int i)
	{
		return En[i].getcontador();
	}
};