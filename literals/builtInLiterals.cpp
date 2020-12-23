#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

int main(){
    typedef std::chrono::duration<long long, std::ratio<2700>> hour;
    auto schoolHour = hour(1); //represent 45 minutes (schoolHour = 45min;)
    auto shortBreak = 300s;
    auto longBreak = 0.25h;
    auto schoolWay = 15min;
    auto homeWork = 2h;

    /*  as we converted all distance to meter in MyDistance, chrono
        all time intervals into seconds internally
    */
    auto schoolDayInSeconds = 6*schoolHour + 4*shortBreak + longBreak + 2*schoolWay + homeWork;
    std::cout << "School days in seconds: " << schoolDayInSeconds.count() << std::endl;

    std::chrono::duration<double, std::ratio<3600>> schoolDayInHours = schoolDayInSeconds;
    std::chrono::duration<double, std::ratio<60>> schoolDayInMinutes = schoolDayInSeconds;
    std::chrono::duration<double, std::ratio<1, 1000>> schoolDayInMilliseconds = schoolDayInSeconds;

    std::cout << "School days in hours: " << schoolDayInHours.count() << std::endl;
    std::cout << "School days in minutes: " << schoolDayInMinutes.count() << std::endl;
    std::cout << "School days in milliseconds: " << schoolDayInMilliseconds.count() << std::endl;
    
    return 0;
}