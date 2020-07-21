/*input
9
4 2 5 8 3 6 1 7 9
6 8 8 4 6 3 5 7 5
*/
#include<bits/stdc++.h>
using namespace std;
#define F           first
#define S           second
const int N = 2e5+5;
long int dp[N];
long int seg[4*N],lazy[4*N];

void build(int node,int st,int ed)
{
	lazy[node]=0;
	if(st==ed)
	{
		seg[node]=0;
		return ;
	}

	int mid = (st+ed)/2;
	build(2*node,st,mid);
	build(2*node+1,mid+1,ed);
	seg[node]=max(seg[2*node],seg[2*node+1]);
	return ;
}
//[l,r]
void update(int node,int st,int ed,int l,int r,long int val)
{
	if(lazy[node])
	{
		seg[node]=lazy[node];
		if(st!=ed)
		{
			lazy[2*node]=max(lazy[2*node],lazy[node]);
			lazy[2*node+1]=max(lazy[2*node+1],lazy[node]);
		}
		lazy[node]=0;
	}
	if(st>r || ed<l) return ;
	else if(st>=l && ed<=r)
	{
		seg[node]=val;
		if(st!=ed)
		{
			lazy[2*node]=max(lazy[2*node],val);
			lazy[2*node+1]=max(lazy[2*node+1],val);
		}
		return ;
	}
	else
	{
		int mid = (st+ed)/2;
		update(2*node,st,mid,l,r,val);
		update(2*node+1,mid+1,ed,l,r,val);
		seg[node]=max(seg[2*node],seg[2*node+1]);
		return ;
	}

	assert(0);
	return ;
}
//[l,r]
long int query(int node,int st,int ed,int l,int r)
{
	if(lazy[node])
	{
		seg[node]=lazy[node];
		if(st!=ed)
		{
			lazy[2*node]=max(lazy[2*node],lazy[node]);
			lazy[2*node+1]=max(lazy[2*node+1],lazy[node]);
		}
		lazy[node]=0;
	}
	if(st>r || ed<l) return -1;
	else if(st>=l && ed<=r) return seg[node];
	else
	{
		int mid = (st+ed)/2;
		long int v1 = query(2*node,st,mid,l,r);
		long int v2 = query(2*node+1,mid+1,ed,l,r);
		return max(v1,v2);
	}

	assert(0);
	return -1;
}



int main()
{
	int n;cin>>n;
	vector<pair<int,int>> a(n); // {height,beauty}
	for(int i=0;i<n;i++) cin>>a[i].F;
	for(int i=0;i<n;i++) cin>>a[i].S;

	int st=0,ed=N;
	build(1,st,ed);
	
	for(int i=0;i<n;i++)
	{
		long int mx = query(1,st,ed,0,a[i].F-1) + a[i].S;
		update(1,st,ed,a[i].F,a[i].F,mx);
	}

	long int mx = 0;
	for(int i=0;i<=n;i++) mx=max(mx,query(1,st,ed,i,i));
	cout<<mx<<"\n";
	return 0;
}
