#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip> //조작기

namespace LeeTaerin2276249 {

    class timeOfDay {
    private: 
        int hour{}; 
        int minute{};

        void testHour(int h) { 
            if (h < 0 || h > 23) {
                std::cout << "Wrong hour.\n";
                std::exit(1);
            }
        }

        void testMinute(int m) {
            if (m < 0 || m > 59) {
                std::cout << "Wrong minute.\n";
                std::exit(1);
            }
        }

    public:
        timeOfDay(int h = 0, int m = 0) : hour{h}, minute{m} { 
            testHour(h);
            testMinute(m);
        }

        void input() {
            int h, m;
            std::cout << "Enter hour(0~23): ";
            std::cin >> h;
            std::cout << "Enter minute(0~59): ";
            std::cin >> m;
            
            testHour(h);
            testMinute(m);
            hour = h;     
            minute = m;   
        }

        void setHour(int h) {
            testHour(h); 
            hour = h;
        }

        void setMinute(int m) {
            testMinute(m); 
            minute = m;
        }

        void print() const {
            if (hour < 10) std::cout << "0";
            std::cout << hour << ":";
            if (minute < 10) std::cout << "0";
            std::cout << minute;
        }

        int getHour() const { return hour; }
        int getMinute() const { return minute; }

        timeOfDay& operator++() {
            minute++;
            if (minute >= 60) {
                minute = 0;
                hour++;
                if (hour >= 24) { hour = 0; }
            }
            return *this; 
        }

        timeOfDay operator++(int) {
            timeOfDay temp = *this; 
            ++(*this); 
            return temp; 
        }

        timeOfDay& operator+=(int m) {
            minute += m;
            if (minute >= 60) {
                hour += minute / 60; 
                minute %= 60;
            }
            if (hour >= 24) { hour %= 24; }
            return *this;
        }

        friend std::istream& operator>>(std::istream& in, timeOfDay& t) {
            int h, m;
            // 파일스트림에서도 안전하게 동작하도록 공백이나 줄바꿈을 건너뛰며 읽음
            if (in >> h >> m) {
                t.testHour(h);
                t.testMinute(m);
                t.hour = h;
                t.minute = m;
            }
            return in;
        }

        friend std::ostream& operator<<(std::ostream& out, const timeOfDay& t) {

            // out << std::setw(2) << std::setfill('0') << t.hour << ":"
            // out << std::setw(2) << std::setfill('0') << t.minute; //조작기로 표현

            out.width(2); out.fill('0'); out << t.hour << ":"; 
            out.width(2); out.fill('0'); out << t.minute << ":"; //멤버함수로 표현
            

            return out;
        }

        friend bool operator==(const timeOfDay& t1, const timeOfDay& t2) {
            return (t1.hour == t2.hour) && (t1.minute == t2.minute);
        }

        friend timeOfDay operator+(const timeOfDay& t1, const timeOfDay& t2) {
            int totalMinutes = t1.minute + t2.minute;
            int totalHours = t1.hour + t2.hour + (totalMinutes / 60);
            
            totalMinutes %= 60;
            totalHours %= 24; 
            
            return timeOfDay(totalHours, totalMinutes);
        }
    };
}