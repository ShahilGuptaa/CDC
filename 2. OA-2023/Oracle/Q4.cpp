#include <bits/stdc++.h>
using lli = long long int;
using namespace std;
 
//Find no. of pairs (i,j) i<j s.t. a[i]^a[j] > a[i]&a[j]

void solve(){
 
	int n; cin >> n;
	vector<int> v(n);
 
	int cnt[32] = {0};
	lli ans = 0;
	for(int &x : v){
		cin >> x;
		ans += cnt[31 - __builtin_clz(x)]++;
	}
    lli count = 1ll*(n)*(n-1)/2 - ans;
	cout << count<< '\n';
}
 
int main(){
	int t; cin >> t;
	while(t--) solve();
}