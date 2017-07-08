
const char* FAdv_Help_Line = "Use click to modify entry ,keyboard to enter values.";
int FAdv_Mouse_X,FAdv_Mouse_Y,FAdv_Button;

class Form_Adv {
      public:
	     char* FAdv_Title;
	     char* FAdv_Cmd_Title[12];
	     char* FAdv_Cmd_Desc[12];
	     char* FAdv_Cmd_Desc2[12];
	     char* FAdv_Cmd_Sel_Title;
	     int FAdv_Cmd_Tol;

	     Text_Adv FAdv_Ent[15];
	     int FAdv_Ent_Tol;

	     static int FAdv_Cmd_BkColor;
	     static int FAdv_Cmd_FrColor;
	     static int FAdv_Cmd_BdrColor;

	     static int FAdv_Cmd_Sel_BkColor;
	     static int FAdv_Cmd_Sel_FrColor;
	     static int FAdv_Cmd_Sel_BdrColor;

	     static int FAdv_Cmd_Click_BkColor;
	     static int FAdv_Cmd_Click_FrColor;
	     static int FAdv_Cmd_Click_BdrColor;

	     static int FAdv_Title_BkColor;
	     static int FAdv_Title_FrColor;
	     static int FAdv_Title_BdrColor;

	     static int FAdv_Title_FntTp;
	     static int FAdv_Cmd_FntTp;
	     static int FAdv_Title_FntSz;
	     static int FAdv_Cmd_FntSz;
	     static int FAdv_BkColor;

       private:
	       int FAdv_Cmd_Sel_Curr;
	       int Cmd_Asp_Rat,Cmd_Asp_Rat_Sel;
	       int FAdv_Is_DeCatenated;

	       int FAdv_Ent_Sel,FAdv_Ent_Act;
	       int Ent_Asp_Rat;

	       static int FAdv_Cmd_Height;
	       static int FAdv_Cmd_Sel_Height;

	       static int FAdv_Time;

       private:
	       void FAdv_DeCatenate();
	       void FAdv_Draw_Bar(int,int);
	       void FAdv_Draw_Bar_Sel(int,int);
	       void FAdv_Draw_Bar_Click(int,int);
	       void FAdv_Cmd_Cursored_Get();
	       int FAdv_Ent_Sel_Get(int);
	       void FAdv_Cmd_Sel_Set(int,int,int);
	       int FAdv_Cmd_Sel_Get(int);
	       void FAdv_Prt_Time();

	public:
	       Form_Adv();
	       void FAdv_Init(int);
	       int FAdv_Navigate();

	       };

int Form_Adv::FAdv_Cmd_BkColor;
int Form_Adv::FAdv_Cmd_FrColor;
int Form_Adv::FAdv_Cmd_BdrColor;

int Form_Adv::FAdv_Cmd_Sel_BkColor;
int Form_Adv::FAdv_Cmd_Sel_FrColor;
int Form_Adv::FAdv_Cmd_Sel_BdrColor;

int Form_Adv::FAdv_Cmd_Click_BkColor;
int Form_Adv::FAdv_Cmd_Click_FrColor;
int Form_Adv::FAdv_Cmd_Click_BdrColor;

int Form_Adv::FAdv_Title_BkColor;
int Form_Adv::FAdv_Title_FrColor;
int Form_Adv::FAdv_Title_BdrColor;

int Form_Adv::FAdv_Cmd_Height;
int Form_Adv::FAdv_Cmd_Sel_Height;

int Form_Adv::FAdv_Title_FntTp;
int Form_Adv::FAdv_Cmd_FntTp;
int Form_Adv::FAdv_Title_FntSz;
int Form_Adv::FAdv_Cmd_FntSz;
int Form_Adv::FAdv_BkColor;

int Form_Adv::FAdv_Time;

