#include "snowman.hpp"
#include <string>
#include <stdexcept>
#include <iostream> 
#include <array>

namespace ariel
{
    std::string snowman(int code){
        const int PART_NUMBER = 7 ;
        const int SNOWMAN_LEN = 10 ;
        const int CODE_LEN = 8;
        const int MIN_CODE = 11111111;
        const int MAX_CODE = 44444444;
        const int MIN_NUM_MINUS_1 = 0;
        const int MAX_NUM_MINUS_1 = 3;
        const int INIT = 0;
        const int TEN = 10 ;
        const int RIGHT_ARM = 5 ;
        const int RIGHT_ARM_REPLACE = 8 ;
        const int LEFT_ARM = 4;
        const int LEFT_ARM_REPLACE = 9 ;

        if (code <MIN_CODE || code > MAX_CODE)
        {
            throw std::invalid_argument{"code length incorrect "};
        }
        //HNLRXYTB
        // HHHHH
        // HHHHH
        //X(LNR)Y
        //X(TTT)Y
        // (BBB)
        const std::array<std::array<std::string,4>,8> parts = {{
            {" _===_ ","  ___ \n ..... ","   _\n  /_\\","  ___\n (_*_)"},// hats - H
            {",",".","_"," "},//nose - N
            {"(.","(o","(O","(-"},//left eye - L
            {".)","o)","O)","-)"},//right eye - R
            {"\n<","\n\\","\n/","\n "},//left arm - X
            {">","/","\\"," "},//right arm - Y
            {"( : )","(] [)","(> <)","(   )"},//torso - T
            {"\n ( : )","\n (\" \")","\n (___)","\n (   )"}//base - B
        }};
        int part_type = INIT;
        int part = PART_NUMBER;
        std::array<std::string,SNOWMAN_LEN> snowman;
        for (size_t i = INIT; i < CODE_LEN; i++)
        {
            part_type = code %TEN -1;
            if (part_type < MIN_NUM_MINUS_1 || part_type > MAX_NUM_MINUS_1)
            {
                throw std::invalid_argument{ " Invalid code " + std::to_string(code) };
            }
            
            code /= TEN;
            snowman.at(part) = parts.at(part).at(part_type);
            part--;
        }
        if (snowman.at(RIGHT_ARM) == "/" )
        {
            snowman.at(RIGHT_ARM_REPLACE) = "/";
            snowman.at(RIGHT_ARM) = " ";
        }
        else
        {
            snowman.at(RIGHT_ARM_REPLACE) = " ";
        }
        if (snowman.at(LEFT_ARM) == "\n\\" )
        {
            snowman.at(LEFT_ARM_REPLACE) = "\n\\";
            snowman.at(LEFT_ARM) = "\n ";
        }
        else
        {
            snowman.at(LEFT_ARM_REPLACE) = "\n ";
        }
        const std::array<int,10> order = {0,9,2,1,3,8,4,6,5,7};
        std::string out;
        for (size_t i = INIT; i < TEN; i++)
        {
            out += snowman.at(order.at(i));
        }
        return out;
    }
} 
