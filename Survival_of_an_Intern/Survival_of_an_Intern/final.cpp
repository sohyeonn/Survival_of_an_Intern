#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include "errand.h"
#include "GameBoard.h"
#include <MMSystem.h>
#pragma warning( disable: 4996 )
#pragma comment(lib, "winmm.lib")

/* �÷� ���� */
#define BLUE 9
#define GREEN 10
#define SKY 11
#define RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15
#define DARK_RED 4
#define DARK_YEELOW 6
#define DARK_PURPLE 5
#define DARK_BLUE 3
#define GREY 8


/* �ƽ�Ű�ڵ尪 ���� */
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define ENTER 13

/*
0 ~ 9
: 48 ~ 57
*/

/* pc�ʱ� ��ǥ �� ���� */
#define pcPosX 2
#define pcPosY 8
#define npcPosX 68
#define npcPosY 11

typedef struct Ranking {
	int score;
	char name[3];
}Rank;
Rank rank[11] = { NULL };
int playcount = 0;
int curPosX = 0, curPosY = 1;

int selected = -1;
int passTo = 0;
int canInput = 1;

int num[8];
int n;

int pcSpeed = 30;
int day = 4; // ����
int pay = 35; // ���� ���� ����
int goal_pay = 40; //�ʱ� ��ǥ ���� ��
float bonus = 0;
int HP = 10;
int tmp_HP = 0;
int mydeskCount = 0;
int recyclebin = 0;

int madeCoffee = 0;
int phoneCalled = 0;
int printed = 0;
int chaeWorked = 0;
int kooWorked = 0;
int trash = 0;
int FaxAfterPrint = 0;
int difficulty = 10;
int npc_fail = 0;
int Koo_close = 0; // ģ�е�
int Chae_close = 0;
int stop_npc = 0;
int speedUp_npc = 0;
int npc_color = GREEN;
int board_type = 0;
COORD curPos_PC = { pcPosX,pcPosY }; // pc�� ��ǥ
COORD curPos_NPC = { npcPosX,npcPosY };
clock_t start, now;
clock_t stop_time_start, stop_time_now;
clock_t speedUp_time_start, speedUp_time_now;
double duration = 0;
int m = 1;

/*               ���� ����� ��               */

void SetCurrentCursorPos(int x, int y);
int NPCerrandSelect();
void NPCerrandPrint();
int NPC_TimeLimit();
COORD GetCurrentCursorPos();
void DrawGameBoard(void);
void show_PC();
void delete_PC();
void shiftRight_PC();
void shiftLeft_PC();
void shiftUp_PC();
void shiftDown_PC();
void processKeyinput_PC();
int detectCollision(int posX, int posY);
void show_NPC();
void delete_NPC();
void shiftRight_NPC();
void shiftLeft_NPC();
void shiftDown_NPC();
void shiftUp_NPC();
int followNPC();
void payDown();
void Koo_closeness();
void Chae_closeness();
void npcSpeedUp();
void npcStop();
void DrawGameStartBoard();
void DrawGameStartBoard_2();
void DrawGameStartBoard_3();
void GameBoardStart();
void GameBoardStart_2();
void DrawChatBoard();
void DrawGameFinishBoard();
void DrawGameRankingBoard();
void Redraw_GameBlocks(void);
void Redraw_StartBlocks(void);
void Redraw_SuccessBlocks(void);
void Redraw_FinishBlocks(void);
void Redraw_ChatBlocks(void);
void Redraw_Start2Blocks(void);
void Redraw_Start3Blocks(void);
void Redraw_NextBlocks(void);
void Redraw_RankingBlocks(void);
void RemoveCursor(void);
void ScoreCloseUpdate();
int stageClear();
void nextStage();
void nextStageBoard();
void hpUpdate();
void payUpdate();
void Success();
void Fail();
int doMyWork();
void myDeskUpdate(int i);
void Bonus();
void callErrand(int num);
int detectCatch();
void Redraw_Boards();
/*               �ɺθ� �Լ�               */

void initializedCoffee();
void initializedPrint();
void initializedChae();
void initializedKoo();
void initializedOh();
void removeFaxNumber();
void removeTrash();

void NPC1_coffee_errand();
void coffeeUpdate(int clear);
int makeCoffee();

void NPC1_print_errand();
void printUpdate(int clear);
int printing();

void NPC1_fax_errand();
void faxUpdate(int clear);
int phoneCall();
void faxNumber();

void pickUpTrash(int posX, int posY);
void dumpTrash();
void drawTrash(int posX, int posY);

void Chae_work_errand();
int chaeWorking();
void chaeUpdate(int clear);

void Koo_work_errand();
int kooWorking();
void kooUpdate(int clear);

void fax_after_print();
void toNPC1(int passTo);
void ReStart();

/*                    �Լ� ����γ�                     */

void main()
{
	int st = 1, z;
	int RePlay = 0;
	do {
		PlaySound(TEXT("START.wav"), NULL, SND_ASYNC | SND_LOOP);
		system("mode con:cols=134 lines=30");
		//int st = 1, z;
		char s[6] = { NULL };


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE); //�ܼ� �۾��� �������
		while (st != 0)
		{
			DrawGameStartBoard();
			RemoveCursor();
			for (int i = 0; i < 30; i++) {
				SetCurrentCursorPos(0, 0);
				if (_kbhit() != 0) {
					z = _getch();
				}
				if (z == ENTER) {
					st = 0;
					break;
				}
			}
		}
		z = 0;
		st = 1;
		Redraw_Boards();
		while (st != 0)
		{
			GameBoardStart_2();
			DrawGameStartBoard_3();
			RemoveCursor();
			for (int i = 0; i < 10; i++) {
				SetCurrentCursorPos(0, 0);
				if (_kbhit() != 0) {
					z = _getch();
				}
				if (z == ENTER) {
					st = 0;
					break;
				}
			}
		}
		z = 0;
		st = 1;
		Redraw_Boards();
		while (st != 0)
		{
			DrawGameStartBoard_2();
			GameBoardStart();
			RemoveCursor();
			for (int i = 0; i<4; i++)
				rank[playcount].name[i] = '\0';
			SetCurrentCursorPos(56, 18);
			scanf("%s", rank[playcount].name);
			if (rank[playcount].name[0] != NULL) {
				st = 0;
				break;
			}
		}

		z = 0;
		Redraw_Boards();
		DrawGameBoard();

		while (stageClear() == 0)
		{
			PlaySound(TEXT("BGM.wav"), NULL, SND_ASYNC | SND_LOOP);
			SetCurrentCursorPos(0, 23);
			printf("���� %d����    ���� %d����/ %d����(��ǥ����) \n",
				day, pay, goal_pay, bonus, Koo_close, Chae_close, rank[playcount].name);
			printf("ü��");
			for (int i = HP; i > 0; i--)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				printf("��");
			}
			printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			SetCurrentCursorPos(0, 25);
			printf("���ʽ� %.1f����    ������ + %d    ä�븮 + %d    �̿��� %s  \n",
				bonus, Koo_close, Chae_close, rank[playcount].name);
			SetCurrentCursorPos(pcPosX, pcPosY);
			show_PC();
			SetCurrentCursorPos(npcPosX, npcPosY);
			show_NPC();
			start = clock();
			duration = 0;
			while (duration < 100 || pay <= goal_pay)
			{
				switch (day)
				{
				case 1:
					if (n % 25 == 0)//4��
					{
						NPCerrandPrint();
					}
					break;
				case 2:
					if (n % 25 == 0)//4��
					{
						NPCerrandPrint();
					}
					break;
				case 3:
					if (n % 20 == 0)//5��
					{
						NPCerrandPrint();
					}
					break;
				case 4:
					if (n % 20 == 0)//5��
					{
						NPCerrandPrint();
					}
					break;
				case 5:
					if (n % 16 == 0)//6��
					{
						NPCerrandPrint();
					}
					break;
				}
				now = clock();
				NPC_TimeLimit();
				duration = (double)(now - start) / (CLOCKS_PER_SEC);
				hpUpdate();
				payUpdate();
				ScoreCloseUpdate();
				SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
				processKeyinput_PC();
				if (detectCatch() == -1)
				{
					npc_fail = -1;
					break;
				}

				if (npc_fail == -1)
					break;
				if (pay >= goal_pay)
					break;
				if (duration > 100)
					break;
				n++;
			}
			int whilecount = 1;

			if (stageClear() == -1)
			{
				Fail();
				rank[playcount].score = pay + Chae_close + Koo_close + bonus;

				RemoveCursor();
				whilecount = 1;
				while (whilecount != 0)
				{
					for (int i = 0; i < 100; i++) {
						SetCurrentCursorPos(0, 0);
						if (_kbhit() != 0) {
							z = _getch();
						}
						if (z == ENTER) {
							whilecount = 0;
							break;
						}
					}
				}
				PlaySound(TEXT("RANK.wav"), NULL, SND_ASYNC | SND_LOOP);
				Redraw_FinishBlocks();
				DrawGameRankingBoard();
				break;
			}

			else if (npc_fail == -1)
			{
				//z = 0;
				//RedrawBlocks();

				Fail();
				rank[playcount].score = pay + Chae_close + Koo_close + bonus;

				RemoveCursor();
				whilecount = 1;
				while (whilecount != 0)
				{
					for (int i = 0; i < 100; i++) {
						SetCurrentCursorPos(0, 0);
						if (_kbhit() != 0) {
							z = _getch();
						}
						if (z == ENTER) {
							whilecount = 0;
							break;
						}
					}
				}
				PlaySound(TEXT("RANK.wav"), NULL, SND_ASYNC | SND_LOOP);
				Redraw_FinishBlocks();
				DrawGameRankingBoard();

				break;
			}
			else if (stageClear() == 1 && day == 5)
			{

				Success();
				rank[playcount].score = pay + Chae_close + Koo_close + bonus;

				RemoveCursor();
				whilecount = 1;
				while (whilecount != 0)
				{
					for (int i = 0; i < 100; i++) {
						SetCurrentCursorPos(0, 0);
						if (_kbhit() != 0) {
							z = _getch();
						}
						if (z == ENTER) {
							whilecount = 0;
							break;
						}
					}
				}
				PlaySound(TEXT("RANK.wav"), NULL, SND_ASYNC | SND_LOOP);

				Redraw_SuccessBlocks(); Redraw_Boards();
				DrawGameRankingBoard();
				break;
			}

			else
			{
				nextStage();
				PlaySound(TEXT("NEXT_STAGE.wav"), NULL, SND_ASYNC);
				nextStageBoard();
				Sleep(3000);
				Redraw_Boards();
				DrawGameBoard();
			}
		}
		st = 1;
		z = 0;
		while (st != 0)
		{
			for (int i = 0; i < 100; i++) {
				SetCurrentCursorPos(0, 0);
				if (_kbhit() != 0) {
					z = _getch();
				}
				if (z == ENTER) {
					st = 0;
					RePlay = 1;
					ReStart();
					break;
				}
			}
		}
		Redraw_Boards();
		getchar();
	} while (RePlay == 1);
}

