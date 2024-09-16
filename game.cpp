#include "game.h"

void Game::run_end_game(const int message) const {
  // print the grid a final time
  print_debug_grid();

  // if player died
  if (message == 0) {
    // death message has already been printed, so print nothing else
    cout << endl;
  }
  // if player survived
  else {
    // congratulate them on their victory
    cout << "\nCongratulations, you have escaped with the gold and won the "
            "game!\n"
         << endl;
  }
}

void Game::relocate_wumpus(const int wumpusX, const int wumpusY) {
  // declare vars
  int x, y;

  // notify user that their arrow has missed the target and that the wumpus may
  // choose to move
  cout << "\nYour arrow missed the target. The Wumpus has awoken and may "
          "choose to move."
       << endl;

  // Generate a random number between 0 and 3
  int randNum = rand() % 4;

  // if number is 1, 2, or 3 (75% chance of rellocating)
  if (randNum > 0) {
    // set old position to null
    grid[wumpusX][wumpusY] = NULL;

    // continue to generate numbers while new grid spot is not null or new
    // position equals old postion
    do {
      // set x and y to the new randomly generated coordinates
      x = rand() % grid.size();
      y = rand() % grid[0].size();

      // evaulate conditions
    } while (grid[x][y] != NULL || (x == wumpusX && y == wumpusY));

    // set new position to wumpus object in grid
    grid[x][y] = event_arr[0];

    // update the x and y member vars of wumpus
    this->grid[x][y]->get_event_pointer()->set_position_x(x);
    this->grid[x][y]->get_event_pointer()->set_position_y(y);
  }
}

void Game::kill_wumpus(const int wumpusX, const int wumpusY) {
  // notify the user that they have killed the wumpus
  cout << "\nYour arrow hit and killed the Wumpus!" << endl;

  // remove wumpus
  this->grid[wumpusX][wumpusY] = NULL;

  // set killed wumpus to true
  this->killedWumpus = true;
}

bool Game::check_kill_wumpus(const string direction) {
  // get position of wumpus
  int wumpusX = this->event_arr[0]->get_event_pointer()->get_position_x();
  int wumpusY = this->event_arr[0]->get_event_pointer()->get_position_y();

  bool kill = false;

  // repeat 3 times
  for (int i = 1; i < 4; i++) {

    // if direction is upwards
    if (direction == "w") {

      // if a new movement in the upwards direction does not go out of bounds
      if (this->playerX - i >= 0) {

        // check if that new movement intersects with the position of the wumpus
        if (this->playerX - i == wumpusX && this->playerY == wumpusY) {

          // update variable to indicate the wumpus should be killed
          kill = true;
        }
      }
    }
    // if direction is to the right
    else if (direction == "d") {

      // if a new movement in the right direction does not go out of bounds
      if (this->playerY + i < grid[0].size()) {

        // check if that new movement intersects with the position of the wumpus
        if (this->playerX == wumpusX && this->playerY + i == wumpusY) {

          // update variable to indicate the wumpus should be killed
          kill = true;
        }
      }
    }
    // if direction is down
    else if (direction == "s") {

      // if a new movement in the downwards direction does not go out of bounds
      if (this->playerX + i < grid.size()) {

        // check if that new movement intersects with the position of the wumpus
        if (this->playerX + i == wumpusX && this->playerY == wumpusY) {

          // update variable to indicate the wumpus should be killed
          kill = true;
        }
      }
    }
    // if direction is to the left
    else {

      // if a new movement in the left direction does not go out of bounds
      if (this->playerY - i >= 0) {

        // check if that new movement intersects with the position of the wumpus
        if (this->playerX == wumpusX && this->playerY - i == wumpusY) {

          // update variable to indicate the wumpus should be killed
          kill = true;
        }
      }
    }
  }

  // if wumpus was hit by arrow and should be killed
  if (kill == true) {

    // call function to kill wumpus
    kill_wumpus(wumpusX, wumpusY);

    // return that the wumpus has been killed
    return true;
  }
  // if wumpus was not hit by arrow and thus should not be killed
  else {
    // call function to relocate wumpus
    relocate_wumpus(wumpusX, wumpusY);

    // return that the wumpus has not been killed
    return false;
  }
}

