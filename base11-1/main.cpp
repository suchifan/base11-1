//
//  main.cpp
//  base11-1
//
//  Created by suchao on 6/3/18.
//  Copyright © 2018 cs.nju. All rights reserved.
//

#include <iostream>
using namespace std;


struct node{
    int data;
    node *next;
};

void insert(node *&head, node *&p){
    bool flag = false;
    for(node *tmp = head; tmp!=NULL && !flag; tmp=tmp->next){
        if(tmp->data == p->data){
            flag = true;
        }
    }
    
    if(!flag){
        p->next = head;
        head = p;
    }
    
}



void intersection(node *&h1, node *&h2){
    cout << "intersection: ";
    for(node *p=h1; p != NULL; p=p->next){
        for(node *q=h2; q!=NULL; q=q->next){
            if(p->data == q->data){
                cout << p->data << " ";
                break;
            }
        }
    }
    cout << endl;
}

void uni(node *&h1, node *&h2){
    cout << "union: ";
    for(node *p=h1; p != NULL; p=p->next){
        cout << p->data;
    }
    
    for(node *p=h2; p != NULL; p=p->next){
        bool flag = false;
        for(node *q=h1; q!=NULL; q=q->next){
            if(p->data == q->data){
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << p->data;
    }
    cout << endl;
}

void sub(node *&h1, node *&h2){
    for(node *p=h1; p != NULL; p=p->next){
        bool flag = false;
        for(node *q=h2; q!=NULL; q=q->next){
            if(p->data == q->data){
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << p->data;
    }
    cout << endl;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    
    cout << "input the A set:\n";
    node *head1 = NULL;
    
    int tmp;
    cin >> tmp;
    while(tmp != -1){
        node *p = new node;
        p->data = tmp;
        
        insert(head1,p);
        cin >> tmp;
    }
    
    
    cout << "input the B set:\n";
    node *head2 = NULL;
    cin >> tmp;
    while(tmp != -1){
        node *p = new node;
        p->data = tmp;
        
        insert(head2,p);
        cin >> tmp;
    }
    
    intersection(head1, head2);
    uni(head1, head2);
    cout << "A-B: ";
    sub(head1, head2);
    cout << "B-A: ";
    sub(head2, head1);
    
    
    return 0;
}
