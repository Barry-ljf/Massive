#include<queue>
#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
/*给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 */
using namespace std;
//这道题是非常考察数据类型的一道题，应该好好做哈！多看看回忆回忆
class Solution {
public:
        class reset{
      public:
            bool operator () (const pair<int,int>&a ,const pair<int,int>&b){
                return a.second>b.second;
            }
            
        };
    vector<int> topKFrequent(vector<int>& nums, int k) {



            priority_queue<pair<int,int>, vector<pair<int,int>>, reset> ljf;

            unordered_map<int,int> mayi;
            for(int i = 0; i<nums.size(); i++){
                mayi[nums[i]]++;
            }

            for(unordered_map<int,int>::iterator ant = mayi.begin();ant !=mayi.end();ant++){
                ljf.push(*ant);
                if(ljf.size()>k){
                    ljf.pop();
                }
            }
            vector<int> result;
            for(int i =0 ; i<k; i++){
                result.push_back(ljf.top().first);
                ljf.pop();
            }
            reverse(result.begin(),result.end());
            return result;




    }
};