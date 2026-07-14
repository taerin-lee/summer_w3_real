#include <iostream>
#include <fstream>
#include <string>
#include "timeOfDay.h"

namespace LeeTaerin2276249 {

    void readWriteTimeFile(std::ifstream& fin, std::ofstream& fout) {
        
        std::vector<timeOfDay> v;
        timeOfDay t;
        while (fin >> t) {
            v.push_back(t);
        }
        for (const auto& vi : v) {
            fout << vi << '\n';
        }
    }
} 

int main() {
    using namespace LeeTaerin2276249;

    std::ifstream fin{"timeData.txt"};
    if (!fin.fail()) {
        std::cout << "Input file open failed.\n";
        std::exit(1);
    }

    std::ofstream fout;
    std::string fileName;
    std::cout << "Enter out file name: ";
    std::cin >> fileName;
    fout.open(fileName + ".txt");

    if (!fout.fail()) {
        std::cout << "Input file open failed.\n";
        std::exit(1);
    }

    readWriteTimeFile(fin, fout);

    fin.close();
    fout.close();

    return 0;
}