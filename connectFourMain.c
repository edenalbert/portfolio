//#include "connectFour.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//external variables
int rows;
int columns;
int i;
int j;

////uhhh idk if this is right---orginalprint board but i hate it now
/*
void printBoard(int rows, int columns){
  int i,j;

   for (i=0; i< rows ; i++) {
       printf ("+");
       for (j=0; j<columns; j++)
           printf("---+");
       printf ("\n");
       printf ("|");
       for (j=0; j<columns; j++)
           printf("   |");
       printf ("\n");
   }

   printf ("+");
   for (j=0; j<columns; j++)
       printf("---+");
   printf ("\n");
   return;
}
*/
void howToPlay(){
  printf("Connect four is a fairly simple game.\n");
  printf("In this version you will first decide whether you want to play against another player or against the computer.\n");
  printf("The computer will then randomly select a player to go first.\n");
  printf("When it is your turn you will type in a number corresponding to the column where you want to drop your piece in.\n");
  printf("The first player to get four pieces in a row either horizontally vertically or diagonally wins!\n\n");
  return;
}

void printMenue(){
  int menueChoice;
  printf("\n=========================================\n");
  printf("Please type in a number for an option below:\n");
  printf(" 1 - Two player game\n");
  printf(" 2 - Play against computer\n");
  printf(" 3 - How to Play\n");
  printf("\n=========================================\n");

  while (1) {
    scanf("%d", &menueChoice);
    //lolololol this doesnt word if it is a letter!
    //need to fix that
      if( (menueChoice != 1) && (menueChoice != 2) && (menueChoice != 3) ){
        printf("The number you have selected is invalid. Please try again.\n");
      }
      else{
        break;
      }
    }

    if( menueChoice == 1){
      printf("You have choosen two player mode.\n");
      printf("Player 1 will be 'x'\nPlayer 2 will be 'o'\n");
      //call some function
    }
    if( menueChoice == 2){
      printf("You have choosen to play agsinst the computer.\n");
      printf("You will be 'x'\nThe computer will be 'o'\n");
      //call some function
      //maybe i should make this a return function ? return value back to main, the main calls next function
    }
    if( menueChoice == 3){
      howToPlay();
      printMenue();
    }

  return;
}

void printBoard(char board[rows][columns], int rows, int columns){
  int k;
  int sizeofArray = columns * rows;
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

int main(){
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
  printMenue();
  char board[rows][columns];
  int n;
  //n = sizeof(board); test statement
  //printf("%d\n", n); test statement
  //for loops fills array with - ,so players know that spot is empty
  for(i=0; i<rows; i++){
    for(j=0; j< columns ; j++ ){
        board[i][j] = '-';
    }
  }
  printBoard( board, rows, columns);
  //choose who goes first function

  printf("hey\n");
	return 0;
}
