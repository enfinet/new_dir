#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>

#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <ostream>
#include <iomanip>

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>

#include <bitset>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>

using namespace std;

template< class T > T sq(T &x)
{
    return x * x;
}
template< class T > T abs(T &n)
{
    return (n < 0 ? -n : n);
}
template< class T > T max(T &a, T &b)
{
    return (!(a < b) ? a : b);
}
template< class T > T min(T &a, T &b)
{
    return (a < b ? a : b);
}
template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}
template< class T > T mod(T &a, T &b)
{
    return (a < b ? a : a % b);
}

#define null            0
#define MOD             1000000007
#define read(f)         freopen(f, "r", stdin)
#define write(f)        freopen(f, "w", stdout)
#define clr(p)          memset(p, 0, sizeof(p))
#define ff              first
#define ss		        second
#define pb(x)           push_back(x)
#define fori(i, val, n) for(int i = val; i < (int)(n); i++)
#define ford(i, val, n) for(int i = val; i > (int)(n); i--)

#define s(a)		    scanf("%d",&a)
#define sc(a)		    scanf("%c",&a)
#define sl(a)		    scanf("%lld",&a)
#define sf(a)		    scanf("%f",&a)
#define sd(a)		    scanf("%lf",&a)
#define sst(a)		    scanf("%s",a)

#define p(a)		    printf("%d",a)
#define pc(a)		    printf("%c",a)
#define pl(a)		    printf("%lld",a)
#define pd(a)		    printf("%lf",a)
#define pst(a)		    printf("%s",a)

#define nl              printf("\n");
#define sp              printf(" ");

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = 3.1415926535897932384626433832795;

inline void ifast(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if(c=='-')
    {
        neg = 1;
        c = getchar_unlocked();
    }
    for(; c>47 && c<58 ; c = getchar_unlocked())
    {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
        x = -x;
}

int a[1000005];

int main()
{
    int T;
    //s(T);
    ifast(T);
    while(T--) {
        int n,m;
        //s(n);s(m);
        ifast(n);ifast(m);
        /*for(int i=0;i<=n+1;i++)
            a[i]=0ll;*/
        int w,x,y,num;
        while(m--) {
            //s(w);s(x);s(y);s(num);
            ifast(w);ifast(x);ifast(y);ifast(num);
            if(w==1) {
                a[x]+=(int)num;
                a[y+1]-=(int)num;
            } else {
                a[x]-=(int)num;
                a[y+1]+=(int)num;
            }
        }
        int mn=a[1]+1,mx=a[1]+1;
        for(int i=1;i<n;i++) {
            a[i+1]+=a[i];
            //a[i+1]+=;
            if(mn>(a[i+1]+(int)((int)i+1)))mn=a[i+1]+(int)((int)i+1);
            if(mx<(a[i+1]+(int)((int)i+1)))mx=a[i+1]+(int)((int)i+1);
            //a[i+1]=0ll;
            a[i]=0;
        }
        //p(mn);sp;p(mx);nl;
        a[1]=0;
        a[n]=0;
        p(mx-mn);nl;
    }
    return 0;
}
