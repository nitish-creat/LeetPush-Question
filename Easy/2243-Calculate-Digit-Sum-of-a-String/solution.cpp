class Solution {
public:
    string solve(string&s){
        int sum = 0;
        for(auto &i : s){
            sum += i - '0';
        }

        return to_string(sum);
    }
    string digitSum(string s, int k) {
        string temp;
        int n = s.size();

        while(s.size() > k){
            int i= 0;
            int n= s.size();
            temp = "";
            while(i< n){
                int mini = min( k , n-i);
                string ele = s.substr(i , mini);

                temp += solve(ele);
                i += mini;
            }

            s = temp;
        }

        return s;
    }
};