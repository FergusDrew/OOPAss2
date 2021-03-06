#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "List.h"
#include <vector>
#include <algorithm>
#include <iterator>

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const std::string&, int, const std::string&);
		~Player();
		const int& GetCredit() const;
		const std::string& GetRole() const;
		void AddCredit(int& val);
		void DecreaseCredit(int& val);
		const std::vector <LibraryItem*> getPlayersLibrary() const;
		std::vector <LibraryItem*> getLibrary() const;
		void addLibraryItem(LibraryItem* item);
		void sortByDate();
		void sortByName();
	private:
		std::vector <LibraryItem*> library;
		//List<LibraryItem*> library; This doesnt really work once out of scope it destrys the list 
		int credit;
		std::string role;
};