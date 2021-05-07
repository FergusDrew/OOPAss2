#include "Game.h"

Game::Game(int id, const std::string& name, const std::string& desc, int cost, int rating, int likes, int dislikes)
	: id(id), name(name), description(desc), cost(cost), ageRating(rating), thelikes(likes), thedislikes(dislikes)
{
}

Game::~Game()
{
}

const int& Game::GetId() const
{
	return id;
}

const std::string& Game::GetName() const
{
	return name;
}

const std::string& Game::GetDescription() const
{
	return description;
}

const int& Game::GetCost() const
{
	return cost;
}

const int& Game::GetRating() const
{
	return ageRating;
}
const int& Game::GetLikes() const
{
	return thelikes;
}

const int& Game::GetDislikes() const
{
	return thedislikes;
}