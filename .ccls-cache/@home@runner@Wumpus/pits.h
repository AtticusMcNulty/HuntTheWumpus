#ifndef PITS_H
#define PITS_H

#include <iostream>
#include "event.h"

using namespace std;

class Pits : public Event {
    private:
        int x;
        int y;

    public:
        /*********************************************************************
        ** Function: print_event()
        ** Description: Prints the signifier for the Pits object.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: The signifier for the Pits object is printed.
        *********************************************************************/
        void print_event();

        /*********************************************************************
        ** Function: print_percept()
        ** Description: Prints the percept for the Pits object.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: The percept for the Pits object is printed.
        *********************************************************************/
        void print_percept();

        /*********************************************************************
        ** Function: print_encounter()
        ** Description: Prints the encounter message for the Pits object and returns a corresponding value.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: The encounter message is printed and a value is returned.
        *********************************************************************/
        int print_encounter();

        /*********************************************************************
        ** Function: set_position_x()
        ** Description: Sets the member variable for the x coordinate of the Pits object.
        ** Parameters:
            ** x: An integer representing the x coordinate value.
        ** Pre-Conditions: None
        ** Post-Conditions: The member variable for the x coordinate is updated.
        *********************************************************************/
        void set_position_x(int);

        /*********************************************************************
        ** Function: set_position_y()
        ** Description: Sets the member variable for the y coordinate of the Pits object.
        ** Parameters:
            ** y: An integer representing the y coordinate value.
        ** Pre-Conditions: None
        ** Post-Conditions: The member variable for the y coordinate is updated.
        *********************************************************************/
        void set_position_y(int);

        /*********************************************************************
        ** Function: get_position_x()
        ** Description: Returns the member variable for the x coordinate of the Pits object.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: The member variable for the x coordinate is returned.
        *********************************************************************/
        int get_position_x();

        /*********************************************************************
        ** Function: get_position_y()
        ** Description: Returns the member variable for the y coordinate of the Pits object.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: The member variable for the y coordinate is returned.
        *********************************************************************/
        int get_position_y();
};

#endif