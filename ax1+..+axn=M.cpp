#include <iostream>
#define MAX 100001
using namespace std;
int x[100],n=10,k=4,s=0,a[100]={0,1,1,2,3}, t[6]={0};

void print(int a[100], int k){
	for(int i=1;i<=k;i++){
		cout << x[i] << " ";
	}
	cout << endl;
}
void Try(int i){
     for(int v=0;v<=n;v++){

     	if(s + a[i]*v<=n){
     		x[i] = v;
     		s= s + a[i]*v;
     		if(i==k && s==n) print(x,k);
     		else if(i==k && s!=n) {
                s = s-a[i]*v;
                continue;
     		}
     		else Try(i+1);
     			 s = s-a[i]*v;
		 } else return;

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

