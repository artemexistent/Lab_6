#pragma once
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include <vector>


using namespace std;

struct Point{
    int x,y,z;
};
bool check(Point L, Point k);
bool check_2(Point L, Point k);
bool check_3(Point L, Point l, Point r);

struct List{
    Point key;
    List * next;

    List(){
        key.x=0;
        key.y=0;
        key.z=0;
        this->next=0;
    }

    void add_elem(Point k){
        List * curr=this;

        while (curr->next!=0){
            if ( check(curr->next->key,k) )
                break;
            curr=curr->next;
        }
        List* w = new List();
        w->key=k;
        w->next = curr->next;
        curr->next = w;
    }

    void del_elem(int numb){
            List * curr=this;
            int i=1;
            while (curr->next!=0){
                if ( i==numb )
                    break;
                curr=curr->next;
                i++;
            }
            if (curr->next->next!=0)
                curr->next=curr->next->next;
            else curr->next = 0;
        }
    void write_elem(){
        List * curr = this->next;
        while (curr->next!=0){
            cout << "( " << curr->key.x << ", " << curr->key.y << ", " << curr->key.z << " ) ";
            curr = curr->next;
        }
        cout << "( " << curr->key.x << ", " << curr->key.y << ", " << curr->key.z << " ) ";
    }

    void search_1(Point k){
            List * curr=this;
            int i=1;
            while (curr->next!=0){
                if ( check_2(curr->next->key,k) )
                    break;
                 curr = curr->next;
                 i++;
            }
            if (curr->next!=0){
                curr = curr->next;
                cout << "Number:" << i << "    " << "( " << curr->key.x << ", " << curr->key.y << ", " << curr->key.z << " ) \n";
            }else cout << "This point doesn't exist\n";
    }


    void search_2(Point l, Point r){
            List * curr=this;
            int i=1;
            bool f=true;
            while (curr->next!=0){
                if ( check_3(curr->next->key,l,r) ){
                    cout << "Number:" << i << "    " << "( " << curr->next->key.x << ", " << curr->next->key.y << ", " << curr->next->key.z << " ) \n";
                    f=false;
                }
                 curr = curr->next;
                 i++;
            }
            if (f)
               cout << "This point doesn't exist\n";
    }

};


struct Array_List{

    vector <Point> AL;

    Array_List(){
    }

    void add_elem(Point k){
        Point t;
        t.x=t.y=t.z=INT_MAX;
        AL.push_back(t);
        for (int i=0;i<AL.size();i++){
            if (check(AL[i],k) ){
                for (int j=AL.size()-1;j>i;j--)
                    AL[j]=AL[j-1];
                AL[i]=k;
                break;
            }
        }
    }

    void del_elem(int numb){
        AL.erase(AL.begin()+numb-1);
    }
    void write_elem(){
        for (int i=0;i<AL.size();i++)
         cout << "( " << AL[i].x << ", " << AL[i].y << ", " << AL[i].z << " ) ";
    }

    void search_1(Point k){
            bool f=true;
            for (int i=0;i<AL.size();i++)
                if (check_2(AL[i],k)){
                     cout << "Number:" << i+1 << "    " << "( " << AL[i].x << ", " << AL[i].y << ", " << AL[i].z << " ) \n";
                    f=false;
                }
            if (f)
                cout << "This point doesn't exist\n";
    }


    void search_2(Point l, Point r){
            bool f=true;
            for (int i=0;i<AL.size();i++)
                if (check_3(AL[i],l,r)){
                     cout << "Number:" << i+1 << "    " << "( " << AL[i].x << ", " << AL[i].y << ", " << AL[i].z << " ) \n";
                    f=false;
                }
            if (f)
               cout << "This point doesn't exist\n";
    }

};

struct BinTree{
	Point key;
	int numb;
	BinTree * l;
	BinTree * r;
	BinTree(){
	    Point t;
        t.x=t.y=t.z=INT_MAX;
        this->key=t;
        this->l=0;
        this->r=0;
        this->numb=INT_MAX;
	}
	void add_elem(Point k){
		BinTree * curr=this;
		if (curr->l == 0 && curr->r == 0){
                curr->l= new BinTree();
                curr->l->key=k;
                return;
        }
        curr=curr->l;
		while (true){
            if ( !check(curr->key,k) ){
                if (curr->r==0){
                    curr->r=new BinTree();
                    curr->r->key=k;
                    break;
                }else curr=curr->r;
            }else {
                if (curr->l==0){
                    curr->l=new BinTree();
                    curr->l->key=k;
                    break;
                }else curr=curr->l;
            }
		}
	}

