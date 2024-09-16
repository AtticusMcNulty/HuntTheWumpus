#include "pits.h"

void Pits::print_event() {
    // print object signifier
    cout << "P";
}

void Pits::print_percept() {
    // print object percept
    cout << "\nYou feel a breeze.";
}

int Pits::print_encounter() {
    // print object encounter
    cout << "\n\nGAME OVER - You fell into a pit and died.";

    // return corresponding message
    return 0;
}

void Pits::set_position_x(int x) {
    // set member variable for x coordinate to the value passed in
    this->x = x;
}

void Pits::set_position_y(int y) {
    // set member variable for y coordinate to the value passed in
    this->y = y;
}

int Pits::get_position_x() {
    // return member variable for x coordinate
    return this->x;
}

int Pits::get_position_y() {
    // return member variable for y coordinate
    return this->y;
}