//#include<iostream>
//
//using namespace std;
//
//int a[100], n=4;
//
//void display() {
//    for(int i=1; i<=n; i++) {
//        cout << a[i];
//    }
//    cout << endl;
//}
//
//int TRY(int k) {
//    for(int v=0; v<=1; v++) {
//        a[k]=v;
//        if(k==n) display();
//        else TRY(k+1);
//    }
//}
//
//int main() {
//    TRY(1);
//}
//
//// Liệt kê số chỉnh hợp chập k của n
//#include<stdio.h>
//#include<math.h>
//int a[100]= {},n,k;
//void xuat(int a[],int k) {
//    for (int i=0; i<k; i++) printf("%d ",a[i]);
//    printf("\n");
//}
//int kiemtra(int i,int x) {
//    for (int j=0; j<i; j++) {
//        if (a[j]==x) return 0;
//    }
//    return 1;
//}
//void try1(int i) {
//    for (int x=1; x<=n; x++) {
//        if (kiemtra(i,x)==1) {
//            a[i]=x;
//            if (i==k-1) {
//                xuat(a,k);
//            } else try1(i+1);
//        }
//        a[i]=0;
//    }
//}
//int main() {
//    scanf("%d%d",&k,&n);
//    try1(0);
//    return 0;
//}

#include<iostream>
//#include<stdlib.h>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* makeNode(int x) {
    Node *p= new Node;
    p->value =x;
    p->next = NULL;
    return p;
}

Node *insertAfter(Node *h, Node *p, int x) {
    if(p==NULL) return h;
    Node *q = makeNode(x);
    if(h==NULL) return q;
    q->next = p->next;
    p->next = q;
    return h;
}

void printList(Node *h) {
    Node *p = h;
    while(p!=NULL) {
        printf("%d ", p->value);
        p=p->next;
    }
}

Node* finLast(Node* h) {
    Node *p=h;
    while(p!=NULL) {
        if(p->next == NULL) return p;
        p=p->next;
    }
    return NULL;
}
int main() {
    Node *head;
    head = makeNode(100);
    printList(head);
    insertAfter(head, head, 30);
    cout << endl;
    printList(head);
}
