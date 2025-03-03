#include <iostream>

class CustomString {
    public:
        //default constructor
        CustomString():res(nullptr), len(0){} // it is better to use initializer list because we don't have any parameter right now that's why
        /*
        What is a initializer list and why do we need it?
        it is used to initalize member variable of the class, in this class we don't need the 
        */

       // parameterized constructor
       CustomString(const char* param){ // here we have used const because look at the way we are passing the value `str2 = "hello"` this hello is a const and that's why we are giving it as const
           len = strlen(param);
           res = new char[len + 1]; // here I have given +1 for the character that represents ending of the string "\0"
           strcpy(res, param); // string copy will take care of the /0 and all
       }

        // copy constructor
       CustomString(const CustomString &param){ // in this case we are using const because `str3 = str1` the way we are taking this other string as an input, we don't want to accidently change it and thus we are giving it as const. We are passing by reference because, if we pass it by value it calls a copy constructor and for that it needs a copy constructor which is what we are writing in here :) so we need to pass it by reference. if we don't use & we will get an error.
           len = param.len; // here we can access len even though it is mentioned as private is because it is within the same class
           res = new char[len + 1];
           strcpy(res, param);
       }

       // move constructor
       CustomString(const CustomString &&param){
            // this && is passing rvalue reference
            len = str.len;
            res = str.res;
            str.res = nullptr;
            str.len = 0;
       }

       ~CustomString(){
         if(res){
             delete[] res;
             res = nullptr;
             len = 0;
         }
       }

       // copy assignment constructor
       CustomString& operator=(const CustomString& param){
        /*
        so for this we have to take care of a case where self is passed or basically 
        "str1 = str1" is not 
        */

        if (this != &param) // `this` refers to the object that has called the function, so lets say in our case str3 = str2; this referes to str3 as this object is calling the operator=.
        {
            delete[] res; //this line is being used here because res would already have string in it and we need to delete it before assingning new value or else this would result to memory leak. Delete in bracket is used because we have used an array of memory during the constructor call `res = new char[len + 1];`
            len = param.len;
            res = new char[len];
            strcpy(res, param.res);
        }
        return *this;
       }

       // This is another way to write this copy assignement operator
       CustomString& operator=(CustomString param){
            // here I already have the copy of param that was passed I just need to swap it it follows CAS(copy and swap idiom)
            swap(this, param);
            return *this;
       }

       swap(CustomString& str1, CustomString& str2){
           std::swap(str1.res, str2.res);
           std::swap(str1.len, str2.len);
       }

       unsigned int length(){
           return len;
       }

       friend std::ostream& operator<<(ostream &out, const CustomString &str); // have to make it a friend function as I'm trying to access private members in the definition of the string.
       friend std::istream& operator>>(istream &out, const CustomString &str);

   private:
       char *res;
       unsigned int len;
};

ostream& operator<<(ostream& out, const CustomString& str){
    /*
    for this goto https://youtu.be/uQB7jNWnZaI and then goto section "Output & Input, Operator overloading", this will clear it and its really good if you watch it!
    */

   /*
   Why Make the << Operator Overload Global?

    Left Operand Needs to Be a Standard ostream Object (std::cout):
        The << operator is commonly used for output, like std::cout << "Hello";. Here, the left operand (std::cout) is of type std::ostream.
        For operator overloading, if you were to define operator<< as a member function inside your custom string class, the left operand would have to be an instance of your class. In other words, myStringObject << std::cout; would be how you would use it, which is not what you want.
        To ensure the syntax works like std::cout << myStringObject;, the operator<< needs to be a non-member function where the first (left) operand can be std::ostream, and the second (right) operand can be your custom class.

    Ensures Compatibility with Standard Library Streams:
        The << operator must work seamlessly with standard library streams (like std::ostream). This is only possible if the function is defined globally, allowing the std::ostream object to be the left operand.
        By making it global, you allow the standard library to call your overloaded function without requiring a special instance of your class.
   */
    out << str.res;
    return out;
}

istream& std::operator>>(istream &in, CustomString &str){
    in >> str.res;
    return in;
}

int main(){
    CustomString str1; //default constructor
    CustomString str2 = "hello"; // parameterized constructor
    CustomString str3 = str1;    // copy constructor; CustomString str3(str1);
    str3 = str2;                 // copy assignment operator
    int len = str2.length();
    cout << str2; //overload <<
    cin >> str1; //overload >>

    CustomString str6 = std::move(str2); // move constructor
}

/*
difference between copy constructor and copy assingnment operator

copy constructor is called when the string is called for the first time while copy assignment operator is called when the string already exists and now we are assinging/re-assigning it.
*/

/*
CustomString str6 = std::move(str2); // move constructor

This line would call move constructor and this basically means that you move all the resources of the given object into the new object and you just die(well this die part depends upon the implementation)
*/