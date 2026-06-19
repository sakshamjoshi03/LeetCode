class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m * n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int row = mid / n; //6/4->1
            int col = mid % n; //6%4->2
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};