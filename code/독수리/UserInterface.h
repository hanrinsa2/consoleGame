#pragma once
int FightSelect = 0;
bool Action_Skill = true; //true면 액션, false면 스킬
void ReDrawFightMenu();
void DrawSkillMenu(stHero* Hero);

void DrawUILayer(stHero* Hero, int nStage){
	SetCurrentCursorPos(0, 21);
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("현재 스테이지 : %d \n", nStage+1);
	printf("★캐릭터 상태★ \n");
	printf("HP : %d \n" , Hero->HP);
	printf("MP : %d \n", Hero->MP);
}
void SelectFightMenu(int nSelect)
{
	switch (nSelect)
	{
	case 0:
		SetCurrentCursorPos(48, 24);
		printf("▶");
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
		printf("▶");
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
		printf("▶");
		SetCurrentCursorPos(78, 24);
		printf("  ");
		break;

	case 3:
		SetCurrentCursorPos(48, 24);
		printf("  ");
		SetCurrentCursorPos(58, 24);
		printf("  ");
		SetCurrentCursorPos(68, 24);
		printf("  ");
		SetCurrentCursorPos(78, 24);
		printf("▶");
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
	printf("스킬1");
	SetCurrentCursorPos(60, 24);
	printf("스킬2");
	SetCurrentCursorPos(70, 24);
	printf("    ");
	SetCurrentCursorPos(80, 24);
	printf("뒤로");
}
void DrawFightMenu(stHero* Hero)
{
	SetCurrentCursorPos(65, 22);
	printf("행동");
	SetCurrentCursorPos(50, 23);
	printf("----------------------------------");
	SetCurrentCursorPos(50,24);
	printf("공격");
	SetCurrentCursorPos(60, 24);
	printf("방어");
	SetCurrentCursorPos(70, 24);
	printf("힐링");
	SetCurrentCursorPos(80, 24);
	printf("스킬");
}
void DrawFightHeroUI(stHero* Hero, int nStage){
	SetCurrentCursorPos(0, 21);
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("★캐릭터 상태★ \n");
	if (Hero->HP <70 && Hero->HP > 40)
		SetColor(6);
	else if (Hero->HP <= 40)
		SetColor(4);
	printf("HP : %d \n", Hero->HP);
	SetColor(7);
	printf("MP : %d \n", Hero->MP);
}

void DrawFightBossUI(stBoss* Boss, int nStage){
	SetCurrentCursorPos(80, 5);
	printf("★보스의 상태★ \n");
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
		case 0:		//공격
			Boss->HP -= Hero->Attack;
			break;
		case 1:		//막기
			Hero->bShieldOn = true;
			Hero->MP -= 20;
			break;
		case 2:		//힐링
			Hero->HP += 30;
			Hero->MP -= 50;
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
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			ReDrawFightMenu();
			DrawFightMenu(Hero);
			Action_Skill = true;
			SelectFightMenu(0);
			break;
		}
	}
}