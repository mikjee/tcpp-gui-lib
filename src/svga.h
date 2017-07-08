
int Graph_Res=0;
int huge DetectSVGA256() { return Graph_Res; }

void Graphic_Init(long g_Buf_Size,int is_SVGA=0) {

		 int g_Driver=VGA,g_Mode=VGAHI,g_Error,g_Size;

		 if (is_SVGA==1) {
		     g_Driver=installuserdriver("BGI256V2",DetectSVGA256);
		     g_Driver=DETECT;
				 }

		 g_Size =setgraphbufsize(g_Buf_Size);
		 initgraph(&g_Driver,&g_Mode,"c:\\tc\\bgi\\");
		 g_Error = graphresult();

		 if (g_Error < 0) {
				  cprintf("\nGraphic_Init:Graphics Initialization Failed.\n");
				  cprintf(grapherrormsg(g_Error));
				  getch();
				  exit(1);
					    }
		 cleardevice();
		 return;
		 }

void Graphic_Palette(int R[16],int G[16],int B[16]) {

		     struct palettetype Pal;
		     int Count=0;
		     getpalette(&Pal);

		     while (Count<Pal.size) {
			    setrgbpalette(Pal.colors[Count],R[Count],G[Count],B[Count]);
			    Count++;
				      }

		    return;
						    }

void Graphic_DeInit() {
		   cleardevice();
		   closegraph();
		   return;
		   }

//void main() {
  //	   Graph_Res=2;
    //	   Graphic_Init(50000);
      //
	//   int col=0;
	  // while (col<5000)
	   //{
	    //setfillstyle(1,col);
	    //bar(400,400,500,500);
	    //cout<<col;
	    //while(bioskey(1)==0);
	    //if (bioskey(0)==7181) return;
	    //col++;
	    //}
	    //getch();
	    //}
