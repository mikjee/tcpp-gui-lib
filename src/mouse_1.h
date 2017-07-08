int Recorded_X;
int Recorded_Y;

void Mouse_Init() {
     _AX=0;
     geninterrupt(0x33);
		  }

void Mouse_DeInit() {
     _AX=0;
     geninterrupt(0x33);
		    }

void Mouse_Show() {
     _AX=1;
     geninterrupt(0x33);
		  }

void Mouse_Hide() {
     _AX=2;
     geninterrupt(0x33);
		  }

void Mouse_Block(int x1,int y1,int x2,int y2)
{
	_AX=7;
	_CX=x1;
	_DX=x2;
	geninterrupt(0x33);
	_AX=8;
	_CX=y1;
	_DX=y2;
	geninterrupt(0x33);
}

void Mouse_Get(int *Button,int *X,int *Y)
{
	_AX=3;
	geninterrupt(0x33);
	*Button=_BX;
	*X=_CX;
	*Y=_DX;
}

void Mouse_Record()
{
	int Button;
	Mouse_Get(&Button,&Recorded_X,&Recorded_Y);
}

void Mouse_Set(int X,int Y)
{
	_AX=4;
	_CX=X;
	_DX=Y;
	geninterrupt(0x33);
}

void Mouse_Set_Recorded()
{
	Mouse_Set(Recorded_X,Recorded_Y);
}