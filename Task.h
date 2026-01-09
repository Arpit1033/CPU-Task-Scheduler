#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Task{
public:
    string name;
    int burst_time;
    int priority;
    int remaining_time;
    int start_time;
    int finish_time;

    // Constructor
    Task(string name, int burst_time, int priority = 0) 
        : name(name), burst_time(burst_time), priority(priority), remaining_time(burst_time),
          start_time(-1), finish_time(-1) {}
};

#endif