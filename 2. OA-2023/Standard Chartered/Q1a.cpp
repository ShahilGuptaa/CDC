#include <bits/stdc++.h>
using namespace std;

long maxKnowledge(int d, vector<int> s, vector<int> e, vector<int> a, int k) {
    long n = s.size();
    vector<pair<long,pair<long,long>>>sweep;
    for(long i=0;i<s.size();i++){
        sweep.push_back({s[i],{0,a[i]}});
    }
    for(long i=0;i<s.size();i++){
        sweep.push_back({e[i],{-1,a[i]}});
    }
    sort(sweep.begin(),sweep.end());
    long cnt=0;
    long sum =0;
    long ans =0;
    multiset<long> use,ref;
    for(auto i: sweep){
        long day = i.first;
        long type = i.second.first;
        long gain = i.second.second;
        if(type==-1){
            if(cnt==k){
                if(use.find(gain)!=use.end()){
                    use.erase(use.find(gain));
                    cnt--;
                    sum -=gain;
                    if(!(ref.empty())){
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
                use.erase(ref.find(gain));
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
                        sum -= *use.begin();
                        use.erase(use.begin());
                        use.insert(gain);
                        sum+=gain;
                    }
                    else{
                        ref.insert(gain);
                    }
                }
            }
            ans = max(ans,sum);    
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
    cout<<maxKnowledge(d,start,ed,knowledge,k);

    return 0;
}
