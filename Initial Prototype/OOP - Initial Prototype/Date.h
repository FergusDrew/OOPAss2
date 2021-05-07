#pragma once
#pragma warning(disable : 4996)
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <iostream>
using namespace std;
using std::chrono::system_clock;


class Date
{
public:
	Date();
	~Date();
	string currentDate();
	string SplitDate(string date);
private:
	string month;
	string day;
	string year;



};