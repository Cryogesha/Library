#pragma once
#include <map>
#include <iostream>
#include "LibraryManager.h"
#include "UserManager.h"

class InputHandler
{
public:
	static InputHandler& getInstance();
	void showMainMenu();
	void showLibraryManagement();
	void showUserManagement();	
	int getInput();
	void showDeepLibraryManagement();
private:
	void createSubmenusList(std::map<int, std::string>) const;
	void showHeader(const std::string& title) const;
	LibraryManager libManager = LibraryManager::getInstance();
	UserManager userManager = UserManager::getInstance();
	InputHandler() = default;
};

