#include "User.h"

User::User(const std::string& name, const std::string& surname, const unsigned int age, const std::string& phoneNumber, const int id)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->phoneNumber = phoneNumber;
	this->id = id;
}

int User::getId() const
{
	return id;
}

//void User::bindBook(Book* b, int id)
//{
//	userBooks.insert(std::make_pair(b, id));
//}
//
//
//int User::getBindedBookID() const
//{
//	return bindedBookID;
//}

int User::getAge() const
{
	return age;
}

std::string User::getName() const
{
	return name;
}

std::string User::getSurname() const
{
	return surname;
}
