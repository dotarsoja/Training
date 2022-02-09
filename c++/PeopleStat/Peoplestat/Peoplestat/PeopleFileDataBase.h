#pragma once
// ����� �������� �������� ������ � ����� � �������������

#include <fstream>
#include <list>
#include "People.h"
#include <iostream>


namespace Peoplestat {

	using namespace System;
	using namespace std;
	using namespace System::IO;


// 
	ref class PeopleFileDataBase
	{
	private:
		static  String^ _nations;
		static  String^  _databaseFileName = "database.txt";
		static  String^  _nationalsFileName = "nationals.txt";
		static int _index;

	public:
		// �������� ������ �� �����
		static void LoadPeoplesDataBase()
		{
			try {
				if (File::Exists(_databaseFileName))
				{
					int lineCount = 0;

					for each(String^ str in File::ReadLines(_databaseFileName))
					{
						lineCount++;
					}
					_index = lineCount;
					
				}
				else
				{
					File::Create(_databaseFileName);
				}


			}
			// ��������� ����������
			catch (const std::exception&)
			{

			}
			
		}

		static int GetCurrenIndex()
		{
			return _index;
		}

		// �������� ������ ����������� �������� �� id
		static People^ GetPeopleById(int id)
		{
			try {
				if (File::Exists(_databaseFileName))
				{
					int lineCount = 0;
					for each(String^ str in File::ReadLines(_databaseFileName))
					{
						if (id == lineCount++)
						{
							
							cli::array<System::String^>^ cols = str->Split(';');
							if (cols->Length != 9)
							{
								return nullptr;
							}
							DateTime ^ dath;
							People^ people = gcnew People(
								cols[1],
								cols[2],
								cols[3],
								DateTime::ParseExact(cols[4], "yyyy-MM-dd", nullptr),
								(cols[5] == "null") ? dath : DateTime::ParseExact(cols[5], "yyyy-MM-dd", nullptr),
								(cols[7] == "�������") ? People::Male::Men : People::Male::Women,
								cols[6],
								Int32::Parse(cols[8])
								);
							return people;
						}
					}

				}

			}
			// ��������� ����������
			catch (const std::exception&)
			{

			}
			return nullptr;

		}

		static String^ GetRowById(int id)
		{

			try {
				if (File::Exists(_databaseFileName))
				{
					int lineCount = 0;
					for each(String^ str in File::ReadLines(_databaseFileName))
					{
						if (id == lineCount++)
						{
							return str;
						}
					}

				}

			}
			catch (const std::exception&)
			{

			}
			return nullptr;
		}
		// ��������� �������� � ��
		static bool InsertPeople(People^ people)
		{
			
			try
			{
				String ^ lineFormat = "{0};{1};{2};{3};{4};{5};{6};{7};{8}\n";
				String^ line = String::Format(lineFormat,
					_index++,
					people->firstname,
					people->lastname,
					people->fathertname,
					people->bithday->ToString("yyyy-MM-dd"),
					(people->dath == nullptr) ? "null" : people->dath->ToString("yyyy-MM-dd"),
					people->national,
					people->getMaleText(),
					people->height.ToString()
					);
	
				File::AppendAllText(_databaseFileName, line);
				return true;
			}
			catch(const std::exception&)
			{
				return false;
			}

		}
		// ��������� ������ �������� � ��
		static bool UpdatePeopleById(int id, People^ people)
		{
			return false;
		}

		// �������� ������ ���������������� �� ��
		static String^ GetNationals()
		{
			if (_nations == nullptr)
			{
				_nations = LoadNationals();
			}
			return _nations;
		}
		// �������� ���������� �������������� �� id �� ��
		static String^ GetNationsById(int id)
		{
			if (_nations == nullptr)
			{
				_nations = LoadNationals();
			}

			if (id < 0 || GetNationsCount() < id)
			{
				return nullptr;
			}
			else
			{
				return _nations->Split('\n')[id];
			}
		}
		// �������� id �������������� �� �� �� �����
		static int GetNationsId(String^ nationname)
		{
			if (_nations == nullptr)
			{
				_nations = LoadNationals();
			}

			for (int i = 0; i < GetNationsCount(); i++)
			{
				if (nationname == _nations->Split('\n')[i])
				{
					return i;
				}
			}

			return -1;
		}

		// �������� ������ ��������������� �� ��
		static String^ LoadNationals()
		{

			// �������� �� ���������
			String^ nations = "�������\n�����\n������\n�����\n������\n������\n�������";

			try
			{

				if (File::Exists(_nationalsFileName))
				{

					nations = File::ReadAllText(_nationalsFileName, System::Text::Encoding::UTF8);

				}
				else
				{
					File::WriteAllText(_nationalsFileName, nations);
				}




			}
			 // ��������� ����������
			catch (const std::exception&)
			{


			}

			return nations;
		}
	private:
		static int GetNationsCount()
		{
			return _nations->Split('\n')->Length;
		}

		

	

		
	};

}