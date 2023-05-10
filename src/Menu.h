//
// Created by Sergio on 05/03/2023.
//

#ifndef AED_PROJECT_2_MENU_H
#define AED_PROJECT_2_MENU_H

#include <stack>
#include <iostream>
#include "TSP.h"

/*
 * Menu's states
 */
enum MenuState{
    INIT_MENU, // Initial menu
    MAIN_MENU, // Main menu
    // To add more menus, just add here
};

/*
 * Menu class to manage interface
 */
class Menu {
private:
    TSP tsp;

    /**
     * @var menuState - stack of menu's states
     */
    std::stack<MenuState> menuState;

    /**
     * @brief Function to get the menu on top menuState stack
     */
    void getMenu();

    /**
     * @var option - option selected by user
     */
    int option{};

    /**
     * @brief Initial menu of application
     */
    void InitMenu();

public:
    /**
     * Constructor of Menu class
     */
    Menu();
};


#endif //AED_PROJECT_2_MENU_H
