
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//external variables
int rows;
int columns;
int gameStautus;  // 0 = no winner, 1 = player won

void howToPlay(){
  printf("\n****************DIRECTIONS****************\n");
  printf("Connect four is a fairly simple game.\n");
  printf("In this version you will first decide whether you want to play against another player or against the computer.\n");
  printf("The computer will then randomly select a player to go first.\n");
  printf("When it is your turn you will type in a number corresponding to the column where you want to drop your piece in.\n");
  printf("The first player to get four pieces in a row either horizontally vertically or diagonally wins!\n");
  printf("*******************************************\n\n");
  return;
}

int printMenue(){
  int menueChoice;
  printf("\n=========================================\n");
  printf("Please type in a number for an option below:\n");
  printf(" 1 - Two player game\n");
  printf(" 2 - Play against computer\n");
  printf(" 3 - How to Play\n");
  printf(" 4 - Exit");
  printf("\n=========================================\n");

  while (1) {
    long int temp=-1;
    char tempArray[2000];
    char *tempPtr;
    fgets(tempArray, 2000, stdin);
    temp = strtol (tempArray, &tempPtr, 10);
    menueChoice = (long)temp;

    if( menueChoice == 1){

      printf("=========================================");
      printf("\nYou have choosen two player mode.\n");
      printf("Player 1 will be 'x'\nPlayer 2 will be 'o'\n");
      printf("=========================================\n\n");
      return menueChoice;
    }
    if( menueChoice == 2){

      printf("=========================================");
      printf("\nYou have choosen to play agsinst the computer.\n");
      printf("You will be 'x'\nThe computer will be 'o'\n");
      printf("=========================================\n\n");
      return menueChoice;
    }
    if( menueChoice == 3){
      howToPlay();
      return menueChoice;
    }
    if( menueChoice == 4){
      return menueChoice;
    }
    else{
      printf("Error: Invalid Input. Please Try again\n");
    }
  }
}

void printBoard(char **board, int rows, int columns){

  for(int i=0; i<rows; i++){
    printf("|"); //prints right edge
    for(int j=0; j< columns ; j++ ){
       printf(" %c |",board[i][j]);
     }
     printf("\n");
  }
  //prints column numbers after the bottom row. Two for loops because spacing gets
  //a little weird in 10's place. Didn't worry about 100's because by then
  //the display will be messed up anyway so who cares :)
  if( columns < 10){
  for(int j=1; j< (columns+1) ; j++ ){
     printf("  %d ",j);
   }
  }
  else{
    for(int k=1; k< 11 ; k++ ){
       printf("  %d ",k);
     }
     for(int l=11; l< (columns+1) ; l++ ){
        printf(" %d ",l);
      }
  }
  printf("\n");
  return;
}

