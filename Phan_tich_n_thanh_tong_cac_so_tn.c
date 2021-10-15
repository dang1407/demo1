#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int x[100],n=30, f=0,a[100];

int Try(int i){
  int v;
  for( v=i;v<=n;v++){
    if(v<a[i-1]) continue;
   if(a[i-1] + v <=n) {
    x[i]=v;
    a[i]= a[i-1] + v;
   } else return 0;
//   printf("a[%d] = %d, x[%d] = %d\n", i,a[i], i,x[i]);
   if(a[i]<n) Try(i+1);
   if(a[i]==n) {
    for(int j = 1;j <=i;j++){
        printf("%d ", x[j]);
    }
    printf("\n");
   }
}
}

int main(){
    a[0]=0;
   Try(1);
}
