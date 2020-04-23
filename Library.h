#pragma once
#include <string>
#include <list>
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include "Book.h"
#include "User.h"

class Library
{
public:
	int getId() const;
	std::string getName() const;
	std::string getLocation() const;
	void bookList() const;
	int howMany(const std::string&) const;
	void addBooks(const Book&, const unsigned int id);
	bool search(const std::string&) const;
	bool search(const unsigned int id) const;
	bool isBinded(const unsigned int id) const;
	Book getBook(const unsigned int id) const;
	int getBookId(const unsigned int isbn) const;
	void bindBookTo(const unsigned int, const unsigned int);
	void handOverABook(const unsigned int id, int);
	Library(const std::string&, const int, const std::string&);
private:
	//std::map<int, Book> books
	//std::map<int, std::vector<Book>> bindedBooks
	std::map<int, Book> books;
	std::map<int, std::list<Book>> bindedBooks;
	std::string name;
	std::string location;
	int id;
};

