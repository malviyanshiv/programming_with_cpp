#include "Vector.h"
#include <iostream>
#include <ostream>
#include <vector>

class CObject{
    public:
        CObject(): _x(0) {
            std::cout << "default contructor" << std::endl;
        }

        CObject(int x): _x(x){
            std::cout << "contructor" << std::endl;
        }

        CObject(CObject&& obj){
            std::cout << "move constructor" << std::endl;
            _x = obj._x;
        }

        CObject(CObject& obj){
            std::cout << "copy constructor" << std::endl;
            _x = obj._x;
        }

        void operator=(CObject&& obj){
            std::cout << "move assigment" << std::endl;
            _x = obj._x;
        }

        void operator=(CObject& obj){
            std::cout << "copy assignment" << std::endl;
            _x = obj._x;
        }

        ~CObject(){
            std::cout << "destructor" << std::endl;
        }

        friend std::ostream& operator<<(std::ostream& out, CObject& data){
            out << data._x;
            
            return out;
        }
    private:
        int _x;
};

void Print(Vector<CObject>& vec){
    for(int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";

    std::cout << std::endl;
    
    return;
}

int main(){

    Vector<CObject> cVector;

    cVector.push_back(1);
    cVector.push_back(CObject(2));
    cVector.emplace_back(4);
    cVector.pop_back();
    cVector.emplace_back(3);

    for(auto& e : cVector)
        std::cout << e << std::endl;

    std::cout << std::endl;
    for(Vector<CObject>::Iterator cur = cVector.begin(); cur != cVector.end(); cur++)
        std::cout << *cur << std::endl;

    return 0;
}