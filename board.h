//
//  board.h
//  sharkGame
//
//  created by Kyuri on 2023//11/21.
//
#define BOARDSTATUS_OK        1
#define BOARDSTATUS_NOK       0//파손된 칸  매크로를 처음에 board.c에 놨다가 main.c에 알려야해서 board.h로 옮김. 
#define N_BOARD               15//board.c에 있는거 옮김. 

int board_initboard(void);
int board_printBoardStatus(void); //매턴마다 출력시키는 함수

int board_getBoardStatus(int pos);//보드 어디까지 파손되었니 
int board_getBoardCoin(int pos);//동전습득(동전이 있는지는 board.c에 있으므로 함수호출)
//헤더용함수의 int pos는 int가 중요한거지 pos가 중요한것은 아님. 

//int board_getSharkPosition(void);//상어 위치 반환
int board_stepShark(void);//상어 전진 명령 
