#pragma once


typedef struct stHero{
	int HP;				//HP
	int MP;				//MP
	int Attack;
	bool KeyState;		// ���踦 ������ �ִ°�?
	COORD Position;		//���� ��ǥ
	bool bShieldOn;

	bool SkillOn_001;	//��ų �� ����, �ؿ� ��� �᳻������ �ɵ�~

}STHERO;