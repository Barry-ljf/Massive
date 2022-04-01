#include<string>
#include<iostream>
#include<vector>
#include <unordered_set>
/*给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
*/

using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> record;
        unordered_multiset<int> scan(nums1.begin(),nums1.end());
        unordered_multiset<int> scan_2(nums2.begin(),nums2.end());
        for(int item : nums2)
        {
            if(scan.find(item) != scan.end())
            {
                if(record.count(item)<min(scan.count(item),scan_2.count(item)))
                record.insert(item);
            }
        }
        vector<int>result(record.begin(),record.end());
        return result;


    }
};