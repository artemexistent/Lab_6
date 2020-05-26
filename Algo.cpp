
#include "Header.h"

bool check(Point L, Point k){
    if (L.x>k.x)
        return true;
    if (L.x==k.x){
        if (L.y>k.y)
            return true;
        if (L.y==k.y){
            if (L.z>=k.z)
                return true;
        }
    }
    return false;
}

bool check_2(Point L, Point k){
    if (L.x==k.x && k.y==L.y && L.z==k.z)
        return true;
    return false;
}


bool check_3(Point L, Point l, Point r){
    if (L.x>=l.x && l.y<=L.y && L.z>=l.z && L.x<=r.x && r.y>=L.y && L.z<=r.z)
        return true;
    return false;
}



void Add(List* & L,Array_List &AL,BinTree * & BT,AVL_Tree * &AT,TT_Tree *& TT,int type){
    Point point;
    cout << "Enter Point:\n";
    cout << "x="; cin >> point.x;
    cout << "y="; cin >> point.y;
    cout << "z="; cin >> point.z;
    switch(type){
        case 0: L->add_elem(point); break;
        case 1: AL.add_elem(point); break;
        case 2: BT->add_elem(point); break;
        case 3: AT=insert(AT,point); break;
        case 4: TT=insert(TT,point); break;
    }
    Write(L,AL,BT,AT,TT,type);
}



void Write(List* & L,Array_List& AL,BinTree * & BT,AVL_Tree * &AT,TT_Tree * &TT,int type){
    int num=1;
    switch(type){
        case 0: L->write_elem(); break;
        case 1: AL.write_elem(); break;
        case 2: BT->l->write_elem(num); break;
        case 3: write_AVL(AT); break;
        case 4: write_tt(TT); break;
    }

}

void Delet(List* & L,Array_List& AL,BinTree * & BT,AVL_Tree * &AT,TT_Tree *& TT,int type){
    Write(L,AL,BT,AT,TT,type);
    cout << endl;
    if (type<3)
    cout << "Enter the number of the point to be deleted:";
    int numb;
    if (type<3)
    cin >> numb;
    switch(type){
        case 0: L->del_elem(numb); break;
        case 1: AL.del_elem(numb); break;
        case 2: BT->del_elem(numb); break;
        case 3: {
            Point point;
            cout << "Enter point:\n";
            cout << "x="; cin >> point.x;
            cout << "y="; cin >> point.y;
            cout << "z="; cin >> point.z;
            cout << "\n";
            AT=remove(AT,point);
        }; break;
        case 4: {
            Point point;
            cout << "Enter point:\n";
            cout << "x="; cin >> point.x;
            cout << "y="; cin >> point.y;
            cout << "z="; cin >> point.z;
            cout << "\n";
            TT=remove(TT,point);
        }; break;
    }
}

void Search_1(List* & L,Array_List &AL,BinTree * & BT,AVL_Tree * &AT,TT_Tree * &TT,int type){
    Point point;
    cout << "Enter Point:\n";
    cout << "x="; cin >> point.x;
    cout << "y="; cin >> point.y;
    cout << "z="; cin >> point.z;
    switch(type){
        case 0: L->search_1(point); break;
        case 1: AL.search_1(point); break;
        case 2: BT->search_1(point); break;
        case 3: search_avl_1(AT,point); break;
        case 4: {
            TT_Tree * curr = search(TT,point);
            cout << "Block:\n";
            for (int i=0;i<3;i++){
                cout <<  "( " << curr->key[i].x << ", " << curr->key[i].y << ", " << curr->key[i].z << " ) \n";
            }
        } break;
    }
}


void Search_2(List* & L,Array_List& AL,BinTree * & BT,AVL_Tree * &AT,TT_Tree * &TT,int type){
    Point l;
    cout << "Enter Point_1:\n";
    cout << "x="; cin >> l.x;
    cout << "y="; cin >> l.y;
    cout << "z="; cin >> l.z;
    cout << "\n";

    Point r;
    cout << "Enter Point_2:\n";
    cout << "x="; cin >> r.x;
    cout << "y="; cin >> r.y;
    cout << "z="; cin >> r.z;
    cout << "\n";
    switch(type){
        case 0: L->search_2(l,r); break;
        case 1: AL.search_2(l,r); break;
        case 2: BT->l->search_2(l,r); break;
        case 3: search_avl_2(AT,l,r); break;
        case 4: {
            TT_Tree * curr = search_2(TT,l,r);
            cout << "Block:\n";
            for (int i=0;i<3;i++){
                cout <<  "( " << curr->key[i].x << ", " << curr->key[i].y << ", " << curr->key[i].z << " ) \n";
            }
        } break;
    }
}
