#pragma once
void TypedText(char* lines,int time);


void TypedText(char* lines, int time)
{

	for (int i = 0; i < strlen(lines); i++)
	{
		printf("%c", lines[i]);
		Sleep(time);
	}

}
bool DrawEndingStory()
{
	while (1)
	{
		SetCurrentCursorPos(30, 15);
		SetColor(4);
		TypedText("�� �ڰ� ������ ������ �ž�..",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(4);
		TypedText("�ʹ� ���̵��.. ���� ó���ؾ���..",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(12);
		TypedText("?????????????!!!!!!!!!!!",25);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(7);
		TypedText(".........",25);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(7);
		TypedText("���� ��ü ������ �ο����?",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(12);
		TypedText("����̶��....",50);
		getchar();
		SetColor(7);
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(12);
		TypedText("���̴°� ���ΰ� �ƴ϶�� �ǰ�..", 50);
		getchar();
		SetColor(7);
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(12);
		TypedText("������ �� ��û�� ��밡 ���� ���� �� ����..", 50);
		getchar();
		SetColor(8);
		system("cls");
		SetCurrentCursorPos(30, 15);
		TypedText("�غ��� ���丮�� ������� �Դϴ�...!", 50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		TypedText("�������� �̾߱�� ���� �غ���� �ʾҽ��ϴ�. �ḻ�� ���� �ȳ��԰ŵ��!",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		TypedText("�÷��� ���ּż� �����մϴ�..!",50);
		getchar();
		return true;
	}

}
bool DrawStartStory()
{
	while (1)
	{
		SetCurrentCursorPos(30, 15);
		SetColor(14);
		TypedText("��� ��, ���� �տ� �Ŵ��� ž�� �ϳ� ��� �����.enter",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(14);
		TypedText("�׸��� �� ���ķ�, �������� �̻��� ������ ���̱� �����ߴ�.enter",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(20, 15);
		SetColor(7);
		TypedText("������� ġ�Űɸ� �� ����, ���� �� �Ǵ� �Ҹ��� �ϰ� �ٴѴ�. ������ ���..? ���Ƴ�..?enter",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(13);
		TypedText(".........",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(12);
		TypedText("���տ� ū ���� �ִ�...enter",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(12);
		TypedText("���ðڽ��ϱ� (Y/N)",50);
		SetColor(7);
		switch (getchar())
		{
		case 'Y':
			return true;
			break;
		case 'N':
			return false;
			break;
		case 'y':
			return true;
			break;
		case 'n':
			return false;
			break;
		default:
			continue;
		}
	


	}
}