/*input
6 8
3 1 1
3 6 2
5 4 2
4 2 2
6 1 1
5 2 1
3 2 3
1 5 4


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18

#define pii pair<ll,ll>
#define mp make_pair
#define F first
#define S second


int main()
{
	int n,m;cin>>n>>m;

	vector<vector<vector<pair<ll,ll>>>> adj(n,vector<vector<pair<ll,ll>>> (4,vector<pii> ()));

	for(int i=0;i<m;i++){
		ll x,y;cin>>x>>y;
		x--,y--;
		ll w;cin>>w;
		for(int j=0;j<4;j++){
			adj[x][j] .push_back( {y,w} );
			adj[y][j] .push_back( {x,w} );
		}
	}


	vector<vector<ll>> dist(n,vector<ll> (4,inf));
	priority_queue< pair<ll,pii> , vector< pair<ll,pii> >, greater< pair<ll,pii> >  > pq;

	dist[0][0] = 0;
	pq.push( mp(0,mp(0,0)) );
/*

00 -> none done 
01 -> one edge added
10 -> one edge deleted
11 -> both done 


*/

	while(!pq.empty()){

		pii cur = pq.top().S;
		ll d    = pq.top().F;

		pq.pop();

		if(d!=dist[cur.F][cur.S]) continue;

		ll b1 = (cur.S/2)%2,b2 = cur.S%2;

		for( pii ch : adj[cur.F][cur.S] ){
			if(b1==0 && b2==0){

				if( d+ch.S < dist[ch.F][0] ){
					dist[ch.F][0] = d+ch.S;
					pq.push(mp(dist[ch.F][0],mp(ch.F,0)));
				}

				if( d+ch.S < dist[ch.F][3] ){
					dist[ch.F][3] = d+ch.S;
					pq.push(mp(dist[ch.F][3],mp(ch.F,3)));
				}
				
				if( d+2*ch.S < dist[ch.F][1] ){
					dist[ch.F][1] = d+2*ch.S;
					pq.push(mp(dist[ch.F][1],mp(ch.F,1)));
				}

				if(d < dist[ch.F][2]){
					dist[ch.F][2] = d;
					pq.push(mp(dist[ch.F][2],mp(ch.F,2)));
				}

			}	
			else if(b1==1 && b2==1){
				if( d+ch.S < dist[ch.F][3] ){
					dist[ch.F][3] = d+ch.S;
					pq.push(mp(dist[ch.F][3],mp(ch.F,3)));
				}
			}
			else if(b1==1 && b2==0){
				// one already deleted
				if( d+ch.S < dist[ch.F][2] ){
					dist[ch.F][2] = d+ch.S;
					pq.push(mp(dist[ch.F][2],mp(ch.F,2)));
				}

				if( d+2*ch.S < dist[ch.F][3] ){
					dist[ch.F][3] = d+2*ch.S;
					pq.push(mp(dist[ch.F][3],mp(ch.F,3)));
				}

			}
			else {
				// one already added 
				if( d+ch.S < dist[ch.F][1] ){
					dist[ch.F][1] = d+ch.S;
					pq.push(mp(dist[ch.F][1],mp(ch.F,1)));
				}

				if( d < dist[ch.F][3] ){
					dist[ch.F][3] = d;
					pq.push(mp(dist[ch.F][3],mp(ch.F,3)));
				}

			}
		}
	}

	for(ll i=1;i<n;i++) cout<<dist[i][3]<<" ";

	return 0;
}

/*

		1

	2
4		3
			5
*/