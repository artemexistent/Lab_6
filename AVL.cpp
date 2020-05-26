
#include "Header.h"

int height(AVL_Tree * p){
        return p?p->h:0;
    }
int bfactor(AVL_Tree * p){
        return height(p->r)-height(p->l);
    }
void fixh(AVL_Tree * p){
    int hl=height(p->l);
    int hr=height(p->r);
    p->h=(hl>hr?hl:hr)+1;
}

AVL_Tree * rotateright(AVL_Tree*p){
        AVL_Tree * q=p->l;
        p->l=q->r;
        q->r=p;
        fixh(p);
        fixh(q);
        return q;
}

AVL_Tree * rotateleft(AVL_Tree*q){
        AVL_Tree * p=q->l;
        q->r=p->l;
        p->l=q;
        fixh(q);
        fixh(p);
        return p;
}

AVL_Tree * balance(AVL_Tree*p){
    fixh(p);
    if (bfactor(p)==2){
        if (bfactor(p->r)<0)
            p->r=rotateright(p->r);
        return rotateleft(p);
    }
    if (bfactor(p)==-2){
        if (bfactor(p->l)>0)
            p->l=rotateleft(p->l);
        return rotateright(p);
    }
    return p;
}

AVL_Tree * insert( AVL_Tree* p, Point k){
    if (!p) return new AVL_Tree(k);
    if (check(k,p->key))
        p->l=insert(p->l,k);
    else p->r=insert(p->r,k);
    return balance(p);
}

AVL_Tree *findmin(AVL_Tree*p){
    return p->l?findmin(p->l):p;
}

AVL_Tree *removemin(AVL_Tree*p){
    if (p->l==0)
        return p->r;
    p->l = removemin(p->l);
    return balance(p);
}

AVL_Tree *remove(AVL_Tree*p,Point k){
    if (!p) return 0;
    if (!check(k,p->key))
        p->l=remove(p->l,k);
    else if (check_2(p->key,k))
    {

            AVL_Tree* q=p->l;
            AVL_Tree* w =p->r;
            delete p;
            if (!w) return q;
            AVL_Tree * min=findmin(w);
            min->r=removemin(w);
            min->l=q;
            return balance(min);
        }else p->r=remove(p->r,k);
        return balance(p);
}

void write_AVL(AVL_Tree*p){
    if (!p){ cout << "( " << p->key.x << ", " << p->key.y << ", " << p->key.z << " ) "; return;}
    if (p->r!=NULL)
        write_AVL(p->r);
     cout << "( " << p->key.x << ", " << p->key.y << ", " << p->key.z << " ) ";
     if (p->l!=NULL)
        write_AVL(p->l);
}


void search_avl_1(AVL_Tree*curr,Point k){

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
                cout << "Hight:" << curr->h << "    " << "( " << curr->key.x << ", " << curr->key.y << ", " << curr->key.z << " ) \n";
            }else cout << "This point doesn't exist\n";
}



void search_avl_2(AVL_Tree*curr,Point l, Point r){
           bool f=true;
            while (true){
                if ( check_3(curr->key,l,r) ){
                    cout << "Hight:" << curr->h << "    " << "( " << curr->key.x << ", " << curr->key.y << ", " << curr->key.z << " ) \n";
                    f=true;
                    if (curr->r!=0)
                        search_avl_2(curr->r,l,r);
                    if (curr->l!=0)
                       search_avl_2(curr->l,l,r);
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
