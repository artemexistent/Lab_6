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
    TT_Tree * TT= new TT_Tree(t);

    if (answer==5){
        Demo();
        return 0;
    }
   if (answer==6){
        Bench();
        return 0;
    }

    while (true){
        int answer_2=menu_2();
        Point point;
        switch(answer_2){
            case 0: Add(L,AL,BT,AT,TT,answer); break;
            case 1: Write(L,AL,BT,AT,TT,answer); break;
            case 2: Delet(L,AL,BT,AT,TT,answer); break;
            case 3: Search_1(L,AL,BT,AT,TT,answer); break;
            case 4: Search_2(L,AL,BT,AT,TT,answer); break;
        }
        system ("pause");
    }
}
