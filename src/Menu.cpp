//
// Created by Sergio on 05/03/2023.
//

#include "Menu.h"

using namespace std;

Menu::Menu() {
    this->menuState.push(INIT_MENU);
    railway = Railway();
    getMenu();
}

void Menu::getMenu() {
    if(!this->menuState.empty()){
        switch(this->menuState.top()){
            case INIT_MENU: InitMenu(); break;

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


