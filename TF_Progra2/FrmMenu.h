#pragma once


#include "FrmMenu.h"
#include "FrmNivel1.h"
#include "Personaje.hpp"
#include "Objeto.hpp"
#include <string>

namespace TF_Progra2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMenu
	/// </summary>
	public ref class FrmMenu : public System::Windows::Forms::Form
	{
	public:
		FrmMenu(void)
		{
			InitializeComponent();
			gr = this->CreateGraphics();
			menu = gcnew Bitmap("menu.jpg");
			i = 1;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMenu()
		{
			if (components)
			{
				delete components;
			}
		}





	protected:





	private:
		Graphics ^ gr;
		Bitmap ^ menu;
		int i;


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Timer^  timer1;











	private: System::ComponentModel::IContainer^  components;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::DarkOliveGreen;
			this->button1->Location = System::Drawing::Point(-1, 465);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(286, 78);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Nuevo Juego";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FrmMenu::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::Color::DarkOliveGreen;
			this->button2->Location = System::Drawing::Point(283, 465);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(313, 78);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Instrucciones";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &FrmMenu::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold));
			this->button3->ForeColor = System::Drawing::Color::DarkOliveGreen;
			this->button3->Location = System::Drawing::Point(594, 465);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(297, 78);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Salir";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &FrmMenu::button3_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMenu::timer1_Tick);
			// 
			// FrmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 541);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"FrmMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmMenu";
			this->Load += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		

	private: System::Void FrmMenu_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	FrmNivel1^ juego = gcnew FrmNivel1;
	juego->Show();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	i++;
	if (i % 2 == 0)
	{
		menu = gcnew Bitmap("instrucciones.png");
	}
	else
	{
		menu = gcnew Bitmap("menu.jpg");
	}

}
		 //SALIR = GUARDAR
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	Rectangle R = Rectangle(0, 0, this->Width, this->Height);
	gr->DrawImage(menu, R);
}


};
}
