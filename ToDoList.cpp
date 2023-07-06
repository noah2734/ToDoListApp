#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

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
    std::vector<Task> tasks;
public:
    std::string name;

    ToDoList() {}

    ToDoList(std::string name) { 
        this->name = name;
        std::string toAdd;
        std::ifstream ifs(name.c_str());
        while (std::getline(ifs, toAdd)) {
            tasks.push_back(toAdd);
        }
    }

    void addTask(Task newTask) {
        tasks.push_back(newTask);
    }

    void completeTask(std::string taskName) {

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
                ofs << task.name;
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

            std::cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (!(std::cin >> option) || option > 2 || option < 1) {
                std::cout << "Invalid input." << std::endl;
                continue;
            }
            else if(option == 1) {
                const std::string fileName = "ListOfLists";
                std::ofstream ofs(fileName.c_str(), std::ios::app);
                std::cout << "Please enter a name for your new list: ";
                std::cin.clear();
		        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, list.name);
                ofs << list.name + "\n";
                ofs.close();
                return list.name;
            } 
            else if (option == 2) {
                return "";
            } 
        } else {
            std::cout << existingUserMenu << std::endl;
            
            std::cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (!(std::cin >> option) || option > 2 || option < 1) {
                std::cout << "Invalid input." << std::endl;
                continue;
            }

            if(option == 1) {
                const std::string fileName = "ListOfLists";
                std::ofstream ofs(fileName.c_str(), std::ios::app);
                std::cout << "Please enter a name for your new list: ";
                std::cin.clear();
		        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void mainMenu(ToDoList list) {
    std::string underline = "";
    for (int i = 0; i < size(list.name) + 1; i++) {
        underline += "-";
    }

        std::cout << list.name << std::endl;
        std::cout << underline << std::endl;

    if (list.toString() == "") {
        std::cout << "Your list is empty." << std::endl;
    } else {
        std::cout << list.toString() << std::endl;
    }
}

int main() {
    std::string currentList = EntryMenu(isNewUser());

    if (!checkForList(currentList)) {
        std::cout << "List not found" << std::endl;
    } else {

        ToDoList list(currentList);

        mainMenu(list);
    }


        /*
        std::cout << "2. Add a task." << std::endl;
        std::cout << "3. Complete a task." << std::endl;
        std::cout << "4. Delete a list." << std::endl;
        std::cout << "5. Exit." << std::endl;
        */

       /* switch (option) {
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
        }*/
    
    
    return 0;
}