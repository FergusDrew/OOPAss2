#include "Dates.h"

Dates::Dates() : day(0), month(0), year(0)
{

}

Dates::~Dates()
{

}

int Dates::GetDay()
{
	return day;
}

int Dates::GetMonth()
{
	return month;
}

int Dates::GetYear()
{
	return year;
}


void Dates::currentDate()
{
	time_t const now_c = time(0);
	tm* ltm = localtime(&now_c);
	stringstream ss, ss1, ss2;
	ss << put_time(ltm, "%Y");
	ss1 << put_time(ltm, "%m");
	ss2 << put_time(ltm, "%d");

	string s = ss.str();
	string s1 = ss1.str();
	string s2 = ss2.str();

	year = stoi(s);
	month = stoi(s1);
	day = stoi(s2);
}


