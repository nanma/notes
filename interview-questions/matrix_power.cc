#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
#define EPS  1e-8
#define MAXN 500050
#define INF  0x3f3f3f3f
#define PI   acos(-1.0)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define mabs(a) ((a<0)?(-a):a)
#define L(t) (t << 1)  //Left son t*2
#define R(t) (t << 1 | 1) //Right son t*2+1
#define Mid(a,b) ((a+b)>>1) //Get Mid
#define lowbit(a) (a&-a) //Get Lowbit
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a*b/gcd(a,b);}
struct matrix
{
    int ma[35][35];
} first, result;
int n, k, m;

/*矩阵乘法*/
matrix operator * (matrix a,matrix b)
{
    matrix temp;
    memset(temp.ma,0,sizeof(temp.ma));
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < n ; j++)
            for(int k = 0 ; k < n ; k++)
                temp.ma[i][j] = (temp.ma[i][j] + (a.ma[i][k] * b.ma[k][j]) % m) % m ;
    return temp;
}

/*矩阵加法*/
matrix operator +(matrix a,matrix b)
{
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < n ; j++)
            a.ma[i][j] = (a.ma[i][j] + b.ma[i][j]) % m;
    return a;
}

/*矩阵快速幂*/
matrix m_pow(matrix a, int n)
{
    if(n == 1)
        return a;
    matrix temp = m_pow(a,n/2);
    if(n & 1)
        return temp * temp * a;
    else
        return temp * temp ;

}
/*分治解决!*/
matrix solve(matrix a,int now)
{
    if(now == 1)
        return a ;
    int mid = now>>1;
    matrix temp = solve(a,mid);
    if(now & 1)
        return temp + (m_pow(a,mid) * (temp + m_pow(a,mid+1)))  ;
    else
        return temp + (m_pow(a,mid) * temp);
}
int main()
{
//  freopen("in.txt","r",stdin);
//  freopen("out.txt,"w",stdout);
    cin>>n>>k>>m;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            scanf("%d",&first.ma[i][j]);
    result = solve(first,k);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
            cout<<result.ma[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
