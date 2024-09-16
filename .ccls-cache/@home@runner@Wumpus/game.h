#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "room.h"
#include "wumpus.h"
#include "gold.h"
#include "pits.h"
#include "bats.h"

using namespace std;

class Game {
    private:
        int playerX;
        int playerY;

        int orgX;
        int orgY;

        vector<Room*> event_arr;

        vector< vector<Room*> > grid;

        bool hasGold = false;
        bool killedWumpus = false;

    public:
        /*********************************************************************
        ** Constructor: Game::Game()
        ** Description: Constructs a Game object and sets up the game.
        ** Parameters: None.
        ** Pre-Conditions: None.
        ** Post-Conditions: A Game object is created and the game is set up.
        *********************************************************************/
        Game();

        /*********************************************************************
        ** Destructor: Game::~Game()
        ** Description: Destructs a Game object and deallocates memory for event_arr and grid.
        ** Parameters: None.
        ** Pre-Conditions: None.
        ** Post-Conditions: The Game object is destroyed and memory is deallocated.
        *********************************************************************/
        ~Game();

        /*********************************************************************
        ** Function: set_up_game()
        ** Description: Sets up the game by obtaining user input, populating the event_arr, populating the grid, and running the game.
        ** Parameters: None.
        ** Pre-Conditions: None.
        ** Post-Conditions: The game is set up and run.
        *********************************************************************/
        void set_up_game();

        /*********************************************************************
        ** Function: initialize_user_input()
        ** Description: Initializes the user input for grid size and game mode.
        ** Parameters: None.
        ** Pre-Conditions: None.
        ** Post-Conditions: The user input for grid size and game mode is obtained.
        ** Returns: The game mode ('t' for debug mode, 'n' for normal mode).
        *********************************************************************/
        char initialize_user_input();

        /*********************************************************************
        ** Function: initialize_null_grid()
        ** Description: Initializes the grid with null values.
        ** Parameters:
            ** row: The number of rows in the grid.
            ** col: The number of columns in the grid.
        ** Pre-Conditions: None.
        ** Post-Conditions: The grid is initialized with null values.
        *********************************************************************/
        void initialize_null_grid(int, const int);

        /*********************************************************************
        ** Function: populate_event_arr()
        ** Description: Populates the event_arr with Room objects and assigns child classes to each Room.
        ** Parameters: None.
        ** Pre-Conditions: None.
        ** Post-Conditions: The event_arr is populated with Room objects and child classes are assigned.
        *********************************************************************/
        void populate_event_arr();

        /*********************************************************************
        ** Function: populate_grid()
        ** Description: Populates the grid with events (gold, wumpus, bats, pits) and sets the user's initial position.
        ** Parameters: None.
        ** Pre-Conditions: None.
        ** Post-Conditions: The grid is populated with events and the user's initial position is set.
        *********************************************************************/
        void populate_grid();

        /*********************************************************************
        ** Function: run_game()
        ** Description: Runs the game loop until the game ends (death or victory).
        ** Parameters:
            ** debug: The mode in which the game should be run ('t' for debug mode, 'n' for normal mode).
        ** Pre-Conditions: None.
        ** Post-Conditions: The game loop is executed until the game ends.
        *********************************************************************/
        void run_game(const char);

         /*********************************************************************
        ** Function: print_debug_grid()
        ** Description: Prints the debug grid with the current state of the game.
        ** Parameters: None.
        ** Pre-Conditions: None.
        ** Post-Conditions: The debug grid is printed with the current state of the game.
        *********************************************************************/
        void print_debug_grid() const;

        /*********************************************************************
        ** Function: print_grid()
        ** Description: Prints the normal grid with the current state of the game.
        ** Parameters: None.
        ** Pre-Conditions: None.
        ** Post-Conditions: The normal grid is printed with the current state of the game.
        *********************************************************************/
        void print_grid() const;

        /*********************************************************************
        ** Function: print_object()
        ** Description: Prints the grid element at the specified coordinates.
        ** Parameters:
            ** x: The row index of the grid element.
            ** y: The column index of the grid element.
            ** k: The line number in the grid to determine formatting.
        ** Pre-Conditions: None.
        ** Post-Conditions: The grid element is printed in a formatted manner.
        *********************************************************************/
        void print_object(const int, const int, const int) const;

        /*********************************************************************
        ** Function: check_direction()
        ** Description: Checks the user's direction and validates it.
        ** Parameters:
            ** direction: The direction in which the user wants to move ('w', 'a', 's', or 'd').
            ** reverseCounter: The number of reverse movements the player must complete due to encountering bats.
        ** Pre-Conditions: None.
        ** Post-Conditions: The user's direction may be updated, and the reverseCounter may be modified.
        *********************************************************************/
        int check_direction(string, int, int);