Form_Adv::Form_Adv() {
		   FAdv_Cmd_Sel_Curr=-1;
		   FAdv_Cmd_Height=25;
		   FAdv_Cmd_Sel_Height=50;
		   FAdv_Is_DeCatenated=0;
		   FAdv_Cmd_Sel_Title=(char*)calloc(50,sizeof(char));
		   strset(FAdv_Cmd_Sel_Title,NULL);

		   FAdv_Ent_Sel=-1;
		   FAdv_Ent_Act=-1;

		   int Count=0;

		   while (Count<12) {
			 FAdv_Cmd_Title[Count]=(char*)calloc(50,sizeof(char));
			 FAdv_Cmd_Desc[Count]=(char*)calloc(50,sizeof(char));
			 FAdv_Cmd_Desc2[Count]=(char*)calloc(50,sizeof(char));
			 strset(FAdv_Cmd_Title[Count],NULL);
			 strset(FAdv_Cmd_Desc[Count],NULL);
			 strset(FAdv_Cmd_Desc2[Count],NULL);
			 Count++;
				     }
		     }

void Form_Adv::FAdv_Prt_Time() {

	       struct time FAdv_SysTime;
	       char hr[3],min[3],sec[3];
	       int a;

	       gettime(&FAdv_SysTime);
	       if (int(FAdv_SysTime.ti_sec)!=FAdv_Time) {

		   if ((FAdv_Mouse_X>549)&&(FAdv_Mouse_Y>5)&&
		       (FAdv_Mouse_X<621)&&(FAdv_Mouse_Y<25))
		       Mouse_Hide();

		   setcolor(FAdv_Title_BkColor);
		   setfillstyle(1,FAdv_Title_BkColor);
		   bar(550,6,620,24);

		   a=int(FAdv_SysTime.ti_hour);
		   if (a>12) a=a-12;

		   itoa(a, hr, 10);
		   itoa(int(FAdv_SysTime.ti_min), min, 10);
		   itoa(int(FAdv_SysTime.ti_sec), sec, 10);

		   setcolor(FAdv_Title_FrColor);
		   settextstyle(FAdv_Title_FntTp,0,FAdv_Title_FntSz);

		   outtextxy(550,12,hr);
		   outtextxy(552+textwidth(hr),12,":");
		   outtextxy(554+textwidth(hr)+textwidth(":"),12,min);
		   outtextxy(556+textwidth(hr)+textwidth(min)+textwidth(":")
			     ,12,":");
		   outtextxy(558+textwidth(hr)+textwidth(min)+2*
			     textwidth(":"),12,sec);

		   if ((FAdv_Mouse_X>549)&&(FAdv_Mouse_Y>5)&&
		       (FAdv_Mouse_X<621)&&(FAdv_Mouse_Y<25))
		       Mouse_Show();

		   FAdv_Time=int(FAdv_SysTime.ti_sec);
							    }
	       return;

				}


void Form_Adv::FAdv_Draw_Bar(int Count,int Y) {

			     Mouse_Hide();
			     setcolor(FAdv_BkColor);
			     setlinestyle(0,1,3);
			     line(0,Y,350,Y);
			     line(0,Y+FAdv_Cmd_Height-3,350,Y+FAdv_Cmd_Height-3);

			     setcolor(FAdv_Cmd_BdrColor);
			     setlinestyle(0,1,1);
			     rectangle(0,Y+2,350,Y+FAdv_Cmd_Height-2);

			     setcolor(FAdv_Cmd_BkColor);
			     setfillstyle(1,FAdv_Cmd_BkColor);
			     bar(1,Y+3,349,Y+FAdv_Cmd_Height-3);

			     setcolor(FAdv_Cmd_FrColor);
			     settextstyle(FAdv_Cmd_FntTp,0,FAdv_Cmd_FntSz);
			     outtextxy(50,Y+9,FAdv_Cmd_Title[Count]);
			     Mouse_Show();

					    }

