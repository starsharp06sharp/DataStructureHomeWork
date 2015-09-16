#include <iostream>

using namespace std;

constexpr int MAX_SIZE = 100;

int queue[MAX_SIZE];
int front = 0, rear = 0;

int main()
{
    int n, element;
    while (cin >> n && n != 0) {
        if (n > 0) {
            cin >> element;
            queue[++rear] = element;
        } else if (n == -1) {
            cout << "Pop: " << queue[rear--] << endl;
        } else {
            cout << "Error input !" << endl;
        }
    }
    return 0;
}
