#include "Vector.h"

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

    /*Matrix get_minor(size_t row, size_t col){
        Matrix minor = Matrix (_size-1, _vectors[0].Get_size()-1); // !!!
        int roww = 0;
        int coll = 0;
        for(int i = 0; i < _size; i++) {
            //Пропустить row-ую строку
            if(i == 0) {
                roww = 1; //Как только встретили строку, которую надо пропустить, делаем смещение для исходной матрицы
            }

            for(int j = 0; j < _vectors[0].Get_size(); j++) {
                //Пропустить col-ый столбец
                if(j == coll) {
                    coll += 1; //Встретили нужный столбец, проускаем его смещением
                }

                minor[i][j] = matrix[i + roww][j + coll];
            }
        }
        return minor;
    }*/

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

    /*Matrix operator+ (const Matrix& tmp) const{
        T* vectors = new Matrix<T>[_size];
        for (int i = 0; i < _size; i++){
            vectors[i] = _vectors[i] + tmp._vectors[i];
        }
        Matrix A = Vector (_size, vectors);
        delete [] vectors;
        return A;
    }*/

    double determinant(size_t n) {
    if (n == 1) {
        return _vectors[0][0];
    }

    int det = 0;
    int sign = 1;
    //Matrix minor = Matrix (_size-1, _vectors[0].Get_size()-1);
    Matrix minor = Matrix (n-1, n-1); // Здесь ошибка (подумать и спросить)

    for (int i = 0; i < n; i++) {
        int subi = 0;
        for (int row = 1; row < n; row++) {
            int subj = 0;
            for (int col = 0; col < n; col++) {
                if (col != i){
                    minor[subi][subj] = _vectors[row][col]; // (Visual Studio + C)' = (VS)
                    subj++;
                }
            }
            subi++;
        }
        det += sign * _vectors[0][i] * determinant(n - 1);

        sign *= -1;
    }

    return det;
    }

    ~Matrix (){
        delete [] _vectors;
    }

    void Completion_matrix(){
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                _vectors[i][j] = rand()%10;
            }
        }
    }

    
    /*(&)меняем сам объект, а не копию !!*/
    Vector<T>& operator[](int index){// достучаться до каждого вектора и каждого индекса
        return _vectors[index];
    }

    friend std:: ostream& operator<< (std:: ostream& os, const Matrix& matr){
        for (size_t i = 0; i < matr._size; i++){
            os << matr._vectors[i] << std:: endl;
        }
        return os;
    }
};