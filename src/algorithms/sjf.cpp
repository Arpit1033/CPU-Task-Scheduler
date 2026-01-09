#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/scheduler.h"

using namespace std;

void sjf(vector<Task> &tasks) {
    // Sort tasks based on burst time (shortest first)
    sort(tasks.begin(), tasks.end(), [](Task &a, Task &b) {
        return a.burst_time < b.burst_time;
    });

    int current_time = 0;

    for (Task &task : tasks) {
        task.start_time = current_time;
        current_time += task.burst_time;
        task.finish_time = current_time;
        cout << task.name << " (Burst Time " << task.burst_time << "): start at " << task.start_time << ", finish at " << task.finish_time << '\n';
    }
}

int main() {
    vector<Task> tasks = {
        Task("Task1", 5),
        Task("Task2", 3),
        Task("Task3", 8),
        Task("Task4", 2)
    };

    cout << "Shortest Job First (SJF) Scheduling:\n";
    sjf(tasks);
    return 0;
}
