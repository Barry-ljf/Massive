#include<iostream>
#include<vector>
using namespace std;
vector<int> new1(5,1);

int show_length(vector<int> &a){
    int count=0;
    for(int i =0; i<a.size()-1;i++){//both is ok
    //for(int ss : a){
        count++;

    }
    return count;
}
int main(){

    cout<<show_length(new1);

}
