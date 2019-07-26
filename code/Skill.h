#pragma once
void DrawSkillEffect(int nSkillNum);
char SkillEffect[][100][100];
char SkillName[4][20] = {	//0,1,2,3
	{
		"����"
	},
	{
		"����"
	},
	{
		"ȭ��"
	},
	{
		"����"
	}
};
char SkillExplane[][100] = {
	{ "MP 15�� �Ҹ��Ͽ�, ���� 3ȸ�� �⺻ ���ݷ��� +5 �����Ѵ�." },
	{ "MP 20�� �Ҹ��Ͽ�, �������͸� �ߵ����� �ϸ��� HP�� 2 ���ҽ�Ų�� (�� 10��)" },
	{ "MP 30�� �Ҹ��Ͽ�, ���������� HP�� 25 ���ҽ�Ų��." },
	{ "MP 15�� �Ҹ��Ͽ�, ���������� ��� ���� �������� 5 �����Ѵ�." }
};
void DrawSkillEffect(int nSkillNum)
{
	switch (nSkillNum)
	{
	case 0:	// ����
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
	case 2:	// ȭ��
		break;
	}

}