
#include "Time.h"
#include <iostream>
#include <iomanip>
using namespace std;

Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

void Time::setTime(int h, int m, int s) {
	setHour(h);
	setMinute(m);
	setSecond(s);
}

void Time::setHour(int h) {
	hour = (h >= 0 && h < 24) ? h : 0;
}

void Time::setMinute(int m) {
	minute = (m >= 0 && m < 60) ? m : 0;
}

void Time::setSecond(int s) {
	second = (s >= 0 && s < 60) ? s : 0;
}

// Métodos const
int Time::getHour() const {
	return hour;
}

int Time::getMinute() const {
	return minute;
}

int Time::getSecond() const {
	return second;
}

void Time::printMilitary() const {
	cout << setfill('0') << setw(2) << hour << ":"
	     << setw(2) << minute << ":" << setw(2) << second;
}

void Time::printStandard() const {
	int h = (hour == 0 || hour == 12) ? 12 : hour % 12;
	cout << h << ":" << setfill('0') << setw(2) << minute << ":"
	     << setw(2) << second << (hour < 12 ? " AM" : " PM");
}
