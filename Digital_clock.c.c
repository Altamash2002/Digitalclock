#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include<windows.h>
#include<time.h>
#define TRUE 1
int SHhrs=999,SHmin=999,SHsec=999;
COORD coord={0,0};
void gotoxy(int x,int y)
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
} 
void zero(int x,int y);
void one(int x,int y); 
void two(int x,int y);
void three(int x,int y);         
void four(int x,int y);
void five(int x,int y);
void six(int x,int y);
void seven(int x,int y);       
void eight(int x,int y);
void nine(int x,int y);
void colon(int x,int y);
void call(int digit,int x,int y);
void getTime();
void getstopwatch();
void getcountdown();
void getuserinput();
void getshutdown();
void countdown_shutdown();
void realtime_shutdown();

void takeTime(int hour,int minute,int second);

int main(void)
{   system("CLS");
int option;
do
{ 
	fflush(stdin);
	system("CLS");
	printf("\n *****MAIN MENU*****");
    printf("\n 1.REALTIME WATCH");
	printf("\n 2.USER TIME WATCH");
	printf("\n 3.COUNTDOWN");
	printf("\n 4.STOPWATCH");
	printf("\n 5.SHUTDOWN");
	printf("\n 6.EXIT\n");
	printf("\n Enter your option: ");
	scanf("%d", &option);
	switch(option)
	{
	case 1:
    while(!_kbhit())
	{
    getTime();
	} 
	break;
  case 2:
		getuserinput();
		break;
  case 3:
			getcountdown();
	
		break;
    case 4:
   		 	getstopwatch();
 			break;
 	case 5:
 		while(1)
 		{
 			getshutdown();
		}
 		break;
 	case 6:
	{
		exit(0);
	}
	break;


}
}
while(option != 6);
}

 void getuserinput()
{
   	int hour;
		int minute;
		int second;
		printf("Enter the hour from 0 to 24\n");
		scanf("%d",&hour);
		printf("Enter the minute from 0 to 60\n");
		scanf("%d",&minute);
		printf("Enter the second from 0 to 60\n");
		scanf("%d",&second);
		fflush(stdin);
if(hour<24 && minute<60 && second<60)
{
while(!_kbhit())
{

	for(hour;hour<24;hour++)
	{
		for(minute;minute<60;minute++)
		{
			for(second;second<60;second++)
			{
				
			takeTime(hour,minute,second);
            Sleep(945);
//            if(hour==SHhrs&&minute==SHmin&&second==SHsec)
//    		{
//    			printf("SHUTTING DOWN");
//    			getshutdown();
//    			if(_kbhit())
//    			{
//    				break;
//				}
//			}
			if(_kbhit())
    			{
    				break;
				}
             
			}
			second=0;
			if(_kbhit())
    			{
    				break;
				}
			}
		minute=0;
		if(_kbhit())
    			{
    				break;
				}
	}
	hour=0;
}}
    else
    {
    	printf("Enter Correct Time Format in HH<24 : MM<60 : SS<60 \n");
    	system("pause"); 
	}
}

void takeTime(int hour,int minute,int second)
{ 
	call(hour/10,40,18);
    call(hour%10,50,18);
    colon(60,18);
    call(minute/10,70,18);
    call(minute%10,80,18);
    colon(90,18);
    call(second/10,100,18);
    call(second%10,110,18);

}
void getshutdown()
{
  int a;
	do{
	printf("\n SET SHUTDOWN WITH");
	printf("\n\ 1.COUNTDOWN TIME");
	printf("\n\ 2.REAL TIME\n");
	printf("\nPLEASE ENTER YOUR CHOICE!\n");
	scanf("%d",&a);
	
	switch(a)
	{
		case 1:
			system("CLS");
			countdown_shutdown();
			break;
		case 2:
			system("CLS");
			realtime_shutdown();
			break;
}
}while(a!=2);
} 

