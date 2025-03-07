#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>

int main() {
    const int totalFiles = 100000;
    const int batchSize = 1000;

    std::vector<std::ofstream> files;
    files.reserve(batchSize);

    for (int i = 0; i < totalFiles; i += batchSize) {
        for (int j = 0; j < batchSize; ++j) {
            std::ofstream file("file_" + std::to_string(i + j) + ".txt");
            if (file.is_open()) {
                files.push_back(std::move(file));
            } else {
                std::cerr << "Failed to open file: file_" << (i + j) << ".txt" << std::endl;
            }
        }
        std::cout << "Opened " << (i + batchSize) << " files." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        files.clear();
    }

    return 0;
}
