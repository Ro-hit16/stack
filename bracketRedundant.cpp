#include <iostream>
#include <stack>
using namespace std;

int checkRedundancy(string s) {
    stack<char> st;
    
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        
        // Push operators and '(' to stack
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        
        // If a closing parenthesis is found
        if (ch == ')') {
            bool redundant = true;
            
            // Check for operators inside the parentheses
            while (st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    redundant = false; // Operator found, so it's not redundant
                }
                st.pop();
            }
            st.pop(); // Pop the opening '('
            
            // If no operator was found, the parentheses are redundant
            if (redundant) {
                return 1; // Redundant parentheses found
            }
        }
    }
    
    return 0; // No redundant parentheses
}

int main() {
    string expr = "((a+b))";
    
    if (checkRedundancy(expr)) {
        cout << "Redundant parentheses found\n";
    } else {
        cout << "No redundant parentheses\n";
    }
    
    return 0;
}
