#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define fi first
#define ii pair<ll,ll>
#define iii pair<pair<ll, ll>, ll >
#define se second
#define ld long double
#define mod 1000000007
#define popcount __builtin_popcountll
#define x0 zxcxzcsacasd
#define x1 ghfghujfgfg
#define y0 olkjhdnncvcv
#define y1 bhvgrewm345345435
using namespace std;
int n;
ll a[200010];
ll aa[200010];
ll b[200010];
vector<int>v[200010];
vector<int>rev[200010];
int deg[200010];
bool vis[200010];
vector<int>p;
    ll amid = 0;

vector<int> go(){
    vector<int>ret;
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front(); q.pop();
        ret.pb(node);
        for(auto nx:v[node]){
            deg[nx]--;
            if(deg[nx]==0)q.push(nx);
        }
    }
    return ret;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld", &a[i]);
        aa[i] = a[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld", &b[i]);
        if(b[i]==-1)continue;
        deg[b[i]]++;
        v[i].pb(b[i]);
    }
    vector<int>tmp = go();
    for(auto x:tmp){
        if(aa[x]<0 || b[x]==-1)continue;
        aa[b[x]] += aa[x];
    }
    for(int i=1;i<=n;i++){
        deg[i] = 0;
        v[i].clear();
    }
    for(int i=1;i<=n;i++){
        if(b[i]==-1)continue;
        if(aa[i]>=0){
            v[i].pb(b[i]);
            deg[b[i]]++;
            continue;
        }
        v[b[i]].pb(i);
        deg[i]++;
    }
    ll amid = 0;
    vector<int>p = go();
    for(auto x:p){
        amid+=a[x];
        if(b[x]!=-1)a[b[x]]+=a[x];
    }

	cout<<amid<<endl;
    for(auto x:p)cout<<x<<" "; cout<<endl;
}
