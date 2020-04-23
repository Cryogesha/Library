#include "LibraryManager.h"

LibraryManager& LibraryManager::getInstance()
{
	static LibraryManager instance;

	return instance;
}

bool LibraryManager::searchById(int id) const
{
	for (auto& library : libraries)
	{
		if (library.getId() == id) {
			return true;
		}
	}
	return false;
}

Library* LibraryManager::getLibraryReference(int id)
{
	if (searchById(id))
	{
		for (auto& library : libraries)
		{
			if (library.getId() == id) return &library;
		}
	}
	throw std::invalid_argument("Not found!");
}

void LibraryManager::addLibrary(const Library& lib)
{
	libraries.push_back(lib);
}

void LibraryManager::removeLibraryById(int id)
{
	for (auto& library : libraries)
	{
		auto begin = libraries.begin();
		if (library.getId() == id)
		{
			libraries.erase(begin);
			return;
		}
		++begin;
	}
	std::cout << "No matching library!" << std::endl;
}

void LibraryManager::librariesInfo() const
{
	if (libraries.size() != 0)
	{
		for (auto& library : libraries)
		{
			std::cout << "Library name: " << library.getName() << "\nLibrary ID: " << library.getId() << "\nLibrary location: " << library.getLocation();
			std::cout << "\n****BOOK LIST****\n";

			library.bookList();

			std::cout << std::endl;
		}
	}
	else
		std::cout << "No libraries!\n";
}
