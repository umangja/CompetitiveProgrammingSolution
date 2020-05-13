#include <bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin >> s;
	set<pair<int,int>> se;
	int g=0,d=0,p,h;
	int ans=0;
	for(auto ch: s){
		p=d;h=g;
		if(ch=='N')g++;
		else if(ch=='S')g--;
		else if(ch=='W')d--;
		else d++;
		if(!se.count({p+d,h+g})){
			ans+=5;
			se.insert({p+d,h+g});
		}else ans++;
	}
	cout<<ans<<"\n";
}
int main(){
	int t;
	cin >> t;
	while(t--)solve();
	return 0;
}