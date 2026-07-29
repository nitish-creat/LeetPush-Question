class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
        sort(boxes.begin(),boxes.end(),[](vector<int>&a , vector<int>&b){
            return a[1] > b[1];
        });
        int ans = 0;

        for(int i = 0;i < boxes.size(); i++){
            int box = boxes[i][0];
            int unit = boxes[i][1];

            int take = min(truckSize , box);
            ans += take*unit;
            truckSize -= take;

            if(truckSize <= 0){
                break;
            }
        }

        return ans;
    }
};