void GameBoardStart()
{
	int i;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	SetCurrentCursorPos(51, 3);
	printf(" ���� �� ����  ");
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	/* ID */
	SetCurrentCursorPos(44, 18);
	printf("ID :");
	SetCurrentCursorPos(41, 21);
	for (i = 0; i < 17; i++)
	{
		printf("��");
	}
	SetCurrentCursorPos(45, 16);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("Please enter your initials��");
	SetCurrentCursorPos(46, 23);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 159);
	printf(" Z O O N  I N T E R. ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 158);
	printf("�� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

	return;
}

void GameBoardStart_2()
{
	SetCurrentCursorPos(50, 3);
	printf("[ ���� ���丮 ]");
	SetCurrentCursorPos(42, 6);
	printf("��ư� 'Zoon Inter.' ���� ä�뿡");
	SetCurrentCursorPos(44, 7);
	printf("�հ��� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//11);
	printf("���ΰ�");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf(" '������'(PC).");
	SetCurrentCursorPos(43, 9);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//11);
	printf("������");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("�� �Ǳ� ���� ������ ����");
	SetCurrentCursorPos(41, 10);
	printf("������ �繫�ǿ��� ���ΰ��� �����ϴ�");
	SetCurrentCursorPos(45, 11);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//11);
	printf("����");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("(NPC)�� �����ϴ�..!");
	SetCurrentCursorPos(42, 12);
	printf("�ű⿡ �����ϸ� ���� ����ٴϴ�");
	SetCurrentCursorPos(45, 13);
	printf("���°��� ����(NPC)����!!");
	SetCurrentCursorPos(41, 16);
	printf("����'������'�� ���� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//11);
	printf("��");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("�� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//11);
	printf("����");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("��");
	SetCurrentCursorPos(43, 17);
	printf("�̰ܳ��� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//11);
	printf("������");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("�� �� �� ������!");
	SetCurrentCursorPos(45, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf(" �׷�, �Ի��Ͻðڽ��ϱ�? ");
	SetCurrentCursorPos(50, 23);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("PRESS [ ENTER ] ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	return;
}

void DrawGameStartBoard_3()
{
	int x, y;
	board_type = 3;
	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 2; x++)
		{
			if (gameStartBoard_3Info[y][x] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
			else if (gameStartBoard_3Info[y][x] == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE | (BLUE << 4));
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
			else if (gameStartBoard_3Info[y][x] == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);// | (BLUE << 4));
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}
}

void ReStart()
{
	int i;
	pay = 0;
	goal_pay = 10;
	day = 1;
	duration = 0;
	tmp_HP = 0;
	mydeskCount = 0;
	stop_npc = 0;
	speedUp_npc = 0;
	Chae_close = 0;
	Koo_close = 0;
	bonus = 0.0;
	stop_time_start = NULL;
	speedUp_time_start = NULL;

	n = 0;
	curPosY = 1;
	curPos_PC.X = pcPosX;
	curPos_PC.Y = pcPosY;
	curPos_NPC.X = npcPosX;
	curPos_NPC.Y = npcPosY;
	SetCurrentCursorPos(curPosX, curPosY);

	for (i = 0; i < 7; i++)
	{
		NPCerrand_occur[i] = 0;
	}
	madeCoffee = 0;
	phoneCalled = 0;
	printed = 0;
	chaeWorked = 0;
	kooWorked = 0;
	trash = 0;
	FaxAfterPrint = 0;
}

void SetCurrentCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int NPCerrandSelect()
{
	int num;
	srand((unsigned)time(NULL));
	switch (day)
	{
	case 1:
		num = rand() % 4;
		break;
	case 2:
		num = rand() % 5;
		break;
	case 3:
		num = rand() % 6;
		break;
	case 4:
		num = rand() % 7;
		break;
	case 5:
		num = rand() % 7;
		break;
	}
	return num;
}
void callErrand(int num) {
	switch (num) {
	case 0:
		canInput = 1;
		initializedOh();
		initializedCoffee();
		selected = 0;      // coffee     
		initializedPrint();
		initializedChae();
		initializedKoo();
		removeFaxNumber();
		removeTrash();
		break;
	case 1:
		canInput = 1;
		removeFaxNumber();
		selected = 1;      // fax
		faxNumber();
		initializedCoffee();
		initializedPrint();
		initializedChae();
		initializedKoo();
		initializedOh();
		removeTrash();
		break;
	case 2:
		canInput = 1;
		selected = 2;      // trash
		dumpTrash();
		SetCurrentCursorPos(37, 3);
		printf("0 / 6");
		initializedCoffee();
		initializedPrint();
		initializedChae();
		initializedKoo();
		initializedOh();
		removeFaxNumber();
		break;
	case 3:
		canInput = 1;
		initializedOh();
		initializedPrint();
		selected = 3;      // print
		initializedCoffee();
		initializedChae();
		initializedKoo();
		removeFaxNumber();
		removeTrash();
		break;
	case 4:
		canInput = 1;
		removeFaxNumber();
		selected = 4;      // fax print
		initializedCoffee();
		initializedPrint();
		initializedChae();
		initializedKoo();
		initializedOh();
		removeTrash();
		break;
	case 5:
		canInput = 1;
		initializedKoo();
		selected = 5;      // koo
		SetCurrentCursorPos(37, 19);
		printf("KOO WORK");
		initializedCoffee();
		initializedPrint();
		initializedChae();
		initializedOh();
		removeFaxNumber();
		removeTrash();
		break;
	case 6:
		canInput = 1;
		initializedChae();
		selected = 6;      // chae
		SetCurrentCursorPos(24, 19);
		printf("CHAE WORK");
		initializedCoffee();
		initializedPrint();
		initializedKoo();
		initializedOh();
		removeFaxNumber();
		removeTrash();
		break;
	default:
		break;
	}
}

void NPCerrandPrint()
{
	int num;
	num = NPCerrandSelect();
	curPosY++;
	if (n == 0)
		curPosY--;
	SetCurrentCursorPos(74, curPosY);
	printf("%s\n", NPCerrandType[num]);
	NPC_start[num] = clock();//NPC �ð� ���� ����   

	NPCerrand_occur[num] = 1;
	curPosY++;

	callErrand(num);
}
int NPC_TimeLimit()
{
	if (NPCerrand_occur[0] == 1)//Ŀ��
	{
		NPC_duration[0] = (double)(now - NPC_start[0]) / (CLOCKS_PER_SEC);
		if (NPC_duration[0] > 15)
		{
			//PlaySound(TEXT("DEBUFF.wav"),NULL,SND_ASYNC);
			passTo = 0;
			SetCurrentCursorPos(6, 17);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf(" FAIL  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

			NPCerrand_occur[0] = 0;
			npcSpeedUp();

			curPosY--;
			DrawChatBoard();
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff_e[0]);
			curPosY++;
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff[0]);

			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 0;
			//��� ����
		}
		else
		{
			if (madeCoffee == 2) {
				//PlaySound(TEXT("BUFF.wav"),NULL,SND_ASYNC);
				madeCoffee = 0;
				canInput = -1;

				NPCerrand_occur[0] = 0;
				//hpUp();
				npcStop();
				curPosY--;
				DrawChatBoard();
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff_e[0]);
				curPosY++;
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff[0]);

				SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
				return 0;
			}

			SetCurrentCursorPos(74, curPosY);
			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[0]);
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 1;

		}
	}
	if (NPCerrand_occur[1] == 1)//�ѽ�
	{
		NPC_duration[1] = (double)(now - NPC_start[1]) / (CLOCKS_PER_SEC);
		if (NPC_duration[1] > 15)
		{
			// PlaySound(TEXT("DEBUFF.wav"),NULL,SND_ASYNC);
			removeFaxNumber();
			SetCurrentCursorPos(32, 11);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf("  FAIL");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

			NPCerrand_occur[1] = 0;
			payDown();
			curPosY--;
			DrawChatBoard();
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff_e[1]);
			curPosY++;
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff[1]);

			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 0;
			//��� ����
		}
		else
		{
			if (phoneCalled == 1) {
				// PlaySound(TEXT("BUFF.wav"),NULL,SND_ASYNC);
				phoneCalled = 0;

				NPCerrand_occur[1] = 0;
				Bonus();
				ScoreCloseUpdate();
				curPosY--;
				DrawChatBoard();
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff_e[1]);
				curPosY++;
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff[1]);

				SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
				return 0;
				// �μ� �ɺθ� ���� ��������
			}
			SetCurrentCursorPos(74, curPosY);
			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[1]);
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 1;
		}
	}
	if (NPCerrand_occur[2] == 1)//������
	{
		NPC_duration[2] = (double)(now - NPC_start[2]) / (CLOCKS_PER_SEC);
		if (NPC_duration[2] > 15)
		{
			//  PlaySound(TEXT("DEBUFF.wav"),NULL,SND_ASYNC);
			removeTrash();
			SetCurrentCursorPos(37, 3);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf("FAIL");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

			NPCerrand_occur[2] = 0;
			//hpDown();
			npcSpeedUp();
			curPosY--;
			DrawChatBoard();
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff_e[2]);
			curPosY++;
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff[2]);

			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 0;
			//�ð� �ʰ� ����
		}
		else
		{
			if (trash == 6) {
				// PlaySound(TEXT("BUFF.wav"),NULL,SND_ASYNC);
				trash = 0;

				NPCerrand_occur[2] = 0;
				//hpUp();
				npcStop();
				curPosY--;
				DrawChatBoard();
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff_e[2]);
				curPosY++;
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff[2]);

				SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
				return 0;
				// ������ �ɺθ� ���� ���� ����
			}
			SetCurrentCursorPos(74, curPosY);
			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[2]);
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 1;
		}
	}
	if (NPCerrand_occur[3] == 1)//�μ��
	{
		NPC_duration[3] = (double)(now - NPC_start[3]) / (CLOCKS_PER_SEC);
		if (NPC_duration[3]> 15)
		{
			// PlaySound(TEXT("DEBUFF.wav"),NULL,SND_ASYNC);
			passTo = 0;
			SetCurrentCursorPos(57, 18);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf("   FAIL   ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

			NPCerrand_occur[3] = 0;
			//hpDown();
			npcSpeedUp();
			curPosY--;
			DrawChatBoard();
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff_e[3]);
			curPosY++;
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff[3]);

			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 0;
			//��� ����
		}
		else
		{
			if (printed == 2) {
				// PlaySound(TEXT("BUFF.wav"),NULL,SND_ASYNC);
				printed = 0;
				canInput = -1;

				NPCerrand_occur[3] = 0;
				Bonus();
				ScoreCloseUpdate();
				curPosY--;
				DrawChatBoard();
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff_e[3]);
				curPosY++;
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff[3]);

				SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
				return 0;
			}
			SetCurrentCursorPos(74, curPosY);
			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[3]);
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 1;
		}
	}
	if (NPCerrand_occur[4] == 1)//�ѽ�-�μ�
	{
		NPC_duration[4] = (double)(now - NPC_start[4]) / (CLOCKS_PER_SEC);
		if (NPC_duration[4]> 15)
		{
			// PlaySound(TEXT("DEBUFF.wav"),NULL,SND_ASYNC);
			NPCerrand_occur[4] = 0;
			//npcSpeedUp();
			payDown();
			curPosY--;
			DrawChatBoard();
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff_e[4]);
			curPosY++;
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff[4]);

			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 0;
			//��� ����
		}
		else
		{
			if (FaxAfterPrint == 2) {
				// PlaySound(TEXT("BUFF.wav"),NULL,SND_ASYNC);
				FaxAfterPrint = 0;

				NPCerrand_occur[4] = 0;
				Bonus();
				ScoreCloseUpdate();
				curPosY--;
				DrawChatBoard();
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff_e[4]);
				curPosY++;
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff[4]);

				SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
				return 0;
			}
			SetCurrentCursorPos(74, curPosY);
			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[4]);
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 1;
		}
	}
	if (NPCerrand_occur[5] == 1)//������
	{
		NPC_duration[5] = (double)(now - NPC_start[5]) / (CLOCKS_PER_SEC);
		if (NPC_duration[5]> 15)
		{
			// PlaySound(TEXT("DEBUFF.wav"),NULL,SND_ASYNC);
			SetCurrentCursorPos(37, 19);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf("   FAIL  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

			NPCerrand_occur[5] = 0;
			//hpDown();
			///npcSpeedUp();
			payDown();
			curPosY--;
			DrawChatBoard();
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff_e[5]);
			curPosY++;
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff[5]);

			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 0;
			//��� ����
		}
		else
		{
			if (kooWorked == 1) {
				// PlaySound(TEXT("BUFF.wav"),NULL,SND_ASYNC);
				kooWorked = 0;

				NPCerrand_occur[5] = 0;
				//hpUp();
				//npcStop();
				curPosY--;
				DrawChatBoard();
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff_e[5]);
				curPosY++;
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff[5]);
				Koo_close++;
				SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
				return 0;
				// ������ �ɺθ� ���� ���� ����
			}
			SetCurrentCursorPos(74, curPosY);
			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[5]);
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 1;
		}
	}
	if (NPCerrand_occur[6] == 1)//ä�븮
	{
		NPC_duration[6] = (double)(now - NPC_start[6]) / (CLOCKS_PER_SEC);
		if (NPC_duration[6]> 15)
		{
			// PlaySound(TEXT("DEBUFF.wav"),NULL,SND_ASYNC);
			SetCurrentCursorPos(24, 19);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf("   FAIL  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

			NPCerrand_occur[6] = 0;
			npcSpeedUp();
			curPosY--;
			DrawChatBoard();
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff_e[6]);
			curPosY++;
			SetCurrentCursorPos(74, curPosY);
			printf("%s\n", Debuff[6]);

			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 0;
			//��� ����
		}
		else
		{
			if (chaeWorked == 1) {
				// PlaySound(TEXT("BUFF.wav"),NULL,SND_ASYNC);
				chaeWorked = 0;

				NPCerrand_occur[6] = 0;
				//hpUp();
				//npcStop();
				curPosY--;
				DrawChatBoard();
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff_e[6]);
				curPosY++;
				SetCurrentCursorPos(74, curPosY);
				printf("%s\n", Buff[6]);
				Chae_close++;
				SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
				return 0;
				// ä�븮 �ɺθ� ���� ���� ����
			}
			SetCurrentCursorPos(74, curPosY);
			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[6]);
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return 1;
		}
	}

	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}

