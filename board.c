//
//  board.c
//  sharkGame
//
//  created by Kyuri on 2023//11/21.
//
#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define N_BOARD         15//매크로로 정의하는게 편함
#define N_COINPOS       12
#define MAX_COIN        4

#define SHARK_INITPOS   -2//게임 난이도 조절
#define MAX_SHARKSTEP   6 

    
static int board_status[N_BOARD];//1차원 형태라 이렇게 잡음, N_BOARD개만큼 칸을 만들었고 상태저장하면됨. 
static int board_coin[N_BOARD];//i번째칸이 몇개짜리 코인이 있냐

static int board_sharkPosition; //static을 앞에 붙여서 외부에서 수정못하게. 
 

int board_initboard(void)//보드 초기화
{
    int i;
    for(i=0;i<N_BOARD;i++)
    {
         board_status[i] = BOARDSTATUS_OK;
         board_coin[i] = 0;                  
    }
    
    board_sharkPosition = SHARK_INITPOS;//상어의 처음 위치:조금뒤에서 출발한다. 
    
    for(i=0;i<N_COINPOS;i++)
    {
         int flag = 0;
         while(flag==0)
         {
             int allocPos = rand()%N_BOARD;
             if(board_coin[allocPos] == 0)
             {
                  board_coin[allocPos] = rand()%MAX_COIN+1;
                  flag = 1;
             }
         }
    }
    return 0;
}

int board_printBoardStatus(void) //매턴마다 출력시키는 함수 |X|X|X|O|O|O|이거 출력 
{
    int i;
    
    printf("========================= BOARD STATUS =======================\n");
    for(i=0; i<N_BOARD; i++)
    {
         printf("|");
         if(board_status[i] == BOARDSTATUS_NOK)
            printf("X");
         else
            printf("O");  
    }
    printf("\n");
    printf("--------------------------------------------------------------\n");
    return 0;
}

int board_getBoardStatus(int pos)//보드파손 여부 출 
{
    return board_status[pos];//전역변수를 밖에서 부를수 없으므로 return으로 빼줌 
}

int board_getBoardCoin(int pos)//동전습득(동전이 있는지는 board.c에 있으므로 함수호출)
{
    int coin = board_coin[pos];//부득이하게 지역변수 필요. 
    board_coin[pos] = 0;
    return coin;
}

//int board_getSharkPosition(void);//상어 위치 반환
int board_stepShark(void)//상어 전진 명령
{
    int step = rand()%MAX_SHARKSTEP +1;
    
    int i;
    for(i=board_sharkPosition+1; i<=board_sharkPosition+step ;i++)
    {
         if (i >= 0 && i < N_BOARD)
            board_status[i] = BOARDSTATUS_NOK;                
    }
    board_sharkPosition += step;
}
