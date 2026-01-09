#include <iostream>
#include <vector>
#include <climits>
#include "../../include/scheduler.h"

using namespace std;

void srtf(vector<Task> &tasks) {
    int n = tasks.size();
    int current_time = 0;
    int completed = 0;

    while (completed < n) {
        int shortest_idx = -1;
        int shortest_time = INT_MAX;

        // Find task with shortest remaining time
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining_time > 0 && tasks[i].remaining_time < shortest_time) {
                shortest_time = tasks[i].remaining_time;
                shortest_idx = i;
            }
        }

        if (shortest_idx == -1) {
            current_time++;
            continue;
        }

        Task &task = tasks[shortest_idx];

        // Set start time if this is the first time the task is being executed
        if (task.start_time == -1) {
            task.start_time = current_time;
        }

        // Execute for 1 time unit (preemptive)
        task.remaining_time--;
        current_time++;

        // Check if task is completed
        if (task.remaining_time == 0) {
            task.finish_time = current_time;
            completed++;
            cout << task.name << " (Burst Time " << task.burst_time << "): start at " 
                 << task.start_time << ", finish at " << task.finish_time << '\n';
        }
    }
}

int main() {
    vector<Task> tasks = {
        Task("Task1", 5),
        Task("Task2", 3),
        Task("Task3", 8),
        Task("Task4", 2)
    };

    cout << "Shortest Remaining Time First (SRTF) Scheduling:\n";
    srtf(tasks);
    return 0;
}
