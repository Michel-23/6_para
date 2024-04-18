#include <iostream>
#include "Matrix.h"

/*template <typename T>
Vector<T> hhh(const Vector<T> vec1, const Vector<T> vec2){
    Vector<T> vec8 = vec1 - vec2;
    return vec8;
}
template <typename G>
Vector<G> ttt(const Vector<G>& vec1, const Vector<G>& vec2){
    Vector<G> vec8 = vec1 - vec2;
    return vec8;
}*/


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

    /*size_t size;
    std:: cin >> size;*/


    Vector<double> vec1 = {1,3,5};
    Vector<double> vec2 = {1,3,5};
    
    Matrix<double> matr1 = Matrix<double> (3, 3);
    Matrix<double> matr2 = Matrix<double> (3, 3);

    matr1[0][0] = 7;
    matr1[0][1] = 8;
    matr1[0][2] = 5;
    matr1[1][0] = 6;
    matr1[1][1] = 0;
    matr1[1][2] = 5;
    matr1[2][0] = 1;
    matr1[2][1] = 4;
    matr1[2][2] = 2.5;

    matr2 = matr1;

    std:: cout << matr1.Obratna_mat() << std:: endl;

    std:: cout << matr2 << std:: endl;

    Matrix<double> matr3 = matr1.Obratna_mat() * matr2;

    std:: cout << matr3 << std:: endl;

    /*std:: cout << matr1 << std:: endl;

    std:: cout << "determinant: \n" << matr.Deter() << std:: endl;

    std:: cout << "Obratn matrix: \n" << matr.Obratna_mat() << std:: endl;

    std:: cout << matr.Tranposition() << std:: endl;*/

    return 0;
}