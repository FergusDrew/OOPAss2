#pragma once
#pragma warning(disable : 4996)
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <iostream>
using namespace std;
using std::chrono::system_clock;


class Dates
{
public:
	Dates();
	~Dates();
	void currentDate();
	int GetDay();
	int GetMonth();
	int GetYear();


private:
	int month;
	int day;
	int year;
};