        /*********************************************************************
        ** Function: check_direction_opposite()
        ** Description: Checks the user's direction in the opposite direction and validates it.
        ** Parameters:
            ** direction: The direction in which the user wants to move ('w', 'a', 's', or 'd').
            ** reverseCounter: The number of reverse movements the player must complete due to encountering bats.
        ** Pre-Conditions: None.
        ** Post-Conditions: The user's direction may be updated, and the reverseCounter may be modified.
        *********************************************************************/
        int check_direction_opposite(string, int, int);

        /*********************************************************************
        ** Function: update_position()
        ** Description: Updates the user's position in the specified direction.
        ** Parameters:
            ** direction: The direction in which the user wants to move ('w', 'a', 's', or 'd').
        ** Pre-Conditions: None.
        ** Post-Conditions: The user's position is updated in the specified direction.
        *********************************************************************/
        void update_position(const string);

        /*********************************************************************
        ** Function: update_position_opposite()
        ** Description: Updates the user's position in the opposite direction to the specified direction.
        ** Parameters:
            ** direction: The direction in which the user wants to move ('w', 'a', 's', or 'd').
        ** Pre-Conditions: None.
        ** Post-Conditions: The user's position is updated in the opposite direction.
        *********************************************************************/
        void update_position_opposite(const string);

        /*********************************************************************
        ** Function: check_percepts()
        ** Description: Checks and prints the percepts of the grid elements adjacent to the player's position.
        ** Parameters: None.
        ** Pre-Conditions: None.
        ** Post-Conditions: The percepts of adjacent grid elements are printed.
        *********************************************************************/
        void check_percepts() const;

        /*********************************************************************
        ** Function: is_adjacent()
        ** Description: Checks if the grid coordinates specified by the parameters are adjacent to the player's position.
        ** Parameters:
            ** i: The row index of the grid element to check.
            ** j: The column index of the grid element to check.
        ** Pre-Conditions: None.
        ** Post-Conditions: None.
        *********************************************************************/
        bool is_adjacent(const int, const int) const;

        /*********************************************************************
        ** Function: run_encounters()
        ** Description: Runs encounters with events in the grid based on the player's position.
        ** Parameters: None.
        ** Pre-Conditions: None.
        ** Post-Conditions: The encounter message is printed, and the gold may be collected if encountered.
        *********************************************************************/
        int run_encounters();

        /*********************************************************************
        ** Function: fire_arrow()
        ** Description: Prompts the user for a direction to shoot the arrow and checks if it hits the wumpus.
        ** Parameters:
            ** reverseCounter: The number of reverse movements the player must complete due to encountering bats.
        ** Pre-Conditions: None.
        ** Post-Conditions: The arrow may hit the wumpus or miss, and the reverseCounter may be updated.
        *********************************************************************/
        int fire_arrow(int);


        /*********************************************************************
        ** Function: check_kill_wumpus()
        ** Description: Checks if the arrow shot by the player kills the wumpus.
        ** Parameters:
            ** direction: The direction in which the arrow is shot ('w', 'a', 's', or 'd').
        ** Pre-Conditions: None.
        ** Post-Conditions: The wumpus may be killed or relocated.
        *********************************************************************/
        bool check_kill_wumpus(const string);

        /*********************************************************************
        ** Function: kill_wumpus()
        ** Description: Notifies the user that they have killed the Wumpus and removes the Wumpus from the grid.
        ** Parameters:
            ** wumpusX: The X-coordinate of the Wumpus position.
            ** wumpusY: The Y-coordinate of the Wumpus position.
        ** Pre-Conditions: None.
        ** Post-Conditions: The Wumpus is removed from the grid and the user is notified of the kill.
        *********************************************************************/
        void kill_wumpus(const int, const int);

        /*********************************************************************
        ** Function: relocate_wumpus()
        ** Description: Relocates the Wumpus to a new random position on the grid.
        ** Parameters:
            ** wumpusX: The X-coordinate of the current Wumpus position.
            ** wumpusY: The Y-coordinate of the current Wumpus position.
        ** Pre-Conditions: None.
        ** Post-Conditions: The Wumpus is moved to a new valid position on the grid.
        *********************************************************************/
        void relocate_wumpus(const int, const int);

        /*********************************************************************
        ** Function: run_end_game()
        ** Description: Runs the end game scenario based on the given message.
        ** Parameters:
            ** message: An integer representing the outcome of the game (0 if the player died, any other value if the player survived).
        ** Pre-Conditions: None.
        ** Post-Conditions: The appropriate message is displayed to the player.
        *********************************************************************/
        void run_end_game(const int) const;
};

#endif