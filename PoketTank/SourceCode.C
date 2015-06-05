#include <graphics.h>
#include<dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include<process.h>
int flag=0,flag1=1,flag3=0,p2=100,q2=100,p=100,q1=100,x1=320,y1=450,x2=320,y2=400,m,fx1,fx2,fy1,fy2,l=10;
int building_1=0,building_2=0,building_3=0,building_4=0,fx3,fy3,tscore;
int str9[50],flag4=0,flag5=0,flag7=0,no_of_bombs=0,no_of_buildings=0,total2=0;
double q=3.14/2;
int total=0;
int c1,flag8=0;
char tname[20],ttime[20],tdate[20],c,name3[10],str[5],ch1,fileh[10],name1[10],file[10],name2[10],files[10],pan[20],ran[20];
FILE *fp;
void bomb();
void together();
void together1();
void fire();
void rotate_right();
void rotate_left();
void move_right();
void move_left();
void score1(int x);
void score2(int x);
void player1();
void frame();
struct date d;
struct time t;
struct node
{
int pt;
struct node *next;
}*head1=NULL,*head2=NULL;


struct node *n=NULL,*temp=NULL,*newnode=NULL;



struct highscore
{
 char name[15];
 int score;
 char date[15];
 char time[15];
 struct highscore *ndata;
}*hss=NULL,*trav2=NULL,*trav=NULL,*temp1=NULL;
struct highscore *hs=NULL;


void  disp()
{
int gdriver=DETECT,gmode,i=0,xx=50,yy=50;
char sst[5];
//printf("\n\n    Name            Date           Time            Score");
initgraph(&gdriver, &gmode, "e:\\tc\\bgi");
setcolor(RED);
settextstyle(1,0,3);
outtextxy(50,20,"NAME");
outtextxy(200,20,"DATE");
outtextxy(350,20,"TIME");
outtextxy(500,20,"SCORE");
for(trav=hss;trav!=NULL && i<10;trav=trav->ndata)
{
/*printf("\n");
printf("     %s      ",trav->name);
printf("  %s  ",trav->date);
printf("  %s  ",trav->time);
printf("  %d  ",trav->score);  */
setcolor(GREEN);
settextstyle(2,0,0);


outtextxy(xx,yy,trav->name);
outtextxy(xx+150,yy,trav->date);
outtextxy(xx+300,yy,trav->time);
itoa(trav->score,sst,10);
outtextxy(xx+450,yy,sst);
yy+=30;
i++;
}
}








void display()
{
printf("\n\n DESCRIPTION                PTs. ");
for(temp=head1;temp!=NULL;temp=temp->next)
{
if(temp->pt==100)
printf("\n BUILDING        :      %d",temp->pt);
if(temp->pt==-20)
printf("\n BOMB WASTE      :      %d",temp->pt);
}
}


