#include "Header.h"

int main()
{
    int answer = menu();
    List *L= new List();
    Array_List AL;
    BinTree * BT= new BinTree();
    Point t;
    t.x=t.y=t.z=0;
    AVL_Tree * AT= new AVL_Tree(t);
 /*   if (answer==5){
        Demo();
        system ("pause");
        return;
    }
    if (answer==6){
        Bench();
        system ("pause");
        return;
    }*/

    while (true){
        int answer_2=menu_2();
        Point point;
        switch(answer_2){
            case 0: Add(L,AL,BT,AT,answer); break;
            case 1: Write(L,AL,BT,AT,answer); break;
            case 2: Delet(L,AL,BT,AT,answer); break;
            case 3: Search_1(L,AL,BT,AT,answer); break;
            case 4: Search_2(L,AL,BT,AT,answer); break;
        }
        system ("pause");
    }
}
