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

std::string Utils::CastToPrice(int price)
{
	float n1 = price;
	n1 = n1 / 100;
	std::stringstream sstream;
	sstream << n1;
	std::string num_str = sstream.str();
	return num_str;
}