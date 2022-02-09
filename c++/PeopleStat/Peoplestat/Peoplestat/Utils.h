#pragma once
#include "People.h"
#include "PeopleFileDataBase.h"
 // Класс рализует различные проверки на соответствие данных и полезные функции 

namespace Peoplestat {

	using namespace System;
	using namespace System::Text::RegularExpressions;

	ref class Utils
	{

	public: static String^ current_error = "";

	public: static bool CheckPeople(People ^ people)
	{
		Regex^ regex = gcnew Regex("^[А-ЯЁ]{1}[а-яё]{2,255}$");

		if ((people->lastname == nullptr) || !regex->IsMatch(people->firstname))
		{
			current_error = "Ошибка в имени человека";
			return false;
		}
		if ((people->lastname == nullptr) || !regex->IsMatch(people->lastname))
		{
			current_error = "Ошибка в фамилии человека.";
			return false;
		}

		if (people->bithday == nullptr)
		{
			current_error = "Не указана дата рождения.";
			return false;
		}

		if (DateTime::Now.ToFileTimeUtc() - people->bithday->ToFileTimeUtc() < 0)
		{

			current_error = "Дата рождения позже текущей.";
			return false;

		}


		if (people->dath != nullptr)
		{
			if (DateTime::Now.ToFileTimeUtc() - people->dath->ToFileTimeUtc() < 0)
			{
				current_error = "Дата смерти позже текущей.";
				return false;

			}

			if (people->dath->ToFileTimeUtc() - people->bithday->ToFileTimeUtc() < 0)
			{
				current_error = "Дата смерти раньше даты рождения.";
				return false;

			}

		}


		if (!((people->male == People::Male::Men) || (people->male == People::Male::Women)))
		{
			current_error = "Не указан пол.";
			return false;
		}

		if (people->height > 300)
		{
			current_error = "Слишком большой рост.";
			return false;
		}

		if (people->height < 10)
		{
			current_error = "Слишком маленький рост.";
			return false;
		}



		if (people->national == nullptr || people->national == "")
		{
			current_error = "Не выбрана национальность.";
			return false;
		}
		else if (!PeopleFileDataBase::LoadNationals()->Contains(people->national))
		{
			current_error = "Указаннолй национальности нет в списке";
			return false;
		}

		current_error = "";
		return true;


	}

	};
};

