//
//  board.h
//  sharkGame
//
//  created by Kyuri on 2023//11/21.
//
#define BOARDSTATUS_OK        1
#define BOARDSTATUS_NOK       0//�ļյ� ĭ  ��ũ�θ� ó���� board.c�� ���ٰ� main.c�� �˷����ؼ� board.h�� �ű�. 
#define N_BOARD               15//board.c�� �ִ°� �ű�. 

int board_initboard(void);
int board_printBoardStatus(void); //���ϸ��� ��½�Ű�� �Լ�

int board_getBoardStatus(int pos);//���� ������ �ļյǾ��� 
int board_getBoardCoin(int pos);//��������(������ �ִ����� board.c�� �����Ƿ� �Լ�ȣ��)
//������Լ��� int pos�� int�� �߿��Ѱ��� pos�� �߿��Ѱ��� �ƴ�. 

//int board_getSharkPosition(void);//��� ��ġ ��ȯ
int board_stepShark(void);//��� ���� ��� 
