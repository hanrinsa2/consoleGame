#pragma once

void DrawReward(stHero* Hero, stBoss* Boss, int* nStage, int* nScene)
{
	int nNum;
	system("cls");
	SetCurrentCursorPos(40, 1);
	SetColor(14);
	printf("%d Stage Boss Clear !!!!\n",*nStage+1);
	SetCurrentCursorPos(47, 2);
	printf("Reward\n");
	SetColor(7);
	SetCurrentCursorPos(35, 3);
	printf("���Ͻô� ��ų��ȣ�� �Է����ּ���\n");
	for (int i = 0; i < 4; i++)
	{
		SetCurrentCursorPos(15, 6+i);
		printf("%d. %s : %s", i+1, SkillName[i], SkillExplane[i]);
		printf("\n");
	}
	SetCurrentCursorPos(19, 13);
	printf("��ų��ȣ �Է� : ");
	scanf("%d", &nNum);
	if (nNum == 2 || nNum == 3 || nNum == 4 || nNum == 1)
	{
		strcpy(Hero->haveSKill[*nStage], SkillName[nNum - 1]);
	}
	*nScene = 1;
}