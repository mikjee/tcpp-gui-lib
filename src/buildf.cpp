// Include the pre-existing headers first ...                               '

# include <iostream.h>
# include <dos.h>
# include <conio.h>
# include <stdlib.h>
# include <alloc.h>
# include <time.h>
# include <fstream.h>
# include <stdio.h>
# include <graphics.h>
# include <string.h>
# include <bios.h>
# include <io.h>
# include <ctype.h>
# include <fcntl.h>

//Include the created headers next in order                                 '
//of their dependance...                                                    '

# include <svga.h>
# include <keybrd.h>
# include <mouse_1.h>
# include <menu_adv.h>
# include <textbox.h>
# include <form_adv.h>
# include <wait_adv.h>
# include <msg_adv.h>
# include <stud_adv.h>

//Declare global objects of Menus, Forms,                                   '
//records etc...                                                            '

Menu_Adv Home;
//Menu_Adv Stream,Science[2],Arts[2],Commerce[2];
Student S[10];

int Record_Tol,ColorScheme,Record_Tol_Last,Record_IsFile;
int CP_R[16],CP_G[16],CP_B[16];

//Declare functions for initializing classes                                '
//graphics, colors, files etc...                                            '

void Menu_Init();
void Form_Init();
void MsgB_Init();

void Color(int);
void StartUp();
void ShutDown();
void Help();
void Config();
void About();

//Declare functions for class details...                                    '

void Profile_New();
void Profile_Sort(int);
void Profile_Carrier();
int Profile_Show(char*,int);
void Profile_View();
void Profile_Delete();

//Declare functions for inst ...                                            '

int IsClgID(char[50]);
int IsClgSeat(char[50]);

//This is where the fun starts ...                                          '

void main() {

	  Graphic_Init(2000);
	  StartUp();
	  int Res1,Res2,Res3,Res4;

	  CP_Home:

	  if ((heapcheck()==-1)||(farheapcheck()==-1)) {

	 Msg_Adv FErr;
	 FErr.Msg_Title="FATAL ERROR";
	 FErr.Msg_Text[0]="The C++ heap memory";
	 FErr.Msg_Text[1]="is corrupt. Please";
	 FErr.Msg_Text[2]="exit program.";
	 FErr.Msg_Show();
					    }

	  Home.MAdv_Init(0);
	  switch(Home.MAdv_Navigate()) {

	       case 0:
		      Profile_New();
		      goto CP_Home;
	       case 1:
		       Profile_Delete();
		       goto CP_Home;
	       case 2:
		       Profile_View();
		       goto CP_Home;
	       case 3:
		       Profile_Carrier();
		       goto CP_Home;
	       case 4:
		       Config();
		       goto CP_Home;
	       case 5:
		       Help();
		       goto CP_Home;
	       case 6:
		       About();
		       goto CP_Home;
	       case 7:
	       case -1:
		       break;
				     }


	  ShutDown();
	  Graphic_DeInit();

	    }

void Color(int Key=0) {

/*   0  -  Black                                                            '
     1	-  BkColor (whole)/(ent_normal)/(ent_Bdr_Normal) 		    '
     2	-  BkColor (title)/(ent_active)/(waitadv)			    '
     3	-  BkColor (normal)/(ent_select)/(ent_act2)			    '
     4	-  BkColor (select)/(ent_bdr_act2)				    '
     5	-  BkColor (click)						    '
     6	-  FrColor (title)/(Msgadv)					    '
     7	-  FrColor (normal)/(txt_normal)/(fr_normal)			    '
     8	-  FrColor (select)/(txt_select)/(fr_select)			    '
     9	-  FrColor (click)/(txt_act)/(fr_act)				    '
     10	-  Msgadv							    '
     11	-  BdrColor(title)/(waitadv)					    '
     12	-  BdrColor(normal)						    '
     13	-  BdrColor(select)						    '
     14	-  BdrColor(click)/(ent_bdr_act)/(ent_bdr_sel)			    '
     15	-  white							   */


/*   0  -  default blue                                                     '
     1	-  new blue							    '
     2	-  classic blue							    '
     3	-  white							    '
     4	-  greyscale							   */

     switch (Key) {

	     case 0:

	    CP_R[0]=0;   CP_R[1]=12;  CP_R[2]=12;  CP_R[3]=12;  CP_R[4]=12;
	    CP_G[0]=0;   CP_G[1]=87;  CP_G[2]=76;  CP_G[3]=85;  CP_G[4]=76;
	    CP_B[0]=0;   CP_B[1]=255; CP_B[2]=245; CP_B[3]=255; CP_B[4]=245;

	    CP_R[5]=240; CP_R[6]=255; CP_R[7]=255; CP_R[8]=255; CP_R[9]=255;
	    CP_G[5]=0;   CP_G[6]=255; CP_G[7]=255; CP_G[8]=255; CP_G[9]=255;
	    CP_B[5]=0;   CP_B[6]=255; CP_B[7]=255; CP_B[8]=255; CP_B[9]=255;

	    CP_R[10]=12; CP_R[11]=0;  CP_R[12]=0;  CP_R[13]=0;  CP_R[14]=0;
	    CP_G[10]=76; CP_G[11]=90; CP_G[12]=80; CP_G[13]=80; CP_G[14]=80;
	    CP_B[10]=250;CP_B[11]=250;CP_B[12]=255;CP_B[13]=245;CP_B[14]=255;

	    CP_R[15]=255;
	    CP_G[15]=255;
	    CP_B[15]=255;

	    break;

	     case 1:

	    CP_R[0]=0;   CP_R[1]=0;   CP_R[2]=12;  CP_R[3]=12;  CP_R[4]=240;
	    CP_G[0]=0;   CP_G[1]=0;   CP_G[2]=87;  CP_G[3]=87;  CP_G[4]=0;
	    CP_B[0]=0;   CP_B[1]=255; CP_B[2]=255; CP_B[3]=255; CP_B[4]=0;

	    CP_R[5]=220; CP_R[6]=30;  CP_R[7]=0;   CP_R[8]=90;  CP_R[9]=255;
	    CP_G[5]=0;   CP_G[6]=76;  CP_G[7]=102; CP_G[8]=126; CP_G[9]=255;
	    CP_B[5]=0;   CP_B[6]=175; CP_B[7]=255; CP_B[8]=220; CP_B[9]=255;

	    CP_R[10]=255;CP_R[11]=255;CP_R[12]=255;CP_R[13]=255;CP_R[14]=255;
	    CP_G[10]=255;CP_G[11]=255;CP_G[12]=255;CP_G[13]=255;CP_G[14]=255;
	    CP_B[10]=255;CP_B[11]=255;CP_B[12]=255;CP_B[13]=255;CP_B[14]=255;

	    CP_R[15]=255;
	    CP_G[15]=255;
	    CP_B[15]=255;

	    break;

	     case 2:

	    CP_R[0]=0;   CP_R[1]=0;   CP_R[2]=0;   CP_R[3]=0;   CP_R[4]=240;
	    CP_G[0]=0;   CP_G[1]=0;   CP_G[2]=0;   CP_G[3]=0;   CP_G[4]=0;
	    CP_B[0]=0;   CP_B[1]=255; CP_B[2]=230; CP_B[3]=230; CP_B[4]=0;

	    CP_R[5]=250; CP_R[6]=255; CP_R[7]=255; CP_R[8]=255; CP_R[9]=255;
	    CP_G[5]=0;   CP_G[6]=255; CP_G[7]=255; CP_G[8]=255; CP_G[9]=255;
	    CP_B[5]=0;   CP_B[6]=255; CP_B[7]=255; CP_B[8]=255; CP_B[9]=255;

	    CP_R[10]=0;  CP_R[11]=255;CP_R[12]=255;CP_R[13]=255;CP_R[14]=255;
	    CP_G[10]=0;  CP_G[11]=255;CP_G[12]=255;CP_G[13]=255;CP_G[14]=255;
	    CP_B[10]=230;CP_B[11]=255;CP_B[12]=255;CP_B[13]=255;CP_B[14]=255;

	    CP_R[15]=255;
	    CP_G[15]=255;
	    CP_B[15]=255;

	    break;

	     case 4:

	    CP_R[0]=0;   CP_R[1]=24;  CP_R[2]=20;  CP_R[3]=24;  CP_R[4]=20;
	    CP_G[0]=0;   CP_G[1]=24;  CP_G[2]=20;  CP_G[3]=24;  CP_G[4]=20;
	    CP_B[0]=0;   CP_B[1]=24;  CP_B[2]=20;  CP_B[3]=24;  CP_B[4]=20;

	    CP_R[5]=80; CP_R[6]=255; CP_R[7]=255; CP_R[8]=255; CP_R[9]=255;
	    CP_G[5]=80; CP_G[6]=255; CP_G[7]=255; CP_G[8]=255; CP_G[9]=255;
	    CP_B[5]=255; CP_B[6]=255; CP_B[7]=255; CP_B[8]=255; CP_B[9]=255;

	    CP_R[10]=20; CP_R[11]=0;  CP_R[12]=0;  CP_R[13]=0;  CP_R[14]=0;
	    CP_G[10]=20; CP_G[11]=0;  CP_G[12]=0;  CP_G[13]=0;  CP_G[14]=0;
	    CP_B[10]=20;CP_B[11]=0;  CP_B[12]=0;  CP_B[13]=0;  CP_B[14]=0;

	    CP_R[15]=255;
	    CP_G[15]=255;
	    CP_B[15]=255;

	    break;
		    }

     ColorScheme = Key;
			  }


