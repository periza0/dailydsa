#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
using namespace std;

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();

    vector<int> v(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        if (!s.empty()) {
            v[i] = s.top();
        }

        s.push(arr[i]);
    }

    for (int x : v) cout << x << " ";
}
