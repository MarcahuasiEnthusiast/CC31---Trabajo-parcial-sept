#pragma once

#include "Objeto.hpp"
#include "Bala.hpp"
#include "Listas.hpp"

class ColeccionBala : public Bala
{
private:
	vector <Bala> Balas;


	//IGUAL QUE BALA PERO EN VECTOR
public:

	ColeccionBala()
	{

	}

	ColeccionBala(int t, int x, int y, int nivel)
	{
		for (int i = 0; i < 2; ++i)
		{
			Balas.push_back(Bala(t, x, y, nivel));
		}
	}

	void CrearBala(int t, int x, int y, int nivel)
	{

		Balas.push_back(Bala(t, x, y, nivel));


	}

	void DibujarBalas(BufferedGraphics^ bg)
	{
		Bitmap^ sprite;


		for (int i = 0; i < Balas.size(); ++i)
		{
			if (Balas[i].gettipo() == 1)
			{
				sprite = gcnew Bitmap("bala1.png");
			}
			else if (Balas[i].gettipo() == 2)
			{
				sprite = gcnew Bitmap("bala2.png");
			}
			else if (Balas[i].gettipo() == 3)
			{
				sprite = gcnew Bitmap("bala3.png");
			}
			else if (Balas[i].gettipo() == 4)
			{
				sprite = gcnew Bitmap("bala4.png");
			}
			else if (Balas[i].gettipo() == 5)
			{
				sprite = gcnew Bitmap("bala5.png");
			}

			Balas[i].dibujarBala(bg, sprite);

		}

	}
	void MoverBalas()
	{
		for (int i = 0; i < Balas.size(); ++i)
		{

			Balas[i].mover();
		}
	}

	void SetAngulos(int nx, int ny)
	{
		Balas[Balas.size() - 1].setAngulo(nx, ny);
	}

	void EliminarB(int k)
	{
		Balas.erase(Balas.begin() + k);
	}

	int TamañoB()
	{
		return Balas.size();
	}

	Rectangle RectanguloBa(int l)
	{
		return Rectangle(Balas[l].getx(), Balas[l].gety(), Balas[l].getancho(), Balas[l].getalto());
	}

	Bala returnBala(int m)
	{
		return Balas.at(m);
	}

	void SetChoque(int i)
	{
		Balas[i].setchoque(1);
	}

	int GetChoque(int i)
	{
		return Balas[i].getchoque();
	}

	int GetClase(int i)
	{
		return Balas[i].getclase();
	}



	void SetDaño(int i, int j)
	{
		Balas[i].setdaño(j);
	}
};