void Menu_Init() {

Home.MAdv_Item_BkColor=3;
Home.MAdv_Item_FrColor=7;
Home.MAdv_Item_BdrColor=12;

Home.MAdv_Item_Sel_BkColor=4;
Home.MAdv_Item_Sel_FrColor=8;
Home.MAdv_Item_Sel_BdrColor=13;

Home.MAdv_Item_Click_BkColor=5;
Home.MAdv_Item_Click_FrColor=9;
Home.MAdv_Item_Click_BdrColor=14;

Home.MAdv_Title_BkColor=2;
Home.MAdv_Title_FrColor=6;
Home.MAdv_Title_BdrColor=11;

Home.MAdv_Title_FntTp=0;
Home.MAdv_Item_FntTp=0;
Home.MAdv_Title_FntSz=1;
Home.MAdv_Item_FntSz=1;
Home.MAdv_BkColor=1;

Home.MAdv_Item_Tol=8;
Home.MAdv_Title="Counseller Pro - Home Menu";
Home.MAdv_Desc="Welcome to Counseller Pro.";
Home.MAdv_Desc2="Click on an item below to begin with.";
Home.MAdv_Desc3="For help, click on Get Help.";

Home.MAdv_Item_Title[0]="New Profile";
Home.MAdv_Item_Title[1]="Delete Profile";
Home.MAdv_Item_Title[2]="View / Modify Profile";
Home.MAdv_Item_Title[3]="View Carrier Choices";
Home.MAdv_Item_Title[4]="Configuration";
Home.MAdv_Item_Title[5]="Get Help";
Home.MAdv_Item_Title[6]="About";
Home.MAdv_Item_Title[7]="Exit";

Home.MAdv_Item_Desc[0]="Create and add a new profile to the";
Home.MAdv_Item_Desc2[0]="existing profile database.";
Home.MAdv_Item_Desc[1]="Delete a profile from the profiles";
Home.MAdv_Item_Desc2[1]="database.";
Home.MAdv_Item_Desc[2]="View or modify the statistics of an";
Home.MAdv_Item_Desc2[2]="existing profile.";
Home.MAdv_Item_Desc[3]="Choose your carrier according to";
Home.MAdv_Item_Desc2[3]="to your marks and subject/stream.";
Home.MAdv_Item_Desc[4]="Configure and set Counseller Pro";
Home.MAdv_Item_Desc2[4]="properties and options.";
Home.MAdv_Item_Desc[5]="Get help with Counseller pro.";
Home.MAdv_Item_Desc2[5]="";
Home.MAdv_Item_Desc[6]="About Counseller Pro ...";
Home.MAdv_Item_Desc2[6]="";
Home.MAdv_Item_Desc[7]="Exit Counseller pro and return to";
Home.MAdv_Item_Desc2[7]="windows.";

}

void Form_Init() {

Form_Adv Temp;

Temp.FAdv_Cmd_BkColor=3;
Temp.FAdv_Cmd_FrColor=7;
Temp.FAdv_Cmd_BdrColor=12;

Temp.FAdv_Cmd_Sel_BkColor=4;
Temp.FAdv_Cmd_Sel_FrColor=8;
Temp.FAdv_Cmd_Sel_BdrColor=13;

Temp.FAdv_Cmd_Click_BkColor=5;
Temp.FAdv_Cmd_Click_FrColor=9;
Temp.FAdv_Cmd_Click_BdrColor=14;

Temp.FAdv_Title_BkColor=2;
Temp.FAdv_Title_FrColor=6;
Temp.FAdv_Title_BdrColor=11;

Temp.FAdv_Title_FntTp=0;
Temp.FAdv_Cmd_FntTp=0;
Temp.FAdv_Title_FntSz=1;
Temp.FAdv_Cmd_FntSz=1;
Temp.FAdv_BkColor=1;

Temp.FAdv_Ent[0].TAdv_BkColor=1;
Temp.FAdv_Ent[0].TAdv_FrColor=7;
Temp.FAdv_Ent[0].TAdv_TxtColor=7;
Temp.FAdv_Ent[0].TAdv_BdrColor=1;

Temp.FAdv_Ent[0].TAdv_Sel_BkColor=3;
Temp.FAdv_Ent[0].TAdv_Sel_FrColor=8;
Temp.FAdv_Ent[0].TAdv_Sel_BdrColor=14;
Temp.FAdv_Ent[0].TAdv_Sel_TxtColor=8;

Temp.FAdv_Ent[0].TAdv_Act_BkColor=2;
Temp.FAdv_Ent[0].TAdv_Act_FrColor=9;
Temp.FAdv_Ent[0].TAdv_Act_BdrColor=14;
Temp.FAdv_Ent[0].TAdv_Act_TxtColor=9;
Temp.FAdv_Ent[0].TAdv_Act_BkColor2=2;
Temp.FAdv_Ent[0].TAdv_Act_BdrColor2=4;

Temp.FAdv_Ent[0].TAdv_FntTp=0;
Temp.FAdv_Ent[0].TAdv_FntSz=1;

		  }