void player1()
{
fx1=x2;
  fy1=y2;
  fx2=fx1+10*cos(q);
  fy2=fy1-10*sin(q);
  setcolor(RED);
  line(fx1,fy1,fx2,fy2);

while(fx1<=640&&fx1>=0&&fy1<=480&&fy1>=0)
{
//if(flag6==1)
//{
  frame();
  setcolor(BLACK);
  line(fx1,fy1,fx2,fy2);
  fx1=fx2;
  fy1=fy2;
  fx2=fx1+10*cos(q);
  fy2=fy1-10*sin(q);
  //sound(300);
  setcolor(RED);
  line(fx1,fy1,fx2,fy2);
  if(kbhit())
  c=getch();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();

  c='z';

if(building_2==0&&m==1)
	{
	if(p<=170)
		{
		delay(50);
		move_right();
		if(kbhit())
		c=getch();
		if(c=='a'||c=='A')
		rotate_left();
		if(c=='d'||c=='D')
		rotate_right();
		c='z';
		if(p==170)
			{
			together1();
			//bomb();
			m=random(4);
			}
		}
	else
		{
		 delay(50);
		 move_left();
		if(kbhit())
		c=getch();
		if(c=='a'||c=='A')
		rotate_left();
		if(c=='d'||c=='D')
		rotate_right();
		c='z';
		if(p==170)
			{
			together1();
			//bomb();
			m=random(4);
			}
		}
	}

if(building_3==0&&m==2)
	{
	if(p<=470)
		{
		delay(50);
		move_right();
		if(kbhit())
		c=getch();
		if(c=='a'||c=='A')
		rotate_left();
		if(c=='d'||c=='D')
		rotate_right();
		c='z';
		if(p==470)
			{
			together1();
			m=random(4);
			}
		}
	else
		{
		delay(50);
		move_left();
		if(kbhit())
		c=getch();
		if(c=='a'||c=='A')
		rotate_left();
		if(c=='d'||c=='D')
		rotate_right();
		c='z';
		if(p==470)
			{

			together1();
			//bomb();
			m=random(4);
			}
		}
	}

if(building_4==0&&m==3)
	{
	if(p<=600)
		{
		delay(50);
		move_right();
		if(kbhit())
		c=getch();
		if(c=='a'||c=='A')
		rotate_left();
		if(c=='d'||c=='D')
		rotate_right();
		c='z';
		if(p==600)
			{

			together1();
			//bomb();
			m=random(4);
			}
		}
	else
		{
		delay(50);
		move_left();
		if(kbhit())
		c=getch();
		if(c=='a'||c=='A')
		rotate_left();
		if(c=='d'||c=='D')
		rotate_right();
		c='z';
		if(p==600)
			{

			together1();
			//bomb();
			m=random(4);
			}
		}
	}
if(building_1==0&&m==0)
	{
	if(p<=50)
		{
		delay(50);
		move_right();
		if(kbhit())
		c=getch();
		if(c=='a'||c=='A')
		rotate_left();
		if(c=='d'||c=='D')
		rotate_right();
		c='z';

		if(p==50)
			{

			together1();
			//bomb();
			m=random(4);
			}
		}
	else
		{
		delay(50);
		move_left();
		if(kbhit())
		c=getch();
		if(c=='a'||c=='A')
		rotate_left();
		if(c=='d'||c=='D')
		rotate_right();
		c='z';

		if(p==50)
			{

			together1();
			//bomb();
			m=random(4);
			}
		}
	}
//flag6=0;
if(building_1==1&&building_2==1&&building_3==1&&building_4==1)
break;
}
}






void score1(int x)
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->pt=x;
newnode->next=NULL;
if(head1==NULL)
{
head1=newnode;
n=newnode;
total+=n->pt;
}
else
{
n->next=newnode;
n=newnode;
total+=n->pt;
}
}













void score2(int x)
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->pt=x;
newnode->next=NULL;
if(head2==NULL)
{
head2=newnode;
n=newnode;
total2+=n->pt;
}
else
{
n->next=newnode;
n=newnode;
total2+=n->pt;
}
}


void frame()
{
// settextstyle(1,0,1);
 setcolor(WHITE);
  rectangle(560,0,600,40);
 setfillstyle(1,BLACK);
 floodfill(570,10,WHITE);
 setcolor(RED);
 itoa(total,str,10);
 outtextxy(570,15,str);
  setcolor(WHITE);
  rectangle(600,0,639,40);
 setfillstyle(1,BLACK);
 floodfill(620,10,WHITE);
  setcolor(RED);
 itoa(total2,str,10);
 outtextxy(610,15,str);
 itoa(no_of_bombs,str,10);
 //settextstyle(2,0,1);

 setcolor(BLACK);
 itoa(no_of_bombs-1,str,10);
 outtextxy(250,10,str);
 setcolor(CYAN);
 itoa(no_of_bombs,str,10);
 outtextxy(250,10,str);
 outtextxy(50,10,"BOMBS CONSUMED : ");

 setcolor(6);
if(building_4==0)                                     // F
{
rectangle(580,474,610,425);                           //R
setfillstyle(1,2);
floodfill(600,450,6);                                 //A
}
if(building_3==0)                                     //M
{
rectangle(455,474,485,425);                           //E
setfillstyle(1,2);
floodfill(460,450,6);
}
if(building_1==0)
{
rectangle(30,474,60,425);
setfillstyle(1,2);
floodfill(50,450,6);
}
if(building_2==0)
{
rectangle(155,474,185,425);
setfillstyle(1,2);
floodfill(160,450,6);
}
setcolor(14);
line(0,475,640,475);
setcolor(14);
arc(320,475,0,180,25);
setfillstyle(1,5);
floodfill(320,470,14);
}



