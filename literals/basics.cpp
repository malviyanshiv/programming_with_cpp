#include <iostream>

int main(){

    int hex = 0x24;
    std::string evaluated_string = "This is a\t\"evaluated string\"";
    std::string raw_string = R"(This is a\t\"raw string literal\")";
    std::cout << hex << std::endl;
    std::cout << evaluated_string << std::endl;
    std::cout << raw_string << std::endl;
    
    return 0;
}