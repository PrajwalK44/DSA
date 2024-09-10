class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Use char stack to store parentheses
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            
            else if (c == ')' || c == '}' || c == ']') {
             
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                st.pop();
                
               
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        // If the stack is not empty at the end, return false
        return st.empty();
    }
};
