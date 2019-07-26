#pragma once
int FightSelect = 0;
int nUISTAGE = 0;
bool Action_Skill = true; //true�� �׼�, false�� ��ų
void ReDrawFightMenu();
void DrawSkillMenu(stHero* Hero);


void DrawUILayer(stHero* Hero, int nStage){
	SetCurrentCursorPos(0, 21);
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("���� �������� : %d \n", nStage+1);
	printf("��ĳ���� ���¡� \n");
	printf("HP : %d \n" , Hero->HP);
	printf("MP : %d \n", Hero->MP);

}
void SelectFightMenu(int nSelect)
{
	switch (nSelect)
	{
	case 0:
		SetCurrentCursorPos(48, 24);
		printf("��");
		SetCurrentCursorPos(58, 24);
		printf("  ");
		SetCurrentCursorPos(68, 24);
		printf("  ");
		SetCurrentCursorPos(78, 24);
		printf("  ");
		break;
	case 1:
		SetCurrentCursorPos(48, 24);
		printf("  ");
		SetCurrentCursorPos(58, 24);
		printf("��");
		SetCurrentCursorPos(68, 24);
		printf("  ");
		SetCurrentCursorPos(78, 24);
		printf("  ");
		break;
	case 2:
		SetCurrentCursorPos(48, 24);
		printf("  ");
		SetCurrentCursorPos(58, 24);
		printf("  ");
		SetCurrentCursorPos(68, 24);
		printf("��");
		SetCurrentCursorPos(78, 24);
		printf("  ");
		break;

	case 3:
		if (Action_Skill)
		{
			SetCurrentCursorPos(48, 24);
			printf("  ");
			SetCurrentCursorPos(58, 24);
			printf("  ");
			SetCurrentCursorPos(68, 24);
			printf("  ");
			SetCurrentCursorPos(78, 24);
			printf("��");
		}
		break;
	}
}
void ReDrawFightMenu()
{
	SetCurrentCursorPos(65, 22);
	printf("          ");
	SetCurrentCursorPos(50, 23);
	printf("----------------------------------");
	SetCurrentCursorPos(50, 24);
	printf("          ");
	SetCurrentCursorPos(60, 24);
	printf("          ");
	SetCurrentCursorPos(70, 24);
	printf("          ");
	SetCurrentCursorPos(80, 24);
	printf("          ");
}
void DrawSkillMenu(stHero* Hero)
{
	SetCurrentCursorPos(65, 22);
	printf("SKILL");
	SetCurrentCursorPos(50, 23);
	printf("----------------------------------");
	SetCurrentCursorPos(50, 24);
	printf("%s",Hero->haveSKill[0]);
	SetCurrentCursorPos(60, 24);
	printf("%s",Hero->haveSKill[1]);
	SetCurrentCursorPos(70, 24);
	printf("�ڷ�");
	SetCurrentCursorPos(80, 24);
	printf("    ");
}
void DrawFightMenu(stHero* Hero)
{
	SetCurrentCursorPos(65, 22);
	printf("�ൿ");
	SetCurrentCursorPos(50, 23);
	printf("----------------------------------");
	SetCurrentCursorPos(50,24);
	printf("����");
	SetCurrentCursorPos(60, 24);
	printf("���");
	SetCurrentCursorPos(70, 24);
	printf("����");
	SetCurrentCursorPos(80, 24);
	printf("��ų");
}
void DrawFightHeroUI(stHero* Hero, int nStage){
	nUISTAGE = nStage;
	SetCurrentCursorPos(0, 21);
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("��ĳ���� ���¡� \n");
	if (Hero->HP <70 && Hero->HP > 40)
		SetColor(6);
	else if (Hero->HP <= 40)
		SetColor(4);
	printf("HP : %d \n", Hero->HP);
	SetColor(7);
	printf("MP : %d \n", Hero->MP);

	if (Hero->bShieldOn == true)
	{
		
		SetColor(6);
		printf("���� ON ���� ���� ���, ���ݷ��� -2 �������ϴ�.     \n ��ų�� ����ϸ� MP�� 30 �����մϴ�.\n");
		SetColor(7);
	}
	if (Hero->bBuffOn == true)
	{
		SetColor(14);
		printf("Ÿ������ ���� Ȱ��ȭ. 3�ϵ��� �⺻ ���ݷ��� +5 �˴ϴ�. \n");
		SetColor(7);
	}
	else{
		printf("                                                                                                                                          ");
		printf("                                                                                                                                          ");
		printf("                                                                                                                                          ");
		printf("                                                                                                                                          ");
	}
	if (Hero->HP <= 0)
	{
		Hero->bHeroDead = true;
	}
}

