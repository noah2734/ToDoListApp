#include <iostream>

struct ToDoList {
    std::string taskName;

    void addTask(std::string taskName) {

    }

    void completeTask(std::string taskName) {

    }
};



int main() {
    int option = -1;
    while (true) {
        std::cout << "1. Create a new list." << std::endl;
        std::cout << "2. Add a task." << std::endl;
        std::cout << "3. Complete a task." << std::endl;
        std::cout << "4. Delete a list." << std::endl;
        std::cout << "5. Exit." << std::endl;
        std::cin >> option;

        switch (option) {
            case 1:
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