#pragma once
#include <string>
#include "User.h"

class Book
{
public:
	Book(const std::string&, const int isbm, const int id);
	std::string getName() const;
	bool operator==(const Book& b);
	bool operator<(const Book& b);
	int getId() const;
	int getISBN() const;
private:
	int userId;
	std::string name;
	int isbn;
	int id;
};

