#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "List.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const std::string&, int, const std::string&);
		~Player();
		const int& GetCredit() const;
		const std::string& GetRole() const;
		void AddCredit(int& val);
		const List<LibraryItem*> getPlayersLibrary() const;
		List<LibraryItem*> getLibrary() const;
		void addLibraryItem(LibraryItem* item);
	private:
		List<LibraryItem*> library;
		int credit;
		std::string role;
};