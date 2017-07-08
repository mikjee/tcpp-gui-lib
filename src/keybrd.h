char KC_To_Char(long KC) {
			  switch(KC) {

			  case 7777: return 'a';
			  case 12386: return 'b';
			  case 11875: return 'c';
			  case 8292: return 'd';
			  case 4709: return 'e';
			  case 8550: return 'f';
			  case 8807: return 'g';
			  case 9064: return 'h';
			  case 5993: return 'i';
			  case 9322: return 'j';
			  case 9579: return 'k';
			  case 9836: return 'l';
			  case 12909: return 'm';
			  case 12654: return 'n';
			  case 6255: return 'o';
			  case 6512: return 'p';
			  case 4209: return 'q';
			  case 4978: return 'r';
			  case 8051: return 's';
			  case 5236: return 't';
			  case 5749: return 'u';
			  case 12150: return 'v';
			  case 4471: return 'w';
			  case 11640: return 'x';
			  case 5497: return 'y';
			  case 11386: return 'z';
			  case 7777-32: return 'A';
			  case 12386-32: return 'B';
			  case 11875-32: return 'C';
			  case 8292-32: return 'D';
			  case 4709-32: return 'E';
			  case 8550-32: return 'F';
			  case 8807-32: return 'G';
			  case 9064-32: return 'H';
			  case 5993-32: return 'I';
			  case 9322-32: return 'J';
			  case 9579-32: return 'K';
			  case 9836-32: return 'L';
			  case 12909-32: return 'M';
			  case 12654-32: return 'N';
			  case 6255-32: return 'O';
			  case 6512-32: return 'P';
			  case 4209-32: return 'Q';
			  case 4978-32: return 'R';
			  case 8051-32: return 'S';
			  case 5236-32: return 'T';
			  case 5749-32: return 'U';
			  case 12150-32: return 'V';
			  case 4471-32: return 'W';
			  case 11640-32: return 'X';
			  case 5497-32: return 'Y';
			  case 11386-32: return 'Z';
			  case 561: return '1';
			  case 818: return '2';
			  case 1075: return '3';
			  case 1332: return '4';
			  case 1589: return '5';
			  case 1846: return '6';
			  case 2103: return '7';
			  case 2360: return '8';
			  case 2617: return '9';
			  case 2864: return '0';
			  case 3167: return '_';
			  case 3117: return '-';
			  case 13615: return '/';
			  case 11100: return '\\';
			  case 10042: return ':';
			  case 13358: return '.';
			  case 13100: return ',';
			  default : return ' ';
			   }
			  }

char* strextr(char* &Extr_Line) {

	     char* Extr_Word;
	     char* Extr_Line2;

	     int Pos=strlen(Extr_Line)-strlen(strstr(Extr_Line," "));

	     Extr_Line2=(char *) calloc(strlen(Extr_Line)-Pos+1, sizeof(char));
	     Extr_Word=(char *) calloc(Pos+1, sizeof(char));

	     if (strstr(Extr_Line," ")==NULL) {
					       strcpy(Extr_Word,Extr_Line);
					       Extr_Line="";
					       return Extr_Word;
					      }

	     strncpy(Extr_Word,Extr_Line,Pos);
	     Extr_Line=strrev(Extr_Line);
	     strncpy(Extr_Line2,Extr_Line,strlen(Extr_Line)-Pos-1);
	     Extr_Line=strrev(Extr_Line2);

	     return Extr_Word;
			      }





