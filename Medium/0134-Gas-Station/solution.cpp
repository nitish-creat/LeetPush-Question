class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalkamai = 0;
        int totalspent = 0;
        for(int i = 0;i<n; i++){
            totalkamai += gas[i];
            totalspent += cost[i];
        }
        int res = 0;
        if(totalkamai < totalspent) return -1;
        else{
            totalkamai = 0;
            
            for(int i = 0;i<n ; i++){
                totalkamai += gas[i];
                totalkamai -= cost[i];
                if(totalkamai < 0){
                    res = i+1;
                    totalkamai = 0;
                }
                
            }
        }

        return res;
    }
};