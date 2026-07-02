class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int leftsum = 0;
        int rightsum = 0;
        int maxi = 0;
        for(int i = 0;i<k;i++){
            leftsum += card[i];
        }

        maxi = leftsum;
        int rightind = card.size()-1;

        for(int i = k-1;i>=0;i--){
            leftsum -= card[i];
            rightsum += card[rightind--];
            maxi = max(maxi , leftsum + rightsum);
        }

        return maxi;
    }
};