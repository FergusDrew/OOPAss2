#include "Date.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <forward_list>
#include <deque>

Date::Date() : year(""), month(""), day("")
{
	
}

Date::~Date()
{

}


std::string Date::SplitDate(string date)
{
    vector<string> aryr;
	stringstream s_stream(date);
	while (s_stream.good()) {
		string substr;
		getline(s_stream, substr, '-'); 
		aryr.push_back(substr);
	}

	year = aryr[2];
	month = aryr[1];
	day = aryr[0];

	date = aryr[2] + "/" + aryr[1] + "/" + aryr[0];

	return date;
}


string Date::currentDate()
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

	int year = stoi(s);
	int month = stoi(s1);
	int day = stoi(s2);
	string dateNow = s2 + "/" + s1 + "/" + s;

	return dateNow;
}