void Form_Adv::FAdv_Draw_Bar_Sel(int Count,int Y) {

				Mouse_Hide();
				setcolor(FAdv_BkColor);
				setlinestyle(0,1,3);
				line(0,Y,350,Y);
				line(0,Y+FAdv_Cmd_Sel_Height-3,350,
				    Y+FAdv_Cmd_Sel_Height-3);

				setcolor(FAdv_Cmd_Sel_BdrColor);
				setfillstyle(1,FAdv_Cmd_Sel_BdrColor);
				bar(0,Y+2,350,Y+FAdv_Cmd_Sel_Height-2);

				setcolor(FAdv_Cmd_Sel_BkColor);
				setfillstyle(1,FAdv_Cmd_Sel_BkColor);
				bar(1,Y+3,349,Y+FAdv_Cmd_Sel_Height-3);

				setcolor(FAdv_Cmd_Sel_FrColor);
				settextstyle(FAdv_Cmd_FntTp,0,
					    FAdv_Cmd_FntSz);
				outtextxy(20,Y+9,FAdv_Cmd_Title[Count]);
				outtextxy(50,Y+9+textheight("f")+7
					 ,FAdv_Cmd_Desc[Count]);
				outtextxy(50,Y+9+2*textheight("f")+10
					 ,FAdv_Cmd_Desc2[Count]);
				Mouse_Show();

					    }

void Form_Adv::FAdv_Draw_Bar_Click(int Count,int Y) {

				   Mouse_Hide();
				   setcolor(FAdv_Cmd_Click_BdrColor);
				   setlinestyle(0,1,1);
				   rectangle(0,Y+2,350,Y+FAdv_Cmd_Sel_Height-2);

				   setcolor(FAdv_Cmd_Click_BkColor);
				   setfillstyle(1,FAdv_Cmd_Click_BkColor);
				   bar(1,Y+3,349,Y+FAdv_Cmd_Sel_Height-3);

				   setcolor(FAdv_Cmd_Click_FrColor);
				   settextstyle(FAdv_Cmd_FntTp,0,
					       FAdv_Cmd_FntSz);
				   outtextxy(20,Y+9,FAdv_Cmd_Title[Count]);
				   outtextxy(50,Y+9+textheight("f")+7
					    ,FAdv_Cmd_Desc[Count]);
				   outtextxy(50,Y+9+2*textheight("f")+10
					    ,FAdv_Cmd_Desc2[Count]);
				   Mouse_Show();

				    }