int Game::fire_arrow(int reverseCounter) {
  // declare var
  string direction;

  // prompt user for a direction in which to shoot the arrow and store input
  cout << "\nEnter a direction to shoot the arrow (w a s d): ";
  cin >> direction;

  // while the user did not enter a valid direction
  while (direction != "w" && direction != "a" && direction != "s" &&
         direction != "d") {

    // reprompt the user for input
    cout << "\nInvalid input - please enter a valid direction (w a s d): ";
    cin >> direction;
  }

  // if the user encountered bats within the last 5 moves
  if (reverseCounter > 0) {
    // reverse the choosen direction of their arrow and pass it into the
    // function to check if it hits the wumpus
    if (direction == "w") {
      this->killedWumpus = check_kill_wumpus("s");
    } else if (direction == "d") {
      this->killedWumpus = check_kill_wumpus("a");
    } else if (direction == "s") {
      this->killedWumpus = check_kill_wumpus("w");
    } else {
      this->killedWumpus = check_kill_wumpus("d");
    }

    // subtract 1 from the number of reverse movements they must complete
    reverseCounter--;
  }
  // if user is not currently affected by bats
  else {
    // call function to check if the arrow will hit the wumpus, pass in the
    // specified direction
    this->killedWumpus = check_kill_wumpus(direction);
  }

  // return the updated (possibly) reverse counter
  return reverseCounter;
}

int Game::run_encounters() {
  // default message to -1 (no encounter, message returned by null grid
  // elements)
  int message = -1;

  // for each row of the grid
  for (int i = 0; i < this->grid.size(); i++) {
    // for each column of the grid
    for (int j = 0; j < this->grid[0].size(); j++) {
      // if the current grid element is not null, and is equal to the user's
      // current position
      if (grid[i][j] != NULL && i == this->playerX && j == this->playerY) {

        // call function to print encounter messsage and store result of
        // encounter
        message = this->grid[i][j]->get_event_pointer()->print_encounter();
      }
    }
  }
  cout << "\n\n";

  // if the user encountered gold and had not previously
  if (message == 1 && this->hasGold == false) {

    // update that they have now encountered old
    this->hasGold = true;

    // get the position of the gold in the grid
    int goldX = this->event_arr[1]->get_event_pointer()->get_position_x();
    int goldY = this->event_arr[1]->get_event_pointer()->get_position_y();

    // update that grid element to null
    grid[goldX][goldY] = NULL;
  }

  // return the encounter message
  return message;
}

bool Game::is_adjacent(const int i, const int j) const {
  // if the coordinates of the grid specified by the parameters is adjacent to
  // the user's current position return true
  if (i + 1 == playerX && j + 1 == playerY) {
    return true;
  } else if (i + 1 == playerX && j == playerY) {
    return true;
  } else if (i + 1 == playerX && j - 1 == playerY) {
    return true;
  } else if (i == playerX && j + 1 == playerY) {
    return true;
  } else if (i == playerX && j - 1 == playerY) {
    return true;
  } else if (i - 1 == playerX && j + 1 == playerY) {
    return true;
  } else if (i - 1 == playerX && j == playerY) {
    return true;
  } else if (i - 1 == playerX && j - 1 == playerY) {
    return true;
  }

  // else return false
  return false;
}

void Game::check_percepts() const {
  // for each row of the grid
  for (int i = 0; i < this->grid.size(); i++) {
    // for each column of the grid
    for (int j = 0; j < this->grid[0].size(); j++) {
      // if the current box is adjacent to the user and not null
      if (is_adjacent(i, j) && grid[i][j] != NULL) {

        // call function to print it's percept
        this->grid[i][j]->get_event_pointer()->print_percept();
      }
    }
  }
  cout << "\n";
}

void Game::update_position_opposite(const string direction) {
  // update user's position in opposition to their specified direction
  if (direction == "w") {
    this->playerX++;
  } else if (direction == "a") {
    this->playerY++;
  } else if (direction == "s") {
    this->playerX--;
  } else if (direction == "d") {
    this->playerY--;
  }
}

