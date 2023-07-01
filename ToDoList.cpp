#include <iostream>
#include <vector>
#include <fstream>

struct Task {
    std::string name;
    //More attributes to be added(date, time, etc...)
};

class ToDoList {
private:
    std::string name;
    std::vector<Task> tasks;
public:

    void addTask(Task newTask) {
        tasks.push_back(newTask);
    }

    void completeTask(std::string taskName) {

    }

    void saveList() {
        std::ofstream ofs(name.c_str());
        if (!ofs.is_open()) {
            std::cerr << "Failed to create todo list. Try different name." << std::endl;
        } else {
            std::cout << "List created with name: " << name << std::endl;
            ofs.close();
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


void openList(ToDoList &list) {

}



int main() {
    std::string fileName = "ListOfLists";
    std::ifstream ifs(fileName.c_str());
    bool newUser = false;
    if(!ifs) {
        std::ofstream ofs(fileName.c_str());
        newUser = true;
    } 

    int option = -1;
    bool exit = false;
    Task task;
    ToDoList list;

    std::string newUserMenu =  "Welcome to your new ToDo list app.\n1. Create your first List.\n2. Exit.\nEnter your choice: ";
    std::string existingUserMenu = "1. Create a new list.\n2. Select an existing list.\nEnter your choice: ";
    while (true) {
        if(newUser) {
            std::cout << newUserMenu;
            std::cin >> option;
            if(option == 1) {
                //create a new list
                newUser = false;
            } 
            else if (option == 2) {
                exit = true; //dont proceed after while loop ends
                break;
            }
        } else {

        }
        /*
        std::cout << "2. Add a task." << std::endl;
        std::cout << "3. Complete a task." << std::endl;
        std::cout << "4. Delete a list." << std::endl;
        std::cout << "5. Exit." << std::endl;
        */

        switch (option) {
            case 1:
                std::cout << "";
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
        }
    }

    return 0;
}