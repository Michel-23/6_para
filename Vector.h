#include <iostream>

template<typename T>
class Vector{
private:
    T* _array;
    size_t _size;
public:
    Vector() = delete;
    Vector(size_t size, T* array) {
        _size = size;
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = array[i];
        }
    }

    Vector(size_t size): _size(size){ // присваивание значений полям класса - инициализирующий список
    _array = new T[size];
        for (int i = 0; i < _size; i++){
            _array[i] = 0;
        }
    }

    Vector(std:: initializer_list<T> list){
        _size = list.size();
        _array = new T[_size];
        int i = 0;
        for (auto elem = list.begin(); elem != list.end(); elem ++, i++){
            _array[i] = *elem;
        }
    }

    ~Vector(){
        delete [] _array;
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