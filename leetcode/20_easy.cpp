#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto c : s) {
            if (c == '[' || c == '(' || c == '{') {
                st.push(c);
            }
            if (c == ']' || c == ')' || c == '}') {
                if (st.empty()) {
                    return false;
                }

                char ch = st.top();
                st.pop();

                if ((c == ']' && ch != '[') ||
                    (c == ')' && ch != '(') ||
                    (c == '}' && ch != '{')) {
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};

int main() {
    string eg = "()[]{}";
    Solution obj;
    cout << obj.isValid(eg) << endl;

    return 0;
}
