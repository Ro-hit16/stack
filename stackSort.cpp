#include<iostream>
#include<stack>
using namespace std;

void sort(stack<int>& s, int num) {
    if (s.empty() || num > s.top()) {
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();
    sort(s, num);
    s.push(n);
}

void sortStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    int num = s.top();
    s.pop();
    sortStack(s);
    sort(s, num);
}

int main() {
    stack<int> s;
    s.push(5);
    s.push(1);
    s.push(3);
    s.push(2);
    s.push(4);

    sortStack(s);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
