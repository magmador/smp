/**
 * Check if string that contains brackets is balanced.
 *"((([{}])))" - true
 * "" - true
 * "(}" - false
 * "({[}])" - false
 * "(())" - true
 * "(){}" - true
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check_balanced(string s) {
    vector<char> vec;
    size_t str_size = s.size();

    if (str_size % 2 != 0) return false;

    for (size_t i = 0; i < str_size; i++) {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
            vec.push_back(s[i]);
        }
        if (s[i] == ']' || s[i] == ')' || s[i] == '}') {
            char ch = vec.back(); // Needs proper check here
            vec.pop_back();
            if (s[i] == ']') {
                if (ch != '[') {
                    return false;
                }
            }
            if (s[i] == '}') {
                if (ch != '{') {
                    return false;
                }
            }
            if (s[i] == ')') {
                if (ch != '(') {
                    return false;
                }
            }
        }
    }

    return vec.size() == 0;
}

int main() {
    bool result = false;
    string s = "((([{}])))";
    result = check_balanced(s);
    cout << "result: " << result << std::endl;
    s = "({[}])";
    result = check_balanced(s);
    cout << "result: " << result << std::endl;
    s = "())(";
    result = check_balanced(s);
    cout << "result: " << result << std::endl;
    s = "";
    result = check_balanced(s);
    cout << "result: " << result << std::endl;
    s = "((";
    result = check_balanced(s);
    cout << "result: " << result << std::endl;

    return 0;
}
