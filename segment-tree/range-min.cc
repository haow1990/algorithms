#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
using namespace std;

class MinSegmentTree {
public:
    MinSegmentTree(const vector<int> &source);
    int min(int start, int end) const;
    void update(int idx, int newval);
private:
    int create(const vector<int> &source, size_t root, size_t start, size_t end);
    int min(size_t root, size_t currentStart, size_t currentEnd, size_t start, size_t end)const;
    void update(size_t root, size_t start, size_t end, int idx, int newval);
    vector<int> data_;
    size_t size_;
};

MinSegmentTree::MinSegmentTree(const vector<int> &source)
{
    size_ = source.size();
    if (source.empty()) {
        return;
    }
    size_t datasize = 2;
    size_t srcsize = source.size();
    while ((srcsize >>= 1) !=  0) {
        datasize <<= 1;
    }
    data_.resize(datasize, INT_MAX);
    create(source, 0, 0, source.size() - 1);
}

// [start, end]
int MinSegmentTree::create(const vector<int> &src, size_t root, size_t start, size_t end)
{
    if (start == end) {
        data_[root] = src[start];
        return src[start];
    }
    if (start > end) {
        return INT_MAX;
    }
    int mid = (start + end) / 2;
    int min1 = create(src, 2 * root + 1, start, mid);
    int min2 = create(src, 2 * root + 2, mid + 1, end);
    if (min1 < min2) {
        data_[root] = min1;
    } else {
        data_[root] = min2;
    }
    return data_[root];
}

// [start, end]
int MinSegmentTree::min(int start, int end) const
{
    if (size_ == 0) {
        return INT_MAX;
    } else {
        return min(0, 0, size_ - 1, start, end);
    }
}


int MinSegmentTree::min(size_t root, size_t currentStart, size_t currentEnd, size_t start, size_t end) const
{
    if (start < currentStart || end > currentEnd || start > end) {
        return INT_MAX;
    }
    if (start == currentStart && end == currentEnd) {
        return data_[root];
    }
    int mid = (currentStart + currentEnd) / 2;
    if (mid >= end) {
        return min(2 * root + 1, currentStart, mid, start, end);
    } else if (mid < start) {
        return min(2 * root + 2, mid + 1, currentEnd, start, end);
    }
    int min1 = min(2 * root + 1, currentStart, mid, start, mid);
    int min2 = min(2 * root + 2, mid + 1, currentEnd, mid + 1, end);
    if (min1 < min2) {
        return min1;
    } else {
        return min2;
    }
}

void MinSegmentTree::update(int idx, int newval)
{
    if (size_ == 0) {
        return;
    }
    update(0, 0, size_ - 1, idx, newval);
}

void MinSegmentTree::update(size_t root, size_t start, size_t end, int idx, int newval)
{
    if (idx < start || idx > end) {
        return;
    }  
    if (start == idx && end == idx) {
        data_[root] = newval;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) {
        update(root * 2 + 1, start, mid, idx, newval);
    } else {
        update(root * 2 + 2, mid + 1, end, idx,newval);
    }
    if (data_[root * 2 + 1] < data_[root * 2 + 2]) {
        data_[root] = data_[root * 2 + 1];
    } else {
        data_[root] = data_[root * 2 + 2];
    }
}

int main(int argc, char **argv)
{
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    vector<int> nums;
    for (int i = 3; i < argc; ++i) {
        nums.push_back(atoi(argv[i]));
    }

    MinSegmentTree tree(nums);
    tree.update(4, 5);
    cout << tree.min(start, end) << endl;
    return 0;
}