	void write_elem(int &num){
	    BinTree * curr= this;
        if (curr->l!=0)
            curr->l->write_elem(num);
        cout << "( " << curr->key.x << ", " << curr->key.y << ", " << curr->key.z << " ) ";
        curr->numb=(num);
        num++;
        if (curr->r!=0)
            curr->r->write_elem(num);
    }

    void find_elem(vector <Point> & point){

       if (this->l!=0){
          point.push_back(this->l->key);
          this->l->find_elem(point);
       }
       if (this->r!=0){
          point.push_back(this->r->key);
          this->r->find_elem(point);
       }

    }


    void del_elem (int num){
         BinTree * curr=this;
        vector <Point> point;
        while (true){
            if (curr->l!=0 && curr->l->numb==num){
                curr->l->find_elem(point);
                curr->l=0;
                break;
            }
            if (curr->r!=0 && curr->r->numb==num){
                curr->r->find_elem(point);
                curr->r=0;
                break;
            }
            if (curr->numb>num){
                curr=curr->l;
            }else curr=curr->r;
        }

        for (int i=0;i<point.size();i++){
            this->add_elem(point[i]);
        }

    }

    void search_1(Point k){
           BinTree * curr=this->l;
            while (true){
                if ( check_2(curr->key,k) )
                    break;
                if ( !check(curr->key,k) ){
                    if (curr->r!=0)
                        curr=curr->r;
                    else break;
                }else {
                    if (curr->l!=0)
                      curr=curr->l;
                    else break;
                }
            }
            if (check_2(curr->key,k)){
                cout << "Number:" << curr->numb << "    " << "( " << curr->key.x << ", " << curr->key.y << ", " << curr->key.z << " ) \n";
            }else cout << "This point doesn't exist\n";
    }


    void search_2(Point l, Point r){
           BinTree * curr=this;
           bool f=true;
            while (true){
                if ( check_3(curr->key,l,r) ){
                    cout << "Number:" << curr->numb << "    " << "( " << curr->key.x << ", " << curr->key.y << ", " << curr->key.z << " ) \n";
                    f=true;
                    if (curr->r!=0)
                        curr->r->search_2(l,r);
                    if (curr->l!=0)
                       curr->l->search_2(l,r);
                    return ;
                }
                if ( !check(curr->key,l) ){
                    if (curr->r!=0)
                        curr=curr->r;
                    else return;
                }else if (check(curr->key,r)){
                    if (curr->l!=0)
                      curr=curr->l;
                    else return;
                }
            }
            if (f)
                cout << "This point doesn't exist\n";
    }

};


struct AVL_Tree{
    Point key;
    int h;
    AVL_Tree *l;
    AVL_Tree *r;
    AVL_Tree(Point k){
        key=k;
        l=NULL;
        r=NULL;
        h=1;
    }

};

int height(AVL_Tree * p);
int bfactor(AVL_Tree * p);
void fixh(AVL_Tree * p);
AVL_Tree * rotateright(AVL_Tree*p);
AVL_Tree * rotateleft(AVL_Tree*q);
AVL_Tree * balance(AVL_Tree*p);
AVL_Tree * insert( AVL_Tree* p, Point k);
AVL_Tree *findmin(AVL_Tree*p);
AVL_Tree *removemin(AVL_Tree*p);
AVL_Tree *remove(AVL_Tree*p,Point k);
void write_AVL(AVL_Tree*p);
void search_avl_1(AVL_Tree*curr,Point k);
void search_avl_2(AVL_Tree*curr,Point l, Point r);

void Add(List *& L,Array_List &AL,BinTree * & BT,AVL_Tree * &AT,int type);
void Write(List* & L,Array_List &AL,BinTree * & BT,AVL_Tree * &AT,int type);
void Delet(List* & L,Array_List &AL,BinTree * & BT,AVL_Tree * &AT,int type);
void Search_1(List* & L,Array_List &AL,BinTree * & BT,AVL_Tree * &AT,int type);
void Search_2(List* & L,Array_List &AL,BinTree * & BT,AVL_Tree * &AT,int type);
int menu();
int menu_2();