COORD GetCurrentCursorPos()
{
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;

	return curPoint;
}

void DrawGameBoard(void)
{
	int x, y;
	board_type = 0;

	//PlaySound(TEXT("BGM.wav"), NULL, SND_ASYNC);

	/* �ð� �κ� ó�� */
	for (y = 0; y < GBOARD_HEIGHT + 1; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 2; x++)
		{
			if (gameBoardInfo[y][x] != -9 && gameBoardInfo[y][x] <= 0)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
			if (gameBoardInfo[y][x] == -9)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				SetCurrentCursorPos(x * 2, y);
				printf("��");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			}
			if (gameBoardInfo[y][x] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 121);
				SetCurrentCursorPos(x * 2, y);
				//printf("��");
				printf("��");
				//printf("��");

			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			if (gameBoardInfo[y][x] == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				SetCurrentCursorPos(x * 2, y);
				printf("��");
				//printf("��");
				//printf("��");
				//printf("��");
				//printf("��");
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			if (gameBoardInfo[y][x] == 3)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
			if (gameBoardInfo[y][x] == 4)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}

		}
	}

	SetCurrentCursorPos(8, 3);
	printf("�� å��");
	SetCurrentCursorPos(8, 5);
	printf("W O R K");

	SetCurrentCursorPos(36, 2);
	printf("������");

	SetCurrentCursorPos(60, 4);
	printf("�� ����");
	SetCurrentCursorPos(61, 5);
	printf("å��");
	SetCurrentCursorPos(59, 7);
	printf("[ SPACE ]");

	SetCurrentCursorPos(33, 10);
	printf("�ѽ���");

	SetCurrentCursorPos(5, 15);
	printf("Ŀ����Ʈ");
	SetCurrentCursorPos(6, 17);
	printf("M A K E");

	SetCurrentCursorPos(26, 17);
	printf("ä�븮");
	SetCurrentCursorPos(27, 18);
	printf("å��");
	SetCurrentCursorPos(24, 19);
	//printf("%d / 10", Chae_desk);
	printf("CHAE WORK");

	SetCurrentCursorPos(38, 17);
	printf("������");
	SetCurrentCursorPos(39, 18);
	printf("å��");
	SetCurrentCursorPos(37, 19);
	//printf("%d / 10", Koo_desk);
	printf("KOO WORK");

	SetCurrentCursorPos(59, 16);
	printf("�μ��");
	SetCurrentCursorPos(58, 18);
	printf("P R I N T");
}

void ScoreCloseUpdate() {
	SetCurrentCursorPos(0, 25);
	printf("���ʽ� %.1f����    ������ + %d    ä�븮 + %d    �̿��� %s  \n",
		bonus, Koo_close, Chae_close, rank[playcount].name);
	SetCurrentCursorPos(pcPosX, pcPosY);
}

void show_PC()
{
	//curPos_PC = GetCurrentCursorPos();
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	printf("��");
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}
void show_NPC()
{
	//curPos_NPC = GetCurrentCursorPos();
	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), npc_color);
	printf("��");
	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void delete_PC()
{
	//COORD curPos_PC = GetCurrentCursorPos();
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
	printf(" ");
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void delete_NPC()
{
	//COORD curPos_NPC = GetCurrentCursorPos();
	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
	printf(" ");
	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
}

void shiftRight_PC()
{
	if (detectCollision(curPos_PC.X + 2, curPos_PC.Y) == 0)
		return;
	if (selected == 2)
		pickUpTrash(curPos_PC.X + 2, curPos_PC.Y);
	delete_PC();
	curPos_PC.X += 2;
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
	show_PC();
}
void shiftRight_NPC()
{
	if (detectCollision(curPos_NPC.X + 2, curPos_NPC.Y) == 0)
		return;
	delete_NPC();
	curPos_NPC.X += 2;
	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
	show_NPC();
	if (selected == 2)
		drawTrash(curPos_NPC.X - 2, curPos_NPC.Y);
	//   SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void shiftLeft_PC()
{
	if (detectCollision(curPos_PC.X - 2, curPos_PC.Y) == 0)
		return;
	if (selected == 2)
		pickUpTrash(curPos_PC.X - 2, curPos_PC.Y);
	delete_PC();
	curPos_PC.X -= 2;
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
	show_PC();
}
void shiftLeft_NPC()
{
	if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 0)
		return;

	delete_NPC();
	curPos_NPC.X -= 2;
	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
	show_NPC();
	if (selected == 2)
		drawTrash(curPos_NPC.X + 2, curPos_NPC.Y);
	//   SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
}
void shiftUp_PC()
{
	if (detectCollision(curPos_PC.X, curPos_PC.Y - 1) == 0)
		return;
	if (selected == 2)
		pickUpTrash(curPos_PC.X, curPos_PC.Y - 1);
	delete_PC();
	curPos_PC.Y -= 1;
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
	show_PC();
}
void shiftUp_NPC()
{
	if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 0)
		return;

	delete_NPC();
	curPos_NPC.Y -= 1;
	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
	show_NPC();
	if (selected == 2)
		drawTrash(curPos_NPC.X, curPos_NPC.Y + 1);
	//   SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
}
void shiftDown_PC()
{
	if (detectCollision(curPos_PC.X, curPos_PC.Y + 1) == 0)
		return;
	if (selected == 2)
		pickUpTrash(curPos_PC.X, curPos_PC.Y + 1);
	delete_PC();
	curPos_PC.Y += 1;
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
	show_PC();
}
void shiftDown_NPC()
{
	if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0)
		return;

	delete_NPC();
	curPos_NPC.Y += 1;
	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
	show_NPC();
	if (selected == 2)
		drawTrash(curPos_NPC.X, curPos_NPC.Y - 1);
	//   SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
}
int detectCatch()
{
	int dx = curPos_PC.X - curPos_NPC.X;
	int dy = curPos_PC.Y - curPos_NPC.Y;
	if (dx == 0 && dy == 0)
	{
		return -1;
	}
	return 1;
}

