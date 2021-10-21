// Bài toán tìm dãy con có tổng lớn nhất của 1 dãy số bất kì có n phần tử

#include<stdio.h>
#include<math.h>
int x[100] = {8, 29, 119, 200, 243, 252, 256, 256, 262, 433},y=256,n;

int maxSeq(int x[100], int l, int r) { // hàm maxSeq với các tham số: mảng x[100], bắt đầu từ l và kết thúc ở r
    if(l==r) return x[r]; // a[l] có thể âm
    int mid = (l+r)/2;
    int mL = maxSeq(x,l,mid); // tổng của dãy con lớn nhất từ 1 ->mid, duyệt bắt đầu từ mid sang trái
    int mR = maxSeq(x,mid+1,r); // tổng của dãy con lớn nhất từ mid+1 -> r, duyệt bắt đầu từ mid+1 sang phải
    int mLR = maxLeft(x,l,mid) + maxRight(x,mid+1,r); // tổng của dãy con lớn nhất bắt đầu từ nửa trái và kết thúc ở nửa phải
    int max = mL;   // gán max = tổng của dãy con lớn nhất từ 1 ->mid
    if(max < mR ) max = mR; // tìm dãy con lớn nhất trong 3 tổng nhỏ
    if(max < mLR) max = mLR;
    return max;
}

int maxLeft(int x[100], int l, int r) {
    int s=0;
    int max = -pow(10,8);
    for(int i=r; i>=l; i--) {
        s+=x[i];
        if(s>max) max =s;
    }
    return max;
}


int maxRight(int x[100], int l, int r) {
    int s=0;
    int max=-pow(10,9);
    for(int i=l; i<=r; i++) {
        s+=x[i];
        if(s>max) max=s;
    }
    return max;
}

int main() {

  printf("Nhap n:"); scanf("%d", &n);
  printf("Nhap mang:");
  for(int i=1;i<=n;i++){
    scanf("%d", &x[i]);
  }
  printf(" max = %d", maxSeq(x,1,n));
}











//// bài toán xóa phần tử để được dãy con tăng lớn nhất
//#include <stdio.h>
//
//#include <algorithm>
//
//#include <iostream>
//
//#include <vector>
//
//using namespace std;
//
//
//
//#define N 100005
//
//int n, a[N], F[N];
//
//int m, b[N];
//
//
//
//int main() {
//
//    // array a, length n
//
//    while (scanf("%d", &a[n + 1]) > 0) n++;
//
//
//
//    // array b, length m, in increasing order
//
//    for (int i = 1; i <= n; i++) {
//
//        F[i] = upper_bound(b + 1, b + m + 1, a[i]) - b;
//
//        m = max(m, F[i]);
//
//        b[F[i]] = a[i];
//
//    }
//
//
//
//    // m is also max(F)
//
//    printf("%d\n-\n", m);
//
//
//
//    int Expected = m;
//
//    vector<int> T;
//
//
//
//    // add m elements from a into T
//
//    for (int i = n; i >= 1; i--) {
//
//        if (F[i] == Expected) {
//
//            T.push_back(a[i]);
//
//            Expected--;
//
//        }
//
//    }
//
//
//
//    // output T in reversed order
//
//    for (int i = T.size() - 1; i >= 0; i--)
//
//        printf("%d ", T[i]);
//
//    return 0;
//
//}
