#include <iostream>

class HumanBeing {
    public:
        explicit HumanBeing(std::string name_): name(name_){}
        HumanBeing(HumanBeing&) = delete;

        const std::string& getName() const{
            return name;
        }

        void setName(std::string name_){
            name = std::move(name_);
        }

    private:
        std::string name;
};

class Man: public HumanBeing{
    public:
        explicit Man(std::string name_): HumanBeing(name_), gender("Man"){}
        Man(Man&) = delete; 

        const std::string& getGender() const{
            return gender;
        }

    private:
        std::string gender;
};

class Woman: public HumanBeing{
    public:
        explicit Woman(std::string name_): HumanBeing(name_), gender("Woman"){}
        Woman(Woman&) = delete;
        
        const std::string& getGender() const{
            return gender;
        }

    private:
        std::string gender;
};

int main(){

    Man man("Andre");
    std::cout << "Name: " << man.getName() << ", " << man.getGender() << std::endl;
    man.setName("Andre Scrhool");
    std::cout << "Name: " << man.getName() << ", " << man.getGender() << std::endl;
    return 0;
}