int followNPC()
{
	double stop_duration = 0.0;
	double speedUp_duration = 0.0;

	int dx = curPos_PC.X - curPos_NPC.X;
	int dy = curPos_PC.Y - curPos_NPC.Y;
	if (speedUp_npc == 1)
	{
		speedUp_time_now = clock();
		speedUp_duration = (double)(speedUp_time_now - speedUp_time_start) / CLOCKS_PER_SEC;
		if (speedUp_duration >= 10)
		{
			difficulty = 10;
			npc_color = GREEN;
			speedUp_npc = 0;
		}

	}
	if (stop_npc == 1)
	{
		stop_time_now = clock();
		stop_duration = (double)(stop_time_now - stop_time_start) / CLOCKS_PER_SEC;
		if (stop_duration < 5)
			return 0;
		else
			stop_npc = 0;
	}
	if (dx == 0 && dy == 0)
	{
		return -1;
	}

	if (dx < 0 && dy < 0) // PC�� ����, ���� ����
	{
		if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 0) //����x
		{
			if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 0) // ����x, ����x
			{
				shiftDown_NPC();
			}

			else  // ����x ���� o
			{
				shiftUp_NPC();
			}
		}
		else //���� o
		{
			if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 0) // ���� x
				shiftLeft_NPC();
			else //���� o 
			{
				if (dx*dx > dy*dy)
					shiftLeft_NPC();
				else
					shiftUp_NPC();
			}

		}

	}
	else if (dx < 0 && dy>0) // PC�� ����, �Ʒ� ����
	{

		if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 0) // ����x
		{
			if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0) // ����x, �Ʒ�x
			{
				shiftUp_NPC();
			}
			else //�Ʒ� o
			{
				shiftDown_NPC();
			}

		}
		else //���� o
		{
			if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0) //�Ʒ�x
				shiftLeft_NPC();
			else // ��o �Ʒ�x
			{
				if (dx*dx > dy*dy)
					shiftLeft_NPC();
				else
					shiftDown_NPC();
			}

		}

	}

	else if (dx < 0 && dy == 0) //PC�� ����, y��ǥ�� ������
	{

		if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 0) //����x
		{
			if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0) // �Ʒ�x
			{
				shiftUp_NPC();
			}
			else if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 1)//�Ʒ� o
			{
				shiftDown_NPC();
			}
			else if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 0) // �� x
			{
				shiftDown_NPC();
			}
			else if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 1)
			{
				shiftUp_NPC();
			}
		}
		else //����o
			shiftLeft_NPC();

	}

	else if (dx > 0 && dy < 0) //PC�� ������, ���ʿ� ������
	{

		if (detectCollision(curPos_NPC.X + 2, curPos_NPC.Y) == 0) // ������x
		{
			if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 0) // ���� x
			{
				shiftDown_NPC();
			}
			else // ����o
				shiftUp_NPC();
		}
		else // ������ o 
		{
			if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 0) // ����x
				shiftRight_NPC();
			else //������o, ����o
			{
				if (dx*dx > dy*dy)
					shiftRight_NPC();
				else
					shiftUp_NPC();
			}

		}

	}

	else if (dx > 0 && dy > 0) //PC�� ������, �Ʒ��� ���� ��
	{

		if (detectCollision(curPos_NPC.X + 2, curPos_NPC.Y) == 0) // ������x
		{
			if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0) //�Ʒ���x
			{
				shiftUp_NPC();
			}
			else  //�Ʒ���o
			{
				shiftDown_NPC();
			}

		}
		else // ������ o
		{

			if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0) // �Ʒ�x
				shiftRight_NPC();
			else //������o, �Ʒ�o
			{
				if (dx*dx > dy*dy)
					shiftRight_NPC();
				else
					shiftDown_NPC();
			}

		}

	}


	else if (dx > 0 && dy == 0) //PC�� ������, y��ǥ�� ������
	{

		if (detectCollision(curPos_NPC.X + 2, curPos_NPC.Y) == 0) //������x
		{
			if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0) // �Ʒ�x
			{
				shiftUp_NPC();
			}
			else if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 1) //�Ʒ�o
			{
				shiftDown_NPC();
			}
			else if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 0) // �� x
			{
				shiftDown_NPC();
			}
			else if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 1)
			{
				shiftUp_NPC();
			}
		}
		else
			shiftRight_NPC();

	}
	else if (dx == 0 && dy < 0) // PC x��ǥ ����, ���� ���� ��
	{
		if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 0) //��x
		{
			if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 0) // ����x
				shiftRight_NPC();
			else if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 1) //����o
				shiftLeft_NPC();
			else if (detectCollision(curPos_NPC.X + 2, curPos_NPC.Y) == 0) //������x
				shiftLeft_NPC();
			else if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 1)
				shiftRight_NPC();
		}
		else
		{
			shiftUp_NPC();
		}

	}
	else if (dx == 0 && dy > 0) // PC x��ǥ ����, �Ʒ��� ���� ��
	{
		if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0)
		{
			if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 0) // ����x
				shiftRight_NPC();
			else if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 1) //����o
				shiftLeft_NPC();
			else if (detectCollision(curPos_NPC.X + 2, curPos_NPC.Y) == 0) //������x
				shiftLeft_NPC();
			else if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 1)
				shiftRight_NPC();
		}
		else
		{
			shiftDown_NPC();
		}
	}
	Sleep(5);
	return 1;
}

void processKeyinput_PC()
{
	int key;
	int doneWork = 0;

	for (int i = 0; i<30; i++)
	{
		now = clock();
		duration = (double)(now - start) / (CLOCKS_PER_SEC);
		if (duration > 100)
			return;
		hpUpdate();
		NPC_TimeLimit();
		if (i%difficulty == 0)
		{
			npc_fail = followNPC();
		}


		if (npc_fail == -1)
		{
			Fail();
			break;
		}


		if (_kbhit() != 0)
		{
			key = _getch();
			switch (key)
			{
			case LEFT:
				shiftLeft_PC();
				if (detectCatch() == -1)
				{
					npc_fail = -1;
					break;
				}
				break;
			case RIGHT:
				shiftRight_PC();
				if (detectCatch() == -1)
				{
					npc_fail = -1;
					//NPCrestart = clock() / (CLOCKS_PER_SEC);
					break;
				}
				break;
			case UP:
				shiftUp_PC();
				if (detectCatch() == -1)
				{
					npc_fail = -1;
					//NPCrestart = clock() / (CLOCKS_PER_SEC);
					break;
				}
				break;
			case DOWN:
				shiftDown_PC();
				if (detectCatch() == -1)
				{
					npc_fail = -1;
					//NPCrestart = clock() / (CLOCKS_PER_SEC);
					break;
				}
				break;
			case 'w':
				if (detectCatch() == -1)
				{
					npc_fail = -1;
					//   NPCrestart = clock() / (CLOCKS_PER_SEC);
					break;
				}
				if (gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -1)
				{
					myDeskUpdate(0);
					while (1)
					{
						now = clock();
						duration = (double)(now - start) / (CLOCKS_PER_SEC);
						hpUpdate();
						NPC_TimeLimit();
						npc_fail = followNPC();
						doneWork = doMyWork();

						if (doneWork == 1)
						{
							pay++;
							payUpdate();
							break;
						}
						if (doneWork == -1)
						{
							SetCurrentCursorPos(8, 5);
							printf("W O R K");
							SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
							break;
						}
						if (doneWork == 2)
							return;
						if (duration > 100)
							return;
					}
				}
				break;
			case 'm':
				// Ŀ��   
				if (selected == 0 && canInput == 1)
					NPC1_coffee_errand();
				break;
			case '0':
				// �ѽ�
				if ((selected == 1 && canInput == 1) || (selected == 4 && FaxAfterPrint == 1))
					NPC1_fax_errand();

				break;
			case 'p':
				// ����Ʈ
				if (selected == 3 && canInput == 1)
					NPC1_print_errand();
				if (selected == 4 && canInput == 1)
					fax_after_print();

				break;
			case 'k':
				// ������
				if (selected == 5 && canInput == 1)
					Koo_work_errand();

				break;
			case 'c':
				// ä�븮
				if (selected == 6 && canInput == 1)
					Chae_work_errand();

				break;
			case SPACE:
				// �������ڸ��� ����
				if ((selected == 0 || selected == 3) && canInput == 0)
					toNPC1(passTo);

				break;
			default:
				break;
			}
			if (detectCatch() == -1)
			{
				npc_fail = -1;
				break;
			}
		}
		if (detectCatch() == -1)
		{
			npc_fail = -1;
			break;
		}
		Sleep(pcSpeed);

	}
}

int detectCollision(int posX, int posY) //�ε����� 0, �ƴϸ� 1, pc�� �浹�˻�
{
	int x = posX / 2;
	int y = posY;
	if (gameBoardInfo[y][x] > 0) // pc�� ��ġ��ǥ�� 0 �̻� �� ���
		return 0;
	return 1;
}