void Profile_Sort(int Key=0) {

/*    Key         Sort                                                      '
									    '
      0		  Roll							    '
      1		  Name							    '
      2		  School						    '
      3		  Stream						    '
      4		  Sub-stream						    '
      5           Spc-stream                                                '
									   */

      char* Field[10];
      int Count=0;
      int Count2=0;
      int Pos=1,Res=0;
      Student Temp;

      while (Count<Record_Tol) {
	     Field[Count] = (char*)calloc(50,sizeof(char));
	     strset(Field[Count],NULL);
	     Count++;
			       }

/*                                                                          '
		       Assign field according to key			    '
									   */

      Count=0;
      while (Count<Record_Tol) {

	     switch(Key) {

		    case 0:strcpy(Field[Count],S[Count].Stud_Roll);
			   break;
		    case 1:strcpy(Field[Count],S[Count].Stud_Name_Self);
			   break;
		    case 2:strcpy(Field[Count],S[Count].Stud_School);
			   break;
		    case 3:strcpy(Field[Count],S[Count].Stud_Stream);
			   break;
		    case 4:strcpy(Field[Count],S[Count].Stud_Stream_Sub);
			   break;
		    case 5:strcpy(Field[Count],S[Count].Stud_Stream_Spc);
			   break;
			 }
	     Count++;
			       }

/*                                                                          '
			  Selection exchange sort			    '
									   */

      Count=0;
      while (Count<Record_Tol) {

	     Count2=Count+1;
	     Pos=Count;

	     while (Count2<Record_Tol) {

		    Res=strcmp(Field[Pos],Field[Count2]);
		    if (Res>0) Pos=Count2;
		    Count2++;
				       }

	     Temp=S[Pos];
	     S[Pos]=S[Count];
	     S[Count]=Temp;
	     Count++;
			      }
			       }

int Profile_Show(char* Title,int Key) {

/*    Key         Sort                                                      '
									    '
      0		  Roll							    '
      1		  Name							    '
      2		  School						    '
      3		  Stream						    '
      4		  Sub-stream						    '
      5           Spc-stream                                                '
									   */

    if ((heapcheck()==-1)||(farheapcheck()==-1)) {

	 Msg_Adv FErr;
	 FErr.Msg_Title="FATAL ERROR";
	 FErr.Msg_Text[0]="The C++ heap memory";
	 FErr.Msg_Text[1]="is corrupt. Please";
	 FErr.Msg_Text[2]="exit program.";
	 FErr.Msg_Show();
					    }

    Profile_Sort(Key);

    Menu_Adv Profile[3];
    int Curr=0,Count=0,Res,Tol,Count2=0;;
    char* Field[10];
    char* Field2[10];
    char* Field3[10];

    Count=0;
    while (Count<3) {
	   (Profile[Count].MAdv_Title=Title);
	   (Profile[Count].MAdv_Desc="Select a profile.");
	   (Profile[Count].MAdv_Desc2="Click next to go to next page.");
	   (Profile[Count].MAdv_Desc3="Click prev to view previous page.");
	   Profile[Count].MAdv_Item_Tol=0;
	   Count++;
		    }

/*                                                                          '
			Create dyanamic menus				    '
									   */

    Count=0;
    while (Count<Record_Tol) {

	   Field[Count]=(char*)calloc(50,sizeof(char));
	   Field2[Count]=(char*)calloc(50,sizeof(char));
	   Field3[Count]=(char*)calloc(50,sizeof(char));

	   strset(Field[Count],NULL);
	   strset(Field2[Count],NULL);
	   strset(Field3[Count],NULL);

	   switch(Key) {

		    case 0:Field[Count]=S[Count].Stud_Roll;
			   Field2[Count]=S[Count].Stud_Name_Self;
			   Field3[Count]=S[Count].Stud_Stream;
			   break;
		    case 1:Field[Count]=S[Count].Stud_Name_Self;
			   Field2[Count]=S[Count].Stud_Roll;
			   Field3[Count]=S[Count].Stud_Stream;
			   break;
		    case 2:Field[Count]=S[Count].Stud_School;
			   Field2[Count]=S[Count].Stud_Roll;
			   Field3[Count]=S[Count].Stud_Name_Self;
			   break;
		    case 3:Field[Count]=S[Count].Stud_Stream;
			   Field2[Count]=S[Count].Stud_Roll;
			   Field3[Count]=S[Count].Stud_Name_Self;
			   break;
		    case 4:Field[Count]=S[Count].Stud_Stream_Sub;
			   Field2[Count]=S[Count].Stud_Roll;
			   Field3[Count]=S[Count].Stud_Name_Self;
			   break;
		    case 5:Field[Count]=S[Count].Stud_Stream_Spc;
			   Field2[Count]=S[Count].Stud_Roll;
			   Field3[Count]=S[Count].Stud_Name_Self;
			   break;
			 }

	   if ((Count2==7)&&(Curr!=0)) {

		  Profile[Curr].MAdv_Item_Tol=10;

		  (Profile[Curr].MAdv_Item_Title[7]="Previous");
		  (Profile[Curr].MAdv_Item_Desc[7]="Go to the previous page and");
		  (Profile[Curr].MAdv_Item_Desc2[7]="view previous profiles.");

		  Profile[Curr].MAdv_Item_Tol++;
		  (Profile[Curr].MAdv_Item_Title[8]="Next");
		  (Profile[Curr].MAdv_Item_Desc[8]="Go to the next page and view");
		  (Profile[Curr].MAdv_Item_Desc2[8]="more profiles.");

		  Profile[Curr].MAdv_Item_Tol++;
		  (Profile[Curr].MAdv_Item_Title[9]="Cancel");
		  (Profile[Curr].MAdv_Item_Desc[9]="Cancel and go to previous menu");
		  (Profile[Curr].MAdv_Item_Desc2[9]="and sort results differently.");

		  Curr++;
		  Count2=0;
						}

	   else if ((Count2==8)&&(Curr==0)) {

			  Profile[Curr].MAdv_Item_Tol=10;

			  (Profile[Curr].MAdv_Item_Title[8]="Next");
			  (Profile[Curr].MAdv_Item_Desc[8]="Go to the next page and view");
			  (Profile[Curr].MAdv_Item_Desc2[8]="more profiles.");

			  (Profile[Curr].MAdv_Item_Title[9]="Cancel");
			  (Profile[Curr].MAdv_Item_Desc[9]="Cancel and go to previous menu");
			  (Profile[Curr].MAdv_Item_Desc2[9]="and sort results differently.");

			  Curr++;
			  Count2=0;
			  }

	   Profile[Curr].MAdv_Item_Tol++;

	   Profile[Curr].MAdv_Item_Title[Count2]=Field[Count];
	   Profile[Curr].MAdv_Item_Desc[Count2]=Field2[Count];
	   Profile[Curr].MAdv_Item_Desc2[Count2]=Field3[Count];

	   Count++;
	   Count2++;

		   }

/*                                                                          '
		    Append the last navigation controls			    '
									   */

if ((Profile[Curr].MAdv_Item_Tol!=10)&&(Curr>0))  {

    Profile[Curr].MAdv_Item_Tol +=2;

    (Profile[Curr].MAdv_Item_Title[Count2]="Previous");
    (Profile[Curr].MAdv_Item_Desc[Count2]="Go to the previous page and");
    (Profile[Curr].MAdv_Item_Desc2[Count2]="view previous profiles.");

    (Profile[Curr].MAdv_Item_Title[Count2+1]="Cancel");
    (Profile[Curr].MAdv_Item_Desc[Count2+1]="Cancel and go to previous menu");
    (Profile[Curr].MAdv_Item_Desc2[Count2+1]="and sort results differently.");

				      }

else if ((Profile[Curr].MAdv_Item_Tol!=10)&&(Curr==0))  {

    Profile[Curr].MAdv_Item_Tol +=1;

    (Profile[Curr].MAdv_Item_Title[Count2]="Cancel");
    (Profile[Curr].MAdv_Item_Desc[Count2]="Cancel and go to previous menu");
    (Profile[Curr].MAdv_Item_Desc2[Count2]="and sort results differently.");

				      }

Tol=Curr+1;
Curr=0;

/*                                                                          '
		      Start the navigation dyanamically			    '
									   */

while (1) {

       Profile[Curr].MAdv_Init(0);
       Res=Profile[Curr].MAdv_Navigate();

       if (Res==Profile[Curr].MAdv_Item_Tol-1) return -1;

       else if ((Res==Profile[Curr].MAdv_Item_Tol-2)
		&&(Curr!=0)&&(Curr!=Tol-1)) Curr++;
       else if ((Res==Profile[Curr].MAdv_Item_Tol-3)
		&&(Curr!=0)&&(Curr!=Tol-1)) Curr--;

       else if ((Res==Profile[Curr].MAdv_Item_Tol-2)
		&&(Curr==0)&&(Curr!=Tol-1)) Curr++;
       else if ((Res==Profile[Curr].MAdv_Item_Tol-2)
		&&(Curr!=0)&&(Curr==Tol-1)) Curr--;

       else return (Curr*7)+Res;

	   }
		     }

