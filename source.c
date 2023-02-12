#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <Wincon.h>
#include <winuser.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <time.h>
#include <wchar.h>
#include "header.h"
/*
FOREGROUND_BLUE
Text color contains blue.
FOREGROUND_GREEN
Text color contains green.
FOREGROUND_RED
Text color contains red.
FOREGROUND_INTENSITY
Text color is intensified.
BACKGROUND_BLUE
Background color contains blue.
BACKGROUND_GREEN
Background color contains green.
BACKGROUND_RED
Background color contains red.
BACKGROUND_INTENSITY
*/


int Meniu()
{
short unsigned int difficulty;
printf("Welcome to Matchy Card.\n You have to match the cards in order to win.\n ");
printf("Please pick your difficulty:\n");
printf("1 - Easy [No time pressure, No Health, Low High-Score Potential]\n");
printf("2 - Medium [Time, 8 Lives, Mid High-Score Potential]\n");
printf("3 - Hard [Time, 5 Lives, High High-Score Potential]\n");
printf("4 - INSANE [Time, 3 Lives, Best High-Score Potential\n");
printf("################################################################\n");

scanf("%hu",&difficulty);
	
	while (difficulty>4)
	{
	
	printf("I am sorry, that's not a valid difficulty, try again!\n");
	Sleep(450);
	scanf("%hu", &difficulty);
	}

system("CLS");
return difficulty;
}

void Memory_Game(short unsigned int difficulty)
{
	clearscreen();
	int a[10][10];	
	axis cursor;
	short selector=0;
	int health=0;	int i1=-1,j1=-1; 
	int timer=0;	int score=0;
	int seconds;	int i2=-1,j2=-1;
	int mapsize=2*(difficulty)+2; //^2
	cursor.x=cursor.y=0;
	//if(difficulty > 1)
		set_stats(difficulty,&timer, &health);
	
	set_emoji(a, mapsize);
	clock_t before = clock();
	firstdisplay_game(a,mapsize);
	Sleep(1000);
	while(1)
	{
		clock_t passed=clock()-before;
		seconds=passed/1000;
		;
		if (GetAsyncKeyState('W'))
		{
			if (cursor.y > 0)
			{
				
				--cursor.y;
			}
		}

		if (GetAsyncKeyState('A'))
		{
			if (cursor.x > 0)
			{
				--cursor.x;
			}
		}

		if (GetAsyncKeyState('S'))
		{
			if (cursor.y < 10)
			{
				++cursor.y;
			}
		}

		if (GetAsyncKeyState('D'))
		{
			if (cursor.x < 10)
			{
				
				++cursor.x;
			}
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
					if(selector==0)
					{
					i1=cursor.y;
					j1=cursor.x;
					selector=1;
					}

					else
					{
					i2=cursor.y;
					j2=cursor.x;
					selector=0;
					}
		}
		display_game( cursor, i1, j1, i2, j2, a, mapsize);
		if(i2>=0) // Automat si j o sa aiba o val.
		{
			if(a[i1][j1]==a[i2][j2])
			{a[i1][j1]*=-1; //(-)val marcheaza ghicit
				score++;
			a[i2][j2]*=-1;
			i1=j1=i2=j2=-1;}
			else
			{
				health--;
				i1=j1=j2=i2=-1; //Resetez indexii, nu e necesar
			}
			if(score==mapsize*mapsize)
			{
				system("CLS");
				printf("YOU WON!");
				Sleep(1000);
			}

		}

		
					if(difficulty>1)
					{
						printf("\n TIME: %d   HEALTH: %d\n",	timer-seconds,	health);
		if(timer-seconds==0 || health==0)
		{
			Sleep(1000);
			system("CLS");
			printf("YOU LOST :( GAME OVER");
			sleep(1000);
		}

					}
				clearscreen();
		Sleep(200);
	}


}

void clearscreen() //O functie de pe StackOverflow care face system("CLS") mai smooth
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position); // pur si simplu seteaza cursorul consolei la inceputul cmdului
}

void set_stats(unsigned short int difficulty ,int *timer, int *health)
{
	switch(difficulty)
	{
		case 1:
		{
		*timer=999;
		*health=999;
		break;
		}

		case 2:
		{
		*timer=300;
		*health=8;
		break;
		}

		case 3:
		{
			*timer=190;
			*health=5;
			break;
		}

		case 4:
		{
			*timer=100;
			*health=3;
			break;
		}
	}
}

