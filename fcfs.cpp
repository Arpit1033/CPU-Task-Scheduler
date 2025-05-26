#include <iostream>
#include "scheduler.h"

using namespace std;

void fcfs(vector<Task> &tasks) {
    int current_time = 0;

    for (Task &task : tasks) {
        task.start_time = current_time;
        current_time += task.burst_time;
        task.finish_time = current_time;
        cout << task.name << ": start at " << task.start_time << ", finish at " << task.finish_time << '\n';
    }
}

int main(){
    vector<Task> tasks = {
        Task("Task1", 5),
        Task("Task1", 3),
        Task("Task1", 8)
    };

    cout << "FCFS Scheduling:\n";
    fcfs(tasks);
    return 0;
}