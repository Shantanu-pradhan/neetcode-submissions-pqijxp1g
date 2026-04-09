class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = (int)matrix.size();
        if (m == 0) return false;
        int n = (int)matrix[0].size();
        if (n == 0) return false;

        // Store last element of each row
        vector<int> lelement;
        lelement.reserve(m);
        for (int i = 0; i < m; i++) {
            lelement.push_back(matrix[i][n - 1]);
        }

        // Binary search to find the first row whose last element >= target
        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (lelement[mid] >= target) r = mid - 1;
            else l = mid + 1;
        }

        int row = l;                 // candidate row
        if (row >= m) return false;  // target > all last elements
        if (target < matrix[row][0]) return false;

        // Binary search within that row
        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] < target) i = mid + 1;
            else j = mid - 1;
        }

        return false;
    }
};
