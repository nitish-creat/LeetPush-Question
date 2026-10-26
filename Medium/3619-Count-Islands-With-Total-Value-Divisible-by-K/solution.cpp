class Solution {
public:
    int n , m;
    typedef long long ll;
    ll check(vector<vector<int>> &grid , int i, int j){
        if(i < 0 ||i >= n || j < 0 || j >= m) return 0;

        if(grid[i][j] == 0) return 0;
        ll val = grid[i][j];
        grid[i][j] = 0;

        ll left = check(grid , i, j-1);
        ll right = check(grid , i, j+1);
        ll down = check(grid , i+1, j);
        ll up = check(grid , i-1, j);

        return val + left + right+ down + up ;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for(int i = 0;i<n; i++){
            for(int j = 0;j<m; j++){
                if(grid[i][j] != 0){
                    ll sum = check(grid ,i, j);
                    if(sum % k == 0) count++;
                }
            }
        } 

        return count;
    }
};