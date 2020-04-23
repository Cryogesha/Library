#pragma once
#include <algorithm>
#include "Library.h"

Library::Library(const std::string& name, const int id, const std::string& location)
{
	this->name = name;
	this->id = id;
	this->location = location;
}

int Library::getId() const
{
	return id;
}

std::string Library::getName() const
{
	return name;
}

std::string Library::getLocation() const
{
	return location;
}

void Library::bookList() const
{
	if (books.size() != 0)
	{
		for (auto& book : books)
		{
			std::cout << "Book name: " << book.second.getName() << " ----- " << " ISBN: " << book.second.getISBN() << " ----- Instances: " << howMany(book.second.getName()) << std::endl;
			if (isBinded(book.first))
			{
				for (auto& book : bindedBooks)
				{
					std::cout << "Binded to: " << book.first << std::endl;
				}
			}
		}
	}
	else {
		std::cout << "The library is empty!\n";
	}
}

bool Library::search(const std::string& name) const
{
	for (auto& book : books)
	{
		if (book.second.getName() == name)
		{
			return true;
		}
	}
	return false;
}

void Library::handOverABook(const unsigned int bookId, int userId)
{
	if (isBinded(bookId))
	{
		bindedBooks.at(userId).erase(std::remove(bindedBooks.at(userId).begin(), bindedBooks.at(userId).end(), getBook(bookId)));
	}
	else
		std::cout << "No matching book!" << std::endl;
}

bool Library::search(const unsigned int id) const
{
	if (books.find(id) == books.end()) return false;

	return true;
}

int Library::howMany(const std::string& name) const
{
	int count = 0;
	for (auto& book : books)
	{
		if (book.second.getName() == name)
			++count;
	}
	return count;
}

void Library::addBooks(const Book& book, const unsigned int id)
{
	books.insert(std::make_pair(id, book));
}

Book Library::getBook(const unsigned int id) const
{
	for (auto book : books)
	{
		if (book.first == id) return book.second;
	}
	throw std::invalid_argument("No book!");
}

bool Library::isBinded(const unsigned int id) const
{
	for (auto& binded : bindedBooks)
	{
		for (auto& bindedBook : binded.second)
		{
			if (getBookId(bindedBook.getISBN()) == id) return true;
		}
	}
	return false;
}

int Library::getBookId(const unsigned int isbn) const
{
	for (auto& book : books)
	{
		if (book.second.getISBN() == isbn) return book.first;
	}
	throw std::invalid_argument("Not found!");
}

void Library::bindBookTo(const unsigned int userId, const unsigned int bookId)
{
	if (search(bookId))
	{
		if (isBinded(bookId))
		{
			std::cout << "The book is already binded!\n";
		}
		else 
		{
			if (bindedBooks.find(userId) == bindedBooks.end())
			{
				std::list<Book> booksToAdd;
				bindedBooks.insert(std::make_pair(userId, booksToAdd));
			}

			bindedBooks.at(userId).push_back(getBook(bookId));
		}
	}
	else
	{
		std::cout << "No matching book!\n";
	}
}