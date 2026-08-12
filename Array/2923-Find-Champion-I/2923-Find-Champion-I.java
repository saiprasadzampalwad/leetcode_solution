class Solution {
    public int findChampion(int[][] grid) {
        int n = grid.length;
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (grid[i][j] == 1) {
                j--;      
            } 
            else {
            i++;     
            }
        }
        int candidate = i;
        for (int k = 0; k < n; k++) {
            if (k != candidate) {
            
                if (grid[candidate][k] == 0) return -1;
                if (grid[k][candidate] == 1) return -1;
            }
        }

        return candidate;
    }
}