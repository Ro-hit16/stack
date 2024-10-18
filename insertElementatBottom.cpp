#include <stack>
using namespace std;

class Solution {
public:
    void solve(stack<int>& st, int x) {
        if (st.empty()) {
            st.push(x);
            return; // Base case: if stack is empty, push the element and return
        }
        
        int num = st.top();
        st.pop();
        solve(st, x); // Recursive call
        st.push(num); // Push the popped element back onto the stack
    }

    stack<int> insertAtBottom(stack<int> st, int x) {
        solve(st, x);
        return st;
    }
};
