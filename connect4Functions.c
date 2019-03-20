#include "connectFour.h"

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

void printMenue(){
  int menueChoice;

  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWelcome to Connect Four!!\n");
  printf("Please enter the dimensions you want your board to be\n");
  printf("rows:");
  scanf("%d",&rows);
  printf("columns:");
  scanf("%d",&columns);
  printf("Board size is %d rows and %d columns.", rows, columns);
  printf("Please type in a number for an option below\n");
  printf(" 1 - Two player game\n");
  printf(" 2 - Play against computer\n");
  printf(" 3 - How to Play\n");
  printf(" 4 - Settings\n");
  scanf("%d", &menueChoice);

  if( menueChoice == 1){
    printf("You have choosen two player mode.\n");
  }
  if( menueChoice == 2){
    printf("You have choosen to play agsinst the computer.\n");
  }
  if( menueChoice == 3){
    printf("directons");
  }
  if( menueChoice == 4){
    printf("Settings\n");
  }

  printBoard( rows, columns );
  return;
}
