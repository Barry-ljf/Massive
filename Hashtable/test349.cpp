#include<string>
#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> nums_store(nums1.begin(),nums1.end());
        for(int item : nums2){
            if(nums_store.find(item) != nums_store.end())
            {
                result.insert(item);
            }
            
        }
        return vector<int>(result.begin(),result.end());
    }

};