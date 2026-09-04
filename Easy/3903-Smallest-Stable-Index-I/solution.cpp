class Solution {
public:
    int maxi(vector<int> arr, int n){
        int m = arr[0];
        int i= 0;
        while(i <= n){
            m = max(arr[i],m);
            i++;
        }
        return m;
    }
    int mini(vector<int> arr,int n){
        int m = arr[n];

        while(n < arr.size()){
            m =min(arr[n] , m);
            n++;
        }
        return m;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i=0 ;i<nums.size();i++){
            int m = maxi(nums, i);
            int mi = mini(nums,i);

            if( (m - mi) <= k ){
                return i;
            }
        }
        return -1;
    }
};