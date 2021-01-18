// Copyright 2021 Bekusov Mikhail

#include <iostream>
#include "postfix.h"

int main() {
    std::cout << infix2postfix("(1 + 200)") << std::endl;
    std::cout << infix2postfix("(10 + 10 + 10 * 10)") << std::endl;
    std::cout << infix2postfix("550 - 362 * 152 + 250") << std::endl;
    std::cout << infix2postfix("564 + 62 * 15 / 65 - 56 / 51") << std::endl;
    std::cout << infix2postfix("(564 + 62) * 15 / (65 - 56) / 51") << std::endl;
    std::cout << infix2postfix("(52 * (15 - 25) / (36 + 43))") << std::endl;
    std::cout << infix2postfix("52 * 15 - 25 / 36 + 43 - 85 * 250") << std::endl;
    return 0;
}
