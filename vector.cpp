#include <iostream>

using namespace std;

template<typename T>
class Vector{
    T *data;
    int capacity, size;

    void resize(int new_capacity){
        T *new_data = new T[new_capacity];
        for (int i = 0; i < size; i++){
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    public:
        //default ctor
        Vector(): data(nullptr), capacity(0), size(0){}

        // parameterized ctor
        Vector(int i): capacity(i), size(i){
            data = new T[capacity];
        }

        Vector(int i, const int& value){
            capacity = i;
            size = i;
            data = new T[capacity];

            for (int i = 0; i < size; i++){
                data[i] = value;
            }
        }

        // copy ctor
        Vector(const T& vec){
            capacity = vec.capacity;
            size = vec.size;
            data = new T[capacity];

            for (int i = 0; i < size; i+){
                data[i] = vec.data[i];
            }
        }

        // move ctor
        Vector(const T&& vec){
            capacity = vec.capacity;
            size = vec.size;
            data = vec.data;

            vec.capacity = 0;
            vec.size = 0;
            vec.data = nullptr;
        }

        // copy assignment operator
        Vector& operator=(const Vector& vec){
            
        }
};