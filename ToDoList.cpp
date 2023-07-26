#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <unordered_map>

struct Task {
    std::string name;
    Task(std::string name) {
        this->name = name;
    }
    Task() {
        name = "";
    }
    //More attributes to be added(date, time, etc...)
};

class ToDoList {
private:
    std::unordered_map<std::string, int> frequency_map;
    std::vector<Task> tasks;
public:
    std::string name;

    ToDoList() {}

    ToDoList(std::string name) { 
        this->name = name;
        std::ifstream ifs(name.c_str());

        if (!ifs) {
            std::ofstream ofs(name.c_str());
        } else {
            while(std::getline(ifs, name)) {
                tasks.push_back(Task(name));
                frequency_map[name]++;
            }
        }
    }

    void addTask(Task* newTask) {
        int f = ++frequency_map[newTask->name];
        if (f > 1) {
            newTask->name = newTask->name + "(" + std::to_string(f-1) + ")";
        }
        tasks.push_back(*newTask);
    }

    bool editTask(std::string name, std::string newName) {
        for (auto& task : tasks) {
            if (task.name == name) {
                task.name = newName;
                return true;
            }                
        }
        return false;
    }

    bool deleteTask(std::string taskName) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if ((*it).name == taskName) {
                tasks.erase(it);
                return true;
            }
        }
        return false;
    }

    /*void retrieveList() {
        std::string taskName;
        std::ifstream ifs(name.c_str());
        if (!ifs.is_open()) {
            return;
        } else {
            while(std::getline(ifs, taskName)) {
                tasks.push_back(Task(taskName));
            }
        }
    }*/

    void saveList() {
        std::ofstream ofs(name.c_str());
        if (!ofs.is_open()) {
            std::cout << "There was an error with the file." << std::endl;
        } else {
            for (auto& task : tasks) {
                ofs << task.name + "\n";
            }
        }
    }

    std::string toString() {
        std::string result;
        for (auto& task : tasks) {
            result += task.name + "\n";
        }
        return result;
    }
};


void openListOfLists(ToDoList &list) {

}

std::string EntryMenu(bool newUser) {
    int option = -1;
    bool exit = false;
    const std::string listOfLists = "ListOfLists";
    Task task;
    ToDoList list;

    std::string newUserMenu =  "Welcome to your new ToDo list app.\n1. Create your first List.\n2. Exit.\nEnter your choice: ";
    std::string existingUserMenu = "1. Create a new list.\n2. Select an existing list.\nEnter your choice: ";

    while (true) {
        if(newUser) {
            std::cout << newUserMenu;
            std::cin >> option;

            if (!(std::cin.good()) || option > 2 || option < 1) {
                std::cout << "Invalid input." << std::endl;
                std::cin.clear();
		        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else if(option == 1) {
                const std::string fileName = "ListOfLists";
                std::ofstream ofs(fileName.c_str(), std::ios::app);
                std::cout << "Please enter a name for your new list: ";
                std::cin.clear();
		       // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, list.name);
                ofs << list.name + "\n";
                ofs.close();
                return list.name;
            } 
            else if (option == 2) {
                return "";
            } 
        } else {
            std::cout << existingUserMenu;
            std::cin >> option;

            if (!(std::cin.good()) || option > 2 || option < 1) {
                std::cout << "Invalid input." << std::endl;
                std::cin.clear();
		        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if(option == 1) {
                const std::string fileName = "ListOfLists";
                std::ofstream ofs(fileName.c_str(), std::ios::app);
                std::cout << "Please enter a name for your new list: ";
                std::cin.clear();
		       // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, list.name);
                ofs << list.name + "\n";
                ofs.close();
                return list.name;
            } 
            else if (option == 2) {
                std::string taskName;
                std::string taskList;
                std::ifstream ifs(listOfLists.c_str());

                while(std::getline(ifs, taskName)) {
                    taskList += taskName + "\n";
                }

                std::cout << taskList << std::endl;
                std::cout << "Enter name of list to open: ";
                taskName = "";
                std::cin >> taskName;
                ifs.close();
                return taskName;
            }
        }
    }
}

bool isNewUser() {
    const std::string fileName = "ListOfLists";
    std::ifstream ifs(fileName.c_str());
    bool newUser = false;

    if(!ifs) {
        std::ofstream ofs(fileName.c_str());
        newUser = true;
    } else {
        std::string temp;
        std::string result = "";

        while (std::getline(ifs, temp)) {
            result += temp;
        }
        if (result == "") {
            newUser = true;
        } else {
            newUser = false;
        }
    }
    ifs.close();
    return newUser;
}

bool checkForList(std::string currentList) {
    const std::string listOfLists = "ListOfLists";
    std::ifstream ifs(listOfLists.c_str());
    std::string toOpen;

    while (std::getline(ifs, toOpen)) {
        if (toOpen == currentList) {
            break;
        }
    }
    ifs.close();

    if (toOpen != currentList || toOpen == "") {
        return false;
    } else {
        return true;
    }
}

void mainMenu(ToDoList *list) {
    std::string underline = "";
    for (int i = 0; i < size(list->name) + 1; i++) {
        underline += "-";
    }

    const std::string menu = "1. Add new task\n2. Edit a task\n3. Finish a task\n4. Exit\nEnter your choice: ";

    int option = -1;
    bool exit = false;
    std::string taskName;
    std::string toEdit;
    std::string newName;
    std::string toDelete;
    while (!exit) {
        std::cout << list->name << std::endl;
        std::cout << underline << std::endl;
        std::cout << list->toString() << std::endl;
        std::cout << menu;
        std::cin >> option;
        switch (option) {
            case 1:
                std::cout << "Enter task name: ";
                std::cin >> taskName;
                list->addTask(new Task(taskName));
                break;
            case 2:
                std::cout << "Enter name of task to edit: ";
                std::cin >> toEdit;
                std::cout << "Enter new task name: ";
                std::cin >> newName;

                if (!list->editTask(taskName, newName)) {
                    std::cout << "Task not found." << std::endl;
                }
                break;
            case 3:
                std::cout << "Enter name of task to remove: ";
                std::cin >> toDelete;
                if (!list->deleteTask(toDelete)) {
                    std::cout << "Task not found." << std::endl;
                }
                break;
            case 4:
                exit = true;
                list->saveList();
                break;
            default:
                std::cout << "Invalid input" << std::endl;
                break;
        }
    }


}

int main() {
    std::string currentList = EntryMenu(isNewUser());

    if (!checkForList(currentList)) {
        std::cout << "List not found" << std::endl;
    } else {

        ToDoList list(currentList);

        mainMenu(&list);
    }
    
    
    return 0;
}