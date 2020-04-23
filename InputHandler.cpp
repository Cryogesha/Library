#include "InputHandler.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Library.h"

using namespace std;

InputHandler& InputHandler::getInstance()
{
	static InputHandler instance;

	return instance;
}

void InputHandler::showMainMenu() 
{
	showHeader("MAIN MENU");
	map<int, string> submenus;
	submenus.insert(make_pair(1, "Library management"));
	submenus.insert(make_pair(2, "User management"));
	createSubmenusList(submenus);
	int result = getInput();
	
	if (result == 1) showLibraryManagement();
	if (result == 2) showUserManagement();
	if (result == -1) exit(0);
}

void InputHandler::showUserManagement()
{
	showHeader("USER MANAGEMENT");
	map<int, string> submenus;
	submenus.insert(make_pair(1, "Add user"));
	submenus.insert(make_pair(2, "Remove user"));
	submenus.insert(make_pair(3, "Users"));
	createSubmenusList(submenus);
	int result = getInput();
	
	if (result == 1)
	{
		string name, surname, phoneNumber;
		int age, id;
		cout << "\nEnter user name: ";
		cin >> name;
		cout << "\nEnter user surname: ";
		cin >> surname;
		cout << "\nEnter phone number: ";
		cin >> phoneNumber;
		cout << "\nEnter user age: ";
		cin >> age;
		cout << "\nEnter user id: ";
		cin >> id;
		User newLib(name, surname, age, phoneNumber, id);
		if (userManager.searchUser(id))
		{
			cout << "Such user already exists!\n";
			showUserManagement();
		}
		else
		{
			userManager.addUser(newLib);
			cout << "User was successfully added!\n";
			showUserManagement();
		}
		showUserManagement();
	}

	else if (result == 2)
	{
		cout << "Enter user id: ";
		int id = getInput();
		if (userManager.searchUser(id))
		{
			userManager.removeUserById(id);
			showUserManagement();
		}
		else
		{
			cout << "No such user\n";
			showUserManagement();
		}
	}
	else if (result == 3)
	{
		userManager.userInfo();
		showUserManagement();
	}

	else if (result == 0) showMainMenu();
	else if (result == -1) exit(0);
}

void InputHandler::showLibraryManagement()
{
	showHeader("LIBRARY MANAGEMENT");
	map<int, string> submenus;
	submenus.insert(make_pair(1, "Add library"));
	submenus.insert(make_pair(2, "Remove library"));
	submenus.insert(make_pair(3, "Libraries"));
	createSubmenusList(submenus);
	int result = getInput();
	if (result == 1) {
		int id;
		string name;
		string location;
		cout << "\nEnter library name: ";
		cin >> name;
		cout << "\nEnter library id: ";
		cin >> id;
		cout << "\nEnter library location: ";
		cin >> location;

		if (libManager.searchById(id)) {
			cout << "Library with such id already exists!\n";
			showLibraryManagement();
		} 
		else {
			Library newLib(name, id, location);
			libManager.addLibrary(newLib);
			cout << "Library was successfully added!\n";
			showLibraryManagement();
		}
	}

	else if (result == 2)
	{
		int id;
		cout << "\nEnter library id: ";
		cin >> id;
		if (id == 0) showLibraryManagement();
		if (libManager.searchById(id))
		{
			libManager.removeLibraryById(id);
			cout << "Library is successfully removed!\n";
			showLibraryManagement();
		}
		else {
			cout << "Not found\n";
			showLibraryManagement();
		}
	}

	else if (result == 3) {
		showDeepLibraryManagement();
	}

	else if (result == 0) showMainMenu();
	else if (result == -1) exit(0);
}

void InputHandler::showDeepLibraryManagement()
{
	showHeader("SPECIFIC LIBRARY MANAGEMENT");
	libManager.librariesInfo();
	
	cout << "Enter library id: ";
	int id = getInput();
	if (id == 0) showLibraryManagement();
	else if (id == -1) exit(0);
	if (libManager.searchById(id))
	{
		Library* lib = libManager.getLibraryReference(id);
		map<int, string> submenu;
		submenu.insert(make_pair(1, "Add book"));
		submenu.insert(make_pair(2, "Bind book"));
		submenu.insert(make_pair(3, "Hand over a book"));
		createSubmenusList(submenu);
		int result = getInput();
		if (result == 1)
		{
			int isbn, id;
			string bookName;

			cout << "Enter book name: ";
			cin >> bookName;
			cout << "Enter book isbn: ";
			cin >> isbn;
			cout << "Enter book id: ";
			cin >> id;

			if (lib->search(id))
			{
				cout << "Book with such id already exists!\n";
				showDeepLibraryManagement();
			}
			else
			{
				Book newBook(bookName, isbn, id);
				lib->addBooks(newBook, id);
				cout << "Book was successfully added!\n";
				showDeepLibraryManagement();
			}
		}

		else if (result == 2)
		{
			cout << "Enter user id: ";
			int userId = getInput();
			cout << "Enter book id: ";
			int bookId = getInput();
			if (lib->isBinded(bookId))
			{
				cout << "This book is already binded!\n";
				showDeepLibraryManagement();
			}
			else
			{
				lib->bindBookTo(userManager.getUserById(userId).getId(), bookId);
				showDeepLibraryManagement();
			}
		}

		else if (result == 3)
		{
			cout << "Enter book id: ";
			int bookId = getInput();
			cout << "Enter user id: ";
			int userId = getInput();
			lib->handOverABook(bookId, userId);
			cout << "Book was successfully handovered!\n";
			showDeepLibraryManagement();
		}

		else if (result == 0) showLibraryManagement();
		else if (result == -1) exit(0);
	}
}

void InputHandler::showHeader(const string& title) const
{
	cout << setw(50) << "************" << title << "*************" << right << endl;
	cout << "Enter a number which corresponds to what you want to do \nwrite \"0\" to go back \nwrite \"-1\" to leave\n\n";
}

void InputHandler::createSubmenusList(std::map<int, std::string> submenus) const
{
	for (auto& menu : submenus)
	{
		cout << menu.first << ". " << menu.second << endl;
	}
}

int InputHandler::getInput()
{
	int userInputValue;
	cin >> userInputValue;
	return userInputValue;
}