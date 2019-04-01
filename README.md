# Connect Four Portfolio Project
### Written by Eden Albert

Portfolio Project for CS201 at The University of Alabama Spring 2019.
For my portfolio project I decided to try and code the Connect Four game in C!
This project can be accessed by going [here](https://github.com/edenalbert/portfolio).
A video demonstration can be seen [here](https://www.youtube.com/watch?v=MsxY_0T64Z0&feature=youtu.be).

### Getting Started
The code for this project is included in one .c file, so it is fairly easy to run. Simple run the makefile via the
```
make
```
 command in the terminal. Then enter
```
 ./connectFourMain
```
  and the project will run.


### Explaining the Body of the Code

The code starts off pretty simplistically. First the user is asked what size they want the board to be. The user is given a menu and asked what they would like to do. These options are either: player vs. player, player vs. computer, look at how to play connect four, or exit. From there a while loop is entered that consists of the core of the game. Memory for the board is dynamically allocated in this while loop too via the malloc operation. For my code I decided to use a 2D array to represent the board because I personally find those easier to understand for a project of this concept. Depending on what mode the user is playing on, the code will next enter a while loop designated to that mode. These while loops will run until either a tie has happened or a player has won.
The Player vs. player while loop calls on the function dropAPiece. In dropAPiece, players are asked to enter the number corresponding to the column they would like to drop their piece down. Once that piece has found the bottom of that column, the function checkWinner is called. CheckWinner makes note of what piece was just dropped in to the board, then calls the function inRow. This function checks to see if four pieces are in a row horizontally, vertically, or diagonally via recursive calls to itself. If it doesn’t find a matching piece or if the piece is on the edge, this function returns a zero. If it finds a matching piece it returns 1+inRow, so it calls itself again. Once inRow has ran, the values are returned back to checkWinner. If the return value is greater than 4, there is a winner and value of 1 is passed back to dropAPiece where it is finally sent to main to signal a winner. Players are then asked if they want to play again, the score board is updated, and memory of the array is freed.
For Player vs. Computer, a little more strategic thinking of Connect Four was needed. After doing some googling, I found this [power point]() posted by The Massachusetts Institute of Technology that describes the strategy a connect four artificial intelligence bot should use. They ranked these as the top positions to take:

1. If there is a winning move, take it.
2. If your opponent has a winning move, take the move so he (or she) can’t take it.
3. Take the center square over edges and corners.

So the code firsts checks for all these positions, but if they are not available, a random column is picked for where the piece is to be inserted. After finding the appropriate column to drop its piece, the computer then passes this index to checkWinner and this function does its job as stated earlier. Once either the user or the computer wins, the user is asked if they want to play again, the score board is updated, and memory of the array is freed as before.
