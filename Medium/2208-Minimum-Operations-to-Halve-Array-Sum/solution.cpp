class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(),nums.end());
        double sum = 0;
        for(auto &i : nums) sum += i;
        double half = sum / 2;
        int count = 0;
        while(sum > half){
            double ele = pq.top();
            pq.pop();
            double h = ele / 2;
            pq.push(h);
            sum -= h;
            count++;
        }

        return count;
    }
};