void together1()
{
p2=p;
q2=100;
flag4=0;
//printf("\n together 1");
while((q2<=400)||(fx1<=640&&fx1>=0&&fy1<=480&&fy1>=0))
{
if(no_of_bombs<10||flag5==9)
{
frame();
q2+=10;
setcolor(6);
setfillstyle(1,BLUE);
circle(p2,q2,10);
floodfill(p2,q2,6);
c1=getpixel(fx2,fy2-5);
if(c1==1)
{
flag3=1;
setcolor(6);
circle(p2,q2,10);
setfillstyle(1,BLACK);
floodfill(p2,q2,6);
setcolor(0);
circle(p2,q2,10);

//printf("\ntogether 1");
score2(100);
//score1(-20);
break;
}

delay(50);
setcolor(6);
circle(p2,q2,10);
setfillstyle(1,BLACK);
floodfill(p2,q2,6);
setcolor(0);
circle(p2,q2,10);
   setcolor(BLACK);
  line(fx1,fy1,fx2,fy2);
  fx1=fx2;
  fy1=fy2;
  fx2=fx1+10*cos(q);
  fy2=fy1-10*sin(q);
//  sound(100);
  setcolor(RED);
  line(fx1,fy1,fx2,fy2);
if(getpixel(p2,430)!=2)
{
if(flag4==0)
{
//printf("\ntogether 1");
score1(-20);
flag4++;
}
}

if(getpixel(p2,(q2+20))==2)
{
if(p2>=580 && p2<=610)
{
//printf("\ntogether 1");
score1(100);
building_4+=1;
setfillstyle(1,0);
delay(100);
floodfill(600,450,6);
setcolor(0);
rectangle(580,474,610,425);
}
if(p2>=455 && p2<=485)
{
//printf("\ntogether 1");
score1(100);
building_3+=1;
setfillstyle(1,0);
delay(100);
//delay(20);
floodfill(460,450,6);
setcolor(0);
rectangle(455,474,485,425);
}
if(p2>=30 && p2<=60)
{
//printf("\ntogether 1");
score1(100);
building_1+=1;
setfillstyle(1,0);
delay(100);
floodfill(50,450,6);
setcolor(0);
rectangle(30,474,60,425);
/*setfillstyle(1,128);
floodfill(50,450,6); */
}
if(p2>=155 && p2<=185)
{
//printf("\ntogether 1");
score1(100);
building_2+=1;
setfillstyle(1,0);
delay(100);
//delay(20);
floodfill(160,450,6);
setcolor(0);
rectangle(155,474,185,425);
}
}


flag5++;
//printf("\nflag5==%d",flag5);
if(building_2!=0 &&  building_1!=0 &&  building_3!=0 &&building_4!=0 )
{
//printf("\n\nGame over in together 1");
//delay(100);
//getch();
c='o';
break;
}

 if(kbhit())
  c=getch();
  if(c=='4'||c=='4')
  move_left();
  if(c=='6'||c=='6')
  move_right();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  c='z';
}

else
{
flag5++;
//break;
}


}
if(flag5==10)
{
cleardevice();
//printf("\nInside conditionflag5==%d",flag5);
//printf("\n\nGame over in together 1 ");
//printf("\n\n\nBOmbs r finished");
c='o';
//delay(1000);
//getch();

}



flag4=0;
}









void together()
{
flag4=0;
if(flag7!=1)
{
 fx1=x2;
 fy1=y2;
 fx2=fx1+10*cos(q);
 fy2=fy1-10*sin(q);
 flag4=0;
}
 while((q2<=400)||(fx1<=640&&fx1>=0&&fy1<=480&&fy1>=0))
{
flag7=0;
if(no_of_bombs<10||flag5==9)
{
frame();
q2+=10;
setcolor(6);
setfillstyle(1,BLUE);
circle(p2,q2,10);
floodfill(p2,q2,6);
c1=getpixel(fx2,fy2-5);
//printf(" c1==%d",c1);
if(c1==1)
{
flag3=1;
setcolor(6);
circle(p2,q2,10);
setfillstyle(1,BLACK);
floodfill(p2,q2,6);
setcolor(0);
circle(p2,q2,10);
//printf("\ntogether c1");
score2(100);
//score1(-20);
break;
}
delay(50);
setcolor(6);
circle(p2,q2,10);
setfillstyle(1,BLACK);
floodfill(p2,q2,6);
setcolor(0);
circle(p2,q2,10);
  line(fx1,fy1,fx2,fy2);
  fx1=fx2;
  fy1=fy2;
  fx2=fx1+10*cos(q);
  fy2=fy1-10*sin(q);
  //sound(100);
  setcolor(RED);
  line(fx1,fy1,fx2,fy2);
/*if(getpixel(p2,430)!=2)
{
if(flag4==0)
{
printf("\ntogether -20");
score1(-20);
flag4++;
}
} */


if(getpixel(p2,(q2+20))==2)
{
if(p2>=580 && p2<=610)
{
//printf("\ntogether score");
score1(100);
flag8=1;
building_4+=1;
setfillstyle(1,0);
delay(100);
floodfill(600,450,6);
setcolor(0);
rectangle(580,474,610,425);
}
if(p2>=455 && p2<=485)
{
//printf("\ntogether score");
score1(100);
flag8=1;
building_3+=1;
setfillstyle(1,0);
delay(100);
//delay(20);
floodfill(460,450,6);
setcolor(0);
rectangle(455,474,485,425);
}
if(p2>=30 && p2<=60)
{
//printf("\ntogether score");
//printf("\ntogether ");
score1(100);
flag8=1;
building_1+=1;
setfillstyle(1,0);
delay(100);
floodfill(50,450,6);
setcolor(0);
rectangle(30,474,60,425);
/*setfillstyle(1,128);
floodfill(50,450,6);  */
}
if(p2>=155 && p2<=185)
{
//printf("\ntogether score");
score1(100);
flag8=1;
building_2+=1;
setfillstyle(1,0);
delay(100);
//delay(20);
floodfill(160,450,6);
setcolor(0);
rectangle(155,474,185,425);
}
}


flag5++;
if(building_2!=0 &&  building_1!=0 &&  building_3!=0 &&building_4!=0 )
{
cleardevice();
//printf("\n\nGAme over in together  ");
//printf("\n\n\nGame over");
//delay(1000);
//getch();
c='o';
break;
}


if(kbhit())
  c=getch();
  if(c=='4'||c=='4')
  move_left();
  if(c=='6'||c=='6')
  move_right();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  c='z';
}



else
{
flag5++;
}

}
if(flag5==10)
{
cleardevice();
//printf("\n\n\nGAme over ");
//printf("\n\nGAme over in together  ");
//printf("\n\n\nBOmbs r finished");
c='o';

}

}




