class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxi = 0;
        int n = tokens.size();
        int left = 0;
        int right = n-1;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        while(left <= right){
            if(power >= tokens[left]){
                power -= tokens[left];
                left++;
                score += 1;
                maxi = max(maxi , score);
            }
            else if(score >= 1){
                power += tokens[right];
                right--;
                score -=1;
            }
            else{
                break;
            }
        }

        return maxi;
    }
};