#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "List.h"

class Player : public User
{
	public:
		Player();
		Player(const std::string&, const std::string&, const std::string&, int, const std::string);
		~Player();
		//const int& GetCredit() const;
		//const std::string& GetRole() const;
		//LibraryItem* library[2] = { }; // TODO: replace with custom List<T> class
		List<LibraryItem*> getLibrary() const;
	private:
		List<LibraryItem*> library;
	//	int credit;
		//std::string role;
};