void bomb()
{
//printf("\n\n ENETRing bomb " );
p2=p;
q2=100;
flag8=0;
while(q2<=400)
{
if(no_of_bombs<10||flag5==9)
 {
  frame();
  c='z';
  if(flag3==1)
  break;
  flag5++;
  if(kbhit())
  c=getch();
  if(c=='4'||c=='4')
  move_left();
  if(c=='6'||c=='6')
  move_right();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  if(c=='f'||c=='F')
   together();


  c='z';
  q2+=10;
  setcolor(6);
  setfillstyle(1,BLUE);

  circle(p2,q2,10);
  floodfill(p2,q2,6);
  delay(50);
  setcolor(6);
  circle(p2,q2,10);
  setfillstyle(1,BLACK);
  floodfill(p2,q2,6);
  setcolor(0);
  circle(p2,q2,10);
if(getpixel(p2,430)!=2)
{
 if(flag4==0&&flag8==0)
  {
  // printf("\nbomb ");
   score1(-20);
   flag4++;
   flag8=1;
   }
 }
   if(getpixel(p2,(q2+20))==2)
    {
     if(p2>=580 && p2<=610)
      {
    //   printf("\nbomb ");
       score1(100);
       building_4+=1;
       setfillstyle(1,0);
       delay(100);
       floodfill(600,450,6);
       setcolor(0);
       rectangle(580,474,610,425);
     }
   if(p2>=455 && p2<=485)
  {
  // printf("\nbomb ");
   score1(100);
building_3+=1;
setfillstyle(1,0);
delay(100);
//delay(20);
floodfill(460,450,6);
setcolor(0);
rectangle(455,474,485,425);
}
if(p2>=30 && p2<=60)
{
//printf("\nbomb ");
score1(100);
building_1+=1;
setfillstyle(1,0);
delay(100);
floodfill(50,450,6);
setcolor(0);
rectangle(30,474,60,425);


}
if(p2>=155 && p2<=185)
{
//printf("\nbomb ");
score1(100);
building_2+=1;
setfillstyle(1,0);
delay(100);
//delay(20);
floodfill(160,450,6);
setcolor(0);
rectangle(155,474,185,425);
}
}

if(building_2!=0 &&  building_1!=0 &&  building_3!=0 &&building_4!=0 )
{
cleardevice();
setcolor(GREEN);
settextstyle(1,0,2);
outtextxy(280,230,"GAME OVER!!!");
c='o';
delay(1000);
getch();
break;
}

}
else
flag5++;
}
if(flag5==10)
{
cleardevice();
setcolor(GREEN);
settextstyle(1,0,2);
outtextxy(280,200,"BOMBS FINISHED");
outtextxy(280,230,"GAME OVER!!!");

delay(1000);
c='o';
}
flag4=0;
}




