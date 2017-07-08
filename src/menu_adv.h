
const char* MAdv_Help_Line = "Use mouse to navigate, Esc to exit current menu";
int MAdv_Mouse_X,MAdv_Mouse_Y,MAdv_Button;

class Menu_Adv {
      public:
	     char* MAdv_Title;
	     char* MAdv_Desc;
	     char* MAdv_Desc2;
	     char* MAdv_Desc3;
	     char* MAdv_Item_Title[12];
	     char* MAdv_Item_Desc[12];
	     char* MAdv_Item_Desc2[12];
	     char* MAdv_Item_Sel_Title;
	     int MAdv_Item_Tol;

	     static int MAdv_Item_BkColor;
	     static int MAdv_Item_FrColor;
	     static int MAdv_Item_BdrColor;

	     static int MAdv_Item_Sel_BkColor;
	     static int MAdv_Item_Sel_FrColor;
	     static int MAdv_Item_Sel_BdrColor;

	     static int MAdv_Item_Click_BkColor;
	     static int MAdv_Item_Click_FrColor;
	     static int MAdv_Item_Click_BdrColor;

	     static int MAdv_Title_BkColor;
	     static int MAdv_Title_FrColor;
	     static int MAdv_Title_BdrColor;

	     static int MAdv_Title_FntTp;
	     static int MAdv_Item_FntTp;
	     static int MAdv_Title_FntSz;
	     static int MAdv_Item_FntSz;
	     static int MAdv_BkColor;

       private:
	       int MAdv_Item_Sel_Curr;
	       int Asp_Rat,Asp_Rat_Sel;
	       int MAdv_Is_DeCatenated;

	       static int MAdv_Item_Height;
	       static int MAdv_Item_Sel_Height;

	       static int MAdv_Time;

       private:
	       void MAdv_DeCatenate();
	       void MAdv_Draw_Bar(int,int);
	       void MAdv_Draw_Bar_Sel(int,int);
	       void MAdv_Draw_Bar_Click(int,int);
	       void MAdv_Item_Cursored_Get();
	       void MAdv_Item_Sel_Set(int,int,int);
	       int MAdv_Item_Sel_Get(int);
	       void MAdv_Prt_Time();

	public:
	       Menu_Adv();
	       void MAdv_Init(int);
	       int MAdv_Navigate();

	       };

int Menu_Adv::MAdv_Item_BkColor;
int Menu_Adv::MAdv_Item_FrColor;
int Menu_Adv::MAdv_Item_BdrColor;

int Menu_Adv::MAdv_Item_Sel_BkColor;
int Menu_Adv::MAdv_Item_Sel_FrColor;
int Menu_Adv::MAdv_Item_Sel_BdrColor;

int Menu_Adv::MAdv_Item_Click_BkColor;
int Menu_Adv::MAdv_Item_Click_FrColor;
int Menu_Adv::MAdv_Item_Click_BdrColor;

int Menu_Adv::MAdv_Title_BkColor;
int Menu_Adv::MAdv_Title_FrColor;
int Menu_Adv::MAdv_Title_BdrColor;

int Menu_Adv::MAdv_Item_Height;
int Menu_Adv::MAdv_Item_Sel_Height;

int Menu_Adv::MAdv_Title_FntTp;
int Menu_Adv::MAdv_Item_FntTp;
int Menu_Adv::MAdv_Title_FntSz;
int Menu_Adv::MAdv_Item_FntSz;
int Menu_Adv::MAdv_BkColor;

int Menu_Adv::MAdv_Time;

