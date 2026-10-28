class Solution {
public:
    typedef pair<double,pair<int,int>> P;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<P> pq;
        int left = 0;
        int right = arr.size()-1;
        while(right > 0){
            if(left == right){
                left = 0;
                right--;
            }
            else{
                double fra =   (double)arr[left] / arr[right];
                pq.push({fra , {arr[left] , arr[right]}});
                if(pq.size() > k) pq.pop();
                left++;
            }
        }
        auto ele = pq.top();
        res.push_back(ele.second.first);
        res.push_back(ele.second.second);

        return res;
    }
};