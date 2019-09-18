#pragma once

using namespace System::Drawing;
using namespace System::Collections::Generic;

#include "Objeto.hpp"
#include "Municion.hpp"

class ColeccionMunicion : public Municion
{
	list <Municion*>* Mu = new list <Municion*>;
	
public:
	ColeccionMunicion()
	{
		for (int i = 0; i < 18; ++i)
		{
			Mu->agregaInicial(new Municion());
		}
	}

	void crearColeccionMun(int niv)
	{
		if (niv == 1)
		{
			for (int i = 0; i < 18; ++i)
			{
				Mu->agregaInicial(new Municion());
			}
		}
		else if (niv == 2)
		{
			for (int i = 0; i < 20; ++i)
			{
				Mu->agregaInicial(new Municion());
			}
		}
		else if (niv == 3)
		{
			for (int i = 0; i < 22; ++i)
			{
				Mu->agregaInicial(new Municion());
			}
		}


	}

	/*void hacertransparente(Bitmap^ sprite) {
		Color color1 = sprite->GetPixel(0, 0);
		sprite->MakeTransparent(color1);
	}*/

	void DibujarMunicion(BufferedGraphics^ bg)
	{
		Bitmap^ sprite;
		//hacertransparente(sprite);
		for (int i = 0; i < Mu->longitud(); ++i)
		{
			switch (Mu->obtenerPos(i)->gettipo())
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

			Mu->obtenerPos(i)->dibujarMun(bg, sprite);
		}
	}

	int cantidadMunicion()
	{
		return Mu->longitud();

	}

	void EliminarMun(int k)
	{
		Mu->eliminaPos(k);
	}

	Rectangle RectanguloMun(int i)
	{
		return Rectangle(Mu->obtenerPos(i)->getx(), Mu->obtenerPos(i)->gety(), Mu->obtenerPos(i)->getancho(), 
			Mu->obtenerPos(i)->getalto());
	}

	Municion* ReturnMun(int l)
	{
		return Mu->obtenerPos(l);
	}


};