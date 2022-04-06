#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
/*
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指在第 i 天之后，才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。


*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //单调栈
        stack<int> st;
        vector<int> result(temperatures.size(),0);
        st.push(0);
        for(int i = 1 ; i < temperatures.size(); i++){
            
            if(temperatures[i] == temperatures[st.top()]){
                st.push(i);
            }
            else if(temperatures[i] < temperatures[st.top()]){
                st.push(i);
            }else{
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                result[st.top()] = (i-st.top());
                st.pop();
            }
            st.push(i);
            }
            
        }
        return result;


        /*超时的写法*/
        // vector<int> result(temperatures.size(),0);
        // int count = 0;
        // for(int i =0; i < temperatures.size(); i++){
        //     int t = 0;
        //     for(int j =i+1 ;j < temperatures.size();j++ ){
                
        //         if(temperatures[j] > temperatures[i]){
        //             t++;
        //             result[i] = t;
        //             break;
        //         }
        //         else{
        //             t++;
        //         }

        //     }
        // }
        // return result;

    }
};