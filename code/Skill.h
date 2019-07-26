#pragma once
void DrawSkillEffect(int nSkillNum);
char SkillEffect[][100][100];
char SkillName[4][20] = {	//0,1,2,3
	{
		"복수"
	},
	{
		"부패"
	},
	{
		"화염"
	},
	{
		"동상"
	}
};
char SkillExplane[][100] = {
	{ "MP 15를 소모하여, 다음 3회의 기본 공격력이 +5 증가한다." },
	{ "MP 20을 소모하여, 보스몬스터를 중독시켜 턴마다 HP를 2 감소시킨다 (총 10턴)" },
	{ "MP 30을 소모하여, 보스몬스터의 HP를 25 감소시킨다." },
	{ "MP 15를 소모하여, 보스몬스터의 모든 공격 데미지가 5 감소한다." }
};
void DrawSkillEffect(int nSkillNum)
{
	switch (nSkillNum)
	{
	case 0:	// 복수
		SetColor(14);
		SetCurrentCursorPos(15, 5);
		printf("           #***+*##%");
		SetCurrentCursorPos(15, 6);
		printf("			*+=====#    %%%	");
		SetCurrentCursorPos(15, 7);
		printf("		      #======%");
		SetCurrentCursorPos(15, 8);
		printf("                 *======#");
		SetCurrentCursorPos(15, 9);
		printf("                  %+=: .:+% %");
		SetCurrentCursorPos(15, 10);
		printf("                   #+=   :*%* #%             % ");
		SetCurrentCursorPos(15, 11);
		printf("                    %*=   .==* %             %");
		SetCurrentCursorPos(15, 12);
		printf("                        *=.   .=%         %*%");
		SetCurrentCursorPos(15, 13);
		printf("                      %%%%+=:   .*%    %=:# %     %");
		SetCurrentCursorPos(15, 14);
		printf("                           + %+.   :+*%#*=.*%   %%%");
		SetCurrentCursorPos(15, 15);
		printf("                              #     #*= .:#%%%%%%%##*%");
		SetCurrentCursorPos(15, 16);
		printf("                                         #*##%##*###%%");
		SetColor(7);
		break;
	case 2:	// 화염
		break;
	}

}