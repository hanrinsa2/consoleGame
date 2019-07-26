#pragma once

void SetCurrentCursorPos(int x, int y)
{
	COORD Temp = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Temp);
}
COORD GetCurrentCursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO curInfo;      // structure included in windows.h
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	COORD Temp = { curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y };
	return Temp;
}
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}