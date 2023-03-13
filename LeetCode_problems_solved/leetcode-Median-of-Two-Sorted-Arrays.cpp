class Solution {
public:
    double quick_sort(vector <int> v){
        if(v.size() <= 1){
            return v;
        }
        int countt = 0;
        int pivot = rand() % v.size() - 1;
        vector <int> small;
        vector <int> big;
        for(int i = 0; i < v.size(); i++){
            if(v[i] < v[pivot]){
                small.push_back(v[i]);
            }
            else if(v[i] > v[pivot]){
                big.push_back(v[i]);
            }
            else{
                countt++;
            }
        }
        vector <int> sorted_small = qucik_sort(small);
        vector <int> sorted_big = quick_sort(big);
        vector <int> sorted_done;
        for(int i = 0; i < sorted_small.size(); i++){
            sorted_done.push_back(sorted_small[i]);
        }

        for(int i = 0; i < countt; i++){
            sorted_done.push_back(v[pivot]);
        }

        for(int i = 0; i < sorted_big.size(); i++){
            sorted_done.push_back(sorted_big[i]);
        }
        int x = sorted_done.size() / 2;
        double median;
        if(x % 2 != 0){
            median = (sorted_done[x - 1] + sorted_done[x]) / 2;
        }
        else{
            median = (sorted_done[x] + sorted_done[x + 1]) / 2;
        }
        return median;

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        vector <int> v;
        for(int i = 0; i < nums1.size(); i++){
            v.push_back(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++){
            v.push_back(nums2[i]);
        }
        double ans = quick_sort(v);
        return ans;
    }
};
