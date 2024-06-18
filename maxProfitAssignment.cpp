#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int n = difficulty.size();
        for(int i=0; i<n; ++i){
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int m = worker.size();
        int ans = 0;
        int maxProfit = 0;
        int j = 0;
        for(int i=0; i<m; ++i){
            while(j < n && worker[i] >= jobs[j].first){
                maxProfit = max(maxProfit, jobs[j].second);
                ++j;
            }
            ans += maxProfit;
        }
        return ans;
    }
};


//Example input
int main(){
    Solution sol;
    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 6, 7};
    cout << sol.maxProfitAssignment(difficulty, profit, worker) << endl;
    return 0;
}