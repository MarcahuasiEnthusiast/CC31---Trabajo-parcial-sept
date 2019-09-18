#pragma once

#include "Objeto.hpp"
#include "Bala.hpp"

class ColeccionBala : public Bala
{
private:
	list <Bala*>  * Balas = new list <Bala*>;


	//IGUAL QUE BALA PERO EN VECTOR
public:

	ColeccionBala()
	{

	}

	ColeccionBala(int t, int x, int y, int nivel)
	{
		for (int i = 0; i < 2; ++i)
		{
			Balas->agregaInicial(new Bala(t, x, y, nivel));
		}
	}

	void CrearBala(int t, int x, int y, int nivel)
	{

		Balas->agregaInicial(new Bala(t, x, y, nivel));


	}

	void DibujarBalas(BufferedGraphics^ bg)
	{
		Bitmap^ sprite;


		for (int i = 0; i < Balas->longitud(); ++i)
		{
			if (Balas->obtenerPos(i)->gettipo() == 1)
			{
				sprite = gcnew Bitmap("bala1.png");
			}
			else if (Balas->obtenerPos(i)->gettipo() == 2)
			{
				sprite = gcnew Bitmap("bala2.png");
			}
			else if (Balas->obtenerPos(i)->gettipo() == 3)
			{
				sprite = gcnew Bitmap("bala3.png");
			}
			else if (Balas->obtenerPos(i)->gettipo() == 4)
			{
				sprite = gcnew Bitmap("bala4.png");
			}
			else if (Balas->obtenerPos(i)->gettipo() == 5)
			{
				sprite = gcnew Bitmap("bala5.png");
			}

			Balas->obtenerPos(i)->dibujarBala(bg, sprite);

		}

	}
	void MoverBalas()
	{
		for (int i = 0; i < Balas->longitud(); ++i)
		{
			Balas->obtenerPos(i)->mover();
		}
	}

	void SetAngulos(int nx, int ny)
	{
		Balas->obtenerPos(0)->setAngulo(nx, ny);
	}

	void EliminarB(int k)
	{
		Balas->eliminaPos(k);
	}

	int TamañoB()
	{
		return Balas->longitud();
	}

	Rectangle RectanguloBa(int i)
	{
		return Rectangle(Balas->obtenerPos(i)->getx(), Balas->obtenerPos(i)->gety(), Balas->obtenerPos(i)->getancho(), Balas->obtenerPos(i)->getalto());
	}

	Bala * returnBala(int m)
	{
		return Balas->obtenerPos(m);
	}

	void SetChoque(int i)
	{
		Balas->obtenerPos(i)->setchoque(1);
	}

	int GetChoque(int i)
	{
		return Balas->obtenerPos(i)->getchoque();
	}

	int GetClase(int i)
	{
		return Balas->obtenerPos(i)->getclase();
	}



	void SetDaño(int i, int j)
	{
		Balas->obtenerPos(i)->setdaño(j);
	}
};