void  MsgB_Init() {

      Msg_Adv Temp;
      Temp.Msg_BkColor=1;
      Temp.Msg_FrColor=6;
      Temp.Msg_BkColor2=10;
      Temp.Msg_FrColor2=6;
      Temp.Msg_BdrColor=10;
      Temp.Msg_TimeOut=3000;

		 }

int IsClgID(char ID[50]) {  return 1;

			 }

int IsClgSeat(char ID[50]) {  return 1;

			   }

void Profile_New() {

if ((heapcheck()==-1)||(farheapcheck()==-1)) {

	 Msg_Adv FErr;
	 FErr.Msg_Title="FATAL ERROR";
	 FErr.Msg_Text[0]="The C++ heap memory";
	 FErr.Msg_Text[1]="is corrupt. Please";
	 FErr.Msg_Text[2]="exit program.";
	 FErr.Msg_Show();
					    }

if (Record_Tol==10) {

    Msg_Adv Err2;
    Err2.Msg_Title="FATAL ERROR";
    Err2.Msg_Text[0]="C++ heap memory low.";
    Err2.Msg_Text[1]="Please delete a few";
    Err2.Msg_Text[2]="records.";
    Err2.Msg_Show();
    return;
		     }

Form_Adv Profile,Marks;
Wait_Adv Prog;
int Res;
Msg_Adv Err;

/*                                                                          '
			    Initialize the values			    '
									   */

Err.Msg_Title="Incomplete Entry";
Err.Msg_Text[0]="Please complete all";
Err.Msg_Text[1]="fields in student";
Err.Msg_Text[2]="details and marks.";

Profile.FAdv_Cmd_Tol=2;
Profile.FAdv_Title="Add New Profile - Enter Student Details";
Profile.FAdv_Cmd_Title[0]="Next";
Profile.FAdv_Cmd_Title[1]="Cancel";
Profile.FAdv_Cmd_Desc[0]="Proceed to enter subject marks and";
Profile.FAdv_Cmd_Desc2[0]="a few other details.";
Profile.FAdv_Cmd_Desc[1]="Cancel and return to home menu.";
Profile.FAdv_Cmd_Desc2[1]="";
Profile.FAdv_Ent_Tol=11;

Marks.FAdv_Cmd_Tol=3;
Marks.FAdv_Title="Add New Profile - Enter Subject Marks";
Marks.FAdv_Cmd_Title[1]="Finish";
Marks.FAdv_Cmd_Title[2]="Cancel";
Marks.FAdv_Cmd_Title[0]="Back";
Marks.FAdv_Cmd_Desc[1]="Add profile to existing database";
Marks.FAdv_Cmd_Desc2[1]="for carrier choice.";
Marks.FAdv_Cmd_Desc[2]="Cancel and return to home menu.";
Marks.FAdv_Cmd_Desc2[2]="";
Marks.FAdv_Cmd_Desc[0]="Go back and change the entered";
Marks.FAdv_Cmd_Desc2[0]="student details.";
Marks.FAdv_Ent_Tol=6;

Profile.FAdv_Ent[0].TAdv_Title="Roll Nos. :";
Profile.FAdv_Ent[1].TAdv_Title="Admission Nos. :";
Profile.FAdv_Ent[2].TAdv_Title="Student Name :";
Profile.FAdv_Ent[3].TAdv_Title="Father's Name :";
Profile.FAdv_Ent[4].TAdv_Title="Mother's Name :";
Profile.FAdv_Ent[5].TAdv_Title="School :";
Profile.FAdv_Ent[6].TAdv_Title="Stream :";
Profile.FAdv_Ent[7].TAdv_Title="Sub-Stream :";
Profile.FAdv_Ent[8].TAdv_Title="Address :";
Profile.FAdv_Ent[9].TAdv_Title="Caste Category :";
Profile.FAdv_Ent[10].TAdv_Title="Date of Birth :";

Marks.FAdv_Ent[0].TAdv_Title="Marks 1 :";
Marks.FAdv_Ent[1].TAdv_Title="Marks 2 :";
Marks.FAdv_Ent[2].TAdv_Title="Marks 3 :";
Marks.FAdv_Ent[3].TAdv_Title="Marks 4 :";
Marks.FAdv_Ent[4].TAdv_Title="Marks 5 :";
Marks.FAdv_Ent[5].TAdv_Title="Phone No. :";

/*                                                                          '
				Load the forms				    '
									   */

Step1:
Profile.FAdv_Init(0);
Res=Profile.FAdv_Navigate();
if ((Res==1)||(Res==-1)) return;

Marks.FAdv_Init(0);
Res=Marks.FAdv_Navigate();
if (Res==0) goto Step1;
else if((Res==2)||(Res==-1)) return;

/*                                                                          '
		       Check presence of null entries 			    '
									   */

if ((strlen(Profile.FAdv_Ent[0].TAdv_Text)==0)||(strlen(Profile.FAdv_Ent[5].TAdv_Text)==0)||
    (strlen(Profile.FAdv_Ent[1].TAdv_Text)==0)||(strlen(Profile.FAdv_Ent[6].TAdv_Text)==0)||
    (strlen(Profile.FAdv_Ent[2].TAdv_Text)==0)||(strlen(Profile.FAdv_Ent[7].TAdv_Text)==0)||
    (strlen(Profile.FAdv_Ent[3].TAdv_Text)==0)||(strlen(Profile.FAdv_Ent[8].TAdv_Text)==0)||
    (strlen(Profile.FAdv_Ent[4].TAdv_Text)==0)||(strlen(Profile.FAdv_Ent[9].TAdv_Text)==0)||
    (strlen(Profile.FAdv_Ent[10].TAdv_Text)==0)||(strlen(Marks.FAdv_Ent[0].TAdv_Text)==0)||
    (strlen(Marks.FAdv_Ent[1].TAdv_Text)==0)||(strlen(Marks.FAdv_Ent[4].TAdv_Text)==0)||
    (strlen(Marks.FAdv_Ent[2].TAdv_Text)==0)||(strlen(Marks.FAdv_Ent[5].TAdv_Text)==0)||
    (strlen(Marks.FAdv_Ent[3].TAdv_Text)==0)) {
					       Err.Msg_Show();
					       goto Step1;
					      }

/*                                                                          '
			   Enter data into array			    '
									   */

Prog.WAdv_Init(19);
strcpy(S[Record_Tol].Stud_Roll,Profile.FAdv_Ent[0].TAdv_Text);
strcpy(S[Record_Tol].Stud_Admn,Profile.FAdv_Ent[1].TAdv_Text);
strcpy(S[Record_Tol].Stud_Name_Self,Profile.FAdv_Ent[2].TAdv_Text);
strcpy(S[Record_Tol].Stud_Name_Father,Profile.FAdv_Ent[3].TAdv_Text);
strcpy(S[Record_Tol].Stud_Name_Mother,Profile.FAdv_Ent[4].TAdv_Text);
Prog.WAdv_Update(5);
strcpy(S[Record_Tol].Stud_DOB,Profile.FAdv_Ent[10].TAdv_Text);
strcpy(S[Record_Tol].Stud_Addr,Profile.FAdv_Ent[8].TAdv_Text);
strcpy(S[Record_Tol].Stud_School,Profile.FAdv_Ent[5].TAdv_Text);
strcpy(S[Record_Tol].Stud_Phone,Marks.FAdv_Ent[5].TAdv_Text);
strcpy(S[Record_Tol].Stud_Caste,Profile.FAdv_Ent[9].TAdv_Text);
Prog.WAdv_Update(10);
strcpy(S[Record_Tol].Stud_Stream,Profile.FAdv_Ent[6].TAdv_Text);
strcpy(S[Record_Tol].Stud_Stream_Sub,Profile.FAdv_Ent[7].TAdv_Text);
strcpy(S[Record_Tol].Stud_Stream_Spc,"NIL - Select your carrier");
strcpy(S[Record_Tol].Stud_Marks1,Marks.FAdv_Ent[0].TAdv_Text);
strcpy(S[Record_Tol].Stud_Marks2,Marks.FAdv_Ent[1].TAdv_Text);
Prog.WAdv_Update(15);
strcpy(S[Record_Tol].Stud_Marks3,Marks.FAdv_Ent[2].TAdv_Text);
strcpy(S[Record_Tol].Stud_Marks4,Marks.FAdv_Ent[3].TAdv_Text);
strcpy(S[Record_Tol].Stud_Marks5,Marks.FAdv_Ent[4].TAdv_Text);
strcpy(S[Record_Tol].Stud_ClgID,"NIL - Select your carrier");
Prog.WAdv_Update(19);
Record_Tol++;
		    }

