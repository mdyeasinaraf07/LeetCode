class Solution {
public:
    int maxDepth(string s) {
        stack <char> st;
        int i = 0;
        int countt = 0;
        int maxi = 0;
        while(s[i] != '\0'){
            if(s[i] == '('){
                st.push(s[i]);
                countt++;
               }
            else if(s[i] == ')'){
                maxi = max(maxi , countt);
                countt--;
                st.pop();
            }
            i++;
        }
        return maxi;
    }
};
