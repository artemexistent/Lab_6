#include "Header.h"

void Demo(){

    system ("cls");
    Point point;
    cout << "List:\n";\
    List *L= new List();
    cout << "Add point(2,3,5)\n";
    point.x=2; point.y=3; point.z=5;
    L->add_elem(point);
    Sleep(3000);
    cout << "Add point(1,1,1)\n";
    point.x=1; point.y=1; point.z=1;
    L->add_elem(point);
    Sleep(3000);
    cout << "Add point(1,2,5)\n";
    point.x=1; point.y=2; point.z=5;
    L->add_elem(point);
    Sleep(3000);
    cout << "Write List\n";
    L->write_elem();
    Sleep(3000);
    cout << "\nDelete point(1,2,5) number 2\n";
    int num= 2;
    L->del_elem(num);
    Sleep(3000);
    cout << "Write List\n";
    L->write_elem();
    Sleep(3000);
    cout << "\nSearch point(1,2,5)\n";
    L->search_1(point);
    Sleep(3000);
    cout << "Search point(1,1,1)\n";
    point.x=1; point.y=1; point.z=1;
    L->search_1(point);
    Point l,r;
    Sleep(3000);
    cout << "Search point in (0,1,0) and (2,2,2)\n";
    l.x=0; l.y=1; l.z=0; r.x=2; r.y=2; r.z=2;
    L->search_2(l,r);
    system ("pause");


    system ("cls");
    cout << "Array:\n";
    Array_List AL;
    cout << "Add point(2,3,5)\n";
    point.x=2; point.y=3; point.z=5;
    AL.add_elem(point);
    Sleep(3000);
    cout << "Add point(1,1,1)\n";
    point.x=1; point.y=1; point.z=1;
    AL.add_elem(point);
    Sleep(3000);
    cout << "Add point(1,2,5)\n";
    point.x=1; point.y=2; point.z=5;
    AL.add_elem(point);
    Sleep(3000);
    cout << "Write Array\n";
    AL.write_elem();
    Sleep(3000);
    cout << "\nDelete point(1,2,5) number 2\n";
    num= 2;
    AL.del_elem(num);
    Sleep(3000);
    cout << "Write Array\n";
    AL.write_elem();
    Sleep(3000);
    cout << "\nSearch point(1,2,5)\n";
    AL.search_1(point);
    Sleep(3000);
    cout << "Search point(1,1,1)\n";
    point.x=1; point.y=1; point.z=1;
    AL.search_1(point);
    Sleep(3000);
    cout << "Search point in (0,1,0) and (2,2,2)\n";
    l.x=0; l.y=1; l.z=0; r.x=2; r.y=2; r.z=2;
    AL.search_2(l,r);
    system ("pause");


    system ("cls");
    cout << "BinTree:\n";
    BinTree * BT= new BinTree();
    cout << "Add point(2,3,5)\n";
    point.x=2; point.y=3; point.z=5;
    BT->add_elem(point);
    Sleep(3000);
    cout << "Add point(1,1,1)\n";
    point.x=1; point.y=1; point.z=1;
    BT->add_elem(point);
    Sleep(3000);
    cout << "Add point(1,2,5)\n";
    point.x=1; point.y=2; point.z=5;
    BT->add_elem(point);
    Sleep(3000);
    cout << "Write BinTree\n";
    BT->l->write_elem(num);
    Sleep(3000);
    cout << "\nDelete point(1,2,5) number 2\n";
    num= 2;
    BT->del_elem(num);
    Sleep(3000);
    cout << "Write BinTree\n";
    BT->l->write_elem(num);
    Sleep(3000);
    cout << "\nSearch point(1,2,5)\n";
    BT->search_1(point);
    Sleep(3000);
    cout << "Search point(1,1,1)\n";
    point.x=1; point.y=1; point.z=1;
    BT->search_1(point);
    Sleep(3000);
    cout << "Search point in (0,1,0) and (2,2,2)\n";
    l.x=0; l.y=1; l.z=0; r.x=2; r.y=2; r.z=2;
    BT->l->search_2(l,r);
    system ("pause");

    Point t;
    t.x=t.y=t.z=0;


    system ("cls");
    cout << "AVL-Tree:\n";
    AVL_Tree * AT= new AVL_Tree(t);
    cout << "Add point(1,1,1)\n";
    point.x=1; point.y=1; point.z=1;
    AT=insert(AT,point);
    Sleep(3000);
    cout << "Add point(2,3,5)\n";
    point.x=2; point.y=3; point.z=5;
    AT=insert(AT,point);
    Sleep(3000);
    cout << "Add point(1,2,5)\n";
    point.x=1; point.y=2; point.z=5;
    AT=insert(AT,point);
    Sleep(3000);
    cout << "Write AVL-Tree\n";
    write_AVL(AT);
    Sleep(3000);
    cout << "\nDelete point(1,2,5) number 2\n";
    num= 2;
    AT=remove(AT,point);
    Sleep(3000);
    cout << "Write AVL-Tree\n";
    write_AVL(AT);
    Sleep(3000);
    cout << "\nSearch point(1,2,5)\n";
    search_avl_1(AT,point);
    Sleep(3000);
    cout << "Search point(1,1,1)\n";
    point.x=1; point.y=1; point.z=1;
    search_avl_1(AT,point);
    Sleep(3000);
    cout << "Search point in (0,1,0) and (2,2,2)\n";
    l.x=0; l.y=1; l.z=0; r.x=2; r.y=2; r.z=2;
    search_avl_2(AT,l,r);
    system ("pause");



    system ("cls");
    cout << "2-3-4 - Tree:\n";
    TT_Tree * TT= new TT_Tree(t);
    cout << "Add point(2,3,5)\n";
    point.x=2; point.y=3; point.z=5;
    TT=insert(TT,point);
    Sleep(3000);
    cout << "Add point(1,1,1)\n";
    point.x=1; point.y=1; point.z=1;
    TT=insert(TT,point);
    Sleep(3000);
    cout << "Add point(1,2,5)\n";
    point.x=1; point.y=2; point.z=5;
    TT=insert(TT,point);
    Sleep(3000);
    cout << "Write 2-3-4 - Tree\n";
    write_tt(TT);
    Sleep(3000);
    cout << "\nDelete point(1,2,5) number 2\n";
    num= 2;
    TT=remove(TT,point);
    Sleep(3000);
    cout << "Write 2-3-4 - Tree\n";
    write_tt(TT);
    Sleep(3000);
    cout << "\nSearch point(1,1,1)\n";

    point.x=1; point.y=1; point.z=1;
     TT_Tree * curr = search(TT,point);
            cout << "Block:\n";
            for (int i=0;i<3;i++){
                cout <<  "( " << curr->key[i].x << ", " << curr->key[i].y << ", " << curr->key[i].z << " ) \n";
            }
    Sleep(3000);
    cout << "Search point(1,1,1)\n";
    point.x=1; point.y=1; point.z=1;
    curr = search(TT,point);
            cout << "Block:\n";
            for (int i=0;i<3;i++){
                cout <<  "( " << curr->key[i].x << ", " << curr->key[i].y << ", " << curr->key[i].z << " ) \n";
            }
    Sleep(3000);
    cout << "Search point in (0,1,0) and (2,2,2)\n";
    l.x=0; l.y=1; l.z=0; r.x=2; r.y=2; r.z=2;
    curr = search_2(TT,l,r);
            cout << "Block:\n";
            for (int i=0;i<3;i++){
                cout <<  "( " << curr->key[i].x << ", " << curr->key[i].y << ", " << curr->key[i].z << " ) \n";
            }
    system ("pause");

}
