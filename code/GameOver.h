#pragma once

bool DrawGameOver()
{
	fflush(stdin);
	system("cls");
	SetCurrentCursorPos(40, 1);
	SetColor(12);
	printf("����ΰ� ����Ͽ����ϴ�.\n");
	SetColor(14);
	printf("�ٽ� ����� �Ͻðڽ��ϱ�? (Y/N)");
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
			printf("Y Ȥ�� N���� �ٽ� �Է�");
			SetColor(7);
			SetCurrentCursorPos(40, 2);
			break;
		}
	}
	
}