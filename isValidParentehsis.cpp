#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> br;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{') {
                br.push(ch);
            }
            else {
                if(br.empty()) {
                    return false;
                }
                
                char top = br.top();
                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '[')) {
                    br.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        return br.empty();
    }
};
