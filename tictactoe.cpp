#include<iostream.h>                            //for input output
#include<conio.h>                               //for clrscr() and getch()
#include<dos.h>                                 // for delay
#include<graphics.h>
#include<stdlib.h>                             //for random();
/*

    NAME : vipul khullar
    
			 GAME OF TIC TAC TOE
*/
   char tic[3][3];                                 // global matrix declerations
   int d,e,f,a,t,i,j,x,y;                         // global variables declerations
   char p;
   int sum;                                      // variable to check whether the game is draw
   void player1win();                            // displays message if player 1 wins
   void pcwin();                                //displays message if player loses
   void draw();                                 // displays message if the game is draw
  void display();                               //  displays the matrix
   void user();                                //  function for user's move
  void player2win();                          //   displays message if player 2 wins
   void player2();                           //  function for second player's move
   void game();                             // starts game
   void menu();                             // displays selection menu
   void comp();                            //  function for PC's move
   int check();                            //  function for finding out the winner
   int horizontal();                      //  function for horizontal line check
   int vertical();                       //  function for vertical line check
   int diagonal();                      //  function for diagonal line check
   void instructions();                //displays instructions
   void setgraph();
   void main()                            // main function
   {
     clrscr();                           //clears the previous output screen
     setgraph();
     setbkcolor(0);
     for(int i=0;i<500;++i)
      {
	delay(7);
	putpixel(random(640),random(480),random(15));
      }
     settextstyle(7,0,5);
     outtextxy(285,90,"TIC");
     outtextxy(285,130,"TAC");
     outtextxy(285,170,"TOE");
     for( i=0;i<80;++i)
       {
	 setcolor(4);
	 circle(320,160,i+80);
	 delay(50);
       }
     settextstyle(5,0,3);
     setcolor(4);
     outtextxy(210,330,"press any key to continue ......");
     setcolor(13);
     outtextxy(220,400,"By : Yashika Ranjan");
     getch();
     closegraph();
     menu();
   }

   void menu()
   {
     clrscr();
     setgraph();
     setbkcolor(1);
       for(int i=0;i<635;i+=20)
	 {
	   setcolor(2);
	   setfillstyle(1,2);
	   circle(12+i,10,10);
	   floodfill(12+i,10,2);
	 }
       for(i=0;i<635;i+=20)
	 {
	   setcolor(2);
	   setfillstyle(1,2);
	   circle(12+i,468,10);
	   floodfill(12+i,468,2);
	 }
     settextstyle(8,0,3);
     for(i=420;i>30;i-=3)
	{
	  setcolor(random(15));
	  outtextxy(230,i,"SeLeCtIoN MeNu");
	  delay(40);
	  setcolor(1);
	  outtextxy(230,i,"SeLeCtIoN MeNu");
	}
     setcolor(14);
     outtextxy(230,30,"SeLeCtIoN MeNu");
     line(220,60,440,60);
     for(i=0;i<200;i+=3)
	{
	  setcolor(i);
	  settextstyle(7,0,2);
	  outtextxy(i,110," 1. NEW GAME");
	  outtextxy(i,160," 2. INSTRUCTIONS");
	  outtextxy(i,210," 3. EXIT");
	  delay(40);
	  setcolor(1);
	  outtextxy(i,110," 1. NEW GAME");
	  outtextxy(i,160," 2. INSTRUCTIONS");
	  outtextxy(i,210," 3. EXIT");
	}
     int v;
     for(int h=0;;)
       {
	  for(int i=0;i<635;i+=20)
	    {
	      setcolor(2);
	      setfillstyle(1,2);
	      circle(12+i,10,10);
	      floodfill(12+i,10,2);
	    }
	  for(i=0;i<635;i+=20)
	    {
	      setcolor(2);
	      setfillstyle(1,2);
	      circle(12+i,468,10);
	      floodfill(12+i,468,2);
	    }
     i=200;
     setcolor(15);
     ellipse(310,180,0,360,140,100);
     setfillstyle(1,4);
     floodfill(310,180,15);
     setcolor(15);
     settextstyle(7,0,2);
     outtextxy(i,110," 1. NEW GAME");
     outtextxy(i,160," 2. INSTRUCTIONS");
     outtextxy(i,210," 3. EXIT");
     setcolor(14);
     setfillstyle(1,14);
     circle(180,350,10);
     floodfill(180,350,14);
     setcolor(10);
     setfillstyle(1,10);
     circle(130,200,20);
     floodfill(130,200,10);
     setcolor(6);
     setfillstyle(1,6);
     circle(600,300,15);
     floodfill(600,300,6);
     setcolor(13);
     setfillstyle(1,13);
     circle(30,330,15);
     floodfill(30,330,13);
     setcolor(12);
     setfillstyle(1,12);
     circle(460,350,15);
     floodfill(460,350,12);
     setcolor(13);
     setfillstyle(1,13);
     circle(480,220,20);
     floodfill(480,220,13);
     setcolor(12);
     setfillstyle(1,12);
     circle(50,80,10);
     floodfill(50,80,12);
     setcolor(14);
     setfillstyle(1,14);
     circle(590,80,10);
     floodfill(590,80,14);

     if(h==300)
	v=1;
     else
     if(h==0)
	v=0;
     if(v==1)
	h-=10;
     else
     if(v==0)
	h+=10;
     setcolor(15);
     settextstyle(8,0,2);
     outtextxy(h,400,"Enter Your Choice (1,2 or 3)");
     delay(150);
     setcolor(1);
     settextstyle(8,0,2);
     outtextxy(h,400,"Enter Your Choice (1,2 or 3)");
     if(kbhit())
	{
	   char c=getch();
	   if(c=='1')
	       {
		setcolor(4);
		rectangle(205,320,440,420);
		setcolor(14);
		rectangle(206,321,439,419);
		setcolor(15);
		settextstyle(2,0,6);
		outtextxy(210,340," 1. USER vs COMPUTER");
		outtextxy(210,370," 2.PLAYER 1 vs PLAYER 2");
		p= getch();
		closegraph();
		game();
	       }
	   else
	   if(c=='2')
	       instructions();
	   else
	       exit(0);
	}
     settextstyle(8,0,3);
     setcolor(14);
     outtextxy(230,30,"SeLeCtIoN MeNu");
     line(220,60,440,60);
       }

   }
    void instructions()
    {
      cleardevice();
      setbkcolor(6);
      setcolor(1);
      line(0,2,640,2);
      line(0,4,640,4);
      line(0,6,640,6);
      line(0,473,640,473);
      line(0,477,640,477);
      line(0,475,640,475);
      setcolor(1);
      settextstyle(4,0,6);
      outtextxy(110,15,"INSTRUCTIONS");
      setcolor(10);
      settextstyle(7,0,3);
      outtextxy(90,80,"TIC TAC TOE is a popular game also");
      outtextxy(120,100,"known as noughts and crosses.");
      setcolor(15);
      settextstyle(0,0,5);
      outtextxy(10,110,".");
      settextstyle(2,0,6);
      outtextxy(40,130," You can play this game with computer or another  player.");
      settextstyle(0,0,5);
      outtextxy(10,140,".");
      settextstyle(2,0,6);
      outtextxy(40,160," Player has to try and complete a row(horizontal,vertical");
      outtextxy(40,180," or diagonal)with his crosses against the computer or another");
      outtextxy(40,200," player . The player has to enter the coordinates where he");
      outtextxy(40,220," wants to put his cross .");
      settextstyle(2,0,6);
      outtextxy(40,250," eg: To fill first row second column enter x=0,y=1  ");
      settextstyle(1,0,3);
      outtextxy(317,280,"X");
      line(350,280,350,370);
      line(300,280,300,370);
      line(250,310,400,310);
      line(250,340,400,340);
      settextstyle(2,0,6);
      outtextxy(40,370,"The coodinates cannot be greater than 2 and less than 0");
      settextstyle(0,0,5);
      outtextxy(10,380,".");
      settextstyle(2,0,6);
      outtextxy(40,400," One who does this first is the winner .");
      setcolor(1);
      settextstyle(2,0,6);
      outtextxy(380,430,"press any key to return ...");
      getch();
      setbkcolor(1);
      cleardevice();
    }


    void game()
     {
      textbackground(GREEN);
      textcolor(WHITE);
      clrscr();
      sum=0;
      cout<<endl<<"\t\t\t  ~'~'~'~'~'~'~'~'~`~'~'~'~"<<endl;
      cout<<"\t\t\t  |      TIC TAC TOE      |"<<endl;
      cout<<"\t\t\t  ~'~'~'~'~'~'~'~'~`~'~'~'~"<<endl;
      textcolor(RED);
      clreol();
      cout<<"\t\t\t     enter -1 to go to menu"<<endl;                                                                                                  //
      cout<<"\t\t\t   --------------------------";
      cout<<endl<<endl;
      for(i=0;i<3;++i)
      for(j=0;j<3;++j)
      tic[i][j]=' ';                     //assigning space' 'to all elements of the matrix
      display();                         //display function call
      cout<<endl<<endl;
      user();
     }
    void setgraph()
      {
       int mode,driver=DETECT;
       initgraph(&driver,&mode,"\\tc");
     }
    void display()                          //display function call
    {
      cout<<" \t\t\t   0  1  2"<<endl;
      for(t=0;t<3;++t)
	{
	 cout<<"\t\t\t"<<t<<" "<<tic[t][0]<<" |"<<tic[t][1]<<"  |"<<tic[t][2]<<endl;     //figure formation
	 if(t!=2)
	   cout<<"  \t\t\t  --|---|--"<<endl;
	}
    }
    void user()                          //user function definition
    {
      do
      {
	cout<<endl;
	if(p=='2')
	  {
	    textcolor(RED);
	    clreol();
	    cout<<"  PLAYER 1's MOVE"<<endl;
	  }
	cout<<endl;
	cout<<"  ENTER THE COORDINATES WHERE YOU WANT TO PUT YOUR X "<<endl;
	cout<<"  x=";
	cin>>x;
	if(x==-1)
	   menu();
	cout<<endl;
	cout<<"  y=";
	cin>>y;
	if((x<0)||(x>2)||(y<0)||(y>2))           //check for valid coordinates
	  {
	    cout<<endl;
	    textcolor(BLUE);
	    clreol();
	    cout<<" *.ENTER THE CORRECT COORDINATES!!!!"<<endl<<endl;
	  }
      }while((x<0)||(x>2)||(y<0)||(y>2));

	 if(tic[x][y]==' ')                  //check for vacant space at entered coordinates
	   {
	     tic[x][y]='X';
	     cout<<endl<<endl;
	     ++sum;
	     textbackground(GREEN);
	     textcolor(WHITE);
	     clrscr();
	     display();                     //calling function display
	   }
	 else
	   { textcolor(BLUE);
	     clreol();
	     cout<<"\t\tTHIS POSITION IS ALREADY FILLED."<<endl;
	     textcolor(BLUE);
	     clreol();
	     cout<<"\t\tCHOOSE SOME OTHER COORDINATES"<<endl;
	     user();                              //user function call
	   }

     d=check();                                  //check function call
     if(d==0)
       {
	 if(sum==9)
	    draw();
	 else
	   if(p=='1')
	     comp();                                 //comp function call
	   else
	     player2();
       }
     else
       {
	 cout<<endl;
	 player1win();

       }
       getch();
       menu();


    }
   void comp()
    {
       int a,b;
       cout<<endl;
       textcolor(RED);
       clreol();
       cout<<"  This is the computer's move"<<endl<<endl;
       a=3,b=3;
       for(int x=0;x<3;++x)
	 {
	  if(tic[x][0]!=' '&& tic[x][0]== tic[x][1] && tic[x][2]==' ')
	      {
		 a=x;
		 b=2;
		 break;
	      }
	  else
	  if(tic[x][0]!=' '&& tic[x][0]== tic[x][2] && tic[x][1]==' ')
	      {
		 a=x;
		 b=1;
		 break;
	      }
	  else
	  if(tic[x][1]!=' '&& tic[x][1]== tic[x][2] && tic[x][0]==' ')
	      {
		 a=x;
		 b=0;
		 break;
	      }
	 }
      if(a==3)
	{
	 for(int x=0;x<3;++x)
	    {
	     if(tic[0][x]!=' '&& tic[0][x]== tic[1][x] && tic[2][x]==' ')
	      {
		 a=2;
		 b=x;
		 break;
	      }
	  else
	  if(tic[0][x]!=' '&& tic[0][x]== tic[2][x] && tic[1][x]==' ')
	      {
		 a=1;
		 b=x;
		 break;
	      }
	  else
	  if(tic[1][x]!=' '&& tic[1][x]== tic[2][x] && tic[0][x]==' ')
	      {
		 a=0;
		 b=x;
		 break;
	      }
	 }
	 }
      if(a==3)
	{
	  if(tic[0][0]!=' '&& tic[0][0]== tic[1][1] && tic[2][2]==' ')
	      {
		 a=2;
		 b=2;
	      }
	   else
	  if(tic[0][0]!=' '&& tic[0][0]== tic[2][2] && tic[1][1]==' ')
	      {
		 a=1;
		 b=1;
	      }
	  else
	  if(tic[1][1]!=' '&& tic[1][1]== tic[2][2] && tic[0][0]==' ')
	      {
		 a=0;
		 b=0;
	      }
	  else
	  if(tic[0][2]!=' '&& tic[0][2]== tic[1][1] && tic[2][0]==' ')
	      {
		 a=2;
		 b=0;

	      }
	  else
	  if(tic[0][2]!=' '&& tic[0][2]== tic[2][0] && tic[1][1]==' ')
	      {
		 a=1;
		 b=1;

	      }
	  else
	  if(tic[1][1]!=' '&& tic[1][1]== tic[2][0] && tic[0][2]==' ')
	      {
		 a=0;
		 b=2;

	      }
	   }
	  if(a==3)
	   {
	    for(int m=0;m<=2;++m)
	      for(int l=0;l<=2;++l)
		    {
		      if(tic[m][l]==' ')
			 {
			   a=m;
			   b=l;
			   break;
			 }
		    }
	  }

       tic[a][b]='O';
       ++sum;
       display();
       d=check();
       if(d==0)
	  if(sum==9)
	    draw();
	  else
	     user();
       else
	 {
	   cout<<endl;
	   getch();
	   pcwin();

	 }
	   getch();
	   menu();
     }
    void player2()
     {
       do
	{
	  cout<<endl;
	  textcolor(RED);
	  clreol();
	  cout<<"  PLAYER 2's MOVE"<<endl<<endl;
	  cout<<"  ENTER THE COORDINATES WHERE YOU WANT TO PUT YOUR 'O' "<<endl;
	  cout<<"  x=";
	  cin>>x;
	  if(x==-1)
	     menu();
	  cout<<endl;
	  cout<<"  y=";
	  cin>>y;
	  if((x<0)||(x>2)||(y<0)||(y>2))            //check for valid coordinates
	    {
	     cout<<endl;
	     textcolor(BLUE);
	     clreol();
	     cout<<" *.ENTER THE CORRECT COORDINATES!!!!"<<endl<<endl;
	    }
	}while((x<0)||(x>2)||(y<0)||(y>2));

       if(tic[x][y]==' ')                        //check for vacant space at entered coordinates
	   {
	     tic[x][y]='O';
	     cout<<endl<<endl;
	     ++sum;
	     textbackground(GREEN);
	     textcolor(WHITE);
	     clrscr();
	     display();                     //calling function display
	   }
       else
	   {
	     textcolor(BLUE);
	     clreol();
	     cout<<"\t\tTHIS POSITION IS ALREADY FILLED."<<endl;
	     textcolor(BLUE);
	     clreol();
	     cout<<"\t\tCHOOSE SOME OTHER COORDINATES"<<endl;
	     player2();                              //user function call
	   }

     d=check();                                  //check function call
     if(d==0)
       {
	 if(sum==9)
	    draw();
	 else
	    user();	                        //user function call
       }
     else
       {
	 cout<<endl;
	 player2win();

       }
   }

    check()
     {
       horizontal();                                 //horcheck function call
       vertical();                                //vertical function call
       diagonal();                               //diagonal function call
       return(d||e||f);
     }
    horizontal()                                   //horizontal function definition
     {
       if(((tic[0][0]==tic[0][1])&&(tic[0][1]==tic[0][2])
       &&(tic[0][1]!=' '))||((tic[1][0]==tic[1][1])&&(tic[1][1]==tic[1][2])
       &&(tic[1][1]!=' '))||((tic[2][0]==tic[2][1])&&(tic[2][1]==tic[2][2])
       &&(tic[2][2]!=' ')))
       d=1;                                 //returns 1 if all 3 elements of any horizontal line are same
       else
       d=0;
       return d;
     }
    vertical()                                  //vertical function definition
     {
	 if(((tic[0][0]==tic[1][0])&&(tic[1][0]==tic[2][0])        //checks each element of a vertical line to be same
	   &&(tic[0][0]!=' '))||((tic[0][1]==tic[1][1])
	   &&(tic[1][1]==tic[2][1])&&(tic[0][1]!=' '))||((tic[0][2]==tic[1][2])
	   &&(tic[1][2]==tic[2][2])&&(tic[0][2]!=' ')))
	 e=1;                                 //returns 1 if all 3 elements of any vertical line are same
	 else
	 e=0;
	 return e;
     }
    diagonal()                                                   //diagonal function definition
     {
	if(((tic[0][0]==tic[1][1])&&(tic[1][1]==tic[2][2])        //checks each element of a diagonal line to be same
	   &&(tic[0][0]!=' '))||((tic[0][2]==tic[1][1])
	   &&(tic[1][1]==tic[2][0])&&(tic[1][1]!=' ')))
	 f=1;                                 //returns 1 if all 3 elements of any diagonal line are same
	 else
	 f=0;
	 return f;
     }
     void player1win()
       {
	 setgraph();
	 for(int i=0;i<230;i+=5)
	    {
	      setcolor(4);
	      rectangle(235-i,241-i,395+i,241+i);
	      delay(80);
	    }

	for(i=0;i<40;++i)
	   {
	     setcolor(random(15));
	     settextstyle(4,0,5);
	     outtextxy(100,150,"CONGRATULATIONS ");
	     settextstyle(7,0,4);
	     if(p=='2')
	       outtextxy(120,220,"PLAYER 1 is the winner");
	     else
	       outtextxy(250,220,"YOU WON");
	     delay(20);
	   }
	setcolor(15);
	settextstyle(4,0,5);
	outtextxy(100,150,"CONGRATULATIONS ");
	settextstyle(7,0,4);
	if(p=='2')
	    outtextxy(120,220,"PLAYER 1 is the winner");
	else
	    outtextxy(250,220,"YOU WON");
	circle(320,320,40);
	circle(300,300,5);
	circle(340,300,5);
	outtextxy(318,300,"l");
	arc(320,340,180,360,8);

      }
       void player2win()
       {
	 setgraph();
	 for(int i=0;i<230;i+=5)
	    {
	      setcolor(5);
	      rectangle(235-i,241-i,395+i,241+i);
	      delay(80);
	    }

	for(i=0;i<40;++i)
	   {
	     setcolor(random(15));
	     settextstyle(4,0,5);
	     outtextxy(100,150,"CONGRATULATIONS ");
	     settextstyle(7,0,4);
	     outtextxy(120,220,"PLAYER 2 is the winner");
	     delay(20);
	  }
	setcolor(15);
	settextstyle(4,0,5);
	outtextxy(100,150,"CONGRATULATIONS ");
	settextstyle(7,0,4);
	outtextxy(120,220,"PLAYER 2 is the winner");
	circle(320,320,40);
	circle(300,300,5);
	circle(340,300,5);
	outtextxy(318,300,"l");
	arc(320,340,180,360,8);
      }
    void pcwin()
       {
	 setgraph();
	 for(int i=0;i<230;i+=5)
	    {
	      setcolor(1);
	      rectangle(235-i,241-i,395+i,241+i);
	      delay(80);
	    }

	for(i=0;i<40;++i)
	   {
	     setcolor(random(15));
	     settextstyle(4,0,5);
	     outtextxy(230,150,"OOPS !!! ");
	     settextstyle(7,0,4);
	       outtextxy(250,220,"You Lost");

	     delay(20);
	  }
	 setcolor(15);
	 settextstyle(4,0,5);
	 outtextxy(230,150,"OOPS !!! ");
	 settextstyle(7,0,4);
	 outtextxy(250,220,"You Lost");
	 circle(320,320,40);
	 circle(300,300,5);
	 circle(340,300,5);
	 outtextxy(318,300,"l");
	 arc(320,350,0,180,8);
       }
      void draw()
       {
	 setgraph();
	 for(int i=0;i<230;i+=5)
	    {
	      if (i%2==0)
		setcolor(1);
	      else
		setcolor(4);
	      rectangle(235-i,241-i,395+i,241+i);
	      delay(80);
	    }

	 for(i=0;i<40;++i)
	   {
	     setcolor(random(15));
	     settextstyle(4,0,5);
	     outtextxy(230,150,"DRAW!!! ");
	     settextstyle(7,0,4);
	       outtextxy(130,220,"Better Luck Next Time..");
	     delay(20);
	   }
	 setcolor(15);
	 settextstyle(4,0,5);
	 outtextxy(230,150,"DRAW!!!");
	 settextstyle(7,0,4);
	 outtextxy(130,220,"Better Luck Next Time..");
	 circle(320,320,40);
	 circle(300,300,5);
	 circle(340,300,5);
	 outtextxy(318,300,"l");
	 outtextxy(313,320,"o");
	 getch();
      }










































































































