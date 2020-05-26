#include "Header.h"



int menu() {
    int key = 0;
    int code;
    do {
        system( "cls" );
        key = ( key + 7 ) % 7;
        if ( key == 0 ) cout<<"-> Linked List"<<endl;
            else  cout<<"   Linked List"<<endl;
        if ( key == 1 ) cout<<"-> Array List"<<endl;
            else  cout<<"   Array List"<<endl;
        if ( key == 2 ) cout<<"-> Bin Tree"<<endl;
            else  cout<<"   Bin Tree"<<endl;
        if ( key == 3 ) cout<<"-> ABL-Tree"<<endl;
            else  cout<<"   ABL-Tree"<<endl;
        if ( key == 4 ) cout<<"-> 2-3 Tree"<<endl;
            else  cout<<"   2-3 Tree"<<endl;
        if ( key == 5 ) cout<<"-> Demonstration"<<endl;
            else  cout<<"   Demonstration"<<endl;
        if ( key == 6 ) cout<<"-> Benchmark"<<endl;
            else  cout<<"   Benchmark"<<endl;
        code = _getch();
        if ( code == 224 ){
            code = _getch();
            if ( code == 80 ) key ++;
            if ( code == 72 ) key --;
        }
        if ( code == 27 ){
            system( "cls" );
            exit(0);
        }
    }while( code != 13 );
    system( "cls" );
    return key;
}


int menu_2() {
    int key = 0;
    int code;
    do {
        system( "cls" );
        key = ( key + 5 ) % 5;
        cout << "Type:\n";
        if ( key == 0 ) cout<<"-> add_elem"<<endl;
            else  cout<<"   add_elem"<<endl;
        if ( key == 1 ) cout<<"-> write"<<endl;
            else  cout<<"   write"<<endl;
        if ( key == 2 ) cout<<"-> delete"<<endl;
            else  cout<<"   delete"<<endl;
        if ( key == 3 ) cout<<"-> search by value"<<endl;
            else  cout<<"   search by value"<<endl;
        if ( key == 4 ) cout<<"-> range search"<<endl;
            else  cout<<"   range search"<<endl;
        code = _getch();
        if ( code == 224 ){
            code = _getch();
            if ( code == 80 ) key ++;
            if ( code == 72 ) key --;
        }
        if ( code == 27 ){
            system( "cls" );
            exit(0);
        }
    }while( code != 13 );
    system( "cls" );
    return key;
}


