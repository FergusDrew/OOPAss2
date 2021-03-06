#include "Utils.h"

std::string Utils::GetLineFromUser()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}

char Utils::GetCharFromUser()
{
	return toupper(GetLineFromUser()[0]);
}

const std::string Utils::toLower(const std::string& text)
{
	std::string temp;
	for (int i = 0; i < text.length(); i++)
	{
		temp += tolower(text[i]);
	}
	return temp;
}

std::string Utils::CastToPrice(int price)
{
	float n1 = price;
	n1 = n1 / 100;
	std::stringstream sstream;
	sstream << n1;
	std::string num_str = sstream.str();
	return num_str;
}

std::string Utils::CastToCredit(const int credits)
{
	float n1 = credits;
	n1 = n1 / 100;
	std::stringstream sstream;
	sstream << n1;
	std::string num_str = sstream.str();
	return num_str;
	/*
	const int credit = credits;
	std::stringstream sstream;
	sstream << credit;
	std::string num_str = sstream.str() + ".00";
	return num_str*/
}

bool Utils::contains(std::string name, std::string text)
{
	return name.find(text);
}

std::string Utils::toUpperOne(std::string caps)
{

	//std::transform(caps.begin(), caps.end(), caps.begin(), ::toupper);

	for (int i = 0; i < caps.length(); i++)
		caps[i] = toupper(caps[i]);

	return caps;
}

std::string Utils::toUpperTwo(std::string caps, int temp)
{
	if (temp >= caps.size()) {
		return caps;
	}
	caps[temp] = toupper(caps[temp]);
	caps = toUpperTwo(caps, temp + 1);
	return caps;
}
int Utils::randomrangeNum(int& rrnum)
{
	srand((unsigned)time(0));

	rrnum = 10 + rand() % ((60 + 1) - 10);
	return rrnum;
}
std::string Utils::fullplayTime(int time, std::string& playtime)
{
	int hour = 60;

	int hours = time / hour;
	int min = time % hour;
	min = min * 10 / hour;

	if (time <= 59)
	{
		playtime += std::to_string(min);
	}
	if (time >= hour && time <= 419)
	{
		playtime += std::to_string(hours);
		playtime += '.';
		playtime += std::to_string(min);
	}
	if (time >= 420)
	{
		playtime += std::to_string(hours);
	}

	return playtime;
}
std::string Utils::percentRating(int like, int dislike, std::string& percent)
{

	/*int one = dislike / like;
	int two = dislike % like;
	two = two * 10 / like;


		percent = two;*/
	

	return percent;
}
