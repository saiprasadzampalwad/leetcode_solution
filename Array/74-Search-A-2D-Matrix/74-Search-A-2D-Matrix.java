class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
       int rows = matrix.length;
        int col=matrix[0].length;
        int s = 0, e = (rows * col)-1;
        int m,i,j;
        while (s <= e) {
        m = s +(e-s) / 2;
        i=m/col;
        j=m%col;
        if (matrix[i][j] == target) {
             return true;
        } 
        else if (matrix[i][j] < target) {
            s = m +1;
        } 
        else {
            e= m-1 ;
        }
    }
    return false; 
    }
}