void realtime_shutdown()
{
	int wh_shutdown;
	int sh_hour;
	int sh_minute;
	int sh_second;
	int corrupt;
	do{
	printf("ENTER THE TIME AT WHICH YOU HAVE TO SHUTDOWN!\n");
	printf("Enter the hour from 0 to 24\n");
	scanf("%d",&sh_hour);
	printf("Enter the minute from 0 to 60\n");
	scanf("%d",&sh_minute);
	printf("Enter the second from 0 to 60\n");
	scanf("%d",&sh_second); 
	if(sh_hour>23||sh_minute>59||sh_second>59)
	{
	corrupt=1;
	printf("ENTER CORRECT TIME");
	system("CLS");
	} 
	else
	{
	corrupt=0;
	}
    }while(corrupt==1);
	printf("\n1.DIALOG BOX FOR SHUTDOWN");
	printf("\n2.DIRECT SHUTDOWN\n");
	scanf("%d",&wh_shutdown); 
	while(TRUE)
	{
	time_t s;
    struct tm *curtime;
    s=time(NULL);
    curtime=localtime(&s);
    int hour=0;
    int minute=0;
    int second=0;
    hour =curtime->tm_hour;
	minute =curtime->tm_min;
	second =curtime->tm_sec;    
                                                  
    call(hour/10,40,18);
    call(hour%10,50,18);
    colon(60,18); 
    call(minute/10,70,18); 
    call(minute%10,80,18);
    colon(90,18);
    call(second/10,100,18);
    call(second%10,110,18);
    Sleep(945);
    if(hour==sh_hour&&minute==sh_minute&&second==sh_second){
    	break;
	}
    } 
    	if(wh_shutdown==1)
		{
			system("c:\\windows\\system32\\shutdown -i");
			exit(0);
		}
		else if(wh_shutdown==2)
		{
			system("c:\\windows\\system32\\shutdown -s");
			exit(0);
		}
    
}

void countdown_shutdown()
{
	int wh_shutdown;
	int hour=0;
    int minute=0;
    int second=0;
   
	printf("Enter the time in HH:MM:SS :\n");
	scanf("%d%d%d",&hour,&minute,&second);
	printf("\n1.DIALOG BOX");
	printf("\n2.DIRECT SHUTDOWN\n");
	scanf("%d",&wh_shutdown);
	while(1) 
	{
					
    call(hour/10,40,18);
    call(hour%10,50,18);
    colon(60,18);
    call(minute/10,70,18);
    call(minute%10,80,18);
    colon(90,18);
    call(second/10,100,18);
    call(second%10,110,18);
    
	Sleep(945); 
	if(second!=0)
	{
		second--;
	}
	if(second==0 && minute!=0)
	{
		second=59;
		minute--;
	}
	if(second==0 && minute==0 && hour!=0)
	{
		hour--;
		minute=59;
		second=59;
	}
	if(hour==0 && minute==0 && second==0)
	{
		if(wh_shutdown==1)
		{
			system("c:\\windows\\system32\\shutdown -i");
			exit(0);
		}
		else if(wh_shutdown==2)
		{
			system("c:\\windows\\system32\\shutdown -s");
			exit(0);
		}
		
	} 
	}
}

void getcountdown()
{   int hour=0;
    int minute=0;
    int second=0;
   
	printf("Enter the time in HH:MM:SS :\n");
	scanf("%d%d%d",&hour,&minute,&second);
	while(!_kbhit())  
	{
					
    call(hour/10,40,18);
    call(hour%10,50,18);
    colon(60,18);
    call(minute/10,70,18);
    call(minute%10,80,18);
    colon(90,18);
    call(second/10,100,18);
    call(second%10,110,18);
    
	Sleep(945); 
	if(second!=0)
	{
		second--;
	}
	if(second==0 && minute!=0)
	{
		second=59;
		minute--;
	}
	if(second==0 && minute==0 && hour!=0)
	{
		hour--;
		minute=59;
		second=59;
	}
	if(hour==0 && minute==0 && second==0)
	{
		system("PAUSE");
		break;
	}
	}
}

void getstopwatch()
{
	int i;
	int hour=0;
    int minute=0;
    int second=0;
    
while(!_kbhit())
{
	for(hour;hour<24;hour++) 
	{
		for(minute;minute<60;minute++)
		{
			for(second;second<60;second++)
			{
				if(!_kbhit())
				{
				call(hour/10,40,18); 
    			call(hour%10,50,18);
    			colon(60,18);
    			call(minute/10,70,18);
    			call(minute%10,80,18);
   				colon(90,18);
    			call(second/10,100,18);
    			call(second%10,110,18);
    
				Sleep(70);
				for(double i=0;i<99999999;i++)
				{
					i++;
					i--;
				}
				}
				else
				break;
			}
			second=0;
		}
		minute=0;
	}
	hour=0;
}
}

