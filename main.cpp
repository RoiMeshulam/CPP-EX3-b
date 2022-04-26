#include <iostream>
#include "sources/Matrix.hpp"

using namespace std;
using namespace zich;

int main() {
    vector<double> identity = {1,0,0,0,1,0,0,0,1};
    Matrix m1 {identity,3,3};
    cout<<m1<<endl;
    cout<<endl;
    vector<double> v1 = {10,10,10,10,10,10,10,10,10};
    Matrix m2 {v1,3,3};
    cout<< m2 << endl;
    cout<<endl;
    cout<< m1+m2<<endl;
    cout<<endl;
    cout<< m1*m2<<endl;
    cout<<endl;
    vector<double> v2 = {1,2,3,4,5,6,7,8,9,10,11,12};
    Matrix m3 {v2,3,4};
    cout<< m2*m3<<endl;
    cout<<endl;

//    example of throwing
//    cout<< m3*m2<<endl;
//    cout<<endl;
}