void fire()
 {
  fx1=x2;
  fy1=y2;
  fx2=fx1+10*cos(q);
  fy2=fy1-10*sin(q);
  setcolor(RED);
  line(fx1,fy1,fx2,fy2);
  while(fx1<=640&&fx1>=0&&fy1<=480&&fy1>=0)
  { frame();
	delay(50);
  setcolor(BLACK);
  line(fx1,fy1,fx2,fy2);
  fx1=fx2;
  fy1=fy2;
  fx2=fx1+10*cos(q);
  fy2=fy1-10*sin(q);
  //sound(300);
  setcolor(RED);
  line(fx1,fy1,fx2,fy2);
	if(kbhit())
  c=getch();
  if(c=='4'||c=='4')
  move_left();
   if(c=='6'||c=='6')
  move_right();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  if(c=='5'||c=='5')
	 {no_of_bombs++;
	 together1(); }
	 //bomb();
  c='z';
  frame();
  }
 }

void rotate_right()
{

setcolor(BLACK);
  line(x1,y1,x2,y2);

  q=q-3.14/16;
  x2=320+50*cos(q);
  y2=450-50*sin(q);
  setcolor(WHITE);
  line(x1, y1, x2, y2);
frame();
}





void rotate_left()
{

setcolor(BLACK);
  line(x1,y1,x2,y2);

  q=q+3.14/16;
  x2=320+50*cos(q);
  y2=450-50*sin(q);
  setcolor(WHITE);
  line(x1, y1, x2, y2);
frame();
}

void move_right()
{

     setcolor(GREEN);
   ellipse(p,q1,0,180,20,10);
   line(p-40,q1,p+40,q1);
   ellipse(p,q1,180,360,40,10);
	 setfillstyle(1,BLACK);
  floodfill(p+10,q1+1,GREEN);
  floodfill(p+10,q1-1,GREEN);

     setcolor(BLACK);
	ellipse(p,q1,0,180,20,10);
   line(p-40,q1,p+40,q1);
   ellipse(p,q1,180,360,40,10);

	p+=10;

   setcolor(GREEN);
   ellipse(p,q1,0,180,20,10);
   line(p-40,q1,p+40,q1);
   ellipse(p,q1,180,360,40,10);
 setfillstyle(1,RED);
 floodfill(p+10,q1+2,GREEN);
  floodfill(p+10,q1-2,GREEN);
 frame();
}

void move_left()
{



   setcolor(GREEN);
   ellipse(p,q1,0,180,20,10);
   line(p-40,q1,p+40,q1);
   ellipse(p,q1,180,360,40,10);
	 setfillstyle(1,BLACK);
  floodfill(p+10,q1+1,GREEN);
  floodfill(p+10,q1-1,GREEN);
setcolor(BLACK);
	   ellipse(p,q1,0,180,20,10);
   line(p-40,q1,p+40,q1);
   ellipse(p,q1,180,360,40,10);
	p-=10;
   setcolor(GREEN);
   ellipse(p,q1,0,180,20,10);
   line(p-40,q1,p+40,q1);
   ellipse(p,q1,180,360,40,10);
 setfillstyle(1,RED);
  floodfill(p+10,q1+2,GREEN);
  floodfill(p+10,q1-2,GREEN);



frame();
}







