#include <iostream>

namespace Distance{
    class MyDistance{
        public:
            explicit MyDistance(const long double mDistance_) : mDistance(mDistance_){}

            friend MyDistance operator+(const MyDistance& lhs, const MyDistance& rhs){
                return MyDistance(lhs.mDistance + rhs.mDistance);
            }

            friend MyDistance operator-(const MyDistance& lhs, const MyDistance& rhs){
                return MyDistance(lhs.mDistance + rhs.mDistance);
            }

            friend std::ostream& operator<<(std::ostream& out, const MyDistance& myDistance){
                out << myDistance.mDistance << "_m";
                return out;
            }

        private:
            long double mDistance;
    };

    namespace Unit{
        //converting kilometer into meter
        MyDistance operator"" _km(long double val){
            return MyDistance(val*1000);
        }
        //converting meter into meter
        MyDistance operator"" _m(long double val){
            return MyDistance(val);
        }
        //converting decimeter into meter
        MyDistance operator"" _dm(long double val){
            return MyDistance(val/10);
        }
        //converting centimeter into meter
        MyDistance operator"" _cm(long double val){
            return MyDistance(val/100);
        }
    }
}

using namespace Distance::Unit;

//protecting main from getting included in others
#ifndef USER_DEFINED_LITERAL
int main(){
    
    std::cout << "1.0_km + 200.0_m + 900.0_dm + 90.0_cm : " << (1.0_km + 200.0_m + 900.0_dm + 90.0_cm) << std::endl;
    
    return 0;
}
#endif