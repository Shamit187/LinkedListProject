#include <iostream>
#include "FacultyData.h"
FacultyData facultyData;

void facultyInterface(){
    while(true) {
        int choice;
        std::cout << "1: CREATE\n2: READ\n3: UPDATE\n4: DELETE\n5: QUIT\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                facultyData.create();
                break;
            case 2:
                facultyData.read();
                break;
            case 3:
                facultyData.update();
                break;
            case 4:
                facultyData.remove();
                break;
            case 5:
                return;
                break;
            default:
                std::cout << "Wrong choice\n";
                break;
        }
    }
}

int main() {
    while(true) {
        int choice;
        std::cout << "1 For Faculty List\n2 For Course List\n3 For Assignment\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                facultyInterface();
                break;
            case 2:
                std::cout << "To be implemented\n";
                break;
            case 3:
                std::cout << "To be implemented\n";
                break;
            default:
                std::cout << "Wrong choice\n";
                break;
        }
    }
}
