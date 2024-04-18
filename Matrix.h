#include "Vector.h"
#include <random>

template<typename T>
class Matrix{
private:
    Vector<T>* _vectors;
    size_t _size;
public:
    Matrix() = delete;

    Matrix (size_t rows, size_t cols){
        _size = rows;
        _vectors = new Vector<T>[rows];
        for (size_t i = 0; i < _size; i++){
            _vectors[i] = Vector<T> (cols); // расширяем вектор (выделяем память под каждый элемент)
        }
    }

    Matrix (const Matrix& tmp){ // конструктор копирования
        _size = tmp._size;
        _vectors = new Vector<T>[_size];
        for (int i = 0; i < _size; i++){
            _vectors[i] = tmp._vectors[i];
        }
    }

    Matrix(std:: initializer_list<T> list){
        _size = list.size(); 
        _vectors = new T[_size]; 
        int i = 0; 
        for (auto elem = list.begin(); elem != list.end(); elem ++, i++){ 
            _vectors[i] = *elem; 
        }
    }

    Matrix operator+ (const Matrix& tmp) const{ //?<T>
        Matrix A = Matrix (tmp._size, _vectors[0].Get_size());

        for (int i = 0; i < _size; i++){
            for (int j = 0; j < _vectors[0].Get_size(); j++){
                A[i][j] = _vectors[i][j] + tmp._vectors[i][j];
            }
        }

        return A;
    }

    Matrix operator- (const Matrix& tmp) const{ //?<T>
        Matrix A = Matrix (tmp._size, _vectors[0].Get_size());

        for (int i = 0; i < _size; i++){
            for (int j = 0; j < _vectors[0].Get_size(); j++){
                A[i][j] = _vectors[i][j] - tmp._vectors[i][j];
            }
        }

        return A;
    }

    Matrix operator*(const Matrix& tmp) const{

        if (_vectors[0].Get_size() != tmp._size){
            throw "error";
        }

        Matrix A = Matrix(_size, tmp._vectors[0].Get_size());

        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < tmp._vectors[0].Get_size(); j++) {
                for (int k = 0; k < _size; k++) {
                    A[i][j] += _vectors[i][k] * tmp._vectors[k][j];
                }
            }
        }

        return A;
    }

    Matrix operator/(Matrix& tmp) const {
        Matrix A = _vectors * tmp.Obratna_mat();
        return A;
    }

    /*T determinant(Matrix matr, size_t n) {

    if (_size != _vectors[0].Get_size()){
        throw "Error";
    }

    if (n == 1) {
        return _vectors[0][0];
    }
    if (n == 2) {
        return _vectors[0][0] * _vectors[1][1] - _vectors[0][1] * _vectors[1][0];
    }

    T det = 0;
    //Matrix minor = Matrix (_size-1, _vectors[0].Get_size()-1);
    Matrix minor = Matrix (n - 1, n - 1);
    for (int i = 0; i < n; i++) {
        int row = 0;
        for (int i = 1; i < n; i++) {
            int col = 0;
            for (int j = 0; j < n; j++) {
                if (col != j){
                    minor[row][col] = _vectors[i][j];
                    col++;
                }
                det += pow(-1,i) * _vectors[0][i] * determinant(minor, n - 1);
            }
            row++;
        }
        //det += sign * _vectors[0][i] * determinant(minor, n - 1);
    }

    return det;
    }*/

    Matrix Obratna_mat(){
        T det = Deter();
        if (det == 0){
            throw "error";
        }

        Matrix A = Matrix(_size, _vectors[0].Get_size());

        if (_size != _vectors[0].Get_size()){
            throw "error";
        }

        for(size_t i = 0;i < _size;i++){
            for(size_t j = 0;j < _vectors[0].Get_size();j++){
                Matrix minor = Minor(i,j);
                T minorDet = minor.Deter();
                T cof;
                if ((i + j) % 2 == 0){
                    cof = minorDet;
                }
                else{
                    cof = -minorDet;
                }
                A[j][i] = cof / det;
            }

        }
        
        return A;

    }

    Matrix Tranposition(){
        Matrix A = Matrix (_vectors->Get_size(), _size);
        for (int i = 0; i < _vectors->Get_size(); i++){
            for (int j = 0; j < _size; j++){
                A[i][j] = _vectors[j][i];
            }
        }
        return A;
    }

    T Deter(){
        if (_size != _vectors[0].Get_size()){
            throw "Error";
        }

        if (_size == 1){
            return _vectors[0][0];
        }

        else{
            T det = 0;
            for (int i = 0; i < _vectors[0].Get_size(); i++){
                Matrix mino = Minor(0, i);
                //std::cout << mino << std::endl;
                det += pow(-1, i) * _vectors[0][i] * mino.Deter();
            }
            return det;
        }
    }

    Matrix Minor(size_t ro, size_t co) const{
        Matrix result = Matrix (_size - 1, _vectors[0].Get_size() - 1);
        int row = 0;
        for (int i = 0; i < _size - 1; i++){
            int col = 0;
            if (i == ro){
                row = 1;
            }
            for (int j = 0; j < _vectors[0].Get_size(); j++){
                if (j == co){
                    col = 1;
                }
                int kr = i;
                int kl = j;
                if (row != 0){
                    kr = i + 1;
                }
                if (col != 0){
                    kl = j + 1;
                }
                result[i][j] = _vectors[kr][kl];
            }
        }
        return result;
    }

    void RandomFill(Matrix& matr) {
        /*for (size_t i = 0; i < matr._size; i++) {
            for (size_t j = 0; j < matr._vectors[i].Get_size(); j++) {
                matr._vectors[i][j] = j + i;
            }
        }*/
    }

    Matrix& operator=(const Matrix& matr){
        if (_size != matr._size || _vectors[0].Get_size() != matr._vectors[0].Get_size()){
            throw "Error";
        }
        _size = matr._size;
        for (int i = 0; i < _size; i++){
            for (int j = 0; j < _vectors[0].Get_size(); j++){
                _vectors[i][j] = matr._vectors[i][j];
            }
        }
        return *this;
    }

    ~Matrix (){
        delete [] _vectors;
    }
    
    /*(&)меняем сам объект, а не копию !!*/
    Vector<T>& operator[](int index){ /*достучаться до каждого вектора и каждого индекса*/ return _vectors[index];}

    friend std:: ostream& operator<< (std:: ostream& os, const Matrix& matr){ for (size_t i = 0; i < matr._size; i++){ os << matr._vectors[i] << std:: endl; } return os;}
};