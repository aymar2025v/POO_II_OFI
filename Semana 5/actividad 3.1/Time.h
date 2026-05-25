
#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
public:
    
    Time(int h = 0, int m = 0, int s = 0);

    // Métodos set (modificadores) – NO son const
    void setTime(int h, int m, int s);
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);

    // Métodos get (consultores) – SÍ son const
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    // Métodos de impresión (no modifican) – SÍ const
    void printMilitary() const;
    void printStandard() const;

private:
    int hour;
    int minute;
    int second;
};

#endif
