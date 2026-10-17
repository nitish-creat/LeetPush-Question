class Solution {
public:
    int digitsum(int n){
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            sum += digit;
            n /= 10;
        }

        return sum;
    }
    int minSwaps(vector<int>& nums) {
        vector<tuple<int,int,int>> temp;
    
        for(int i = 0;i<nums.size(); i++){
            int sum = digitsum(nums[i]);
            temp.push_back({sum, nums[i], i});
        }
        sort(temp.begin(),temp.end());
        int count = 0;
        int n = temp.size();
        vector<bool> vis(n,false);
        for(int i = 0;i<n; i++){
            if(vis[i] || get<2>(temp[i]) == i) continue;
            int j = i;
            int cyclesize =0;
            while(!vis[j]){
                vis[j] = true;
                j = get<2>(temp[j]);
                cyclesize++;
            }
            count += cyclesize -1;
        }  

        return count;
    }
};