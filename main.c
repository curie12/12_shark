#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define  MAX_CHARNAME   200
#define  N_PLAYER       3 
#define  MAX_DIE        6

#define  PLAYERSTATUS_LIVE  0
#define  PLAYERSTATUS_DIE   1
#define  PLAYERSTATUS_END   2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];//0-live, 1-die, 2-end
char player_statusString[3][MAX_CHARNAME]={"LIVE", "DIE", "END"};

void opening(void)
{
     printf("===================================================================\n");
     printf("*******************************************************************\n");
     printf("                            SHARK GAME                             \n");
     printf("*******************************************************************\n");
     printf("===================================================================\n");
}

int rolldie(void)
{
    return rand()%MAX_DIE+1;
}
void printPlayerPosition(int player)
{
     int i;
     for(i=0;i<N_BOARD;i++)
     {
          printf("|");
          if (i == player_position[player])
             printf("%c", player_name[player][0]);
          else
          {
              if(board_getBoardStatus(i) == BOARDSTATUS_NOK)
                  printf("X");
              else
                  printf(" ");
          }                 
     }
     printf("|\n");
}
void printPlayerStatus(void)
{
     int i;
     printf("player status ---\n");
     for(i=0;i<N_PLAYER;i++)
     {
          printf("%s : pos %i, coin %i, status %s\n", player_name[i], player_position[i], player_coin[i],
                     player_statusString[player_status[i]]);
          printPlayerPosition(i);
     }
     printf("------------------\n");
}
void checkDie(void)
{
     int i;
     for (i=0; i<N_PLAYER;i++)
     {
         if (board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
            player_status[i] = PLAYERSTATUS_DIE;
     }     
}
/*void closing(void)
{
     printf("===================================================================\n");
     printf("*******************************************************************\n");
     printf("                         CONGRATULATION                            \n");
     printf("*******************************************************************\n");
     printf("===================================================================\n");
}*/    

int main(int argc, char *argv[])
{
  int pos = 0;
  int i;
  int turn = 0; 
  srand((unsigned)time(NULL));
  
  //0. opening
  opening();
  
  //1. �ʱ�ȭ& �÷��̾� �̸� ����
  board_initboard();
  //1-2. PLAYER INIT.-�ʱ�ȭ�� �ѹ������ϰ� ���̶� �Լ�ȭ�� �ʼ��� �ƴ�.
  for(i=0;i<N_PLAYER;i++)
  {
       player_position[i] = 0;
       player_coin[i] = 0;
       player_status[i] = PLAYERSTATUS_LIVE;
       //player name
       printf("Player %i's name:", i); 
       scanf("%s", player_name[i]); //��ü�� �����Ͷ� &�ʿ����.           
                         
  } 
  
  //2. �ݺ���(�÷��̾� ��)
  do{
       int step = rolldie();
       int coinResult;
       char c;
       
       if (player_status[turn] != PLAYERSTATUS_LIVE)//�װų� ������ ����϶� ���̾����. 
       {
            turn = (turn +1)%N_PLAYER; 
            continue;//� ���� �����ÿ� �Ʒ��Ž�����ϰ� �ٷ����δٽÿö�. 
       }
       //2-1. �÷��̾� ���� ���
       board_printBoardStatus();
       for(i=0;i<N_PLAYER;i++)
            printPlayerPosition(i);
       printPlayerStatus();
       
       //2-2. �ֻ��� ������
       printf("%s turn!!", player_name[turn]);
       printf("press any key\n");
       scanf("%d", &c);//while�� �� ���ư��� ��ü���ȵ�. �׷��� ���� ����. 
       fflush(stdin);//�Է��ؾ� �����ٷ� �Ѿ�� buffer, stdin:ǥ���Է� 
       step = rolldie();
       
       //2-3. �̵�
       player_position[turn] += step;
       //�������� ��� �����ؾ���
       if (player_position[turn] >= N_BOARD-1)//�̵��� ��ġ�� ���ȣ �̻��̴�.
       { 
             player_position[turn] = N_BOARD-1; 
             player_status[turn] = PLAYERSTATUS_END;
       }                                          
       //��ġ��� printf("player[turn]�� ��ġ�� %i�Դϴ�.");
       
       //2-4. ���� �ݱ� 
       coinResult = board_getBoardCoin(player_position[turn]);//
       player_coin[turn] += coinResult;
       //printf()
       
       
       //2-5. ������
       turn = (turn + 1) % N_PLAYER; //wrap around.
       
       //2-6. if(����: ��� �÷��̾ �ѹ��� ���� ����.)
       if (turn == 0)
       {
              //��� ����
              int shark_pos = board_stepShark();
              //printf()
              checkDie();//��ҳ� �׾��ĸ� �Ǵ� 
       } 
  } while(1);
       //3. ����(���� ���, ��� ��) 
        
  system("PAUSE");	
  return 0;
}