#include <iostream>

using namespace std;

template <typename T>
class Vector{
    private:
        T *data;
        int capacity;
        int size;

        void resize(unsigned int new_capacity){
            T *new_data = new T[new_capacity];
            for (int i = 0; i < size; i++){
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }

    public:
        // default constructor
        Vector(): data(nullptr), capacity(0), size(0){}

        // destructor
        ~Vector(){
            if(data){
                delete[] data;
            }
        }

        // copy constructor
        Vector(const Vector& vec){
            this->size = vec.size;
            this->capacity = vec.capacity;
            this->data = new T[this->capacity];

            // now I have to copy all the data into this new vector
            for (int i = 0; i < size; i++){
                data[i] = vec.data[i];
            }
        }

        // move constructor
        Vector(Vector&& vec){
            this->size = vec.size;
            this->capacity = vec.capacity;
            this->data = vec.data;

            // now vec's job is done, I'm gonna kill it :(
            vec.capacity = 0;
            vec.size = 0;
            vec.data = nullptr;
        }

        // copy assignment operator overloading
        Vector& operator=(const Vector& vec){
            if(this != &vec){
                delete[] data;
                capacity = vec.capacity;
                size = vec.size;
                data = new T[this->capacity];

                for (int i = 0; i < size; i++){
                    data[i] = vec.data[i];
                }
            }
            return *this;
        }

        // [] operator overloading
        T& operator[](unsigned int index){
            if(index >= size){
                throw std::out_of_range("Index out of the range.");
            }
            return data[index];
        }

        void pop_back(){
            if(size > 0)
                size--;
        }

        void push_back(const T& value){
            if(size == capacity){
                resize(capacity == 0 ? 1 : capacity * 2);
            }
            data[size++] = value;
        }

        int get_size(){
            return size;
        }

        int get_capacity(){
            return capacity;
        }

        bool is_empty(){
            return size == 0;
        }

        friend ostream& operator<<(ostream& out,const Vector<T>& vect){
            for (int i = 0; i < vect.size; i++){
                out << vect.data[i] << " ";
            }
            return out;
        }
};

int main(){
    Vector<int> v1;
    
}