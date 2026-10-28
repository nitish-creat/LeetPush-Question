class Solution {
public:
    // int K;
    // int n;
    // priority_queue<int,vector<int>, greater<int>> pq;

    // void removeele(int ele){
    //     vector<int> temp;
    //     while(!pq.empty()){
    //         int x = pq.top();
    //         pq.pop();
    //         if(ele == x) break;

    //         temp.push_back(x);
    //     }

    //     for(auto &i:temp){
    //         pq.push(i);
    //     }
    // }
    // int solve(vector<int>&n1, vector<int> &n2 , int sum , int mini, int i, int count){
    //     if(count == K){
    //         return sum * mini;
    //     }
    //     if(i >= n) return 0;

    //     pq.push(n2[i]);
    //     int take = solve(n1 , n2 , sum+n1[i], pq.top(), i+1, count+1);
    //     removeele(n2[i]);
    //     int skip = solve(n1 , n2 , sum, mini, i+1 , count);

    //     return max(take , skip);
    // }
    typedef long long ll;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        ll res = 0;
        vector<pair<int,int>> temp;
        for(int i = 0;i<nums1.size(); i++){
            temp.push_back({nums2[i] , nums1[i]});
        }

        sort(temp.rbegin() , temp.rend());
        ll  sum = 0;
        priority_queue<int , vector<int> , greater<int >> pq;
        for(int i = 0;i<k; i++){
            int ele =temp[i].second;
            sum += ele;
            pq.push(ele);
        }
        res = sum * temp[k-1].first;
        for(int i = k;i < temp.size() ; i++){
            sum += temp[i].second - pq.top();
            pq.pop();
            pq.push(temp[i].second);

            res = max(res , sum * temp[i].first);
        }

        return res;
    }
};