void Bonus()
{
	bonus += 0.5;
}

void payDown()
{
	int p = 0;
	p = pay % 10;
	pay = pay - p;
	payUpdate();
}

void Chae_closeness()
{
	Chae_close++;
}
void Koo_closeness()
{
	Koo_close++;
}

void DrawGameStartBoard()
{
	int x, y;
	char key = 0;
	board_type = 1;
	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 2; x++)
		{
			RemoveCursor();
			if (gameStartBoardInfo[y][x] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW | (DARK_YEELOW << 4));
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
			else if (gameStartBoardInfo[y][x] == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), SKY | (DARK_BLUE << 4));
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
			else if (gameStartBoardInfo[y][x] == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DARK_PURPLE);
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	SetCurrentCursorPos(72, 15);
	printf("����������<���� CHARACTER����CAST����>����������  ");
	SetCurrentCursorPos(72, 16);
	printf("������������������������������������������������  ");
	SetCurrentCursorPos(72, 17);
	printf("�����������������ϡ�浡�������������������������  ");
	SetCurrentCursorPos(72, 18);
	printf("�����������������塡浡�������������          ��  ");
	SetCurrentCursorPos(72, 19);
	printf("�����������������塡浡�������������          ��   ");
	SetCurrentCursorPos(72, 20);
	printf("������������ä�븮��浡�������ä��ȭ          ��   ");
	SetCurrentCursorPos(72, 21);
	printf("������������������������������������������������   ");
	SetCurrentCursorPos(72, 22);
	printf("������������������������������������������������   ");
	SetCurrentCursorPos(44, 24);
	printf(" < PRESS  ENTER  KEY  TO  START  GAME > ");
}
void DrawGameStartBoard_2()
{
	int x, y;
	board_type = 2;
	playcount++;
	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 2; x++)
		{
			if (gameStartBoard_2Info[y][x] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
			if (gameStartBoard_2Info[y][x] == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
			else if (gameStartBoard_2Info[y][x] == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE | (BLUE << 4));
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
			else if (gameStartBoard_2Info[y][x] == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);//| (BLUE << 4));
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}
}

void Redraw_GameBlocks(void)
{
	int x, y;
	int color = 9;
	int cursX, cursY;
	for (y = 0; y < GBOARD_HEIGHT + 5; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 5; x++)
		{
			if (gameBoardInfo[y][x] == 1 || gameBoardInfo[y][x] == 2 || gameBoardInfo[y][x] == 3 || gameBoardInfo[y][x] == 4
				|| gameBoardInfo[y][x] == -1 || gameBoardInfo[y][x] == -2 || gameBoardInfo[y][x] == -4 ||
				gameBoardInfo[y][x] == -5 || gameBoardInfo[y][x] == -6 || gameBoardInfo[y][x] == -7 ||
				gameBoardInfo[y][x] == -8 || gameBoardInfo[y][x] == -9 || gameBoardInfo[y][x] == 0)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("��");
				RemoveCursor();
			}
		}
	}
}
void Redraw_StartBlocks(void)
{
	int x, y;
	int color = 9;
	int cursX, cursY;
	for (y = 0; y < GBOARD_HEIGHT + 5; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 5; x++)
		{
			if (gameStartBoardInfo[y][x] == 1 || gameStartBoardInfo[y][x] == 2 || gameStartBoardInfo[y][x] == 3 || gameStartBoardInfo[y][x] == 0)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("��");
				RemoveCursor();
			}
		}
	}
}
void Redraw_SuccessBlocks(void)
{
	int x, y;
	int color = 9;
	int cursX, cursY;
	for (y = 0; y < GBOARD_HEIGHT + 5; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 5; x++)
		{
			if (gameSuccessBoardInfo[y][x] == 1 || gameSuccessBoardInfo[y][x] == 2 || gameSuccessBoardInfo[y][x] == 3 || gameSuccessBoardInfo[y][x] == 4
				|| gameSuccessBoardInfo[y][x] == 5 || gameSuccessBoardInfo[y][x] == 0)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("��");
				RemoveCursor();
			}
		}
	}
}
void Redraw_FinishBlocks(void)
{
	int x, y;
	int color = 9;
	int cursX, cursY;
	for (y = 0; y < GBOARD_HEIGHT + 5; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 5; x++)
		{
			if (gameFinishBoardInfo[y][x] == 1 || gameFinishBoardInfo[y][x] == 2 || gameFinishBoardInfo[y][x] == 0)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("��");
				RemoveCursor();
			}
		}
	}
}
void Redraw_ChatBlocks(void)
{
	int x, y;
	int color = 9;
	int cursX, cursY;
	for (y = 0; y < GBOARD_HEIGHT + 5; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 5; x++)
		{
			if (gameChatBoardInfo[y][x] == 1 || gameChatBoardInfo[y][x] == 2 || gameChatBoardInfo[y][x] == 3 || gameChatBoardInfo[y][x] == 4
				|| gameChatBoardInfo[y][x] == -1 || gameChatBoardInfo[y][x] == -2 || gameChatBoardInfo[y][x] == -4 ||
				gameChatBoardInfo[y][x] == -5 || gameChatBoardInfo[y][x] == -6 || gameChatBoardInfo[y][x] == -7 ||
				gameChatBoardInfo[y][x] == -8 || gameChatBoardInfo[y][x] == -9 || gameChatBoardInfo[y][x] == 0)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("��");
				RemoveCursor();
			}
		}
	}
}
void Redraw_Start2Blocks(void)
{
	int x, y;
	int color = 9;
	int cursX, cursY;
	for (y = 0; y < GBOARD_HEIGHT + 5; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 5; x++)
		{
			if (gameStartBoard_2Info[y][x] == 1 || gameStartBoard_2Info[y][x] == 2 || gameStartBoard_2Info[y][x] == 3 || gameStartBoard_2Info[y][x] == 0)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("��");
				RemoveCursor();
			}
		}
	}
}
void Redraw_Start3Blocks(void)
{
	int x, y;
	int color = 9;
	int cursX, cursY;
	for (y = 0; y < GBOARD_HEIGHT + 5; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 5; x++)
		{
			if (gameStartBoard_3Info[y][x] == 1 || gameStartBoard_3Info[y][x] == 0)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("��");
				RemoveCursor();
			}
		}
	}
}
void Redraw_NextBlocks(void)
{
	int x, y;
	int color = 9;
	int cursX, cursY;
	for (y = 0; y < GBOARD_HEIGHT + 5; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 5; x++)
		{
			if (nextStageBoardInfo[y][x] == 1 || nextStageBoardInfo[y][x] == 2 || nextStageBoardInfo[y][x] == 3 || nextStageBoardInfo[y][x] == 4
				|| nextStageBoardInfo[y][x] == 6 || nextStageBoardInfo[y][x] == 5 || nextStageBoardInfo[y][x] == 0)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("��");
				RemoveCursor();
			}
		}
	}
}
void Redraw_RankingBlocks(void)
{
	int x, y;
	int color = 9;
	int cursX, cursY;
	for (y = 0; y < GBOARD_HEIGHT + 5; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 5; x++)
		{
			if (gameRankingBoardInfo[y][x] == 1 || gameRankingBoardInfo[y][x] == 2 || gameRankingBoardInfo[y][x] == 3 || gameRankingBoardInfo[y][x] == 4
				|| gameRankingBoardInfo[y][x] == 0)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("��");
				RemoveCursor();
			}

		}
	}

}
void Redraw_Boards()
{
	switch (board_type)
	{
	case 0: Redraw_GameBlocks();
		break;
	case 1: Redraw_StartBlocks();
		break;
	case 2: Redraw_Start2Blocks();
		break;
	case 3: Redraw_Start3Blocks();
		break;
	case 4: Redraw_FinishBlocks();
		break;
	case 5: Redraw_SuccessBlocks();
		break;
	case 6: Redraw_ChatBlocks();
		break;
	case 7: Redraw_NextBlocks();
		break;
	case 8: Redraw_RankingBlocks();
		break;
	}

}
void DrawChatBoard() {

	int x;
	int z;
	board_type = 6;
	for (z = m; z <= 20; z++)
	{
		for (x = 1; x < GBOARD_CHAT_WIDTH; x++)
		{
			if (gameChatBoardInfo[z][x] != 1)
			{
				SetCurrentCursorPos((x * 2) + 72, z);
				printf("��");
				RemoveCursor();
			}
			RemoveCursor();
		}
		RemoveCursor();
	}
	RemoveCursor();

	m += 2;
}

void DrawGameFinishBoard() {
	int x, y, color = 9;
	board_type = 4;
	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 2; x++)
		{
			if (gameFinishBoardInfo[y][x] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				SetCurrentCursorPos(x * 2, y);

				printf("��");

			}
			else if (gameFinishBoardInfo[y][x] == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DARK_PURPLE);
				SetCurrentCursorPos(x * 2, y);

				printf("��");

			}
		}
	}
}

