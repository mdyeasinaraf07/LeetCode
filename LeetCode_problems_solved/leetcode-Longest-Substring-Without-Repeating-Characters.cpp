class Solution {
public:


    //trying but not solved (:<)

    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1){
            return 1;
        }
        vector <char> v;
        int maxi = 0;
        int countt = v.size();
        bool x = true;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < v.size(); j++){
                if(s[i] != v[j]){
                    x = true;
                }
                else{
                    x = false;
                    break;
                }
            }
            if(x == true){
                v.push_back(s[i]);
                countt = v.size();
                maxi = max(maxi, countt);
            }
            else{
                maxi = max(maxi, countt);
                v.clear();
                countt = 0;
                v.push_back(s[i]);
                countt = v.size();
                x = true;
            }
        }
        return maxi;
    }
};
