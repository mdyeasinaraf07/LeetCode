class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector <int> v;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "+"){
                int temp = (v[v.size() - 1]) + (v[v.size() - 2]);
                v.push_back(temp);
            }
            else if(operations[i] == "D"){
                int temp = (v[v.size() - 1]) * 2;
                v.push_back(temp);
            }
            else if(operations[i] == "C"){
                v.pop_back();
            }
            else{
                int temp = stoi(operations[i]);
                v.push_back(temp);
            }
        }
        int sum = 0;
        for(int i = 0; i < v.size(); i++){
            sum += v[i];
        }

        return sum;
    }
};
