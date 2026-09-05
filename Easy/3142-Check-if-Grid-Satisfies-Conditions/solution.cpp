class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0;i<row; i++){
            for(int j =0; j<col; j++){
                if(i < row-1 && grid[i][j] != grid[i+1][j]) return false;
                if(j < col-1 && grid[i][j] == grid[i][j+1]) return false;
            }
        }

        return true;
    }
};