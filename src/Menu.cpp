//
// Created by Sergio on 05/03/2023.
//

#include "Menu.h"
#include "TSP.h"

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

using namespace std;

Menu::Menu() {
    this->menuState.push(INIT_MENU);
    getMenu();
}

void Menu::getMenu() {
    if(!this->menuState.empty()){
        switch(this->menuState.top()){
            case INIT_MENU: InitMenu(); break;
            case MAIN_MENU: mainMenu(); break;
            case BASIC_TSP_BACKTRACK: basicTSPBacktrack(); break;
            case BACKTRACK_TSP_TOY: basicTSPBacktrackToy(); break;
            case BACKTRACK_TSP_MEDIUM: basicTSPBacktrackMedium(); break;
            case BACKTRACK_TSP_REAL_WORLD: basicTSPBacktrackRealWorld(); break;
            case WARNING_TSP_MEDIUM: basicTSPWarningMedium();break;
            case WARNING_TSP_REAL_WORLD: basicTSPWarningRealWorld(); break;
            case TRIANGLE_TSP_TOY: basicTSPTriangleToy(); break;
            case TRIANGLE_TSP_MEDIUM: basicTSPTriangleMedium(); break;
            case TRIANGLE_TSP_REAL_WORLD: basicTSPTriangleRealWorld(); break;
            case TSP_TRIANGLE_HEURISTIC: TSPtriangle(); break;
            case TSP_OUR_HEURISTICS: ourHeuristics(); break;
            case HEURISTICS_TSP_TOY: heuristicsTSPToy(); break;
            case HEURISTICS_TSP_MEDIUM: heuristicsTSPMedium(); break;

        }
    } else {

        exit(0);
    }
}

void Menu::mainMenu() {

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
        system(CLEAR_COMMAND);

        cin.clear();
        cin.ignore(1000, '\n');

    } while (this->option < 1 || this->option > 4);

    switch (this->option) {
        case 1: {
            cout << "Creating Graph 1..." << endl;
            tsp.createNodes(tsp.graph, "../data/Real-world Graphs/graph1/nodes.csv");
            tsp.createEdges(tsp.graph, "../data/Real-world Graphs/graph1/edges.csv");

            menuState.push(MAIN_MENU);
            break;
        }
        case 2: {
            cout << "Creating Graph 2..." << endl;
            tsp.createNodes(tsp.graph,"../data/Real-world Graphs/graph2/nodes.csv");
            tsp.createEdges(tsp.graph,"../data/Real-world Graphs/graph1/edges.csv");

            menuState.push(MAIN_MENU);
            break;
        }
        case 3:{
            cout << "Creating Graph 3..." << endl;
            tsp.createNodes(tsp.graph,"../data/Real-world Graphs/graph3/nodes.csv");
            tsp.createEdges(tsp.graph,"../data/Real-world Graphs/graph1/edges.csv");

            menuState.push(MAIN_MENU);
            break;
        }
        case 4: {
            menuState.pop();
            break;
        }
    }
    system(CLEAR_COMMAND);
    getMenu();
}

