#include <iostream>

using namespace std;

size_t merge (size_t aLen, size_t bLen, int* a, int* b, int* target)
{
    size_t i = 0, j = 0, k = 0;

    while (i < aLen && j < bLen) {
            if (a[i] < b[j])
                target[k++] = a[i++];
            else
                target[k++] = b[j++];
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

     int ans[aLen + bLen];
     size_t ansLen = merge(aLen, bLen, a, b, ans);

     for (size_t i = 0; i < ansLen; ++i) {
        cout << ans[i] << ' ';
     }
    return 0;
}
