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

void fcfs(vector<Task> &tasks) {
    cout << "FCFS Scheduling\n";
    int current_time = 0;  // Current execution time

    for (Task &task : tasks) {
        task.start_time = current_time;
        current_time += task.burst_time;
        task.finish_time = current_time;
        cout << task.name << ' ' << task.start_time << ' ' << task. finish_time << '\n';
    }
}

int main(){
    vector<Task> tasks = {
        Task("Task1", 5),
        Task("Task1", 3),
        Task("Task1", 8)
    };

    fcfs(tasks);

    return 0;
}