class Solution {
public:
    int max_ele(vector<int>&arr){
        int maxi = INT_MIN;
        for(auto i:arr){
            maxi = max(maxi,i);
        }
        return maxi;
    }
    long long total_time(vector<int>&arr , int n){
        long long total =0;
        for(int i=0;i<arr.size();i++){
            total += (arr[i] + n - 1) / n;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high = max_ele(piles);

        while(low <= high){
            int mid = low + (high-low)/2;
            long long t = total_time(piles,mid);
            if(t <= h){
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return low;

    }
};