void Menu::InitMenu() {
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

        system(CLEAR_COMMAND);
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
            menuState.push(TSP_OUR_HEURISTICS);
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
    system(CLEAR_COMMAND);

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
        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 5);

    switch (this->option) {
        case 1: {
            menuState.push(BACKTRACK_TSP_TOY);
            break;
        }
        case 2:{
            menuState.push(WARNING_TSP_MEDIUM);
            break;
        }
        case 3:{
            menuState.push(WARNING_TSP_REAL_WORLD);
            break;
        }
        case 4: {
            menuState.pop();
            break;
        }
        case 5: {
            clearStack();
            break;
        }

    }
    system(CLEAR_COMMAND);

    getMenu();
}
void Menu::basicTSPBacktrackToy() {
    do {
        cout << "Which graph do you want to choose to run backtracking? " << endl;
        cout << "1 - Shipping Graph" << endl;
        cout << "2 - Stadium Graph" << endl;
        cout << "3 - Tourism Graph" << endl;
        cout << "4 - Back" << endl;
        cout << "5 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 5) {
            cout << "Invalid Option!" << endl;
        }

        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 5);

    string number;
    vector<string> res;

    switch (this->option) {
        case 1: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.toyGraphShipping.getNumVertex()];
            double minCost = tsp.tspBT(this->tsp.toyGraphShipping, this->tsp.toyGraphShipping.getNumVertex(),
                                       path);
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << minCost << endl << endl;

            cout << "You should take the following path: " << endl;

            for (int i = 0; i < this->tsp.toyGraphShipping.getNumVertex(); i++) {
                cout << " " << path[i] << " ->";
            }
            cout << " " << path[0] << " (again eheheh ;)" << endl << endl;

            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 2: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.toyGraphStadiums.getNumVertex()];
            double minCost = tsp.tspBT(this->tsp.toyGraphStadiums, this->tsp.toyGraphStadiums.getNumVertex(),
                                       path);
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << minCost << endl << endl;

            cout << "You should take the following path: " << endl;

            for (int i = 0; i < this->tsp.toyGraphStadiums.getNumVertex(); i++) {
                cout << " " << path[i] << " ->";
            }
            cout << " " << path[0] << " (again eheheh ;)" << endl << endl;

            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 3: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.toyGraphTourism.getNumVertex()];
            double minCost = tsp.tspBT(this->tsp.toyGraphTourism, this->tsp.toyGraphTourism.getNumVertex(),
                                       path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << minCost << endl << endl;

            cout << "You should take the following path: " << endl << endl;

            for (int i = 0; i < this->tsp.toyGraphTourism.getNumVertex(); i++) {
                cout << " " << path[i] << " ->";
            }
            cout << " " << path[0] << " (again eheheh ;)" << endl << endl;

            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 4: {
            menuState.pop();
            break;
        }
        case 5: {
            clearStack();
            break;
        }
    }
    system(CLEAR_COMMAND);

    getMenu();
}

void Menu::basicTSPWarningMedium() {
    do {
        cout << "WARNING!!!! " << endl;
        cout << "This algorithm takes a long time to run. Are you sure you want to do it?" << endl;
        cout << "1 - Let's do it" << endl;
        cout << "2 - Back" << endl;
        cout << "3 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 3) {
            cout << "Invalid Option!" << endl;
        }

        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 5);

    switch(this->option){
        case 1: {
            menuState.push(BACKTRACK_TSP_MEDIUM);
            break;
        }
        case 2: {
            menuState.pop();
            break;
        }
        case 3: {
            clearStack();
            break;
        }
    }

    system(CLEAR_COMMAND);
    getMenu();
}

void Menu::basicTSPWarningRealWorld() {
    do {
        cout << "WARNING!!!! " << endl;
        cout << "This algorithm takes a long time to run. Are you sure you want to do it?" << endl;
        cout << "1 - Let's do it" << endl;
        cout << "2 - Back" << endl;
        cout << "3 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 3) {
            cout << "Invalid Option!" << endl;
        }

        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 5);

    switch(this->option){
        case 1: {
            menuState.push(BACKTRACK_TSP_REAL_WORLD);
            break;
        }
        case 2: {
            menuState.pop();
            break;
        }
        case 3: {
            clearStack();
            break;
        }
    }

    system(CLEAR_COMMAND);
    getMenu();
}