void Game::update_position(const string direction) {
  // update user's position in accordance to their specified direction
  if (direction == "w") {
    this->playerX--;
  } else if (direction == "a") {
    this->playerY--;
  } else if (direction == "s") {
    this->playerX++;
  } else if (direction == "d") {
    this->playerY++;
  }
}

int Game::check_direction_opposite(string direction, int reverseCounter,
                                   int arrowsAvaliable) {
  // call function to update user's position in the opposite direction
  update_position_opposite(direction);

  // while the user did not input a valid direction
  while ((direction != "w" && direction != "a" && direction != "s" &&
          direction != "d" && direction != "f") ||
         (playerX < 0 || playerX >= grid.size() || playerY >= grid[0].size() ||
          playerY < 0) ||
         (direction == "f" &&
          (arrowsAvaliable == 0 || this->killedWumpus == true))) {

    // call function to reset position
    update_position(direction);

    // reprompt the user for a new direction
    cout << "\nInvalid input - please enter a valid direction (w a s d): ";
    cin >> direction;

    // if the new direction is not to fire an arrow
    if (direction != "f") {

      // update position with new position
      update_position_opposite(direction);
    }
    // if new direction is to fire an arrow
    else if (arrowsAvaliable > 0 && this->killedWumpus == false) {
      // call function to fire an arrow, reverseCounter may be updated depending
      // on if the user is currently affect by bats
      reverseCounter = fire_arrow(reverseCounter);
    }
  }

  return reverseCounter;
}

int Game::check_direction(string direction, int reverseCounter,
                          int arrowsAvaliable) {
  // call function to update user's position in the specified direction
  update_position(direction);

  // while the user did not input a valid direction
  while ((direction != "w" && direction != "a" && direction != "s" &&
          direction != "d" && direction != "f") ||
         (playerX < 0 || playerX >= grid.size() || playerY >= grid[0].size() ||
          playerY < 0) ||
         (direction == "f" &&
          (arrowsAvaliable == 0 || this->killedWumpus == true))) {

    // call function to reset position
    update_position_opposite(direction);

    // reprompt the user for a new direction
    cout << "\nInvalid input - please enter a valid direction (w a s d), or "
            "press f to fire an arrow: ";
    cin >> direction;

    // if the new direction is not to fire an arrow
    if (direction != "f") {

      // update position with new position
      update_position(direction);
    }
    // if new direction is to fire an arrow and there are arrows avaliable
    else if (arrowsAvaliable > 0 && this->killedWumpus == false) {
      // call function to fire an arrow, reverseCounter may be updated depending
      // on if the user is currently affect by bats
      reverseCounter = fire_arrow(reverseCounter);
    }
  }

  return reverseCounter;
}

void Game::print_object(const int x, const int y, const int k) const {
  // if the current grid box is not null and is on the correct line
  if (this->grid[x][y] != NULL && k == 1) {
    // output the particular grid element in a formatted manner
    cout << " ";
    this->grid[x][y]->get_event_pointer()->print_event();
    cout << " |";
  } else {
    // output the null grid element in a formatted manner
    cout << "   |";
  }
}

void Game::print_debug_grid() const {
  // for each row of the grid
  for (int i = 0; i < this->grid.size(); i++) {
    // print the start of the top of each grid row
    cout << "+";

    // for each column of the grid
    for (int j = 0; j < this->grid[0].size(); j++) {
      // print rest of top of grid rows
      cout << "---+";
    }
    cout << endl;

    // for each sub row
    for (int k = 0; k < 2; k++) {
      cout << "|";

      // for each column of the sub row
      for (int l = 0; l < this->grid[0].size(); l++) {

        // if the current grid box contains the user and is on the correct line
        if (i == playerX && l == playerY && k == 1) {

          // display the user
          cout << " * |";
        } else {

          // call function to print null and child class elements accordingly
          print_object(i, l, k);
        }
      }
      cout << endl;
    }
  }

  // print the start of the bottom of each grid row
  cout << "+";
  for (int m = 0; m < this->grid[0].size(); m++) {

    // print the rest of the bottom of each grid row
    cout << "---+";
  }
  cout << endl;
}

