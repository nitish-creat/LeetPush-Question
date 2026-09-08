class Solution {
public:
    int countCommas(int n) {
        string s = to_string(n);
        if(s.size() < 4) return 0;
        int count = (s.size() - 1) / 3;
        int total = n - 1000;

        return count * (total +1);
    }
};