void DrawGameRankingBoard() {
	int x, y;
	board_type = 8;
	int i, j = 1;
	int max = 1000;
	int big_ind = 0;
	int px = 1;
	int ind[11];
	Rank ranking[8];
	int tmp;
	char tmp1[4] = { '\0' };

	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 2; x++)
		{
			if (gameRankingBoardInfo[y][x] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 255);
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
			if (gameRankingBoardInfo[y][x] == 2) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 102);
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
			if (gameRankingBoardInfo[y][x] == 3) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
			if (gameRankingBoardInfo[y][x] == 4) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}

	//rank[playcount].score = pay + Chae_close + Koo_close + bonus;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	SetCurrentCursorPos(57, 3);
	printf("��  ���� �� ���� �� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	SetCurrentCursorPos(57, 22);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 252);
	printf(" [ENTER] -> RESTART ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	for (i = 1; i < playcount; i++) {
		for (j = i + 1; j <= playcount; j++) {
			if (rank[i].score < rank[j].score) {
				tmp = rank[i].score;
				rank[i].score = rank[j].score;
				rank[j].score = tmp;
				strcpy(tmp1, rank[i].name);
				strcpy(rank[i].name, rank[j].name);
				strcpy(rank[j].name, tmp1);
				for (int i = 0; i < 4; i++) {
					tmp1[i] = NULL;
				}
			}
		}
	}

	for (int i = playcount; i >= 1; i--)
	{
		ranking[i].name[3] = '\0';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		SetCurrentCursorPos(53, 4 + 2 * i);
		printf("%d. %s  ", i, rank[i].name);
		SetCurrentCursorPos(63, 4 + 2 * i);
		printf("%d", rank[i].score);
		Sleep(1000);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	RemoveCursor();

	return;
}

void DrawGameSuccessBoard() {
	int x, y, color = 9;
	board_type = 5;

	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 2; x++)
		{

			if (gameSuccessBoardInfo[y][x] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				SetCurrentCursorPos(x * 2, y);
				printf("��");
				color++;
				if (color > 14)
					color = 9;
			}
			if (gameSuccessBoardInfo[y][x] == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
				SetCurrentCursorPos(x * 2, y);
				printf("��");

			}
			if (gameSuccessBoardInfo[y][x] == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PINK);
				SetCurrentCursorPos(x * 2, y);
				printf("��");

			}
			if (gameSuccessBoardInfo[y][x] == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
				SetCurrentCursorPos(x * 2, y);
				printf("��");

			}
			if (gameSuccessBoardInfo[y][x] == 5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
				SetCurrentCursorPos(x * 2, y);
				printf("��");

			}
		}
	}
}

void RemoveCursor(void)
{//Ŀ�� ������ ����
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void hpUpdate()
{
	int i = (int)duration / 10;
	if (i != tmp_HP)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DARK_RED);
		SetCurrentCursorPos(24 - (i * 2), 24);
		printf("��");
		tmp_HP = i;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}

}
int stageClear()
{
	if (duration >= 100 && pay < goal_pay)
		return -1;
	if (day == 5 && pay == goal_pay)
		return 1;
	else
		return 0;
}
void nextStage()
{
	int i;
	pay = goal_pay;
	goal_pay += 10;
	day++;
	duration = 0;
	tmp_HP = 0;
	mydeskCount = 0;
	stop_npc = 0;
	speedUp_npc = 0;
	stop_time_start = NULL;
	speedUp_time_start = NULL;

	n = 0;
	curPosY = 1;
	curPos_PC.X = pcPosX;
	curPos_PC.Y = pcPosY;
	curPos_NPC.X = npcPosX;
	curPos_NPC.Y = npcPosY;
	SetCurrentCursorPos(curPosX, curPosY);

	for (i = 0; i < 7; i++)
	{
		NPCerrand_occur[i] = 0;
	}

	Redraw_GameBlocks();
	nextStageBoard();

}
void nextStageBoard() {
	int x, y;
	board_type = 7;
	npc_color = GREEN;

	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		for (x = 0; x < GBOARD_WIDTH + 2; x++)
		{
			if (nextStageBoardInfo[y][x] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 143);
				SetCurrentCursorPos(x * 2, y);
				printf("��");
			}

			if (nextStageBoardInfo[y][x] == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW | (DARK_YEELOW << 4));
				SetCurrentCursorPos(x * 2, y);
				printf("��");

			}
			if (nextStageBoardInfo[y][x] == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 93);
				SetCurrentCursorPos(x * 2, y);
				printf("��");

			}
			if (nextStageBoardInfo[y][x] == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				SetCurrentCursorPos(x * 2, y);
				printf("��");

			}
			if (nextStageBoardInfo[y][x] == 5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				SetCurrentCursorPos(x * 2, y);
				printf("��");

			}
			if (nextStageBoardInfo[y][x] == 6)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				SetCurrentCursorPos(x * 2, y);
				printf("��");

			}

		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}
