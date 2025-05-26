#include <iostream>
#include <algorithm>
#include <vector>
#include "scheduler.h"

using namespace std;

void priority_scheduling(vector<Task> &tasks) {
    // Sort tasks based on priority (lower number = higher priority);
    sort(tasks.begin(), tasks.end(), [](Task &a, Task &b){
        return a.priority < b.priority;
    });

    int current_time = 0;

    for (Task &task : tasks) {
        task.start_time = current_time;
        current_time += task.burst_time;
        task.finish_time = current_time;
        cout << task.name << " (Priority " << task.priority << "): start at " << task.start_time << ", finish at " << task.finish_time << '\n';
    }
}

int main() {
    vector<Task> tasks = {
        Task("Task1", 5, 3),
        Task("Task2", 3, 1),
        Task("Task3", 8, 2)
    };
    
    cout << "Priority Scheduling (Non-Preemptive):\n";
    priority_scheduling(tasks);
    return 0;
}