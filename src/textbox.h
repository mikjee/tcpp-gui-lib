
class Text_Adv {

      public:
	      char TAdv_Text[50];
	      char* TAdv_Title;
	      int TAdv_Text_Len;
	      int TAdv_Is_RO;
	      int TAdv_X,TAdv_Y;
     private:
	      int TAdv_Is_Act;
	      static int TAdv_Height;
      public:
	      static int TAdv_BkColor;
	      static int TAdv_FrColor;
	      static int TAdv_TxtColor;
	      static int TAdv_BdrColor;
	      static int TAdv_Sel_BkColor;
	      static int TAdv_Sel_FrColor;
	      static int TAdv_Sel_BdrColor;
	      static int TAdv_Sel_TxtColor;
	      static int TAdv_Act_BkColor;
	      static int TAdv_Act_FrColor;
	      static int TAdv_Act_BdrColor;
	      static int TAdv_Act_TxtColor;
	      static int TAdv_Act_BkColor2;
	      static int TAdv_Act_BdrColor2;
	      static int TAdv_FntTp;
	      static int TAdv_FntSz;

      public:

	      Text_Adv();
	      ~Text_Adv();
	      void TAdv_Init();
	      void TAdv_Activate();
	      void TAdv_Select();
	      void TAdv_DeSelect();
	      void TAdv_Input(int);

		};

int Text_Adv::TAdv_BkColor;
int Text_Adv::TAdv_FrColor;
int Text_Adv::TAdv_TxtColor;
int Text_Adv::TAdv_BdrColor;
int Text_Adv::TAdv_Sel_BkColor;
int Text_Adv::TAdv_Sel_FrColor;
int Text_Adv::TAdv_Sel_BdrColor;
int Text_Adv::TAdv_Sel_TxtColor;
int Text_Adv::TAdv_Act_BkColor;
int Text_Adv::TAdv_Act_FrColor;
int Text_Adv::TAdv_Act_BdrColor;
int Text_Adv::TAdv_Act_TxtColor;
int Text_Adv::TAdv_Act_BkColor2;
int Text_Adv::TAdv_Act_BdrColor2;
int Text_Adv::TAdv_FntTp;
int Text_Adv::TAdv_FntSz;
int Text_Adv::TAdv_Height;

Text_Adv::Text_Adv() {
		     int Count=0;
		     while (Count<50) {
			    TAdv_Text[Count]=NULL;
			    Count++;
				       }
		     TAdv_Title=(char*)calloc(100,sizeof(char));
		     strset(TAdv_Title,NULL);
		     TAdv_Height=25;
		     TAdv_Text_Len=0;
		     TAdv_Is_Act=0;
		     TAdv_Is_RO=0;
		      }

Text_Adv::~Text_Adv() {
		      //free(TAdv_Title);
		      //free((void*)TAdv_Text);
		      }
void Text_Adv::TAdv_Init() {

	       Mouse_Hide();

	       setcolor(TAdv_BkColor);
	       setfillstyle(1,TAdv_BkColor);
	       settextstyle(TAdv_FntTp,0,TAdv_FntSz);
	       setlinestyle(0,0,1);

	       TAdv_Text_Len=strlen((char*)TAdv_Text);

	       bar(TAdv_X,TAdv_Y,TAdv_X+450,TAdv_Y+TAdv_Height);
	       setcolor(TAdv_BdrColor);
	       rectangle(TAdv_X,TAdv_Y,TAdv_X+450,TAdv_Y+TAdv_Height);

	       setcolor(TAdv_FrColor);
	       outtextxy(TAdv_X+5,TAdv_Y+9,TAdv_Title);
	       setcolor(TAdv_TxtColor);
	       outtextxy(TAdv_X+5+textwidth(TAdv_Title)
			 +textwidth(" "),TAdv_Y+9,TAdv_Text);

	       Mouse_Show();
						     }
void Text_Adv::TAdv_Activate() {

	       if (TAdv_Is_RO==1) return;

	       Mouse_Hide();

	       setcolor(TAdv_Act_BkColor);
	       setfillstyle(1,TAdv_Act_BkColor);
	       settextstyle(TAdv_FntTp,0,TAdv_FntSz);
	       setlinestyle(0,0,1);

	       bar(TAdv_X,TAdv_Y,TAdv_X+450,TAdv_Y+TAdv_Height);
	       setcolor(TAdv_Act_BdrColor);
	       rectangle(TAdv_X,TAdv_Y,TAdv_X+450,TAdv_Y+TAdv_Height);
	       setcolor(TAdv_Act_FrColor);
	       outtextxy(TAdv_X+5,TAdv_Y+9,TAdv_Title);

	       setcolor(TAdv_Act_BkColor2);
	       setfillstyle(1,TAdv_Act_BkColor2);
	       bar(TAdv_X+3+textwidth(TAdv_Title)+textwidth(" "),
		   TAdv_Y+5,TAdv_X+445,TAdv_Y+TAdv_Height-5);

	       setcolor(TAdv_Act_BdrColor2);
	       setfillstyle(1,TAdv_Act_BdrColor2);
	       setlinestyle(0,0,1);
	       rectangle(TAdv_X+3+textwidth(TAdv_Title)+textwidth(" "),
			 TAdv_Y+5,TAdv_X+445,TAdv_Y+TAdv_Height-5);

	       setfillstyle(1,TAdv_Sel_BkColor);
	       bar(TAdv_X+5+textwidth(TAdv_Title)+textwidth(" ")
		   +textwidth(TAdv_Text),TAdv_Y+6,
		   TAdv_X+5+textwidth(TAdv_Title)+textwidth(" ")
		   +textwidth(TAdv_Text)+5,TAdv_Y+TAdv_Height-6);

	       setcolor(TAdv_Act_TxtColor);
	       outtextxy(TAdv_X+5+textwidth(TAdv_Title)
			 +textwidth(" "),TAdv_Y+9,TAdv_Text);

	       TAdv_Is_Act=1;
	       Mouse_Show();
			     }

