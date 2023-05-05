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
        cout << "1 - Read default files" << endl;
        cout << "2 - Read custom files" << endl;
        cout << "3 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 3) {
            cout << "Invalid Option!" << endl;
        }
        cin.clear();
        cin.ignore(1000, '\n');

    } while (this->option < 1 || this->option > 3);

    switch (this->option) {
        case 1: {

            menuState.push(MAIN_MENU);
            break;
        }
        case 2: {

            menuState.push(MAIN_MENU);
            break;
        }
        case 3: {
            menuState.pop();
            break;
        }
    }

    getMenu();
}


