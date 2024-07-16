#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
#define F first
#define S second

ii par[26][26];
int size[26][26];

ii find(ii x){
    if(par[x.F][x.S]==x) return x;
    else return (par[x.F][x.S] = find(par[x.F][x.S]));
}
//don't do rank compression
void unite(ii x,ii y)
{
    ii rx = find(x), ry = find(y);
    if(size[rx.F][rx.S]<size[ry.F][ry.S]) swap(rx,ry);

    if(rx==ry) return;

    size[rx.F][rx.S] += size[ry.F][ry.S];
    par[ry.F][ry.S] = rx;
}

void solve()
{
    int n;cin>>n;
    vector<string> v(n);
    int arr[26][26];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++) cin>>v[i];

    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            par[i][j] = {i,j};
            size[i][j] = 0;
        }
    }
    string s;
    int components = 0;
    
    for(int i=0;i<n;i++)
    {
        int r = v[i][0]-'a';
        int c = v[i][1]-'a';
        arr[r][c] = 1;
        size[r][c] = 1;
        
        for(int x=0;x<26;x++)
        {
            if(arr[r][x]){
                ii temp = find({r,x});
                unite(temp,{r,c});
            }
            if(arr[x][r]){
                ii temp = find({x,r});
                unite(temp,{r,c});
            }
            if(arr[x][c]){
                ii temp = find({x,c});
                unite(temp,{r,c});
            }
            if(arr[c][x]){
                ii temp = find({c,x});
                unite(temp,{r,c});
            }
        }
        ii root = (find({r,c}));
        if(size[root.F][root.S]==i+1){
            s.push_back('1');
        }else{
            s.push_back('0');
        }
    }
    cout<<s<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}