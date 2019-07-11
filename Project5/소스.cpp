#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define max_x 50
#define max_y 28

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void resizeConsol()
{
	char chtemp[50];
	sprintf(chtemp, "Mode con cols=%d lines=%d", max_x, max_y);
	system(chtemp);
}
void printbound()
{
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x += 2) {
			if (y == 0 || y == max_y - 1 || x == 0 || x == max_x - 2) printf("★");
			else printf("  ");
		}
	}
}
void initcursor()
{
	CONSOLE_CURSOR_INFO cursorinfo = { 0, };
	cursorinfo.dwSize = 1;
	cursorinfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo);
}
int main()
{
	system("title studyScience");
	initcursor();
	resizeConsol();
	printbound();
	gotoxy(12, 4);
	printf("<결합 종류 파악 프로그램>");
	gotoxy(11, 7);
	printf("결합의 종류를 파악하고 싶은");
	gotoxy(11, 9);
	printf("분자의 화학식을 적어 주세요.");
	gotoxy(11, 15);
	printf("(                          )");
	gotoxy(20, 15);
	char a[100];
	int len = 0;
	char list[20][3] = { "H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca" };
	int num[20] = { 0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1 };
	scanf("%s", a);
	len = strlen(a);
	int check[2] = { 0 }, i, j;
	for (i = 0; i < len; i++) {
		if (a[i] >= 65 && a[i] <= 90) {
			int cnt = 0;
			char s[3] = { 0 };
			s[0] = a[i];
			if (a[i + 1] >= 97 && a[i + 1] <= 122) s[1] = a[i + 1];
			for (j = 0; j < 20; j++) {
				if (strcmp(s, list[j]) == 0) {
					check[num[j]] = 1;
					break;
				}
			}
			if (j == 20) {
				gotoxy(10, 20);
				printf("해당 원소는 주기율표 20번째 안에");
				gotoxy(10, 21);
				printf("포함되지 않거나 존재하지 않습니다.");
				char q;
				scanf(" %c",&q);
				return 0;
			}
		}
	}
	if (check[0] && check[1]) {
		gotoxy(10, 20);
		printf("해당 분자식은 이온결합입니다.");
	}
	else if (check[0]) {
		gotoxy(10, 20);
		printf("해당 분자식은 공유결합입니다.");
	}
	else if (check[1]) {
		gotoxy(10, 20);
		printf("해당 분자식은 금속결합입니다.");
	}
	char q;
	scanf(" %c",&q);
	return 0;
}