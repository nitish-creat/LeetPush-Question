class Solution {
public:
    const int mod = 1e9 +7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i = 0;i<n ; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum += nums[j];
                pq.push(sum);
            }
        }

        int count = 1;
        long long sum = 0;
        while(count <= right){
            int ele = pq.top();
            pq.pop();
            if(count >= left){
                sum = (sum + ele) % mod;
            }
            count++;
        }

        return sum;
    }
};