class Solution {
public:
    int n , m;
    bool check(vector<vector<int>>&grid , int r, int c){
        if(r >= n || r < 0 || c >= m || c < 0) return false;

        if(grid[r][c] == 1) return true;
        grid[r][c] = 1;

        bool left = check(grid , r , c-1);
        bool right = check(grid , r, c+1);
        bool up = check(grid , r-1, c);
        bool down = check(grid , r+1,c);

        return left && up && down && right;

    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for(int i = 0;i<n ; i++){
            for(int j = 0;j<m; j++){
                if(grid[i][j] == 0){
                    if(check(grid , i, j)){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};