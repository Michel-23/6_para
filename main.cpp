#include <iostream>
#include "Vector.h"

int main(){
    double* array_for_vec2 = new double[10]{
        1,2,3,4,5,6,7,8,9,10
    };
    double arr[] = {1,3,4,6,8};

    Vector <int> vec1 = {1,3,4,6,8};
    Vector <double> vec2  = Vector <double> (10, array_for_vec2);

    std:: cout << vec1 << std:: endl;
    std:: cout << vec2 << std:: endl;

    delete [] array_for_vec2;
    return 0;
}