void DrawFightBossUI(stBoss* Boss, int nStage){
	SetCurrentCursorPos(80, 5);
	printf("�ں����� ���¡� \n");
	SetCurrentCursorPos(80, 6);
	if (Boss->HP <70 && Boss->HP > 40)
		SetColor(6);
	else if (Boss->HP <= 40)
		SetColor(4);
	printf("HP : %d \n", Boss->HP);
	SetCurrentCursorPos(80, 7);
	SetColor(7);
	printf("MP : %d \n", Boss->MP);
}
void DecideSelect(int FightSelect, stBoss* Boss, stHero* Hero)
{
	if (Action_Skill)
	{
		switch (FightSelect)
		{
		case 0:		//����
			if (Hero->bShieldOn == true)
			{
				BossMinusHP((Hero->Attack - 2),12);
				Boss->HP -= Hero->Attack - 2;
				SetColor(8);
				SetCurrentCursorPos(0, 0);
				DrawBossLook(Boss->nBossNum);
				Sleep(150);
				SetCurrentCursorPos(0, 0);
				SetColor(7);
				DrawBossLook(Boss->nBossNum);
			}
			else if (Hero->bBuffOn == true)
			{
				BossMinusHP((Hero->Attack ), 12);
				Boss->HP -= Hero->Attack;
				SetColor(12);
				SetCurrentCursorPos(0, 0);
				DrawBossLook(Boss->nBossNum);
				Sleep(150);
				SetCurrentCursorPos(0, 0);
				SetColor(7);
				DrawBossLook(Boss->nBossNum);
				Hero->nBuffCount++;
				if (Hero->nBuffCount >= 3)
				{
					Hero->bBuffOn = false;
					Hero->Attack -= 5;
					Hero->nBuffCount = 0;
				}
			}
			else
			{
				BossMinusHP((Hero->Attack), 12);
				Boss->HP -= Hero->Attack;
				SetColor(14);
				SetCurrentCursorPos(0, 0);
				DrawBossLook(Boss->nBossNum);
				Sleep(150);
				SetCurrentCursorPos(0, 0);
				SetColor(7);
				DrawBossLook(Boss->nBossNum);
			}
			PlaySound(NULL, 0, 0);
			PlaySound(TEXT("Sound/�⺻����.wav"), NULL, SND_ASYNC | SND_NOSTOP);
			break;
		case 1:		//����
			if (Hero->MP >= 10)
			{
				Hero->bShieldOn = true;
				Hero->MP -= 20;
				UseMP(20);
				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("Sound/����.wav"), NULL, SND_ASYNC | SND_NOSTOP);
			}
			break;
		case 2:		//����
			if (Hero->MP >= 15)
			{
				Hero->HP += 20;
				Hero->MP -= 15;
				UseMP(15);
				SetColor(10);
				SetCurrentCursorPos(10, 23);
				printf("+20");
				Sleep(300);
				SetCurrentCursorPos(10, 23);
				SetColor(7);
				printf("     ");
				
				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("Sound/����.wav"), NULL, SND_ASYNC | SND_NOSTOP);
			}
			break;
		case 3:
			ReDrawFightMenu();
			DrawSkillMenu(Hero);
			Action_Skill = false;
			SelectFightMenu(0);

			break;
		}
	}
	else
	{
		switch (FightSelect)
		{
		case 0:
			if (strcmp(Hero->haveSKill[0], "����") == 0)
			{
				Hero->Attack += 5;
				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("Sound/Ÿ�����º���.wav"), NULL, SND_ASYNC | SND_NOSTOP);
				UseMP(15);
				Hero->bBuffOn = true;
				Hero->MP -= 15;
			}
			else if (strcmp(Hero->haveSKill[0], "����") == 0)
			{
				if (Hero->MP - 20 >= 0)
				{
					PlaySound(NULL, 0, 0);
					PlaySound(TEXT("Sound/����������.wav"), NULL, SND_ASYNC | SND_NOSTOP);
					UseMP(20);
					Boss->bPoisonOn = true;
					Hero->MP -= 20;
				}
			}
			else if (strcmp(Hero->haveSKill[0], "ȭ��") == 0)
			{
				if (Hero->bFireCheck == false)
				{
					PlaySound(NULL, 0, 0);
					PlaySound(TEXT("Sound/ȭ���ĵ�.wav"), NULL, SND_ASYNC | SND_NOSTOP);
					UseMP(30);
					SetCurrentCursorPos(0, 0);
					SetColor(12);
					DrawBossLook(Boss->nBossNum);
					Sleep(100);
					SetCurrentCursorPos(0, 0);
					SetColor(13);
					DrawBossLook(Boss->nBossNum);
					Sleep(100);
					SetCurrentCursorPos(0, 0);
					SetColor(7);
					DrawBossLook(Boss->nBossNum);
					BossMinusHP(25, 12);
					Boss->HP -= 25;
					Hero->MP -= 30;
					DrawFightBossUI(Boss, nUISTAGE);
					Hero->bFireCheck = true;
				}
			}
			else if (strcmp(Hero->haveSKill[0], "����") == 0)
			{
				if (Hero->MP - 15 >= 0)
				{
					PlaySound(NULL, 0, 0);
					PlaySound(TEXT("Sound/����ȭ����.wav"), NULL, SND_ASYNC | SND_NOSTOP);
					UseMP(15);
					Boss->bFreezeOn = true;
					SetCurrentCursorPos(0, 0);
					SetColor(9);
					DrawBossLook(Boss->nBossNum);
					SetColor(7);
					Hero->MP -= 15;
				}
			}
			break;
		case 1:
			if (strcmp(Hero->haveSKill[1], "����") == 0)
			{
				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("Sound/Ÿ�����º���.wav"), NULL, SND_ASYNC | SND_NOSTOP);
				UseMP(15);
				Hero->bBuffOn = true;
				Hero->MP -= 15;
			}
			else if (strcmp(Hero->haveSKill[1], "����") == 0)
			{
				if (Hero->MP - 20 >= 0)
				{
					PlaySound(NULL, 0, 0);
					PlaySound(TEXT("Sound/����������.wav"), NULL, SND_ASYNC | SND_NOSTOP);
					UseMP(20);
					Boss->bPoisonOn = true;
					Hero->MP -= 20;
				}
			}
			else if (strcmp(Hero->haveSKill[1], "ȭ��") == 0)
			{
				if (Hero->bFireCheck == false)
				{
					PlaySound(NULL, 0, 0);
					PlaySound(TEXT("Sound/ȭ���ĵ�.wav"), NULL, SND_ASYNC | SND_NOSTOP);
					UseMP(30);
					SetCurrentCursorPos(0, 0);
					SetColor(12);
					DrawBossLook(Boss->nBossNum);
					Sleep(100);
					SetCurrentCursorPos(0, 0);
					SetColor(13);
					DrawBossLook(Boss->nBossNum);
					Sleep(100);
					SetCurrentCursorPos(0, 0);
					SetColor(7);
					DrawBossLook(Boss->nBossNum);
					BossMinusHP(25, 12);
					Boss->HP -= 25;
					Hero->MP -= 30;
					Hero->bFireCheck = true;
				}
			}
			else if (strcmp(Hero->haveSKill[1], "����") == 0)
			{
				if (Hero->MP - 15 >= 0)
				{
					PlaySound(NULL, 0, 0);
					PlaySound(TEXT("Sound/����ȭ����.wav"), NULL, SND_ASYNC | SND_NOSTOP);
					UseMP(15);
					Boss->bFreezeOn = true;
					SetCurrentCursorPos(0, 0);
					SetColor(9);
					DrawBossLook(Boss->nBossNum);
					SetColor(7);
					Hero->MP -= 15;
				}
			}
			break;
		case 2:
			ReDrawFightMenu();
			DrawFightMenu(Hero);
			Action_Skill = true;
			SelectFightMenu(2);
			break;
		}
		DrawFightHeroUI(Hero, nUISTAGE);
	}
}