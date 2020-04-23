#include "UserManager.h"
#include <iostream>
using namespace std;

UserManager& UserManager::getInstance()
{
	static UserManager instance;

	return instance;
}

void UserManager::addUser(const User& user)
{
	users.push_back(user);
}

bool UserManager::searchUser(int id)
{
	for (auto& user : users)
	{
		if (user.getId() == id) return true;
	}
	return false;
}

void UserManager::userInfo() const
{
	cout << "USER LIST\n\n";
	for (auto& user : users)
	{
		cout << "User name: " << user.getName() << "\nUser surname: " << user.getSurname() << "\nUser age: " << user.getAge() << endl;
	}
}

User UserManager::getUserById(int id)
{
	if (searchUser(id))
	{
		for (auto& user : users)
		{
			if (user.getId() == id) return user;
		}
	}
	throw std::invalid_argument("Not found!");
}

void UserManager::removeUserById(int id)
{
	for (auto& user : users)
	{
		auto begin = users.begin();
		if (user.getId() == id)
		{
			users.erase(begin);
			return;
		}
		++begin;
	}
	std::cout << "No matching library!" << std::endl;
}