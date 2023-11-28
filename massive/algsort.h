#ifndef ALGSORT_H
#define ALGSORT_H

#include<iostream>
#include<vector>
namespace massive{
class AlgSort{

    public:
    AlgSort(std::vector<int>& array):_mInitArray(array){};
    std::vector<int>& BubbleSort();
    std::vector<int>& InsertSort();
    std::vector<int>& SelectSort();
    void QuickSort(std::vector<int>& array, int low, int high);

    private:
    std::vector<int> _mInitArray;
    int size;
};

}
#endif