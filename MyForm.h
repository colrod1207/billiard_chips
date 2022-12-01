#pragma once
#include"Controlador.h"
#include"Archivo.h"
namespace Examenfinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Controlador* control;
	private: System::Windows::Forms::Timer^ timer1;
		   Archivo* archivo;
		  
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			g = CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, ClientRectangle);
			archivo = new Archivo();
			control = new Controlador(buffer->Graphics, archivo->getmax());
			
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(791, 444);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::Green);
		control->rebotar();
		control->movertodo(buffer->Graphics);
		control->dibujartodo(buffer->Graphics);
		control->eliminarficha(buffer->Graphics);
		control->colision();
		buffer->Render(g);
	}

	private: System::Void MyForm_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void MyForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (control->getmax() > 0) {
			control->crearficha(buffer->Graphics, e->X,e->Y);
		}
	}
	};
}