void Form_Adv::FAdv_Cmd_Sel_Set(int Status,int Cmd_New,int Force_Ref=0) {

/*

#####################################
	  Heart of Forms            .
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
				 int Cmd_A,Cmd_B;


				 //Handled Exception 1

				 if (Status==1) {
				     if ((FAdv_Cmd_Sel_Curr==-1)&&
					(Force_Ref==0)) return;
				     Mouse_Hide();
				     setcolor(FAdv_BkColor);
				     setfillstyle(1,FAdv_BkColor);

				     bar(0,Cmd_Asp_Rat_Sel,350,Cmd_Asp_Rat);
				     bar(0,Cmd_Asp_Rat+FAdv_Cmd_Tol*FAdv_Cmd_Height-1,
					350,Cmd_Asp_Rat_Sel+(FAdv_Cmd_Tol-1)*
					FAdv_Cmd_Height+FAdv_Cmd_Sel_Height);
				     Mouse_Show();

				     while(Count<FAdv_Cmd_Tol) {
					   FAdv_Draw_Bar(Count,Cmd_Asp_Rat+Count
							*FAdv_Cmd_Height);
					   Count++;
								}
				     FAdv_Cmd_Sel_Curr=-1;
				     return;
						     }

				 //Handled Exception 2

				 if (Status==2) {
				     if ((FAdv_Cmd_Sel_Curr!=-1)
					&&(Force_Ref==0)) return;

				     while(Count<FAdv_Cmd_Tol) {

					   if (Count==Cmd_New)
					       FAdv_Draw_Bar_Sel(Count,
								Cmd_Asp_Rat_Sel+
								Count*FAdv_Cmd_Height);

					   else if (Count<Cmd_New)
					       FAdv_Draw_Bar(Count,
							    Cmd_Asp_Rat_Sel+
							    Count*FAdv_Cmd_Height);

					   else if (Count>Cmd_New)
					       FAdv_Draw_Bar(Count,
							    Cmd_Asp_Rat_Sel+
							    Count*FAdv_Cmd_Height
							    +(FAdv_Cmd_Sel_Height-
							    FAdv_Cmd_Height));

					   Count++;
								}

				     FAdv_Cmd_Sel_Curr=Cmd_New;
				     return;
						     }

				     //Handled Exception 3 ( not required )

				     //Handled Exception 4

				     if (Status==4) {
					 if ((Cmd_New==FAdv_Cmd_Sel_Curr)
					    &&(Force_Ref==0)) return;

					 if (Cmd_New>FAdv_Cmd_Sel_Curr) {
					     Cmd_A=FAdv_Cmd_Sel_Curr;
					     Cmd_B=Cmd_New;
									  }
					 else {
					     Cmd_A=Cmd_New;
					     Cmd_B=FAdv_Cmd_Sel_Curr;
					      }

					 Count=Cmd_A;
					 while (Count <= Cmd_B) {
					   if (Count==Cmd_New)
					       FAdv_Draw_Bar_Sel(Count,
								Cmd_Asp_Rat_Sel+
								Count*FAdv_Cmd_Height);

					   else if (Count<Cmd_New)
					       FAdv_Draw_Bar(Count,
							    Cmd_Asp_Rat_Sel+
							    Count*FAdv_Cmd_Height);

					   else if (Count>Cmd_New)
					       FAdv_Draw_Bar(Count,
							    Cmd_Asp_Rat_Sel+
							    Count*FAdv_Cmd_Height
							    +(FAdv_Cmd_Sel_Height-
							    FAdv_Cmd_Height));

					   Count++;
								  }
					   FAdv_Cmd_Sel_Curr=Cmd_New;
					   return;
								}

					   //Handled Exception 5 ( Not Required )

						}

int Form_Adv::FAdv_Cmd_Sel_Get(int Y) {

/*

#############################
      Stimuli of menus      .
   Cmd Selection Locator   .

*/

				if (FAdv_Cmd_Sel_Curr==-1) {
				    if (Y<Cmd_Asp_Rat) return -1;
				    Y=Y-Cmd_Asp_Rat;
				    if (Y>=FAdv_Cmd_Height*FAdv_Cmd_Tol) return -1;

				    return Y/FAdv_Cmd_Height;
							    }
				else {
				    if (Y<Cmd_Asp_Rat_Sel) return -1;
				    Y=Y-Cmd_Asp_Rat_Sel;
				    if (Y>=(FAdv_Cmd_Height*(FAdv_Cmd_Tol-1))
					+FAdv_Cmd_Sel_Height) return -1;

				    int Sel_Y=FAdv_Cmd_Sel_Curr*
					      FAdv_Cmd_Height;

				    if (Y<Sel_Y) return Y/FAdv_Cmd_Height;

				    else {
					 Y=Y-Sel_Y;

					 if (Y<FAdv_Cmd_Sel_Height)
					    return FAdv_Cmd_Sel_Curr;

					 else {
					      Y=Y-FAdv_Cmd_Sel_Height;
					      return FAdv_Cmd_Sel_Curr+(Y/
						     FAdv_Cmd_Height)+1;
					      }
					  }
				     }
				}

int Form_Adv::FAdv_Ent_Sel_Get(int Y) {

	       if ((Y<=Ent_Asp_Rat)||(Y>=Ent_Asp_Rat+(FAdv_Ent_Tol*26)))
		  return -1;
	       else return (Y-Ent_Asp_Rat)/26;
					}