void StartUp() {

	  Mouse_Init();
	  Mouse_Show();
	  Mouse_Set(getmaxx()/2,getmaxy()/2);
	  delay(100);

	  Wait_Adv Start;
	  //fstream File;

	  Color(0);
	  Graphic_Palette(CP_R,CP_G,CP_B);

	  Start.WAdv_BkColor=2;
	  Start.WAdv_FrColor=11;
	  Start.WAdv_BdrColor=11;
	  Start.WAdv_Init(100);
	  delay(2000);
	  Start.WAdv_Update(10);

	  Menu_Init();
	  delay(500);
	  Start.WAdv_Update(40);

	  Form_Init();
	  delay(500);
	  Start.WAdv_Update(80);

	  MsgB_Init();
	  delay(500);
	  Start.WAdv_Update(90);

	  Record_Tol=0;
	  Record_Tol_Last=0;
	  Record_IsFile=0;
	  //File.open("c:\\CPRecord.Dat",ios::in|
		//	    ios::binary|ios::nocreate);

	  if (0) {
	      Msg_Adv Err;
	      Err.Msg_Title="File I/O Error";
	      Err.Msg_Text[0]="Records file not found.";
	      Err.Msg_Text[1]="--";
	      Err.Msg_Text[2]="--";
	      Err.Msg_Show();
	      Mouse_Hide();
	      cleardevice();
	      Mouse_Show();
	      Start.WAdv_Init(100);
		      }

	   else {

		}

	   Start.WAdv_Update(100);
	   Mouse_Record();
	   return;
		   }

void ShutDown() {
		 //fstream File;
		 int Count=0;

		 //remove("c:\\CPRecord.Dat");
		 //File.open("c:\\CPRecord.Dat",ios::out
		//   |ios::binary);

		 if (1) {
		     Msg_Adv Err;
		     Err.Msg_Title="File I/O Error";
		     Err.Msg_Text[0]="Records file could";
		     Err.Msg_Text[1]="not be created.";
		     Err.Msg_Text[2]="--";
		     Err.Msg_Show();
				    }
		 else {
		     Msg_Adv Prog;
		     Prog.Msg_Title="Please Wait...";
		     Prog.Msg_Text[0]="";
		     Prog.Msg_Text[1]="Updating records file.";
		     Prog.Msg_Text[2]="";
		     Prog.Msg_Show();

		     while (Count<Record_Tol) {
			    //File.write((char*)& S[Count],sizeof(Student));
			    Count++;
					       }
		     //File.close();
		       }

		     Msg_Adv Thk;
		     Thk.Msg_Title="Please Wait...";
		     Thk.Msg_Text[0]="";
		     Thk.Msg_Text[1]="Exiting.";
		     Thk.Msg_Text[2]="";
		     Thk.Msg_Show();

		     }

void About() {
	   Msg_Adv AboutCP;
	   AboutCP.Msg_Title="About...";
	   AboutCP.Msg_Text[0]="Counseller Pro";
	   AboutCP.Msg_Text[1]="Final Build 29-12-2006";
	   AboutCP.Msg_Text[2]="Soumik Chatterjee";
	   AboutCP.Msg_Show();
	      }

