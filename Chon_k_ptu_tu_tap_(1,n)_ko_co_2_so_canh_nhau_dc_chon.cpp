
// Liệt kê tất cả các cách chọn ra k phần tử từ 1,2,...,n sao cho ko có 2 phần từ cạnh nhau cùng được chọn

#include <iostream>
using namespace std;

int x[10]={0}, n=6,M=10,a[10]={0,1,2,3},k=3;

void display(){ // in mảng màn hình
    int i;
 for(i=1;i<=k;i++){
 cout << x[i] << ' ';
 }
 cout << endl;
}
int check(int i){  // 2 phần tử cạnh nhau có hiệu là 1
 if(i==1) return 1;
 if(x[i]==x[i-1] || x[i]-x[i-1]==1 || x[i]<x[i-1]) return 0;
 else return 1;
}


int Try(int i){
  int v;
 for(v=i;v<=n-k+i;v++){
   x[i]=v;
   if(check(i)==0) continue;
    if(i<k) Try(i+1);
    else display();
 }
}

int main(){
    x[0]=1;
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
