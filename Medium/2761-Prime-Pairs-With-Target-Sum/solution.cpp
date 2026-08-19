class Solution {
public:
    bool isprime(int n){
        if(n <=1) return false;
        if(n == 2) return true;
        if(n % 2== 0) return false;

        for(int i = 3 ; i*i <= n; i+=2){
            if( n % i == 0) return false;
        }
        return true;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;

        vector<int> arr;
        for(int i = 0;i<=n ;i++){
            if(isprime(i)) arr.push_back(i);
        }
        int left = 0;
        int right = arr.size() -1;
        while(left <= right){
            int first = arr[left];
            int second = arr[right];
            int sum = first + second;
            if(sum == n){
                ans.push_back({first , second});
                left++;
                right--;
            }  
            else if(sum > n){
                right--;
            }
            else if(sum < n){
                left++;
            }
        }

        return ans;
    }
};  