void Text_Adv::TAdv_Select() {

	       if (TAdv_Is_RO==1) return;

	       Mouse_Hide();

	       setcolor(TAdv_Sel_BkColor);
	       setfillstyle(1,TAdv_Sel_BkColor);
	       settextstyle(TAdv_FntTp,0,TAdv_FntSz);
	       setlinestyle(0,0,1);

	       bar(TAdv_X,TAdv_Y,TAdv_X+450,TAdv_Y+TAdv_Height);
	       setcolor(TAdv_Sel_BdrColor);
	       rectangle(TAdv_X,TAdv_Y,TAdv_X+450,TAdv_Y+TAdv_Height);
	       setcolor(TAdv_Sel_FrColor);
	       outtextxy(TAdv_X+5,TAdv_Y+9,TAdv_Title);

	       setcolor(TAdv_Sel_TxtColor);
	       outtextxy(TAdv_X+5+textwidth(TAdv_Title)
			 +textwidth(" "),TAdv_Y+9,TAdv_Text);

	       TAdv_Is_Act=0;
	       Mouse_Show();
			     }

void Text_Adv::TAdv_DeSelect() {

	       if (TAdv_Is_RO==1) return;

	       Mouse_Hide();

	       setcolor(TAdv_BkColor);
	       setfillstyle(1,TAdv_BkColor);
	       settextstyle(TAdv_FntTp,0,TAdv_FntSz);
	       setlinestyle(0,0,1);

	       bar(TAdv_X,TAdv_Y,TAdv_X+450,TAdv_Y+TAdv_Height);
	       setcolor(TAdv_BdrColor);
	       rectangle(TAdv_X,TAdv_Y,TAdv_X+450,TAdv_Y+TAdv_Height);

	       setcolor(TAdv_FrColor);
	       outtextxy(TAdv_X+5,TAdv_Y+9,TAdv_Title);
	       setcolor(TAdv_TxtColor);
	       outtextxy(TAdv_X+5+textwidth(TAdv_Title)
			 +textwidth(" "),TAdv_Y+9,TAdv_Text);

	       TAdv_Is_Act=0;
	       Mouse_Show();
			       }

void Text_Adv::TAdv_Input(int Key) {
	      if (TAdv_Is_RO==1) return;
	      if (TAdv_Is_Act==0) return;
	      if ((Key==18432)||(Key==20480)||
		 (Key==19712)||(Key==19200)) return;

	      Mouse_Hide();

	      if ((Key==3592)&&(TAdv_Text_Len>0)) {

		   TAdv_Text_Len--;

		   setcolor(TAdv_Act_BkColor2);
		   setfillstyle(1,TAdv_Act_BkColor2);
		   bar(TAdv_X+5+textwidth(TAdv_Title)+textwidth(" "),
		       TAdv_Y+6,TAdv_X+5+textwidth(TAdv_Title)+textwidth(" ")
		       +textwidth(TAdv_Text)+5,TAdv_Y+TAdv_Height-6);

		   TAdv_Text[TAdv_Text_Len]=NULL;

		   setcolor(TAdv_Act_TxtColor);
		   settextstyle(TAdv_FntTp,0,TAdv_FntSz);
		   outtextxy(TAdv_X+5+textwidth(TAdv_Title)
			     +textwidth(" "),TAdv_Y+9,TAdv_Text);

		   setfillstyle(1,TAdv_Sel_BkColor);
		   bar(TAdv_X+5+textwidth(TAdv_Title)+textwidth(" ")
		       +textwidth(TAdv_Text),TAdv_Y+6,
		       TAdv_X+5+textwidth(TAdv_Title)+textwidth(" ")
		       +textwidth(TAdv_Text)+5,TAdv_Y+TAdv_Height-6);

						 }

	      else if ((TAdv_Text_Len<50)&&(Key!=3592)&&
		       (textwidth(TAdv_Text)+textwidth("  ")+
			textwidth(TAdv_Title) < 438)) {

		   TAdv_Text[TAdv_Text_Len]=KC_To_Char(Key);

		   setcolor(TAdv_Act_BkColor2);
		   setfillstyle(1,TAdv_Act_BkColor2);
		   bar(TAdv_X+5+textwidth(TAdv_Title)+textwidth(" "),
		       TAdv_Y+6,TAdv_X+5+textwidth(TAdv_Title)+textwidth(" ")
		       +textwidth(TAdv_Text)+6,TAdv_Y+TAdv_Height-6);

		   setcolor(TAdv_Act_TxtColor);
		   settextstyle(TAdv_FntTp,0,TAdv_FntSz);
		   outtextxy(TAdv_X+5+textwidth(TAdv_Title)
			     +textwidth(" "),TAdv_Y+9,TAdv_Text);

		   setfillstyle(1,TAdv_Sel_BkColor);
		   bar(TAdv_X+5+textwidth(TAdv_Title)+textwidth(" ")
		       +textwidth(TAdv_Text),TAdv_Y+6,
		       TAdv_X+5+textwidth(TAdv_Title)+textwidth(" ")
		       +textwidth(TAdv_Text)+5,TAdv_Y+TAdv_Height-6);

		   TAdv_Text_Len++;
						   }

	      Mouse_Show();
				   }
