#pragma once
#include "PeopleFileDataBase.h"
// класс для отображения базы данных людей в определенном формате.
namespace Peoplestat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ShowAllPeoples
	/// </summary>
	public ref class ShowAllPeoples : public System::Windows::Forms::Form
	{

	private: PeopleFileDataBase^ _dataBase;

	public:
		ShowAllPeoples(void)
		{
			InitializeComponent();
			_dataBase->LoadPeoplesDataBase();
			People ^ person;
			richTextBox1->AcceptsTab = true;
			String^ format = "{8}\t{0,-15}\t{1,-20}\t{2,-25}\t{3,-25}\t{4,-15}\t{5,-15}\t{6,-15}\t{7,-10}\n";
			String^ header = String::Format(
				format,
				"Имя",
				"Фамилия",
				"Отчество",
				"Дата рождения",
				"Дата смерти",
				"Национальнасть",
				"Пол",
				"Рост см",
				"№");
			richTextBox1->AppendText(header);

			for (int i = 0; i < _dataBase->GetCurrenIndex() ; i++)
			{
				person = _dataBase->GetPeopleById(i);
				if (person != nullptr)
				{
					String^ line = String::Format(format,
						person->firstname,
						person->lastname,
						person->fathertname,
						person->bithday->ToString("D"),
						(person->dath == nullptr) ? "нет" : person->dath->ToString("D"),
						person->national,
						person->getMaleText(),
						person->height,
						i
						);

					richTextBox1->AppendText(line);

				}

				
			}
			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ShowAllPeoples()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:

	protected:



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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(1008, 361);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// ShowAllPeoples
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 361);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"ShowAllPeoples";
			this->Text = L"База данных людей";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
