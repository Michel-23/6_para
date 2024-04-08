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
            _vectors[i] = Vector<T> (cols);
        }
    }

    ~Matrix (){
        delete [] _vectors;
    }

    Vector<T>& /*(&)меняем сам объект, а не копию !!*/ operator[](int index){// достучаться до каждого вектора и каждого индекса
        return _vectors[index];
    }

    friend std:: ostream& operator<< (std:: ostream& os, const Matrix& matr){
        for (size_t i = 0; i < matr._size; i++){
            os << matr._vectors[i] << std:: endl;
        }
        return os;
    }
};