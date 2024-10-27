#include <bits/stdc++.h>
using namespace std;

class addtask {
public:
    string name;
    string taskdescription;
    string duedate;
    string status;

    addtask(string x, string y, string z, string s) {
        name = x;
        taskdescription = y;
        duedate = z;
        status = s;
    }
};

int main() {
    vector<addtask> tasks;
    int choice;

    do {
        cout << "1. Add task" << endl;
        cout << "2. Delete task" << endl;
        cout << "3. Display tasks" << endl;
        cout << "4. Edit task" << endl;
        cout << "5. Change Task Status" << endl;
        cout << "6. Exit" << endl;
        cout << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore leftover newline

        switch (choice) {
            case 1: {
                string name, taskdescription, duedate, status = "pending";

                cout << "Enter task name: ";
                getline(cin, name);
                cout << "Enter task description: ";
                getline(cin, taskdescription);
                cout << "Enter task due date: ";
                getline(cin, duedate);

                addtask myobj(name, taskdescription, duedate, status);
                tasks.push_back(myobj);
                cout << "Task added successfully!" << endl;
                break;
            }
            case 2: {
                if (tasks.empty()) {
                    cout << "No tasks to delete." << endl;
                    break;
                }
                
                cout << "All Tasks:" << endl;
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ": " << tasks[i].name << " (status - " << tasks[i].status << ")" << endl
                         << "Description: " << tasks[i].taskdescription << endl
                         << "Due Date: " << tasks[i].duedate << endl << endl;
                }

                int task_number;
                cout << "Enter task number to delete: ";
                cin >> task_number;
                if (task_number > 0 && task_number <= tasks.size()) {
                    tasks.erase(tasks.begin() + (task_number - 1));
                    cout << "Task deleted successfully!" << endl;
                } else {
                    cout << "Invalid task number!" << endl;
                }
                cin.ignore();  // Ignore leftover newline
                break;
            }
            case 3: {
                if (tasks.empty()) {
                    cout << "No tasks to display." << endl;
                    break;
                }

                cout << "All Tasks:" << endl;
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ": " << tasks[i].name << " (status - " << tasks[i].status << ")" << endl
                         << "Description: " << tasks[i].taskdescription << endl
                         << "Due Date: " << tasks[i].duedate << endl << endl;
                }
                break;
            }
            case 4: {
                if (tasks.empty()) {
                    cout << "No tasks to edit." << endl;
                    break;
                }

                int task_number;
                cout << "Enter the task number to edit: ";
                cin >> task_number;
                cin.ignore();  // Ignore leftover newline

                if (task_number > 0 && task_number <= tasks.size()) {
                    cout << "Enter new task name: ";
                    getline(cin, tasks[task_number - 1].name);
                    cout << "Enter new task description: ";
                    getline(cin, tasks[task_number - 1].taskdescription);
                    cout << "Enter new task due date: ";
                    getline(cin, tasks[task_number - 1].duedate);
                    cout << "Task edited successfully!" << endl;
                } else {
                    cout << "Invalid task number!" << endl;
                }
                break;
            }
            case 5: {
                if (tasks.empty()) {
                    cout << "No tasks to update status." << endl;
                    break;
                }

                int task_number;
                cout << "Enter task number to mark as completed: ";
                cin >> task_number;

                if (task_number > 0 && task_number <= tasks.size()) {
                    tasks[task_number - 1].status = "completed";
                    cout << "Task marked as completed!" << endl;
                } else {
                    cout << "Invalid task number!" << endl;
                }
                cin.ignore();  // Ignore leftover newline
                break;
            }
            case 6: {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}