void getTime()
{
	time_t s;
    struct tm *curtime;
    s=time(NULL);
    curtime=localtime(&s);
    int hour=0;
    int minute=0;
    int second=0;
    hour =curtime->tm_hour;
	minute =curtime->tm_min;
	second =curtime->tm_sec;    
    call(hour/10,40,18); 
    call(hour%10,50,18);
    colon(60,18);
    call(minute/10,70,18);
    call(minute%10,80,18);
    colon(90,18);
    call(second/10,100,18);
    call(second%10,110,18);
    
    Sleep(945);
}


void call(int digit,int x,int y)
{
switch(digit) 
	{

		case 1: one(x,y);
		break;
		case 2: two(x,y);
		break;
		case 3: three(x,y);
		break;
		case 4: four(x,y);
		break;
		case 5: five(x,y);
		break;
		case 6: six(x,y);
		break;
		case 7: seven(x,y);
		break;
		case 8: eight(x,y);
		break;
		case 9: nine(x,y);
		break;
	    default : zero(x,y);
	}
}

void zero(int x,int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{ 
		for(j=1;j<=9;j++)
		{ 
			gotoxy(x,y);
			if(i==1 || i==9 || j==1 || j==9)
			{
				printf("*");
			}
			else
			{ 
				printf(" ");    
			} 
			x++; 
		} 
			y++;
			x=x-9;
		
		printf("\n");
	}
}
void one(int x,int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			gotoxy(x,y);
			if(j==5)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
			x++;
		}
		y++;
			x=x-9;
		printf("\n");
	}
}
void two(int x,int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			gotoxy(x,y);
			if((i==1 || i==5 || i==9) || (i<5 && j==9) || (i>5 && j==1))
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
			x++;
		}
		y++;
			x=x-9;
		printf("\n");
	}
}
void three(int x,int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			gotoxy(x,y);
			if(i==1 || i==5 || i==9 || j==9) 
			{
				printf("*");
			}
			else 
			{
				printf(" ");
			}
			x++;
		}
		y++;
			x=x-9;
		printf("\n");
	}
}
void four(int x,int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			gotoxy(x,y);
			if((i==5 || j==9) || (i<5 && j==1)) 
			{
				printf("*");
			}
			else 
			{
				printf(" ");
			}
			x++;
		}
		y++;
			x=x-9;
		printf("\n");
	}
}
void five(int x,int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			gotoxy(x,y);
			if((i==1 || i==5 || i==9) || (i<5 && j==1) || (i>5 && j==9)) 
			{
				printf("*");
			}
			else 
			{
				printf(" ");
			}
			x++;
		}
		y++;
			x=x-9;
		printf("\n");
	}
}
void six(int x,int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			gotoxy(x,y);
			if((i==1 || i==5 || i==9 || j==1) || (i>5 && j==9)) 
			{
				printf("*");
			}
			else 
			{
				printf(" ");
			}
			x++;
		}
		y++;
			x=x-9;
		printf("\n");
	}
}
void seven(int x,int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			gotoxy(x,y);
			if(i==1 || j==9) 
			{
				printf("*");
			}
			else 
			{
				printf(" ");
			}
			x++;
		}
		y++;
			x=x-9;
		printf("\n");
	}
}
void eight(int x,int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			gotoxy(x,y);
			if(i==1 || i==5 || i==9 || j==1 || j==9) 
			{
				printf("*");
			}
			else 
			{
				printf(" ");
			}
			x++;
		}
		y++;
			x=x-9;
		printf("\n");
	}
}
void nine(int x,int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			gotoxy(x,y);
			if((i==1 || i==5 || i==9 || j==9) || (i<5 && j==1)) 
			{
				printf("*");
			}
			else 
			{
				printf(" ");
			}
			x++;
		}
		y++;
			x=x-9;
		printf("\n");
	}
}
void colon(int x,int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			gotoxy(x,y);
			if((i==3 && j==5) || (i==7 && j==5)) 
			{
				printf("##");
			}
			else 
			{
				printf(" ");
			}
			x++;
		}
		y++;
			x=x-9;
		printf("\n"); 
	}
}