void Profile_Delete() {

     int Count1=0,Res;
     Msg_Adv Err,Err2;

     if ((heapcheck()==-1)||(farheapcheck()==-1)) {

	 Msg_Adv FErr;
	 FErr.Msg_Title="FATAL ERROR";
	 FErr.Msg_Text[0]="The C++ heap memory";
	 FErr.Msg_Text[1]="is corrupt. Please";
	 FErr.Msg_Text[2]="exit program.";
	 FErr.Msg_Show();
					    }

     Err.Msg_Title="No Records";
     Err.Msg_Text[0]="There are currently";
     Err.Msg_Text[1]="no profiles stored.";
     Err.Msg_Text[2]="Please add new profile.";

     Err2.Msg_Title="Profile Deleted";
     Err2.Msg_Text[0]="To recover profile";
     Err2.Msg_Text[1]="copy records file";
     Err2.Msg_Text[2]="before exiting.";

     CheckIt:

     if (Record_Tol==0) {
			 Err.Msg_Show();
			 return;
			 }

     Res=Profile_Show("Counseller Pro - Delete Profile",0);
     if (Res==-1) return;

     while (Res<Record_Tol-1) {
	    S[Res]=S[Res+1];
	    Res++;
			       }
     Record_Tol--;
     Err2.Msg_Show();
     goto CheckIt;
		      }

