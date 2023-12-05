#ifndef COMPLEX_TEST_H
#define COMPLEX_TEST_H
#include <iostream>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include "massive/complex.h"
namespace massive{

TEST(COMPLEX,COMPLEX_TEST){
    complex c1(2, 1);
    complex c2(4, 0);

    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << "c1+c2 "<< c1+c2 << std::endl;
}
}
#endif