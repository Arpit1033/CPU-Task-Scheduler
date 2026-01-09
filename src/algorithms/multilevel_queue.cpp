#include <iostream>
#include <vector>
#include <queue>
#include "../../include/scheduler.h"

using namespace std;

/*
 * Multilevel Queue Scheduling
 * - Queue 1 (High Priority, priority 0-1): Round Robin with given quantum
 * - Queue 2 (Medium Priority, priority 2-3): Round Robin with quantum * 2
 * - Queue 3 (Low Priority, priority 4+): FCFS
 * Higher priority queues are serviced first before moving to lower priority queues.
 */
void multilevel_queue(vector<Task> &tasks, int quantum) {
    queue<Task*> high_priority_queue;    // Priority 0-1 (Round Robin)
    queue<Task*> medium_priority_queue;  // Priority 2-3 (Round Robin with larger quantum)
    queue<Task*> low_priority_queue;     // Priority 4+ (FCFS)

    // Distribute tasks into appropriate queues
    for (Task &task : tasks) {
        if (task.priority <= 1) {
            high_priority_queue.push(&task);
        } else if (task.priority <= 3) {
            medium_priority_queue.push(&task);
        } else {
            low_priority_queue.push(&task);
        }
    }

    int current_time = 0;

    cout << "\n--- High Priority Queue (Round Robin, quantum=" << quantum << ") ---\n";
    // Process high priority queue with Round Robin
    while (!high_priority_queue.empty()) {
        Task* task = high_priority_queue.front();
        high_priority_queue.pop();

        if (task->start_time == -1) task->start_time = current_time;

        if (task->remaining_time > quantum) {
            current_time += quantum;
            task->remaining_time -= quantum;
            high_priority_queue.push(task);
        } else {
            current_time += task->remaining_time;
            task->finish_time = current_time;
            task->remaining_time = 0;
            cout << task->name << " (Priority " << task->priority << "): start at " 
                 << task->start_time << ", finish at " << task->finish_time << '\n';
        }
    }

    cout << "\n--- Medium Priority Queue (Round Robin, quantum=" << quantum * 2 << ") ---\n";
    // Process medium priority queue with larger Round Robin quantum
    int medium_quantum = quantum * 2;
    while (!medium_priority_queue.empty()) {
        Task* task = medium_priority_queue.front();
        medium_priority_queue.pop();

        if (task->start_time == -1) task->start_time = current_time;

        if (task->remaining_time > medium_quantum) {
            current_time += medium_quantum;
            task->remaining_time -= medium_quantum;
            medium_priority_queue.push(task);
        } else {
            current_time += task->remaining_time;
            task->finish_time = current_time;
            task->remaining_time = 0;
            cout << task->name << " (Priority " << task->priority << "): start at " 
                 << task->start_time << ", finish at " << task->finish_time << '\n';
        }
    }

    cout << "\n--- Low Priority Queue (FCFS) ---\n";
    // Process low priority queue with FCFS
    while (!low_priority_queue.empty()) {
        Task* task = low_priority_queue.front();
        low_priority_queue.pop();

        task->start_time = current_time;
        current_time += task->remaining_time;
        task->finish_time = current_time;
        task->remaining_time = 0;
        cout << task->name << " (Priority " << task->priority << "): start at " 
             << task->start_time << ", finish at " << task->finish_time << '\n';
    }
}

int main() {
    vector<Task> tasks = {
        Task("Task1", 5, 0),
        Task("Task2", 3, 1),
        Task("Task3", 8, 2),
        Task("Task4", 4, 3),
        Task("Task5", 6, 5),
        Task("Task6", 2, 4)
    };

    int quantum = 2;
    cout << "Multilevel Queue Scheduling:\n";
    multilevel_queue(tasks, quantum);
    return 0;
}
