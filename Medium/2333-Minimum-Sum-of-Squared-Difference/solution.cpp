class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        int n = nums1.size();
        vector<int> count(1e5+1 , 0);
        for(int i =0;i<n; i++){
            int ele = abs(nums1[i] - nums2[i]);
            count[ele]++;
        }
        long long k = k1+k2;
        for(int i = 1e5; i>0 && k >0 ; i--){
            int countops = min((long long)count[i] , k);
            count[i] -= countops;
            count[i-1] += countops;
            k -= countops;
        }

        long long sum = 0;
        for(long long i = 0;i<=1e5; i++){
            sum += (count[i] * i*i);
        }
        return sum;
    }
};