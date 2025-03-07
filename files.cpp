#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    vector<string> filenames = {"bolvsanka1", "bolvanka2", "bolvanka3"};

    vector<ofstream> open_files;
    for (const auto& filename : filenames) {
        open_files.emplace_back(filename);
        if (open_files.back().is_open()) {
            cout << "Opened " << filename << " successfully." << endl;
            this_thread::sleep_for(chrono::seconds(15));
        } else {
            cerr << "Failed to open " << filename << endl;
        }
    }

    return 0;
}