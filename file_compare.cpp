#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string file1;
    std::string file2;
    std::cin >> file1;
    std::cin >> file2;

    std::ifstream file1Stream(file1);
    if (!file1Stream.is_open()) {
        std::cerr << "Failed to open file: " << file1 << std::endl;
        return 1;
    }
    std::ifstream file2Stream(file2);
    if (!file2Stream.is_open()) {
        std::cerr << "Failed to open file: " << file2 << std::endl;
        return 1;
    }
    for (std::string line1, line2; std::getline(file1Stream, line1) && std::getline(file2Stream, line2);) {
        if (line1 != line2) {
            std::cerr << "Files are different." << std::endl;
            return 1;
        }
    }
    return 0;
}