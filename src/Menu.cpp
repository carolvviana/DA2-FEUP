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
void Menu::basicTSPBacktrack() {

    do {
        cout << "Basic TSP with backtrack" << endl;
        cout << "Which graphs do you want to test?" << endl;
        cout << "1 - Toy graphs" << endl;
        cout << "2 - Medium graphs" << endl;
        cout << "3 - Real World graphs" << endl;
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

    switch (option) {
        case 1: {
            do {
                cout << "1 - Shipping Graph" << endl;
                cout << "2 - Stadium Graph" << endl;
                cout << "3 - Tourism Graph" << endl;
                cout << "Option:" << endl;
                cin >> this->option;

                if (this->option < 1 || this->option > 3) {
                    cout << "Invalid Option!" << endl;
                }

                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input

            } while (this->option < 1 || this->option > 3);

            string number;
            vector<string> res;

            switch (this->option) {
                case 1: {
                    unsigned int path[this->tsp.toyGraphShipping.getNumVertex()];
                    double minCost = tsp.tspBT(this->tsp.toyGraphShipping, this->tsp.toyGraphShipping.getNumVertex(),
                                               path);

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphShipping.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << " (again eheheh ;)" << endl;

                    break;
                }
                case 2: {

                    unsigned int path[this->tsp.toyGraphStadiums.getNumVertex()];
                    double minCost = tsp.tspBT(this->tsp.toyGraphStadiums, this->tsp.toyGraphStadiums.getNumVertex(),
                                               path);

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphStadiums.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << " (again eheheh ;)" << endl;

                    break;
                }

                case 3: {

                    unsigned int path[this->tsp.toyGraphTourism.getNumVertex()];
                    double minCost = tsp.tspBT(this->tsp.toyGraphTourism, this->tsp.toyGraphTourism.getNumVertex(),
                                               path);

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphTourism.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << " (again eheheh ;)" << endl;


                    break;
                }
            }
            break;

        }

        case 2: {
            do {
                cout << "Which graph do you want to choose? Pick from 1-12" << endl;
                cout << "Option:" << endl;
                cin >> this->option;

                if (this->option < 1 || this->option > 12) {
                    cout << "Invalid Option!" << endl;
                }

                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input

            } while (this->option < 1 || this->option > 12);

            switch (this->option) {
                case 1: {
                    unsigned int path[this->tsp.toyGraphStadiums.getNumVertex()];
                    double cost = tsp.tspTriangleHeuristic(tsp.toyGraphStadiums, path);

                    for (auto i: path){
                        cout << i << " -> " <<'\n';
                    }
                    cout << cost << endl;
                    break;
                }
                case 2: {

                    std::vector<int> path;
                    double cost = tsp.nearestNeighboor(tsp.toyGraphStadiums, path);

                    for (auto i: path){
                        cout << i << " -> " <<'\n';
                    }
                    cout << cost << endl;
                    cout << endl;

                    double cost2 = tsp.twoOpt(tsp.toyGraphStadiums, path, cost);

                    for (auto i: path){
                        cout << i << " -> " <<'\n';
                    }
                    cout << cost2 << endl;
                    break;
                }
                case 3: {

                    break;
                }
                case 4: {

                    break;
                }
                case 5: {

                    break;
                }
                case 6: {

                    break;
                }
                case 7: {

                    break;
                }
                case 8: {

                    break;
                }
                case 9: {

                    break;
                }
                case 10: {

                    break;
                }
                case 11: {

                    break;
                }
                case 12: {

                    break;
                }


                    break;
            }
            case 4: {
                string station1;

                do {

                } while (true);

                break;

            }
            case 5: {
                //back
                menuState.pop();
                break;
            }
            case 6: {
                //exit
                clearStack();
                break;
            }
        }

            getMenu();
    }

}

void Menu::TSPtriangle() {
    unsigned int path[this->tsp.graph.getNumVertex()];
    double cost = tsp.tspTriangleHeuristic(tsp.graph, path);

    for (auto i: path){
        cout << i << " -> " <<'\n';
    }
    cout << cost << endl;
    return;
}





void Menu::clearStack() {
    while(!this->menuState.empty()){
        this->menuState.pop();
    }
}


