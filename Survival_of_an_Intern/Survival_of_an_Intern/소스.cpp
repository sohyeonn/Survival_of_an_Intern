//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<conio.h>
//#include<windows.h>
//#include<time.h>
//#include "errand.h"
//#include "GameBoard.h"
//#pragma warning( disable: 4996 )
//
///* �÷� ���� */
//#define BLUE 9
//#define GREEN 10
//#define SKY 11
//#define RED 12
//#define PINK 13
//#define YELLOW 14
//#define WHITE 15
//#define DARK_RED 4
//#define DARK_YEELOW 6
//#define DARK_PURPLE 5
//#define RED 12
//
///* �ƽ�Ű�ڵ尪 ���� */
//#define LEFT 75
//#define RIGHT 77
//#define UP 72
//#define DOWN 80
//#define SPACE 32
//#define ENTER 13
//
///*
//0 ~ 9
//: 48 ~ 57
//*/
//
///* pc�ʱ� ��ǥ �� ���� */
//#define pcPosX 2
//#define pcPosY 8
//#define npcPosX 68
//#define npcPosY 11
//
//int curPosX = 0, curPosY = 1;
//int flag = 0, selected = -1;
//int num[8];
//int n;
//
//int pcSpeed = 30;
//int day = 1; // ����
//int pay = 0; // ���� ���� ����
//int goal_pay = 10; //�ʱ� ��ǥ ���� ��
//int HP = 10;
//int tmp_HP = 0;
//int mydeskCount = 0;
//int recyclebin = 0;
//float bonus = 0;
//int Oh_close = 0; // ģ�е�
//int Koo_close = 0;
//int Chae_close = 0;
//int madeCoffee = 0;
//int phoneCalled = 0;
//int printed = 0;
//int chaeWorked = 0;
//int kooWorked = 0;
//int trash = 0;
//int difficulty = 10;
//
//COORD curPos_PC = { pcPosX,pcPosY }; // pc�� ��ǥ
//COORD curPos_NPC = { npcPosX,npcPosY };
//clock_t start, now;
//double duration = 0;
//
///*               ���� ����� ��               */
//
//void SetCurrentCursorPos(int x, int y);
//int NPCerrandSelect();
//void NPCerrandPrint();
//int NPC_TimeLimit();
//COORD GetCurrentCursorPos();
//void DrawGameBoard(void);
//void show_PC();
//void delete_PC();
//void shiftRight_PC();
//void shiftLeft_PC();
//void shiftUp_PC();
//void shiftDown_PC();
//void processKeyinput_PC();
//int detectCollision(int posX, int posY);
//void show_NPC();
//void delete_NPC();
//void shiftRight_NPC();
//void shiftLeft_NPC();
//void shiftDown_NPC();
//void shiftUp_NPC();
//void followNPC();
//void hpUp();
//void hpDown();
//void Bonus();
//void payDown();
//void payUp();
//void Oh_closeness();
//void Koo_closeness();
//void Chae_closeness();
//void DrawGameStartBoard();
//void DrawChatBoard();
//void DrawGameFinishBoard();
//void RedrawBlocks(void);
//void RemoveCursor(void);
//int stageClear();
//void nextStage();
//void hpUpdate();
//void payUpdate();
//void Success();
//void Fail();
//int doMyWork();
//void myDeskUpdate(int i);
//
//void callErrand(int num);
//
///*               �ɺθ� �Լ�               */
//
//void initializedCoffee();
//void initializedPrint();
//void initializedChae();
//void initializedKoo();
//void initializedOh();
//void removeFaxNumber();
//void removeTrash();
//
//void NPC1_coffee_errand();
//void coffeeUpdate(int clear);
//int makeCoffee();
//
//void NPC1_print_errand();
//void printUpdate(int clear);
//int printing();
//
//void NPC1_fax_errand();
//void faxUpdate(int clear);
//int phoneCall();
//void faxNumber();
//
//void pickUpTrash(int posX, int posY);
//void dumpTrash();
//
//void Chae_work_errand();
//int chaeWorking();
//void chaeUpdate(int clear);
//
//void Koo_work_errand();
//int kooWorking();
//void kooUpdate(int clear);
//
//void fax_after_print();
//void toNPC1(int flag, int time);
//
///*                    �Լ� ����γ�                     */
//
//void main()
//{
//	system("mode con:cols=134 lines=27");
//	int st = 1, z;
//	char s[6] = { NULL };
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE); //�ܼ� �۾��� �������
//	while (st != 0)
//	{
//		DrawGameStartBoard();
//		RemoveCursor();
//		for (int i = 0; i < 10; i++) {
//			SetCurrentCursorPos(0, 0);
//			if (_kbhit() != 0) {
//				z = _getch();
//			}
//			if (z == ENTER) {
//				st = 0;
//				break;
//			}
//		}
//
//	}
//	RedrawBlocks();
//	DrawGameBoard();
//
//	while (stageClear() == 0)
//	{
//
//		SetCurrentCursorPos(0, 23);
//		printf("���� %d����    ���� %d����/ %d����(��ǥ����)\n", day, pay, goal_pay);
//		printf("ü��");
//		for (int i = HP; i > 0; i--)
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
//			printf("��");
//		}
//		printf(" ");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//
//		SetCurrentCursorPos(pcPosX, pcPosY);
//		show_PC();
//		SetCurrentCursorPos(npcPosX, npcPosY);
//		show_NPC();
//		start = clock();
//		duration = 0;
//		while (duration < 100 || pay <= goal_pay)
//		{
//			switch (day)
//			{
//			case 1:
//				if (n % 25 == 0)//4��
//				{
//					NPCerrandPrint();
//				}
//				break;
//			case 2:
//				if (n % 25 == 0)//4��
//				{
//					NPCerrandPrint();
//				}
//				break;
//			case 3:
//				if (n % 20 == 0)//5��
//				{
//					NPCerrandPrint();
//				}
//				break;
//			case 4:
//				if (n % 20 == 0)//5��
//				{
//					NPCerrandPrint();
//				}
//				break;
//			case 5:
//				if (n % 15 == 0)//6��
//				{
//					NPCerrandPrint();
//				}
//				break;
//			}
//			now = clock();
//			NPC_TimeLimit();
//			duration = (double)(now - start) / (CLOCKS_PER_SEC);
//			hpUpdate();
//			payUpdate();
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			processKeyinput_PC();
//			if (pay >= goal_pay)
//				break;
//			if (duration > 100)
//				break;
//			n++;
//		}
//		if (duration >= 100) {
//			Fail();
//			break;
//		}
//		if (stageClear() == 1 && day == 5)
//		{
//			Success();
//			break;
//		}
//		else
//		{
//			nextStage();
//		}
//	}
//	getchar();
//
//}
//
//void SetCurrentCursorPos(int x, int y)
//{
//	COORD pos = { x, y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//int NPCerrandSelect()
//{
//	int num;
//	srand((unsigned)time(NULL));
//	switch (day)
//	{
//	case 1:
//		num = rand() % 4;
//		break;
//	case 2:
//		num = rand() % 5;
//		break;
//	case 3:
//		num = rand() % 6;
//		break;
//	case 4:
//		num = rand() % 7;
//		break;
//	case 5:
//		num = rand() % 7;
//		break;
//	}
//	return num;
//}
//void callErrand(int num) {
//	switch (num) {
//	case 0:
//		initializedOh();
//		initializedCoffee();
//		selected = 0;      // coffee     
//		initializedPrint();
//		initializedChae();
//		initializedKoo();
//		removeFaxNumber();
//		removeTrash();
//		break;
//	case 1:
//		removeFaxNumber();
//		selected = 1;      // fax
//		faxNumber();
//		initializedCoffee();
//		initializedPrint();
//		initializedChae();
//		initializedKoo();
//		initializedOh();
//		removeTrash();
//		break;
//	case 2:
//		selected = 2;      // trash
//		dumpTrash();
//		SetCurrentCursorPos(37, 3);
//		printf("0 / 6");
//		initializedCoffee();
//		initializedPrint();
//		initializedChae();
//		initializedKoo();
//		initializedOh();
//		removeFaxNumber();
//		break;
//	case 3:
//		initializedOh();
//		initializedPrint();
//		selected = 3;      // print
//		initializedCoffee();
//		initializedChae();
//		initializedKoo();
//		removeFaxNumber();
//		removeTrash();
//		break;
//	case 4:
//		removeFaxNumber();
//		selected = 4;      // fax print
//		initializedCoffee();
//		initializedPrint();
//		initializedChae();
//		initializedKoo();
//		initializedOh();
//		removeTrash();
//		break;
//	case 5:
//		initializedKoo();
//		selected = 5;      // koo
//		SetCurrentCursorPos(37, 19);
//		printf("KOO WORK");
//		initializedCoffee();
//		initializedPrint();
//		initializedChae();
//		initializedOh();
//		removeFaxNumber();
//		removeTrash();
//		break;
//	case 6:
//		initializedChae();
//		selected = 6;      // chae
//		SetCurrentCursorPos(24, 19);
//		printf("CHAE WORK");
//		initializedCoffee();
//		initializedPrint();
//		initializedKoo();
//		initializedOh();
//		removeFaxNumber();
//		removeTrash();
//		break;
//	default:
//		break;
//	}
//}
//
//void NPCerrandPrint()
//{
//	int num;
//	num = NPCerrandSelect();
//	curPosY++;
//	if (n == 0)
//		curPosY--;
//	SetCurrentCursorPos(74, curPosY);
//	printf("%s\n", NPCerrandType[num]);
//	NPC_start[num] = clock();//NPC �ð� ���� ����   
//
//	NPCerrand_occur[num] = 1;
//	curPosY++;
//
//	callErrand(num);
//}
//int NPC_TimeLimit()
//{
//
//	if (NPCerrand_occur[0] == 1)//Ŀ��
//	{
//		NPC_duration[0] = (double)(now - NPC_start[0]) / (CLOCKS_PER_SEC);
//		if (NPC_duration[0] > 15)
//		{
//			NPCerrand_occur[0] = 0;
//			hpDown();
//			//DrawChatBoard();
//
//			curPosY--;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff_e[0]);
//			curPosY++;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff[0]);
//
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 0;
//			//��� ����
//		}
//		else
//		{
//			SetCurrentCursorPos(74, curPosY);
//			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[0]);
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 1;
//
//		}
//	}
//	if (NPCerrand_occur[1] == 1)//�ѽ�
//	{
//		NPC_duration[1] = (double)(now - NPC_start[1]) / (CLOCKS_PER_SEC);
//		if (NPC_duration[1] > 15)
//		{
//			NPCerrand_occur[1] = 0;
//			hpDown();
//			//DrawChatBoard();
//
//			curPosY--;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff_e[1]);
//			curPosY++;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff[1]);
//
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 0;
//			//��� ����
//		}
//		else
//		{
//			SetCurrentCursorPos(74, curPosY);
//			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[1]);
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 1;
//		}
//	}
//	if (NPCerrand_occur[2] == 1)//������
//	{
//		NPC_duration[2] = (double)(now - NPC_start[2]) / (CLOCKS_PER_SEC);
//		if (NPC_duration[2] > 15)
//		{
//			NPCerrand_occur[2] = 0;
//			hpDown();
//			//DrawChatBoard();
//
//			curPosY--;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff_e[2]);
//			curPosY++;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff[2]);
//
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 0;
//			//��� ����
//		}
//		else
//		{
//			SetCurrentCursorPos(74, curPosY);
//			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[2]);
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 1;
//		}
//	}
//	if (NPCerrand_occur[3] == 1)//�μ��
//	{
//		NPC_duration[3] = (double)(now - NPC_start[3]) / (CLOCKS_PER_SEC);
//		if (NPC_duration[3]> 15)
//		{
//			NPCerrand_occur[3] = 0;
//			hpDown();
//			//DrawChatBoard();
//
//			curPosY--;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff_e[3]);
//			curPosY++;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff[3]);
//
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 0;
//			//��� ����
//		}
//		else
//		{
//			SetCurrentCursorPos(74, curPosY);
//			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[3]);
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 1;
//		}
//	}
//	if (NPCerrand_occur[4] == 1)//�ѽ�-�μ�
//	{
//		NPC_duration[4] = (double)(now - NPC_start[4]) / (CLOCKS_PER_SEC);
//		if (NPC_duration[4]> 15)
//		{
//			NPCerrand_occur[4] = 0;
//			hpDown();
//			//DrawChatBoard();
//
//			curPosY--;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff_e[4]);
//			curPosY++;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff[4]);
//
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 0;
//			//��� ����
//		}
//		else
//		{
//			SetCurrentCursorPos(74, curPosY);
//			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[4]);
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 1;
//		}
//	}
//	if (NPCerrand_occur[5] == 1)//������
//	{
//		NPC_duration[5] = (double)(now - NPC_start[5]) / (CLOCKS_PER_SEC);
//		if (NPC_duration[5]> 15)
//		{
//			NPCerrand_occur[5] = 0;
//			hpDown();
//			//DrawChatBoard();
//
//			curPosY--;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff_e[5]);
//			curPosY++;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff[5]);
//
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 0;
//			//��� ����
//		}
//		else
//		{
//			SetCurrentCursorPos(74, curPosY);
//			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[5]);
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 1;
//		}
//	}
//	if (NPCerrand_occur[6] == 1)//ä�븮
//	{
//		NPC_duration[6] = (double)(now - NPC_start[6]) / (CLOCKS_PER_SEC);
//		if (NPC_duration[6]> 15)
//		{
//			NPCerrand_occur[6] = 0;
//			hpDown();
//			//DrawChatBoard();
//
//			curPosY--;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff_e[6]);
//			curPosY++;
//			SetCurrentCursorPos(74, curPosY);
//			printf("%s\n", Debuff[6]);
//
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 0;
//			//��� ����
//		}
//		else
//		{
//			SetCurrentCursorPos(74, curPosY);
//			printf("( �����ð� %.lf��  ) ", 15 - NPC_duration[6]);
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return 1;
//		}
//	}
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//
//COORD GetCurrentCursorPos()
//{
//	COORD curPoint;
//	CONSOLE_SCREEN_BUFFER_INFO curInfo;
//
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
//	curPoint.X = curInfo.dwCursorPosition.X;
//	curPoint.Y = curInfo.dwCursorPosition.Y;
//
//	return curPoint;
//}
//
//void DrawGameBoard(void)
//{
//	int x, y, color = 9;
//
//	/* �ð� �κ� ó�� */
//	for (y = 0; y < GBOARD_HEIGHT + 1; y++)
//	{
//		for (x = 0; x < GBOARD_WIDTH + 2; x++)
//		{
//			if (gameBoardInfo[y][x] != -9 && gameBoardInfo[y][x] <= 0)
//			{
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//			}
//			if (gameBoardInfo[y][x] == -9)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//			}
//			if (gameBoardInfo[y][x] == 1)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//
//			}
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//			if (gameBoardInfo[y][x] == 2)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//			}
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//			if (gameBoardInfo[y][x] == 3)
//			{
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//			}
//			if (gameBoardInfo[y][x] == 4)
//			{
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//			}
//
//		}
//	}
//
//	SetCurrentCursorPos(8, 3);
//	printf("�� å��");
//	SetCurrentCursorPos(8, 5);
//	printf("W O R K");
//
//	SetCurrentCursorPos(36, 2);
//	printf("������");
//	//SetCurrentCursorPos(37, 3);
//	//printf("%d / 6", trash);
//
//	SetCurrentCursorPos(60, 4);
//	printf("�� ����");
//	SetCurrentCursorPos(61, 5);
//	printf("å��");
//	SetCurrentCursorPos(59, 7);
//	printf("[ SPACE ]");
//
//	SetCurrentCursorPos(33, 10);
//	printf("�ѽ���");
//	//SetCurrentCursorPos(33, 11);
//	//printf("%d / 5", fax);
//
//	SetCurrentCursorPos(5, 15);
//	printf("Ŀ����Ʈ");
//	SetCurrentCursorPos(6, 17);
//	printf("M A K E");
//
//	SetCurrentCursorPos(26, 17);
//	printf("ä�븮");
//	SetCurrentCursorPos(27, 18);
//	printf("å��");
//	SetCurrentCursorPos(24, 19);
//	//printf("%d / 10", Chae_desk);
//	printf("CHAE WORK");
//
//	SetCurrentCursorPos(38, 17);
//	printf("������");
//	SetCurrentCursorPos(39, 18);
//	printf("å��");
//	SetCurrentCursorPos(37, 19);
//	//printf("%d / 10", Koo_desk);
//	printf("KOO WORK");
//
//	SetCurrentCursorPos(59, 16);
//	printf("�μ��");
//	SetCurrentCursorPos(58, 18);
//	printf("P R I N T");
//
//}
//
//void show_PC()
//{
//	//curPos_PC = GetCurrentCursorPos();
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
//	printf("��");
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//}
//void show_NPC()
//{
//	//curPos_NPC = GetCurrentCursorPos();
//	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
//	printf("��");
//	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//void delete_PC()
//{
//	//COORD curPos_PC = GetCurrentCursorPos();
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//	printf(" ");
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//void delete_NPC()
//{
//	//COORD curPos_NPC = GetCurrentCursorPos();
//	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
//	printf(" ");
//	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
//}
//
//void shiftRight_PC()
//{
//	if (detectCollision(curPos_PC.X + 2, curPos_PC.Y) == 0)
//		return;
//	if (selected == 2)
//		pickUpTrash(curPos_PC.X + 2, curPos_PC.Y);
//	delete_PC();
//	curPos_PC.X += 2;
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//	show_PC();
//}
//void shiftRight_NPC()
//{
//	if (detectCollision(curPos_NPC.X + 2, curPos_NPC.Y) == 0)
//		return;
//	delete_NPC();
//	curPos_NPC.X += 2;
//	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
//	show_NPC();
//	//   SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//void shiftLeft_PC()
//{
//	if (detectCollision(curPos_PC.X - 2, curPos_PC.Y) == 0)
//		return;
//	if (selected == 2)
//		pickUpTrash(curPos_PC.X - 2, curPos_PC.Y);
//	delete_PC();
//	curPos_PC.X -= 2;
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//	show_PC();
//}
//void shiftLeft_NPC()
//{
//	if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 0)
//		return;
//	delete_NPC();
//	curPos_NPC.X -= 2;
//	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
//	show_NPC();
//	//   SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
//}
//void shiftUp_PC()
//{
//	if (detectCollision(curPos_PC.X, curPos_PC.Y - 1) == 0)
//		return;
//	if (selected == 2)
//		pickUpTrash(curPos_PC.X, curPos_PC.Y - 1);
//	delete_PC();
//	curPos_PC.Y -= 1;
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//	show_PC();
//}
//void shiftUp_NPC()
//{
//	if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 0)
//		return;
//	delete_NPC();
//	curPos_NPC.Y -= 1;
//	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
//	show_NPC();
//	//   SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
//}
//void shiftDown_PC()
//{
//	if (detectCollision(curPos_PC.X, curPos_PC.Y + 1) == 0)
//		return;
//	if (selected == 2)
//		pickUpTrash(curPos_PC.X, curPos_PC.Y + 1);
//	delete_PC();
//	curPos_PC.Y += 1;
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//	show_PC();
//}
//void shiftDown_NPC()
//{
//	if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0)
//		return;
//	delete_NPC();
//	curPos_NPC.Y += 1;
//	SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
//	show_NPC();
//	//   SetCurrentCursorPos(curPos_NPC.X, curPos_NPC.Y);
//}
//void followNPC()
//{
//	int dx = curPos_PC.X - curPos_NPC.X;
//	int dy = curPos_PC.Y - curPos_NPC.Y;
//	int r = rand() % 3;
//	if (dx < 0 && dy<0) // PC�� ����, ���� ����
//	{
//		if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 0)
//		{
//			if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 0)
//			{
//				/*if (r == 0)
//				shiftDown_NPC();
//				else*/
//				shiftRight_NPC();
//			}
//
//			else
//			{
//				if (r == 0)
//					shiftUp_NPC();
//				else
//					shiftRight_NPC();
//			}
//		}
//		else
//		{
//			shiftLeft_NPC();
//			if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 1)
//				shiftUp_NPC();
//		}
//
//	}
//	else if (dx < 0 && dy>0) // PC�� ����, �Ʒ� ����
//	{
//
//		if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 0)
//		{
//			if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0)
//			{
//				if (r == 0)
//					shiftUp_NPC();
//				else
//					shiftRight_NPC();
//			}
//
//			else
//				shiftDown_NPC();
//		}
//		else
//		{
//			shiftLeft_NPC();
//			if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 1)
//				shiftUp_NPC();
//			else
//				shiftDown_NPC();
//		}
//
//	}
//
//	else if (dx < 0 && dy == 0) //PC�� ����, y��ǥ�� ������
//	{
//
//		if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 0)
//		{
//			if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0)
//			{
//				/*if (r == 0)
//				shiftUp_NPC();
//				else*/
//				shiftRight_NPC();
//			}
//
//			else
//			{
//				if (r == 0)
//					shiftDown_NPC();
//				else
//					shiftRight_NPC();
//			}
//
//		}
//		else
//			shiftLeft_NPC();
//
//	}
//
//	else if (dx > 0 && dy < 0) //PC�� ������, ���ʿ� ������
//	{
//
//		if (detectCollision(curPos_NPC.X + 2, curPos_NPC.Y) == 0)
//		{
//			if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 0)
//			{
//				if (r == 0)
//					shiftDown_NPC();
//				else
//					shiftLeft_NPC();
//			}
//
//			else
//				shiftUp_NPC();
//		}
//		else
//		{
//			shiftRight_NPC();
//			if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 1)
//				shiftUp_NPC();
//
//		}
//
//	}
//
//	else if (dx > 0 && dy > 0) //PC�� ������, �Ʒ��� ���� ��
//	{
//
//		if (detectCollision(curPos_NPC.X + 2, curPos_NPC.Y) == 0)
//		{
//			if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0)
//			{
//				if (r == 0)
//					shiftUp_NPC();
//				else
//					shiftLeft_NPC();
//			}
//			else
//				shiftDown_NPC();
//		}
//		else
//		{
//			shiftRight_NPC();
//			if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 1)
//				shiftDown_NPC();
//
//		}
//
//	}
//
//
//	else if (dx > 0 && dy == 0) //PC�� ������, y��ǥ�� ������
//	{
//
//		if (detectCollision(curPos_NPC.X + 2, curPos_NPC.Y) == 0)
//		{
//			if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0)
//			{
//				if (r == 0)
//					shiftUp_NPC();
//				else
//					shiftLeft_NPC();
//			}
//			else
//				shiftDown_NPC();
//		}
//		else
//			shiftRight_NPC();
//
//	}
//	else if (dx == 0 && dy < 0) // PC x��ǥ ����, ���� ���� ��
//	{
//		if (detectCollision(curPos_NPC.X, curPos_NPC.Y - 1) == 0)
//		{
//			if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 0)
//				shiftRight_NPC();
//			else
//				shiftLeft_NPC();
//		}
//		else
//		{
//			shiftUp_NPC();
//		}
//
//	}
//	else if (dx == 0 && dy > 0) // PC x��ǥ ����, �Ʒ��� ���� ��
//	{
//		if (detectCollision(curPos_NPC.X, curPos_NPC.Y + 1) == 0)
//		{
//			if (detectCollision(curPos_NPC.X - 2, curPos_NPC.Y) == 0)
//				shiftRight_NPC();
//			else
//				shiftLeft_NPC();
//		}
//		else
//		{
//			shiftDown_NPC();
//		}
//	}
//	Sleep(5);
//}
//void processKeyinput_PC()
//{
//	int key;
//	int doneWork = 0;
//	for (int i = 0; i<20; i++)
//	{
//		now = clock();
//		duration = (double)(now - start) / (CLOCKS_PER_SEC);
//		if (duration > 100)
//			return;
//		if (i % 3 == 0)
//			followNPC();
//		hpUpdate();
//
//		NPC_TimeLimit();
//		if (_kbhit() != 0)
//		{
//			key = _getch();
//			switch (key)
//			{
//			case LEFT:
//				shiftLeft_PC();
//				break;
//			case RIGHT:
//				shiftRight_PC();
//				break;
//			case UP:
//				shiftUp_PC();
//				break;
//			case DOWN:
//				shiftDown_PC();
//				break;
//			case 'w':
//				if (gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -1)
//				{
//					myDeskUpdate(0);
//					while (1)
//					{
//						now = clock();
//						duration = (double)(now - start) / (CLOCKS_PER_SEC);
//						hpUpdate();
//						NPC_TimeLimit();
//						//followNPC();
//						doneWork = doMyWork();
//
//						if (doneWork == 1)
//						{
//							pay++;
//							payUpdate();
//							break;
//						}
//						if (doneWork == -1)
//						{
//							SetCurrentCursorPos(8, 5);
//							printf("W O R K");
//							SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//							break;
//						}
//						if (doneWork == 2)
//							return;
//						if (duration > 100)
//							return;
//					}
//				}
//				break;
//			case 'm':
//				// Ŀ��
//				if (selected == 0)
//					NPC1_coffee_errand();
//				break;
//			case '0':
//				// �ѽ�
//				if (selected == 1 || (selected == 4 && flag == 2))
//					NPC1_fax_errand();
//				break;
//			case 'p':
//				// ����Ʈ
//				if (selected == 3)
//					NPC1_print_errand();
//				if (selected == 4)
//					fax_after_print();
//				break;
//			case 'k':
//				// ������
//				if (selected == 5)
//					Koo_work_errand();
//				break;
//			case 'c':
//				// ä�븮
//				if (selected == 6)
//					Chae_work_errand();
//				break;
//			case SPACE:
//				// �������ڸ��� ����
//				if (selected == 0 || selected == 3)
//					toNPC1(flag, 3);
//				break;
//			default:
//				break;
//			}
//
//		}
//
//		Sleep(pcSpeed);
//
//	}
//}
//
//int detectCollision(int posX, int posY) //�ε����� 0, �ƴϸ� 1, pc�� �浹�˻�
//{
//	int x = posX / 2;
//	int y = posY;
//	if (gameBoardInfo[y][x] > 0) // pc�� ��ġ��ǥ�� 0 �̻� �� ���
//		return 0;
//	return 1;
//}
//
//void hpUp()
//{
//	if (duration < 100)
//		duration = -10;
//	int i = 10 - ((int)duration / 10);
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DARK_RED);
//	SetCurrentCursorPos(4 + (i * 2), 24);
//	printf("��");
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//	hpUpdate();
//}
//
//void hpDown()
//{
//	if (duration <= 90)
//		duration = +20;
//	hpUpdate();
//}
//
//void Bonus()
//{
//	bonus += 0.5;
//}
//void payDown() {
//	int p = 0;
//	p = pay % 10;
//	pay = pay - p;
//	payUpdate();
//}
//void Oh_closeness() {
//	Oh_close++;
//}
//void Chae_closeness() {
//	Chae_close++;
//}
//void Koo_closeness() {
//	Koo_close++;
//}
//
//void DrawGameStartBoard()
//{
//	int x, y, color = 9;
//
//	for (y = 0; y <= GBOARD_HEIGHT; y++)
//	{
//		for (x = 0; x < GBOARD_WIDTH + 2; x++)
//		{
//			if (gameStartBoardInfo[y][x] == 1)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//			}
//			else if (gameStartBoardInfo[y][x] == 2)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//			}
//			else if (gameStartBoardInfo[y][x] == 3)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//			}
//			else if (gameStartBoardInfo[y][x] == 4)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//			}
//
//
//		}
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//	}
//
//}
//
//void RedrawBlocks(void)
//{
//	int x, y;
//	int color = 9;
//	int cursX, cursY;
//	for (y = 0; y < GBOARD_HEIGHT + 1; y++)
//	{
//		for (x = 0; x < GBOARD_WIDTH + 2; x++)
//		{
//			if (gameBoardInfo[y][x] == 1 || gameBoardInfo[y][x] == 2 || gameBoardInfo[y][x] == 3 || gameBoardInfo[y][x] == 4
//				|| gameBoardInfo[y][x] == -1 || gameBoardInfo[y][x] == -2 || gameBoardInfo[y][x] == -4 ||
//				gameBoardInfo[y][x] == -5 || gameBoardInfo[y][x] == -6 || gameBoardInfo[y][x] == -7 ||
//				gameBoardInfo[y][x] == -8 || gameBoardInfo[y][x] == -9 || gameBoardInfo[y][x] == 0)
//			{
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//			}
//		}
//	}
//
//}
//
//
//
//void DrawChatBoard() {
//	int x;
//	int z;
//	for (z = 1; z <= 20; z++)
//	{
//		for (x = 1; x < GBOARD_CHAT_WIDTH; x++)
//		{
//			if (gameChatBoardInfo[z][x] != 1)
//			{
//				SetCurrentCursorPos((x * 2) + 72, z);
//				printf("��");
//				RemoveCursor();
//			}
//			RemoveCursor();
//		}
//		RemoveCursor();
//	}
//	RemoveCursor();
//
//	/*curPosY++;
//	if (n == 0)
//	curPosY--;
//	SetCurrentCursorPos(74, curPosY);
//	printf("%s\n", Debuff_e[7]);
//	*/
//}
//
//void DrawGameFinishBoard() {
//	int x, y, color = 9;
//
//	for (y = 0; y <= GBOARD_HEIGHT; y++)
//	{
//		for (x = 0; x < GBOARD_WIDTH + 2; x++)
//		{
//			if (gameFinishBoardInfo[y][x] == 1)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
//				SetCurrentCursorPos(x * 2, y);
//
//				printf("��");
//
//			}
//		}
//	}
//}
//
//void DrawGameSuccessBoard() {
//	int x, y, color = 9;
//
//	for (y = 0; y <= GBOARD_HEIGHT; y++)
//	{
//		for (x = 0; x < GBOARD_WIDTH + 2; x++)
//		{
//
//			if (gameSuccessBoardInfo[y][x] == 1)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//				color++;
//				if (color > 14)
//					color = 9;
//			}
//			if (gameSuccessBoardInfo[y][x] == 2)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//
//			}
//			if (gameSuccessBoardInfo[y][x] == 3)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PINK);
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//
//			}
//			if (gameSuccessBoardInfo[y][x] == 4)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//
//			}
//			if (gameSuccessBoardInfo[y][x] == 5)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
//				SetCurrentCursorPos(x * 2, y);
//				printf("��");
//
//			}
//		}
//	}
//}
//
//
//void RemoveCursor(void)
//{//Ŀ�� ������ ����
//	CONSOLE_CURSOR_INFO curInfo;
//	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
//	curInfo.bVisible = 0;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
//}
//
//void hpUpdate()
//{
//	int i = (int)duration / 10;
//	if (i != tmp_HP)
//	{
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DARK_RED);
//		SetCurrentCursorPos(24 - (i * 2), 24);
//		printf("��");
//		tmp_HP = i;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//	}
//
//}
//int stageClear()
//{
//	if (day == 5 && pay == goal_pay)
//		return 1;
//	else
//		return 0;
//}
//void nextStage()
//{
//	pay = goal_pay;
//	goal_pay += 10;
//	day++;
//	duration = 0;
//	tmp_HP = 0;
//	mydeskCount = 0;
//
//
//	n = 0;
//	curPosY = 1;
//	curPos_NPC = { npcPosX,npcPosY };
//	SetCurrentCursorPos(curPosX, curPosY);
//
//	RedrawBlocks();
//	DrawGameBoard();
//
//}
//void payUpdate()
//{
//	SetCurrentCursorPos(14, 23);
//	printf("���� %d���� / %d����(��ǥ����) ", pay, goal_pay);
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//
//void Success() {
//	int key;
//
//	RedrawBlocks();
//	DrawGameSuccessBoard();
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//	SetCurrentCursorPos(53, 8);
//	printf("���ϵ帳�ϴ�!");
//	SetCurrentCursorPos(48, 9);
//	printf("���ϴ� 'Zoon ���ͳ��ų�'");
//	SetCurrentCursorPos(47, 10);
//	printf("���������� ä��Ǽ̽��ϴ�.");
//	SetCurrentCursorPos(50, 12);
//	printf("���� ����: %d ����", pay);
//	SetCurrentCursorPos(49, 13);
//	printf("���� ���ʽ�: %.1f ����", bonus);
//
//	/*SetCurrentCursorPos(48, 15);
//	printf("Replay : SPACE");
//	key = _getch();
//	if (key = _getch()) {
//	RedrawBlocks();
//	DrawGameStartBoard();
//	}*/
//}
//void Fail() {
//	int key;
//	RedrawBlocks();
//	DrawGameFinishBoard();
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//	SetCurrentCursorPos(49, 8);
//	printf("������ �پ ��������");
//	SetCurrentCursorPos(47, 9);
//	printf("�ұ��ϰ� �ݹ� ä�뿡�� �Բ�");
//	SetCurrentCursorPos(50, 10);
//	printf("�� �� ���� �Ǿ����ϴ�.");
//	SetCurrentCursorPos(50, 12);
//	printf("���� ����: ���� %d ����", day);
//	SetCurrentCursorPos(50, 13);
//	printf("���� ����: %d ����", pay);
//	SetCurrentCursorPos(50, 14);
//	printf("���� ���ʽ�: %d ����", pay);
//	/*SetCurrentCursorPos(51, 15);
//	printf("Replay : SPACE");
//	key = _getch();
//	if (key = _getch()) {
//	RedrawBlocks();
//	DrawGameStartBoard();
//	}*/
//}
//
//
//int doMyWork()
//{
//	int key;
//	int clear = 0;
//
//	for (int i = 0; i < 100; i++)
//	{
//		now = clock();
//		duration = (double)(now - start) / (CLOCKS_PER_SEC);
//		hpUpdate();
//		NPC_TimeLimit();
//		if (_kbhit() != 0)
//		{
//			key = _getch();
//			switch (key)
//			{
//			case 'o':
//				if (clear == 0 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -1)
//				{
//					clear++;
//					myDeskUpdate(1);
//				}
//				else
//					return 0;
//
//				break;
//			case 'r':
//				if (clear == 1 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -1)
//				{
//					clear++;
//					myDeskUpdate(2);
//				}
//				else
//					return 0;
//
//				break;
//			case 'k':
//				if (clear == 2 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -1)
//				{
//					clear++;
//					myDeskUpdate(3);
//					clear = 0;
//					if (stageClear() == 1)
//						return 2;
//					return 1;
//				}
//				else
//					return 0;
//
//				break;
//
//			default:
//				clear = 0;
//				return -1;
//				break;
//			}
//		}
//		Sleep(50);
//	}
//
//}
//void myDeskUpdate(int clear)
//{
//	SetCurrentCursorPos(8, 5);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
//	switch (clear)
//	{
//	case 0:
//		printf("W ");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 1:
//		printf("W O ");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 2:
//		printf("W O R ");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 3:
//		printf("W O R K");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		Sleep(100);
//		SetCurrentCursorPos(8, 5);
//		printf("W O R K");
//		break;
//	default:
//		break;
//	}
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//
//// ������ ����
//void toNPC1(int flag, int time) {
//
//	if (flag == 1 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -8)
//	{
//		if (time != 0) {
//			// ���� �ӵ� ����
//			//speedUp();
//			SetCurrentCursorPos(59, 7);
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
//			printf("SPEED UP!");
//
//
//			switch (selected) {
//			case 0:
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//				SetCurrentCursorPos(6, 17);
//				printf("M A K E");
//				break;
//
//			case 3:
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//				SetCurrentCursorPos(58, 18);
//				printf("P R I N T");
//				break;
//
//			default:
//				break;
//			}
//
//			flag = 0;
//			return;
//		}
//		else {
//			// ����� ü�� ����
//			hpDown();
//			flag = 0;
//
//			switch (selected) {
//			case 0:
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//				SetCurrentCursorPos(6, 17);
//				printf("M A K E");
//				break;
//
//			case 3:
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//				SetCurrentCursorPos(58, 18);
//				printf("P R I N T");
//				break;
//
//			default:
//				break;
//			}
//		}
//	}
//	// NPC1���� �������ַ��� �߿� �ð� �� �Ǹ� make, print�۾� ������� �ϱ�
//
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//
//// Ŀ��
//void NPC1_coffee_errand() {
//
//	if (gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -2)
//	{
//		coffeeUpdate(0);
//
//		madeCoffee = makeCoffee();
//		if (madeCoffee == 1)
//		{
//			flag = 1;
//			// �� �Է��ϸ�
//			return;
//		}
//		if (madeCoffee == -1)
//		{
//			// �ٸ� Ű �Է��ϸ� ���� �Է��ϰ�
//			SetCurrentCursorPos(6, 17);
//			printf("M A K E");
//			return;
//		}
//
//	}
//}
//int makeCoffee()
//{
//	int key;
//	int clear = 0;
//
//	for (int i = 0; i < 100; i++)
//	{
//		now = clock();
//		duration = (double)(now - start) / (CLOCKS_PER_SEC);
//		hpUpdate();
//		NPC_TimeLimit();
//		if (_kbhit() != 0)
//		{
//			key = _getch();
//			switch (key)
//			{
//			case 'a':
//				if (clear == 0 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -2)
//				{
//					clear++;
//					coffeeUpdate(1);
//				}
//				else
//					return 0;
//
//				break;
//			case 'k':
//				if (clear == 1 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -2)
//				{
//					clear++;
//					coffeeUpdate(2);
//				}
//				else
//					return 0;
//				break;
//			case 'e':
//				if (clear == 2 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -2)
//				{
//					clear++;
//					coffeeUpdate(3);
//					clear = 0;
//					return 1;
//				}
//				else
//					return 0;
//				break;
//			default:
//				clear = 0;
//				return -1;
//				break;
//			}
//		}
//		Sleep(50);
//	}
//}
//
//void coffeeUpdate(int clear)
//{
//	SetCurrentCursorPos(6, 17);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
//	switch (clear)
//	{
//	case 0:
//		printf("M ");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 1:
//		printf("M A ");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 2:
//		printf("M A K ");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 3:
//		printf("M A K E");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	default:
//		break;
//	}
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//
//// �ѽ�
//
//void NPC1_fax_errand() {
//
//	if (gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4)
//	{
//		faxUpdate(-2);
//
//		phoneCalled = phoneCall();
//		if (flag == 2 && phoneCalled == 1) {
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//			SetCurrentCursorPos(58, 18);
//			printf("P R I N T");
//			flag = 0;
//		}
//
//		if (phoneCalled == 1) {
//			removeFaxNumber();
//			SetCurrentCursorPos(33, 11);
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
//			printf(" SPEED");
//
//			SetCurrentCursorPos(35, 12);
//			printf("UP");
//
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		}
//		if (phoneCalled == -1)
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//			SetCurrentCursorPos(32, 11);
//			printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
//			SetCurrentCursorPos(34, 12);
//			printf("%d%d%d%d", num[4], num[5], num[6], num[7]);
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return;
//		}
//
//	}
//
//}
//
//int phoneCall()
//{
//	int key;
//	int clear = -1;
//
//	switch (clear)
//	{
//	case -1:
//		for (int i = 0; i<20; i++)
//		{
//			now = clock();
//			duration = (double)(now - start) / (CLOCKS_PER_SEC);
//			hpUpdate();
//			NPC_TimeLimit();
//
//			if (_kbhit() != 0)
//			{
//				key = _getch();
//
//				if (key == '2' && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear++;
//					faxUpdate(-1);
//					break;
//				}
//				else if (clear == -1 && key != '2' && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear = -1;
//					return -1;
//				}
//			}
//			Sleep(50);
//		}
//
//	case 0:
//		for (int i = 0; i<20; i++)
//		{
//			now = clock();
//			duration = (double)(now - start) / (CLOCKS_PER_SEC);
//			hpUpdate();
//			NPC_TimeLimit();
//
//			if (_kbhit() != 0)
//			{
//				key = _getch();
//
//				if (key == num[0] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear++;
//					faxUpdate(0);
//					break;
//				}
//				else if (clear == 0 && key != num[0] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear = -1;
//					return -1;
//				}
//			}
//			Sleep(50);
//		}
//
//	case 1:
//		for (int i = 0; i<20; i++)
//		{
//			now = clock();
//			duration = (double)(now - start) / (CLOCKS_PER_SEC);
//			hpUpdate();
//			NPC_TimeLimit();
//
//			if (_kbhit() != 0)
//			{
//				key = _getch();
//
//				if (key == num[1] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear++;
//					faxUpdate(1);
//					break;
//				}
//				else if (clear == 1 && key != num[1] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear = -1;
//					return -1;
//				}
//			}
//			Sleep(50);
//		}
//
//	case 2:
//		for (int i = 0; i<20; i++)
//		{
//			now = clock();
//			duration = (double)(now - start) / (CLOCKS_PER_SEC);
//			hpUpdate();
//			NPC_TimeLimit();
//
//			if (_kbhit() != 0)
//			{
//				key = _getch();
//
//				if (key == num[2] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear++;
//					faxUpdate(2);
//					break;
//				}
//				else if (clear == 2 && key != num[2] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear = -1;
//					return -1;
//				}
//			}
//			Sleep(50);
//		}
//
//	case 3:
//		for (int i = 0; i<20; i++)
//		{
//			now = clock();
//			duration = (double)(now - start) / (CLOCKS_PER_SEC);
//			hpUpdate();
//			NPC_TimeLimit();
//
//			if (_kbhit() != 0)
//			{
//				key = _getch();
//
//				if (key == num[3] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear++;
//					faxUpdate(3);
//					break;
//				}
//				else if (clear == 3 && key != num[3] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear = -1;
//					return -1;
//				}
//			}
//			Sleep(50);
//		}
//
//	case 4:
//		for (int i = 0; i<20; i++)
//		{
//			now = clock();
//			duration = (double)(now - start) / (CLOCKS_PER_SEC);
//			hpUpdate();
//			NPC_TimeLimit();
//
//			if (_kbhit() != 0)
//			{
//				key = _getch();
//
//				if (key == num[4] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear++;
//					faxUpdate(4);
//					break;
//				}
//				else if (clear == 4 && key != num[4] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear = -1;
//					return -1;
//				}
//			}
//			Sleep(50);
//		}
//
//	case 5:
//		for (int i = 0; i<20; i++)
//		{
//			now = clock();
//			duration = (double)(now - start) / (CLOCKS_PER_SEC);
//			hpUpdate();
//			NPC_TimeLimit();
//
//			if (_kbhit() != 0)
//			{
//				key = _getch();
//
//				if (key == num[5] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear++;
//					faxUpdate(5);
//					break;
//				}
//				else if (clear == 5 && key != num[5] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear = -1;
//					return -1;
//				}
//			}
//			Sleep(50);
//		}
//
//	case 6:
//		for (int i = 0; i<20; i++)
//		{
//			now = clock();
//			duration = (double)(now - start) / (CLOCKS_PER_SEC);
//			hpUpdate();
//			NPC_TimeLimit();
//
//			if (_kbhit() != 0)
//			{
//				key = _getch();
//
//				if (key == num[6] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear++;
//					faxUpdate(6);
//					break;
//				}
//				else if (clear == 6 && key != num[6] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear = -1;
//					return -1;
//				}
//			}
//			Sleep(50);
//		}
//
//	case 7:
//		for (int i = 0; i<20; i++)
//		{
//			now = clock();
//			duration = (double)(now - start) / (CLOCKS_PER_SEC);
//			hpUpdate();
//			NPC_TimeLimit();
//
//			if (_kbhit() != 0)
//			{
//				key = _getch();
//
//				if (key == num[7] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear++;
//					faxUpdate(7);
//					clear = -1;
//					return 1;
//				}
//				else if (clear == 7 && key != num[7] + 48 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -4) {
//					clear = -1;
//					return -1;
//				}
//
//			}
//			Sleep(50);
//		}
//		break;
//	}
//}
//void faxUpdate(int clear)
//{
//	SetCurrentCursorPos(32, 11);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
//	switch (clear)
//	{
//	case -2:
//		printf("0");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case -1:
//		printf("02-");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 0:
//		printf("02-%d", num[0]);
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 1:
//		printf("02-%d%d", num[0], num[1]);
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 2:
//		printf("02-%d%d%d", num[0], num[1], num[2]);
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 3:
//		printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 4:
//		printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
//		SetCurrentCursorPos(34, 12);
//		printf("%d", num[4]);
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 5:
//		printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
//		SetCurrentCursorPos(34, 12);
//		printf("%d%d", num[4], num[5]);
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 6:
//		printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
//		SetCurrentCursorPos(34, 12);
//		printf("%d%d%d", num[4], num[5], num[6]);
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 7:
//		printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
//		SetCurrentCursorPos(34, 12);
//		printf("%d%d%d%d", num[4], num[5], num[6], num[7]);
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		Sleep(100);
//		SetCurrentCursorPos(32, 11);
//		printf("02-%d%d%d%d-", num[0], num[1], num[2], num[3]);
//		SetCurrentCursorPos(34, 12);
//		printf("%d%d%d%d", num[4], num[5], num[6], num[7]);
//		break;
//	default:
//		break;
//	}
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//void faxNumber() {
//	srand((unsigned)time(NULL));
//	for (int i = 0; i<8; i++)
//		num[i] = rand() % 9;
//
//	SetCurrentCursorPos(32, 11);
//	printf("02-");
//	for (int i = 0; i<4; i++) {
//		printf("%d", num[i]);
//	}
//
//	printf("-");
//	SetCurrentCursorPos(34, 12);
//	for (int i = 4; i<8; i++) {
//		printf("%d", num[i]);
//	}
//}
//
//// ����Ʈ
//void NPC1_print_errand() {
//	if (gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -3)
//	{
//		printUpdate(0);
//
//		printed = printing();
//		if (printed == 1)
//		{
//
//			flag = 1;
//			if (selected == 4)
//				flag = 2;
//
//			return;
//		}
//		if (printed == -1)
//		{
//			SetCurrentCursorPos(58, 18);
//			printf("P R I N T");
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return;
//		}
//	}
//
//}
//int printing() {
//	int key;
//	int clear = 0;
//
//	for (int i = 0; i < 100; i++)
//	{
//		now = clock();
//		duration = (double)(now - start) / (CLOCKS_PER_SEC);
//		hpUpdate();
//		NPC_TimeLimit();
//		if (_kbhit() != 0)
//		{
//			key = _getch();
//			switch (key)
//			{
//			case 'r':
//				if (clear == 0 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -3)
//				{
//					clear++;
//					printUpdate(1);
//				}
//				else
//					return 0;
//
//				break;
//			case 'i':
//				if (clear == 1 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -3)
//				{
//					clear++;
//					printUpdate(2);
//				}
//				else
//					return 0;
//				break;
//			case 'n':
//				if (clear == 2 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -3)
//				{
//					clear++;
//					printUpdate(3);
//				}
//				else
//					return 0;
//				break;
//			case 't':
//				if (clear == 3 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -3)
//				{
//					clear++;
//					printUpdate(4);
//					clear = 0;
//					return 1;
//				}
//				else
//					return 0;
//				break;
//			default:
//				clear = 0;
//				return -1;
//				break;
//				// -1 : �ٽ� �Է��ϰ��ϱ�
//			}
//		}
//		Sleep(50);
//	}
//}
//void printUpdate(int clear) {
//
//	SetCurrentCursorPos(58, 18);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
//	switch (clear)
//	{
//	case 0:
//		printf("P ");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 1:
//		printf("P R ");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 2:
//		printf("P R I ");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 3:
//		printf("P R I N");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 4:
//		printf("P R I N T");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	default:
//		break;
//	}
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//
//// ä�븮
//void Chae_work_errand() {
//	if (gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
//	{
//		chaeUpdate(0);
//
//		chaeWorked = chaeWorking();
//		if (chaeWorked == 1) {
//			//DrawChatBoard();
//			SetCurrentCursorPos(24, 19);
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
//			printf("SPEED UP");
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			// ����
//			return;
//		}
//		if (chaeWorked == -1) {
//			SetCurrentCursorPos(24, 19);
//			printf("CHAE WORK");
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return;
//		}
//	}
//}
//int chaeWorking() {
//	int key;
//	int clear = 0;
//
//	for (int i = 0; i < 100; i++)
//	{
//		now = clock();
//		duration = (double)(now - start) / (CLOCKS_PER_SEC);
//		hpUpdate();
//		NPC_TimeLimit();
//		if (_kbhit() != 0)
//		{
//			key = _getch();
//			switch (key)
//			{
//			case 'h':
//				if (clear == 0 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
//				{
//					clear++;
//					chaeUpdate(1);
//				}
//				else
//					return 0;
//
//				break;
//			case 'a':
//				if (clear == 1 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
//				{
//					clear++;
//					chaeUpdate(2);
//				}
//				else
//					return 0;
//				break;
//			case 'e':
//				if (clear == 2 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
//				{
//					clear++;
//					chaeUpdate(3);
//				}
//				else
//					return 0;
//				break;
//			case 'w':
//				if (clear == 3 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
//				{
//					clear++;
//					chaeUpdate(4);
//				}
//				else
//					return 0;
//				break;
//			case 'o':
//				if (clear == 4 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
//				{
//					clear++;
//					chaeUpdate(5);
//				}
//				else
//					return 0;
//				break;
//			case 'r':
//				if (clear == 5 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
//				{
//					clear++;
//					chaeUpdate(6);
//				}
//				else
//					return 0;
//				break;
//			case 'k':
//				if (clear == 6 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -6)
//				{
//					clear++;
//					chaeUpdate(7);
//					clear = 0;
//					return 1;
//				}
//				else
//					return 0;
//				break;
//			default:
//				clear = 0;
//				return -1;
//				break;
//			}
//		}
//		Sleep(50);
//	}
//}
//void chaeUpdate(int clear) {
//
//	SetCurrentCursorPos(24, 19);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
//	switch (clear)
//	{
//	case 0:
//		printf("C");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 1:
//		printf("CH");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 2:
//		printf("CHA");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 3:
//		printf("CHAE");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 4:
//		printf("CHAE W");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 5:
//		printf("CHAE WO");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 6:
//		printf("CHAE WOR");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 7:
//		printf("CHAE WORK");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	default:
//		break;
//	}
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//
//// ������
//void Koo_work_errand() {
//	if (gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
//	{
//		kooUpdate(0);
//
//		kooWorked = kooWorking();
//		if (kooWorked == 1) {
//			//DrawChatBoard();
//			SetCurrentCursorPos(37, 19);
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
//			printf("SPEED UP");
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			// ����
//			return;
//		}
//		if (kooWorked == -1) {
//			SetCurrentCursorPos(37, 19);
//			printf("KOO WORK");
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return;
//		}
//	}
//}
//int kooWorking() {
//	int key;
//	int clear = 0;
//
//	for (int i = 0; i < 100; i++)
//	{
//		now = clock();
//		duration = (double)(now - start) / (CLOCKS_PER_SEC);
//		hpUpdate();
//		NPC_TimeLimit();
//		if (_kbhit() != 0)
//		{
//			key = _getch();
//			switch (key)
//			{
//			case 'o':
//				if (clear == 0 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
//				{
//					clear++;
//					kooUpdate(1);
//				}
//				else if (clear == 1 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
//				{
//					clear++;
//					kooUpdate(2);
//				}
//				else if (clear == 3 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
//				{
//					clear++;
//					kooUpdate(4);
//				}
//				else
//					return 0;
//				break;
//			case 'w':
//				if (clear == 2 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
//				{
//					clear++;
//					kooUpdate(3);
//				}
//				else
//					return 0;
//				break;
//			case 'r':
//				if (clear == 4 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
//				{
//					clear++;
//					kooUpdate(5);
//				}
//				else
//					return 0;
//				break;
//			case 'k':
//				if (clear == 5 && gameBoardInfo[curPos_PC.Y][curPos_PC.X / 2] == -7)
//				{
//					clear++;
//					kooUpdate(6);
//					clear = 0;
//					return 1;
//				}
//				else
//					return 0;
//				break;
//			default:
//				clear = 0;
//				return -1;
//				break;
//			}
//		}
//		Sleep(50);
//	}
//}
//void kooUpdate(int clear) {
//	SetCurrentCursorPos(37, 19);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
//	switch (clear)
//	{
//	case 0:
//		printf("K");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 1:
//		printf("KO");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 2:
//		printf("KOO");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 3:
//		printf("KOO W");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 4:
//		printf("KOO WO");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 5:
//		printf("KOO WOR");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	case 6:
//		printf("KOO WORK");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//		break;
//	default:
//		break;
//	}
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//
//// �μ��ϰ� �ѽ� ������
//void fax_after_print() {
//	// �μ��ϰ�
//	NPC1_print_errand();
//	// �ѽ�
//	if (flag == 2) {
//		faxNumber();
//	}
//}
//// ������
//void pickUpTrash(int posX, int posY) {
//
//	int x = posX / 2;
//	int y = posY;
//
//	if (gameBoardInfo[y][x] == -5)
//	{
//		trash++;
//		gameBoardInfo[y][x] = -10; // �� ��ġ�� �ִ� ������ �����
//		SetCurrentCursorPos(37, 3);
//		printf("%d / 6", trash);
//
//		if (trash >= 6) {
//			//DrawChatBoard();
//			trash = 0;
//			SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//			return;
//		}
//	}
//	// ���� �� �ӵ� ���� �Լ� ȣ��, ���� �� ���� X
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//void dumpTrash() {
//
//	for (int y = 0; y <= GBOARD_HEIGHT; y++) {
//		for (int x = 0; x < GBOARD_WIDTH + 2; x++)
//		{
//			if (gameBoardInfo[y][x] == -10) {
//				gameBoardInfo[y][x] = -5;
//			}
//
//			if (gameBoardInfo[y][x] == -5)
//			{
//				SetCurrentCursorPos(x * 2, y);
//				printf("@");
//			}
//
//		}
//	}
//}
//// �ʱ�ȭ
//void initializedCoffee() {
//	SetCurrentCursorPos(6, 17);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//	printf("M A K E");
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//void initializedPrint() {
//	SetCurrentCursorPos(58, 18);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//	printf("P R I N T");
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//void initializedKoo() {
//	SetCurrentCursorPos(37, 19);
//	printf("KOO WORK");
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//void initializedChae() {
//	SetCurrentCursorPos(24, 19);
//	printf("CHAE WORK");
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//void initializedOh() {
//	SetCurrentCursorPos(59, 7);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//	printf("[ SPACE ]");
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//void removeTrash() {
//	trash = 0;
//	SetCurrentCursorPos(37, 3);
//	printf("     ");
//
//	for (int y = 0; y <= GBOARD_HEIGHT; y++) {
//		for (int x = 0; x < GBOARD_WIDTH + 2; x++)
//		{
//			if (gameBoardInfo[y][x] == -5)
//			{
//				SetCurrentCursorPos(x * 2, y);
//				printf(" ");
//			}
//
//		}
//	}
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
//void removeFaxNumber() {
//	SetCurrentCursorPos(32, 11);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
//	printf("        ��");
//	SetCurrentCursorPos(34, 12);
//	printf("    ");
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
//	SetCurrentCursorPos(curPos_PC.X, curPos_PC.Y);
//}
