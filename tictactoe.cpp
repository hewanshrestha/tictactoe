#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
struct Game
{
	int i;
	char ch;
};
struct Game inputValue(char[],int);

void restart();

void run();

void Display(char[]);

int check(char[],char,int);

int main()
{
	char option;
	int i;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\tLoading.........\n");
	for(i=0;i<120;i++)
	{
		printf("%c",221);
		Sleep(10);
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t1.Play TicTacToe\n");
	printf("\t\t\t2.Exit");
	printf("\n\n\t\t\tENter your choice:");
	scanf("%d",&option);
	system("cls");
	switch(option)
	{
		case 1:
			restart();
		case 2:
			exit(0);
		default:
			printf("\nInvalid Option!!!\n");
			break;
	}
	
	
}
void restart()
{
	int reStart;
	again:
	run();
	printf("\n\t\tDo you want to play again?\n\t\tPress 1 to continue the game:  ");
	scanf("%d",&reStart);
	if(reStart==1)
	{
		system("cls");
		goto again;
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\tGame Over!!!!!\n\n\n\n\n\n\n\n\n\n");
		exit(0);
	}
}
void run()
{
	int count=0;
	struct Game game;
	char symbol[9]={'1','2','3','4','5','6','7','8','9'};
	Display(symbol);
	again:
	game=inputValue(symbol,count);
	symbol[game.i]=game.ch;
	system("cls");
	Display(symbol);
	if(check(symbol,game.ch,count)==1);
	else
	{
		count++;
		goto again;
	}
}
int check(char sym[9],char ch,int count)
{
	int i;
	for(i=0;i<=6;i+=3)
	{
		if(sym[i]==ch && sym[i+1]==ch && sym[i+2]==ch)
		{
			printf("\n\n\n\t\tThe Winner is:%c\n",ch);
			return 1;
		}
	}
	for(i=0;i<3;i++)
	{
		if(sym[i]==ch && sym[i+3]==ch && sym[i+6]==ch)
		{
			printf("\n\n\n\t\tThe Winner is:%c\n",ch);
			return 1;
		}
	}
	if(sym[0]==ch && sym[4]==ch && sym[8]==ch)
	{
		printf("\n\n\n\t\tThe Winner is:%c\n",ch);
		return 1;
	}
	else if(sym[2]==ch && sym[4]==ch && sym[6]==ch)
	{
		printf("\n\n\n\t\tThe Winner is:%c\n",ch);
		return 1;
	}
	else if(count==8)
	{
		printf("\n\n\n\t\tNot valid!!!\n");
		return 1;
	}
	else
		return 0;
}

struct Game inputValue(char sym[9],int count)
{
	char value;
	int i;
	struct Game game;
	inputAgain:
	if(count%2==0)
	{
		printf("\n\nEnter the position for X:");
	}
	else
	{
		printf("\n\nEnter the position for O:");
	}
	scanf("%s",&value);
	for(i=0;i<9;i++)
	{
		if(value==sym[i])
		{
			game.i=i;
			if(count%2==0)
				game.ch='X';
			else
				game.ch='O';
			break;
		}
		else
		{
			game.i=-1;
			game.ch=' ';
		}
	}
	if(game.i==-1)
	{
		printf("\nInvalid!!!!\n");
		goto inputAgain;
	}
	return game;
}
void Display(char sym[9])
{
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\tTic Tac Toe Game:\n");
	printf("\t\tPlayer 1: Symbol X\n");
	printf("\t\tPlayer 2: Symbol O");
	printf("\n\n\t\t\t\t        |        |       ");
	printf("\n\t\t\t\t    %c   |    %c   |    %c   ",sym[0],sym[1],sym[2]);
	printf("\n\t\t\t\t--------|--------|--------");
	printf("\n\t\t\t\t    %c   |    %c   |    %c   ",sym[3],sym[4],sym[5]);
	printf("\n\t\t\t\t--------|--------|--------");
	printf("\n\t\t\t\t    %c   |    %c   |    %c   ",sym[6],sym[7],sym[8]);
	printf("\n\t\t\t\t        |        |       ");
}
