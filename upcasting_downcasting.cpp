#include <iostream>


class Animal{
    public:
        virtual void makeSound(){
            std::cout << "animal Sound" << std::endl;
        }
};

class Dog: public Animal{
    public:
        void makeSound(){ // over-riding
            std::cout << "Bark" << std::endl;
        }

        void wagTail(){
            std::cout << "wagging heavily" << std::endl;
        }
};

int main(){
    Dog dog;
    Animal *animalptr = &dog; // upcasting
    animalptr->makeSound(); // bark

    Dog *dogptr = dynamic_cast<Dog*>(animalptr); // this is for downcasting
    if(dogptr)dogptr->wagTail();
    else{
        std::cout << "downcasting failed" << std::endl;
    }
}

// below given main will produce failed downcasting

// int main(){
//     Dog dog;
//     Animal *animalptr = new Animal(); // upcasting
//     animalptr->makeSound(); // bark

//     Dog *dogptr = dynamic_cast<Dog*>(animalptr);
//     if(dogptr)dogptr->wagTail();
//     else{
//         std::cout << "downcasting failed" << std::endl;
//     }

//     delete animalptr;
// }