class Solution {
public:
    int max(int x, int y) {
        return x > y ? x : y;
    }
    int max(int x, int y, int z) {
        return x > y ? max(x, z) : max(y, z);
    }
    int min(int x, int y) {
        return x > y ? y : x;
    }
    int min(int x, int y, int z) {
        return x > y ? min(y, z) : min(x, z);
    }
    int maxProduct(int A[], int n) {
        if (n < 1) {
            return 0;
        }
        int result = A[0];
        int lower = A[0];
        int upper = A[0];
        for (int i = 1; i < n; ++i) {
            int v1 = lower * A[i];
            int v2 = upper * A[i];
            lower = min(v1, v2, A[i]);
            upper = max(v1, v2, A[i]);
            result = max(result, upper);
        }
        return result;
    }
};
