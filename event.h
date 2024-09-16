#ifndef EVENT_H
#define EVENT_H

using namespace std;

#include <iostream>

class Event {
    protected:
        int posX;
        int posY;
    
    public:
        /*********************************************************************
        ** Function: print_event()
        ** Description: Prints the event information.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        virtual void print_event() = 0;

        /*********************************************************************
        ** Function: print_percept()
        ** Description: Prints the percept information.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        virtual void print_percept() = 0;

        /*********************************************************************
        ** Function: print_encounter()
        ** Description: Prints the encounter information.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        virtual int print_encounter() = 0;

        /*********************************************************************
        ** Function: set_position_x()
        ** Description: Sets the X position.
        ** Parameters:
        ** - position_x: an integer representing the X position
        ** Pre-Conditions: None
        ** Post-Conditions: The X position is set.
        *********************************************************************/
        virtual void set_position_x(int) = 0;

        /*********************************************************************
        ** Function: set_position_y()
        ** Description: Sets the Y position.
        ** Parameters:
        ** - position_y: an integer representing the Y position
        ** Pre-Conditions: None
        ** Post-Conditions: The Y position is set.
        *********************************************************************/
        virtual void set_position_y(int) = 0;

        /*********************************************************************
        ** Function: get_position_x()
        ** Description: Retrieves the X position.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        ** Returns: An integer representing the X position.
        *********************************************************************/
        virtual int get_position_x() = 0;

        /*********************************************************************
        ** Function: get_position_y()
        ** Description: Retrieves the Y position.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        ** Returns: An integer representing the Y position.
        *********************************************************************/
        virtual int get_position_y() = 0;
};

#endif