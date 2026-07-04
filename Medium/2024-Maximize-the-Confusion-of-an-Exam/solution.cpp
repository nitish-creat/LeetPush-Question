class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int countTrue = 0;
        int countFalse = 0;
        int left = 0;
        int right = 0;
        int ansTrue = 0 , ansFalse = 0;
        while(right < s.size()){
            if(s[right] == 'F') countTrue++;

            while(countTrue > k){
                if(s[left] == 'F') countTrue--;
                left++;
            }
            if(countTrue <= k){
                ansTrue = max(ansTrue , right - left +1);
            }
            right++;
        }

        right = 0 ; left =0;
        while(right < s.size()){
            if(s[right] == 'T') countFalse++;

            while(countFalse > k){
                if(s[left] == 'T') countFalse--;
                left++;
            }
            if(countFalse <= k){
                ansFalse = max(ansFalse  , right - left +1);
            }
            right++;
        }


        return max(ansFalse , ansTrue);
    }
};