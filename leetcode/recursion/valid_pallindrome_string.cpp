class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c); // Convert to lowercase and append if alphanumeric
            }
        }
        
        string reversed = solve(filtered, 0);
        return (reversed == filtered);
    }

    string solve(string& s, int idx){

        if(idx >= s.size())
            return "";

        
        return solve(s, idx + 1) + s[idx];
    }
};