void Menu::basicTSPBacktrackMedium() {
    do {
        cout << "Which graph do you want to choose? Pick from 1-12" << endl;
        cout << "1 - Medium - 25 nodes" << endl;
        cout << "2 - Medium - 50 nodes" << endl;
        cout << "3 - Medium - 75 nodes" << endl;
        cout << "4 - Medium - 100 nodes" << endl;
        cout << "5 - Medium - 200 nodes" << endl;
        cout << "6 - Medium - 300 nodes" << endl;
        cout << "7 - Medium - 400 nodes" << endl;
        cout << "8 - Medium - 500 nodes" << endl;
        cout << "9 - Medium - 600 nodes" << endl;
        cout << "10 - Medium - 700 nodes" << endl;
        cout << "11 - Medium - 800 nodes" << endl;
        cout << "12 - Medium - 900 nodes" << endl;
        cout << "13 - Back" << endl;
        cout << "14 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 14) {
            cout << "Invalid Option!" << endl;
        }

        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 14);

    switch (this->option) {
        case 1: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_25.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspBT(tsp.mediumGraph, tsp.mediumGraph.getNumVertex(), path);
            //double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 2: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_50.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspBT(tsp.mediumGraph, tsp.mediumGraph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 3: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_75.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspBT(tsp.mediumGraph, tsp.mediumGraph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 4: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_100.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspBT(tsp.mediumGraph, tsp.mediumGraph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 5: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_200.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspBT(tsp.mediumGraph, tsp.mediumGraph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 6: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_300.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspBT(tsp.mediumGraph, tsp.mediumGraph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 7: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_400.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspBT(tsp.mediumGraph, tsp.mediumGraph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 8: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_500.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspBT(tsp.mediumGraph, tsp.mediumGraph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 9: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_600.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspBT(tsp.mediumGraph, tsp.mediumGraph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 10: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_700.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspBT(tsp.mediumGraph, tsp.mediumGraph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 11: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_800.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspBT(tsp.mediumGraph, tsp.mediumGraph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 12: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_900.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspBT(tsp.mediumGraph, tsp.mediumGraph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 13: {
            menuState.pop();
            break;
        }
        case 14: {
            clearStack();
            break;
        }
    }

    system(CLEAR_COMMAND);

    getMenu();
}

void Menu::basicTSPBacktrackRealWorld() {
    do {
        cout << "Which graph do you want to choose to run backtracking? " << endl;
        cout << "1 - Real 1" << endl;
        cout << "2 - Real 2" << endl;
        cout << "3 - Real 3" << endl;
        cout << "4 - Back" << endl;
        cout << "5 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 5) {
            cout << "Invalid Option!" << endl;
        }

        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 5);

    switch(this->option){
        case 1: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.graph.clearGraph();
            cout << "Creating graph..." << endl;
            tsp.createNodes(this->tsp.graph, "../data/Real-world Graphs/graph1/nodes.csv");
            tsp.createEdges(this->tsp.graph, "../data/Real-world Graphs/graph1/edges.csv");

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.graph.getNumVertex()];
            double cost = tsp.tspBT(tsp.graph, tsp.graph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();
            break;
        }
        case 2: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.graph.clearGraph();
            cout << "Creating graph..." << endl;
            tsp.createNodes(this->tsp.graph, "../data/Real-world Graphs/graph2/nodes.csv");
            tsp.createEdges(this->tsp.graph, "../data/Real-world Graphs/graph2/edges.csv");

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.graph.getNumVertex()];
            double cost = tsp.tspBT(tsp.graph, tsp.graph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();
            break;
        }
        case 3: {
            cout << '\n' << "----------------- BACKTRACK -----------------" << endl;
            tsp.graph.clearGraph();
            cout << "Creating graph..." << endl;
            tsp.createNodes(this->tsp.graph, "../data/Real-world Graphs/graph3/nodes.csv");
            tsp.createEdges(this->tsp.graph, "../data/Real-world Graphs/graph3/edges.csv");

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.graph.getNumVertex()];
            double cost = tsp.tspBT(tsp.graph, tsp.graph.getNumVertex(), path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();
            break;
        }
        case 4: {
            menuState.pop();
            break;
        }
        case 5: {
            clearStack();
            break;
        }
    }

    system(CLEAR_COMMAND);
    getMenu();
}

void Menu::TSPtriangle() {
    do {
        cout << "TSP approximation algorithm using traingle inequality" << endl;
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
        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 5);

    switch (this->option) {
        case 1: {
            menuState.push(TRIANGLE_TSP_TOY);
            break;
        }
        case 2:{
            menuState.push(TRIANGLE_TSP_MEDIUM);
            break;
        }
        case 3:{
            menuState.push(TRIANGLE_TSP_REAL_WORLD);
            break;
        }
        case 4: {
            menuState.pop();
            break;
        }
        case 5: {
            clearStack();
            break;
        }

    }
    system(CLEAR_COMMAND);

    getMenu();
}

