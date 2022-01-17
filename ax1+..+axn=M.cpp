#include<bits/stdc++.h>

using namespace std;

int x[100]={0},a[100],n,s,M,dem=0;

void display(int x[100], int n){
   for(int i=1;i<=n;i++){
    cout << x[i] << " ";
   }
   cout << "\n";
}
int tong(int x[100], int k){
   int s=0;
   for(int i=1;i<=k;i++){
    s+=x[i];
   }
   return s;
}
void Try(int k){

    for(int v=1; v<= M;v++){
        s = tong(x,k-1);
        if(s + v*a[k] <= M){
            x[k] = v;
            if(k==n && tong(x,k)==M) {
              display(x,k);
              dem=1;
            } else if(k==n && s!=M) continue;
            else Try(k+1);
            s -= v*a[k];
        } else return;
    }
}



int main(){
    n=5,M=15;
    for(int i=1;i<=5;i++){
        a[i]=1;
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

