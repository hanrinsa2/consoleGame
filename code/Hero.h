#pragma once


typedef struct stHero{
	int HP;				//HP
	int MP;				//MP
	int Attack;
	int nBuffCount;
	bool KeyState;		// 열쇠를 가지고 있는가?
	COORD Position;		//현재 좌표
	bool bShieldOn;
	bool bHeroDead;
	bool bBuffOn;
	bool bFireCheck;

	char haveSKill[2][20];

}STHERO;
void MinusHP(int Num)
{
	SetColor(12);
	SetCurrentCursorPos(10, 23);
	if (Num > 0)
		printf("-%d", Num);
	else
		printf("+%d", abs(Num));
	Sleep(300);
	SetCurrentCursorPos(10, 23);
	SetColor(7);
	printf("     ");
}
void UseMP(int Num)
{
	SetColor(11);
	SetCurrentCursorPos(10, 24);
	printf("-%d", Num);
	Sleep(300);
	SetCurrentCursorPos(10, 24);
	SetColor(7);
	printf("     ");
}