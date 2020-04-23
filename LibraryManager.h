#pragma once
#include <vector>
#include <list>
#include <iostream>
#include "Library.h"

class LibraryManager
{
public:
	void addLibrary(const Library&);
	void removeLibraryById(int id);
	void librariesInfo() const;
	bool searchById(int id) const;
	Library* getLibraryReference(int id);
	static LibraryManager& getInstance();
private:
	LibraryManager() = default;
	std::list<Library> libraries;
};