Menu_Adv::Menu_Adv() {
		   MAdv_Item_Sel_Curr=-1;
		   MAdv_Item_Height=25;
		   MAdv_Item_Sel_Height=50;
		   MAdv_Is_DeCatenated=0;

		   MAdv_Item_Sel_Title=(char*)calloc(50,sizeof(char));
		   strset(MAdv_Item_Sel_Title,NULL);

		   MAdv_Title=(char*)calloc(50,sizeof(char));
		   strset(MAdv_Title,NULL);
		   MAdv_Desc=(char*)calloc(50,sizeof(char));
		   strset(MAdv_Desc,NULL);
		   MAdv_Desc2=(char*)calloc(50,sizeof(char));
		   strset(MAdv_Desc2,NULL);
		   MAdv_Desc3=(char*)calloc(50,sizeof(char));
		   strset(MAdv_Desc3,NULL);

		   int Count=0;

		   while (Count<12) {
			 MAdv_Item_Title[Count]=(char*)calloc(50,sizeof(char));
			 MAdv_Item_Desc[Count]=(char*)calloc(50,sizeof(char));
			 MAdv_Item_Desc2[Count]=(char*)calloc(50,sizeof(char));

			 strset(MAdv_Item_Title[Count],NULL);
			 strset(MAdv_Item_Desc[Count],NULL);
			 strset(MAdv_Item_Desc2[Count],NULL);

			 Count++;
				     }
		     }

void Menu_Adv::MAdv_Prt_Time() {

	       struct time MAdv_SysTime;
	       char hr[3],min[3],sec[3];
	       int a;

	       gettime(&MAdv_SysTime);
	       if (int(MAdv_SysTime.ti_sec)!=MAdv_Time) {

		   if ((MAdv_Mouse_X>549)&&(MAdv_Mouse_Y>5)&&
		       (MAdv_Mouse_X<621)&&(MAdv_Mouse_Y<25))
		       Mouse_Hide();

		   setcolor(MAdv_Title_BkColor);
		   setfillstyle(1,MAdv_Title_BkColor);
		   bar(550,6,620,24);

		   a=int(MAdv_SysTime.ti_hour);
		   if (a>12) a=a-12;

		   itoa(a, hr, 10);
		   itoa(int(MAdv_SysTime.ti_min), min, 10);
		   itoa(int(MAdv_SysTime.ti_sec), sec, 10);

		   setcolor(MAdv_Title_FrColor);
		   settextstyle(MAdv_Title_FntTp,0,MAdv_Title_FntSz);

		   outtextxy(550,12,hr);
		   outtextxy(552+textwidth(hr),12,":");
		   outtextxy(554+textwidth(hr)+textwidth(":"),12,min);
		   outtextxy(556+textwidth(hr)+textwidth(min)+textwidth(":")
			     ,12,":");
		   outtextxy(558+textwidth(hr)+textwidth(min)+2*
			     textwidth(":"),12,sec);

		   if ((MAdv_Mouse_X>549)&&(MAdv_Mouse_Y>5)&&
		       (MAdv_Mouse_X<621)&&(MAdv_Mouse_Y<25))
		       Mouse_Show();

		   MAdv_Time=int(MAdv_SysTime.ti_sec);
							    }
	       return;

				}

void Menu_Adv::MAdv_Draw_Bar(int Count,int Y) {

			     Mouse_Hide();
			     setcolor(MAdv_BkColor);
			     setlinestyle(0,1,3);
			     line(0,Y,350,Y);
			     line(0,Y+MAdv_Item_Height-3,350,Y+MAdv_Item_Height-3);

			     setcolor(MAdv_Item_BdrColor);
			     setlinestyle(0,1,1);
			     rectangle(0,Y+2,350,Y+MAdv_Item_Height-2);

			     setcolor(MAdv_Item_BkColor);
			     setfillstyle(1,MAdv_Item_BkColor);
			     bar(1,Y+3,349,Y+MAdv_Item_Height-3);

			     setcolor(MAdv_Item_FrColor);
			     settextstyle(MAdv_Item_FntTp,0,MAdv_Item_FntSz);
			     outtextxy(50,Y+9,MAdv_Item_Title[Count]);
			     Mouse_Show();

					    }

