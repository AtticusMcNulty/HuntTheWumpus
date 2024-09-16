#ifndef ROOM_H
#define ROOM_H

#include "event.h"
#include <iostream>

using namespace std;

class Room {
    private:
        Event *e;

    public:
        /*********************************************************************
        ** Function: Room()
        ** Description: Constructor for the Room class. Initializes the event pointer to null.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: The event pointer is set to null.
        *********************************************************************/
        Room();

        /*********************************************************************
        ** Function: ~Room()
        ** Description: Destructor for the Room class. Deallocates the event pointer.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: The event pointer is deallocated.
        *********************************************************************/
        ~Room();

        /*********************************************************************
        ** Function: get_event_pointer()
        ** Description: Getter function for the event pointer.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: The event pointer is returned.
        *********************************************************************/
        Event* get_event_pointer();

        /*********************************************************************
        ** Function: set_event_pointer()
        ** Description: Setter function for the event pointer. Deletes the current event pointer and assigns the passed-in event pointer.
        ** Parameters:
            ** e: Pointer to an Event object
        ** Pre-Conditions: None
        ** Post-Conditions: The event pointer is updated with the passed-in event pointer.
        *********************************************************************/
        void set_event_pointer(Event*);
};

#endif