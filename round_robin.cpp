#include <iostream>
#include <queue>
#include "scheduler.h"

using namespace std;

void round_robin(vector<Task> &tasks, int quantum) {
    queue<Task*> task_queue;  
    int current_time = 0;  

    for (Task &task : tasks) task_queue.push(&task);

    while (!task_queue.empty()) {
        Task* task = task_queue.front();
        task_queue.pop();

        if (task->start_time == -1) task->start_time = current_time;
        
        if (task->remaining_time > quantum) {
            current_time += quantum;
            task->remaining_time -= quantum;
            task_queue.push(task);
        } else {
            current_time += task->remaining_time;
            task->finish_time = current_time;
            task->remaining_time = 0;
            cout << task->name << ": start at " << task->start_time << ", finish at " << task->finish_time << '\n';
        }
    }
}

int main() {
    vector<Task> tasks = {
        Task("Task1", 5),
        Task("Task2", 3),
        Task("Task3", 8)
    };

    int quantum = 2;
    cout << "Round Robin Scheduling:\n";
    round_robin(tasks, quantum);

    return 0;
}