class Solution {
public:

    vector<int> lps(string &s){
        vector<int> p(s.size(), 0);
        for(int i=1; i<s.size(); i++){
            int j=p[i-1];
            if(s[i]==s[j]){
                p[i]=j+1;
                continue;
            }
            while(j>0 && s[i]!=s[j]){
                j--;
                j=p[j];
            }
            if(s[i]==s[j]) p[i]=j+1;
        }
        return p;
    }


    string shortestPalindrome(string s) {
        if(s== "") return "";
        string t=s;
        reverse(s.begin(), s.end());
        t+="$";
        t+=s;
        reverse(s.begin(), s.end()); 
    

        vector<int> p=lps (t);
        int matched=p[t.size()-1];

        string appendChars=s.substr(matched);
        reverse(appendChars.begin(), appendChars.end());
        return appendChars + s;
    }
};