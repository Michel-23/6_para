#include <iostream>
#include "Matrix.h"

template <typename T>
Vector<T> hhh(const Vector<T> vec1, const Vector<T> vec2){
    Vector<T> vec8 = vec1 - vec2;
    return vec8;
}
template <typename G>
Vector<G> ttt(const Vector<G>& vec1, const Vector<G>& vec2){
    Vector<G> vec8 = vec1 - vec2;
    return vec8;
}


int main(){
    // int arr[] = {1,3,4,6,8};
    // int arr2[] = {1,3,4,6,5};

    // Vector <int> vec1 = Vector <int> (5, arr);
    // Vector <int> veccopy = Vector <int> (vec1); // дефолтный конструктор копирования, но его нам нужно переопределить
    // int arr[] = {1,3,4,6,8};
    // int arr2[] = {1,3,4,6,5};

    // Vector <int> vec1 = Vector <int> (5, arr);
    // Vector <int> vec2 = Vector <int> (5, arr2);
    // std::cout << vec1 << std::endl;
    // vec1 = vec2;
    // std::cout << vec1 << std::endl;

    // Matrix<int> matrix = Matrix<int> (3,4);
    // std::cout << matrix << std::endl;

    // matrix[1][1] = 10;
    // std::cout << matrix << std::endl;

    Vector<double> vec1 = {1,2,3,4,5};
    std::cout << vec1.Lengg() << std::endl;

    Vector<double> vec2 = {5,4,3,2,1};

    Vector<double> vec3 = vec1 + vec2;
    std::cout << vec3 << std::endl;

    Vector<double> vec4 = vec1 - vec2;
    std::cout << vec4 << std::endl;

    double vec5 = vec1 * vec2;
    std::cout << vec5 << std::endl;

    std::cout << vec1.normaliz() << std::endl;

    Vector<double> rez = hhh(vec1, vec2);
    std::cout << rez << std::endl;

    Vector<double> rew = ttt(vec1, vec2);
    std::cout << rew << std::endl;
    return 0;
}