void main()
{

int gdriver = DETECT, gmode, errorcode;
int input;
char instruct[100];
initgraph(&gdriver, &gmode, "e:\\tc\\bgi");

while(!kbhit())
   {
	setcolor(random(16));
	settextstyle(4,0,4);
	outtextxy(200,200,"Pocket Tank");
	settextstyle(2,0,0);
	outtextxy(400,300,"AVINAV SHARAN (07102186)");
	outtextxy(400,320,"ANKUR GUPTA (07102192)");
	outtextxy(400,340,"SHANTANU SHUKLA (07102188)");
	outtextxy(400,360,"DEEPAK SHARMA (07102198)");
	settextstyle(2,0,4);
   outtextxy(420,460,"Press Any Key To Continue...");
   }
  getch();
  closegraph();
   start:
  clrscr();
  initgraph(&gdriver, &gmode, "e:\\tc\\bgi");
  settextstyle(4,0,4);
  outtextxy(230,80," Press.......");
  outtextxy(180,130,"1.For New Game");
  outtextxy(180,180,"2.For Instructions");
  outtextxy(180,230,"3.For History");
  outtextxy(180,280,"4.For Highest Scores");
  outtextxy(180,330,"5.For Exit");
  scanf("%d",&input);
  closegraph();
  switch(input)
  {
  case 1:
  {
  int input;
  initgraph(&gdriver, &gmode, "e:\\tc\\bgi");
  settextstyle(4,0,4);
  outtextxy(250,130,"Press.......");
  outtextxy(180,180,"1.For 1 Player Game");
  outtextxy(180,230,"2.For 2 Player Game");
  outtextxy(180,280,"3.Main Menu...");
  outtextxy(180,330,"4.For Exit");


 scanf("%d",&input);
  closegraph();
switch(input)
  {
  case 1:
  {
    initgraph(&gdriver, &gmode, "e:\\tc\\bgi");
	 settextstyle(2,0,0);
	outtextxy(100,200,"Enter player 1 Name");
	scanf("%s",name1);
     //	outtextxy(100,300,name1);
	     delay(1000);
	cleardevice();

  //initgraph(&gdriver, &gmode, "e:\\tc\\bgi");
head1=NULL;
head2=NULL;
c='0';
flag4=0;
no_of_bombs=0;
no_of_buildings=0;
building_1=0;
building_2=0;
building_3=0;
building_4=0;
flag=0;flag1=1;flag3=0;p2=100;q2=100;p=100;q1=100;x1=320;y1=450;x2=320;y2=400;l=10;flag5=0;total=0;

//delay(2000);
while(!kbhit())
   {
	setcolor(random(16));
	settextstyle(2,0,0);
	outtextxy(50,450,"LOADING....");
   }

cleardevice();
randomize();
while(1)
{
if(kbhit())
  c=getch();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  if(c=='f'||c=='F')
  player1();
//fire();
    c='z';

m=random(4);
if(building_2==0)
if(m==1)
{
if(p<=170)
{
while(p!=170)
{
delay(50);

move_right();
if(kbhit())
  c=getch();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  if(c=='f'||c=='F')
  player1();

    c='z';
if(flag3==1)
flag3=0;
}
no_of_bombs++;
bomb();
}

else
{
while(p!=170)
{
 delay(50);
 move_left();

if(kbhit())
  c=getch();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  if(c=='f'||c=='F')
  player1();
    c='z';
if(flag3==1)
flag3=0;
}
no_of_bombs++;
bomb();
}
}

if(building_3==0)
if(m==2)
{
if(p<=470)
{

while(p!=470)
{
  delay(50);
  move_right();
if(kbhit())
  c=getch();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  if(c=='f'||c=='F')
    player1();
    c='z';
if(flag3==1)
flag3=0;
if(p==470)
{
no_of_bombs++;
bomb();
}
}
no_of_bombs++;
bomb();
}
else
{
while(p!=470)
{
delay(50);
move_left();
if(kbhit())
  c=getch();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  if(c=='f'||c=='F')
    player1();
    c='z';
if(flag3==1)
flag3=0;
}
no_of_bombs++;
bomb();
}
}

if(building_4==0)

if(m==3)
{
if(p<=600)
{
while(p!=600)
{
delay(50);
move_right();
if(kbhit())
  c=getch();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  if(c=='f'||c=='F')
    player1();
    c='z';
if(flag3==1)
flag3=0;
}
no_of_bombs++;
bomb();
}
else
{
while(p!=600)
{
  delay(50);
  move_left();
if(kbhit())
  c=getch();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  if(c=='f'||c=='F')
    player1();
    c='z';
if(flag3==1)
flag3=0;
if(p==600)
{
no_of_bombs++;
bomb();
}
}
no_of_bombs++;
bomb();
}

}

if(building_1==0)

if(m==0)
{
if(p<=50)
{
while(p!=50)
{

delay(50);
move_right();
if(kbhit())
  c=getch();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  if(c=='f'||c=='F')
    player1();
    c='z';
if(flag3==1)
flag3=0;
if(p==50)
{
no_of_bombs++;
bomb();
}
}
no_of_bombs++;
bomb();

}
else
{
while(p!=50)
{
delay(50);
move_left();
if(kbhit())
  c=getch();
  if(c=='a'||c=='A')
  rotate_left();
  if(c=='d'||c=='D')
  rotate_right();
  if(c=='f'||c=='F')
    player1();
    c='z';
if(flag3==1)
flag3=0;
}
no_of_bombs++;
bomb();
}
}
if(building_1==1&&building_2==1&&building_3==1&&building_4==1)
break;
}

settextstyle(5,0,4);
setcolor(CYAN);
cleardevice();
if(total>total2)
outtextxy(200,220,"YOU LOSE!!!");
if(total<total2)
outtextxy(200,220,"YOU WIN!!!");
if(total==total2)
outtextxy(200,220,"DRAW!!!!");
delay(2000);
//getch();

cleardevice();
display();

printf("\n\ntotal===%d",total);
getch();
closegraph();

strcpy(files,name1);
strcpy(ran,"e:\\tc\\bin\\");
strcat(ran,files);
strcat(ran,".txt");
fp=fopen(ran,"a");
getdate(&d);
gettime(&t);
fprintf(fp,"\n%d " ,total2);
fprintf(fp,"%2d:%02d:%02d.%02d ",t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
fprintf(fp,"%d", d.da_year);
 fprintf(fp,"-%d", d.da_day);
 fprintf(fp,"-%d", d.da_mon);
fclose(fp);
fp=fopen("game.txt","a");
fprintf(fp,"\n%s ",name1);
fprintf(fp,"%d ",total2);
fprintf(fp,"%2d:%02d:%02d.%02d ",t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
fprintf(fp,"%d", d.da_year);
 fprintf(fp,"-%d", d.da_day);
 fprintf(fp,"-%d", d.da_mon);
fclose(fp);


goto start;


}


case 2:
  {
head1=NULL;
head2=NULL;
initgraph(&gdriver, &gmode, "e:\\tc\\bgi");
	settextstyle(2,0,0);
	outtextxy(100,200,"Enter player 1 Name");
	scanf("%s",name1);
       //	outtextxy(100,300,name1);
	     delay(1000);
	cleardevice();
		outtextxy(100,200,"Enter player 2 Name");
	scanf("%s",name2);
       //	outtextxy(100,300,name2);
	  delay(1000);
	cleardevice();



c='0';
flag4=0,flag7=0;
no_of_bombs=0;
no_of_buildings=0;
building_1=0;
building_2=0;
building_3=0;
building_4=0;
flag=0;flag1=1;flag3=0;p2=100;q2=100;p=100;q1=100;x1=320;y1=450;x2=320;y2=400;l=10;
total=0,total2=0;
flag5=0;
while(!kbhit())
   {
	setcolor(random(16));
	settextstyle(2,0,0);
	outtextxy(50,450,"LOADING....");
   }



cleardevice();
line(x1,y1,x2,y2);
while(1)
{
frame();
flag3=0;
if(kbhit())
fflush(stdin);
c=getch();
if(c=='6'||c=='6')
move_right();
if(c=='4'||c=='4')
move_left();
if(c=='5'||c=='5')
{
no_of_bombs++;
bomb();
}
if(c=='o'||c=='O')
break;
if(c=='d'||c=='D')
rotate_right();
if(c=='a'||c=='A')
rotate_left();
if(c=='f'||c=='F')
fire();
//nosound();
c='z';
}
cleardevice();
display();
printf("\n\n PLAYER 1 TOTAL  : %d ",total);
printf("\n\n PLAYER 2 TOTAL  : %d ",total2);
getch();
settextstyle(5,0,4);
setcolor(CYAN);
cleardevice();
if(total>total2)
outtextxy(200,220,"PLAYER 1 WINS!!!");
if(total<total2)
outtextxy(200,220,"PLAYER 2 WINS!!!");
if(total==total2)
outtextxy(200,220,"DRAW!!!!");
strcpy(files,name1);
strcpy(ran,"e:\\tc\\bin\\");
strcat(ran,files);
strcat(ran,".txt");
fp=fopen(ran,"a");
getdate(&d);
gettime(&t);
fprintf(fp,"\n%d ",total);
fprintf(fp,"%2d:%02d:%02d.%02d",t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
fprintf(fp," %d", d.da_year);
 fprintf(fp,"-%d", d.da_day);
 fprintf(fp,"-%d", d.da_mon);
fclose(fp);
strcpy(files,name2);
strcpy(ran,"e:\\tc\\bin\\");
strcat(ran,files);
strcat(ran,".txt");
fp=fopen(ran,"a");
{getdate(&d);

gettime(&t);
fprintf(fp,"\n%d ",total2);
fprintf(fp,"%2d:%02d:%02d.%02d",t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
 fprintf(fp," %d",d.da_year);
 fprintf(fp,"-%d", d.da_day);
 fprintf(fp,"-%d", d.da_mon);

}
fclose(fp);
fp=fopen("game.txt","a");
fprintf(fp,"\n%s ",name1);
fprintf(fp,"%d ",total);
fprintf(fp,"%2d:%02d:%02d.%02d ",t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
fprintf(fp," %d", d.da_year);
 fprintf(fp,"-%d", d.da_day);
 fprintf(fp,"-%d", d.da_mon);
fclose(fp);
//fclose(fp);
fp=fopen("game.txt","a");
fprintf(fp,"\n%s ",name2);
fprintf(fp,"%d ",total2);
fprintf(fp,"%2d:%02d:%02d.%02d",t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
fprintf(fp," %d", d.da_year);
fprintf(fp,"-%d", d.da_day);
fprintf(fp,"-%d", d.da_mon);
fclose(fp);



getch();
closegraph();
goto start;
}
case 4:
 {
  exit(0);
  }
case 3:
  {

   goto start;
  }
  }
 break;
 }
  case 2:
  {
	int xx=50,yy=50;
	FILE *fp;

	fp=fopen("u.txt","r");
	clrscr();
	if(fp==NULL)
	printf("\n\n\nUnable to open the file InStRuCTions.txt");
	else
	{
	 initgraph(&gdriver, &gmode, "e:\\tc\\bgi");
	while(!feof(fp))
	{
	fgets(instruct,500,fp);
	settextstyle(5,0,2);
	setcolor(CYAN);
	outtextxy(xx,yy,instruct);
	yy+=20;
	}
while(!kbhit())
   {
	setcolor(random(16));
	settextstyle(2,0,4);
	outtextxy(420,460,"Press Any Key To Continue...");
   }
   getch();
   closegraph();
   goto start;
	}
	fclose(fp);
	}
   break;





   case 3:
   {     int xx=50,yy=150;
      char inst1[14],inst2[15],inst3[16];
   initgraph(&gdriver, &gmode, "e:\\tc\\bgi");



	cleardevice();
	setcolor(GREEN);
	settextstyle(2,0,0);
	outtextxy(100,100,"Enter your name");
	fflush(stdin);
	gets(name3);
	cleardevice();
	strcpy(fileh,name3);
	strcpy(pan,"e:\\tc\\bin\\");
	strcat(pan,fileh);
	strcat(pan,".txt");
	fp=fopen(pan,"r");

	if(fp==NULL)
printf("\n\nUnable to open the file");
	settextstyle(4,0,4);
       setcolor(RED);
	outtextxy(300,20,name3);
   settextstyle(3,0,2);
outtextxy(50,100,"SCORE");
outtextxy(200,100,"TIME");
outtextxy(350,100,"DATE");

	while(!feof(fp))
	{
       fscanf(fp,"%s %s %s",inst1,inst2,inst3);
	settextstyle(2,0,0);
	setcolor(GREEN);
	outtextxy(xx,yy,inst1);
	outtextxy(xx+150,yy,inst2);
	outtextxy(xx+300,yy,inst3);
	 yy+=30;

	}
	getch();
	fclose(fp);
	closegraph();


 goto start;

	}

case 4:
{

    struct highscore *n=NULL;
   fp=fopen("game.txt","r");
	if(fp==NULL)
{
printf("\n\nUnable to open the file");
 getch();
}
while(!feof(fp))
  {
fscanf(fp,"%s %d %s %s",tname,&tscore,ttime,tdate);
//printf("\n\n\nname=%s,score=%d,time=%s,date=%s",tname,tscore,ttime,tdate);

hs=(struct highscore*) malloc(sizeof(struct highscore));
strcpy(hs->name,tname);
hs->score=tscore;
strcpy(hs->time,ttime);
strcpy(hs->date,tdate);
hs->ndata=NULL;
if(hss==NULL)
{
hss=hs;
n=hs;
//printf("\nhs->score=%d",hs->score);
}
else
{
n->ndata=hs;
n=hs;
n->ndata=NULL;
//printf("\nhs->score=%d",hs->score);
}
}
fclose(fp);

//disp();
getch();
for(trav=hss;trav!=NULL;trav=trav->ndata)
 {
  for(trav2=hss;trav2!=NULL;trav2=trav2->ndata)
   {
   if((trav2->score)<(trav2->ndata->score))
    {
     strcpy(temp1->name,trav2->name);
     strcpy(temp1->date,trav2->date);
     strcpy(temp1->time,trav2->time);
     temp1->score=trav2->score;

     strcpy(trav2->name,trav2->ndata->name);
     strcpy(trav2->date,trav2->ndata->date);
     strcpy(trav2->time,trav2->ndata->time);
     trav2->score=trav2->ndata->score;

     strcpy(trav2->ndata->name,temp1->name);
     strcpy(trav2->ndata->date,temp1->date);
     strcpy(trav2->ndata->time,temp1->time);
     trav2->ndata->score= temp1->score;
   }
   }
 }


disp();
getch();
goto start;
}
case 5:
{
exit(0);
}
default:
{
printf("\n\nWrong input");
goto start;
}
}
}
