class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& a, vector<int>& b) {
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        int left = 0;
        int right = 0;
        while(left < a.size() && right < b.size()){
            if(a[left] <= b[right]){
                left++;
            } 
            right++;
        }

        return left;
    }
};