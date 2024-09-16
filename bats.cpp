#include "bats.h"

void Bats::print_event() {
    // print object signifier
    cout << "B";
}

void Bats::print_percept() {
    // print object percept
    cout << "\nYou hear wings flapping.";
}

int Bats::print_encounter() {
    // print object encounter
    cout << "\n\nYou stumbled into a group of bats, you will be disoriented for the next five moves.";

    // return corresponding message
    return 2;
}

void Bats::set_position_x(int x) {
    // set member variable for x coordinate to the value passed in
    this->x = x;
}

void Bats::set_position_y(int y) {
    // set member variable for y coordinate to the value passed in
    this->y = y;
}

int Bats::get_position_x() {
    // return member variable for x coordinate
    return this->x;
}

int Bats::get_position_y() {
    // return member variable for y coordinate
    return this->y;
}