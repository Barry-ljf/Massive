#include<iostream>
#include<vector>
#include"algsort.h"

namespace massive{

std::vector<int>& AlgSort::BubbleSort(){
    int size = _mInitArray.size();
    for(int i = 0; i <= size - 1; i++){
        for(int j = 1; j < size - i - 1; j++){
            if(_mInitArray[j] < _mInitArray[j-1]){
                std::swap(_mInitArray[j],_mInitArray[j-1]);
            }
        }
    }
    return _mInitArray;
}

std::vector<int>& AlgSort::InsertSort(){
    int size = _mInitArray.size();
    for(int i = 1; i < size; i++){
        for(int j = i ; j > 0; j--){
            if(_mInitArray[j] < _mInitArray[j-1]){
                std::swap(_mInitArray[j] , _mInitArray[j-1]);
            }else{
                break;
            }
        }
    }
    return _mInitArray;
}


std::vector<int>& AlgSort::SelectSort(){
    int size = _mInitArray.size();
    for(int i = 0 ; i < size-1; i++){
        int temp = i;
        for(int j = i+1; j < size; j++){
            if(_mInitArray[j] < _mInitArray[temp]){
                temp = j;
            }
        }
        std::swap(_mInitArray[i],_mInitArray[temp]);
    }
    return _mInitArray;
}

void AlgSort::QuickSort(std::vector<int>& array, int low, int high){
    int size = array.size();
    int i = low;
    int j = high;
    if(low < high){
        int temp = array[low];
        while(i != j){
            while(i < j && array[j]>=temp){
                j--;
            }

            if(i < j ){
                array[i] = array[j];
                i++;
            }

            while(i < j && array[i] < temp ){
                i++;
            }

            if( i < j){
                array[j] = array[i];
                j--;
            }
        }

        if(i == j) array[i] = temp;
        QuickSort(array,low,i-1);
        QuickSort(array,i+1,high);
        }
    }
}

//Need to cancel this if run bazel test!!!!
// int main(){
//     std::vector<int> testarray = {2,4,5,1,9,7,10,7}; 
//     std::vector<int> result;
//     massive::AlgSort sorter(testarray);
//     result = sorter.SelectSort();

//     massive::AlgSort sorter1(testarray);
//     sorter1.QuickSort(testarray,0,7);

//     std::cout << "SelectSort result: ";
//     for (const auto& element : testarray) {
//         std::cout << element << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }



