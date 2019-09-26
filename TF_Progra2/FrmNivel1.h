#pragma once


#include "FrmNivel1.h"




#include "Personaje.hpp"
#include  "ColeccionEnemigos.hpp"
#include "ColeccionBala.hpp"
#include "ColeccionMunicion.hpp"
#include "Barras.hpp"

namespace TF_Progra2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for FrmNivel1
	/// </summary>
	public ref class FrmNivel1 : public System::Windows::Forms::Form
	{
	public:

		FrmNivel1(void)
		{
			InitializeComponent();
			gra = panel1->CreateGraphics();
			bgc = BufferedGraphicsManager::Current;
			bg = bgc->Allocate(gra, this->ClientRectangle);
			fondo = gcnew Bitmap("fondoDiep.jpg");

			Ju = new Jugador();
			nivel = Ju->getnivel();

			tiempo = 0;
			clasebala = 1;
	

			CE = new ColeccionEnemigos();
			CB = new ColeccionBala();
			CM = new ColeccionMunicion();

			BM = new BarraMunicion();
			BC = new BarraColeccion();

			CE->crearColeccionEnemigos(nivel);
			switch (nivel)
			{
			case 2:
				fondo = gcnew Bitmap("fondo1.jpg"); break;
			case 3:
				fondo = gcnew Bitmap("fondo2.jpg"); break;
			case 4:
				Ganar(); break;
			}

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmNivel1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Graphics^ gra;
		BufferedGraphicsContext^ bgc;
		BufferedGraphics^ bg;

		ColeccionEnemigos* CE;
		ColeccionBala* CB;
		Jugador* Ju;
		ColeccionMunicion* CM;
		BarraMunicion* BM;
		BarraColeccion* BC;

		bool n;

		Bitmap^ fondo;

		Rectangle Rv;

		int nivel, tiempo, clasebala, velP, velPn;



	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Timer^ timer3;



	private: System::ComponentModel::IContainer^ components;
			 /// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->SuspendLayout();
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Interval = 50;
				 this->timer1->Tick += gcnew System::EventHandler(this, &FrmNivel1::timer1_Tick);
				 // 
				 // panel1
				 // 
				 this->panel1->Location = System::Drawing::Point(0, 0);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(1273, 821);
				 this->panel1->TabIndex = 0;
				 this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmNivel1::panel1_MouseClick);
				 this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmNivel1::panel1_MouseMove);
				 // 
				 // timer2
				 // 
				 this->timer2->Enabled = true;
				 this->timer2->Interval = 4200;
				 this->timer2->Tick += gcnew System::EventHandler(this, &FrmNivel1::timer2_Tick);
				 // 
				 // timer3
				 // 
				 this->timer3->Enabled = true;
				 this->timer3->Interval = 1000;
				 this->timer3->Tick += gcnew System::EventHandler(this, &FrmNivel1::timer3_Tick);
				 // 
				 // FrmNivel1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1274, 821);
				 this->Controls->Add(this->panel1);
				 this->Name = L"FrmNivel1";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"FrmNivel1";
				 this->Load += gcnew System::EventHandler(this, &FrmNivel1::FrmNivel1_Load);
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel1::FrmNivel1_KeyDown);
				 this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel1::FrmNivel1_KeyUp);
				 this->ResumeLayout(false);

			 }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		//GUARDAR X, Y, DX, DY Y VIDAS DEL JUGADOR EN TODO MOMENTO
		ofstream file("partida.tsv");
		if (file.is_open()) {
			file << Ju->getx() << " ";
			file << Ju->gety() << " ";
			file << Ju->getdx() << " ";
			file << Ju->getdy() << " ";
			file << Ju->getsalud() << " ";
			file << Ju->getnivel() << " ";
		}

		if (CE->cantidadEnemigos() == 0)
		{

			nivel++;
			CE->crearColeccionEnemigos(nivel);
			Ju->setsalud(1000 + (nivel * 500));
			Ju->setx(MAX_X / 2);
			Ju->sety(MAX_Y / 2);

			switch (nivel)
			{
			case 2:
				fondo = gcnew Bitmap("fondo1.jpg"); break;
			case 3:
				fondo = gcnew Bitmap("fondo2.jpg"); break;
			case 4:
				Ganar(); break;

			}
		}

		if (tiempo == 1000 || Ju->getsalud() < 0)
		{

			Perder();
		}


		bg->Graphics->Clear(SystemColors::Control);



		bg->Graphics->DrawImage(fondo, 0, 0, panel1->Width, panel1->Height);

		if (Ju->getc() > 2)
		{
			Ju->setc(0);
		}

		

		tiempoDibujar();
		nivelDibujar();

		if (CM->cantidadMunicion() == 0)
		{
			CM->crearColeccionMun(nivel);
		}


	


		CB->MoverBalas();
		CB->DibujarBalas(bg);

		CE->MoverEnemigos();
		CE->DibujarEnemigos(bg);


		ImpactoMunicion();
		ImpactoBala();
		ImpactoEnemigo();


		CE->destruir(Ju);
		Ju->DibujarJ(bg);

		CM->DibujarMunicion(bg);
		BM->DibujarBarra1(bg);
		BC->DibujarBarra2(bg);


		bg->Render(gra);


		if (n == true)
		{
			Ju->setc(Ju->getc() + 1);
		}
	}

	private: System::Void FrmNivel1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if ((e->KeyCode == Keys::Left || e->KeyCode == Keys::A) && (Ju->getx() + Ju->getdx() > 0))
		{
			Ju->setdx(-7);

			Ju->setx(Ju->getx() + Ju->getdx());

			Ju->setf(1);
			n = true;
		}
		if ((e->KeyCode == Keys::Right || e->KeyCode == Keys::D) && (Ju->getx() + Ju->getdx() + Ju->getanchoI() < MAX_X))
		{
			Ju->setdx(7);

			Ju->setx(Ju->getx() + Ju->getdx());
			Ju->setf(2);
			n = true;
		}
		if ((e->KeyCode == Keys::Up || e->KeyCode == Keys::W) && (Ju->gety() + Ju->getdy() > MIN_Y))
		{
			Ju->setdy(-7);
			Ju->sety(Ju->gety() + Ju->getdy());
			Ju->setf(3);
			n = true;
		}
		if ((e->KeyCode == Keys::Down || e->KeyCode == Keys::S) && (Ju->gety() + Ju->getdy() + Ju->getaltoI() < MAX_Y))
		{
			Ju->setdy(7);
			Ju->sety(Ju->gety() + Ju->getdy());
			Ju->setf(0);
			n = true;
		}

		if (e->KeyCode == Keys::M)
		{
			if (BC->TamañoBarra2() != 0)
			{
				Ju->setsalud(Ju->getsalud() + BC->returnB2()->top()->getvida());
				BC->returnB2()->pop();
			}
		}




	}


	private: System::Void FrmNivel1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		n = false;
		if (Ju->getf() == 1)
		{
			Ju->setc(0);
		}
		else if (Ju->getf() == 2)
		{
			Ju->setc(0);
		}
		else if (Ju->getf() == 3)
		{
			Ju->setc(0);
		}
		else if (Ju->getf() == 0)
		{
			Ju->setc(0);
		}
	}



	private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (BM->TamañoBarra() != 0)
		{
			CB->CrearBala(BM->returnB1()->top()->gettipo(), Ju->getx() + Ju->getanchoI() / 2, Ju->gety() + Ju->getaltoI() / 2, nivel);
			BM->returnB1()->pop();
			CB->SetAngulos(e->X, e->Y);
		}


	}


			 void ImpactoBala()
			 {
				 for (int i = 0; i < CB->TamañoB(); i++)
				 {
					 if ((CB->returnBala(i)->getx() + CB->returnBala(i)->getdx() > MAX_X - 30) || (CB->returnBala(i)->getx() + CB->returnBala(i)->getdx() < 0) || (CB->returnBala(i)->gety() + CB->returnBala(i)->getdy() > MAX_Y - 30) || (CB->returnBala(i)->gety() + CB->returnBala(i)->getdy() < MIN_Y))
					 {
						 CB->EliminarB(i);
						 //CB->SetChoque(i);
					 }
					 else
					 {
						 for (int j = 0; j < CE->TamañoE(); j++)
						 {
							 if (CB->RectanguloBa(i).IntersectsWith(CE->RectanguloEn(j)))
							 {
								 if (CB->returnBala(i)->gettipo() <= 3)
								 {

									 CE->SetSalud(j, CE->ReturnEnemigo(j)->getsalud2() - CB->returnBala(i)->getdaño());
									 CB->SetChoque(i);

								 }
							 }

						 }

						 if (CB->RectanguloBa(i).IntersectsWith(Ju->RectanguloJu()))
						 {
							 if (CB->returnBala(i)->gettipo() > 3)
							 {

								 Ju->setsalud(Ju->getsalud() - CB->returnBala(i)->getdaño());

								 CB->SetChoque(i);
							 }

						 }


						 for (int i = 0; i < CB->TamañoB(); i++)
						 {
							 for (int j = 0; j < CB->TamañoB(); j++)
							 {
								 if (CB->RectanguloBa(i).IntersectsWith(CB->RectanguloBa(j)))
								 {
									 if ((CB->GetClase(i) == 1 || CB->GetClase(i) == 2 || CB->GetClase(i) == 3) && (CB->GetClase(j) == 4 || CB->GetClase(j) == 5))
									 {
										 CB->SetChoque(i);
										 CB->SetChoque(j);
									 }
								 }
							 }

						 }



					 }
				 }

				 for (int j = 0; j < CB->TamañoB(); j++)
				 {
					 if (CB->GetChoque(j) == 1)
					 {

						 CB->EliminarB(j);
					 }

				 }
			 }


			 /////////

			 void ImpactoEnemigo()
			 {
				 for (int i = 0; i < CE->TamañoE(); i++)
				 {
					 if (CE->RectanguloEn(i).IntersectsWith(Ju->RectanguloJu()))
					 {

						 Ju->setsalud(Ju->getsalud() - 10);

					 }
				 }
			 }

			 ///////


			 void enemigoDispara()
			 {

				 for (int j = 0; j < CE->TamañoE(); j++)
				 {
					 if (CE->GetContador(j) == CE->GetCademcia(j))
					 {

						 if (CE->ReturnEnemigo(j)->getclase() == 2)
						 {

							 CB->CrearBala(4 + rand() % 2, CE->ReturnEnemigo(j)->getx() + CE->ReturnEnemigo(j)->getancho() / 2, CE->ReturnEnemigo(j)->gety() + CE->ReturnEnemigo(j)->getalto() / 2, nivel);
							 CB->SetAngulos(1 + rand() % 500, 1 + rand() % 500);

						 }
						 if (CE->ReturnEnemigo(j)->getclase() == 3)
						 {

							 CB->CrearBala(4 + rand() % 2, CE->ReturnEnemigo(j)->getx() + CE->ReturnEnemigo(j)->getancho() / 2, CE->ReturnEnemigo(j)->gety() + CE->ReturnEnemigo(j)->getalto() / 2, nivel);
							 CB->SetAngulos(Ju->getx() + Ju->getanchoI() / 2, Ju->gety() + Ju->getaltoI() / 2);

						 }
					 }

				 }
			 }


	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {

		for (int j = 0; j < CE->TamañoE(); j++)
		{
			CE->SetContador(j, CE->ReturnEnemigo(j)->getcontador() + 1);

		}

		enemigoDispara();
	}

	private: System::Void panel1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		int angulo;

		if (e->X < Ju->getx() && e->Y  < Ju->getx() - e->X + Ju->gety() && e->Y  > -Ju->getx() + e->X + Ju->gety())
		{

			Ju->setf(1);

			angulo = atan((double)(e->Y - Ju->gety()) / (double)(e->X - Ju->getx()));

		}

		else if (e->X > Ju->getx() && e->Y > Ju->getx() - e->X + Ju->gety() && e->Y < -Ju->getx() + e->X + Ju->gety())
		{

			Ju->setf(2);

			angulo = atan((double)(e->Y - Ju->gety()) / (double)(e->X - Ju->getx()));

		}
		else if (e->Y < Ju->gety() && e->Y < Ju->getx() - e->X + Ju->gety() && e->Y < -Ju->getx() + e->X + Ju->gety())
		{

			Ju->setf(3);

			angulo = atan((double)(e->Y - Ju->gety()) / (double)(e->X - Ju->getx()));

		}
		else if (e->Y > Ju->gety() && e->Y > Ju->getx() - e->X + Ju->gety() && e->Y > -Ju->getx() + e->X + Ju->gety())
		{

			Ju->setf(0);

			angulo = atan((double)(e->Y - Ju->gety()) / (double)(e->X - Ju->getx()));

		}


	}

	

	private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
		tiempo++;
	}


			 void tiempoDibujar()
			 {
				 String^ a = tiempo.ToString();

				 System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial", 25);

				 bg->Graphics->DrawRectangle(Pens::Green, MAX_X - 100, MAX_Y - 50, 100, 50);
				 bg->Graphics->FillRectangle(Brushes::White, MAX_X - 100, MAX_Y - 50, 104, 50);
				 bg->Graphics->DrawString(a, f, Brushes::Black, MAX_X - 100, MAX_Y - 50);
			 }



			 void nivelDibujar()
			 {
				 String^ a = "Nivel " + nivel.ToString();

				 System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial", 25);

				 bg->Graphics->DrawRectangle(Pens::Green, 0, MAX_Y - 50, 130, 50);
				 bg->Graphics->FillRectangle(Brushes::White, 0, MAX_Y - 50, 130, 50);
				 bg->Graphics->DrawString(a, f, Brushes::Black, 0, MAX_Y - 50);
			 }


			 void Ganar()
			 {
				 Bitmap^ ban = gcnew Bitmap("ganar.jpg");
				 bg->Graphics->DrawImage(ban, 0, 0, panel1->Width, panel1->Height);
				 bg->Render();
				 system("pause");
				 system("pause");
				 Application::Exit();
			 }

			 void Perder()
			 {
				 Bitmap^ ban = gcnew Bitmap("perder.png");
				 bg->Graphics->DrawImage(ban, 0, 0, panel1->Width, panel1->Height);
				 bg->Render();
				 system("pause");
				 system("pause");
				 Application::Exit();
			 }




	private: System::Void FrmNivel1_Load(System::Object^ sender, System::EventArgs^ e) {
		velP = Ju->getdx();
		velPn = Ju->getdx() * -1;

	}




			 ///////////////////////////////////////////////////////
			 /////////////////////////////////////////////////////
			 ////////////////////////////////////////////////////


		 void ImpactoMunicion()
		 {
			 for (int i = 0; i < CM->cantidadMunicion(); i++)
			 {
				 if (CM->RectanguloMun(i).IntersectsWith(Ju->RectanguloJu()) && (CM->ReturnMun(i)->gettipo() > 0 && CM->ReturnMun(i)->gettipo() <= 3))
				 {

					 BM->returnB1()->push(new Municion(0,0,CM->ReturnMun(i)->gettipo()));
					 
					 CM->ReturnMun(i)->setenbarra(1);

				 }
				 if (CM->RectanguloMun(i).IntersectsWith(Ju->RectanguloJu()) && (CM->ReturnMun(i)->gettipo() > 3 && CM->ReturnMun(i)->gettipo() <= 6))
				 {

					 BC->returnB2()->push(new Municion(0, 31, CM->ReturnMun(i)->gettipo(), CM->ReturnMun(i)->getvida()));
					 
					 CM->ReturnMun(i)->setenbarra(1);

				 }
			 }

			 for (int i = 0; i < CM->cantidadMunicion(); i++)
			 {
				 if (CM->ReturnMun(i)->getbarra() == 1)
				 {
					 CM->EliminarMun(i);
				 }
			 }

		 }


	

	};
}


