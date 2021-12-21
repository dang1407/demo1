#include<bits/stdc++.h>

using namespace std;

int x[100],a[100],n,s=0,M,dem=0;

void display(int x[100], int n){
   for(int i=1;i<=n;i++){
    cout << x[i] << " ";
   }
   cout << "\n";
}

void Try(int k){

    for(int v=1; v<= M;v++){
        if(s + v*a[k] <= M){
            x[k] = v;
            s += v*a[k];
            if(k==n) {
              display(x,k);
              dem=1;
            }
            else Try(k+1);
            s -= v*a[k];
        } else return;
    }
}



int main(){
    srand((int) time(0));
    n = 1  + rand()%4;
    M = 15 + rand()%14;
    for(int i=1;i<=n;i++){
        a[i] = 1 + rand()%9;
    }
    cout << "Giai phuong trinh: ";
    for(int i =1;i<=n;i++){
        cout << a[i] << "x" << i;
        if(i<n) cout << " + ";
    }
    cout << " = " << M <<endl;

    x[0]=0;
    Try(1);
    if(dem==0) cout << "Phuong trinh vo nghiem!";
}
