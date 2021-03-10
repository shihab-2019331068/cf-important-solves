#include<bits/stdc++.h>

using namespace std;

#define fastio            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ifs               freopen("input.txt","r",stdin);
#define ofs               freopen("output.txt","w",stdout);
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

const ll N=12;
vector<ll> t(34),a,b,c,d;
ll e[N][N];
ll n,i,j,k,m,v,rs,s;

int main()
{
    for(i=1,t[0]=1; i<31; i++)
        t[i]=t[i-1]*2;
    cin>>n;
    for(i=0; i<n; i++){
        for(j=0; j<3; j++){
            cin>>v; v--;
            e[i][j]=v;
        }
    }
    c.assign(t[n],0);
    d.assign(t[n],100);
    for(i=0; i<t[n]; i++){
        for(j=0,a={}; j<n; j++){
            if(i&t[j]){
                a.push_back(j);
                for(k=0; k<3; k++){
                    if(~i&t[e[j][k]])
                        c[i]++;
                }
            }
        }
        m=a.size();
        if(m>n/2)
            continue;
        b.assign(N,0);
        do{
            for(j=0; j<m; j++){
                b[a[j]]=j;
            }
            for(j=s=0; j<m; j++){
                for(k=0; k<3; k++){
                    s+=max(0ll,j-b[e[a[j]][k]]);
                }
            }
            d[i]=min(d[i],s);
        } while(next_permutation(all(a)));
    }
    rs=inf;
    for(i=0; i<t[n]; i++){
        rs=min(rs,d[i]+d[~i&(t[n]-1)]+c[i]);
    }
    cout<<rs <<"\n";
}
