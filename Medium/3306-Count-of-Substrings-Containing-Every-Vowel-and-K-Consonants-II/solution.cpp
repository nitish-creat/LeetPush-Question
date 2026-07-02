class Solution {
public:
    bool isvowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        unordered_map<char,int> mp;
        int n = word.size();
        vector<int> constInd(n);
        int lastind = n;
        for(int i = n-1;i>=0;i--){
            constInd[i] = lastind;
            if(!isvowel(word[i])){
                lastind = i;
            }
        }
        int left =0;
        int right = 0;
        long long count = 0;
        int con = 0;
        while(right< n){
            char ch = word[right];
            if(isvowel(ch)){
                mp[ch]++;
            }else{
                con++;
            }

            while(left < n && con > k){
                char c = word[left];
                if(isvowel(c)){
                    mp[c]--;
                    if(mp[c] == 0){
                        mp.erase(c);
                    }
                }
                else{
                    con--;
                }
                left++;
            }

            while(left < n && con == k && mp.size() == 5){
                int ind = constInd[right];
                count += ind - right;
                char ch = word[left];
                if(isvowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }
                else{
                    con--;
                }
                left++;
            }

            right++;
        }

        return count;
    }
};