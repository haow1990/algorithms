#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int binary(int a[], int start, int end, int target)
    {
        if (start >= end)
            return -1;
        int mid = (start + end) / 2;
        if (target == a[mid])
            return mid;
        else if (target > a[mid])
            return binary(a, mid + 1, end, target);
        else
            return binary(a, start, mid, target);
    }

    int search(int a[], int start, int end, int target)
    {
        if (start >= end)
            return -1;
        int mid = (start + end) / 2;
        if (target == a[mid])
            return mid;
        if (mid + 1 == end)
            return search(a, start, mid, target);
        if (start == mid)
            return search(a, mid+1, end, target);
        if (a[start] <= a[mid-1] && target <= a[mid-1] && target >= a[start])
            return binary(a, start, mid, target);
        if (a[mid] <= a[end-1] && target >= a[mid+1] && target <= a[end-1])
            return binary(a, mid + 1, end, target);
        int re = search(a, start, mid, target);
        if (re >= 0)
            return re;
        else
            return search(a, mid+1, end, target);
    }

    int search(int A[], int n, int target) {
        return search(A, 0, n, target);
    }
};

int main(int argc, char **argv)
{
    int target = atoi(argv[1]);
    int *array = new int[argc-2];
    for (int i = 2; i < argc; ++i) {
        array[i-2] = atoi(argv[i]);
    }
    Solution s;
    cout << s.search(array, argc - 2, target) << endl;
    return 0;
}
