#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Task {
private:
    string description;
    bool completed;

public:
    Task(string desc) : description(desc), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    string getDescription() const {
        return description;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string &description) {
        tasks.emplace_back(description);
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }

        cout << left << setw(5) << "ID" << setw(30) << "Description" << "Status" << endl;
        cout << "--------------------------------------------------" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << left << setw(5) << i + 1
                 << setw(30) << tasks[i].getDescription()
                 << (tasks[i].isCompleted() ? "Completed" : "Incomplete") << endl;
        }
    }

    void markTaskCompleted(size_t id) {
        if (id == 0 || id > tasks.size()) {
            cout << "Invalid task ID." << endl;
            return;
        }

        tasks[id - 1].markCompleted();
    }

    void deleteTask(size_t id) {
        if (id == 0 || id > tasks.size()) {
            cout << "Invalid task ID." << endl;
            return;
        }

        tasks.erase(tasks.begin() + id - 1);
    }
};

void displayMenu() {
    cout << "\nTo-Do List Application" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    ToDoList todoList;
    int choice;
    string description;
    size_t id;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); // Clear newline character from buffer
                getline(cin, description);
                todoList.addTask(description);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter task ID to mark as completed: ";
                cin >> id;
                todoList.markTaskCompleted(id);
                break;
            case 4:
                cout << "Enter task ID to delete: ";
                cin >> id;
                todoList.deleteTask(id);
                break;
            case 5:
                cout << "Exiting application." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}