void Menu_Adv::MAdv_Draw_Bar_Sel(int Count,int Y) {

				Mouse_Hide();
				setcolor(MAdv_BkColor);
				setlinestyle(0,1,3);
				line(0,Y,350,Y);
				line(0,Y+MAdv_Item_Sel_Height-3,350,
				    Y+MAdv_Item_Sel_Height-3);

				setcolor(MAdv_Item_Sel_BdrColor);
				setfillstyle(1,MAdv_Item_Sel_BdrColor);
				bar(0,Y+2,350,Y+MAdv_Item_Sel_Height-2);

				setcolor(MAdv_Item_Sel_BkColor);
				setfillstyle(1,MAdv_Item_Sel_BkColor);
				bar(1,Y+3,349,Y+MAdv_Item_Sel_Height-3);

				setcolor(MAdv_Item_Sel_FrColor);
				settextstyle(MAdv_Item_FntTp,0,
					    MAdv_Item_FntSz);
				outtextxy(20,Y+9,MAdv_Item_Title[Count]);
				outtextxy(50,Y+9+textheight("f")+7
					 ,MAdv_Item_Desc[Count]);
				outtextxy(50,Y+9+2*textheight("f")+10
					 ,MAdv_Item_Desc2[Count]);
				Mouse_Show();

					    }

void Menu_Adv::MAdv_Draw_Bar_Click(int Count,int Y) {

				   Mouse_Hide();
				   setcolor(MAdv_Item_Click_BdrColor);
				   setlinestyle(0,1,1);
				   rectangle(0,Y+2,350,Y+MAdv_Item_Sel_Height-2);

				   setcolor(MAdv_Item_Click_BkColor);
				   setfillstyle(1,MAdv_Item_Click_BkColor);
				   bar(1,Y+3,349,Y+MAdv_Item_Sel_Height-3);

				   setcolor(MAdv_Item_Click_FrColor);
				   settextstyle(MAdv_Item_FntTp,0,
					       MAdv_Item_FntSz);
				   outtextxy(20,Y+9,MAdv_Item_Title[Count]);
				   outtextxy(50,Y+9+textheight("f")+7
					    ,MAdv_Item_Desc[Count]);
				   outtextxy(50,Y+9+2*textheight("f")+10
					    ,MAdv_Item_Desc2[Count]);
				   Mouse_Show();

				    }

void Menu_Adv::MAdv_Item_Sel_Set(int Status,int Item_New,int Force_Ref=0) {

/*

#####################################
	  Heart of Menus            .
	Handled Exceptions          .
#####################################

Status      Meaning                 .
1           Mouse was in, now is out.
2           Mouse was out, now is in.
3           Mouse was in, now is in (
	    same item)              .
4           Mouse was in, now is in (
	    different item)         .
5           Mouse was out, now is out

*/


				 int Count=0;
				 int Item_A,Item_B;


				 //Handled Exception 1

				 if (Status==1) {
				     if ((MAdv_Item_Sel_Curr==-1)&&
					(Force_Ref==0)) return;
				     Mouse_Hide();
				     setcolor(MAdv_BkColor);
				     setfillstyle(1,MAdv_BkColor);

				     bar(0,Asp_Rat_Sel,350,Asp_Rat);
				     bar(0,Asp_Rat+MAdv_Item_Tol*MAdv_Item_Height-1,
					350,Asp_Rat_Sel+(MAdv_Item_Tol-1)*
					MAdv_Item_Height+MAdv_Item_Sel_Height);
				     Mouse_Show();

				     while(Count<MAdv_Item_Tol) {
					   MAdv_Draw_Bar(Count,Asp_Rat+Count
							*MAdv_Item_Height);
					   Count++;
								}
				     MAdv_Item_Sel_Curr=-1;
				     return;
						     }

				 //Handled Exception 2

				 if (Status==2) {
				     if ((MAdv_Item_Sel_Curr!=-1)
					&&(Force_Ref==0)) return;

				     while(Count<MAdv_Item_Tol) {

					   if (Count==Item_New)
					       MAdv_Draw_Bar_Sel(Count,
								Asp_Rat_Sel+
								Count*MAdv_Item_Height);

					   else if (Count<Item_New)
					       MAdv_Draw_Bar(Count,
							    Asp_Rat_Sel+
							    Count*MAdv_Item_Height);

					   else if (Count>Item_New)
					       MAdv_Draw_Bar(Count,
							    Asp_Rat_Sel+
							    Count*MAdv_Item_Height
							    +(MAdv_Item_Sel_Height-
							    MAdv_Item_Height));

					   Count++;
								}

				     MAdv_Item_Sel_Curr=Item_New;
				     return;
						     }

				     //Handled Exception 3 ( not required )

				     //Handled Exception 4

				     if (Status==4) {
					 if ((Item_New==MAdv_Item_Sel_Curr)
					    &&(Force_Ref==0)) return;

					 if (Item_New>MAdv_Item_Sel_Curr) {
					     Item_A=MAdv_Item_Sel_Curr;
					     Item_B=Item_New;
									  }
					 else {
					     Item_A=Item_New;
					     Item_B=MAdv_Item_Sel_Curr;
					      }

					 Count=Item_A;
					 while (Count <= Item_B) {
					   if (Count==Item_New)
					       MAdv_Draw_Bar_Sel(Count,
								Asp_Rat_Sel+
								Count*MAdv_Item_Height);

					   else if (Count<Item_New)
					       MAdv_Draw_Bar(Count,
							    Asp_Rat_Sel+
							    Count*MAdv_Item_Height);

					   else if (Count>Item_New)
					       MAdv_Draw_Bar(Count,
							    Asp_Rat_Sel+
							    Count*MAdv_Item_Height
							    +(MAdv_Item_Sel_Height-
							    MAdv_Item_Height));

					   Count++;
								  }
					   MAdv_Item_Sel_Curr=Item_New;
					   return;
								}

					   //Handled Exception 5 ( Not Required )

						}

