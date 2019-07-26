#include <stdio.h>
#include <windows.h>
#include<time.h>
#include<conio.h>
#include "Utill.h"
#include "Story.h"
#include "Hero.h"
#include "Boss.h"
#include "Skill.h"
#include "WallLayer.h"
#include "ObjectLayer.h"
#include "UserInterface.h"
#include "Reward.h"
#include "GameOver.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")



stHero* Hero = new stHero;
stBoss* Boss = new stBoss;

int nStage = 0;
int speed = 10;
int nScene = 1;	//nScene 0 - �޴�, 1 - ���� , 2 - ����Ʈ, 3 - ������

int FightTern = 1;
int FightBossTern = 0;
bool bBossTern = false;
bool bHeroTern = true;
bool bSightCheck = false;

void DeleteHero();
void ReDrawGame();
void InitHero()
{

	Hero->HP = 100;
	Hero->MP = 100;
	Hero->Attack = 5;
	Hero->KeyState = false;
	Hero->Position = COORD{ 30, 2 };
	Hero->bShieldOn = false;
	Hero->bHeroDead = false;
	Hero->nBuffCount = 0;
	Hero->bFireCheck = false;

	if (nStage == 0)
	{
		strcpy(Hero->haveSKill[0], "");
		strcpy(Hero->haveSKill[1], "");
	}


}
void InitBoss()
{
	//�ϴ� �ʱⰪ�� �̷��� ����, ���߿� ���������� ���� �ٲ��־����
	if (nStage == 0)
	{
		Boss->HP = 100;
		Boss->MP = 100;
	}
	else if (nStage == 1)
	{
		Boss->HP = 130;
		Boss->MP = 75;
	}
	Boss->nBossNum = nStage;
	Boss->bShiledOn = false;
	Boss->bFreezeOn = false;
	Boss->bPoisonOn = false;
	Boss->bBossDead = false;

}
bool CollisionObeject(int x, int y)
{
	if (ObjectLayer[nStage][y][x - 2] == 1)
	{
		return true;
	}
	if (ObjectLayer[nStage][y][x - 2] == 2)	//HP ȸ��
	{
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("Sound/ü��ȸ��.wav"), NULL, SND_ASYNC | SND_NOSTOP);
		ObjectLayer[nStage][y][x - 2] = 0;
		Hero->HP += 10;
		return false;
	}
	if (ObjectLayer[nStage][y][x - 2] == 3) //MP ȸ��
	{
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("Sound/����.wav"), NULL, SND_ASYNC | SND_NOSTOP);
		ObjectLayer[nStage][y][x - 2] = 0;
		Hero->MP += 10;
		return false;
	}
	if (ObjectLayer[nStage][y][x - 2] == 4) //HP ����
	{
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("Sound/��.wav"), NULL, SND_ASYNC | SND_NOSTOP);
		ObjectLayer[nStage][y][x - 2] = 0;
		Hero->HP -= 10;
		return false;
	}
	if (ObjectLayer[nStage][y][x - 2] == 5) //MP ����
	{
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("Sound/��.wav"), NULL, SND_ASYNC | SND_NOSTOP);
		ObjectLayer[nStage][y][x - 2] = 0;
		Hero->MP -= 10;
		return false;
	}
	if (ObjectLayer[nStage][y][x - 2] == 6) //����
	{
		nScene = 2;
		ObjectLayer[nStage][y][x - 2] = 0;
		return true;
	}
	if (ObjectLayer[nStage][y][x - 2] == 7) //�þ�
	{
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("Sound/����.wav"), NULL, SND_ASYNC | SND_NOSTOP);
		bSightCheck = true;
		DrawObjectLayer(nStage, Hero, bSightCheck);
		return false;
	}
	if (ObjectLayer[nStage][y][x - 2] == 8) //������������
	{
		if (Hero->KeyState == true)
		{
			nStage++;
			InitHero();
			bSightCheck = false;
			ReDrawGame();

			return false;
		}
		else
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
					if (bSightCheck == false)
					{
						DrawObjectLayer(nStage, Hero, bSightCheck);
					}
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
					if (bSightCheck == false)
					{
						DrawObjectLayer(nStage, Hero, bSightCheck);
					}
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
					if (bSightCheck == false)
					{
						DrawObjectLayer(nStage, Hero, bSightCheck);
					}
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
					if (bSightCheck == false)
					{
						DrawObjectLayer(nStage, Hero, bSightCheck);
					}
					DeleteHero();
					p1->Y += 1;
				}
				if (nScene == 2)
				{

				}
				break;
			case 32: // space bar
				if ((nScene == 2 && bHeroTern == true) && FightSelect != 3)
				{
					DecideSelect(FightSelect, Boss, Hero);
					if (Action_Skill)
					{
						DrawFightHeroUI(Hero, nStage);
						DrawFightBossUI(Boss, nStage);
						if (FightSelect != 1 && FightSelect != 2)
						{
							FightTern++;
							bBossTern = true;
							Sleep(500);
							bHeroTern = false;
							Hero->bFireCheck = false;
						}
					}
				}
				else if (FightSelect == 3)
				{

					DecideSelect(FightSelect, Boss, Hero);
					FightSelect = 0;
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
	DrawObjectLayer(nStage, Hero, bSightCheck);
	DrawUILayer(Hero, nStage);
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
	DrawBossLook(nStage);
	DrawFightBossUI(Boss, nStage);
	DrawFightHeroUI(Hero, nStage);
	DrawFightMenu(Hero);
}
void ReStartGame(bool* FReDraw)
{
	nScene = 1;
	InitHero();
	InitBoss();
	ReDrawGame();
	memcpy(ObjectLayer, RealObjectLayer, sizeof(ObjectLayer));
	*FReDraw = false;
}
int main()
{
	srand(time(NULL));
	if (DrawStartStory())
	{
		system("cls");
		RemoveCursor();
		DrawWallLayer(0);
		InitHero();
		InitBoss();
		DrawObjectLayer(nStage, Hero, bSightCheck);

		DrawUILayer(Hero, nStage);
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
					if (Boss->bBossDead == true)
					{

						nScene = 3;
						if (nStage + 1 >= 2)
						{
							system("cls");
							if (DrawEndingStory())
								break;
						}
						DrawReward(Hero, Boss, &nStage, &nScene);
						InitBoss();
						bSightCheck = true;
						ReDrawGame();
						FightReDraw = false;
						nScene = 1;
						Hero->KeyState = true;
					}
					else if (Hero->bHeroDead == true)
					{
						if (DrawGameOver() == true)
						{
							ReStartGame(&FightReDraw);
						}
						else
						{
							exit(0);
						}
					}
				}
				break;
			}


		}
	}
	return 0;
}