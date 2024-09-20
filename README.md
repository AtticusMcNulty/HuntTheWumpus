# HuntTheWumpus
## Description
Hunt the Wumpus is a game where players aim to kill the Wumpus, collect gold, and escape. You can move in four directions and fire up to three arrows. Arrows can travel a maximum of three squares, eliminating the Wumpus if it's within range. The gold is randomly placed. Beware of two pits and two bats - falling into pits results in a loss, and bats reverse your movement for five turns. Walking into the Wumpus room leads to instant death. The Wumpus has a 75% chance of moving if you miss a shot. Percepts at the start of each new round inform you about adjacent hazards. There are two modes you can run, debug and normal. Debug allows you to see all of the items and hazards while normal only shows your current location. To escape you must return to your original coordinates.

## How to Play
You can download this github project onto your own device and run the program in a terminal with two commands (note the first command may take a second to compile everything):
```
g++ main.cpp game.cpp game.h room.cpp room.h event.cpp event.h bats.cpp bats.h wumpus.cpp wumpus.h pits.cpp pits.h gold.cpp gold.h
./a.out
```

## Walkthrough
Program begins by prompting user to enter the dimensions for the game. Error handling dictates the number of columns and rows must both exceed three.</br>
<img width="1211" alt="Screenshot 2024-09-19 at 7 49 30 PM" src="https://github.com/user-attachments/assets/6fe475dd-a4dc-4a72-bd49-3d2cb96dfff4">
After the user selects whether or not they want to run the game in "debug" mode. In debug mode, all entities are made visible by a char inside a tile (e.g. b for bats), as opposed to each cell simply being empty. When they make their choice, the program will print the starting board. Entities are spawned randomly, including the user whose location is highlighted with a star (*).</br>
Normal mode:</br>
<img width="151" alt="Screenshot 2024-09-19 at 8 15 39 PM" src="https://github.com/user-attachments/assets/2e1225c2-d1be-4e63-af88-1095f8682b2e"></br>
Debug mode:</br>
<img width="151" alt="Screenshot 2024-09-19 at 7 54 26 PM" src="https://github.com/user-attachments/assets/8b1da4e1-1f16-4ff2-9164-07fe3412af7d"></br>
Below the board, messages are printed out indicating any entities in an adjacent square. In the screenshot below, we see the player is next to two bats and the gold, thus two bat percepts and one gold percept are printed.</br>
<img width="218" alt="Screenshot 2024-09-19 at 7 58 49 PM" src="https://github.com/user-attachments/assets/6af35350-43ec-4b4b-88a8-bc7f4bffcd3a"></br>
To move the player, the standard W A S D keys are used. W to go up, A to go right, S to go down, and D to go left. If the user enters a key that moves in an out of bounds direction, they will be reprompted for input.</br>
<img width="717" alt="Screenshot 2024-09-19 at 8 01 43 PM" src="https://github.com/user-attachments/assets/0d9f0ca0-09f0-4cb7-b828-8574b05586d8"></br>
Users also possess the option of firing an arrow. Arrows are used to kill the Wumpus and can travel 3 blocks in any direction. After firing an arrow, a message will let you know the number of arrows you have left. An additional message will let you know if you killed the Wumpus. The Wumpus has a 75% chance of moving if you miss a shot.</br>
<img width="749" alt="Screenshot 2024-09-19 at 8 02 57 PM" src="https://github.com/user-attachments/assets/626fb599-fae5-4988-9772-9d67628a4a6e"></br>
There are two ways a player can die: they fall into a pit or run into the Wumpus. In either case, a death message will appear and the game will end.
<img width="333" alt="Screenshot 2024-09-19 at 8 09 10 PM" src="https://github.com/user-attachments/assets/8f188774-75b6-4dda-9eff-8675ea1b2808"></br>
If you run into bats, you will be notified and your movement inputs will be reversed for 5 moves.
<img width="675" alt="Screenshot 2024-09-19 at 8 13 07 PM" src="https://github.com/user-attachments/assets/3a1a565c-6909-4735-9588-d60e16e9fb06"></br>
As described above, the goal of the game is to kill the Wumpus, get the gold, and return to your starting coordinates. Upon completion the game will end and you will be congratulated for your victory.
<img width="533" alt="Screenshot 2024-09-19 at 8 14 57 PM" src="https://github.com/user-attachments/assets/f6079cd5-a917-4d96-aa4d-d2172f72d43d"></br>

