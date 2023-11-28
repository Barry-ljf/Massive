#include<iostream>
#include <glog/logging.h>
#include <gtest/gtest.h>

#include"massive/algsort.h"

namespace massive{
    TEST(AlgSortTest,AlgSortBubble_test){
        std::vector<int> testarray = {2,4,5,1,7}; 
        std::vector<int> result;
        AlgSort sorter(testarray);
        result = sorter.BubbleSort();

        std::cout << "BubbbleSort result: ";
        for (const auto& element : result) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}