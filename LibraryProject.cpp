#include <iostream>
#include <list>
#include <iomanip>
#include <map>
#include "LibraryManager.h"
#include "Library.h"
#include "User.h"
#include "InputHandler.h"

int main()
{
    InputHandler inputHandler = InputHandler::getInstance();

    inputHandler.showMainMenu();
    /*Library lavGrqer("lav grqer", 0, "varujani 21");
    std::cout << std::boolalpha;
    lavGrqer.addBooks(Book("paterazm ev xaxaxutyun", 1200), 35);
    lavGrqer.addBooks(Book("paterazm ev xaxaxutyun", 1500), 45);
    libManager.addLibrary(lavGrqer);
    Library norGrqer("nor grqer", 1, "tichina 30");
    norGrqer.addBooks(Book("cuyliky", 5300), 67);
    norGrqer.addBooks(Book("mardy", 9543), 98);
    libManager.addLibrary(norGrqer);

    User* david = new User("david", "galstyan", 15, "091-72-18-20");
    norGrqer.bindBookTo(david, 5300);
    norGrqer.handOverABook(5300);
    libManager.librariesInfo();*/
}

