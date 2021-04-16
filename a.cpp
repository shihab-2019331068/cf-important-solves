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














