void Profile_View() {

/*                                                                          '
			     A little error check			    '
									   */

     Msg_Adv Err,Err2;

     if ((heapcheck()==-1)||(farheapcheck()==-1)) {

	 Msg_Adv FErr;
	 FErr.Msg_Title="FATAL ERROR";
	 FErr.Msg_Text[0]="The C++ heap memory";
	 FErr.Msg_Text[1]="is corrupt. Please";
	 FErr.Msg_Text[2]="exit program.";
	 FErr.Msg_Show();
					    }

     if (Record_Tol==0) {
	 Err.Msg_Title="No Records";
	 Err.Msg_Text[0]="There are currently";
	 Err.Msg_Text[1]="no profiles stored.";
	 Err.Msg_Text[2]="Please add new profile.";
	 Err.Msg_Show();
	 return;
			 }

/*                                                                          '
		     Initialize the menus and forms			    '
									   */

     Menu_Adv Rec_View;
     Form_Adv Rec_Sel_1,Rec_Sel_2;
     Wait_Adv Prog;

     int Res,LastRes,Count=0,IsEnroll=0,StudRes;
     int IsCollege=0;

     Err.Msg_Title="Enrollment Failed";
     Err.Msg_Text[0]="The university ID";
     Err.Msg_Text[1]="is incorrect or seat";
     Err.Msg_Text[2]="is full.";

     Err2.Msg_Title="Enrollment Successfull";
     Err2.Msg_Text[0]="You have been enrolled";
     Err2.Msg_Text[1]="successfully.";
     Err2.Msg_Text[2]="Congrats...";

     Rec_View.MAdv_Item_Tol=7;

     Rec_View.MAdv_Item_Title[0]="Sort by roll nos.";
     Rec_View.MAdv_Item_Title[1]="Sort by name";
     Rec_View.MAdv_Item_Title[3]="Sort by stream";
     Rec_View.MAdv_Item_Title[4]="Sort by sub-stream";
     Rec_View.MAdv_Item_Title[5]="Sort by specialized stream";
     Rec_View.MAdv_Item_Title[2]="Sort by school";
     Rec_View.MAdv_Item_Title[6]="Cancel";

     Rec_View.MAdv_Item_Desc[0]="View results sorted by increasing";
     Rec_View.MAdv_Item_Desc2[0]="student roll number.";
     Rec_View.MAdv_Item_Desc[1]="View results sorted alphabetically";
     Rec_View.MAdv_Item_Desc2[1]="according to student name.";
     Rec_View.MAdv_Item_Desc[2]="View results sorted alphabetically";
     Rec_View.MAdv_Item_Desc2[2]="according to school.";
     Rec_View.MAdv_Item_Desc[3]="View results sorted alphabetically";
     Rec_View.MAdv_Item_Desc2[3]="according to stream.";
     Rec_View.MAdv_Item_Desc[4]="View results sorted alphabetically";
     Rec_View.MAdv_Item_Desc2[4]="according to sub stream.";
     Rec_View.MAdv_Item_Desc[5]="View results sorted alphabetically";
     Rec_View.MAdv_Item_Desc2[5]="according to specialized stream.";
     Rec_View.MAdv_Item_Desc[6]="Cancel profile viewing and return";
     Rec_View.MAdv_Item_Desc2[6]="to home menu.";

     Rec_View.MAdv_Title="Counseller Pro - View Profile";
     Rec_View.MAdv_Desc="There were some records found.";
     Rec_View.MAdv_Desc2="Select the way you want to sort the profile for viewing.";
     Rec_View.MAdv_Desc3="Click cancel to return to home menu.";

     Rec_Sel_1.FAdv_Cmd_Tol=3;
     Rec_Sel_1.FAdv_Title="View Profile - Student Details";
     Rec_Sel_1.FAdv_Cmd_Title[0]="Next";
     Rec_Sel_1.FAdv_Cmd_Title[1]="OK";
     Rec_Sel_1.FAdv_Cmd_Title[2]="Cancel";
     Rec_Sel_1.FAdv_Cmd_Desc[0]="View subject marks and a few";
     Rec_Sel_1.FAdv_Cmd_Desc2[0]="other details.";
     Rec_Sel_1.FAdv_Cmd_Desc[1]="Save and return to sorted";
     Rec_Sel_1.FAdv_Cmd_Desc2[1]="results.";
     Rec_Sel_1.FAdv_Cmd_Desc[2]="Cancel changes and return to";
     Rec_Sel_1.FAdv_Cmd_Desc2[2]="sorted results";
     Rec_Sel_1.FAdv_Ent_Tol=11;

     Rec_Sel_2.FAdv_Cmd_Tol=3;
     Rec_Sel_2.FAdv_Title="View Profile - Subject Marks";
     Rec_Sel_2.FAdv_Cmd_Title[1]="OK";
     Rec_Sel_2.FAdv_Cmd_Title[0]="Back";
     Rec_Sel_2.FAdv_Cmd_Title[2]="Cancel";
     Rec_Sel_2.FAdv_Cmd_Desc[1]="Save and return to sorted";
     Rec_Sel_2.FAdv_Cmd_Desc2[1]="results.";
     Rec_Sel_2.FAdv_Cmd_Desc[0]="Go back and change the entered";
     Rec_Sel_2.FAdv_Cmd_Desc2[0]="student details.";
     Rec_Sel_2.FAdv_Cmd_Desc[2]="Cancel changes and return to";
     Rec_Sel_2.FAdv_Cmd_Desc2[2]="sorted results";
     Rec_Sel_2.FAdv_Ent_Tol=8;

     Rec_Sel_1.FAdv_Ent[0].TAdv_Title="Roll Nos. :";
     Rec_Sel_1.FAdv_Ent[1].TAdv_Title="Admission Nos. :";
     Rec_Sel_1.FAdv_Ent[2].TAdv_Title="Student Name :";
     Rec_Sel_1.FAdv_Ent[3].TAdv_Title="Father's Name :";
     Rec_Sel_1.FAdv_Ent[4].TAdv_Title="Mother's Name :";
     Rec_Sel_1.FAdv_Ent[5].TAdv_Title="School :";
     Rec_Sel_1.FAdv_Ent[6].TAdv_Title="Stream :";
     Rec_Sel_1.FAdv_Ent[7].TAdv_Title="Sub-Stream :";
     Rec_Sel_1.FAdv_Ent[8].TAdv_Title="Address :";
     Rec_Sel_1.FAdv_Ent[9].TAdv_Title="Caste Category :";
     Rec_Sel_1.FAdv_Ent[10].TAdv_Title="Date of Birth :";

     Rec_Sel_2.FAdv_Ent[0].TAdv_Title="Marks 1 :";
     Rec_Sel_2.FAdv_Ent[1].TAdv_Title="Marks 2 :";
     Rec_Sel_2.FAdv_Ent[2].TAdv_Title="Marks 3 :";
     Rec_Sel_2.FAdv_Ent[3].TAdv_Title="Marks 4 :";
     Rec_Sel_2.FAdv_Ent[4].TAdv_Title="Marks 5 :";
     Rec_Sel_2.FAdv_Ent[7].TAdv_Title="Phone No. :";
     Rec_Sel_2.FAdv_Ent[5].TAdv_Title="Specialized Stream :";
     Rec_Sel_2.FAdv_Ent[6].TAdv_Title="University ID :";

     ShowSort:

     Rec_View.MAdv_Init(0);
     Res=Rec_View.MAdv_Navigate();
     LastRes=Res;

     if ((Res==-1)||(Res==6)) return;

     ShowRes:
     Res=Profile_Show("Countseller Pro - View Profiles",LastRes);
     if (Res==-1) goto ShowSort;

/*                                                                          '
			   Copy the appropiate details			    '
									   */

     StudRes=Res;
     IsEnroll=0;
     IsCollege=0;

     strcpy(Rec_Sel_1.FAdv_Ent[0].TAdv_Text,S[Res].Stud_Roll);
     strcpy(Rec_Sel_1.FAdv_Ent[1].TAdv_Text,S[Res].Stud_Admn);
     strcpy(Rec_Sel_1.FAdv_Ent[2].TAdv_Text,S[Res].Stud_Name_Self);
     strcpy(Rec_Sel_1.FAdv_Ent[3].TAdv_Text,S[Res].Stud_Name_Father);
     strcpy(Rec_Sel_1.FAdv_Ent[4].TAdv_Text,S[Res].Stud_Name_Mother);
     strcpy(Rec_Sel_1.FAdv_Ent[5].TAdv_Text,S[Res].Stud_School);
     strcpy(Rec_Sel_1.FAdv_Ent[6].TAdv_Text,S[Res].Stud_Stream);
     strcpy(Rec_Sel_1.FAdv_Ent[7].TAdv_Text,S[Res].Stud_Stream_Sub);
     strcpy(Rec_Sel_1.FAdv_Ent[8].TAdv_Text,S[Res].Stud_Addr);
     strcpy(Rec_Sel_1.FAdv_Ent[9].TAdv_Text,S[Res].Stud_Caste);
     strcpy(Rec_Sel_1.FAdv_Ent[10].TAdv_Text,S[Res].Stud_DOB);

     strcpy(Rec_Sel_2.FAdv_Ent[0].TAdv_Text,S[Res].Stud_Marks1);
     strcpy(Rec_Sel_2.FAdv_Ent[1].TAdv_Text,S[Res].Stud_Marks2);
     strcpy(Rec_Sel_2.FAdv_Ent[2].TAdv_Text,S[Res].Stud_Marks3);
     strcpy(Rec_Sel_2.FAdv_Ent[3].TAdv_Text,S[Res].Stud_Marks4);
     strcpy(Rec_Sel_2.FAdv_Ent[4].TAdv_Text,S[Res].Stud_Marks5);
     strcpy(Rec_Sel_2.FAdv_Ent[7].TAdv_Text,S[Res].Stud_Phone);
     strcpy(Rec_Sel_2.FAdv_Ent[5].TAdv_Text,S[Res].Stud_Stream_Spc);
     strcpy(Rec_Sel_2.FAdv_Ent[6].TAdv_Text,S[Res].Stud_ClgID);

/*                                                                          '
		       Show the selected profile			    '
									   */

     ShowSel1:

     Rec_Sel_1.FAdv_Init(0);
     Res=Rec_Sel_1.FAdv_Navigate();
     if ((Res==-1)||(Res==2)) goto ShowRes;
     else if (Res==0) goto ShowSel2;
     else goto SaveSel;

     ShowSel2:

     Rec_Sel_2.FAdv_Init(0);
     Res=Rec_Sel_2.FAdv_Navigate();
     if ((Res==-1)||(Res==2)) goto ShowRes;
     else if (Res==0) goto ShowSel1;
     else goto SaveSel;

     SaveSel:

/*                                                                          '
		       Check presence of invaid entries			    '
									   */

     if ((strlen(Rec_Sel_1.FAdv_Ent[0].TAdv_Text)==0)||(strlen(Rec_Sel_1.FAdv_Ent[5].TAdv_Text)==0)||
	 (strlen(Rec_Sel_1.FAdv_Ent[1].TAdv_Text)==0)||(strlen(Rec_Sel_1.FAdv_Ent[6].TAdv_Text)==0)||
	 (strlen(Rec_Sel_1.FAdv_Ent[2].TAdv_Text)==0)||(strlen(Rec_Sel_1.FAdv_Ent[7].TAdv_Text)==0)||
	 (strlen(Rec_Sel_1.FAdv_Ent[3].TAdv_Text)==0)||(strlen(Rec_Sel_1.FAdv_Ent[8].TAdv_Text)==0)||
	 (strlen(Rec_Sel_1.FAdv_Ent[4].TAdv_Text)==0)||(strlen(Rec_Sel_1.FAdv_Ent[9].TAdv_Text)==0)||
	 (strlen(Rec_Sel_1.FAdv_Ent[10].TAdv_Text)==0)||(strlen(Rec_Sel_2.FAdv_Ent[0].TAdv_Text)==0)||
	 (strlen(Rec_Sel_2.FAdv_Ent[1].TAdv_Text)==0)||(strlen(Rec_Sel_2.FAdv_Ent[2].TAdv_Text)==0)||
	 (strlen(Rec_Sel_2.FAdv_Ent[3].TAdv_Text)==0)||(strlen(Rec_Sel_2.FAdv_Ent[4].TAdv_Text)==0)||
	 (strlen(Rec_Sel_2.FAdv_Ent[5].TAdv_Text)==0)||(strlen(Rec_Sel_2.FAdv_Ent[6].TAdv_Text)==0)||
	 (strlen(Rec_Sel_2.FAdv_Ent[7].TAdv_Text)==0)) {
							Err.Msg_Show();
							goto ShowSel1;
						       }

     IsCollege=IsClgID(Rec_Sel_2.FAdv_Ent[6].TAdv_Text);
     if (IsCollege==1) IsEnroll=IsClgSeat(Rec_Sel_2.FAdv_Ent[6].TAdv_Text);
     if ((IsCollege==0)||(IsEnroll==0)) Err.Msg_Show();

/*                                                                          '
			   Enter data into array			    '
									   */

    Prog.WAdv_Init(19);

    strcpy(S[StudRes].Stud_Roll,Rec_Sel_1.FAdv_Ent[0].TAdv_Text);
    strcpy(S[StudRes].Stud_Admn,Rec_Sel_1.FAdv_Ent[1].TAdv_Text);
    strcpy(S[StudRes].Stud_Name_Self,Rec_Sel_1.FAdv_Ent[2].TAdv_Text);
    strcpy(S[StudRes].Stud_Name_Father,Rec_Sel_1.FAdv_Ent[3].TAdv_Text);
    strcpy(S[StudRes].Stud_Name_Mother,Rec_Sel_1.FAdv_Ent[4].TAdv_Text);
    Prog.WAdv_Update(5);

    strcpy(S[StudRes].Stud_DOB,Rec_Sel_1.FAdv_Ent[10].TAdv_Text);
    strcpy(S[StudRes].Stud_Addr,Rec_Sel_1.FAdv_Ent[8].TAdv_Text);
    strcpy(S[StudRes].Stud_School,Rec_Sel_1.FAdv_Ent[5].TAdv_Text);
    strcpy(S[StudRes].Stud_Phone,Rec_Sel_2.FAdv_Ent[7].TAdv_Text);
    strcpy(S[StudRes].Stud_Caste,Rec_Sel_1.FAdv_Ent[9].TAdv_Text);
    Prog.WAdv_Update(10);

    strcpy(S[StudRes].Stud_Stream,Rec_Sel_1.FAdv_Ent[6].TAdv_Text);
    strcpy(S[StudRes].Stud_Stream_Sub,Rec_Sel_1.FAdv_Ent[7].TAdv_Text);
    strcpy(S[StudRes].Stud_Stream_Spc,Rec_Sel_2.FAdv_Ent[5].TAdv_Text);
    strcpy(S[StudRes].Stud_Marks1,Rec_Sel_2.FAdv_Ent[0].TAdv_Text);
    strcpy(S[StudRes].Stud_Marks2,Rec_Sel_2.FAdv_Ent[1].TAdv_Text);
    Prog.WAdv_Update(15);

    strcpy(S[StudRes].Stud_Marks3,Rec_Sel_2.FAdv_Ent[2].TAdv_Text);
    strcpy(S[StudRes].Stud_Marks4,Rec_Sel_2.FAdv_Ent[3].TAdv_Text);
    strcpy(S[StudRes].Stud_Marks5,Rec_Sel_2.FAdv_Ent[4].TAdv_Text);
    strcpy(S[StudRes].Stud_ClgID,Rec_Sel_2.FAdv_Ent[6].TAdv_Text);
    Prog.WAdv_Update(19);

    if (IsEnroll==1) {
		      Err2.Msg_Show();
		      //Enroll it;
		     }

    goto ShowSort;
		      }


