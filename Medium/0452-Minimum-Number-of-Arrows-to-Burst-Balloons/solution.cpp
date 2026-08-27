class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0;
        sort(points.begin(),points.end());
        pair<int,int> prev = {points[0][0] , points[0][1]};
        for(int i = 1;i<points.size(); i++){
            pair<int,int> curr = {points[i][0] , points[i][1]};
            if(prev.second < curr.first){ 
                count++;
                prev = curr;
            }
            else{
                prev.first = max(curr.first , prev.first);
                prev.second = min(curr.second , prev.second);
            }
        }

        return count+1;
    }
};