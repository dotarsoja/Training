#pragma once

#include "PeopleForm.h"
#include "PeopleFileDataBase.h"
#include "ShowAllPeoples.h"
// Главная форма позвлоялт отобразить список всех людей
// или добавить новых.
namespace Peoplestat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonShowAllPeople;
	private: System::Windows::Forms::Button^  buttonAddPeople;
	protected:


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonShowAllPeople = (gcnew System::Windows::Forms::Button());
			this->buttonAddPeople = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonShowAllPeople
			// 
			this->buttonShowAllPeople->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonShowAllPeople->Location = System::Drawing::Point(45, 127);
			this->buttonShowAllPeople->Name = L"buttonShowAllPeople";
			this->buttonShowAllPeople->Size = System::Drawing::Size(303, 71);
			this->buttonShowAllPeople->TabIndex = 1;
			this->buttonShowAllPeople->Text = L"Отобразить список людей.";
			this->buttonShowAllPeople->UseVisualStyleBackColor = true;
			this->buttonShowAllPeople->Click += gcnew System::EventHandler(this, &MyForm::buttonShowAllPeople_Click);
			// 
			// buttonAddPeople
			// 
			this->buttonAddPeople->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonAddPeople->Location = System::Drawing::Point(45, 33);
			this->buttonAddPeople->Name = L"buttonAddPeople";
			this->buttonAddPeople->Size = System::Drawing::Size(303, 71);
			this->buttonAddPeople->TabIndex = 0;
			this->buttonAddPeople->Text = L"Добавить нового человека.";
			this->buttonAddPeople->UseVisualStyleBackColor = true;
			this->buttonAddPeople->Click += gcnew System::EventHandler(this, &MyForm::buttonAddPeople_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(390, 240);
			this->Controls->Add(this->buttonAddPeople);
			this->Controls->Add(this->buttonShowAllPeople);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->Text = L"База данных";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonAddPeople_Click(System::Object^  sender, System::EventArgs^  e) {
		
		
		Form^ people = gcnew PeopleForm();
		people->Show();
		people->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::DerivedClosed);
		Hide();
	}

	private: System::Void DerivedClosed(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^  e)
			 {
				 this->Show();
			 }

	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

	}
	private: System::Void buttonShowAllPeople_Click(System::Object^  sender, System::EventArgs^  e) {

		Form^ peoplesShow = gcnew ShowAllPeoples();
		peoplesShow->Show();
		peoplesShow->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::DerivedClosed);
		Hide();

	}
};
}