int Menu_Adv::MAdv_Item_Sel_Get(int Y) {

/*

#############################
      Stimuli of menus      .
   Item Selection Locator   .

*/

				if (MAdv_Item_Sel_Curr==-1) {
				    if (Y<Asp_Rat) return -1;
				    Y=Y-Asp_Rat;
				    if (Y>=MAdv_Item_Height*MAdv_Item_Tol) return -1;

				    return Y/MAdv_Item_Height;
							    }
				else {
				    if (Y<Asp_Rat_Sel) return -1;
				    Y=Y-Asp_Rat_Sel;
				    if (Y>=(MAdv_Item_Height*(MAdv_Item_Tol-1))
					+MAdv_Item_Sel_Height) return -1;

				    int Sel_Y=MAdv_Item_Sel_Curr*
					      MAdv_Item_Height;

				    if (Y<Sel_Y) return Y/MAdv_Item_Height;

				    else {
					 Y=Y-Sel_Y;

					 if (Y<MAdv_Item_Sel_Height)
					    return MAdv_Item_Sel_Curr;

					 else {
					      Y=Y-MAdv_Item_Sel_Height;
					      return MAdv_Item_Sel_Curr+(Y/
						     MAdv_Item_Height)+1;
					      }
					  }
				     }
				}

void Menu_Adv::MAdv_Init(int Force_Ref=1) {
			 Mouse_Hide();
			 if (Force_Ref!=0) cleardevice();

			 Asp_Rat=(getmaxy()/2)-(MAdv_Item_Tol*
				 MAdv_Item_Height/2)+35;
			 Asp_Rat_Sel=Asp_Rat-((MAdv_Item_Sel_Height-
				     MAdv_Item_Height)/2);
			 MAdv_Time=99;

			 //BkGround
			 setcolor(MAdv_BkColor);
			 setfillstyle(1,MAdv_BkColor);
			 bar(0,0,getmaxx(),getmaxy());

			 //TitleBar
			 setcolor(MAdv_Title_BkColor);
			 setfillstyle(1,MAdv_Title_BkColor);
			 bar(0,5,450,25);
			 bar(490,5,getmaxx(),25);
			 pieslice(490,15,0,360,10);
			 bar(50,getmaxy()-25,getmaxx()-50,getmaxy()-5);
			 pieslice(50,getmaxy()-15,0,360,10);
			 pieslice(getmaxx()-50,getmaxy()-15,0,360,10);
			 pieslice(450,15,0,360,10);
			 pieslice(getmaxx(),15,0,360,10);
			 bar(0,40,getmaxx(),95);


			 //TitleBdr
			 setcolor(MAdv_Title_BdrColor);
			 setlinestyle(0,1,1);
			 line(490,5,getmaxx(),5);
			 line(50,getmaxy()-25,getmaxx()-50,getmaxy()-25);
			 line(0,5,450,5);
			 line(0,25,450,25);
			 line(0,95,getmaxx(),95);
			 line(0,40,getmaxx(),40);

			 arc(450,15,270,90,10);
			 arc(490,15,90,270,10);
			 line(490,25,getmaxx(),25);
			 line(50,getmaxy()-5,getmaxx()-50,getmaxy()-5);
			 arc(getmaxx()-50,getmaxy()-15,270,90,10);
			 arc(50,getmaxy()-15,90,270,10);

			 //PrtText Title and Helpline
			 setcolor(MAdv_Title_FrColor);
			 settextstyle(MAdv_Title_FntTp,0,MAdv_Title_FntSz);
			 outtextxy(230-textwidth(MAdv_Title)/2,12,MAdv_Title);

			 outtextxy(getmaxx()/2-textwidth(MAdv_Desc)/2
				  ,50,MAdv_Desc);
			 outtextxy(getmaxx()/2-textwidth(MAdv_Desc2)/2
				  ,55+textheight("f"),MAdv_Desc2);
			 outtextxy(getmaxx()/2-textwidth(MAdv_Desc3)/2
				  ,60+2*textheight("f"),MAdv_Desc3);

			 outtextxy(500,12,"Time ");
			 MAdv_Prt_Time();
			 outtextxy((getmaxx()/2)-(textwidth(MAdv_Help_Line)/2)
				  ,getmaxy()-11-textheight("f")
				  ,MAdv_Help_Line);

			 //PrtItems
			 int Count=0;
			 while(Count<MAdv_Item_Tol) {
			       MAdv_Draw_Bar(Count,Asp_Rat+Count
					    *MAdv_Item_Height);
			       Count++;
						    }

			 Mouse_Init();
			 Mouse_Show();
			 Mouse_Set_Recorded();
			   }


