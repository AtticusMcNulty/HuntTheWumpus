#include "gold.h"

void Gold::print_event() {
    // print object signifier
    cout << "G";
}

void Gold::print_percept() {
    // print object percept
    cout << "\nYou see a glimmer nearby.";
}

int Gold::print_encounter() {
    // print object encounter
    cout << "\n\nYou have grabbed the gold!";

    // return corresponding message
    return 1;
}

void Gold::set_position_x(int x) {
    // set member variable for x coordinate to the value passed in
    this->x = x;
}

void Gold::set_position_y(int y) {
    // set member variable for y coordinate to the value passed in
    this->y = y;
}

int Gold::get_position_x() {
    // return member variable for x coordinate
    return this->x;
}

int Gold::get_position_y() {
    // return member variable for y coordinate
    return this->y;
}