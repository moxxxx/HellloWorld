#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_POS 70
#define MAX_STR 32
#define TRUE     1
#define FALSE    0
#define MAX_NUM 10

int  randomInt(int);
void printPosition(char * array);
int  tortMove(int random, int position);
int  hareMove(int random, int position);
int  gameover(int positionH, int positionT);



int main()
{
  char  path[MAX_POS];
  int   positionT, positionH = 0;
  srand(time(NULL));

  while(1){
    positionH = hareMove(randomInt(MAX_NUM),positionH);
    positionT = tortMove(randomInt(MAX_NUM),positionT);

    //fill the path array
    for (int i = 0; i< MAX_POS;++i){
      if (i == positionH && i == positionT){
        path[i] = 'B';
      }else if (i == positionH){
        path[i] = 'H';
      }else if (i == positionT){
        path[i] = 'T';
      }else{
        path[i] = ' ';
      }
    }
    //print position
    printPosition(path);

    //see if someone win
    if (gameover(positionH,positionT) == 1)break;
  }
  return 0;
}


/*
  Function:  randomInt
  Purpose:   returns a random number in the range [0,max)
  Parameters:
    in:      maximum of range
    return:  randomly generated number
*/

int randomInt(int max)
{
  return(rand() % max);
}

void printPosition(char * array){
  printf("|");
  for (int i = 0; i < MAX_POS; ++i){
    printf("%c",array[i]);
  }
  printf("|\n");
}

int  tortMove(int random, int position){
  if (random<5){
    position +=3;
  }else if(random<8){
    position++;
  }else{
    position -=6;
  }
  if (position <= 0) return 0;
  if (position >= 70) return 69;
  return position;
}

int  hareMove(int random, int position){
  if (random<2){
    position +=9;
  }else if(random<5){
    position++;
  }else if(random<6){
    position -=12;
  }else if(random<8){
    position -=2;
  }else{
    //sleep......
  }
  if (position <= 0) return 0;
  else if (position >= 70) return 69;
  return position;
}

int gameover(int positionH, int positionT){
  if (positionH == 69 && positionT == 69){
    printf("Tie!\n");
    return 1;
  }else if(positionH == 69) {
    printf("Winner is Harold!!!\n");
    return 1;
  }else if (positionT == 69){
    printf("Winner is Timmy!!!\n");
    return 1;
  }
  return 0;
}
