
class Student {
      public:
		char Stud_Roll[50];
		char Stud_Admn[50];
		char Stud_Name_Self[50];
		char Stud_Name_Father[50];
		char Stud_Name_Mother[50];
		char Stud_DOB[50];
		char Stud_Addr[50];
		char Stud_School[50];
		char Stud_Phone[50];
		char Stud_Caste[50];
		char Stud_Stream[50];
		char Stud_Stream_Sub[50];
		char Stud_Stream_Spc[50];
		char Stud_Marks1[50];
		char Stud_Marks2[50];
		char Stud_Marks3[50];
		char Stud_Marks4[50];
		char Stud_Marks5[50];
		char Stud_ClgID[50];

      public:
		Student() {
			/*Stud_Roll=(char*)calloc(50,sizeof(char));
			Stud_Admn=(char*)calloc(50,sizeof(char));
			Stud_Name_Self=(char*)calloc(50,sizeof(char));
			Stud_Name_Father=(char*)calloc(50,sizeof(char));
			Stud_Name_Mother=(char*)calloc(50,sizeof(char));
			Stud_DOB=(char*)calloc(50,sizeof(char));
			Stud_Addr=(char*)calloc(50,sizeof(char));
			Stud_School=(char*)calloc(50,sizeof(char));
			Stud_Phone=(char*)calloc(50,sizeof(char));
			Stud_Caste=(char*)calloc(50,sizeof(char));
			Stud_Stream=(char*)calloc(50,sizeof(char));
			Stud_Stream_Sub=(char*)calloc(50,sizeof(char));
			Stud_Stream_Spc=(char*)calloc(50,sizeof(char));
			Stud_Marks[0]=(char*)calloc(50,sizeof(char));
			Stud_Marks[1]=(char*)calloc(50,sizeof(char));
			Stud_Marks[2]=(char*)calloc(50,sizeof(char));
			Stud_Marks[3]=(char*)calloc(50,sizeof(char));
			Stud_Marks[4]=(char*)calloc(50,sizeof(char));
			Stud_ClgID=(char*)calloc(50,sizeof(char));
		       */
			int Count=0;
			while(Count<50) {
			Stud_Roll[Count]=NULL;
			Stud_Admn[Count]=NULL;
			Stud_Name_Self[Count]=NULL;
			Stud_Name_Father[Count]=NULL;
			Stud_Name_Mother[Count]=NULL;
			Stud_DOB[Count]=NULL;
			Stud_Addr[Count]=NULL;
			Stud_School[Count]=NULL;
			Stud_Phone[Count]=NULL;
			Stud_Caste[Count]=NULL;
			Stud_Stream[Count]=NULL;
			Stud_Stream_Sub[Count]=NULL;
			Stud_Stream_Spc[Count]=NULL;
			Stud_Marks1[Count]=NULL;
			Stud_Marks2[Count]=NULL;
			Stud_Marks3[Count]=NULL;
			Stud_Marks4[Count]=NULL;
			Stud_Marks5[Count]=NULL;
			Stud_ClgID[Count]=NULL;
					 Count++;
					 }
			   }

	      /* ~Student() {
			/*free(Stud_Roll);
			free(Stud_Admn);
			free(Stud_Name_Self);
			free(Stud_Name_Father);
			free(Stud_Name_Mother);
			free(Stud_DOB);
			free(Stud_Addr);
			free(Stud_School);
			free(Stud_Phone);
			free(Stud_Caste);
			free(Stud_Stream);
			free(Stud_Stream_Sub);
			free(Stud_Stream_Spc);
			free(Stud_Marks[0]);
			free(Stud_Marks[1]);
			free(Stud_Marks[2]);
			free(Stud_Marks[3]);
			free(Stud_Marks[4]);
			free(Stud_ClgID);

			}*/
			};


/*
int Record_Write(char* Path,Student S[],int Tol) {

		 fstream File;
		 int Count=0;

		 File.open(Path,ios::out|ios::binary|ios::trunc);
		 if (!File) return -1;
		 File.seekp(0,ios::beg);

		 while (Count<Tol) {
			File.write((char*)&S[Count],sizeof(Student));
			Count++;
				   }
		 File.close();
		 return 1;
						 }

int Record_Read(char* Path) {

		fstream File;
		int Tol=0;

		File.open(Path,ios::in|ios::binary|ios::nocreate);
		if (!File) return -1;
		File.seekg(0,ios::beg);

		while (!File.eof()) {
		       File.read((char*)&S2[Tol],sizeof(Student));
		       Tol++;
				    }
		File.close();
		return Tol;
					 }
/*
void main() {


clrscr();

cout<<"enter 19 values:\n";

cin>>S[0].Stud_Roll; //
cin>>S[0].Stud_Admn;
cin>>S[0].Stud_Name_Self;
cin>>S[0].Stud_Name_Father;
cin>>S[0].Stud_Name_Mother;
cin>>S[0].Stud_DOB;
cin>>S[0].Stud_Addr;
cin>>S[0].Stud_School;
cin>>S[0].Stud_Phone;
cin>>S[0].Stud_Caste;
cin>>S[0].Stud_Stream; //
cout<<S[0].Stud_Stream;
cin>>S[0].Stud_Stream_Sub;
cin>>S[0].Stud_Stream_Spc;
cin>>S[0].Stud_Marks[0];
cin>>S[0].Stud_Marks[1];
cin>>S[0].Stud_Marks[2];
cin>>S[0].Stud_Marks[3];
cin>>S[0].Stud_Marks[4];
cin>>S[0].Stud_ClgID;

cout<<"\nenter to write:";
getch();
cout<<Record_Write("c:\\test2.txt",1);
cout<<"\nenter to read:";
getch();
int Res=Record_Read("c:\\test2.txt");
cout<<Res;
if (Res==-1) {
					  cout<<"\nerror\n";
					  getch();
					  exit(1);
					 }

cout<<S2[0].Stud_Roll<<"\n";
cout<<S2[0].Stud_Admn<<"\n";
cout<<S2[0].Stud_Name_Self<<"\n";
cout<<S2[0].Stud_Name_Father<<"\n";
cout<<S2[0].Stud_Name_Mother<<"\n";
cout<<S2[0].Stud_DOB<<"\n";
cout<<S2[0].Stud_Addr<<"\n";
cout<<S2[0].Stud_School<<"\n";
cout<<S2[0].Stud_Phone<<"\n";
cout<<S2[0].Stud_Caste<<"\n";
cout<<S2[0].Stud_Stream<<"\n";
cout<<S2[0].Stud_Stream_Sub<<"\n";
cout<<S2[0].Stud_Stream_Spc<<"\n";
cout<<S2[0].Stud_Marks[0]<<"\n";
cout<<S2[0].Stud_Marks[1]<<"\n";
cout<<S2[0].Stud_Marks[2]<<"\n";
cout<<S2[0].Stud_Marks[3]<<"\n";
cout<<S2[0].Stud_Marks[4]<<"\n";
cout<<S2[0].Stud_ClgID<<"\n";

getch();
}
*/