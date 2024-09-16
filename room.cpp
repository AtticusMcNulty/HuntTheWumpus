#include "room.h"

Room::Room() {
    // intialize event pointer to null
    this->e = nullptr;
}

Room::~Room() {
    // deallocate the event pointer
    delete this->e; 
}

Event* Room::get_event_pointer() {
    // return the event pointer member variable
    return this->e;
}

void Room::set_event_pointer(Event* e) {
    // delete current event pointer
    delete this->e;

    // set member variable event pointer to passed in event pointer
    this->e = e;
}