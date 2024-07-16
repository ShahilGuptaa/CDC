#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::priority_queue<int> ticket_prices;
    std::vector<int> group_sizes(M);

    for (int i = 0; i < N; i++) {
        int ticket_price;
        std::cin >> ticket_price;
        ticket_prices.push(ticket_price);
    }

    for (int i = 0; i < M; i++) {
        std::cin >> group_sizes[i];
    }

    long long total_profit = 0;

    int max_group_size = 0;

    for (int i = 0; i < M; i++) {
        max_group_size = std::max(max_group_size, group_sizes[i]);

        if (!ticket_prices.empty() && max_group_size <= ticket_prices.top()) {
            total_profit += ticket_prices.top();
            ticket_prices.pop();
        }
    }

    std::cout << total_profit;

    return 0;
}