void Menu_Adv::MAdv_Item_Cursored_Get() {

/*

#################################
	 Brain of Menus         .
     User Response Handler      .

*/

			  long Key_Pressed;
			  int Mouse_in=-1;
			  int Item_New;

			  Start_Process:

			  while(bioskey(1)==0) {

			  Mouse_Get(&MAdv_Button,&MAdv_Mouse_X,
					  &MAdv_Mouse_Y);

			  MAdv_Prt_Time();

			  if (MAdv_Mouse_X<=350) {

			      Mouse_in=MAdv_Item_Sel_Get(MAdv_Mouse_Y);
			      if (Mouse_in!=MAdv_Item_Sel_Curr) {

				 if ((Mouse_in==-1)&&
				     (MAdv_Item_Sel_Curr!=-1))
				     MAdv_Item_Sel_Set(1,0);
				 if ((Mouse_in!=-1)&&
				     (MAdv_Item_Sel_Curr==-1))
				     MAdv_Item_Sel_Set(2,Mouse_in);
				 if ((Mouse_in!=-1)&&
				     (MAdv_Item_Sel_Curr!=-1))
				     MAdv_Item_Sel_Set(4,Mouse_in);
								 }
						  }
			      else if (MAdv_Item_Sel_Curr!=-1)
				       MAdv_Item_Sel_Set(1,0);

			      if ((MAdv_Button&1)&&
				  (MAdv_Item_Sel_Curr>-1)) {

				   MAdv_Draw_Bar_Click(MAdv_Item_Sel_Curr,
						       MAdv_Item_Sel_Curr*
						       MAdv_Item_Height+
						       Asp_Rat_Sel);
				   while(MAdv_Button&1) Mouse_Get(&MAdv_Button,
								  &MAdv_Mouse_X,
								  &MAdv_Mouse_Y);
				   Mouse_Record();
				   return;
						    }
						}

			  Key_Pressed = bioskey(0);
			  if (Key_Pressed==283) {
			      MAdv_Item_Sel_Curr=-1;
			      Mouse_Record();
			      return;
						}

			  goto Start_Process;
				       }

int Menu_Adv::MAdv_Navigate() {
			    MAdv_Item_Sel_Set(1,0,1);
			    MAdv_Item_Cursored_Get();
			    if (MAdv_Item_Sel_Curr>-1)
			       MAdv_Item_Sel_Title=MAdv_Item_Title[MAdv_Item_Sel_Curr];
			    return MAdv_Item_Sel_Curr;
			      }