void Menu::basicTSPTriangleToy() {
    do {
        cout << "Which graph do you want to choose? " << endl;
        cout << "1 - Shipping Graph" << endl;
        cout << "2 - Stadium Graph" << endl;
        cout << "3 - Tourism Graph" << endl;
        cout << "4 - Back" << endl;
        cout << "5 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 5) {
            cout << "Invalid Option!" << endl;
        }

        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 5);

    string number;
    vector<string> res;

    switch (this->option) {
        case 1: {

            cout << "Ups! Looks like Shipping is not an adequate graph for this approximation. Try again with another! " << endl;
            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 2: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.toyGraphStadiums.getNumVertex()];
            double minCost = tsp.tspTriangleHeuristic(tsp.toyGraphStadiums, path);
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << '\n' << "The minimum cost to travel between all points is " << minCost << endl;

            cout << "You should take the following path: " << endl;

            for (int i = 0; i < this->tsp.toyGraphStadiums.getNumVertex(); i++) {
                cout << " " << path[i] << " ->";
            }
            cout << " " << path[0] << " (again eheheh ;)" << endl << endl;

            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 3: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.toyGraphTourism.getNumVertex()];
            double minCost = tsp.tspTriangleHeuristic(tsp.toyGraphTourism, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << minCost << endl << endl;

            cout << "You should take the following path: " << endl << endl;

            for (int i = 0; i < this->tsp.toyGraphTourism.getNumVertex(); i++) {
                cout << " " << path[i] << " ->";
            }
            cout << " " << path[0] << " (again eheheh ;)" << endl << endl;

            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 4: {
            menuState.pop();
            break;
        }
        case 5: {
            clearStack();
            break;
        }
    }
    system(CLEAR_COMMAND);

    getMenu();
}

void Menu::basicTSPTriangleMedium() {
    do {
        cout << "Which graph do you want to choose? Pick from 1-12" << endl;
        cout << "1 - Medium - 25 nodes" << endl;
        cout << "2 - Medium - 50 nodes" << endl;
        cout << "3 - Medium - 75 nodes" << endl;
        cout << "4 - Medium - 100 nodes" << endl;
        cout << "5 - Medium - 200 nodes" << endl;
        cout << "6 - Medium - 300 nodes" << endl;
        cout << "7 - Medium - 400 nodes" << endl;
        cout << "8 - Medium - 500 nodes" << endl;
        cout << "9 - Medium - 600 nodes" << endl;
        cout << "10 - Medium - 700 nodes" << endl;
        cout << "11 - Medium - 800 nodes" << endl;
        cout << "12 - Medium - 900 nodes" << endl;
        cout << "13 - Back" << endl;
        cout << "14 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 14) {
            cout << "Invalid Option!" << endl;
        }

        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 14);

    switch (this->option) {
        case 1: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_25.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 2: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_50.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 3: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_75.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 4: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_100.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 5: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_200.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 6: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_300.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 7: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_400.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 8: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_500.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 9: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_600.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 10: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_700.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 11: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_800.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 12: {
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            tsp.mediumGraph.clearGraph();
            tsp.createGraph(this->tsp.mediumGraph, "../data/Medium-Graphs/edges_900.csv", false);

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.mediumGraph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.mediumGraph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();

            break;
        }
        case 13: {
            menuState.pop();
            break;
        }
        case 14: {
            clearStack();
            break;
        }
    }

    system(CLEAR_COMMAND);

    getMenu();
}

void Menu::basicTSPTriangleRealWorld() {
    do {
        cout << "Which graph do you want to choose? " << endl;
        cout << "1 - Real 1" << endl;
        cout << "2 - Real 2" << endl;
        cout << "3 - Real 3" << endl;
        cout << "4 - Back" << endl;
        cout << "5 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 5) {
            cout << "Invalid Option!" << endl;
        }

        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 5);

    switch(this->option){
        case 1: {
            tsp.graph.clearGraph();
            cout << "Creating graph..." << endl;
            tsp.createNodes(this->tsp.graph, "../data/Real-world Graphs/graph1/nodes.csv");
            tsp.createEdges(this->tsp.graph, "../data/Real-world Graphs/graph1/edges.csv");

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.graph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.graph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();
            break;
        }
        case 2: {
            tsp.graph.clearGraph();
            cout << "Creating graph..." << endl;
            tsp.createNodes(this->tsp.graph, "../data/Real-world Graphs/graph2/nodes.csv");
            tsp.createEdges(this->tsp.graph, "../data/Real-world Graphs/graph2/edges.csv");

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.graph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.graph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();
            break;
        }
        case 3: {
            tsp.graph.clearGraph();
            cout << "Creating graph..." << endl;
            tsp.createNodes(this->tsp.graph, "../data/Real-world Graphs/graph3/nodes.csv");
            tsp.createEdges(this->tsp.graph, "../data/Real-world Graphs/graph3/edges.csv");

            auto begin = std::chrono::high_resolution_clock::now();
            unsigned int path[this->tsp.graph.getNumVertex()];
            double cost = tsp.tspTriangleHeuristic(tsp.graph, path);

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << '\n' << "----------------- TRIANGULAR APPROXIMATION HEURISTIC -----------------" << endl;
            cout << "The minimum cost to travel between all points is " << cost << endl << endl;

            for (auto i: path){
                cout << i << " -> ";
            }
            cout << path[0] << " (again eheheh ;)" << endl << endl;
            cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

            //wait for user input
            cout << "Press any key to continue...";
            cin.get();
            break;
        }
        case 4: {
            menuState.pop();
            break;
        }
        case 5: {
            clearStack();
            break;
        }
    }

    system(CLEAR_COMMAND);
    getMenu();
}


