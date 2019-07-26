#pragma once


typedef struct stHero{
	int HP;				//HP
	int MP;				//MP
	int Attack;
	bool KeyState;		// 열쇠를 가지고 있는가?
	COORD Position;		//현재 좌표
	bool bShieldOn;

	bool SkillOn_001;	//스킬 온 유무, 밑에 계속 써내려가면 될둣~

}STHERO;