#include <iostream>
#include "Time.h"

void Time::getTime() {
    std::cout << "Enter hours, minutes and seconds: ";
    std::cin >> hours;;
    std::cin >> minutes;
    std::cin >> seconds;
}

void Time::checkTimeValues() {
    if ((hours > 23) || (hours < 0)) {
        std::cout << "Wrong value of the hours, please enter the value of the hours from 0 to 23: ";
        std::cin >> hours;
    }

    if ((minutes > 60) || (minutes < 0)) {
        std::cout << "Wrong value of the minutes, please enter the value of the minutes from 0 to 60: ";
        std::cin >> minutes;
    }

    if ((seconds > 60) || (seconds < 0)) {
        std::cout << "Wrong value of the seconds, please enter the value of the seconds from 0 to 60: ";
        std::cin >> seconds;
    }
}

void Time::printTime() {
    if (hours >= 0 && hours < 10) {
        std::cout << "0";
    }
    std::cout << hours << ":";

    if (minutes >= 0 && minutes < 10) {
        std::cout << "0";
    }
    std::cout << minutes << ":";

    if (seconds >= 0 && seconds < 10) {
        std::cout << "0";
    }
    std::cout << seconds << std::endl << std::endl;
}

void Time::getTimesSum(Time b) {
    hours = hours + b.hours;
    minutes = minutes + b.minutes;
    seconds = seconds + b.seconds;
}

void Time::getTimesDifference(Time b) {
    hours = hours - b.hours;
    minutes = minutes - b.minutes;
    seconds = seconds - b.seconds;
}

void Time::formatTimesSum() {
    int totalSeconds = hours * 3600 + minutes * 60 + seconds;
    
    hours = totalSeconds / 3600;
    minutes = (totalSeconds % 3600) / 60;
    seconds = totalSeconds % 60;
}

void Time::formatTimesDifference(Time b) {
    int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
    int totalSeconds2 = b.hours * 3600 + b.minutes * 60 + b.seconds;

    int diffSeconds = totalSeconds1 - totalSeconds2;

    hours = diffSeconds / 3600;
    minutes = (diffSeconds % 3600) / 60;
    seconds = diffSeconds % 60;
}

std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << time.hours << ":" << time.minutes << ":" << time.seconds;
    return os;
}

std::istream& operator>>(std::istream& is, Time& time) {
    is >> time.hours >> time.minutes >> time.seconds;
    time.checkTimeValues();
    return is;
}