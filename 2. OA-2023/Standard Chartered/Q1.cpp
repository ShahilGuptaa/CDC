#include <bits/stdc++.h>

using namespace std;

long maxknowledge(int d,vector<int> start,vector<int> ed, vector<int> knowledge,int k){
    int n = start.size();
    vector<pair<int,pair<int,int>>> sweep;
    for(int i=0;i<start.size();i++){
        sweep.push_back({start[i],{0,knowledge[i]}});
    }
    for(int i=0;i<start.size();i++){
        sweep.push_back({ed[i],{-1,knowledge[i]}});
    }
    sort(sweep.begin(),sweep.end());
    int cnt=0;
    int sum=0;
    int ans=0;
    multiset<int> use,ref;
    for(auto i:sweep){
        int day=i.first;
        int type=i.second.first;
        int gain=i.second.second;
        if(type==-1){
            //remove
            if(cnt==k){
                //if using
                if(use.find(gain)!=use.end()){
                    //decrease cnt
                    use.erase(use.find(gain));
                    cnt--;
                    sum-=gain;
                    if(!ref.empty()){
                        sum+=*ref.rbegin();
                        use.insert(*ref.rbegin());
                        cnt++;
                        ref.erase(--ref.end());
                    }
                }
                else{
                    ref.erase(ref.find(gain));
                }
            }
            else{
                cnt--;
                use.erase(use.find(gain));
                sum-=gain;
            }
        }
        else{
            if(cnt<k){
                cnt++;
                use.insert(gain);
                sum+=gain;
            }
            else if(cnt==k){
                if(gain>*use.begin()){
                    ref.insert(*use.begin());
                    sum-=*use.begin();
                    use.erase(use.begin());
                    // cnt--;
                    use.insert(gain);
                    // cnt++;
                    sum+=gain;
                }
                else{
                    ref.insert(gain);
                }
            }
        }
        ans=max(ans,sum);
    }
    return ans;
}

int main()
{
    int n,k,d; 
    vector<int> start,ed,knowledge;
    cin>>d>>n>>k;
    // cout<<k<<endl;
    start.assign(n,0);
    ed.assign(n,0);
    knowledge.assign(n,0);
    
    for(int i=0;i<n;i++) cin>>start[i];
    for(int i=0;i<n;i++) cin>>ed[i];
    for(int i=0;i<n;i++) cin>>knowledge[i];
    cout<<maxknowledge(d,start,ed,knowledge,k);

    return 0;
}