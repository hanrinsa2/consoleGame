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
		TypedText("이 자가 역병의 원인일 거야..",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(4);
		TypedText("너무 힘이든다.. 빨리 처리해야지..",50);
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
		TypedText("나는 대체 누구와 싸운거지?",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(12);
		TypedText("허상이라니....",50);
		getchar();
		SetColor(7);
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(12);
		TypedText("보이는게 전부가 아니라는 건가..", 50);
		getchar();
		SetColor(7);
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(12);
		TypedText("왜인지 더 엄청난 상대가 숨어 있을 것 같다..", 50);
		getchar();
		SetColor(8);
		system("cls");
		SetCurrentCursorPos(30, 15);
		TypedText("준비한 스토리는 여기까지 입니다...!", 50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		TypedText("앞으로의 이야기는 아직 준비되지 않았습니다. 결말이 아직 안나왔거든요!",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		TypedText("플레이 해주셔서 감사합니다..!",50);
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
		TypedText("어느 날, 마을 앞에 거대한 탑이 하나 우뚝 생겼다.enter",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(14);
		TypedText("그리고 그 이후로, 마을에서 이상한 낌새가 보이기 시작했다.enter",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(20, 15);
		SetColor(7);
		TypedText("사람들이 치매걸린 것 마냥, 말도 안 되는 소리를 하고 다닌다. 우주의 기운..? 미쳤나..?enter",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(13);
		TypedText(".........",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(12);
		TypedText("눈앞에 큰 성이 있다...enter",50);
		getchar();
		system("cls");
		SetCurrentCursorPos(30, 15);
		SetColor(12);
		TypedText("들어가시겠습니까 (Y/N)",50);
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