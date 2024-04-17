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
            for (int j = 0; j < _vectors[0].Get_size(); j++) {
                for (int k = 0; k < tmp._vectors[0].Get_size(); k++) {
                    A[i][j] += _vectors[i][k] * tmp._vectors[k][j];
                }
            }
        }

        return A;
    }

    Matrix operator/(Matrix matr) const {
        Matrix A = _vectors * matr.Tranposition();
        return A;
    }

    

    Matrix Tranposition(){
        Matrix mat = Matrix (_vectors->Get_size(), _size);
        for (int i = 0; i < _vectors->Get_size(); i++){
            for (int j = 0; j < _size; j++){
                mat[i][j] = _vectors[j][i];
            }
        }
        return mat;
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

    matrix inverse_matrix(){ // 1 метод
        T det=determinant();
        if (det==0)
        throw "inverse matrix doesnt exist";
        matrix m=matrix(_size, _size);
        for(size_t i=0;i<_size;i++){
            for(size_t j=0;j<_size;j++){
                m[i][j]=new_m(i,j).determinant();
                if((i+j)%2==1&&m[i][j]!=0)
                m[i][j]*=-1;
            }

        }
        matrix m1=m.transpose();
        double x=1.0/det;
        return m1*x;

    }

    matrix<double> reverse_matrix(){ // 2 метод
        if (this->determinant() == 0){
            std::cout<<"matrix viragdena"<<std::endl;
            throw 1;
        }
        matrix<double> new_matrix = matrix<double>(_size);
        for (int i = 0 ; i < _size; i++){
            for (int j = 0; j < _size; j++){
                matrix dop_matrix = matrix(_size - 1);
                int rows = 0;
                for (int k = 0; k < _size; k++){
                    if (k == j){
                        continue;
                    }
                    int cols = 0;
                    for (int l = 0; l < _size; l++){
                        if (l == i){
                            continue;
                        }
                        dop_matrix[rows][cols] = _vectors[k][l];
                        cols += 1;
                    }
                    rows += 1;
                }
                new_matrix[i][j] = pow(-1, j + i) * dop_matrix.determinant();
            }
        }
        new_matrix = new_matrix / this->determinant();
        return new_matrix;
    }

    matrix operator*(const matrix& matr)const{ // перегруз умножения
        size_t s=_vectors[0].getsize();
        size_t s1=matr._vectors[0].getsize();
        if(s!=matr._size)
        throw "sizes are different";
        matrix mat=matrix(_size,s1);
        for(size_t i=0; i<_size; i++){
            for(size_t j=0; j<s1;j++){
                for(int k=0; k<_size; k++){
                int temp = _vectors[i][k]*matr[k][j];
                mat[i][j] += temp;
                temp = 0;
                }
            
            }

        }
        return mat;
    }

    T Deter(){
        if (_size != _vectors->Get_size()){
            std:: cout << "Matrix: Error input";
            throw 0;
        }

        if (_size == 1){
            return _vectors[0][0];
        }

        else{
            T det = 0;
            for (int i = 0; i < _vectors->Get_size(); i++){
                Matrix min = Minor(0, i);
                det += pow(-1, i) * _vectors[0][i] * min.Deter();
            }
            return det;
        }
    }

    Matrix Minor(size_t ro, size_t co) const{
        Matrix res = Matrix (_size - 1, _vectors->Get_size() - 1);
        int row = 0;
        for (int i = 0; i < _size - 1; i++){
            int col = 0;
            if (i == ro){
                row = 1;
            }
            for (int j = 0; j < _vectors->Get_size(); j++){
                if (i == co){
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
                res[i][j] = _vectors[kr][kl];
            }
        }
        return res;
    }

    void RandomFill(Matrix& matr) {
        /*for (size_t i = 0; i < matr._size; i++) {
            for (size_t j = 0; j < matr._vectors[i].Get_size(); j++) {
                matr._vectors[i][j] = j + i;
            }
        }*/
        matr._vectors[0][0] = 1;
        matr._vectors[0][1] = 2;
        matr._vectors[0][2] = 3;
        matr._vectors[0][3] = 4;
        matr._vectors[1][0] = 5;
        matr._vectors[1][1] = 6;
        matr._vectors[1][2] = 7;
        matr._vectors[1][3] = 8;
        matr._vectors[2][0] = 9;
        matr._vectors[2][1] = 1;
        matr._vectors[2][2] = 2;
        matr._vectors[2][3] = 3;
        matr._vectors[3][0] = 4;
        matr._vectors[3][1] = 5;
        matr._vectors[3][2] = 6;
        matr._vectors[3][3] = 5;
    }

    ~Matrix (){
        delete [] _vectors;
    }
    
    /*(&)меняем сам объект, а не копию !!*/
    Vector<T>& operator[](int index){ /*достучаться до каждого вектора и каждого индекса*/ return _vectors[index];}

    friend std:: ostream& operator<< (std:: ostream& os, const Matrix& matr){ for (size_t i = 0; i < matr._size; i++){ os << matr._vectors[i] << std:: endl; } return os;}
};