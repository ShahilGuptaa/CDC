#include<bits/stdc++.h>
using namespace std;

struct Order{
    int time;
    int id;
    bool des; //des =  true means -
              //des = false means +
    int sz; 
};

struct PriceUpdate{
    int time; 
    int id;
    int change;
};

int solve(int initialPrice,vector< pair< int,pair<int,int>> > events) //Time, Update or (Sell or Buy), Sell or Buy
{
    int price = initialPrice;
    sort(events.begin(),events.end());
    int n = events.size();
    for(int i=0;i<events.size();i++)
    {
        int t = events[i].first;
        int query = events[i].second.first;
        int q_val = events[i].second.second;
        if(query==1)
        {
            price += q_val;
        }
    }
}

auto ticketMargin(int initialPrice, vector<Order> &orders, vector<PriceUpdate> &feed)
{
    map<int,vector<int>> mp;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int init; cin>>init;

    int feed_size; cin>>feed_size;
    vector<PriceUpdate> feed(feed_size);
    for(int i=0;i<feed_size;i++)
    {
        cin>>feed[i].time>>feed[i].id>>feed[i].change;
    }

    int order_size; cin>>order_size;
    vector<Order> orders(order_size);
    for(int i=0;i<order_size;i++)
    {
        cin>>orders[i].time>>orders[i].id>>orders[i].des>>orders[i].sz;
    }
}