void Form_Adv::FAdv_Init(int Force_Ref=1) {
			 Mouse_Hide();
			 if (Force_Ref!=0) cleardevice();

			 Cmd_Asp_Rat_Sel=getmaxy()-((FAdv_Cmd_Tol-1)*
					 FAdv_Cmd_Height)-35-
					 FAdv_Cmd_Sel_Height;
			 Cmd_Asp_Rat=Cmd_Asp_Rat_Sel+FAdv_Cmd_Height/2;
			 Ent_Asp_Rat=(((Cmd_Asp_Rat_Sel-30)/2)+30)-
				      (FAdv_Ent_Tol*26/2);
			 FAdv_Time=99;

			 //BkGround
			 setcolor(FAdv_BkColor);
			 setfillstyle(1,FAdv_BkColor);
			 bar(0,0,getmaxx(),getmaxy());

			 //TitleBar
			 setcolor(FAdv_Title_BkColor);
			 setfillstyle(1,FAdv_Title_BkColor);
			 bar(0,5,450,25);
			 bar(490,5,getmaxx(),25);
			 pieslice(490,15,0,360,10);
			 bar(50,getmaxy()-25,getmaxx()-50,getmaxy()-5);
			 pieslice(50,getmaxy()-15,0,360,10);
			 pieslice(getmaxx()-50,getmaxy()-15,0,360,10);
			 pieslice(450,15,0,360,10);
			 pieslice(getmaxx(),15,0,360,10);

			 //TitleBdr
			 setcolor(FAdv_Title_BdrColor);
			 setlinestyle(0,1,1);
			 line(490,5,getmaxx(),5);
			 line(50,getmaxy()-25,getmaxx()-50,getmaxy()-25);
			 line(0,5,450,5);
			 line(0,25,450,25);

			 arc(450,15,270,90,10);
			 arc(490,15,90,270,10);
			 line(490,25,getmaxx(),25);
			 line(50,getmaxy()-5,getmaxx()-50,getmaxy()-5);
			 arc(getmaxx()-50,getmaxy()-15,270,90,10);
			 arc(50,getmaxy()-15,90,270,10);

			 //PrtText Title and Helpline
			 setcolor(FAdv_Title_FrColor);
			 settextstyle(FAdv_Title_FntTp,0,FAdv_Title_FntSz);

			 outtextxy(350-textwidth(FAdv_Title),12,FAdv_Title);
			 outtextxy(500,12,"Time ");
			 FAdv_Prt_Time();
			 outtextxy((getmaxx()/2)-(textwidth(FAdv_Help_Line)/2)
				  ,getmaxy()-11-textheight("f")
				  ,FAdv_Help_Line);

			 //PrtCmds
			 int Count=0;
			 while(Count<FAdv_Cmd_Tol) {
			       FAdv_Draw_Bar(Count,Cmd_Asp_Rat+Count
					    *FAdv_Cmd_Height);
			       Count++;
						    }

			 //PrtTxts
			 Count=0;
			 while (Count<FAdv_Ent_Tol) {
				FAdv_Ent[Count].TAdv_X=0;
				FAdv_Ent[Count].TAdv_Y=Ent_Asp_Rat+(Count*26);
				FAdv_Ent[Count].TAdv_Init();
				Count++;
						    }

			 Mouse_Init();
			 Mouse_Show();
			 Mouse_Set_Recorded();
			   }


