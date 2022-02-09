#pragma once
#include "People.h"
#include "PeopleFileDataBase.h"
 // ����� �������� ��������� �������� �� ������������ ������ � �������� ������� 

namespace Peoplestat {

	using namespace System;
	using namespace System::Text::RegularExpressions;

	ref class Utils
	{

	public: static String^ current_error = "";

	public: static bool CheckPeople(People ^ people)
	{
		Regex^ regex = gcnew Regex("^[�-ߨ]{1}[�-��]{2,255}$");

		if ((people->lastname == nullptr) || !regex->IsMatch(people->firstname))
		{
			current_error = "������ � ����� ��������";
			return false;
		}
		if ((people->lastname == nullptr) || !regex->IsMatch(people->lastname))
		{
			current_error = "������ � ������� ��������.";
			return false;
		}

		if (people->bithday == nullptr)
		{
			current_error = "�� ������� ���� ��������.";
			return false;
		}

		if (DateTime::Now.ToFileTimeUtc() - people->bithday->ToFileTimeUtc() < 0)
		{

			current_error = "���� �������� ����� �������.";
			return false;

		}


		if (people->dath != nullptr)
		{
			if (DateTime::Now.ToFileTimeUtc() - people->dath->ToFileTimeUtc() < 0)
			{
				current_error = "���� ������ ����� �������.";
				return false;

			}

			if (people->dath->ToFileTimeUtc() - people->bithday->ToFileTimeUtc() < 0)
			{
				current_error = "���� ������ ������ ���� ��������.";
				return false;

			}

		}


		if (!((people->male == People::Male::Men) || (people->male == People::Male::Women)))
		{
			current_error = "�� ������ ���.";
			return false;
		}

		if (people->height > 300)
		{
			current_error = "������� ������� ����.";
			return false;
		}

		if (people->height < 10)
		{
			current_error = "������� ��������� ����.";
			return false;
		}



		if (people->national == nullptr || people->national == "")
		{
			current_error = "�� ������� ��������������.";
			return false;
		}
		else if (!PeopleFileDataBase::LoadNationals()->Contains(people->national))
		{
			current_error = "���������� �������������� ��� � ������";
			return false;
		}

		current_error = "";
		return true;


	}

	};
};

