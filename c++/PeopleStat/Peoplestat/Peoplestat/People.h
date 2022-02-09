#pragma once
// класс реализует информацию о человеке
namespace Peoplestat {

	using namespace System;

	ref class People
	{
	public:
		enum class Male {Men, Women };
		String^ firstname;
		String^ lastname;
		String^ fathertname;
		DateTime ^bithday;
		DateTime ^dath;
		Male male;
		String^ national;
		int height;


		People()
		{
			
		}
		


		People(String^ firstname, String^ lastname , String^ fathertname, DateTime ^bithday, DateTime ^dath, Male male, String^ national, int height)
		{
			this->firstname = firstname;
			this->lastname = lastname;
			this->fathertname = fathertname;
			this->national = national;
			this->bithday = bithday;
			this->dath = dath;
			this->male = male;
			this->height = height;
		}

		int GetAge()
		{
			if(dath != nullptr)
				return dath->Year - bithday->Year;
			else
				return DateTime::Today.Year - bithday->Year;
			// todo дописать с учетом мес€ца и года
		}

		String^ getMaleText()
		{
			return (this->male == Male::Men) ? "ћужчина" : "∆енщина";

		}
	};
}

