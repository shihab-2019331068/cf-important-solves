/*
C. Candies Distribution
Mail.Ru Cup 2018 Round 1.
https://codeforces.com/contest/1054/problem/C


There are n children numbered from 1 to n in a kindergarten. Kindergarten teacher gave ai (1≤ai≤n) candies to the i-th child. Children were seated in a row in order
from 1 to n from left to right and started eating candies.

While the i-th child was eating candies, he calculated two numbers li and ri — the number of children seating to the left of him that got more candies than he and 
the number of children seating to the right of him that got more candies than he, respectively.

Formally, li is the number of indices j (1≤j<i), such that ai<aj and ri is the number of indices j (i<j≤n), such that ai<aj.

Each child told to the kindergarten teacher the numbers li and ri that he calculated. Unfortunately, she forgot how many candies she has given to each child.
So, she asks you for help: given the arrays l and r determine whether she could have given the candies to the children such that all children correctly calculated 
their values li and ri, or some of them have definitely made a mistake. If it was possible, find any way how she could have done it.

Solution:
for all a[i]==x, l[i]+r[i]==f[x];
count all possible f[x], if the number of f[x] is greater than n, then impossible.
then decide the array as, a[i]=f[l[i]+r[i]];
then check if 'a' contradcts with 'l' and 'r' or not.
then print 'a'.
*/





#include<bits/stdc++.h>

using namespace std;

#define fastio            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ifs               freopen("aa.in","r",stdin);
#define ofs               freopen("aa.out","w",stdout);
#define iof               ifs ofs
#define ll                long long
#define ld                long double
#define da(x,i)           cout << #x << "[" << i << "]=" << x[i] << "\n";
#define da2(x,i,y,j)      cout << #x << "[" << i << "]=" << x[i] << " ! " << #y << "[" << j << "]=" << y[j] << "\n";
#define d2a(x,i,j)        cout << #x << "[" << i << "][" << j << "]=" << x[i][j] << "\n";
#define db(x)             cout << #x << "=" << (x) << "\n";
#define db2(x,y)          cout << #x << "=" << (x) << " ! " << #y << "=" << (y) << "\n";
#define db3(x,y,z)        cout << #x << "=" << (x) << " ! " << #y << "=" << (y) << " ! " << #z << "=" << (z) << "\n";
#define db4(w,x,y,z)      cout << #w << "=" << (w) << " ! " << #x << "=" << (x) << " ! " << #y << "=" << (y) << " ! " << #z << "=" << (z) << "\n";
#define inf               LLONG_MAX
#define fr                first
#define sc                second
#define all(a)            a.begin(),a.end()



void pno()
{
   cout<<"NO\n";
   exit(0);
}

const ll N=1e4+7;
ll a[N],l[N],r[N],f[N];
ll n,i,j,L,R;
set<ll> s;

int main()
{
   cin>>n;
   for(i=1; i<=n; i++)
      cin>>l[i];
   for(i=1; i<=n; i++){
      cin>>r[i];
      s.insert(l[i]+r[i]);
   }
   if(s.size()>n)
      pno();
   i=n;
   for(ll j:s)
      f[j]=i--;
   for(i=1; i<=n; i++)
      a[i]=f[l[i]+r[i]];
   for(i=1; i<=n; i++){
      L=R=0;
      for(j=1; j<i; j++)
         if(a[j]>a[i])
            L++;
      for(j=i+1; j<=n; j++)
         if(a[j]>a[i])
            R++;
      if(l[i]!=L or r[i]!=R)
         pno();
   }
   cout<<"YES\n";
   for(i=1; i<=n; i++)
      cout<<a[i]<<" \n"[i==n];
}

