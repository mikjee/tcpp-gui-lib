
class Msg_Adv {
      public:
	      char* Msg_Text[3];
	      char* Msg_Title;

	      static int Msg_BkColor;
	      static int Msg_FrColor;
	      static int Msg_BkColor2;
	      static int Msg_FrColor2;
	      static int Msg_BdrColor;
	      static int Msg_TimeOut;

      private:
	      int Msg_IsFree;
      public:
	      Msg_Adv();
	      ~Msg_Adv();
	      void Msg_Show();
	      void Msg_Free();
	      };

int Msg_Adv::Msg_BkColor;
int Msg_Adv::Msg_FrColor;
int Msg_Adv::Msg_FrColor2;
int Msg_Adv::Msg_BkColor2;
int Msg_Adv::Msg_BdrColor;
int Msg_Adv::Msg_TimeOut;

Msg_Adv::Msg_Adv() {
		   Msg_Text[0]=(char*) calloc(25,sizeof(char));
		   Msg_Text[1]=(char*) calloc(25,sizeof(char));
		   Msg_Text[2]=(char*) calloc(25,sizeof(char));
		   Msg_Title=(char*) calloc(25,sizeof(char));

		   strset(Msg_Text[0],NULL);
		   strset(Msg_Text[1],NULL);
		   strset(Msg_Text[2],NULL);
		   strset(Msg_Title,NULL);
		   Msg_IsFree=0;
		   }

void Msg_Adv::Msg_Free() {
		     if (Msg_IsFree==1) return;
		     free(Msg_Text[0]);
		     free(Msg_Text[1]);
		     free(Msg_Text[2]);
		     free(Msg_Title);
		     Msg_IsFree=1;
		     }

Msg_Adv::~Msg_Adv() { //Msg_Free();
		     }

void Msg_Adv::Msg_Show() {
		     if (Msg_IsFree==1) return;
		     Mouse_Hide();

		     setcolor(Msg_BkColor);
		     setfillstyle(1,Msg_BkColor);
		     bar(getmaxx()/2-100,getmaxy()/2-40,
			 getmaxx()/2+100,getmaxy()/2+40);

		     setcolor(Msg_BdrColor);
		     setfillstyle(1,Msg_BkColor2);
		     setlinestyle(0,0,1);
		     rectangle(getmaxx()/2-100,getmaxy()/2-40,
			       getmaxx()/2+100,getmaxy()/2+40);
		     bar(getmaxx()/2-100,getmaxy()/2-40,
			 getmaxx()/2+100,getmaxy()/2-15);
		     rectangle(getmaxx()/2-100,getmaxy()/2-40,
			       getmaxx()/2+100,getmaxy()/2-15);

		     setcolor(Msg_FrColor2);
		     settextstyle(0,0,1);
		     outtextxy(getmaxx()/2-textwidth(Msg_Title)/2,
			       getmaxy()/2-31,Msg_Title);
		     setcolor(Msg_FrColor);
		     outtextxy(getmaxx()/2-textwidth(Msg_Text[0])/2,
			       getmaxy()/2-6,Msg_Text[0]);
		     outtextxy(getmaxx()/2-textwidth(Msg_Text[1])/2,
			       getmaxy()/2-6+textheight("g")+5
			       ,Msg_Text[1]);
		     outtextxy(getmaxx()/2-textwidth(Msg_Text[2])/2,
			       getmaxy()/2-6+2*textheight("g")+10
			       ,Msg_Text[2]);

		     Mouse_Show();
		     delay(Msg_TimeOut);
		     Mouse_Record();
		     }

