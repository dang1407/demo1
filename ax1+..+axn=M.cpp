#include <iostream>
#define MAX 100001
using namespace std;
int x[100],n=30,k=5,s=0,a[100]={0,1,2,3,4,5}, t[6]={0};

void print(int a[100], int k){
	for(int i=1;i<=k;i++){
		cout << x[i] << " ";
	}
	cout << endl;
}
void Try(int i){
     for(int v=0;v<=n;v++){
     	if(t[i-1] + a[i]*v<=n){
     		x[i] = v;
     		t[i]= t[i-1] +a[i]*v;
     		if(i==k && t[i]==n) print(x,k);
     		else if(i==k && t[i]!=n) continue;
     		else Try(i+1);
		 } else return;
	 }
}

void printBinary(int i){
	for(int v=0;v<=1;v++){
		x[i] = v;
		if(i==n) print(x,n);
		else printBinary(i+1);
	}
}

int main(){
	cout << "Giai phuong trinh: ";
	for(int i=1;i<=k;i++){
		cout << a[i] << "x" << i;
		if(i<k) cout << " + ";
	}
	cout << " = " << n <<endl;
	Try(1);
}
