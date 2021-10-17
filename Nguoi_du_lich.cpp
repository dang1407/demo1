//
//// Bài toán người đi du lịch
//
//#include <iostream>
//using namespace std;
//long long int f=0, a[100],n=5, c[100][100], cmin, f_min=9999999999999;
//bool marked[1000];
//void Try(int k){
//for(int v = 1; v<=n;v++){
//    if(marked[v]==false){
//        a[k]=v;
//        f=f+c[a[k-1]][a[k]];
//        marked[v]=true;
//        if(k==n){
//            process();
//        }else {
//        int g = f+ cmin*(n-k+1);
//        if(g<f_min) Try(k+1);
//        }
//    }
//    marked[v] = false;
//    f=f-c[a[k-1]][a[k]];
//}
//}
//void process(){
//  if(f + c[a[n]][a[1]] < f_min){
//    f_min = f + c[a[n]][a[1]];
//  }
//}
//
//int main(){
//
//   int i,j;
//   cout << "Nhap c:";
//   for(i=1;i<=n;i++){
//    for(j=1;j<=n;j++){
//        cin >> c[i][j];
//    }
//   }
//   int cmin=c[1][1];
//   for(i=1;i<=n;i++){
//    for(j=1;j<=n;j++){
//       if(c[i][j]<cmin) cmin=c[i][j];
//    }
//   }
//   for(int v=1;v<=n;v++){
//    marked[v]=false;
//   }
//   a[1]=1; marked[1]=true;
//   Try(2);
//}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

using namespace std;

int n = 4;
int c[MAX][MAX];
int minC = 10000000;
int x[MAX];
bool visit[MAX];

int bestVal = 10000000;
int bestSol[MAX];
int f = 0;

void generateCost()
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <=n; j++)
        {
            if(j==i) continue;
            int randVal = rand()%100;
            c[i][j] = randVal;
            c[j][i] = randVal;

            if(randVal < minC)
            {
                minC = randVal;
            }
        }
    }
}

void printCost()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
             if(j==i) continue;
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

void Try(int k)
{
    for(int v = 2; v <= n; v++)
    {
        if(visit[v] == false)
        {
            x[k] = v;

            f += c[x[k-1]][x[k]];

            visit[v] = true;
           cout << "k = " << k << ",f1 = " << f;
            if( k== n)
            {
                if(f + c[x[k]][x[1]] < bestVal)
                {
                    bestVal = f + c[x[k]][x[1]];

                    for(int i = 1; i <= n; i++)
                    {
                        bestSol[i] = x[i];
                    }
                }
            }
            else
            {
                int g = f + minC * (n-k+1);
                if(g < bestVal)
                {
                    Try(k+1);
                }
            }

            visit[v] = false;

            f -= c[x[k-1]][x[k]];
            cout << "f2 = " << f;
        }
    }
}
int main()
{
    generateCost();

    printCost();

    for(int i = 0; i <= n; i++)
    {
        visit[i] = false;
    }

    x[1] = 1;
    visit[1] = true;

    Try(2);

    cout << "Shortest tour " << bestVal << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << bestSol[i] << "->";
    }
    cout << endl;
    return 0;
}
