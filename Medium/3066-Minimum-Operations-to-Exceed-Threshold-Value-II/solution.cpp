class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll , vector<ll> , greater<ll>> pq;
        for(auto &i : nums) pq.push(i);
        int count = 0;
        while(pq.top() < k && pq.size() >= 2){
           ll x = pq.top();
           pq.pop();
           ll y = pq.top();
           pq.pop();

           ll ele = 1LL * (min(x, y) * 2 + max(x,y));
           pq.push(ele);
           count++;     
        }   

        return count;
    }
};