class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(auto i : s){
            freq[i]++;
        }
        vector<pair<char,int>> temp(freq.begin(),freq.end());
        sort(temp.begin(),temp.end(),[](pair<char,int> &a , pair<char,int>&b) { return a.second>b.second;});
        string res = "";
        for(auto &i : temp){
            res += string(i.second , i.first);
        }
        return res;
    }
};