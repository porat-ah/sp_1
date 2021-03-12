#include "snowman.hpp"
#include <string>
#include <stdexcept>
#include <iostream> 

namespace ariel
{
    std::string snowman(int code){
        if (code <11111111 || code > 44444444)
        {
            throw std::invalid_argument{"code length incorrect "};
        }
        //HNLRXYTB
        //33232124
        // HHHHH
        // HHHHH
        //X(LNR)Y
        //X(TTT)Y
        // (BBB)
        std::string parts [8][4] = {
            {" _===_ ","  ___ \n ..... ","   _\n  /_\\","  ___\n (_*_)"},// hats - H
            {",",".","_"," "},//nose - N
            {"(.","(o","(O","(-"},//left eye - L
            {".)","o)","O)","-)"},//right eye - R
            {"\n<","\n\\","\n/","\n "},//left arm - X
            {">","/","\\"," "},//right arm - Y
            {"( : )","(] [)","(> <)","(   )"},//torso - T
            {"\n ( : )","\n (\" \")","\n (___)","\n (   )"}//base - B
        };
        int part_type;
        int part = 7;
        std::string snowman[10];
        for (size_t i = 0; i < 8; i++)
        {
            part_type = code %10 -1;
            if (part_type < 0 || part_type > 3)
            {
                throw std::invalid_argument{ " Invalid code " + std::to_string(code) };
            }
            
            code /= 10;
            snowman[part] = parts[part][part_type];
            part--;
        }
        if (snowman[5] == "/" )
        {
            snowman[8] = "/";
            snowman[5] = " ";
        }
        else
        {
            snowman[8] = " ";
        }
        if (snowman[4] == "\n\\" )
        {
            snowman[9] = "\n\\";
            snowman[4] = "\n ";
        }
        else
        {
            snowman[9] = "\n ";
        }

        //33232124
        
        int order[] = {0,9,2,1,3,8,4,6,5,7};
        std::string out = "";
        for (size_t i = 0; i < 10; i++)
        {
            out += snowman[order[i]];
        }
        return out;
    }
} 
