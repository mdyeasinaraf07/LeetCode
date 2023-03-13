#include <bits/stdc++.h>
using namespace std;
vector <int> quick_sort(vector <int> nums){
            if(nums.size() <= 1){
                return nums;
            }
            int pivot = rand() % nums.size();
            int countt = 0;
            vector <int> small;
            vector <int> big;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] < nums[pivot]){
                    small.push_back(nums[i]);
                }
                else if(nums[i] > nums[pivot]){
                    big.push_back(nums[i]);
                }
                else{
                    countt++;
                }
            }
            vector <int> sorted_done;
            for(int i = 0; i < small.size(); i++){
                sorted_done.push_back(small[i]);
            }
            for(int i = 0; i < countt; i++){
                sorted_done.push_back(nums[pivot]);
            }
            for(int i = 0; i < big.size(); i++){
                sorted_done.push_back(big[i]);
            }
            return sorted_done;
        }

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> sorted_v = quick_sort(nums);
        int low = 0;
        int high = sorted_v.size() - 1;
        vector <int> ans;
        while(low < high){
            int sum = sorted_v[low] + sorted_v[high];
            if(sum == target){
                ans.push_back(low);
                ans.push_back(high);
            }
            else if(sum < target){
                low++;
            }
            else{
                high--;
            }

        }



        return ans;
    }
};

int main(){
    vector <int> v = {2,7,11,15};
    Solution s;
    vector <int> ans = s.twoSum(v, 9);
    cout<< ans[0] << ans[1];


}

