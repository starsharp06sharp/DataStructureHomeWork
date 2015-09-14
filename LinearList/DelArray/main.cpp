//2014060101028_郑雷_CH2_2
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cout << "Please input the length of the array:";
    cin >> n;
    int arr[n];
    cout << "Please input array:" << endl;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int j, k;
    cout << "Please input the N.O. of the element you want to delete afer and the number of the elements you want to delete:" << endl;
    cin >> j >> k;
    if (j + k > n) {cerr << "Error Input!";exit(-1);}
    for (int i = j; j + k < n; ++j) {
        arr[j] = arr[j + k];
    }
    for (int i = 0; i < n - k; ++i)
        cout << arr[i] << ' ';
    return 0;
}
