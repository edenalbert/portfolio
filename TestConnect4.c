//#include "connectFour.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//external variables
int rows;
int columns;
int player; //1= player1, 2=player2, 3=computer
int i;
int j;
int numberOfTurns;
int gameStautus;  // 0 = no winner, 1 = player 1 won, 2 = player 2 won

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

  for(i=0; i<rows; i++){
    printf("|"); //prints right edge
    for(j=0; j< columns ; j++ ){
       printf(" %c |",board[i][j]);
     }
     printf("\n");
  }
  //prints column numbers on the bottom
  if( columns < 10){
  for(j=1; j< (columns+1) ; j++ ){
     printf("  %d ",j);
   }
  }
  else{
    for(j=1; j< 11 ; j++ ){
       printf("  %d ",j);
     }
     for(j=11; j< (columns+1) ; j++ ){
        printf(" %d ",j);
      }
  }
  printf("\n");
  return;
}

int checkWinner(char board[rows][columns], int numberOfTurns, int rowIndex, int colIndex){
  int sizeOfBoard = rows * columns;

  //no way there could be a connect four when both player 1 hasn't put in four pieces yet
  if(numberOfTurns > 7){ //or 8 maybe idk, indexing is weird
    return 0;
  }
    printf("whack\n");
  //check for vertical win
  //for vertical win, only have to check the column where a piece was last dropped into
    for (int row = rowIndex; row < (rows-1) ; rows++){
      if ( ( board[row][colIndex] == board[row+1][colIndex] ) && (board[row][colIndex] == board[row+2][colIndex]) && (board[row][colIndex] == board[row+3][colIndex]) ){
         printf("d");
         if( numberOfTurns % 2 == 0 ){
           return 1;
         }
         else{
           return 2;
         }
      }
    }


return 0;
}


int dropAPiece(char board[rows][columns], int numberOfTurns, int player){
  int columnDrop;

  while(1){
    //dropping a piece into zero is messed up idkkkk whyyyy im crying
    if( player == 1 ){
      printf("Player 1, which column would you like to drop your piece in?\n");
    }
    if( player == 2 ){
      printf("Player 2, which column would you like to drop your piece in?\n");
    }

    scanf("%d", &columnDrop);

    if(columnDrop > (columns) || columnDrop == 0 ){
      printf("You have entered an invalid input please try again\n");
    }

    if( board[0][(columnDrop-1)] != '-'){
      printf("Error: That column is alread full. \n");
    }

      printf("\n");
      if( columnDrop <= columns){
        columnDrop = columnDrop -1; //zero index
          for( i= (rows - 1) ; i >= 0; i-- ){
              if( board[i][columnDrop] == '-' && board[i][columnDrop] != 'o' && player==1){
                board[i][columnDrop] = 'x';
              }
              if( board[i][columnDrop] == '-' && board[i][columnDrop] != 'x' && player==2){
                  board[i][columnDrop] = 'o';
                }
                printBoard( board);
                gameStautus = checkWinner( board, numberOfTurns, i, columnDrop);
                printf("\n");
                return gameStautus;
              }
            }
    }

    /*else{
      printf("Player 2, which column would you like to drop your piece in?\n");
      scanf("%d", &columnDrop);
        if(columnDrop > columns){
          printf("You have entered an invalid input please try again\n");
        }
        printf("\n");
        if( columnDrop <= columns){
          columnDrop = columnDrop -1; //zero index
        for( i= (rows - 1) ; i >= 0; i-- ){
          if( board[i][columnDrop] == '-' && board[i][columnDrop] != 'x'){
            board[i][columnDrop] = 'o';
            printBoard( board);
            gameStautus = checkWinner( board, numberOfTurns, i, columnDrop);
            return gameStautus;
          }
        }
      }
    }
  }*/

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
      for(i=0; i<rows; i++){
        for(j=0; j< columns ; j++ ){
          board[i][j] = '-';
        }
      }

      while( userInput == 1 || userInput== 2 ){
          printBoard( board );
          player = 1;
          /*if(numberOfTurns % 2 == 0){
            player =1;
          }
          else{
            player =2;
          }*/

          //player vs. player
          while( numberOfTurns != (rows * columns) && userInput == 1){
            gameStautus = dropAPiece (board, numberOfTurns, player);
            //gameStautus = checkWinner( board, numberOfTurns , columnDrop);

            if( gameStautus == 1 ){
              printf("Congratulations Player 1! You won!\n");
              break;
            }
            if( gameStautus == 2 ){
              printf("Congratulations Player 2! You won!\n");
              break;
            }
              numberOfTurns = numberOfTurns + 1;
              if(numberOfTurns % 2 == 0){
                player =1;
              }
              else{
                player =2;
              }

          }

          //computer vs. player
          while( numberOfTurns != (rows * columns) && userInput == 2){
            //dropAPiece (board, rows, columns, numberOfTurns);
            numberOfTurns = numberOfTurns + 1;
          }

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