void set_emoji(int a[][10], int mapsize)
{
	srand(time(NULL));
	int i,j,x;
	int emoji[50]={0};
	int select=(mapsize*mapsize)/2; /// in emoji[50] numar de cate ori apare emojiul 'i'
	for(i=0;i<mapsize;i++)
	{
		for(j=0;j<mapsize;j++)
		{
			x=rand()%select;
			while(emoji[x]==2)
			{
				x=rand()%select;
			}
			++emoji[x];
			a[i][j]=x+1;
		}
	}

}
void firstdisplay_game(int a[][10], int mapsize) ///TODO adauga in header asta
{
	int i,j;
	for(i=0;i<mapsize;++i)
	{ printf("\n");
		for(j=0;j<mapsize;++j)
		{
			printf("[%3d ]  ",a[i][j]);
			/*switch(a[i][j])
			{
			case 1:
			{printf("\U0001f602");  break;}

			case 2:
			{printf("🍈");  break;}

			case 3:
			{printf("🍉") ; break;}

			case 4:
			{printf("🍊");  break;}

			case 5:
			{printf("🍋");  break;}

			case 6:
			{printf("🍌");  break;}

			case 7:
			{printf("🍍");  break;}

			case 8:
			{printf("🥭");  break;}

			case 9:
			{printf("🍎");  break;}

			case 10:
			{printf("🍏") ; break;}

			case 11:
			{printf("🍐");  break;}

			case 12:
			{printf("🍑");  break;}

			case 13:
			{printf("🍒");  break;}

			case 14:
			{printf("🍓");  break;}

			case 15:
			{printf("🫐");  break;}

			case 16:
			{printf("🥝");  break;}

			case 17:
			{printf("🍅") ; break;}

			case 18:
			{printf("🫒") ; break;}

			case 19:
			{printf("🥥");  break;}

			case 20:
			{printf("🥑") ; break;}

			case 21:
			{printf("🍆");  break;}

			case 22:
			{printf("🥔");  break;}

			case 23:
			{printf("🥕");  break;}

			case 24:
			{printf("🌽");  break;}

			case 25:
			{printf("🌶️") ; break;}

			case 26:
			{printf("🥬") ; break;}

			case 27:
			{printf("🥒") ; break;}

			case 28:
			{printf("🧅");  break;}

			case 29:
			{printf("🍄") ; break;}

			case 30:
			{printf("🥜");  break;}

			case 31:
			{printf("🥐");  break;}

			case 32:
			{printf("🥯");  break;}

			case 33:
			{printf("🥞");  break;}

			case 34:
			{printf("🧇"); break;}

			case 35:
			{printf("🧀");  break;}

			case 36:
			{printf("🍖");  break;}

			case 37:
			{printf("🍗");  break;}

			case 38:
			{printf("🍟");  break;}

			case 39:
			{printf("🍕"); break;}

			case 40:
			{printf("🌭");  break;}

			case 41:
			{printf("🌮");  break;}

			case 42:
			{printf("🌯");  break;}

			case 43:
			{printf("🥙");  break;}

			case 44:
			{printf("🥚");  break;}

			case 45:
			{printf("🥗");  break;}

			case 46:
			{printf("🍿");  break;}

			case 47:
			{printf("🧈");  break;}

			case 48:
			{printf("🧂");  break;}

			case 49:
			{printf("🥫");  break;}

			case 50:
			{printf("🍜") ; break;}

			case 51:
			{printf("🍝") ; break;}

			case 52:
			{printf("🍠");  break;}

			case 53:
			{printf("🍢");  break;}

			case 54:
			{printf("🍣");  break;}

			case 55:
			{printf("🍤");  break;}

			case 56:
			{printf("🍥");  break;}

			case 57:
			{printf("🍡");  break;}

			case 58:
			{printf("🥟") ; break;}

			case 59:
			{printf("🥠") ; break;}

			case 60:
			{printf("🦪");  break;}

			case 61:
			{printf("🍦");  break;}

			case 62:
			{printf("🍧");  break;}

			case 63:
			{printf("🍨");  break;}

			case 64:
			{printf("🍩");  break;}

			case 65:
			{printf("🍪");  break;}

			case 66:
			{printf("🎂");  break;}

			case 67:
			{printf("🍰");  break;}

			case 68:
			{printf("🧁");  break;}

			case 69:
			{printf("🥧");  break;}

			case 70:
			{printf("🍫"); break;}

			case 71:
			{printf("🍬");  break;}

			case 72:
			{printf("🍭");  break;}

			case 73:
			{printf("🍮");  break;}

			case 74:
			{printf("🍯");  break;}

			case 75:
			{printf("🍼");  break;}

			case 76:
			{printf("🥛");  break;}

			case 77:
			{printf("☕"); break;}

			case 78:
			{printf("🫖");  break;}

			case 79:
			{printf("🍵");  break;}

			case 80:
			{printf("🍶");  break;}

			case 81:
			{printf("🍾");  break;}

			case 82:
			{printf("🍷");  break;}

			case 83:
			{printf("🍸");  break;}

			case 84:
			{printf("🍹");  break;}

			case 85:
			{printf("🍺");  break;}

			case 86:
			{printf("🍻");  break;}

			case 87:
			{printf("🥂");  break;}

			case 88:
			{printf("🥃");  break;}

			case 89:
			{printf("🥤");  break;}

			case 90:
			{printf("🧋");  break;}

			case 91:
			{printf("🧃");  break;}

			case 92:
			{printf("🧉");  break;}

			case 93:
			{printf("🧊");  break;}

			case 94:
			{printf("🥢");  break;}

			case 95:
			{printf("🍽️");  break;}

			case 96:
			{printf("🍴") ; break;}

			case 97:
			{printf("🥄") ; break;}

			case 98:
			{printf("❤️");  break;}

			case 99:
			{printf("✨");  break;}

			case 100:
			{printf("🔥");  break;}
			}*/
		}
	}
	Sleep(5000);
	system("CLS");
}

void display_game(axis cursor, int i1, int j1, int i2, int j2,int a[][10],int mapsize)
{
int i,j;
//printf("%d   %d\n", cursor.x,cursor.y);
for(i=0;i<mapsize;i++)
	{
		for(j=0;j<mapsize;j++)
		{
			if(a[i][j]<0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_INTENSITY);
				printf("[%3d]",a[i][j]*(-1));
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("  ");
			} 
			else if(i1==i && j1==j)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED  | FOREGROUND_INTENSITY);
				printf("[%3d]",a[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("  ");
			}
			else if(i2==i && j2==j)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE  | FOREGROUND_INTENSITY);
				printf("[%3d]",a[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("  ");
				Sleep(300);
			}else
			if(cursor.y==i && cursor.x==j)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED  | BACKGROUND_INTENSITY);
				printf("[ ? ]");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("  ");
			}
			else
			printf("[ ? ]  ");
		}
		printf("\n");
	}
}
