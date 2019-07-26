#pragma once
char sBossLook[3][64][64] = {

};

typedef struct stBoss{
	int HP;				//HP
	int MP;				//MP
	int nBossNum;		//보스의 넘버
	bool bShiledOn;

	bool SkillOn_001;
	bool SkillOn_002;


}STBOSS;
void BossPattern(stBoss* Boss, stHero* Hero)
{
	
	if (Boss->nBossNum == 0)	//1스테이지 보스 패턴
	{
		if (Boss->MP - 50 >= 0 && Boss->HP < 40)
		{
			if ((rand() % 1 == 0) && Boss->MP == 50)	//피 30깎는 스킬 50퍼 확률로 사용
			{
				if (Hero->bShieldOn == false)
				{
					Hero->HP -= 30;
					Boss->MP -= 50;
				}
				else
				{
					Hero->bShieldOn = false;
					Hero->MP += 40;
				}
			}
			else
			{
				Boss->HP += 30;
				Boss->MP -= 50;
			}
		}
		else
		{
			Hero->HP -= 10;
		}
	}

}
void OpenBossLook(int BossNum){
	FILE *fp;
	char sName[5] = "Boss";
	char sNum[2];
	_itoa(BossNum, sNum,10);
	char sFormat[5] = ".txt";
	char sFileName[20];
	sprintf(sFileName,"%s%s%s", sName, sNum, sFormat);
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
				fscanf(fp, "%c",&t);
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

	for (int y = 0; y < 21; y++)
	{
		for (int x = 0; x < 64; x++)
		{
				printf("%c", sBossLook[BossNum][y][x]);
		}
	}
}
