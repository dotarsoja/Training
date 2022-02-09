#pragma once
#include "People.h"
#include "PeopleFileDataBase.h"
#include "Utils.h"

// форма для добавления людей в базу данных
namespace Peoplestat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для People
	/// </summary>
	public ref class PeopleForm : public System::Windows::Forms::Form
	{
	private: PeopleFileDataBase^ database;
	public:
		PeopleForm(void)
		{
			InitializeComponent();
			database->LoadPeoplesDataBase();
			comboBoxNational->Items->AddRange(database->GetNationals()->Split('\n'));


		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PeopleForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonAddPeople;
	protected:
	private: System::Windows::Forms::Button^  buttonClear;
	private: System::Windows::Forms::Label^  labelFirstName;
	private: System::Windows::Forms::Label^  labelSecondName;
	private: System::Windows::Forms::Label^  labelFatherName;
	private: System::Windows::Forms::Label^  labelNational;
	private: System::Windows::Forms::Label^  labelBirthday;
	private: System::Windows::Forms::Label^  labelDath;
	private: System::Windows::Forms::Label^  labelMale;
	private: System::Windows::Forms::Label^  labelHeight;
	private: System::Windows::Forms::TextBox^  textBoxFirstName;
	private: System::Windows::Forms::TextBox^  textBoxLastName;
	private: System::Windows::Forms::TextBox^  textBoxFatherName;
	private: System::Windows::Forms::ComboBox^  comboBoxNational;
	private: System::Windows::Forms::DateTimePicker^  dateTimePickerBirthday;
	private: System::Windows::Forms::DateTimePicker^  dateTimePickerDath;







	private: System::Windows::Forms::RadioButton^  radioMen;
	private: System::Windows::Forms::RadioButton^  radioWomen;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownHigh;

	private: System::Windows::Forms::CheckBox^  checkBoxDath;

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
			this->buttonAddPeople = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->labelFirstName = (gcnew System::Windows::Forms::Label());
			this->labelSecondName = (gcnew System::Windows::Forms::Label());
			this->labelFatherName = (gcnew System::Windows::Forms::Label());
			this->labelNational = (gcnew System::Windows::Forms::Label());
			this->labelBirthday = (gcnew System::Windows::Forms::Label());
			this->labelDath = (gcnew System::Windows::Forms::Label());
			this->labelMale = (gcnew System::Windows::Forms::Label());
			this->labelHeight = (gcnew System::Windows::Forms::Label());
			this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLastName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFatherName = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxNational = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePickerBirthday = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePickerDath = (gcnew System::Windows::Forms::DateTimePicker());
			this->radioMen = (gcnew System::Windows::Forms::RadioButton());
			this->radioWomen = (gcnew System::Windows::Forms::RadioButton());
			this->numericUpDownHigh = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBoxDath = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownHigh))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonAddPeople
			// 
			this->buttonAddPeople->Location = System::Drawing::Point(275, 355);
			this->buttonAddPeople->Name = L"buttonAddPeople";
			this->buttonAddPeople->Size = System::Drawing::Size(117, 23);
			this->buttonAddPeople->TabIndex = 0;
			this->buttonAddPeople->Text = L"Добавить";
			this->buttonAddPeople->UseVisualStyleBackColor = true;
			this->buttonAddPeople->Click += gcnew System::EventHandler(this, &PeopleForm::buttonAddPeople_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(25, 355);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(109, 23);
			this->buttonClear->TabIndex = 1;
			this->buttonClear->Text = L"Очистить все";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &PeopleForm::buttonClear_Click);
			// 
			// labelFirstName
			// 
			this->labelFirstName->AutoSize = true;
			this->labelFirstName->Location = System::Drawing::Point(85, 23);
			this->labelFirstName->Name = L"labelFirstName";
			this->labelFirstName->Size = System::Drawing::Size(29, 13);
			this->labelFirstName->TabIndex = 2;
			this->labelFirstName->Text = L"Имя";
			// 
			// labelSecondName
			// 
			this->labelSecondName->AutoSize = true;
			this->labelSecondName->Location = System::Drawing::Point(58, 61);
			this->labelSecondName->Name = L"labelSecondName";
			this->labelSecondName->Size = System::Drawing::Size(56, 13);
			this->labelSecondName->TabIndex = 3;
			this->labelSecondName->Text = L"Фамилия";
			// 
			// labelFatherName
			// 
			this->labelFatherName->AutoSize = true;
			this->labelFatherName->Location = System::Drawing::Point(60, 99);
			this->labelFatherName->Name = L"labelFatherName";
			this->labelFatherName->Size = System::Drawing::Size(54, 13);
			this->labelFatherName->TabIndex = 4;
			this->labelFatherName->Text = L"Отчество";
			// 
			// labelNational
			// 
			this->labelNational->AutoSize = true;
			this->labelNational->Location = System::Drawing::Point(22, 137);
			this->labelNational->Name = L"labelNational";
			this->labelNational->Size = System::Drawing::Size(92, 13);
			this->labelNational->TabIndex = 5;
			this->labelNational->Text = L"Национальность";
			// 
			// labelBirthday
			// 
			this->labelBirthday->AutoSize = true;
			this->labelBirthday->Location = System::Drawing::Point(28, 175);
			this->labelBirthday->Name = L"labelBirthday";
			this->labelBirthday->Size = System::Drawing::Size(86, 13);
			this->labelBirthday->TabIndex = 6;
			this->labelBirthday->Text = L"Дата рождения";
			// 
			// labelDath
			// 
			this->labelDath->AutoSize = true;
			this->labelDath->Location = System::Drawing::Point(41, 213);
			this->labelDath->Name = L"labelDath";
			this->labelDath->Size = System::Drawing::Size(73, 13);
			this->labelDath->TabIndex = 7;
			this->labelDath->Text = L"Дата смерти";
			// 
			// labelMale
			// 
			this->labelMale->AutoSize = true;
			this->labelMale->Location = System::Drawing::Point(87, 251);
			this->labelMale->Name = L"labelMale";
			this->labelMale->Size = System::Drawing::Size(27, 13);
			this->labelMale->TabIndex = 8;
			this->labelMale->Text = L"Пол";
			// 
			// labelHeight
			// 
			this->labelHeight->AutoSize = true;
			this->labelHeight->Location = System::Drawing::Point(83, 289);
			this->labelHeight->Name = L"labelHeight";
			this->labelHeight->Size = System::Drawing::Size(31, 13);
			this->labelHeight->TabIndex = 9;
			this->labelHeight->Text = L"Рост";
			// 
			// textBoxFirstName
			// 
			this->textBoxFirstName->Location = System::Drawing::Point(183, 20);
			this->textBoxFirstName->Name = L"textBoxFirstName";
			this->textBoxFirstName->Size = System::Drawing::Size(209, 20);
			this->textBoxFirstName->TabIndex = 10;
			// 
			// textBoxLastName
			// 
			this->textBoxLastName->Location = System::Drawing::Point(183, 58);
			this->textBoxLastName->Name = L"textBoxLastName";
			this->textBoxLastName->Size = System::Drawing::Size(209, 20);
			this->textBoxLastName->TabIndex = 11;
			// 
			// textBoxFatherName
			// 
			this->textBoxFatherName->Location = System::Drawing::Point(183, 96);
			this->textBoxFatherName->Name = L"textBoxFatherName";
			this->textBoxFatherName->Size = System::Drawing::Size(209, 20);
			this->textBoxFatherName->TabIndex = 12;
			// 
			// comboBoxNational
			// 
			this->comboBoxNational->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxNational->FormattingEnabled = true;
			this->comboBoxNational->Location = System::Drawing::Point(183, 134);
			this->comboBoxNational->Name = L"comboBoxNational";
			this->comboBoxNational->Size = System::Drawing::Size(209, 21);
			this->comboBoxNational->TabIndex = 13;
			// 
			// dateTimePickerBirthday
			// 
			this->dateTimePickerBirthday->Location = System::Drawing::Point(183, 169);
			this->dateTimePickerBirthday->Name = L"dateTimePickerBirthday";
			this->dateTimePickerBirthday->Size = System::Drawing::Size(209, 20);
			this->dateTimePickerBirthday->TabIndex = 14;
			// 
			// dateTimePickerDath
			// 
			this->dateTimePickerDath->Enabled = false;
			this->dateTimePickerDath->Location = System::Drawing::Point(183, 207);
			this->dateTimePickerDath->Name = L"dateTimePickerDath";
			this->dateTimePickerDath->Size = System::Drawing::Size(209, 20);
			this->dateTimePickerDath->TabIndex = 15;
			// 
			// radioMen
			// 
			this->radioMen->AutoSize = true;
			this->radioMen->Checked = true;
			this->radioMen->Location = System::Drawing::Point(183, 249);
			this->radioMen->Name = L"radioMen";
			this->radioMen->Size = System::Drawing::Size(70, 17);
			this->radioMen->TabIndex = 16;
			this->radioMen->TabStop = true;
			this->radioMen->Text = L"Мужчина";
			// 
			// radioWomen
			// 
			this->radioWomen->AutoSize = true;
			this->radioWomen->Location = System::Drawing::Point(311, 249);
			this->radioWomen->Name = L"radioWomen";
			this->radioWomen->Size = System::Drawing::Size(75, 17);
			this->radioWomen->TabIndex = 17;
			this->radioWomen->Text = L"Женщина";
			this->radioWomen->UseVisualStyleBackColor = true;
			// 
			// numericUpDownHigh
			// 
			this->numericUpDownHigh->Location = System::Drawing::Point(183, 287);
			this->numericUpDownHigh->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			this->numericUpDownHigh->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDownHigh->Name = L"numericUpDownHigh";
			this->numericUpDownHigh->Size = System::Drawing::Size(209, 20);
			this->numericUpDownHigh->TabIndex = 18;
			this->numericUpDownHigh->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 150, 0, 0, 0 });
			this->numericUpDownHigh->ValueChanged += gcnew System::EventHandler(this, &PeopleForm::numericUpDown1_ValueChanged);
			// 
			// checkBoxDath
			// 
			this->checkBoxDath->AutoSize = true;
			this->checkBoxDath->Location = System::Drawing::Point(407, 212);
			this->checkBoxDath->Name = L"checkBoxDath";
			this->checkBoxDath->Size = System::Drawing::Size(15, 14);
			this->checkBoxDath->TabIndex = 19;
			this->checkBoxDath->UseVisualStyleBackColor = true;
			this->checkBoxDath->CheckedChanged += gcnew System::EventHandler(this, &PeopleForm::checkBoxDath_CheckedChanged);
			// 
			// PeopleForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(434, 402);
			this->Controls->Add(this->checkBoxDath);
			this->Controls->Add(this->numericUpDownHigh);
			this->Controls->Add(this->radioWomen);
			this->Controls->Add(this->radioMen);
			this->Controls->Add(this->dateTimePickerDath);
			this->Controls->Add(this->dateTimePickerBirthday);
			this->Controls->Add(this->comboBoxNational);
			this->Controls->Add(this->textBoxFatherName);
			this->Controls->Add(this->textBoxLastName);
			this->Controls->Add(this->textBoxFirstName);
			this->Controls->Add(this->labelHeight);
			this->Controls->Add(this->labelMale);
			this->Controls->Add(this->labelDath);
			this->Controls->Add(this->labelBirthday);
			this->Controls->Add(this->labelNational);
			this->Controls->Add(this->labelFatherName);
			this->Controls->Add(this->labelSecondName);
			this->Controls->Add(this->labelFirstName);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->buttonAddPeople);
			this->Name = L"PeopleForm";
			this->Text = L"Человек";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownHigh))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void checkBoxDath_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	dateTimePickerDath->Enabled = checkBoxDath->Checked;
}
private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxFirstName->Text = "";
	textBoxFatherName->Text = "";
	textBoxLastName->Text = "";
	numericUpDownHigh->Value = 150;
	checkBoxDath->Checked = false;
	dateTimePickerBirthday->Value = DateTime::Now;
	dateTimePickerDath->Value = DateTime::Now;
	
}

private: System::Void buttonAddPeople_Click(System::Object^  sender, System::EventArgs^  e) {
	

	DateTime^ dathDay;

	People^ people = gcnew People(
		textBoxFirstName->Text,
		textBoxLastName->Text,
		textBoxFatherName->Text,
		dateTimePickerBirthday->Value,
		(checkBoxDath->Checked) ? dateTimePickerDath->Value : dathDay,
		(radioMen->Checked) ? People::Male::Men : People::Male::Women,
		comboBoxNational->Text,
		int(numericUpDownHigh->Value)
		);

	if (!Utils::CheckPeople(people))
	{
		MessageBox::Show(Utils::current_error);
	}
	else
	{
		String ^ message = "Вы действительно хотите добавить в базу?\n" +
			people->firstname + " " +
			people->lastname + " " + people->fathertname +
			"\n" + String::Format("Дата рождения: {0}\nВозраст: {1} лет \nПол: {2}\nРост: {3} см",
				people->bithday->ToString("D"),
				people->GetAge(),
				people->getMaleText(),
				people->height);
		
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			message, "Добавить человека?", MessageBoxButtons::YesNo);
		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			database->InsertPeople(people);
			this->Close();
		}
	}
	
}
};
}
