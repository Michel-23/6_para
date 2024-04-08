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

    Matrix (const Matrix& tmp){ // конструктор копирования
        _size = tmp._size;
        _vectors = new Vector<T>[_size];
        for (int i = 0; i < _size; i++){
            _vectors[i] = tmp._vectors[i];
        }
    }

    Matrix get_minor(size_t row, size_t col){
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