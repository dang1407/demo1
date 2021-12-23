#include<bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node* leftMostchild;
    Node* rightSibling;
};

Node* makeNode(int x) {
    Node* p = new Node;
    p->key = x;
    p->leftMostchild = NULL;
    p->rightSibling = NULL;
    return p;
}

void preOder(Node* r) {
    // thứ tự trước
    if(r==NULL) return;
    cout << r->key << " ";
    Node* p = r->leftMostchild;
    while(p!=NULL) {
        preOder(p);
        p=p->rightSibling;
    }
}

void inOrder(Node* r) {
    if(r == NULL) return;
    Node* p = r->leftMostchild;
    inOrder(p);
    printf("%d ",r->key);
    if(p != NULL)
        p = p->rightSibling;
    while(p != NULL) {
        inOrder(p);
        p = p->rightSibling;
    }
}


Node* findNode(Node* r, int k) {
    if(r->key == k) return r;
    Node* p = r->leftMostchild;
    while(p!=NULL) {
        Node* h = findNode(p,k);
        if(h!=NULL) return h;
        p=p->rightSibling;
    }
    return NULL;
}

Node* addLeft(Node* r, Node* p, int x) {
    Node* q = makeNode(x);
    if(r==NULL) return q;
    p->leftMostchild = q;
    return r;
}
Node* addRight(Node* r, Node* p, int x) {
    Node* q = makeNode(x);
    if(r==NULL) return q;
    if(p->leftMostchild!=NULL)
        p->leftMostchild->rightSibling = q;
    else r = addLeft(r,p,x);
    return r;
}
int main() {
    int a[100],n=5,i,x;
    Node *r = NULL, *p, *q;
//   srand((int) time(0));
//   n = rand()%4 +5;
//   for(i=1;i<=n;i++){
//    a[i] = 1 + rand()%9;
//   }
//   cout << "So phan tu la: " << n << endl;
//   cout << "Mang tao duoc la: ";
//   for(i=1;i<=n;i++){
//    cout << a[i] << " ";
//   }
// r = makeNode(1);
//   for(i =1; i <=n;i++){
//    x = rand()%2;
//    if(i%2==0)
//    Node* p = findNode(r, i/2);
//    else Node* p = findNode(r,(i-1)/2);
//    if(x==1) r = addLeft(r,p,i);
//    else r = addRight(r,p,i);
//   }
    for(i=1; i<=5; i++) {
        if(r==NULL) {
            r = makeNode(i);
            continue;
        }
        if(i%2==0) {
            Node* p =findNode(r,i/2);
            if(p!=NULL) r = addLeft(r,p,i);
            else r = addLeft(r,r,i);
        } else {
            Node* p =findNode(r,(i-1)/2);
            if(p!=NULL) r = addRight(r,p,i);
            else r = addRight(r,r,i);
        }
    }
    inOrder(r);

}
