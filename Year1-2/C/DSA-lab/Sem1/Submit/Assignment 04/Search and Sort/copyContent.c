#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<stdlib.h>
#include<ctype.h>
#include<fstream.h>

void main( )
{
	ofstream outfile;
	ifstream  infile;
	string fname1 , fname2;

	char ch,uch;
	fname1 = "from.txt";
	fname2 = "sort.txt";
	infile.open(fname1);

if( infile.fail( ) )
	{
		cerr<< " No such a file Exit";
		getch();
		exit(1);
	}
	outfile.open( fname2);
		if(outfile.fail( ))
		{
			cerr<<"Unable to create a file";
			getch();
			exit(1);
		}
	while( !infile.eof( ) )
	{
		ch = (char) infile.get( );
		uch = toupper(ch);
		outfile.put(uch);
	}
	infile.close( );
	outfile.close( );
	getch( );
}
