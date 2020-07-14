#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
using namespace std;

const int MAX = 100;

char err_mess[] = "\nBlad wywolania programu!\n"
                  "\nPodaj parametry:\n1.[s|t]\n"
				  "2.Nazwa pliku do szyfrowania/deszyfrowania\n"
				  "3.Nazwa pliku do odszyfrowania/zaszyfrowania\n"
				  "4.Jednoznakowy klucz";

void dzialanieNaPliku(char st, string fileIn, string fileOut, char k){
	bool isS = (st=='s') ? true : false;
	int a = 0;
	string nd[MAX];
	string data;
	fstream plik;
	plik.open(fileIn, ios::in);
	while( !plik.eof()) {
		getline(plik,data);
		nd[a] = data;
		++a;
		}
		plik.close();
		plik.open(fileOut, ios::out );
		for( int i = 0; i < a; ++i ){
			for( int d = 0; d < nd[ i ].size(); ++d){
			    if(isS) plik << char(nd[i][d]+k);
				else plik << char(nd[i][d]-k);
			}
			plik << endl;
		}
		plik.close();
}
int main( int argc, char * args[] ) {
  	puts( "\n" );
  	if( --argc == 0 ) puts( err_mess );
  	else if( strlen( args[4] ) == 1 && (args[4] != NULL)  && args[3] != NULL && args[2] != NULL && strlen( args[1] ) == 1 && ((tolower(args[1][0])=='s')||tolower(args[1][0])=='t')){
		printf( "\nTryb:  %s", args[1] );
		printf( "\nNazwa pliku pierwszego:  %s", args[ 2 ] );
		printf( "\nZapis danych do pliku:  %s", args[ 3 ] );
		printf( "\nJednoznakowy klucz: %s", args[ 4 ] );
		dzialanieNaPliku(args[1][0],args[2],args[3],args[4][0]);
	}
    return EXIT_SUCCESS;
}

