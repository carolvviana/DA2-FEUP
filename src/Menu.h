#ifndef AED_PROJECT_2_MENU_H
#define AED_PROJECT_2_MENU_H

#include <stack>
#include <iostream>
#include <chrono>
#include "TSP.h"

/*
 * Menu's states
 */
enum MenuState{
    INIT_MENU, // Initial menu
    MAIN_MENU, // Main menu
    BASIC_TSP_BACKTRACK,// To add more menus, just add here
    TSP_TRIANGLE_HEURISTIC,
    TSP_OUR_HEURISTICS,
    BACKTRACK_TSP_TOY,
    BACKTRACK_TSP_MEDIUM,
    BACKTRACK_TSP_REAL_WORLD,
    WARNING_TSP_MEDIUM,
    WARNING_TSP_REAL_WORLD,
    TRIANGLE_TSP_TOY,
    TRIANGLE_TSP_MEDIUM,
    TRIANGLE_TSP_REAL_WORLD,
    HEURISTICS_TSP_TOY,
    HEURISTICS_TSP_MEDIUM
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
    int option;

    /**
     * @brief Initial menu of application
     */
    void InitMenu();

    void mainMenu();

    void basicTSPBacktrack();

    void TSPtriangle();

    void clearStack();

    void ourHeuristics();

    void basicTSPBacktrackToy();

    void basicTSPWarningRealWorld();

    void basicTSPWarningMedium();

    void basicTSPBacktrackMedium();

    void basicTSPBacktrackRealWorld();

    void basicTSPTriangleToy();

    void basicTSPTriangleMedium();

    void basicTSPTriangleRealWorld();

    void heuristicsTSPToy();

    void heuristicsTSPMedium();

public:
    /**
     * Constructor of Menu class
     */
    Menu();
};


#endif //AED_PROJECT_2_MENU_H
