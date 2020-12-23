//hacky way to protect main from getting included
#define USER_DEFINED_LITERAL
#include ".\userDefinedLiterals.cpp"

namespace Distance::Unit{
    MyDistance operator"" _ft(long double val){
        return MyDistance(val*0.3048);
    }

    MyDistance operator"" _mi(long double val){
        return MyDistance(val*1609.344);
    }
}

int main(){
    std::cout << "5 miles: " << 5.0_mi << std::endl;

    return 0;
}