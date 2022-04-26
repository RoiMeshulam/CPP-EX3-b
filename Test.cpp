#include "sources/Matrix.hpp"
#include <algorithm>
#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>
#include "doctest.h"

using namespace zich;
using namespace std;

TEST_CASE("bad input in constructor"){
    vector<double> arr={1,2,3,4,5,6,7,8,9,10,11,12};
    CHECK_THROWS(Matrix a(arr,2,2));
    CHECK_THROWS(Matrix a(arr,13,1));
    CHECK_THROWS(Matrix a(arr,0,12));
    CHECK_THROWS(Matrix a(arr,-2,-6));
    CHECK_NOTHROW(Matrix a(arr,3,4));
    CHECK_NOTHROW(Matrix a(arr,4,3));
    CHECK_NOTHROW(Matrix a(arr,2,6));
    CHECK_NOTHROW(Matrix a(arr,6,2));
    CHECK_NOTHROW(Matrix a(arr,1,12));
    CHECK_NOTHROW(Matrix a(arr,12,1));
}

TEST_CASE("Equality tests"){
    //Define matrix a,b,c
    vector<double> vec_a = {1,2,3,4,5,6,7,8,9};
    Matrix a {vec_a, 3, 3};
    vector<double> vec_b = {3,1,2,4,6,5,7,10,8};
    Matrix b {vec_b,3,3};
    CHECK_EQ(a == b, false);
    CHECK_EQ(a != b, true);
    CHECK_EQ(a < b, true);
    CHECK_EQ(a > b, false);
    CHECK_EQ(a <= b, true);
    CHECK_EQ(a >= b, false);

    //checking increment and decrement
    vector<double> first = {1,1,1,1,1,1,1,1,1};
    vector<double> second = {2,2,2,2,2,2,2,2,2};
    vector<double> third = {3,3,3,3,3,3,3,3,3};
    Matrix m1 {first,3,3};
    Matrix m2 {second,3,3};
    Matrix m3 {third,3,3};

    CHECK_EQ(m1 == m2, false);
    CHECK_EQ(m1 == m3, false);
    CHECK_EQ(m2 == m3, false);
    CHECK_EQ(m1++ == m2, false);
    CHECK_EQ(m1 == m2, true);
    CHECK_EQ(++m1 == m3, true);
    CHECK_EQ(m1-- == m2, false);
    CHECK_EQ(m1 == m2, true);
    CHECK_EQ(--m3 == m2, true);
}

TEST_CASE("Checking addition and subtraction"){
    vector<double> vec_a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Matrix a {vec_a, 2, 5};
    vector<double> vec_b = {8, 7, 6, 5, 4, 3, 2, 1};
    Matrix b {vec_b,4,2};
    vector<double> vec_c = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Matrix c {vec_c,2,5};

    CHECK_THROWS(a+b);
    CHECK_THROWS(b+c);
    CHECK_THROWS(a-b);
    CHECK_THROWS(b-c);
    CHECK_NOTHROW(a+c);
    CHECK_NOTHROW(a-c);

    vector<double> ans1 = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //a+c
    vector<double> ans2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};//a-c
    Matrix m1 {ans1, 2, 5};
    Matrix m2 {ans2, 2, 5};
    Matrix m3 {vec_a, 2, 5};
    CHECK((a+c)==m1);
    CHECK((m1-c)==a);
    a-=c;
    CHECK(a==m2);
    a+=c;
    CHECK(a==m3);
}

TEST_CASE("Multiple CHECK"){
    vector<double> vec_a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12};
    Matrix a {vec_a, 3, 4};
    vector<double> vec_b = {8, 7, 6, 5, 4, 3, 2, 1};
    Matrix b {vec_b,4,2};
    vector<double> vec_c = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Matrix c {vec_c,2,5};
    Matrix d {vec_a,4,3};
    CHECK_THROWS(a*c);
    CHECK_THROWS(c*a);
    CHECK_THROWS(c*b);
    CHECK_THROWS(b*a);
    CHECK_NOTHROW(a*b);
    CHECK_NOTHROW(b*c);
    vector<double> ans1 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    Matrix m1 {ans1, 2, 5};
    CHECK(c*2==m1);
    CHECK(2*c==m1);
    vector<double> ans2 = {70, 80, 90 ,158, 184, 210, 246, 288, 330}; // ans2==a*d (3X3)
    Matrix m2 {ans2,3,3};
    CHECK((a*d)==m2);
}
