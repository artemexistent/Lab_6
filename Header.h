#pragma once
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <fstream>

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
                }else return;
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


struct TT_Tree {

    Point key[3];
private:
    int size;      // ���������� ������� ������
    TT_Tree *first;   // *first <= key[0];
    TT_Tree *second;  // key[0] <= *second < key[1];
    TT_Tree *third;   // key[1] <= *third < key[2];
    TT_Tree *fourth;  // kye[2] <= *fourth.
    TT_Tree *parent; //��������� �� �������� ����� ��� ����, ������ ��� ����� ����� ����� �������� ��� ��������

    bool find(Point k) { // ���� ����� ���������� true, ���� ���� k ��������� � �������, ����� false.
        for (int i = 0; i < size; ++i)
            if (check_2(key[i],k)) return true;
        return false;
    }

    bool find_2(Point l,Point r) { // ���� ����� ���������� true, ���� ���� k ��������� � �������, ����� false.
        for (int i = 0; i < size; ++i)
            if (check_3(key[i],l,r)) return true;
        return false;
    }

    void swap(Point &x, Point &y) {
        Point r = x;
        x = y;
        y = r;
    }

    void sort2(Point &x, Point &y) {
        if (check(x,y)) swap(x, y);
    }

    void sort3(Point &x, Point &y, Point &z) {
        if (check(x,y)) swap(x, y);
        if (check(x,z)) swap(x, z);
        if (check(y,z)) swap(y, z);
    }

    void sort() { // ����� � �������� ������ ���� �������������
        if (size == 1) return;
        if (size == 2) sort2(key[0], key[1]);
        if (size == 3) sort3(key[0], key[1], key[2]);
    }

    void insert_to_TT_Tree(Point k) {  // ��������� ���� k � ������� (�� � ������)
        key[size] = k;
        size++;
        sort();
    }

    void remove_from_TT_Tree(Point k) { // ������� ���� k �� ������� (�� �� ������)
        if (size >= 1 && check_2(key[0], k) ) {
            key[0] = key[1];
            key[1] = key[2];
            size--;
        } else if (size == 2 && check_2(key[1], k)) {
            key[1] = key[2];
            size--;
        }
    }

    void become_TT_Tree2(Point k, TT_Tree *first_, TT_Tree *second_) {  // ������������� � 2-�������.
        key[0] = k;
        first = first_;
        second = second_;
        third = nullptr;
        fourth = nullptr;
        parent = nullptr;
        size = 1;
    }

    bool is_leaf() { // �������� �� ���� ������; �������� ������������ ��� ������� � ��������.
        return (first == nullptr) && (second == nullptr) && (third == nullptr);
    }

public:
    // ��������� ������ ����� ������� ������ � ����� ������
    TT_Tree(Point k): size(1), key{k, 0, 0}, first(nullptr), second(nullptr),
                 third(nullptr), fourth(nullptr), parent(nullptr) {}

    TT_Tree (Point k, TT_Tree *first_, TT_Tree *second_, TT_Tree *third_, TT_Tree *fourth_, TT_Tree *parent_):
                            size(1), key{k, 0, 0}, first(first_), second(second_),
                            third(third_), fourth(fourth_), parent(parent_) {}

    friend TT_Tree *split(TT_Tree *item); // ����� ��� ���������� ������� ��� ������������;
    friend TT_Tree *insert(TT_Tree *p, Point k); // ������� � ������;
    friend TT_Tree *search(TT_Tree *p, Point k); // ����� � ������;
    friend TT_Tree *search_2(TT_Tree *p, Point l, Point r);
    friend TT_Tree *search_min(TT_Tree *p); // ����� ������������ �������� � ���������;
    friend TT_Tree *merge(TT_Tree *leaf); // ������� ������������ ��� ��������;
    friend TT_Tree *redistribute(TT_Tree *leaf); // ����������������� ����� ������������ ��� ��������;
    friend TT_Tree *fix(TT_Tree *leaf); // ������������ ����� �������� ��� ����������� ������� ������ (���������� merge ��� redistribute)
    friend TT_Tree *remove(TT_Tree *p, Point k); // ����������, �� �������� �������;
    friend void write_tt(TT_Tree* p);
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
void Add(List *& L,Array_List &AL,BinTree * & BT,AVL_Tree * &AT,TT_Tree * &TT,int type);
void Write(List* & L,Array_List &AL,BinTree * & BT,AVL_Tree * &AT,TT_Tree * &TT,int type);
void Delet(List* & L,Array_List &AL,BinTree * & BT,AVL_Tree * &AT,TT_Tree * &TT,int type);
void Search_1(List* & L,Array_List &AL,BinTree * & BT,AVL_Tree * &AT,TT_Tree * &TT,int type);
void Search_2(List* & L,Array_List &AL,BinTree * & BT,AVL_Tree * &AT,TT_Tree *&TT,int type);
int menu();
int menu_2();
void Demo();
void Bench();
