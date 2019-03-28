//#include "connectFour.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//external variables
int rows;
int columns;

int numberOfTurns;
int gameStautus;  // 0 = no winner, 1 = player 1 won, 2 = player2/computer won

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
  printf(" 4 - Exit\n");
  printf("\n=========================================\n\n");

  while (1) {
    scanf("%d", &menueChoice);
    //lolololol this doesnt work if it is a letter!***************************************************************
    //need to fix that
      if( (menueChoice != 1) && (menueChoice != 2) && (menueChoice != 3) && (menueChoice != 4) ){
        printf("The number you have selected is invalid. Please try again.\n");
      }
      else{
        break;
      }
    }

    if( menueChoice == 1){
      printf("You have choosen two player mode.\n");
      printf("Player 1 will be 'x'\nPlayer 2 will be 'o'\n");
      return menueChoice;
    }
    if( menueChoice == 2){
      printf("You have choosen to play agsinst the computer.\n");
      printf("You will be 'x'\nThe computer will be 'o'\n");
      return menueChoice;
    }
    if( menueChoice == 3){
      howToPlay();
      printMenue();
    }
    if( menueChoice == 4){
      return menueChoice;
    }
    return menueChoice;
}

void printBoard(char board[rows][columns]){
  int k;

  for(int i=0; i<rows; i++){
    printf("|"); //prints right edge
    for(int j=0; j< columns ; j++ ){
       printf(" %c |",board[i][j]);
     }
     printf("\n");
  }
  //prints column numbers on the bottom
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

int inRow(char board[rows][columns], int rowIndex, int colIndex, int direction){
  printf("2\n");
  char playerPiece = board[rowIndex][colIndex];
  //checking to the left of piece inserted
  if(direction == 8){  //had to make this direction 8 because i dont think the parameters liked a stand alone 1
    if(colIndex == 0){  //reached left side of the board
      printf("3\n");
      if( board[rowIndex][colIndex]== playerPiece){
        return 1; //don't need to run recursion because we are on the edge and there's no where to go !!
      }
      else{
        return 0;
      }
    }
    //no edge, just else statment because if edge, we'd go into first if statment
    else{
      if(board[rowIndex][colIndex-1]== playerPiece){
        colIndex = colIndex-1;
        return 1 + inRow(board, rowIndex, colIndex, 8);
      }
      else{
        return 0;
      }
    }
  }

  //checking to the right of piece inserted
  if(direction == 2){
      printf("4\n");
    if(colIndex == (columns-1) ){  //reached right  side of the board
      if( board[rowIndex][colIndex]== playerPiece){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      if(board[rowIndex][colIndex+1]== playerPiece){
      //  colIndex = colIndex+1;
        return 1 + inRow(board, rowIndex, colIndex+1, 2);
      }
      else{
        return 0;
      }
    }
  }
  //checking down from a piece, Vertical Check
  if(direction == 3){
      printf("5\n");
    if(rowIndex == (rows-1) ){  //reached bottom of the board
      if( board[rowIndex][colIndex]== playerPiece){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      printf("a\n");
      printf("%d", rowIndex);
      printf("    %d\n",colIndex);
      if(board[rowIndex+1][colIndex] == playerPiece){
        printf("b\n");
        rowIndex = rowIndex+1;
        return 1 + inRow(board, rowIndex, colIndex, 3);
      }
      else{
        printf("c\n");
        return 0;
      }
    }
  }
  //checking from BOTTOM LEFT from index
  if(direction == 4){
      printf("6\n");
    if( (rowIndex == (rows-1)) || (colIndex == 0) ){ //reached either the bottom or left edge of the board
      if( board[rowIndex][colIndex]== playerPiece){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      if(board[rowIndex+1][colIndex-1]== playerPiece){
        rowIndex = rowIndex+1;
        colIndex = colIndex-1;
        return 1 + inRow(board, rowIndex, colIndex, 4);
      }
      else{
        return 0;
      }
    }
  }
  //checking TOP RIGHT from index
  if(direction == 5){
      printf("7\n");
    if( (rowIndex == 0) || (colIndex == (columns-1)) ){ //reached either the top or right edge of the board
      if( board[rowIndex][colIndex]== playerPiece){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      if(board[rowIndex-1][colIndex+1]== playerPiece){
        rowIndex = rowIndex-1;
        colIndex = colIndex+1;
        return 1 + inRow(board, rowIndex, colIndex, 5);
      }
      else{
        return 0;
      }
    }
  }
  //checking TOP LEFT from index
  if(direction == 6){
      printf("8\n");
    if( (rowIndex == 0) || (colIndex == 0) ){ //reached either the top or left edge of the board
      if( board[rowIndex][colIndex]== playerPiece){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      if(board[rowIndex-1][colIndex-1]== playerPiece){
        rowIndex = rowIndex-1;
        colIndex = colIndex-1;
        return 1 + inRow(board, rowIndex, colIndex, 6);
      }
      else{
        return 0;
      }
    }
  }
  //checking BOTTOM RIGHT from index
  if(direction == 7){
      printf("9\n");
    if( (rowIndex == (rows-1)) || (colIndex == (columns-1)) ){ //reached either the bottom or right edge of the board
      if( board[rowIndex][colIndex]== playerPiece){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      if(board[rowIndex-1][colIndex+1]== playerPiece){
        rowIndex = rowIndex-1;
        colIndex = colIndex+1;
        return 1 + inRow(board, rowIndex, colIndex, 7);
      }
      else{
        return 0;
      }
    }
  }
  printf("oh no\n");
return 0;
}

int checkWinner(char board[rows][columns], int numberOfTurns, int rowIndex, int colIndex){

  //no way there could be a connect four when the sum of the players moves dont equal more than 7
  //so just return
  if(numberOfTurns < 6){
    printf("1\n");
    return 0;
  }

  int horizontalInRow = inRow(board, rowIndex, colIndex, 8) + inRow(board, rowIndex, colIndex, 2) ;
  int verticalInRow = inRow(board, rowIndex, colIndex,  3) ;
  int bottomLeftToTopRight =  inRow(board, rowIndex, colIndex , 4) + inRow(board, rowIndex, colIndex, 5);
  int topLeftToBottomRight =  inRow(board, rowIndex, colIndex , 6) + inRow(board, rowIndex, colIndex, 7);

  if( horizontalInRow >= 4 || verticalInRow >=4 || bottomLeftToTopRight>=4 ){
    return 1; //someone won!
  }
  else{
  return 0; //keep playing
  }

}


/*int AI(char board[rows][columns], int parent, int cols, int depth, int color  ){
  int scoreOfBoard = score(board);

}*/



int dropAPiece(char board[rows][columns], int numberOfTurns, int playMode){
  int columnDrop;

  while(1){
    //dropping a piece into zero is messed up idkkkk whyyyy im crying
    if( numberOfTurns % 2 == 0 ){
      printf("Player 1, which column would you like to drop your piece in?\n");
      scanf("%d", &columnDrop);

      if(columnDrop > (columns) || columnDrop <= 0  ){
        printf("You have entered an invalid input please try again\n");
      }
      if( board[0][(columnDrop-1)] != '-'){
        printf("Error: That column is alread full. \n");
      }
      printf("\n");
      if( columnDrop <= columns){
        columnDrop = columnDrop -1; //zero index
          for( int i= (rows - 1) ; i >= 0; i-- ){
              if( board[i][columnDrop] == '-' && board[i][columnDrop] != 'o'){
                board[i][columnDrop] = 'x';
                printBoard( board);
                printf("a\n");
                printf("Row:  %d", i);
                printf("        column #: %d\n",columnDrop);
                gameStautus = checkWinner( board, numberOfTurns, i, columnDrop);
                printf("\n");
                return gameStautus;
              }
            }
        }
    }

    if ( (numberOfTurns % 2 != 0) && playMode ==1){
      printf("Player 2, which column would you like to drop your piece in?\n");
      scanf("%d", &columnDrop);
        if(columnDrop > columns){
          printf("You have entered an invalid input please try again\n");
        }
        if( board[0][(columnDrop-1)] != '-'){
          printf("Error: That column is alread full. \n");
        }
        printf("\n");
        if( columnDrop <= columns){
          columnDrop = columnDrop -1; //zero index
        for( int i= (rows - 1) ; i >= 0; i-- ){
          if( board[i][columnDrop] == '-' && board[i][columnDrop] != 'x'){
            board[i][columnDrop] = 'o';
            printBoard( board);
            printf("a\n");
            printf("Row:  %d", i);
            printf("        column #: %d\n",columnDrop);
            gameStautus = checkWinner( board, numberOfTurns, i, columnDrop);
            return gameStautus;
          }
        }
      }
    }

  /*else{
    // calculate the column the computer should drop down using the Negamax algorithm
    int columnDrop = AI(currentBoard, -1, columnDrop, getDepth(), 1);

    for( i= (rows - 1) ; i >= 0; i-- ){
        if( board[i][columnDrop] == '-' && board[i][columnDrop] != 'x'){
          board[i][columnDrop] = '0';
          printBoard( board);
          gameStautus = checkWinner( board, numberOfTurns, i, columnDrop);
          printf("\n");
          return gameStautus;
        }
      }
    return 0;
  }*/
}
}





int main(){
    int userInput;

    //intro screen and getting board size
    printf("\n=========================================\n");
    printf("Welcome to Connect Four!!\n");
    printf("Please enter the dimensions you want your board to be\n");
    printf("Warining: any dimensions larger than 40 x 40 will have unwidely screen handlings\n");
    printf("Warning: any dimensions smaller than 4 x 4 will be too small to play Connect Four\n");
    while(1){
      printf("rows:");
      scanf("%d",&rows);
      printf("columns:");
      scanf("%d",&columns);
      if(rows < 4 || columns < 4){
        printf("The board size you have entered is too small, please select a larger size\n");
      }
      else{
        break;
      }
    }

    printf("Board size is %d rows and %d columns.", rows, columns);



    userInput = printMenue();

    //The real code for this game takes place in this while loop, with
    //calls to various functions
    while( userInput != 4){
      numberOfTurns = 0;

      if( userInput == 3 ){
        userInput = printMenue();
      }

      //sets board
      char board[rows][columns];
      for(int i=0; i<rows; i++){
        for(int j=0; j< columns ; j++ ){
          board[i][j] = '-';
        }
      }

        while( userInput == 1 || userInput== 2 ){
          printBoard( board );
          //player vs. player
          while( numberOfTurns != (rows * columns) && userInput == 1){
            gameStautus = dropAPiece (board, numberOfTurns, userInput);

            if( gameStautus == 1 ){
              if( numberOfTurns % 2 == 0 ){
                printf("Congratulations Player 1! You won!\n");
              }
              else{
              //if( numberOfTurns % 2 != 0 ){
                printf("Congratulations Player 2! You won!\n");
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
                printf("Congratulations Player 1! You won!\n");
              }
              else{
              //if( numberOfTurns % 2 != 0 ){
                printf("Sorry, You Lose!\n");
              }
              numberOfTurns = (rows * columns)-1;
            }

            numberOfTurns = numberOfTurns + 1;
          }
            printf("There was a tie!");

          break;
      }

      //while loop determining play again
      while(numberOfTurns == (rows*columns)){
        int playAgain;
        printf("Would you like to play again?\n");
        printf("Please enter 1 for yes or 2 for no\n");
        scanf("%d", &playAgain);
        if( playAgain != 1 && playAgain != 2){
          printf("*****You have entered an invalid input please try again.*****\n\n");
        }
        if( playAgain == 2){
          userInput = 4;
          break;
        }
        if(playAgain == 1){
          break;
        }
      }


      printf("\n");
    }
  printf("Thank You for Playing!\n");
  printf("Goodbye!\n");
	return 0;
}
