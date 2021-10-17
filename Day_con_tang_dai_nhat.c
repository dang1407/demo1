#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int c[100][100], n, cmin, f=0, fmin;


int a[100],b[100],n;

void DayConDaiNhat (int a[100], int b[100], int n){
    int i;
    for(i=1;i<=100;i++){
        b[i]=1;
    }
    for(i=2;i<=n;i++){
        if(a[i]>a[i-1]) b[i]+=b[i-1];
    }
    int max = b[1];
    for(i=1;i<=n;i++){
        if(b[i]>max) max = b[i];
    }
    for(i=1;i<=n;i++){
        if(b[i]==max){
            for(int j = i-max +1 ;j<=i;j++){
                printf("%d ",a[j]);
            }
            break;
        }

    }
}

int main(){
  printf("Nhap n:"); scanf("%d",&n);
  for(int i=1;i<=n;i++){
    printf("a[%d] = ",i);
    scanf("%d",&a[i]);
  }
  DayConDaiNhat(a,b,n);
}
