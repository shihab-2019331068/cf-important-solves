#include<bits/stdc++.h>

using namespace std;

#define ios               ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ifs               freopen("input.txt","r",stdin);
#define ofs               freopen("output.txt","w",stdout);
#define iof               ifs ofs
#define ll                long long
#define ld                long double
#define da(x,i)           cout << #x << "[" << i << "] = " << x[i] << "\n";
#define da2(x,i,y,j)      cout << #x << "[" << i << "] = " << x[i] << " ! " << #y << "[" << j << "] = " << y[j] << "\n";
#define d2a(x,i,j)        cout << #x << "[" << i << "][" << j << "] = " << x[i][j] << "\n";
#define db(x)             cout << #x << " = " << (x) << "\n";
#define db2(x,y)          cout << #x << " = " << (x) << " ! " << #y << " = " << (y) << "\n";
#define db3(x,y,z)        cout << #x << " = " << (x) << " ! " << #y << " = " << (y) << " ! " << #z << " = " << (z) << "\n";
#define db4(w,x,y,z)      cout << #w << " = " << (w) << " ! " << #x << " = " << (x) << " ! " << #y << " = " << (y) << " ! " << #z << " = " << (z) << "\n";
#define inf               LLONG_MAX
#define fr                first
#define sc                second
#define all(a)            a.begin(),a.end()



struct st
{
    ll u=0,v=0;
    ll du=-inf,dv=-inf;
};

const ll N=1e5+7;
vector<st> mv(N);
vector<ll> a(N,0), g[N], V, P(N,0);
vector<ll> dn(N,-inf), up(N,-inf);
ll n,m,A,u,v,D;

void upf(ll u)
{
    V[u]=1;
    if(a[P[u]])
        up[u]=1;
    up[u]=max(up[u],up[P[u]]+1);
    if(mv[P[u]].u!=u)
        up[u]=max(up[u],mv[P[u]].du+2);
    else
        up[u]=max(up[u],mv[P[u]].dv+2);
    for(ll v : g[u]){
        if(!V[v])
            upf(v);
    }
}

void down(ll u)
{
    V[u]=1;
    if(a[u])
        dn[u]=0;
    for(ll v : g[u]){
        if(V[v])
            continue;
        P[v]=u;
        down(v);
        dn[u]=max(dn[u],dn[v]+1);
    }
}

int main()
{
    cin>>n>>m>>D;
    for(;m--;){
        cin>>u;
        a[u]=1;
    }
    for(m=1; m<n; m++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    V.assign(n+1,0);
    down(1);
    for(u=1; u<=n; u++){
        for(ll v : g[u]){
            if(v==P[u])
                continue;
            if(dn[v]>mv[u].du){
                mv[u].v=mv[u].u;
                mv[u].u=v;
                mv[u].dv=mv[u].du;
                mv[u].du=dn[v];
            }
            else if(dn[v]>mv[u].dv){
                mv[u].v=v;
                mv[u].dv=dn[v];
            }
        }
    }
    V.assign(n+1,0);
    upf(1);
    for(u=1,A=0; u<=n; u++){
        if(max(up[u],dn[u])<=D)
            A++;
    }
    cout<< A;
}
