//
//  board.c
//  sharkGame
//
//  created by Kyuri on 2023//11/21.
//
#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define N_BOARD         15//��ũ�η� �����ϴ°� ����
#define N_COINPOS       12
#define MAX_COIN        4

#define SHARK_INITPOS   -2//���� ���̵� ����
#define MAX_SHARKSTEP   6 

    
static int board_status[N_BOARD];//1���� ���¶� �̷��� ����, N_BOARD����ŭ ĭ�� ������� ���������ϸ��. 
static int board_coin[N_BOARD];//i��°ĭ�� �¥�� ������ �ֳ�

static int board_sharkPosition; //static�� �տ� �ٿ��� �ܺο��� �������ϰ�. 
 

int board_initboard(void)//���� �ʱ�ȭ
{
    int i;
    for(i=0;i<N_BOARD;i++)
    {
         board_status[i] = BOARDSTATUS_OK;
         board_coin[i] = 0;                  
    }
    
    board_sharkPosition = SHARK_INITPOS;//����� ó�� ��ġ:���ݵڿ��� ����Ѵ�. 
    
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

int board_printBoardStatus(void) //���ϸ��� ��½�Ű�� �Լ� |X|X|X|O|O|O|�̰� ��� 
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

int board_getBoardStatus(int pos)//�����ļ� ���� �� 
{
    return board_status[pos];//���������� �ۿ��� �θ��� �����Ƿ� return���� ���� 
}

int board_getBoardCoin(int pos)//��������(������ �ִ����� board.c�� �����Ƿ� �Լ�ȣ��)
{
    int coin = board_coin[pos];//�ε����ϰ� �������� �ʿ�. 
    board_coin[pos] = 0;
    return coin;
}

//int board_getSharkPosition(void);//��� ��ġ ��ȯ
int board_stepShark(void)//��� ���� ���
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
