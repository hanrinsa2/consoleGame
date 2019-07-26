#pragma once

bool DrawGameOver()
{
	fflush(stdin);
	system("cls");
	SetCurrentCursorPos(40, 1);
	SetColor(12);
	printf("히어로가 사망하였습니다.\n");
	SetColor(14);
	printf("다시 재시작 하시겠습니까? (Y/N)");
	SetColor(7);
	while (1)
	{
		
		switch (getchar())
		{
		case 'y':
			return true;
			break;
		case 'Y':
			return true;
			break;
		case 'n':
			return false;
			break;
		case 'N':
			return false;
			break;
		default:
			SetCurrentCursorPos(40, 6);
			SetColor(12);
			printf("Y 혹은 N으로 다시 입력");
			SetColor(7);
			SetCurrentCursorPos(40, 2);
			break;
		}
	}
	
}