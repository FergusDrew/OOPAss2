#pragma once

#include <string>

class Game
{
	public:
		Game(int, const std::string&, const std::string&, int, int);
		~Game();
		const int& GetId() const;
		const std::string& GetName() const;
		const std::string& GetDescription() const;
		const int& GetCost() const;
		const int& GetRating() const;
	private:
		int id;
		std::string name;
		std::string description;
		int cost;
		int ageRating;
};