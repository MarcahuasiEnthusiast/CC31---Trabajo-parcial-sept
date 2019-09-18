#pragma once

#include "Objeto.hpp"
#include "Enemigo.hpp"
#include "Personaje.hpp"

#include "Lista.hpp"


class ColeccionEnemigos : public Enemigo
{
private:
	list <Enemigo> * En = new list <Enemigo>;

public:

	ColeccionEnemigos()
	{
		for (int i = 0; i < 6; ++i)
		{
			En->agregaInicial(Enemigo());
		}
	}

	void crearColeccionEnemigos(int niv)
	{
		if (niv == 1)
		{
			for (int i = 0; i < 8; ++i)
			{
				En->agregaInicial(Enemigo(niv));
			}
		}
		else if (niv == 2)
		{
			for (int i = 0; i < 10; ++i)
			{
				En->agregaInicial(Enemigo(niv));
			}
		}
		else if (niv == 3)
		{
			for (int i = 0; i < 12; ++i)
			{
				En->agregaInicial(Enemigo(niv));
			}
		}


	}

	void DibujarEnemigos(BufferedGraphics^ bg)
	{
		Bitmap^ sprite;

		for (int i = 0; i < En->longitud(); ++i)
		{
			switch (En->obtenerPos(i).getclase())
			{
			case 2:
				sprite = gcnew Bitmap("enemigo2.png");
				break;
			case 3:
				sprite = gcnew Bitmap("enemigo1.png");
				break;

			default:		break;
			}

			En->obtenerPos(i).DibujarE(bg, sprite);
		}

	}


	int cantidadEnemigos()
	{
		return En->longitud();

	}

	void MoverEnemigos()
	{
		for (int i = 0; i < En->longitud(); ++i)
		{
			En->obtenerPos(i).MoverE();
		}
	}

	void EliminarE(int k)
	{
		En->eliminaPos(k);
	}

	int TamañoE()
	{
		return En->longitud();
	}

	Rectangle RectanguloEn(int i)
	{
		return Rectangle(En->obtenerPos(i).getx(), En->obtenerPos(i).gety(), En->obtenerPos(i).getancho(), En->obtenerPos(i).getalto());
	}

	Enemigo ReturnEnemigo(int l)
	{
		return En->obtenerPos(l);
	}

	void destruir(Jugador* Ju)
	{
		for (int i = 0; i < En->longitud(); ++i)
		{
			if (En->obtenerPos(i).getsalud2() <= 0)
			{
				En->eliminaPos(i);
				Ju->setsalud(Ju->getsalud() + 50);

			}
		}
	}

	void SetSalud(int i, int nuevo)
	{
		En->obtenerPos(i).setsalud2(nuevo);
	}

	int GetSalud(int i)
	{
		return En->obtenerPos(i).getsalud2();
	}

	void SetContador(int i, int nuevo)
	{
		En->obtenerPos(i).setcontador(nuevo);
	}

	int GetCademcia(int i)
	{
		return En->obtenerPos(i).getcadencia();
	}

	int GetContador(int i)
	{
		return En->obtenerPos(i).getcontador();
	}
};