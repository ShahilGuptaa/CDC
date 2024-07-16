#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    vector<int> audio(n);
    for(int i=0;i<n;i++) cin>>audio[i];

    vector<int> read(n,0);
    vector<int> vis(n,0);

    int k; cin>>k;
    vector<pair<int,int>> logs(k);

    for(int i=0;i<k;i++){
        string p; cin>>p;
        int mins; cin>>mins;
        if(p[0]=='L')
        {
            for(int j=0;j<n;j++){
                if(audio[j]<=0) continue;

                read[j] = min(audio[j],mins);
                audio[j] -= read[j];
                mins -= audio[j];

                if(audio[j]==0) vis[j]=1;
                if(mins<=0) break;
            }
        }
        else{
            audio[mins]=-1;
        }
    }
    cout<<max_element(read.begin(),read.end()) - read.begin();
}

int main()
{
    solve();
}