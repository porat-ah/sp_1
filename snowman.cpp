#include "snowman.hpp"
#include <string>
#include <stdexcept>
#include <iostream> 
#include <array>

using namespace std;
namespace ariel
{
    void check(int code){
        const int MIN_CODE = 11111111;
        const int MAX_CODE = 44444444;
        if (code <MIN_CODE || code > MAX_CODE)
        {
            throw std::invalid_argument{"code length incorrect "};
        }
    }
    //HNLRXYTB
    // HHHHH
    // HHHHH
    //X(LNR)Y
    //X(TTT)Y
    // (BBB)
    string snowman(int code){
        check(code);
        const int MIN_NUM_MINUS_1 = 0;
        const int MAX_NUM_MINUS_1 = 3;
        const int INIT = 0;
        const int TEN = 10 ;
        const int CODE_LEN = 8;
        array<int , CODE_LEN> HNLRXYTB = {};
        int _code = code;
        for (int i = CODE_LEN -1; i > -1; --i)
        {
            HNLRXYTB.at(i) = (code %TEN) -1;
            if ( HNLRXYTB.at(i) < MIN_NUM_MINUS_1 || HNLRXYTB.at(i) > MAX_NUM_MINUS_1)
            {
                throw invalid_argument{ " Invalid code " + to_string(_code) };
            }
            code /= TEN;
        }
        const array<array<string,4>,10> parts = {{
            {" _===_ ","  ___ \n ..... ","   _\n  /_\\","  ___\n (_*_)"},// hats - H
            {",",".","_"," "},//nose - N
            {"(.","(o","(O","(-"},//left eye - L
            {".)","o)","O)","-)"},//right eye - R
            {"\n<","\n ","\n/","\n "},//left arm - X
            {">"," ","\\"," "},//right arm - Y
            {"( : )","(] [)","(> <)","(   )"},//torso - T
            {"\n ( : )","\n (\" \")","\n (___)","\n (   )"},//base - B
            {"\n ","\n\\","\n ","\n "},// second left arm 
            {" ", "/", " ", " "}// second right arm
        }};
        const array<int,10> order = {0,8,2,1,3,9,4,6,5,7};
        const array<int,10> part_order = {0,4,2,1,3,5,4,6,5,7};
        string out;
        for (size_t i = INIT; i < TEN; i++)
        {
            int part =  HNLRXYTB.at(part_order.at(i));
            out += parts.at(order.at(i)).at(part);
        }
        return out;
    }
} 
