#pragma once
#include <map>
#include <list>
#include "User.h"

class UserManager
{
public:
	static UserManager& getInstance();
	void addUser(const User&);
	bool searchUser(int id);
	User getUserById(int id);
	void removeUserById(int id);
	void userInfo() const;
private:
	std::list<User> users;
	UserManager() = default;
};