void Menu::ourHeuristics(){
    do{
        cout << "Which graph do you want to choose to run our heuristics? " << endl;
        cout << "Which graphs do you want to test?" << endl;
        cout << "1 - Toy graphs" << endl;
        cout << "2 - Medium graphs" << endl;
        cout << "3 - Back" << endl;
        cout << "4 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 4) {
            cout << "Invalid Option!" << endl;
        }
        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 4);

    switch (this->option) {
        case 1: {
            menuState.push(HEURISTICS_TSP_TOY);
            break;
        }
        case 2:{
            menuState.push(HEURISTICS_TSP_MEDIUM);
            break;
        }
        case 3: {
            menuState.pop();
            break;
        }
        case 4: {
            clearStack();
            break;
        }

    }
    system(CLEAR_COMMAND);

    getMenu();
}

void Menu::heuristicsTSPToy() {
    do{
        cout << "Which graph do you want to use?" << endl;
        cout << "1 - Shipping" << endl;
        cout << "2 - Stadiums" << endl;
        cout << "3 - Tourism" << endl;
        cout << "4 - Back" << endl;
        cout << "5 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 5) {
            cout << "Invalid Option!" << endl;
        }

        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 5);

    switch(this->option){
        case 1:{
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.toyGraphShipping, path);
                    minCost = tsp.twoOpt(this->tsp.toyGraphShipping, path, minCost);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphShipping.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.toyGraphShipping, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphShipping.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.toyGraphShipping, path);
                    tsp.twoOpt(this->tsp.toyGraphShipping, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.toyGraphShipping, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphShipping.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.toyGraphShipping, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphShipping.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }

            break;
        }
        case 2:{
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(tsp.toyGraphStadiums, path);
                    minCost = tsp.twoOpt(this->tsp.toyGraphStadiums, path, minCost);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphStadiums.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.toyGraphStadiums, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphStadiums.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {

                    auto begin = std::chrono::high_resolution_clock::now();


                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.toyGraphStadiums, path);
                    tsp.twoOpt(this->tsp.toyGraphStadiums, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.toyGraphStadiums, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphStadiums.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.toyGraphStadiums, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphStadiums.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }
                    cout << path[0]->getId() << endl;

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 3:{
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.toyGraphTourism, path);
                    minCost = tsp.twoOpt(this->tsp.toyGraphTourism, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphTourism.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.toyGraphTourism, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphTourism.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.toyGraphTourism, path);
                    tsp.twoOpt(this->tsp.toyGraphTourism, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.toyGraphTourism, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphTourism.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.toyGraphTourism, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.toyGraphTourism.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 4:{
            menuState.pop();
            break;
        }
        case 5:{
            clearStack();
            break;
        }
    }
    system(CLEAR_COMMAND);
    getMenu();
}

