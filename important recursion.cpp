#include<bits/stdc++.h>

using namespace std;

#define fastio            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ifs               freopen("wormhole.in","r",stdin);
#define ofs               freopen("wormhole.out","w",stdout);
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

const ll N=15;
vector<ll> f(N,0),x=f,y=f;
ll A,i,j,n,ok,k;
vector<vector<pair<ll,ll>>> g;
ll F[N][2];

void dfs(ll u,ll k)
{
    if(F[u][k]>2 or ok){
        ok=1; return;
    }
    F[u][k]++;
    for(auto p : g[u]){
        if(k==p.sc)
            continue;
        dfs(p.fr,p.sc);
    }
}

bool foo()
{
    ll i;
    for(i=ok=0; !ok and i<n; i++){
        memset(F,0,sizeof(F));
        dfs(i,0);
    }
    A+=ok;
}

void rec(ll i=0)
{
    if(i==n){
        foo();
        return;
    }
    if(f[i]){
        rec(i+1); return;
    }
    ll j;
    for(j=0; j<n; j++){
        if(f[j] or i==j)
            continue;
        f[i]=f[j]=1;
        g[i].push_back({j,1});
        g[j].push_back({i,1});
        rec(i+1);
        f[i]=f[j]=0;
        g[i].pop_back();
        g[j].pop_back();
    }
}

int main()
{
    iof
    cin>>n;
    for(i=0; i<n; i++)
        cin>>x[i]>>y[i];
    g.assign(n,{});
    for(i=0; i<n; i++){
        for(j=0,k=-1; j<n; j++){
            if(y[i]!=y[j] or x[i]>=x[j])
                continue;
            if(k==-1 or x[k]>x[j])
                k=j;
        }
        if(k!=-1)
            g[i].push_back({k,0});
    }
    rec();
    cout<< A <<"\n";
}

