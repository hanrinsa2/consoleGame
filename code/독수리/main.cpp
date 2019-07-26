#include <stdio.h>
#include <windows.h>
#include<time.h>
#include<conio.h>
#include "Utill.h"
#include "Hero.h"
#include "Boss.h"
#include "WallLayer.h"
#include "ObjectLayer.h"
#include "UserInterface.h"




stHero* Hero = new stHero;
stBoss* Boss = new stBoss;

int nStage = 0;
int speed = 10;
int nScene = 1;	//nScene 0 - �޴�, 1 - ���� , 2 - ����Ʈ, 3 - ������

int FightTern = 1;
int FightBossTern = 0;
bool bBossTern = false;
bool bHeroTern = true;

void DeleteHero();
void ReDrawGame();
void InitHero()
{

	Hero->HP = 100;
	Hero->MP = 100;
	Hero->Attack = 10;
	Hero->KeyState = false;
	Hero->Position = COORD{ 30, 15 };
	Hero->bShieldOn = false;
	Hero->SkillOn_001 = false;

}
void InitBoss()
{
	//�ϴ� �ʱⰪ�� �̷��� ����, ���߿� ���������� ���� �ٲ��־����
	Boss->HP = 100;
	Boss->MP = 100;
	Boss->nBossNum = nStage;
	Boss->bShiledOn = false;
	Boss->SkillOn_001 = true;
	Boss->SkillOn_002 = true;
}
bool CollisionObeject(int x, int y)
{
	if (ObjectLayer[nStage][y][x-2] == 1)
	{
		return true;
	}
	if (ObjectLayer[nStage][y][x - 2] == 5)
	{
		nScene = 2;
		return true;
	}
	if (WallLayer[0][y][x] != 0)
	{
		return true;
	}
	return false;
}
void ProcessKeyInput(COORD *p1)
{
	for (int i = 0; i < 10; i++) {
		if (_kbhit() != 0)
		{
			int keys = _getch();
			switch (keys)
			{
			case 49:
			{
					   nStage = 0;
					   ReDrawGame();
					   break;
			}
			case 50:
			{
					   nStage = 1;
					   ReDrawGame();
					   break;
			}

			case 75://left
				if (CollisionObeject(p1->X - 1, p1->Y) != true && nScene == 1) // GameScene�϶�
				{
					DeleteHero();
					p1->X -= 1;
				}
				if (nScene == 2)	//FightScene�϶�
				{
					if (FightSelect > 0)
					{
						FightSelect--;
						SelectFightMenu(FightSelect);
					}
				}
				break;
			case 77://right

				if (CollisionObeject(p1->X + 1, p1->Y) != true && nScene == 1)
				{
					DeleteHero();
					p1->X += 1;
				}
				if (nScene == 2)
				{
					if (FightSelect < 3)
					{
						FightSelect++;
						SelectFightMenu(FightSelect);
					}
				}
				break;
			case 72://up

				if (CollisionObeject(p1->X, p1->Y - 1) != true && nScene == 1)
				{
					DeleteHero();
					p1->Y -= 1;
				}
				if (nScene == 2)
				{

				}
				break;
			case 80://DOWN

				if (CollisionObeject(p1->X, p1->Y + 1) != true && nScene == 1)
				{
					DeleteHero();
					p1->Y += 1;
				}
				if (nScene == 2)
				{

				}
				break;
			case 32: // space bar
				if ( (nScene == 2 && bHeroTern == true ) && FightSelect != 3)
				{
					DecideSelect(FightSelect, Boss,Hero);
					DrawFightHeroUI(Hero, nStage);
					DrawFightBossUI(Boss, nStage);
					FightTern++;
					bBossTern = true;
					Sleep(500);
					bHeroTern = false;
				}
				else if (FightSelect == 3)
				{
					DecideSelect(FightSelect, Boss,Hero);
				}
				break;
			}
			
		
		}
		Sleep(speed);
	}
}
void DeleteHero(){
	SetCurrentCursorPos(Hero->Position.X, Hero->Position.Y);
	printf(" ");
	
}
void ReDrawGame(){
	system("cls");
	DrawWallLayer(0);
	DrawObjectLayer(nStage);
	DrawUILayer(Hero,nStage);
}
void RemoveCursor(){

		CONSOLE_CURSOR_INFO curInfo;

		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

		curInfo.bVisible = 0;

		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);


}
void DrawFightSceneALL()
{
	OpenBossLook(nStage);
	DrawFightBossUI(Boss, nStage);
	DrawFightHeroUI(Hero, nStage);
	DrawFightMenu(Hero);
}
int main()
{
	srand(time(NULL));
	RemoveCursor();
	DrawWallLayer(0);

	DrawObjectLayer(nStage);
	InitHero();
	InitBoss();
	DrawUILayer(Hero,nStage);
	bool FightReDraw = false;


	while (true)
	{
		switch (nScene)
		{
		case 1:	//���Ӿ��϶�
			ProcessKeyInput(&Hero->Position);
			DrawUILayer(Hero, nStage);

			SetCurrentCursorPos(Hero->Position.X, Hero->Position.Y);	
			SetColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("@");
			SetColor(7);
			break;
		case 2: //����Ʈ���϶�
			if (FightReDraw == false)
			{
				system("cls");
				DrawFightSceneALL();
				SelectFightMenu(FightSelect);
				FightReDraw = true;
			}
			ProcessKeyInput(&Hero->Position);
			if (bBossTern == true)
			{
				BossPattern(Boss, Hero);
				DrawFightHeroUI(Hero, nStage);
					DrawFightBossUI(Boss, nStage);
				bBossTern = false;
				bHeroTern = true;
			}
			break;
		}

		
	}
	return 0;
}