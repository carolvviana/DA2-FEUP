//
// Created by Sergio on 05/03/2023.
//

#include "Menu.h"
#include "TSP.h"

using namespace std;

Menu::Menu() {
    this->menuState.push(INIT_MENU);
    tsp = TSP();
    getMenu();
}

void Menu::getMenu() {
    if(!this->menuState.empty()){
        switch(this->menuState.top()){
            case INIT_MENU: InitMenu(); break;
            case MAIN_MENU: mainMenu(); break;
            case BASIC_TSP_BACKTRACK: basicTSPBacktrack(); break;
            case TSP_TRIANGLE_HEURISTIC: TSPtriangle(); break;
        }
    } else {

        exit(0);
    }
}

void Menu::InitMenu() {

    do {
        cout << "Initial Menu" << endl;
        cout << "1 - Read Graph 1" << endl;
        cout << "2 - Read Graph 2" << endl;
        cout << "3 - Read Graph 3" << endl;
        cout << "4 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 4) {
            cout << "Invalid Option!" << endl;
        }
        cin.clear();
        cin.ignore(1000, '\n');

    } while (this->option < 1 || this->option > 4);

    switch (this->option) {
        case 1: {
            tsp.createNodes("../data/Real-World-Graphs/graph1/nodes.csv");
            tsp.createEdges("../data/Real-World-Graphs/graph1/edges.csv");

            menuState.push(MAIN_MENU);
            break;
        }
        case 2: {
            tsp.createNodes("../data/Real-World-Graphs/graph2/nodes.csv");
            tsp.createEdges("../data/Real-World-Graphs/graph1/edges.csv");

            menuState.push(MAIN_MENU);
            break;
        }
        case 3:{
            tsp.createNodes("../data/Real-World-Graphs/graph3/nodes.csv");
            tsp.createEdges("../data/Real-World-Graphs/graph1/edges.csv");

            menuState.push(MAIN_MENU);
            break;
        }
        case 4: {
            menuState.pop();
            break;
        }
    }

    getMenu();
}


void Menu::mainMenu() {
    do{
        cout << "Main Menu" << endl;
        cout << "1 - Basic TSP with Backtracking" << endl;
        cout << "2 - TSP with Triangular Approximation Heuristic" << endl;
        cout << "3 - Our own algorithm" << endl;
        cout << "4 - Back" << endl;
        cout << "5 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 5) {
            cout << "Invalid Option!" << endl;
        }

        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 5);

    switch(this->option){
        case 1: {
            menuState.push(BASIC_TSP_BACKTRACK);
            break;
        }
        case 2: {
            menuState.push(TSP_TRIANGLE_HEURISTIC);
            break;
        }
        case 3:{
            menuState.push(MAIN_MENU);
            break;
        }
        case 4: {
            //return
            menuState.pop();
            break;
        }
        case 5: {
            //exit
            clearStack();
            break;
        }
    }

    getMenu();
}






void Menu::clearStack() {
    while(!this->menuState.empty()){
        this->menuState.pop();
    }
}


