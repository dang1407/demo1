#include <iostream>
using namespace std;

int x[10]={0}, n=3,M=10,a[10]={0,1,2,3};

void display(){
    int i;
 for(i=1;i<=n;i++){
 cout << x[i] << ' ';
 }
 cout << endl;
}
int F(int i){
  int F=0,j;
  if(i==0) return 0;
  for(j=1;j<=i;j++){
    F+=x[i]*a[i];
  }
  return F;
}
int check(){
  int i,f=0;
  for(i=1;i<=n;i++){
    f+=a[i]*x[i];
  }
  return f==M;
}

int Try(int i){
  int v;
  for(v=1;v<=(M-F(i-1))/a[i]+1;v++){
    x[i]=v;
    if(i<n) Try(i+1);
    else {
        if(check()){
            display();
        }
    }
  }
}

int main(){
    int i;
    cout << "Nhap n,M:";
    cin >> n >> M;
    cout <<"Nhap cac he so a";
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    Try(1);
}

//#include<bits/stdc++.h>
//#define fo(i,a,b) for(int i = a; i<=b;++i)
//using namespace std;
//
//int m, n, a[105], x[105];
//
//void write(){
//fo(i,1,n) cout<<x[i]<<' ';
//cout<<'\n';
//}
//
//int check(){
//int tmp = 0;
//fo(i,1,n) tmp+=a[i]*x[i];
//return tmp==m;
//}
//
//int tryy(int i){
//fo(j,1,m){
//x[i] = j;
//if(i<n) tryy(i+1); else if (check()) write();
//}
//}
//
//int main(){
//cin>>m>>n;
//fo(i,1,n) cin>>a[i];
//tryy(1);
//}
