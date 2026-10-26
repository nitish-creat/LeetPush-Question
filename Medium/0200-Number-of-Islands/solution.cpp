class Solution {
public:
    int n , m;
    void check(vector<vector<char>>& grid , int i , int j){
        if(i >= n || i < 0|| j >=m || j <0) return;
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';

        check(grid , i , j-1);
        check(grid , i , j+1);
        check(grid ,i-1, j);
        check(grid , i+1 , j);

    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m ; j++){
                if(grid[i][j] == '1'){
                    check(grid , i, j);
                    count++;
                }
            }
        }

        return count;
    }   
};