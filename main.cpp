#include <iostream>
#include <fstream>
#include <string>
#include "timeOfDay.h"
#include "alarm.h"
#include <sstream>

namespace LeeTaerin2276249 {

    // void printvectorArray..? 없음. 7/15강의

    void readWriteTimeFile(std::ifstream& fin, std::ofstream& fout) {
        
        std::vector<timeOfDay> v;
        timeOfDay t;

        std::streambuf* origBuf{ std::cout.rdbuf() };
        std::cout.rdbuf(nullptr);
        while (fin >> t) {
            v.push_back(t);
        }
        for (const auto& vi : v) {
            fout << vi << '\n';
        }
    }

    void parsingAlarm(std::iostream& io)     //std::iostream ->std::stringstream,std::fstream 상속받음
    {
        alarm a;
        
        std::streambuf* origBuf{ std::cout.rdbuf() };
        std::cout.rdbuf(nullptr);
        io >> a; //alarm의 입력연산자
        std::cout.rdbuf(origBuf);

        io.clear();
        io.seekp(0, std::ios::end);

        io << a;//alarm의 출력연산자
    }
}

int main() {
    using namespace LeeTaerin2276249;

    // std::ifstream fin{"timeData.txt"};
    // if (!fin.fail()) {
    //     std::cout << "Input file open failed.\n";
    //     std::exit(1);
    // }

    // std::ofstream fout;
    // std::string fileName;
    // std::cout << "Enter out file name: ";
    // std::cin >> fileName;
    // fout.open(fileName + ".txt");

    // if (!fout.fail()) {
    //     std::cout << "Input file open failed.\n";
    //     std::exit(1);
    // }

    // readWriteTimeFile(fin, fout);

    // fin.close();
    // fout.close();

    std::stringstream ss;
    std::string ad{"morning\n7 0\n1\n"};
    ss << ad; //std::cout << ad;
    parsingAlarm(ss); //io = ss;
    std::cout << ss.str() << '\n';
    std::fstream f{"alarmData.txt"};
    if (fs.fail())
    {
        std::cout<<"file open failed\n";
        std::exit(1);
    }
    parsingAlarm(fs);
    
    return 0;
}