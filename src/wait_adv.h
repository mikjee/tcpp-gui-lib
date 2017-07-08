
class Wait_Adv {
     private:
	     double WAdv_Tol;
	     double WAdv_Done;
	     double WAdv_Last;
      public:
	     static int WAdv_BkColor;
	     static int WAdv_FrColor;
	     static int WAdv_BdrColor;

      public:
	     Wait_Adv();
	     void WAdv_Init(int);
	     void WAdv_Update(int);
		};

int Wait_Adv::WAdv_BkColor;
int Wait_Adv::WAdv_FrColor;
int Wait_Adv::WAdv_BdrColor;

Wait_Adv::Wait_Adv() {     }

void Wait_Adv::WAdv_Init(int New_Tol) {

	       Mouse_Hide();

	       setcolor(WAdv_BkColor);
	       setlinestyle(0,0,1);
	       setfillstyle(1,WAdv_BkColor);

	       pieslice(getmaxx()/2+50,getmaxy()/2,0,360,12);
	       pieslice(getmaxx()/2-50,getmaxy()/2,0,360,12);
	       bar(getmaxx()/2-50,getmaxy()/2-12,
	       getmaxx()/2+50,getmaxy()/2+12);

	       setcolor(WAdv_BdrColor);
	       line(getmaxx()/2-50,getmaxy()/2-12,
		    getmaxx()/2+50,getmaxy()/2-12);
	       line(getmaxx()/2-50,getmaxy()/2+12,
		    getmaxx()/2+50,getmaxy()/2+12);
	       arc(getmaxx()/2-50,getmaxy()/2,90,270,12);
	       arc(getmaxx()/2+50,getmaxy()/2,270,90,12);

	       setfillstyle(1,WAdv_FrColor);
	       setcolor(WAdv_FrColor);
	       pieslice(getmaxx()/2-45,getmaxy()/2,0,360,3);

	       Mouse_Show();
	       WAdv_Tol=New_Tol;
	       WAdv_Last=0;
	       WAdv_Done=0;
		      }

void Wait_Adv::WAdv_Update(int New_Done) {

	       setcolor(WAdv_FrColor);
	       setfillstyle(1,WAdv_FrColor);
	       setlinestyle(0,0,1);

	       double Count = WAdv_Last;
	       int Rate = 2;
	       WAdv_Done=New_Done;

	       while ( Count <= 90*(WAdv_Done/WAdv_Tol) ) {

		      Mouse_Hide();

		      bar(Count+getmaxx()/2-45,getmaxy()/2-3,
			  Count+getmaxx()/2-45+Rate,getmaxy()/2+3);
		      pieslice(Count+getmaxx()/2-45+Rate,getmaxy()/2,
			       0,360,3);

		      Mouse_Show();
		      delay(25);
		      Count=Count+Rate;
							 }

	       WAdv_Last=90*(WAdv_Done/WAdv_Tol);
	       Mouse_Record();
				}

/*
main() {

Graphic_Init(20000);
Wait_Adv a;

a.WAdv_BkColor=4;
a.WAdv_FrColor=12;
a.WAdv_BdrColor=12;

a.WAdv_Init(100);
getch();


a.WAdv_Update(50);
getch();

a.WAdv_Update(75);
getch();

a.WAdv_Update(100);
getch();

Graphic_DeInit();
}
*/