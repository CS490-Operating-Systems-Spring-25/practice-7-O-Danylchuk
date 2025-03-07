#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>

using namespace std;

int main() {
    chrono::time_point<chrono::system_clock> start, end;
    string line;

    ofstream outfile("test.txt", ios_base::app);
    if (!outfile.is_open()) {
        cout << "Unable to open output file" << endl;
        return 1;
    }

    for (int i = 0; i < 1000; ++i) {
        line = i;
        outfile << line << endl;
        outfile.flush();
        this_thread::sleep_for(chrono::seconds(1));
    }
    
    return 0;
}