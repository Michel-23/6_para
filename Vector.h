#include <iostream>
#include <cmath>

template /*для абстрактного типа данных*/<typename /*тип данных*/T>
class Vector{
private:
    T* _array;
    //double* _norm;
    size_t _size;
public:
    Vector(){
        _size = 10; 
        _array = new T[_size];
        //_norm = new double [_size];
    }
    Vector(size_t size, T* array) { // просто конструктор
        _size = size;
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = array[i];
        }
        //_norm = new double [_size];
    }

    size_t Get_size(){
        return _size;
    }

    Vector (const Vector& tmp){ // конструктор копирования
        _size = tmp._size;
        _array = new T[_size];
        //_norm = new double [_size];
        for (int i = 0; i < _size; i++){
            _array[i] = tmp._array[i];
        }
    }

    double Lengg(){
        double leng = 0;
        for (int i = 0; i < _size; i++){
            leng += _array[i]*_array[i];
        }
        leng = sqrt(leng);
        return leng;
    }

    /*Vector normaliz (){
        double len = this->Lengg();
        for (int i = 0; i < _size; i++){
            _norm[i] = _array[i] / len;
        }
        return Vector (_size, _norm);
    }*/

    Vector(size_t size): _size(size){ // присваивание значений полям класса - инициализирующий список
    _array = new T[size];
        for (int i = 0; i < _size; i++){
            _array[i] = 0;
        }
    }

    Vector operator+ (const Vector& tmp) const{
        T* array = new T[_size];
        for (int i = 0; i < _size; i++){
            array[i] = _array[i] + tmp._array[i];
        }
        Vector A = Vector (_size, array);
        delete [] array;
        return A;
    }

    Vector operator- (const Vector& tmp) const{
        T* array = new T[_size];
        for (int i = 0; i < _size; i++){
            array[i] = _array[i] - tmp._array[i];
        }
        Vector A = Vector (_size, array);
        delete [] array;
        return A;
    }

    double operator* (const Vector& tmp) const{
        T* array = new T[_size];
        double rez = 0;
        for (int i = 0; i < _size; i++){
            array[i] = _array[i] * tmp._array[i];
            rez += array[i]; 
        }
        Vector A = Vector (_size, array);
        delete [] array;
        return rez;
    }

    Vector(std:: initializer_list<T> list){ // конструктор принимающий список инициализации list=список
        _size = list.size();
        _array = new T[_size];
        //_norm = new double [_size];
        int i = 0;
        for (auto elem = list.begin(); elem != list.end(); elem ++, i++){
            _array[i] = *elem;
        }
    }

    ~Vector(){
        delete [] _array;
        //delete [] _norm;
    }

    Vector& operator=(const Vector& tmp){ // !!!
        if (tmp._size > _size){
            delete [] _array;
            _array = new T[tmp._size];
        }
        _size = tmp._size;
        for (size_t i = 0; i < _size; i++){
            _array [i] = tmp._array[i];
        }

        return *this;
    }

    /*const возвращаем только константную ссылку*/T& operator[] (int i) /*const действует  напрямую на объекты указателя*/{
        return _array[i];
    }

    friend std:: ostream& operator<<(std::ostream& os, const Vector& vec){
        os << "(";
        for (int i = 0; i < vec._size; i++){
            os << vec._array[i];
            if (i + 1 != vec._size)
                os << ", ";
        }
        os << ")";
        return os;
    }
};