class Solution {
public:
    void sortColors(int A[], int n) {
        int array[3] = {};
        for (int i = 0; i < n; ++i) {
            ++array[A[i]];
        }
        for (int i = 0; i < array[0]; ++i)
            A[i] = 0;
        for (int i = array[0]; i < array[0] + array[1]; ++i)
            A[i] = 1;
        for (int i = array[0] + array[1]; i < n; ++i)
            A[i] = 2;
    }
};
