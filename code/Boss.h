#pragma once
char sBossLook[3][64][64] = {

};

typedef struct stBoss{
	int HP;				//HP
	int MP;				//MP
	char BossName[20];
	int nBossNum;		//보스의 넘버
	int PoisonCount = 0;
	int FreezeCount = 0;
	bool bShiledOn;
	bool bPoisonOn;	//독 온
	bool bFreezeOn;	//얼음 온
	bool bBossDead;

	bool SkillOn_001;
	bool SkillOn_002;


}STBOSS;
void BossMinusHP(int Num,int Color)
{
	SetColor(Color);
	SetCurrentCursorPos(90, 6);
	printf("-%d", Num);
	Sleep(300);
	SetCurrentCursorPos(90, 6);
	SetColor(7);
	printf("     ");
}
void BossUseMP(int Num)
{
	SetColor(11);
	SetCurrentCursorPos(90, 7);
	printf("-%d", Num);
	Sleep(300);
	SetCurrentCursorPos(90, 7);
	SetColor(7);
	printf("     ");
}
void DrawBossLook(int nBossNum);
void BossPattern(stBoss* Boss, stHero* Hero)
{

	if (Boss->nBossNum == 0)	//1스테이지 보스 패턴
	{

		if (Boss->bPoisonOn && Boss->PoisonCount < 10)
		{
			Boss->HP -= 2;
			BossMinusHP(-2, 13);
			Boss->PoisonCount += 1;
			SetCurrentCursorPos(0, 0);
			SetColor(13);
			DrawBossLook(Boss->nBossNum);
			SetColor(7);
			if (Boss->PoisonCount >= 10)
			{
				Boss->bPoisonOn = false;
				Boss->PoisonCount = 0;
				SetCurrentCursorPos(0, 0);
				SetColor(7);
				DrawBossLook(Boss->nBossNum);
			}
			SetCurrentCursorPos(0, 0);
			SetColor(7);
			DrawBossLook(Boss->nBossNum);
			if (Boss->HP <= 0)
				Boss->bBossDead = true;

		}
		if (Boss->HP <= 0)
			Boss->bBossDead = true;
		if ((Boss->MP - 50 >= 0 && Boss->HP < 40) && Boss->bBossDead == false)
		{
			if ((rand() % 1 == 0) && (Boss->MP <= 60 && Boss->MP > 0))	//피 30깎는 스킬 50퍼 확률로 사용
			{
				if (Hero->bShieldOn == false)
				{
					if (Boss->bFreezeOn)
					{
						Hero->HP -= 25;
						MinusHP(25);
						Boss->MP -= 30;
						BossUseMP(30);
					}
					else
					{
						Hero->HP -= 30;
						MinusHP(30);
						Boss->MP -= 30;
						BossUseMP(30);
					}
				}
				else
				{
					PlaySound(NULL, 0, 0);
					PlaySound(TEXT("Sound/방패막기.wav"), NULL, SND_ASYNC | SND_NOSTOP);
					Hero->bShieldOn = false;
					UseMP(-30);
					Hero->MP += 30;
					BossUseMP(30);
					Boss->MP -= 30;
				}
			}
			else
			{
				SetColor(10);
				SetCurrentCursorPos(90, 6);	//힐부분
				printf("+20");
				Sleep(300);
				SetCurrentCursorPos(90, 6);
				SetColor(7);
				printf("     ");
				Boss->HP += 20;
				BossUseMP(15);
				Boss->MP -= 15;
			}
		}
		else
		{
			if (Hero->bShieldOn == false)
			{
				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("Sound/기본공격.wav"), NULL, SND_ASYNC | SND_NOSTOP);
				if (Boss->bFreezeOn)
				{
					Hero->HP -= 0;
				}
				else
				{
					MinusHP(5);
					Hero->HP -= 5;
				}
			}
			else
			{

				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("Sound/방패막기.wav"), NULL, SND_ASYNC | SND_NOSTOP);
				Hero->bShieldOn = false;
			}
		}
		if (Boss->bFreezeOn && Boss->FreezeCount < 5)
		{
			Boss->FreezeCount += 1;
			if (Boss->FreezeCount >= 5)
			{

				Boss->FreezeCount = 0;
				Boss->bFreezeOn = false;
				SetCurrentCursorPos(0, 0);
				SetColor(7);
				DrawBossLook(Boss->nBossNum);
			}
			else{
				SetCurrentCursorPos(0, 0);
				SetColor(9);
				DrawBossLook(Boss->nBossNum);
				SetColor(7);
			}
		}
	}

	if (Boss->nBossNum == 1)	//2스테이지 보스 패턴
	{
		if (Boss->bPoisonOn && Boss->PoisonCount < 10)
		{
			Boss->HP -= 2;
			BossMinusHP(-2, 13);
			Boss->PoisonCount += 1;
			SetCurrentCursorPos(0, 0);
			SetColor(13);
			DrawBossLook(Boss->nBossNum);
			SetColor(7);
			if (Boss->PoisonCount >= 10)
			{
				Boss->bPoisonOn = false;
				Boss->PoisonCount = 0;
				SetCurrentCursorPos(0, 0);
				SetColor(7);
				DrawBossLook(Boss->nBossNum);
			}
			SetCurrentCursorPos(0, 0);
			SetColor(7);
			DrawBossLook(Boss->nBossNum);
			if (Boss->HP <= 0)
				Boss->bBossDead = true;

		}
		if (Boss->HP <= 0)
			Boss->bBossDead = true;
		if ((Boss->MP - 50 >= 0 && Boss->HP < 40) && Boss->bBossDead == false)
		{
			if ((rand() % 1 == 0) && (Boss->MP <= 60 && Boss->MP > 0))	//피 30깎는 스킬 50퍼 확률로 사용
			{
				if (Hero->bShieldOn == false)
				{
					if (Boss->bFreezeOn)
					{
						Hero->HP -= 25;
						MinusHP(25);
						Boss->MP -= 30;
						BossUseMP(30);
					}
					else
					{
						Hero->HP -= 30;
						MinusHP(30);
						Boss->MP -= 30;
						BossUseMP(30);
					}
				}
				else
				{
					PlaySound(NULL, 0, 0);
					PlaySound(TEXT("Sound/방패막기.wav"), NULL, SND_ASYNC | SND_NOSTOP);
					Hero->bShieldOn = false;
					UseMP(-30);
					Hero->MP += 30;
					BossUseMP(30);
					Boss->MP -= 30;
				}
			}
			else
			{
				SetColor(10);
				SetCurrentCursorPos(90, 6);	//힐부분
				printf("+20");
				Sleep(300);
				SetCurrentCursorPos(90, 6);
				SetColor(7);
				printf("     ");
				Boss->HP += 20;
				BossUseMP(15);
				Boss->MP -= 15;
			}
		}
		else
		{
			if (Hero->bShieldOn == false)
			{
				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("Sound/기본공격.wav"), NULL, SND_ASYNC | SND_NOSTOP);
				if (Boss->bFreezeOn)
				{
					Hero->HP -= 0;
				}
				else
				{
					MinusHP(5);
					Hero->HP -= 5;
				}
			}
			else
			{

				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("Sound/방패막기.wav"), NULL, SND_ASYNC | SND_NOSTOP);
				Hero->bShieldOn = false;
			}
		}
		if (Boss->bFreezeOn && Boss->FreezeCount < 5)
		{
			Boss->FreezeCount += 1;
			if (Boss->FreezeCount >= 5)
			{

				Boss->FreezeCount = 0;
				Boss->bFreezeOn = false;
				SetCurrentCursorPos(0, 0);
				SetColor(7);
				DrawBossLook(Boss->nBossNum);
			}
			else{
				SetCurrentCursorPos(0, 0);
				SetColor(9);
				DrawBossLook(Boss->nBossNum);
				SetColor(7);
			}
		}
	}


}
void DrawBossLook(int BossNum){
	for (int y = 0; y < 21; y++)
	{
		for (int x = 0; x < 64; x++)
		{
			printf("%c", sBossLook[BossNum][y][x]);
		}
	}
}
void OpenBossLook(int BossNum){
	FILE *fp;
	char sName[5] = "Boss";
	char sNum[2];
	_itoa(BossNum, sNum, 10);
	char sFormat[5] = ".txt";
	char sFileName[20];
	sprintf(sFileName, "%s%s%s", sName, sNum, sFormat);
	if ((fp = fopen(sFileName, "r")) == NULL)
	{
		printf("Look Open Error");
		return;
	}
	else{
		for (int y = 0; y < 64; y++)
		{
			for (int x = 0; x < 64; x++)
			{
				char t;
				fscanf(fp, "%c", &t);
				if (t == '\n')
				{
					sBossLook[BossNum][y][x] = '\n';
					break;
				}
				else
				{
					sBossLook[BossNum][y][x] = t;
				}
			}
		}
	}
	fclose(fp);


}