void Form_Adv::FAdv_Cmd_Cursored_Get() {

/*

#################################
	 Brain of Forms         .
     User Response Handler      .

*/

			  long Key_Pressed;
			  int Mouse_in=-1;
			  int Cmd_New;

			  Start_Process:

			  while(bioskey(1)==0) {

			  Mouse_Get(&FAdv_Button,&FAdv_Mouse_X,
					  &FAdv_Mouse_Y);

			  FAdv_Prt_Time();

			  //This Part is for cmds

			  if (FAdv_Mouse_X<=350) {

			      Mouse_in=FAdv_Cmd_Sel_Get(FAdv_Mouse_Y);
			      if (Mouse_in!=FAdv_Cmd_Sel_Curr) {

				 if ((Mouse_in==-1)&&
				     (FAdv_Cmd_Sel_Curr!=-1))
				     FAdv_Cmd_Sel_Set(1,0);
				 if ((Mouse_in!=-1)&&
				     (FAdv_Cmd_Sel_Curr==-1))
				     FAdv_Cmd_Sel_Set(2,Mouse_in);
				 if ((Mouse_in!=-1)&&
				     (FAdv_Cmd_Sel_Curr!=-1))
				     FAdv_Cmd_Sel_Set(4,Mouse_in);
								 }
						  }
			      else if (FAdv_Cmd_Sel_Curr!=-1)
				       FAdv_Cmd_Sel_Set(1,0);

			      if ((FAdv_Button&1)&&
				  (FAdv_Cmd_Sel_Curr>-1)) {

				   FAdv_Draw_Bar_Click(FAdv_Cmd_Sel_Curr,
						       FAdv_Cmd_Sel_Curr*
						       FAdv_Cmd_Height+
						       Cmd_Asp_Rat_Sel);
				   while(FAdv_Button&1) Mouse_Get(&FAdv_Button,
								  &FAdv_Mouse_X,
								  &FAdv_Mouse_Y);
				   Mouse_Record();
				   return;
						    }

			  //This part is for txts

			  if (FAdv_Mouse_X<=450) {
			      Mouse_in=FAdv_Ent_Sel_Get(FAdv_Mouse_Y);

			      if (Mouse_in!=FAdv_Ent_Sel) {
				  if ((FAdv_Ent_Sel!=-1)&&
				      (FAdv_Ent_Sel!=FAdv_Ent_Act))
				      FAdv_Ent[FAdv_Ent_Sel].TAdv_DeSelect();
				  if ((Mouse_in!=-1)&&
				      (Mouse_in!=FAdv_Ent_Act))
				      FAdv_Ent[Mouse_in].TAdv_Select();
				      FAdv_Ent_Sel=Mouse_in;
							   }

						}
			  else if((FAdv_Ent_Sel!=-1)&&
				  (FAdv_Ent_Sel!=FAdv_Ent_Act))   {
				  FAdv_Ent[FAdv_Ent_Sel].TAdv_DeSelect();
				  FAdv_Ent_Sel=-1;
						    }

			  if (FAdv_Button&1) {

			     if (FAdv_Ent_Sel!=FAdv_Ent_Act) {
				 if (FAdv_Ent_Act!=-1)
				      FAdv_Ent[FAdv_Ent_Act].TAdv_DeSelect();
				  if (Mouse_in!=-1)
				      FAdv_Ent[Mouse_in].TAdv_Activate();
				      FAdv_Ent_Act=Mouse_in;
							 }
			      if ((FAdv_Mouse_X>=450)&&(FAdv_Ent_Act!=-1)) {
				  FAdv_Ent[FAdv_Ent_Act].TAdv_DeSelect();
				  FAdv_Ent_Act=-1;
									   }
								     }

			  //Process Key press

						}

			  Key_Pressed = bioskey(0);

			  //This part is for cmds

			  if (Key_Pressed==283) {
			      FAdv_Cmd_Sel_Curr=-1;
			      Mouse_Record();
			      return;
						}

			  //This part is for txts

			  if ((Key_Pressed==7181)&&
			      (FAdv_Ent_Act>-1)&&
			      (FAdv_Ent_Act<FAdv_Ent_Tol-1)) {
			       FAdv_Ent[FAdv_Ent_Act].TAdv_DeSelect();
			       FAdv_Ent_Act++;
			       FAdv_Ent[FAdv_Ent_Act].TAdv_Activate();
							      }
			  else if ((FAdv_Ent_Act!=-1)&&
				   (Key_Pressed!=7181))
			      FAdv_Ent[FAdv_Ent_Act].TAdv_Input(Key_Pressed);


			  goto Start_Process;
				       }

int Form_Adv::FAdv_Navigate() {
			    FAdv_Cmd_Sel_Set(1,0,1);
			    FAdv_Cmd_Cursored_Get();
			    if (FAdv_Cmd_Sel_Curr>-1)
			       FAdv_Cmd_Sel_Title=FAdv_Cmd_Title[FAdv_Cmd_Sel_Curr];
			    FAdv_Ent_Act=-1;
			    FAdv_Ent_Sel=-1;
			    return FAdv_Cmd_Sel_Curr;
			       }