void Game::print_grid() const {
  // for each row of the grid
  for (int i = 0; i < this->grid.size(); i++) {
    // print the start of the top of each grid row
    cout << "+";

    // for each column of the grid
    for (int j = 0; j < this->grid[0].size(); j++) {
      // print rest of top of grid rows
      cout << "---+";
    }
    cout << endl;

    // for each sub row
    for (int k = 0; k < 2; k++) {
      cout << "|";

      // for each column of the sub row
      for (int l = 0; l < this->grid[0].size(); l++) {

        // if the current grid box contains the user and is on the correct line
        if (i == playerX && l == playerY && k == 1) {

          // display the user
          cout << " * |";
        } else {
          // print black grid boxes accordingly
          cout << "   |";
        }
      }
      cout << endl;
    }
  }

  // print the start of the bottom of each grid row
  cout << "+";
  for (int m = 0; m < this->grid[0].size(); m++) {

    // print the rest of the bottom of each grid row
    cout << "---+";
  }
  cout << endl;
}

void Game::run_game(const char debug) {
  // declare vars
  string direction;
  int message = -1, reverseCounter = 0, arrowsAvaliable = 3;

  // while the game has not ended (death or victory)
  do {
    // if the game is in debug mode
    if (debug == 't') {

      // print the debug grid
      print_debug_grid();
    }
    // if the game is in normal mode
    else {

      // print the normal grid
      print_grid();
    }

    // call function to check possible percepts
    check_percepts();

    // get directional input from user
    cout << "\nEnter the direction you would like to move in (w a s d), or "
            "press f to fire an arrow: ";
    cin >> direction;

    // if the returned message indicates the user has stumbled across bats
    if (message == 2) {

      // reset their reverse movement counter to 5
      reverseCounter = 5;
    }

    // if the user is moving in a direction
    if (direction != "f") {

      // if the user is currently affected by bats
      if (reverseCounter > 0) {

        // call function to update and error check their movement accordingly
        reverseCounter = check_direction_opposite(direction, reverseCounter,
                                                  arrowsAvaliable);

        // update the number of reverse movements left
        reverseCounter--;
      }
      // if the user is not currently affected by bats
      else {
        // call function to update and error check their movement accordingly
        reverseCounter =
            check_direction(direction, reverseCounter, arrowsAvaliable);
      }
    }
    // if the user has fired an arrow, the wumpus has not been killed, and the
    // user has a sufficient number of arrows
    else if (direction == "f" && this->killedWumpus == false &&
             arrowsAvaliable > 0) {

      // call function to fire arrows
      reverseCounter = fire_arrow(reverseCounter);

      // update number of arrows remaining
      arrowsAvaliable--;

      // if there are arrows left
      if (arrowsAvaliable > 0) {

        // update the user on how many arrows they have left
        cout << "\nYou have " << arrowsAvaliable << " arrows left." << endl;
      }
    }
    // if the user has fired an arrow but wumpus is dead
    else if (direction == "f" && this->killedWumpus == true) {

      // update the user on their situation
      cout << "\nThe wumpus is dead, there is no need to fire your arrows."
           << endl;
    }

    // if the user has fired an arrow but there are not arrows left
    if (direction == "f" && arrowsAvaliable == 0 &&
        this->killedWumpus == false) {

      // update the user on their situation
      cout << "\nYou have no more arrows left to fire." << endl;
    }

    // organize
    cout << "\n----------------------------------------------------------------"
            "----------------------------------";

    // if the user is currently affected by bats
    if (reverseCounter > 0) {

      // update them on the number of disoriented movements they have remaining
      cout << "\n\nYou will be disoriented for " << reverseCounter
           << " more moves.";
    }

    // call function to run encounters based upon the user's movement, store the
    // result in message
    message = run_encounters();

  } while ((this->hasGold == false || this->killedWumpus == false ||
            (this->playerX != orgX || this->playerY != orgY)) &&
           message != 0);

  // call function to run the victory/loss messages
  run_end_game(message);
}

