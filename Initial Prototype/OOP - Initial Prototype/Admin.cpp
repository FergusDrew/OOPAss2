#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const std::string& created, int credit, const std::string role) : Player(username, password, created, credit, role)
{
}

Admin::~Admin()
{
}