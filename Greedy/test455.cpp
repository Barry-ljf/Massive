#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

 
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort(g.begin(),g.end());
        // sort(s.begin(),s.end());
        // int index = s.size() -1;
        // int happy = 0;
        // for(int i = g.size()-1 ; i >= 0; i-- ){
        //     if(index >= 0 && s[index] >= g[i]){
        //         happy++;
        //         index--;
        //     }
        // }
        // return happy;




    /*遇到大数组就歇菜,解决了，记住，for循环的是饼干数目，从最小的开始的时候，是比：如果一个小饼干，小朋友1吃不了，应该自动跳饼干，因此饼干在for循环里面，然后小朋友是因为被满足了才下一个，按逻辑讲局部问题是每一个小朋友被满足，就会全部被满足
    反之，如果从最大的值开始比，那就是饼干是有条件的跳，而小朋友在一个吃不了之后就跳下一个就好了，所以在for循环里面循环的是孩子*/
        int happy = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        if(s.size() == 0 || g.size() == 0){return 0;}
        int child =0;
        for(int binggan = 0 ; binggan < s.size(); binggan++){
            if(child < g.size() && g[child] <= s[binggan])
            {
                child++;
                happy++;
            }
        }

            ///

        
        return happy;

}
};