void Profile_Carrier() { }
void Help() { }
void Config() {

     int a=getgraphmode();
     int Res,Count;
     char b[2];
     b[1]=NULL;

     if ((heapcheck()==-1)||(farheapcheck()==-1)) {

	 Msg_Adv FErr;
	 FErr.Msg_Title="FATAL ERROR";
	 FErr.Msg_Text[0]="The C++ heap memory";
	 FErr.Msg_Text[1]="is corrupt. Please";
	 FErr.Msg_Text[2]="exit program.";
	 FErr.Msg_Show();
					    }

     cleardevice();
     restorecrtmode();

     thestart:
     clrscr();

     cout<<"Counseller Pro Configuration Utility";
     cout<<"\nConseller Pro version 1.00";
     cout<<"\nBuild 29-12-2006";

     cout<<"\n\n\n\nThis mode helps you find memory leaks";
     cout<<" and fix errors which can stop unusual program";
     cout<<" crashes and malfunctioning. This mode runs";
     cout<<" in CRT mode so as not to cause overflows itself.";

     cout<<"\n\n\n\nTotal Records (Current): "<<Record_Tol;
     cout<<"\nTotal Records (In file): "<<Record_Tol_Last;
     cout<<"\nColor Scheme :"<<ColorScheme;
     cout<<"\nRecords Database Path : c:\\";
     cout<<"\nRecords File Exists :"<<Record_IsFile;
     cout<<"\nC++ Heap Check :"<<heapcheck();
     cout<<"\nC++ Heap Check (far):"<<farheapcheck();

     cout<<"\n\nPress esc to return, enter to view all records.\n";
     cout<<"c to change color scheme ...\n";

     while (bioskey(1)==0);
     Res=bioskey(0);

     if (Res==11875) {
		       clrscr();
		       cout<<"...";
		       while (bioskey(1)==0);
		       Res=bioskey(0);
		       b[0]=KC_To_Char(Res);
		       Color(atoi(b));
		       clrscr();
		       cout<<"Please wait...";
		       delay(2000);
		       goto thestart;
		     }

     else if (Res!=7181) goto theend;

     Count=0;
     while (Count<Record_Tol) {

    clrscr();
    cout<<"\n"<<S[Count].Stud_Roll;
    cout<<"\n"<<S[Count].Stud_Admn;
    cout<<"\n"<<S[Count].Stud_Name_Self;
    cout<<"\n"<<S[Count].Stud_Name_Father;
    cout<<"\n"<<S[Count].Stud_Name_Mother;
    cout<<"\n"<<S[Count].Stud_DOB;
    cout<<"\n"<<S[Count].Stud_Addr;
    cout<<"\n"<<S[Count].Stud_School;
    cout<<"\n"<<S[Count].Stud_Phone;
    cout<<"\n"<<S[Count].Stud_Caste;
    cout<<"\n"<<S[Count].Stud_Stream;
    cout<<"\n"<<S[Count].Stud_Stream_Sub;
    cout<<"\n"<<S[Count].Stud_Stream_Spc;
    cout<<"\n"<<S[Count].Stud_Marks1;
    cout<<"\n"<<S[Count].Stud_Marks2;
    cout<<"\n"<<S[Count].Stud_Marks3;
    cout<<"\n"<<S[Count].Stud_Marks4;
    cout<<"\n"<<S[Count].Stud_Marks5;
    cout<<"\n"<<S[Count].Stud_ClgID;

	    cout<<"\nEnter to continue...\n";
	    while (bioskey(1)==0);
	    Res=bioskey(0);
	    if (Res!=7181) goto thestart;
	    Count++;
			      }

     goto thestart;

     theend:
     setgraphmode(a);
     Graphic_Palette(CP_R,CP_G,CP_B);
     return;
	       }
