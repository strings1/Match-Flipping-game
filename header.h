#ifndef _FLIP_H
#define _FLIP_H
typedef struct AXIS
{
	unsigned short x,y;
} axis;
void clearscreen();
int Meniu();
void Memory_Game(short unsigned int difficulty);
void set_stats(unsigned short int difficulty ,int *timer,int *health);
void set_emoji(int a[][10], int mapsize);
void display_game(axis cursor, int i1, int j1, int i2, int j2,int a[][10],int mapsize);
void firstdisplay_game(int a[][10], int mapsize);
#endif