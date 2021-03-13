#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <stdexcept>
using namespace std;

string nospace(string input){
    string out ;
    for (size_t i = 0; i < input.length(); i++)
    {
        char at = input.at(i);
        if(at != '\n' && at != ' ' && at != '\t' && at != '\r'){
            out += at;
        }
    }
    return out;
}

TEST_CASE("Good input"){
    //1
    CHECK(nospace(snowman(11111111)) == nospace(string("_===_\n(.,.)\n<( : )>\n( : )")));
    //2
    CHECK(nospace(snowman(22222222)) == nospace(string(" ___\n.....\n\\(o.o)/\n (] [)\n (\" \")")));
    //3
    CHECK(nospace(snowman(33333333)) == nospace(string("  _\n /_\\\n (O_O)\n/(> <)\\\n (___)")));
    //4
    CHECK(nospace(snowman(44444444)) == nospace(string(" ___\n(_*_)\n(- -)\n(   )\n(   )")));
    //5
    CHECK(nospace(snowman(11114411)) == nospace(string("_===_\n(.,.)\n( : )\n( : )")));
    //6
    CHECK(nospace(snowman(33232124)) == nospace(string("   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )")));
    //7
    CHECK(snowman(33232124) != "");
}

TEST_CASE("bad input"){
    // short input
    int right_len = 8;
    int input;
    //8 - 15
    for (size_t i = 1; i < right_len; i++)
    {
        input = 0;
        for (size_t j = 0; j < i; j++)
        {
            input *=10;
            ++input;
        }
        CHECK_THROWS(snowman(input));
    }
    // long input
    //15-19
    for (size_t i = right_len+1; i <= 12; i++)
    {
        input = 0;
        for (size_t j = 0; j <= i; j++)
        {
            input *=10;
            ++input;
        }
        CHECK_THROWS(snowman(input));
    }
    // more then 4 
    //19 - 24
    int start = 11110000;
    int end = 111;
    for (size_t i = 5; i < 10; i++)
    {
        CHECK_THROWS(snowman(start + end + i*1000));
    }
    //all more then 4 
    //25
    CHECK_THROWS(snowman(55555555));
    //26
    CHECK_THROWS(snowman(66666666));
    //27
    CHECK_THROWS(snowman(77777777));
    //28
    CHECK_THROWS(snowman(88888888));
    //29
    CHECK_THROWS(snowman(99999999));
    //30 check type of execption for more then 4 input 
    CHECK_THROWS_AS(snowman(66666666),invalid_argument);
    // 31 check type of execption for short input 
    CHECK_THROWS_AS(snowman(1111),invalid_argument);
    // 32 check type of execption for long input 
    CHECK_THROWS_AS(snowman(111111111),invalid_argument);
}


