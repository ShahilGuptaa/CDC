#include<bits/stdc++.h>
using namespace std;

int calculateScore( vector<int>& nums) {
    int score = 0;
     unordered_map<int, int> freq_map;

    for (int num : nums) {
        freq_map[num]++;
    }

    while (!nums.empty()) {
        int max_num = nums[0];

        for (int num : nums) {
            if (freq_map[num] * num > freq_map[max_num] * max_num) {
                max_num = num;
            }
        }
        score += freq_map[max_num] * max_num;
        freq_map[max_num] = 0;
        nums.erase( remove(nums.begin(), nums.end(), max_num - 1), nums.end());
        nums.erase( remove(nums.begin(), nums.end(), max_num), nums.end());
        nums.erase( remove(nums.begin(), nums.end(), max_num + 1), nums.end());
    }
    return score;
}

int main() {
    int n;
     cout << "Enter the number of elements in the array: ";
     cin >> n;

     vector<int> nums(n);
     cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
         cin >> nums[i];
    }

    int score = calculateScore(nums);
     cout << "Final score: " << score <<  endl;

    return 0;
}