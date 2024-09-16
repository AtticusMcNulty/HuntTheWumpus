#include "wumpus.h"

void Wumpus::print_event() {
    // print object signifier
    cout << "W";
}

void Wumpus::print_percept() {
    // print object percept
    cout << "\nYou smell a terrible stench.";
}

int Wumpus::print_encounter() {
    // print object encounter
    cout << "\n\nGAME OVER - You were eaten by the wumpus.";

    // return corresponding message
    return 0;
}

void Wumpus::set_position_x(int x) {
    // set member variable for x coordinate to the value passed in
    this->x = x;
}

void Wumpus::set_position_y(int y) {
    // set member variable for y coordinate to the value passed in
    this->y = y;
}

int Wumpus::get_position_x() {
    // return member variable for x coordinate
    return this->x;
}

int Wumpus::get_position_y() {
    // return member variable for y coordinate
    return this->y;
}