#include "Header.h"


TT_Tree *insert(TT_Tree *p, Point k) {
    if (!p) return new TT_Tree(k);

    if (p->is_leaf()) p->insert_to_TT_Tree(k);
    else if ( check(k, p->key[0]) || check_2(k, p->key[0])) insert(p->first, k);
    else if ((p->size == 1) || ((p->size == 2) && ( check(k, p->key[1]) || check_2(k, p->key[1])))) insert(p->second, k);
    else insert(p->third, k);

    return split(p);
}


TT_Tree *split(TT_Tree *item) {
    if (item->size < 3) return item;

    TT_Tree *x = new TT_Tree(item->key[0], item->first, item->second, nullptr, nullptr, item->parent);
    TT_Tree *y = new TT_Tree(item->key[2], item->third, item->fourth, nullptr, nullptr, item->parent);
    if (x->first)  x->first->parent = x;
    if (x->second) x->second->parent = x;
    if (y->first)  y->first->parent = y;
    if (y->second) y->second->parent = y;

    if (item->parent) {
        item->parent->insert_to_TT_Tree(item->key[1]);

        if (item->parent->first == item) item->parent->first = nullptr;
        else if (item->parent->second == item) item->parent->second = nullptr;
        else if (item->parent->third == item) item->parent->third = nullptr;

        if (item->parent->first == nullptr) {
            item->parent->fourth = item->parent->third;
            item->parent->third = item->parent->second;
            item->parent->second = y;
            item->parent->first = x;
        } else if (item->parent->second == nullptr) {
            item->parent->fourth = item->parent->third;
            item->parent->third = y;
            item->parent->second = x;
        } else {
            item->parent->fourth = y;
            item->parent->third = x;
        }

        TT_Tree *tmp = item->parent;
        delete item;
        return tmp;
    } else {
        x->parent = item;
        y->parent = item;
        item->become_TT_Tree2(item->key[1], x, y);
        return item;
    }
}


TT_Tree *search(TT_Tree *p, Point k) {
    if (!p) return nullptr;

    if (p->find(k)) return p;
    else if ( check(k,p->key[0]) ) return search(p->first, k);
    else if (((p->size == 2) && check(k,p->key[1]))|| (p->size == 1)) return search(p->second, k);
    else if (p->size == 2) return search(p->third, k);
}

TT_Tree *search_2(TT_Tree *p, Point l, Point r) {
    if (!p) return nullptr;

    if (p->find_2(l,r)) return p;
    else if ( check(r,p->key[0]) ) return search_2(p->first, l,r);
    else if (((p->size == 2) && check(r,p->key[1]))|| (p->size == 1)) return search_2(p->second, l,r);
    else if (p->size == 2) return search_2(p->third, l,r);
}


TT_Tree *search_min(TT_Tree *p) {
    if (!p) return p;
    if (!(p->first)) return p;
    else return search_min(p->first);
}


TT_Tree *remove(TT_Tree *p, Point k) {
    TT_Tree *item = search(p, k);

    if (!item) return p;

    TT_Tree *min = nullptr;
    if (check_2(item->key[0], k)) min = search_min(item->second);
    else min = search_min(item->third);

    if (min) {
        Point &z = (check_2(item->key[0], k) ? item->key[0] : item->key[1]);
        item->swap(z, min->key[0]);
        item = min;
    }

    item->remove_from_TT_Tree(k);
    return fix(item);
}

TT_Tree *fix(TT_Tree *leaf) {
    if (leaf->size == 0 && leaf->parent == nullptr) {
        delete leaf;
        return nullptr;
    }
    if (leaf->size != 0) {
        if (leaf->parent) return fix(leaf->parent);
        else return leaf;
    }

    TT_Tree *parent = leaf->parent;
    if (parent->first->size == 2 || parent->second->size == 2 || parent->size == 2) leaf = redistribute(leaf);
    else if (parent->size == 2 && parent->third->size == 2) leaf = redistribute(leaf);
    else leaf = merge(leaf);

    return fix(leaf);
}

