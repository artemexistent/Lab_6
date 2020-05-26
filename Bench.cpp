#include "Header.h"


void Bench(){

    srand(time(0));
    ofstream out("Benchmark.txt");
    int n=rand()%20+5;
    clock_t start,end;
    Point point;

    out << "Points = " << n << "\n\n\n";

    out<< "List:";
    out << "memory  " << sizeof(List) << "\n";
    List *L= new List();
    start = clock();
    for (int i=0;i<n;i++){
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;
       L->add_elem(point);
    }
    end = clock();
    out << "Add   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";
    L->write_elem();
    start = clock();
    for (int i=0;i<n/2;i++){
       L->del_elem(i+1);
    }
    end = clock();
    out << "Del   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";
    start = clock();
    for (int i=0;i<n;i++){
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;
       L->search_1(point);
    }
    end = clock();
    out << "Search1   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";

    start = clock();
    for (int i=0;i<n;i++){
       Point r;
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;
       r=point;
       r.x=r.x+1;
       L->search_2(point,r);
    }
    end = clock();
    out << "Search2   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";

    out<< "Array:";
    out << "memory  " << sizeof(Array_List) << "\n";
    Array_List AL;
    start = clock();
    for (int i=0;i<n;i++){
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;
       AL.add_elem(point);
    }
    end = clock();
    out << "Add   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";
    AL.write_elem();
    start = clock();
    for (int i=0;i<n/2;i++){
       AL.del_elem(n/2-1);
    }
    end = clock();
    out << "Del   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";
    start = clock();
    for (int i=0;i<n;i++){
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;
       AL.search_1(point);
    }
    end = clock();
    out << "Search1   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";

    start = clock();
    for (int i=0;i<n;i++){
       Point r;
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;
       r=point;
       r.x=r.x+1;
       AL.search_2(point,r);
    }
    end = clock();
    out << "Search2   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";



    out<< "BinTree:";
    out << "memory  " << sizeof(BinTree) << "\n";
    BinTree * BT= new BinTree();
    start = clock();
    for (int i=0;i<n;i++){
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;
       BT->add_elem(point);
    }
    end = clock();
    out << "Add   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";
    int num=1;
    BT->l->write_elem(num);
    start = clock();
    for (int i=2;i<n/4;i++){
       BT->del_elem(2);
    }
    end = clock();
    out << "Del   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";
    start = clock();
    for (int i=0;i<n;i++){
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;
       BT->search_1(point);
    }
    end = clock();
    out << "Search1   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";

    start = clock();
    for (int i=0;i<n;i++){
       Point r;
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;
       r=point;
       r.x=r.x+1;
       BT->l->search_2(point,r);
    }
    end = clock();
    out << "Search2   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";






   Point t;
    t.x=t.y=t.z=0;


    out<< "AVL-TREE:";
    out << "memory  " << sizeof(AVL_Tree) << "\n";
    AVL_Tree * AT= new AVL_Tree(t);
    start = clock();
    point.x=point.y=point.z=1;
    AT=insert(AT,point);
    for (int i=0;i<n;i++){
       AT=insert(AT,point);
    }
    end = clock();
    out << "Add   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";
//    int num=1;
    write_AVL(AT);
    start = clock();
    for (int i=2;i<n/4;i++){
       AT=remove(AT,point);
    }
    end = clock();
    out << "Del   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";
    start = clock();
    for (int i=0;i<n;i++){
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;
       search_avl_1(AT,point);
    }
    end = clock();
    out << "Search1   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";

    start = clock();
    for (int i=0;i<n;i++){
       Point r;
       r=point;
       r.x=r.x+1;
       search_avl_2(AT,point,r);
    }
    end = clock();
    out << "Search2   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";


     out<< "2-3-4-TREE:";
    out << "memory  " << sizeof(TT_Tree) << "\n";
    TT_Tree * TT= new TT_Tree(t);
    start = clock();
    point.x=point.y=point.z=1;
    TT=insert(TT,point);
    for (int i=0;i<n;i++){
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;

       TT=insert(TT,point);
    }
    end = clock();
    out << "Add   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";
//    int num=1;
    write_tt(TT);
    start = clock();
    for (int i=2;i<n/4;i++){

       TT=remove(TT,point);
    }
    end = clock();
    out << "Del   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";
    start = clock();
    for (int i=0;i<n;i++){
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;
       TT_Tree * curr = search(TT,point);
    }
    end = clock();
    out << "Search1   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";

    start = clock();
    for (int i=0;i<n;i++){
       point.x=rand()%10; point.y=rand()%10; point.z=rand()%10;

       Point r;
       r=point;
       r.x=r.x+1;
       TT_Tree * curr = search_2(TT,point,r);
    }
    end = clock();
    out << "Search2   time:" << ((double)end-start)/((double)CLOCKS_PER_SEC) << "\n";



    system ("pause");

}
