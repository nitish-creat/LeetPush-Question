class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto &i:piles){
            pq.push(i);
        }

        while(k > 0){
            int ele = pq.top();
            pq.pop();
            ele -= ele/2;
            pq.push(ele);
            k--;
        }
        int total = 0;
        while(!pq.empty()){
            total += pq.top();
            pq.pop();
        }

        return total;
    }
};