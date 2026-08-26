class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> ans(n+m , 0);
        for(int i = n-1;i>=0; i--){
            int a = num1[i] - '0';
            for(int j = m -1; j>=0 ; j--){
                int b = num2[j] - '0';
                int mul = a *b;
                int p1 = i + j;
                int p2 = i +j +1;
                int sum = mul + ans[p2];
                ans[p2] = sum % 10;
                ans[p1] += sum / 10;
            }
        }

        string s = "";
        for(auto &i : ans){
            if(i == 0 && s.empty()) continue;
            s += (i + '0');
        }

        return s.empty() ? "0" : s;
    }
};