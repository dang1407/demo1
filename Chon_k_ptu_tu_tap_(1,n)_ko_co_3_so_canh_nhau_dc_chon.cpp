
// Liệt kê tất cả các cách chọn ra k phần tử từ 1,2,...,n sao cho ko có 3 phần từ cạnh nhau cùng được chọn

#include <iostream>
using namespace std;

int x[10]={0}, n=10,M=10,a[10]={0,1,2,3},k=4;

void display(){ // in mảng màn hình
    int i;
 for(i=1;i<=k;i++){
 cout << x[i] << ' ';
 }
 cout << endl;
}
int check(int i){  // 2 phần tử cạnh nhau có hiệu là 1
 if(i==1) return 1;
 if(x[i]-x[i-1]==1 && x[i-1]-x[i-2]==1 ) return 0;
 else return 1;
}


int Try(int i){
  int v;
 for(v=i;v<=n-k+i;v++){
   x[i]=v;
   if(check(i)==0 || x[i-1] >=v ) continue;
    if(i<k) Try(i+1);
    else display();
 }
}

int main(){
    x[0]=-1;
    Try(1);
}