TT_Tree *redistribute(TT_Tree *leaf) {
    TT_Tree *parent = leaf->parent;
    TT_Tree *first = parent->first;
    TT_Tree *second = parent->second;
    TT_Tree *third = parent->third;

    if ((parent->size == 2) && (first->size < 2) && (second->size < 2) && (third->size < 2)) {
        if (first == leaf) {
            parent->first = parent->second;
            parent->second = parent->third;
            parent->third = nullptr;
            parent->first->insert_to_TT_Tree(parent->key[0]);
            parent->first->third = parent->first->second;
            parent->first->second = parent->first->first;

            if (leaf->first != nullptr) parent->first->first = leaf->first;
            else if (leaf->second != nullptr) parent->first->first = leaf->second;

            if (parent->first->first != nullptr) parent->first->first->parent = parent->first;

            parent->remove_from_TT_Tree(parent->key[0]);
            delete first;
        } else if (second == leaf) {
            first->insert_to_TT_Tree(parent->key[0]);
            parent->remove_from_TT_Tree(parent->key[0]);
            if (leaf->first != nullptr) first->third = leaf->first;
            else if (leaf->second != nullptr) first->third = leaf->second;

            if (first->third != nullptr) first->third->parent = first;

            parent->second = parent->third;
            parent->third = nullptr;

            delete second;
        } else if (third == leaf) {
            second->insert_to_TT_Tree(parent->key[1]);
            parent->third = nullptr;
            parent->remove_from_TT_Tree(parent->key[1]);
            if (leaf->first != nullptr) second->third = leaf->first;
            else if (leaf->second != nullptr) second->third = leaf->second;

            if (second->third != nullptr)  second->third->parent = second;

            delete third;
        }
    } else if ((parent->size == 2) && ((first->size == 2) || (second->size == 2) || (third->size == 2))) {
        if (third == leaf) {
            if (leaf->first != nullptr) {
                leaf->second = leaf->first;
                leaf->first = nullptr;
            }

            leaf->insert_to_TT_Tree(parent->key[1]);
            if (second->size == 2) {
                parent->key[1] = second->key[1];
                second->remove_from_TT_Tree(second->key[1]);
                leaf->first = second->third;
                second->third = nullptr;
                if (leaf->first != nullptr) leaf->first->parent = leaf;
            } else if (first->size == 2) {
                parent->key[1] = second->key[0];
                leaf->first = second->second;
                second->second = second->first;
                if (leaf->first != nullptr) leaf->first->parent = leaf;

                second->key[0] = parent->key[0];
                parent->key[0] = first->key[1];
                first->remove_from_TT_Tree(first->key[1]);
                second->first = first->third;
                if (second->first != nullptr) second->first->parent = second;
                first->third = nullptr;
            }
        } else if (second == leaf) {
            if (third->size == 2) {
                if (leaf->first == nullptr) {
                    leaf->first = leaf->second;
                    leaf->second = nullptr;
                }
                second->insert_to_TT_Tree(parent->key[1]);
                parent->key[1] = third->key[0];
                third->remove_from_TT_Tree(third->key[0]);
                second->second = third->first;
                if (second->second != nullptr) second->second->parent = second;
                third->first = third->second;
                third->second = third->third;
                third->third = nullptr;
            } else if (first->size == 2) {
                if (leaf->second == nullptr) {
                    leaf->second = leaf->first;
                    leaf->first = nullptr;
                }
                second->insert_to_TT_Tree(parent->key[0]);
                parent->key[0] = first->key[1];
                first->remove_from_TT_Tree(first->key[1]);
                second->first = first->third;
                if (second->first != nullptr) second->first->parent = second;
                first->third = nullptr;
            }
        } else if (first == leaf) {
            if (leaf->first == nullptr) {
                leaf->first = leaf->second;
                leaf->second = nullptr;
            }
            first->insert_to_TT_Tree(parent->key[0]);
            if (second->size == 2) {
                parent->key[0] = second->key[0];
                second->remove_from_TT_Tree(second->key[0]);
                first->second = second->first;
                if (first->second != nullptr) first->second->parent = first;
                second->first = second->second;
                second->second = second->third;
                second->third = nullptr;
            } else if (third->size == 2) {
                parent->key[0] = second->key[0];
                second->key[0] = parent->key[1];
                parent->key[1] = third->key[0];
                third->remove_from_TT_Tree(third->key[0]);
                first->second = second->first;
                if (first->second != nullptr) first->second->parent = first;
                second->first = second->second;
                second->second = third->first;
                if (second->second != nullptr) second->second->parent = second;
                third->first = third->second;
                third->second = third->third;
                third->third = nullptr;
            }
        }
    } else if (parent->size == 1) {
        leaf->insert_to_TT_Tree(parent->key[0]);

        if (first == leaf && second->size == 2) {
            parent->key[0] = second->key[0];
            second->remove_from_TT_Tree(second->key[0]);

            if (leaf->first == nullptr) leaf->first = leaf->second;

            leaf->second = second->first;
            second->first = second->second;
            second->second = second->third;
            second->third = nullptr;
            if (leaf->second != nullptr) leaf->second->parent = leaf;
        } else if (second == leaf && first->size == 2) {
            parent->key[0] = first->key[1];
            first->remove_from_TT_Tree(first->key[1]);

            if (leaf->second == nullptr) leaf->second = leaf->first;

            leaf->first = first->third;
            first->third = nullptr;
            if (leaf->first != nullptr) leaf->first->parent = leaf;
        }
    }
    return parent;
}


TT_Tree *merge(TT_Tree *leaf) {
    TT_Tree *parent = leaf->parent;

    if (parent->first == leaf) {
        parent->second->insert_to_TT_Tree(parent->key[0]);
        parent->second->third = parent->second->second;
        parent->second->second = parent->second->first;

        if (leaf->first != nullptr) parent->second->first = leaf->first;
        else if (leaf->second != nullptr) parent->second->first = leaf->second;

        if (parent->second->first != nullptr) parent->second->first->parent = parent->second;

        parent->remove_from_TT_Tree(parent->key[0]);
        delete parent->first;
        parent->first = nullptr;
    } else if (parent->second == leaf) {
        parent->first->insert_to_TT_Tree(parent->key[0]);

        if (leaf->first != nullptr) parent->first->third = leaf->first;
        else if (leaf->second != nullptr) parent->first->third = leaf->second;

        if (parent->first->third != nullptr) parent->first->third->parent = parent->first;

        parent->remove_from_TT_Tree(parent->key[0]);
        delete parent->second;
        parent->second = nullptr;
    }

    if (parent->parent == nullptr) {
        TT_Tree *tmp = nullptr;
        if (parent->first != nullptr) tmp = parent->first;
        else tmp = parent->second;
        tmp->parent = nullptr;
        delete parent;
        return tmp;
    }
    return parent;
}




void write_tt(TT_Tree* p){

    if ((p->first)!=0) write_tt(p->first);
    if (p->size == 3)
    cout <<  "( " << p->key[0].x << ", " << p->key[0].y << ", " << p->key[0].z << " ) \n";
    if (p->second!=0) write_tt(p->second);
    cout <<  "( " << p->key[1].x << ", " << p->key[1].y << ", " << p->key[1].z << " ) \n";
    if (p->first!=0) write_tt(p->first);
    if (p->size>1)
    cout <<  "( " << p->key[2].x << ", " << p->key[2].y << ", " << p->key[2].z << " ) \n";

}