/*

main() {

      Graphic_Init(20000);

      Form_Adv Profile;

Profile.FAdv_Cmd_BkColor=9;
Profile.FAdv_Cmd_FrColor=15;
Profile.FAdv_Cmd_BdrColor=15;

Profile.FAdv_Cmd_Sel_BkColor=4;
Profile.FAdv_Cmd_Sel_FrColor=15;
Profile.FAdv_Cmd_Sel_BdrColor=15;

Profile.FAdv_Cmd_Click_BkColor=12;
Profile.FAdv_Cmd_Click_FrColor=15;
Profile.FAdv_Cmd_Click_BdrColor=15;

Profile.FAdv_Title_BkColor=9;
Profile.FAdv_Title_FrColor=15;
Profile.FAdv_Title_BdrColor=15;

Profile.FAdv_Title_FntTp=0;
Profile.FAdv_Cmd_FntTp=0;
Profile.FAdv_Title_FntSz=1;
Profile.FAdv_Cmd_FntSz=1;
Profile.FAdv_BkColor=1;

Profile.FAdv_Cmd_Tol=2;
Profile.FAdv_Title="Counseller Pro - Add New Profile";

Profile.FAdv_Cmd_Title[0]="Add";
Profile.FAdv_Cmd_Title[1]="Cancel";

Profile.FAdv_Cmd_Desc[0]="Create and add a new profile to the\0";
Profile.FAdv_Cmd_Desc2[0]="existing profile database.\0";
Profile.FAdv_Cmd_Desc[1]="Cancel and return to home menu.\0";
Profile.FAdv_Cmd_Desc2[1]="\0";

Profile.FAdv_Ent[0].TAdv_BkColor=1;
Profile.FAdv_Ent[0].TAdv_FrColor=15;
Profile.FAdv_Ent[0].TAdv_TxtColor=15;
Profile.FAdv_Ent[0].TAdv_BdrColor=1;

Profile.FAdv_Ent[0].TAdv_Sel_BkColor=4;
Profile.FAdv_Ent[0].TAdv_Sel_FrColor=15;
Profile.FAdv_Ent[0].TAdv_Sel_BdrColor=15;
Profile.FAdv_Ent[0].TAdv_Sel_TxtColor=15;

Profile.FAdv_Ent[0].TAdv_Act_BkColor=9;
Profile.FAdv_Ent[0].TAdv_Act_FrColor=15;
Profile.FAdv_Ent[0].TAdv_Act_BdrColor=15;
Profile.FAdv_Ent[0].TAdv_Act_TxtColor=15;
Profile.FAdv_Ent[0].TAdv_Act_BkColor2=9;
Profile.FAdv_Ent[0].TAdv_Act_BdrColor2=9;

Profile.FAdv_Ent[0].TAdv_FntTp=0;
Profile.FAdv_Ent[0].TAdv_FntSz=1;

Profile.FAdv_Ent_Tol=9;

Profile.FAdv_Ent_Title[1]="Student Name :";
Profile.FAdv_Ent_Text[1]="";
Profile.FAdv_Ent_Title[3]="Permanent Address :";
Profile.FAdv_Ent_Text[3]="";
Profile.FAdv_Ent_Title[2]="Date Of Birth (DD-MM-YYYY) :";
Profile.FAdv_Ent_Text[2]="";
Profile.FAdv_Ent_Title[0]="Roll :";
Profile.FAdv_Ent_Text[0]="";
Profile.FAdv_Ent_Title[4]="Father's Name :";
Profile.FAdv_Ent_Text[4]="";
Profile.FAdv_Ent_Title[5]="Mother's Name :";
Profile.FAdv_Ent_Text[5]="";
Profile.FAdv_Ent_Title[6]="School :";
Profile.FAdv_Ent_Text[6]="";
Profile.FAdv_Ent_Title[7]="Stream :";
Profile.FAdv_Ent_Text[7]="";
Profile.FAdv_Ent_Title[8]="Sub-Stream :";
Profile.FAdv_Ent_Text[8]="";

Profile.FAdv_Init();
Profile.FAdv_Navigate();

//cout<<Profile.FAdv_Ent_Text[0];

getch();
Graphic_DeInit();
	}           */