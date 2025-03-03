## Virtual Inheritance

- this is done to resolve the classic problem, Diamond problem 
```cpp
class person{
    int property;
};

class emp: public person{
    int something;
};

class teacher: public emp, virtual public person{ // this is virtual inheritance, this will only include those things which are not there in the base class EMP
    // some code 
}
```