void Game::populate_grid() {
  // declare vars
  int x, y;

  // for each element in the event_arr (gold, wumpus, bats, bats, pit, pit)
  for (int i = 0; i < 6; i++) {

    // continue to randomize their x and y coordinates until a null position is
    // found
    do {
      x = rand() % grid.size();
      y = rand() % grid[0].size();
    } while (grid[x][y] != NULL);

    // set the current position to the current child class
    grid[x][y] = event_arr[i];

    // update the position of that child class
    this->grid[x][y]->get_event_pointer()->set_position_x(x);
    this->grid[x][y]->get_event_pointer()->set_position_y(y);
  }

  // continue to randomize the user's x and y coordinates until a null position
  // is found
  do {
    x = rand() % grid.size();
    y = rand() % grid[0].size();
  } while (grid[x][y] != NULL);

  // update the user's position accordingly
  this->playerX = x;
  this->playerY = y;
  this->orgX = x;
  this->orgY = y;
}

void Game::populate_event_arr() {
  // create and assign Room objects to the event_arr
  for (int i = 0; i < 6; i++) {

    // create a new Room object
    Room *room = new Room;

    // add the Room object to the event_arr
    this->event_arr.push_back(room);
  }

  for (int i = 0; i < 6; i++) {
    // get the room pointer from event_arr
    Room *room = this->event_arr[i];

    // get the event pointer from the room
    Event *e = room->get_event_pointer();

    delete e; // delete the existing event

    // create new child classes depending on the iteration of the array
    if (i == 0) {
      e = new Wumpus;
    } else if (i == 1) {
      e = new Gold;
    } else if (i % 2 == 0) {
      e = new Pits;
    } else {
      e = new Bats;
    }

    // add the current event to the event_arr
    room->set_event_pointer(e);
  }
}

void Game::initialize_null_grid(int row, const int col) {
  // for each row
  for (int i = 0; i < row; i++) {

    // create a set of columns of the specified length and intialize them to
    // null
    vector<Room *> temp(col, NULL);

    // add that column of null values to our grid
    this->grid.push_back(temp);
  }
}

char Game::initialize_user_input() {
  // declare vars
  int row, col;
  char debug;

  // get the number rows from the user
  cout << "Enter the number of rows for the grid: ";
  cin >> row;

  // while the number of rows entered is less than 4
  while (row < 4 || cin.fail()) {
    // clear the error flags
    cin.clear();
    cin.ignore(1000, '\n');

    // reprompt the user
    cout << "\nInvalid input - please enter an integer greater than 3: ";
    cin >> row;
  }

  // get the number columns from the user
  cout << "\nEnter the number of columns for the grid: ";
  cin >> col;

  // while the number of columns entered is less than 4
  while (col < 4 || cin.fail()) {
    // clear the error flags
    cin.clear();
    cin.ignore(1000, '\n');

    // reprompt the user
    cout << "\nInvalid input - please enter an integer greater than 3: ";
    cin >> col;
  }

  // get the mode to run the game in
  cout << "\nEnter 't' to run debug mode, enter 'n' to run as usual: ";
  cin >> debug;

  // while the mode entered by the user doesn't exist
  while (debug != 'n' && debug != 't') {

    // reprompt the user
    cout << "\nInvalid input - please enter either 't' or 'n': ";
    cin >> debug;
  }

  // call function to initialize all grid elements to null
  initialize_null_grid(row, col);

  return debug;
}

void Game::set_up_game() {
  // call function to get user input for rows, columns, and mode, store the mode
  // of the game
  char debug = initialize_user_input();

  cout << "\n";

  // call function to populate the event_arr with the necessary child classes
  populate_event_arr();

  // call function to populate grid with those child classes
  populate_grid();

  // call function to run the game
  run_game(debug);
}

Game::Game() {
  // seed random number generator
  srand(time(NULL));

  // call function to manage the game
  set_up_game();
}

Game::~Game() {
  // Deallocate memory for event_arr and also grid
  for (int i = 0; i < event_arr.size(); i++) {
    delete event_arr[i];
    event_arr[i] = nullptr;
  }
}