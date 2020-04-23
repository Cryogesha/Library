#pragma once
#include <string>
#include <map>
#include "Book.h"

class User
{
public:
	User(const std::string& name, const std::string& surname, const unsigned int age, const std::string& phoneNumber, const int id);
	std::string getName() const;
	std::string getSurname() const;
	int getAge() const;
	int getId() const;
private:
	std::string name;
	std::string surname;
	std::string phoneNumber;
	int id;
	unsigned int age;
};

