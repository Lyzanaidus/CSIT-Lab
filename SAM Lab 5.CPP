#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
	int r[200],fm=0,bm=0,lm=0,rm=0,d,i,x=15,y=10,x1=5;
	clrscr();
	printf("Enter distanc in steps:");
	scanf("%d",&d);
	printf("Enter seed values r[0] and r[1]:");
	scanf("%d%d",&r[0],&r[1]);
	clrscr();
	for(i=2;i<2*d;i++)
	{
		r[i]=(r[i-1]+r[i-2])%101;
	}
	gotoxy(15,1);
	printf("Start");
	gotoxy(15,2);
	printf("%c",1);
	gotoxy(15+d,1);
	printf("Stop");
	gotoxy(15+d,2);
	printf("%c",2);

	for(i=0;i<2*d;i++)
	{
		gotoxy(x1+3,19);
		printf("%d",r[i]);
		if(r[i]<=50)
		{
			fm=fm+1;
			gotoxy(x,y);
			printf("%c",16);
			x=x+1;
			delay(100);
		}
		else if(r[i]<=75)
		{
			bm=bm+1;
			x=x-1;
			gotoxy(x,y);
			printf("%c",17);
			delay(100);
		}
		else if(r[i]<=90)
		{
			lm=lm+1;
			y=y-1;
			gotoxy(x,y);
			printf("%c",30);
			delay(100);
		}
		else
		{
			rm=rm+1;
			y=y+1;
			gotoxy(x,y);
			printf("%c",31);
			delay(100);
		}
	}
	gotoxy(5,22);
	printf("No. of Forward Movement: %d\tNo. of Backward Movement: %d",fm,bm);
	gotoxy(5,23);
	printf("No. of Left Movement: %d\tNo. of Right Movement: %d",lm,rm);
	if((fm-bm==d)&&(lm==rm))
	{
		gotoxy(5,24);
		printf("The person reaches his destination.");
	}
	else
	{
		gotoxy(5,24);
		printf("The person does not reach his destination.");
	}
	getch();
}
