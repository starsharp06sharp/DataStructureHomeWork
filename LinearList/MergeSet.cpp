#include <iostream>

using namespace std;

namespace my {
    void qsort(int* a, int left, int right)
    {
        if (left >= right) return ;
        int middle = a[(left + right) / 2];
        int i = left;
        int j = right;
        while (true) {
            while (a[i] < middle) ++i;
            while (a[j] > middle) --j;
            if (i >= j) break;
            swap(a[i], a[j]);
        }
        qsort(a, left, i - 1);
        qsort(a, i + 1, right);
    }
    
}
size_t merge (size_t aLen, size_t bLen, int* a, int* b, int* target)
{
    size_t i = 0, j = 0, k = 0;

    while (i < aLen && j < bLen) {
            if (a[i] < b[j])
                target[k++] = a[i++];
            else
                target[k++] = b[j++];

            if (a[i] == b[j - 1])
                ++i;
    }
    while (i < aLen)
        target[k++] = a[i++];
    while (j < bLen)
        target[k++] = b[j++];

    return k;
}

int main ()
{
     size_t aLen, bLen;
     cin >> aLen >> bLen;
     int a[aLen], b[bLen];
     for (size_t i = 0; i < aLen; ++i) {
        cin >> a[i];
     }
    for (size_t i = 0; i < bLen; ++i) {
        cin >> b[i];
     }
     my::qsort(a, 0, aLen - 1);
     my::qsort(b, 0, bLen - 1);
     int ans[aLen + bLen];
     size_t ansLen = merge(aLen, bLen, a, b, ans);

     for (size_t i = 0; i < ansLen; ++i) {
        cout << ans[i] << ' ';
     }
    return 0;
}
