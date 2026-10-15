class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &i : stones) pq.push(i);
        while(pq.size() != 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            pq.push(abs(second - first));
        }

        return pq.top();
    }
};