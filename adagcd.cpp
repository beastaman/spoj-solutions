/*
 *  author:  beastaman 
 *  problem: ADAGCD--SPOJ
 * 
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define inf 1e7+9
ll mod=1000000007;
ll power(ll x,ll y,ll p){
    ll res = 1;   
    x = x % p;    
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p; 
    }
    return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n,c,p; cin>>n; vector<int>prim; prim.reserve(10000+1);
	map<ll,ll>mp; vector<ll>lp(inf+1); mp.clear();
	for(int i=2;i<=inf;++i) lp[i]=i;
	for(int i=2;i*i<=inf;++i){
		if(lp[i]==i)
			for(int j=i*i;j<=inf;j+=i){
				if(lp[j]==j) lp[j]=i;
			}
	}
	for(int k=0;k<n;++k){
		ll m;cin>>m;
		map<ll,ll>mp2;mp2.clear();
		for(int j=0;j<m;++j){
			ll a; cin>>a;
			if(k==0){
				while(a>1){
					c=0;p=lp[a];
					while(a>1 and a>=p and a%p==0){
						++c;a/=p;
					}
					mp[p]+=c;	
				}
				
			}
			else{
				while(a>1){
					c=0;p=lp[a];
					while(a>=p and a%p==0){
						++c;a/=p;
					}
					mp2[p]+=c;
				}
			}
		}
		if(k>0){
			auto it=mp.begin();
			while(it!=mp.end()){
				if(mp2.find(it->first)==mp2.end()) mp[it->first]=0;
				else mp[it->first]=min(mp[it->first],mp2[it->first]);
				//cout<<it->first<<" "<<it->second<<" ";
				++it;
			}
			//cout<<"\n";
		}
	}
	ll ans=1;
	auto it=mp.begin();
	while(it!=mp.end()){
		ans=(ans*power(it->first,it->second,(ll)mod));//%(ll)mod;
		ans=ans%mod;
		//cout<<ans<<"\n";
		++it;
	}
	cout<<ans<<"\n";
	return 0;
}
