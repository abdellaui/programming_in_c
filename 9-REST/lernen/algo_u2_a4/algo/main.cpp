#include <iostream>
#include "levensheit.h"


int main()
{
 std::string original = "head";
 std::string katze = "cat";
 int result = levenshtein_distance(original, katze);
 std::cout << result;
    return 0;
}
