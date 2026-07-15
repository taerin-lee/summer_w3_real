#pragma once
#include <iostream>
#include <string>
#include "timeOfDay.h"

namespace LeeTaerin2276249 {

    class alarm {
    private:
        std::string name;
        timeOfDay wakeTime;
        bool inActive; 

    public:
        alarm(const std::string& n = "no name yet", timeOfDay t = timeOfDay(0, 0), bool a = false) 
            : name{n}, wakeTime(t), inActive(a) {}

        void print() const {
            std::cout << name << ": ";
            wakeTime.print();
            std::cout << " alarm is " << (inActive ? "on" : "off") << "\n";
        }

        friend std::ostream& operator<<(std::ostream& os, const alarm& a) {
            os << a.name << ": ";
            os << a.wakeTime; //timeOfDay의 출력연산자
            os << " alarm is " << (a.inActive ? "on" : "off") << '\n';
            return os;
        }

        void input() {
            std::cout << "Enter alarm name: ";
            std::getline(std::cin >> std::ws, name); 
            wakeTime.input();
            std::cout << "Enter 1 or 0 (on/off): ";
            std::cin >> inActive;
        }

        friend std::istream& operator>>(std::istream& is, alarm& a) {
            std::cout << "Enter alarm name: ";
            std::getline(is >> std::ws, a.name); 
            is >> a.wakeTime;//timeOfDay의 입력연산자
            std::cout << "Enter 1 or 0 (on/off): ";
            is >> a.inActive;
            return is;
        }

        std::string getName() const { return name; }
        const timeOfDay& getWakeTime() const { return wakeTime; }
        bool getActive() const { return inActive; }
        
        void setName(const std::string& n) { name = n; }
        void setWakeTime(const timeOfDay& t) { wakeTime = t; }
        void setActive(bool b) { inActive = b; }
    };
}