void payUpdate()
{
	SetCurrentCursorPos(14, 23);
	printf("���� %d���� / %d����(��ǥ����) ", pay, goal_pay);
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void Success() {
	int key;
	npc_color = GREEN;

	PlaySound(TEXT("SUCCESS.wav"), NULL, SND_ASYNC);

	Redraw_GameBlocks();
	DrawGameSuccessBoard();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	SetCurrentCursorPos(53, 6);
	printf("���ϵ帳�ϴ�!");
	SetCurrentCursorPos(46, 7);
	printf("���ϴ� 'Zoon ���ͳ��ų�'��");
	SetCurrentCursorPos(46, 8);
	printf("���������� ä��Ǽ̽��ϴ�!!");
	SetCurrentCursorPos(48, 10);
	printf("����  ����:    ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	printf("%d ", pay);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("����");
	SetCurrentCursorPos(48, 11);
	printf("���� ���ʽ�:  ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	printf("%.1f ", bonus);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("����");
	SetCurrentCursorPos(48, 12);
	printf("���� ģ�е�: ������ ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	printf("+%d", Koo_close);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	SetCurrentCursorPos(48, 13);
	printf("���� ģ�е�: ä�븮 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	printf("+%d", Chae_close);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	SetCurrentCursorPos(50, 18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	printf("[ENTER] -> RANKING");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}
void Fail() {
	int key;
	npc_color = GREEN;

	//Redraw_Boards();
	Redraw_GameBlocks();
	DrawGameFinishBoard();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	if (npc_fail == -1)
	{
		PlaySound(TEXT("GAME_OVER.wav"), NULL, SND_ASYNC);
		SetCurrentCursorPos(51, 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf("[ENTER] -> RANKING");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		SetCurrentCursorPos(51, 4);
		printf("����� ���� �����");
		SetCurrentCursorPos(50, 5);
		printf("ġ�ٴ��Ÿ��� �� �̰�");
		SetCurrentCursorPos(49, 6);
		printf("ȸ�縦 ��� �Ͽ����ϴ�.");
		SetCurrentCursorPos(49, 8);
		printf("����   ����: ����");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf(" %d ", day);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("����");
		SetCurrentCursorPos(49, 9);
		printf("����   ����:     ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf("%d ", pay);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("����");
		SetCurrentCursorPos(49, 10);
		printf("���� ���ʽ�:   ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf("%.1f ", bonus);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("����");
		SetCurrentCursorPos(49, 11);
		printf("���� ģ�е�:  ������ ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf("+%d", Koo_close);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		SetCurrentCursorPos(49, 12);
		printf("���� ģ�е�:  ä�븮 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf("+%d", Chae_close);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		return;
	}
	else
	{
		PlaySound(TEXT("GAME_OVER.wav"), NULL, SND_ASYNC);
		SetCurrentCursorPos(50, 2);
		printf("RANKING -> [ENTER]");
		SetCurrentCursorPos(49, 4);
		printf("������ �پ ��������");
		SetCurrentCursorPos(47, 5);
		printf("�ұ��ϰ� �ݹ� ä�뿡�� �Բ�");
		SetCurrentCursorPos(49, 6);
		printf("�� �� ���� �Ǿ����ϴ�.");
		SetCurrentCursorPos(50, 8);
		printf("����   ����: ���� ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf("%d ", day);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("����");
		SetCurrentCursorPos(50, 9);
		printf("����   ����:     ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf("%d ", pay);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("����");
		SetCurrentCursorPos(50, 10);
		printf("���� ���ʽ�:   ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf("%.1f ", bonus);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("����");
		SetCurrentCursorPos(50, 11);
		printf("���� ģ�е�: ������ ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf("+%d", Koo_close);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		SetCurrentCursorPos(50, 12);
		printf("���� ģ�е�: ä�븮 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf("+%d", Chae_close);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		return;
	}
}
int doMyWork()
{
	int key;
	int clear = 0;

	for (int i = 0; i < 100; i++)
	{
		now = clock();
		duration = (double)(now - start) / (CLOCKS_PER_SEC);
		hpUpdate();
		NPC_TimeLimit();
		if (i%difficulty == 0)
			followNPC();
		if (_kbhit() != 0)
		{
			key = _getch();
			switch (key)
			{
			case 'o':
				if (clear == 0 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -1)
				{
					clear++;
					myDeskUpdate(1);
				}
				else
					return 0;

				break;
			case 'r':
				if (clear == 1 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -1)
				{
					clear++;
					myDeskUpdate(2);
				}
				else
					return 0;

				break;
			case 'k':
				if (clear == 2 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -1)
				{
					clear++;
					myDeskUpdate(3);
					clear = 0;
					if (stageClear() == 1)
						return 2;
					return 1;
				}
				else
					return 0;

				break;

			default:
				clear = 0;
				return -1;
				break;
			}
		}
		Sleep(50);
	}

}
void myDeskUpdate(int clear)
{
	SetCurrentCursorPos(8, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	switch (clear)
	{
	case 0:
		printf("W ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 1:
		printf("W O ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 2:
		printf("W O R ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 3:
		printf("W O R K");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		Sleep(100);
		SetCurrentCursorPos(8, 5);
		printf("W O R K");
		break;
	default:
		break;
	}
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}

// ������ ����
void toNPC1(int passTo) {

	if (passTo == 1 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -8)
	{
		switch (selected) {
		case 0:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			SetCurrentCursorPos(6, 17);
			printf("M A K E");
			madeCoffee = 2;
			canInput = 1;
			break;

		case 3:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			SetCurrentCursorPos(58, 18);
			printf("P R I N T");
			printed = 2;
			canInput = 1;
			break;

		default:
			break;
		}
		// NPC1���� �������ַ��� �߿� �ð� �� �Ǹ� make, print�۾� ������� �ϱ�
		SetCurrentCursorPos(59, 7);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf("  CLEAR  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

		SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
	}

}

// Ŀ��
void NPC1_coffee_errand() {

	if (gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -2)
	{
		if (NPC_duration[0] > 15) {
			return;
		}
		coffeeUpdate(0);

		madeCoffee = makeCoffee();
		if (madeCoffee == 1)
		{
			canInput = 0;
			passTo = 1;
			// �� �Է��ϸ�
			return;
		}
		if (madeCoffee == -1)
		{
			// �ٸ� Ű �Է��ϸ� ���� �Է��ϰ�
			canInput = 1;
			SetCurrentCursorPos(6, 17);
			printf("M A K E");
			return;
		}

	}
}
int makeCoffee()
{
	int key;
	int clear = 0;

	for (int i = 0; i < 100; i++)
	{
		now = clock();
		duration = (double)(now - start) / (CLOCKS_PER_SEC);
		hpUpdate();
		NPC_TimeLimit();

		if (_kbhit() != 0)
		{
			key = _getch();
			switch (key)
			{
			case 'a':
				if (clear == 0 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -2)
				{
					clear++;
					coffeeUpdate(1);
				}
				else
					return 0;

				break;
			case 'k':
				if (clear == 1 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -2)
				{
					clear++;
					coffeeUpdate(2);
				}
				else
					return 0;
				break;
			case 'e':
				if (clear == 2 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -2)
				{
					clear++;
					coffeeUpdate(3);
					clear = 0;
					return 1;
				}
				else
					return 0;
				break;
			default:
				clear = 0;
				return -1;
				break;
			}
		}

		Sleep(50);
	}
}
void coffeeUpdate(int clear)
{
	SetCurrentCursorPos(6, 17);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	switch (clear)
	{
	case 0:
		printf("M ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 1:
		printf("M A ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 2:
		printf("M A K ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 3:
		printf("M A K E");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	default:
		break;
	}
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}

// �ѽ�
void NPC1_fax_errand() {

	if (gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4)
	{
		if (selected == 1 && NPC_duration[1] > 15) {
			return;
		}
		if (selected == 4 && NPC_duration[4] > 15) {
			return;
		}
		faxUpdate(-2);

		phoneCalled = phoneCall();
		if (FaxAfterPrint == 1 && phoneCalled == 1) {
			// �μ� �� �ѽ������� 2�ܰ� ����
			canInput = -1;   // �ѽ���ȣ �ٽ� �Է� ���ް�
			FaxAfterPrint = 2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			SetCurrentCursorPos(58, 18);
			printf("P R I N T");
		}

		if (phoneCalled == 1) {
			// �ѽ� �ɺθ� ����
			canInput = -1;   // �ٽ� �Է� ���ް�
			removeFaxNumber();
			SetCurrentCursorPos(33, 11);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf("CLEAR");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		if (phoneCalled == -1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			SetCurrentCursorPos(32, 11);
			printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
			SetCurrentCursorPos(34, 12);
			printf("%d%d%d%d", num[4], num[5], num[6], num[7]);
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return;
		}

	}

}
int phoneCall()
{
	int key;
	int clear = -1;

	switch (clear)
	{
	case -1:
		for (int i = 0; i<30; i++)
		{
			now = clock();
			duration = (double)(now - start) / (CLOCKS_PER_SEC);
			hpUpdate();
			NPC_TimeLimit();
			if (npc_fail == -1)
			{
				Fail();
				break;
			}
			if (_kbhit() != 0)
			{
				key = _getch();

				if (key == '2' && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear++;
					faxUpdate(-1);
					break;
				}
				else if (clear == -1 && key != '2' && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear = -1;
					return -1;
				}
			}
			if (detectCatch() == -1)
			{
				npc_fail = -1;
				//break;
				return 0;
			}
			Sleep(50);
		}

	case 0:
		for (int i = 0; i<30; i++)
		{
			now = clock();
			duration = (double)(now - start) / (CLOCKS_PER_SEC);
			hpUpdate();
			NPC_TimeLimit();
			if (i%difficulty == 0)
			{
				npc_fail = followNPC();
			}
			if (npc_fail == -1)
			{
				Fail();
				break;
			}
			if (_kbhit() != 0)
			{
				key = _getch();

				if (key == num[0] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear++;
					faxUpdate(0);
					break;
				}
				else if (clear == 0 && key != num[0] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear = -1;
					return -1;
				}
			}
			if (detectCatch() == -1)
			{
				npc_fail = -1;
				//break;
				return 0;
			}
			Sleep(50);
		}

	case 1:
		for (int i = 0; i<30; i++)
		{
			now = clock();
			duration = (double)(now - start) / (CLOCKS_PER_SEC);
			hpUpdate();
			NPC_TimeLimit();
			if (npc_fail == -1)
			{
				Fail();
				break;
			}
			if (_kbhit() != 0)
			{
				key = _getch();

				if (key == num[1] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear++;
					faxUpdate(1);
					break;
				}
				else if (clear == 1 && key != num[1] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear = -1;
					return -1;
				}
			}
			if (detectCatch() == -1)
			{
				npc_fail = -1;
				//break;
				return 0;
			}
			Sleep(50);
		}

	case 2:
		for (int i = 0; i<30; i++)
		{
			now = clock();
			duration = (double)(now - start) / (CLOCKS_PER_SEC);
			hpUpdate();
			NPC_TimeLimit();
			if (i%difficulty == 0)
			{
				npc_fail = followNPC();
			}
			if (npc_fail == -1)
			{
				Fail();
				break;
			}
			if (_kbhit() != 0)
			{
				key = _getch();

				if (key == num[2] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear++;
					faxUpdate(2);
					break;
				}
				else if (clear == 2 && key != num[2] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear = -1;
					return -1;
				}
			}
			if (detectCatch() == -1)
			{
				npc_fail = -1;
				//break;
				return 0;
			}
			Sleep(50);
		}

	case 3:
		for (int i = 0; i<30; i++)
		{
			now = clock();
			duration = (double)(now - start) / (CLOCKS_PER_SEC);
			hpUpdate();
			NPC_TimeLimit();
			if (npc_fail == -1)
			{
				Fail();
				break;
			}
			if (_kbhit() != 0)
			{
				key = _getch();

				if (key == num[3] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear++;
					faxUpdate(3);
					break;
				}
				else if (clear == 3 && key != num[3] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear = -1;
					return -1;
				}
			}
			if (detectCatch() == -1)
			{
				npc_fail = -1;
				//break;
				return 0;
			}
			Sleep(50);
		}

	case 4:
		for (int i = 0; i<30; i++)
		{
			now = clock();
			duration = (double)(now - start) / (CLOCKS_PER_SEC);
			hpUpdate();
			NPC_TimeLimit();
			if (i%difficulty == 0)
			{
				npc_fail = followNPC();
			}
			if (npc_fail == -1)
			{
				Fail();
				break;
			}
			if (_kbhit() != 0)
			{
				key = _getch();

				if (key == num[4] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear++;
					faxUpdate(4);
					break;
				}
				else if (clear == 4 && key != num[4] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear = -1;
					return -1;
				}
			}
			if (detectCatch() == -1)
			{
				npc_fail = -1;
				//break;
				return 0;
			}
			Sleep(50);
		}

	case 5:
		for (int i = 0; i<30; i++)
		{
			now = clock();
			duration = (double)(now - start) / (CLOCKS_PER_SEC);
			hpUpdate();
			NPC_TimeLimit();
			if (npc_fail == -1)
			{
				Fail();
				break;
			}
			if (_kbhit() != 0)
			{
				key = _getch();

				if (key == num[5] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear++;
					faxUpdate(5);
					break;
				}
				else if (clear == 5 && key != num[5] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear = -1;
					return -1;
				}
			}
			if (detectCatch() == -1)
			{
				npc_fail = -1;
				//break;
				return 0;
			}
			Sleep(50);
		}

	case 6:
		for (int i = 0; i<30; i++)
		{
			now = clock();
			duration = (double)(now - start) / (CLOCKS_PER_SEC);
			hpUpdate();
			NPC_TimeLimit();
			if (i%difficulty == 0)
			{
				npc_fail = followNPC();
			}
			if (npc_fail == -1)
			{
				Fail();
				break;
			}
			if (_kbhit() != 0)
			{
				key = _getch();

				if (key == num[6] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear++;
					faxUpdate(6);
					break;
				}
				else if (clear == 6 && key != num[6] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear = -1;
					return -1;
				}
			}
			if (detectCatch() == -1)
			{
				npc_fail = -1;
				//break;
				return 0;
			}
			Sleep(50);
		}

	case 7:
		for (int i = 0; i<30; i++)
		{
			now = clock();
			duration = (double)(now - start) / (CLOCKS_PER_SEC);
			hpUpdate();
			NPC_TimeLimit();
			if (npc_fail == -1)
			{
				Fail();
				break;
			}
			if (_kbhit() != 0)
			{
				key = _getch();

				if (key == num[7] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear++;
					faxUpdate(7);
					clear = -1;
					return 1;
				}
				else if (clear == 7 && key != num[7] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
					clear = -1;
					return -1;
				}

			}
			if (detectCatch() == -1)
			{
				npc_fail = -1;
				//break;
				return 0;
			}
			Sleep(50);
		}
		break;
	}

}
void faxUpdate(int clear)
{
	SetCurrentCursorPos(32, 11);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	switch (clear)
	{
	case -2:
		printf("0");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case -1:
		printf("02-");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 0:
		printf("02-%d", num[0]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 1:
		printf("02-%d%d", num[0], num[1]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 2:
		printf("02-%d%d%d", num[0], num[1], num[2]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 3:
		printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 4:
		printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
		SetCurrentCursorPos(34, 12);
		printf("%d", num[4]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 5:
		printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
		SetCurrentCursorPos(34, 12);
		printf("%d%d", num[4], num[5]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 6:
		printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
		SetCurrentCursorPos(34, 12);
		printf("%d%d%d", num[4], num[5], num[6]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 7:
		printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
		SetCurrentCursorPos(34, 12);
		printf("%d%d%d%d", num[4], num[5], num[6], num[7]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		Sleep(100);
		SetCurrentCursorPos(32, 11);
		printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
		SetCurrentCursorPos(34, 12);
		printf("%d%d%d%d", num[4], num[5], num[6], num[7]);
		break;
	default:
		break;
	}
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void faxNumber() {
	srand((unsigned)time(NULL));
	for (int i = 0; i<8; i++)
		num[i] = rand() % 9;

	SetCurrentCursorPos(32, 11);
	printf("02-");
	for (int i = 0; i<4; i++) {
		printf("%d", num[i]);
	}

	printf("-");
	SetCurrentCursorPos(34, 12);
	for (int i = 4; i<8; i++) {
		printf("%d", num[i]);
	}
}

// ����Ʈ
void NPC1_print_errand() {
	if (gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -3)
	{
		if (selected == 3 && NPC_duration[3] > 15) {
			return;
		}
		if (selected == 4 && NPC_duration[4] > 15) {
			return;
		}
		printUpdate(0);

		printed = printing();
		if (printed == 1)
		{
			canInput = 0;
			if (selected == 3)
				passTo = 1;
			if (selected == 4)
				FaxAfterPrint = 1;
			// �μ��� �ѽ������� �� 1�ܰ� �μ� ����
			return;
		}
		if (printed == -1)
		{
			canInput = 1;
			SetCurrentCursorPos(58, 18);
			printf("P R I N T");
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return;
		}
	}

}
int printing() {
	int key;
	int clear = 0;

	for (int i = 0; i < 100; i++)
	{
		now = clock();
		duration = (double)(now - start) / (CLOCKS_PER_SEC);
		hpUpdate();
		NPC_TimeLimit();
		if (_kbhit() != 0)
		{
			key = _getch();
			switch (key)
			{
			case 'r':
				if (clear == 0 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -3)
				{
					clear++;
					printUpdate(1);
				}
				else
					return 0;

				break;
			case 'i':
				if (clear == 1 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -3)
				{
					clear++;
					printUpdate(2);
				}
				else
					return 0;
				break;
			case 'n':
				if (clear == 2 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -3)
				{
					clear++;
					printUpdate(3);
				}
				else
					return 0;
				break;
			case 't':
				if (clear == 3 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -3)
				{
					clear++;
					printUpdate(4);
					clear = 0;
					return 1;
				}
				else
					return 0;
				break;
			default:
				clear = 0;
				return -1;
				break;
				// -1 : �ٽ� �Է��ϰ��ϱ�
			}
		}
		Sleep(50);
	}
}
void printUpdate(int clear) {
	SetCurrentCursorPos(58, 18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	switch (clear)
	{
	case 0:
		printf("P ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 1:
		printf("P R ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 2:
		printf("P R I ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 3:
		printf("P R I N");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 4:
		printf("P R I N T");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	default:
		break;
	}
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}

// �μ��ϰ� �ѽ� ������
void fax_after_print() {
	// �μ��ϰ�
	NPC1_print_errand();
	// �ѽ�
	if (FaxAfterPrint == 1) {
		faxNumber();
	}
}

// ������
void Koo_work_errand() {
	if (gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
	{
		if (NPC_duration[5] > 15) {
			return;
		}
		kooUpdate(0);

		kooWorked = kooWorking();
		if (kooWorked == 1) {
			canInput = -1;
			SetCurrentCursorPos(37, 19);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf("  CLEAR  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			// ����
			return;
		}
		if (kooWorked == -1) {
			canInput = 1;
			SetCurrentCursorPos(37, 19);
			printf("KOO WORK");
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return;
		}
	}
}
int kooWorking() {
	int key;
	int clear = 0;

	for (int i = 0; i < 100; i++)
	{
		now = clock();
		duration = (double)(now - start) / (CLOCKS_PER_SEC);
		hpUpdate();
		NPC_TimeLimit();
		if (_kbhit() != 0)
		{
			key = _getch();
			switch (key)
			{
			case 'o':
				if (clear == 0 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
				{
					clear++;
					kooUpdate(1);
				}
				else if (clear == 1 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
				{
					clear++;
					kooUpdate(2);
				}
				else if (clear == 3 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
				{
					clear++;
					kooUpdate(4);
				}
				else
					return 0;
				break;
			case 'w':
				if (clear == 2 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
				{
					clear++;
					kooUpdate(3);
				}
				else
					return 0;
				break;
			case 'r':
				if (clear == 4 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
				{
					clear++;
					kooUpdate(5);
				}
				else
					return 0;
				break;
			case 'k':
				if (clear == 5 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
				{
					clear++;
					kooUpdate(6);
					clear = 0;
					return 1;
				}
				else
					return 0;
				break;
			default:
				clear = 0;
				return -1;
				break;
			}
		}
		Sleep(50);
	}
}
void kooUpdate(int clear) {
	SetCurrentCursorPos(37, 19);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	switch (clear)
	{
	case 0:
		printf("K");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 1:
		printf("KO");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 2:
		printf("KOO");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 3:
		printf("KOO W");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 4:
		printf("KOO WO");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 5:
		printf("KOO WOR");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 6:
		printf("KOO WORK");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	default:
		break;
	}
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}

// ä�븮
void Chae_work_errand() {
	if (gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
	{
		if (NPC_duration[6] > 15) {
			return;
		}
		chaeUpdate(0);

		chaeWorked = chaeWorking();
		if (chaeWorked == 1) {
			canInput = -1;
			SetCurrentCursorPos(24, 19);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf("  CLEAR  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			// ����
			return;
		}
		if (chaeWorked == -1) {
			canInput = 1;
			SetCurrentCursorPos(24, 19);
			printf("CHAE WORK");
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return;
		}
	}
}
int chaeWorking() {
	int key;
	int clear = 0;

	for (int i = 0; i < 100; i++)
	{
		now = clock();
		duration = (double)(now - start) / (CLOCKS_PER_SEC);
		hpUpdate();
		NPC_TimeLimit();
		if (_kbhit() != 0)
		{
			key = _getch();
			switch (key)
			{
			case 'h':
				if (clear == 0 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
				{
					clear++;
					chaeUpdate(1);
				}
				else
					return 0;

				break;
			case 'a':
				if (clear == 1 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
				{
					clear++;
					chaeUpdate(2);
				}
				else
					return 0;
				break;
			case 'e':
				if (clear == 2 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
				{
					clear++;
					chaeUpdate(3);
				}
				else
					return 0;
				break;
			case 'w':
				if (clear == 3 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
				{
					clear++;
					chaeUpdate(4);
				}
				else
					return 0;
				break;
			case 'o':
				if (clear == 4 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
				{
					clear++;
					chaeUpdate(5);
				}
				else
					return 0;
				break;
			case 'r':
				if (clear == 5 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
				{
					clear++;
					chaeUpdate(6);
				}
				else
					return 0;
				break;
			case 'k':
				if (clear == 6 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
				{
					clear++;
					chaeUpdate(7);
					clear = 0;
					return 1;
				}
				else
					return 0;
				break;
			default:
				clear = 0;
				return -1;
				break;
			}
		}
		Sleep(50);
	}
}
void chaeUpdate(int clear) {
	SetCurrentCursorPos(24, 19);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	switch (clear)
	{
	case 0:
		printf("C");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 1:
		printf("CH");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 2:
		printf("CHA");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 3:
		printf("CHAE");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 4:
		printf("CHAE W");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 5:
		printf("CHAE WO");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 6:
		printf("CHAE WOR");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	case 7:
		printf("CHAE WORK");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		break;
	default:
		break;
	}
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}

// ������
void pickUpTrash(int posX, int posY)
{
	int x = posX / 2;
	int y = posY;

	if (gameBoardInfo[y][x] == -5)
	{
		trash++;
		gameBoardInfo[y][x] = -10; // �� ��ġ�� �ִ� ������ �����
		SetCurrentCursorPos(37, 3);
		printf("%d / 6", trash);

		if (trash >= 6) {
			SetCurrentCursorPos(37, 3);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf("CLEAR");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
			return;
		}
	}

	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void dumpTrash() {

	for (int y = 0; y <= GBOARD_HEIGHT; y++) {
		for (int x = 0; x < GBOARD_WIDTH + 2; x++)
		{
			if (gameBoardInfo[y][x] == -10) {
				gameBoardInfo[y][x] = -5;
			}

			if (gameBoardInfo[y][x] == -5)
			{
				SetCurrentCursorPos(x * 2, y);
				printf("@");
			}

		}
	}
}
void drawTrash(int posX, int posY) {
	int x = posX / 2;
	int y = posY;

	if (gameBoardInfo[y][x] == -5) {
		SetCurrentCursorPos(x * 2, y);
		printf("@");
	}
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}

// �ʱ�ȭ
void initializedCoffee() {
	SetCurrentCursorPos(6, 17);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("M A K E");
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void initializedPrint() {
	SetCurrentCursorPos(58, 18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("P R I N T");
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void initializedKoo() {
	SetCurrentCursorPos(37, 19);
	printf("KOO WORK");
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void initializedChae() {
	SetCurrentCursorPos(24, 19);
	printf("CHAE WORK ");
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void initializedOh() {
	SetCurrentCursorPos(59, 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("[ SPACE ]");
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void removeTrash() {
	trash = 0;
	SetCurrentCursorPos(37, 3);
	printf("     ");

	for (int y = 0; y <= GBOARD_HEIGHT; y++) {
		for (int x = 0; x < GBOARD_WIDTH + 2; x++)
		{
			if (gameBoardInfo[y][x] == -5)
			{
				SetCurrentCursorPos(x * 2, y);
				printf(" ");
			}

		}
	}
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void removeFaxNumber() {
	SetCurrentCursorPos(32, 11);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("        ");
	SetCurrentCursorPos(34, 12);
	printf("    ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}
void npcSpeedUp()
{
	if (stop_npc == 1)  // ���� ���¿��� ���ǵ���� ����� ��� �ߺ���� x
	{
		stop_time_start = NULL;
		stop_npc = 0;
	}
	if (speedUp_npc == 1) // �̹� ���ǵ� �� ���°� �������̾����� �ʱ�ȭ �� �ð� �ٽý���
	{
		speedUp_time_start = NULL;
	}
	speedUp_npc = 1;
	difficulty = 6;
	npc_color = RED;
	speedUp_time_start = clock();

}
void npcStop()
{
	if (speedUp_npc == 1)
	{
		speedUp_time_start = NULL;
		speedUp_npc = 0;
		difficulty = 20;
	}
	if (stop_npc == 1) // �̹� ������ �������̾����� �ʱ�ȭ �� �ð� �ٽý���
	{
		stop_time_start = NULL;
	}
	stop_npc = 1;
	stop_time_start = clock();
	/* npc �������� ���� �Ķ������� �Ͽ� ������������ �ð������� ������ */
	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
	printf("��");
	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
}