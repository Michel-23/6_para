#include <iostream>
#include "Matrix.h"

// template <typename T>
// Vector<T> hhh(const Vector<T> vec1, const Vector<T> vec2){
//     Vector<T> vec8 = vec1 - vec2;
//     return vec8;
// }
// template <typename G>
// Vector<G> ttt(const Vector<G>& vec1, const Vector<G>& vec2){
//     Vector<G> vec8 = vec1 - vec2;
//     return vec8;
// }


int main(){
    // Vector<double> vec1 = {1,2,3,4,5};
    // std::cout << vec1.Lengg() << std::endl;

    // Vector<double> vec2 = {5,4,3,2,1};

    // Vector<double> vec3 = vec1 + vec2;
    // std::cout << vec3 << std::endl;

    // Vector<double> vec4 = vec1 - vec2;
    // std::cout << vec4 << std::endl;

    // double vec5 = vec1 * vec2;
    // std::cout << vec5 << std::endl;

    // std::cout << vec1.normaliz() << std::endl;

    // Vector<double> rez = hhh(vec1, vec2);
    // std::cout << rez << std::endl;

    // Vector<double> rew = ttt(vec1, vec2);
    // std::cout << rew << std::endl;

    size_t size;
    std:: cin >> size;

    Matrix<double> matr = Matrix<double>(size,size);

    //std::cout << matr.matrixDet() << std::endl;

    return 0;
}