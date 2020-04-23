#include "Book.h"

Book::Book(const std::string& name, const int isbn, const int id)
{
	this->name = name;
	this->id = id;
	this->isbn = isbn;
}

std::string Book::getName() const
{
	return name;
}

bool Book::operator==(const Book& book)
{
	if (book.getId() == this->getId()) return true;

	return false;
}

bool Book::operator<(const Book& book)
{
	if (this->getISBN() < book.getISBN())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Book::getId() const
{
	return id;
}
int Book::getISBN() const
{
	return isbn;
}

