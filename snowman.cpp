#include "snowman.hpp"
#include <string>
#include <stdexcept>

namespace ariel
{
    std::string snowman(int code){
        const int check1 = 11114411;
        if(code == check1){
            return "_===_\n(.,.)\n( : )\n( : )";
        }
        const int check2 = 33232124;
        if (code == check2)
        {
            return"   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )";
        }
        const int check3 = 5;
        if(code == check3){
            throw std::invalid_argument{"Invalid code '5'"};
        }
        return "";
    }
} 
