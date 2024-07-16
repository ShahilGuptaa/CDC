vector<string> ans;
    // for(int i=0;i<n;i++)
    // {
    //     map<char,int> temp;
    //     string p = s.substr(0,1);
    //     for(int j=i+1;j<n;j++){
    //         temp[s[j]]++;
    //     }
    //     for(int j=i+1;j<n;j++){
    //         auto it = lower_bound(temp.begin(),temp.end(),s[j]);
    //         if(it==temp.end()) it--;

    //         char c = it->first;
    //         p.push_back(c);

    //         temp[it->first]--;
    //         if(temp[it->first]==0) temp.erase(it->first);
    //     }
    //     ans.push_back(p);
    // }
    // sort(ans.begin(),ans.end());
    // cout<<ans[0]<<'\n';