void Menu::heuristicsTSPMedium() {
    do {
        cout << "Which graph do you want to choose? Pick from 1-12" << endl;
        cout << "1 - Medium - 25 nodes" << endl;
        cout << "2 - Medium - 50 nodes" << endl;
        cout << "3 - Medium - 75 nodes" << endl;
        cout << "4 - Medium - 100 nodes" << endl;
        cout << "5 - Medium - 200 nodes" << endl;
        cout << "6 - Medium - 300 nodes" << endl;
        cout << "7 - Medium - 400 nodes" << endl;
        cout << "8 - Medium - 500 nodes" << endl;
        cout << "9 - Medium - 600 nodes" << endl;
        cout << "10 - Medium - 700 nodes" << endl;
        cout << "11 - Medium - 800 nodes" << endl;
        cout << "12 - Medium - 900 nodes" << endl;
        cout << "13 - Back" << endl;
        cout << "14 - Exit" << endl;
        cout << "Option: ";
        cin >> this->option;

        if (this->option < 1 || this->option > 14) {
            cout << "Invalid Option!" << endl;
        }

        system(CLEAR_COMMAND);
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

    } while (this->option < 1 || this->option > 14);

    switch (this->option) {
        case 1: {
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_25.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;


                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_25.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_25.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 2: {
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_50.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;


                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_50.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_50.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 3: {
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_75.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_75.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_75.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 4: {
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_100.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;


                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_100.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_100.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 5: {
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_200.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;


                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_200.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_200.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 6: {
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_300.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_300.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_300.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 7: {
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_400.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;


                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_400.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_400.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 8: {
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_500.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;


                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_500.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_500.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 9: {
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_600.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_600.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_600.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 10: {
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_700.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;


                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_700.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_700.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 11: {
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_800.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_800.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_800.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 12: {
            do{
                cout << "Which algorithm do you want to use?" << endl;
                cout << "1 - Nearest Neighboors + 2-Opt" << endl;
                cout << "2 - Simulated Annealing" << endl;
                cout << "3 - Christofides" << endl;
                cout << "4 - Back" << endl;
                cout << "Option: ";
                cin >> this->option;

                if (this->option < 1 || this->option > 4) {
                    cout << "Invalid Option!" << endl;
                }

                system(CLEAR_COMMAND);
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(1000, '\n'); // ignore last input
            } while(this->option < 1 || this->option > 4);

            switch(this->option){
                case 1: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_900.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- NEAREST NEIGHBOORS + 2-OPT MINIMUM PATH -----------------" << endl;
                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;


                    auto begin2 = std::chrono::high_resolution_clock::now();
                    minCost = tsp.twoOpt(this->tsp.mediumGraph, path, minCost);

                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

                    cout << "----------------- 2-OPT MINIMUM PATH OPTIMIZATION -----------------" << minCost << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }

                    cout << "Execution time: " << elapsed2.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 2: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_900.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<int> path;
                    double minCost = tsp.nearestNeighboor(this->tsp.mediumGraph, path);
                    tsp.twoOpt(this->tsp.mediumGraph, path, minCost);
                    path.push_back(0);
                    minCost = tsp.simulatedAnnealing(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- SIMULATED ANNEALING MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i] << " ->";
                    }
                    cout << " " << path[0] << endl;
                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 3: {
                    tsp.mediumGraph.clearGraph();
                    tsp.createGraph(tsp.mediumGraph, "../data/Medium-Graphs/edges_900.csv", false);

                    auto begin = std::chrono::high_resolution_clock::now();

                    vector<Vertex *> path;
                    double minCost = tsp.christofides(this->tsp.mediumGraph, path);

                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout << "----------------- CHRISTOFIDES MINIMUM PATH -----------------" << endl;

                    cout << "The minimum cost to travel between all points is " << minCost << endl;

                    cout << "You should take the following path: " << endl;

                    for (int i = 0; i < this->tsp.mediumGraph.getNumVertex(); i++) {
                        cout << " " << path[i]->getId() << " ->";
                    }

                    cout << "Execution time: " << elapsed.count() * 1e-9 << " seconds." << endl;

                    //wait for user input
                    cout << "Press any key to continue...";
                    cin.get();

                    break;
                }
                case 4: default: {
                    break;
                }
            }
            break;
        }
        case 13: {
            menuState.pop();
            break;
        }
        case 14: {
            clearStack();
            break;
        }
    }

    system(CLEAR_COMMAND);

    getMenu();
}
void Menu::clearStack() {
    while(!this->menuState.empty()){
        this->menuState.pop();
    }
}