int inRow(char **board, int rowIndex, int colIndex, int direction, char piece){

  //checking to the left of piece inserted
  if(direction == 1){
    if(colIndex == 0){  //reached left side of the board
      if( board[rowIndex][colIndex]== piece){
        return 1; //don't need to run recursion because we are on the edge so there's no where to go !!
      }
      else{
        return 0;
      }
    }
    //not at an edge
    else{
      if(board[rowIndex][colIndex]== piece){
        colIndex = colIndex-1; //sets the value we are going to look at in next recursion
        return 1 + inRow(board, rowIndex, colIndex , 1, piece);
      }
      else{
        return 0;
      }
    }
  }

  //checking to the right of piece inserted
  if(direction == 2){
    if(colIndex == (columns-1) ){  //reached right side of the board
      if( board[rowIndex][colIndex]== piece){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      if(board[rowIndex][colIndex]== piece){
        colIndex = colIndex+1;
        return 1 + inRow(board, rowIndex, colIndex, 2, piece);
      }
      else{
        return 0;
      }
    }
  }
  //checking down from a piece, Vertical Check
  if(direction == 3){
    if(rowIndex == (rows-1) ){  //reached bottom of the board
      if( board[rowIndex][colIndex]== piece){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      if(board[rowIndex][colIndex] == piece){
        rowIndex = rowIndex+1;
        return 1 + inRow(board, rowIndex, colIndex, 3, piece);
      }
      else{
        return 0;
      }
    }
  }
  //checking from BOTTOM LEFT from index
  if(direction == 4){
    if( (rowIndex == (rows-1)) || (colIndex == 0) ){ //reached either the bottom or left edge of the board
      if( board[rowIndex][colIndex]== piece){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      if(board[rowIndex][colIndex]== piece){
        rowIndex = rowIndex+1;
        colIndex = colIndex-1;
        return 1 + inRow(board, rowIndex, colIndex, 4, piece);
      }
      else{
        return 0;
      }
    }
  }
  //checking TOP RIGHT from index
  if(direction == 5){
    if( (rowIndex == 0) || (colIndex == (columns-1)) ){ //reached either the top or right edge of the board
      if( board[rowIndex][colIndex]== piece){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      if(board[rowIndex][colIndex]== piece){
        rowIndex = rowIndex-1;
        colIndex = colIndex+1;
        return 1 + inRow(board, rowIndex, colIndex, 5, piece);
      }
      else{
        return 0;
      }
    }
  }
  //checking TOP LEFT from index
  if(direction == 6){
    if( (rowIndex == 0) || (colIndex == 0) ){ //reached either the top or left edge of the board
      if( board[rowIndex][colIndex]== piece){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      if(board[rowIndex][colIndex]== piece){
        rowIndex = rowIndex-1;
        colIndex = colIndex-1;
        return 1 + inRow(board, rowIndex, colIndex, 6, piece);
      }
      else{
        return 0;
      }
    }
  }
  //checking BOTTOM RIGHT from index
  if(direction == 7){
    if( (rowIndex == (rows-1)) || (colIndex == (columns-1)) ){ //reached either the right edge of board or bottom of board
      if( board[rowIndex][colIndex]== piece){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      if(board[rowIndex][colIndex]== piece){
        rowIndex = rowIndex+1;
        colIndex = colIndex+1;
        return 1 + inRow(board, rowIndex, colIndex, 7, piece);
      }
      else{
        return 0;
      }
    }
  }
return 0;
}

int checkWinner(char **board, int rowIndex, int colIndex){

  char playerPiece = board[rowIndex][colIndex];

  int horizontalInRow = (inRow(board, rowIndex, colIndex, 1, playerPiece) + inRow(board, rowIndex, colIndex, 2, playerPiece)) -1 ;
  int verticalInRow = inRow(board, rowIndex, colIndex,  3, playerPiece);
  int bottomLeftToTopRight =  (inRow(board, rowIndex, colIndex , 4, playerPiece) + inRow(board, rowIndex, colIndex, 5, playerPiece)) -1;
  int topLeftToBottomRight =  (inRow(board, rowIndex, colIndex , 6, playerPiece) + inRow(board, rowIndex, colIndex, 7, playerPiece)) -1;

  if( horizontalInRow ==4 || verticalInRow == 4 || bottomLeftToTopRight == 4 || topLeftToBottomRight == 4){
    return 1; //someone won!
  }
  else{
  return 0; //keep playing
  }

}

int dropAPiece(char **board, int numberOfTurns, int playMode){
  int columnDrop;

  while(1){
    if( numberOfTurns % 2 == 0 || (( (numberOfTurns % 2 != 0) && playMode ==1)) ){
      if( numberOfTurns % 2 == 0) {
        printf("Player 1, which column would you like to drop your piece in?\n");
      }
      if ( numberOfTurns % 2 != 0 ){
        printf("Player 2, which column would you like to drop your piece in?\n");
      }
      long int temp=-1;
      char tempArray[2000];
      char *tempPtr;
      fgets(tempArray, 2000, stdin);
      temp = strtol (tempArray, &tempPtr, 10);
      columnDrop = (long)temp;
      if(columnDrop > (columns) || columnDrop <= 0 || (board[0][(columnDrop-1)] != '-') ){
        printf("You have entered an invalid input please try again\n");
        continue;
      }
      printf("\n");
      if( columnDrop <= columns){
        columnDrop = columnDrop -1; //zero index
          for( int i= (rows - 1) ; i >= 0; i-- ){
            if( board[i][columnDrop] == '-'){
              if( numberOfTurns % 2 == 0) {
                board[i][columnDrop] = 'x';
              }
              if( numberOfTurns % 2 != 0 ){
                board[i][columnDrop] = 'o';
              }
                printBoard( board, rows, columns );
                gameStautus = checkWinner( board, i, columnDrop);
                printf("\n");
                return gameStautus;
              }
            }
        }
    }

    //calculate where the computer wants to drop piece
    if ( (numberOfTurns % 2 != 0) && playMode ==2){
      int possibleWin;
      printf("Computer's turn.\n");

      /*check to see where computer could win which is the most important
      move the computer could make, hence why it is the first thing looked for*/
      for(int c = 0; c <= columns; c++){
        for(int r= (rows - 1) ; r > 0; r-- ){
          if( board[r][c] == '-'){
            if( r == rows-1 ){
              board[r][c] = 'o';
              possibleWin = checkWinner(board, r, c);
              if(possibleWin == 1){
                printBoard( board, rows, columns );
                printf("\n");
                return 0;
              }
              else{
                board[r][c] = '-';
              }
            }
             if( (r!= rows-1) && (board[r+1][c]!= '-')){
              board[r][c] = 'o';
              possibleWin = checkWinner(board, r, c);
              if(possibleWin == 1){ //computer wins somehwere
                printBoard( board, rows, columns );
                printf("\n");
                return possibleWin;
              }
              else{//computer doesnt win
                board[r][c] = '-';
              }
            }
          }
          /*check to see where player 1 could win
          second most important move the computer could make
          because if the computer doesn't take that spot, player 1
          will win and the game is over.*/
          if( board[r][c] == '-'){
              if( r == rows-1 ){
                board[r][c] = 'x';
                possibleWin = checkWinner(board, r, c);
                if(possibleWin == 1){
                  board[r][c] = 'o'; //replace the x that triggered a win with computer's piece
                  printBoard( board, rows, columns );
                  printf("\n");
                  return 0;
                }
                else{
                  board[r][c] = '-';
                }
              }

               if( (r!= rows-1) && (board[r+1][c]!= '-')){
                board[r][c] = 'x';
                possibleWin = checkWinner(board, r, c);
                if(possibleWin == 1){
                  board[r][c] = 'o'; //replace the x that triggered a win with computer's piece
                  printBoard( board, rows, columns );
                  printf("\n");
                  return 0;
                }
                else{
                  board[r][c] = '-';
                }
             }
            }
          }
      }
      /*next best move is taking squares in the middle
      if player 1 or computer can't win*/
      int middleCol = floor(columns/2);
      if(board[0][(middleCol-1)] == '-'){
        for( int r= (rows - 1) ; r >= 0; r-- ){
            if( board[r][middleCol] == '-' && board[r][middleCol] != 'x'){
              board[r][middleCol] = 'o';
              printBoard( board, rows, columns );
              printf("\n");
              return 0;
            }
          }
      }
      /*if middlecol is full and theres no where to put a piece
      to win, pick a random column.*/
      while(1){
        int col = (rand()%columns);
        if(board[0][(middleCol-1)] == '-'){
          for(int b= (rows - 1) ; b >= 0; b-- ){
            if(board[b][col]=='-' && board[b][col]!= 'x'){
              board[b][col] = 'o';
              printBoard( board, rows, columns );
              printf("\n");
              return 0;
            }
          }
        }
      }
    }


  }
}

int main() {
    int userInput;
    int player1Wins=0;
    int player2Wins=0;

    //intro screen and getting board size
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n=========================================\n");
    printf("******* Welcome to Connect Four!! *******\n\n");
    printf("Please enter the dimensions you want your board to be.\n");
    printf("**********************************************************************************\n");
    printf("*Warining: any dimensions larger than 40 x 40 will have unwidely screen handlings*\n");
    printf("*and any dimensions smaller than 4 x 4 will be too small to play Connect Four.   *\n");
    printf("**********************************************************************************\n");
    while(1){
      long int temp=-1;
      char tempArray[2000];
      char *tempPtr;
      printf("Number of Rows:");
      fgets(tempArray, 2000, stdin);
      temp = strtol (tempArray, &tempPtr, 10);
      rows = (long)temp;
      //scanf("%d%s",&rows);
      printf("Number of Columns: ");
      fgets(tempArray, 2000, stdin);
      temp = strtol (tempArray, &tempPtr, 10);
      columns = (long)temp;

      //scanf("%d%c",&columns);
      if(rows < 4 || columns < 4){
        printf("The board size you have entered invalid input, please try again.\n");
      }
      else{
        break;
      }
    }
    printf("\nBoard size is now %d rows by %d columns.\n", rows, columns);

    userInput = printMenue();

    while( userInput != 4){
      int numberOfTurns = 0;
      int whoIsWinner=0;

      if( userInput == 3 ){
        userInput = printMenue();
      }
      if(userInput == 4 ){
        break;
      }

      char **board = malloc ( sizeof(char *) * rows);
      for(int a=0; a<rows; a++){
        board[a] = malloc(sizeof(char)* columns);
      }
      //sets board to empty
      //char board[rows][columns];
      for(int i=0; i<rows; i++){
        for(int j=0; j< columns ; j++ ){
          board[i][j] = '-';
        }
      }
      printBoard(board, rows, columns );

      /*The actual calls to functions that make the game work happen in
      this while looop. This whille loop contains two while loops. One
      for player vs. player, and one for player vs.computer. For each piece
      that is dropped, a value of 0 or 1 is returned from the drop piece
      function. This value is then elvalutaed to determine the state of the
      game.If theres a winner, the numberOfTurns variable is manipulated so
      the inner while loop is exited. Then players are asked if they would
      like to play again and score is kepy count of.*/
      while( userInput == 1 || userInput== 2 ){
          //player vs. player
          while( numberOfTurns != (rows * columns) && userInput == 1){
            gameStautus = dropAPiece (board, numberOfTurns, userInput);
            if( gameStautus == 1 ){
              if( numberOfTurns % 2 == 0 ){
                printf("*********Congratulations Player 1! You won!*********\n\n");
                whoIsWinner = 1;
              }
              else{
                printf("*********Congratulations Player 2! You won!*********\n\n");
                whoIsWinner = 2;
              }
              numberOfTurns = (rows * columns) -1 ;
            }
            numberOfTurns = numberOfTurns + 1;
          }

          //computer vs. player
          while( numberOfTurns != (rows * columns) && userInput == 2){
            gameStautus = dropAPiece (board, numberOfTurns, userInput);
            if( gameStautus == 1 ){
                  if( numberOfTurns % 2 == 0 ){
                      printf("*********Congratulations Player 1! You won!*********\n\n");
                      whoIsWinner = 1;
                    }
                  else{
                    printf("*********Sorry, You Lose!*********\n\n");
                    whoIsWinner = 2;
                  }
                  numberOfTurns = (rows * columns)-1;
            }

            numberOfTurns = numberOfTurns + 1;
          }

          if(numberOfTurns == (rows*columns) && gameStautus==0){
            printf("*********There was a tie!*********\n\n");
          }

          break;
      }

      /*The next lines of code deal with deciding to play another game or not
      and keep tracking of the score of the total matches*/

      int playAgain;
      while(1){
        printf("Would you like to play again?\n");
        printf("Please enter 1 for Yes or 2 for No.\n");
        long int temp=-1;
        char tempArray[2000];
        char *tempPtr;
        fgets(tempArray, 2000, stdin);
        temp = strtol (tempArray, &tempPtr, 10);
        playAgain = (long)temp;
        if( playAgain != 1 && playAgain != 2){
          printf("*****ERROR: You have entered an invalid input please try again.*****\n\n");
        }
        else{
          if(whoIsWinner == 1){
            player1Wins++;
          }
          if(whoIsWinner == 2){
            player2Wins++;
          }
          printf("      Total Game Scoreboard\n");
          printf("      ---------------------\n");
          printf("    Player 1 has won %d games.\n", player1Wins);
          if (userInput == 1) {
            printf("    Player 2 has won %d games.\n", player2Wins);
            break;
          }
          if (userInput == 2) {
            printf("    The computer has won %d games.\n", player2Wins);
            break;
          }
        }
      }
    if( playAgain == 2){
      for (int i = 0; i < rows; i++) {
        free(board[i]);
      }
      break;
    }
    printf("\nNew Game\n");
    printf("-----------\n");
    for (int i = 0; i < rows; i++) {
      free(board[i]);
    }
  }

    printf("\n");
    printf("Thank You for Playing!\n");
    printf("Goodbye!\n");
    return 0;
}
