#include <iostream>
#define CONCAT(a, b) a b

int main() {
    const char* outfile_name = "123";
    const char* extension = ".replace";
    const char* outfile_path = CONCAT(outfile_name, extension);
    std::cout << outfile_path << std::endl;
    return 0;
}