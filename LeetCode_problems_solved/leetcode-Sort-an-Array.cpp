class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        if(nums.size() <= 1){
            return nums;
        }
        int mid = nums.size() / 2;
        vector <int> left;
        for(int i = 0; i < mid; i++){
            left.push_back(nums[i]);
        }

        vector <int> right;
        for(int i = mid; i < nums.size(); i++){
            right.push_back(nums[i]);
        }
        vector <int> sorted_left = sortArray(left);
        vector <int> sorted_right = sortArray(right);

        int index1 = 0;
        int index2 = 0;
        vector <int> sorted_done;
        for(int i = 0; i < nums.size(); i++){
            if(sorted_left.size() == index1){
                sorted_done.push_back(sorted_right[index2]);
                index2++;
            }
            else if(sorted_right.size() == index2){
                sorted_done.push_back(sorted_left[index1]);
                index1++;
            }
            else if(sorted_left[index1] < sorted_right[index2]){
                sorted_done.push_back(sorted_left[index1]);
                index1++;
            }
            else{
                sorted_done.push_back(sorted_right[index2]);
                index2++;
            }
        }

        return sorted_done;
    }
};
