#include <iostream>
#include "FacultyData.h"
#include "CourseData.h"
#include "CourseAssignmentData.h"

bool facultyInterface(FacultyData& facultyData){
    int choice;
    std::cout << "1: CREATE\n2: READ\n3: UPDATE\n4: DELETE\n5: LIST\n6: QUIT" << std::endl;
    std::cin >> choice;
    switch (choice) {
        case 1:
            facultyData.create();
            return true;
        case 2:
            facultyData.read();
            return true;
        case 3:
            facultyData.update();
            return true;
        case 4:
            facultyData.remove();
            return true;
        case 5:
            facultyData.print();
            return true;
        case 6:
            return false;
        default:
            std::cout << "Wrong choice\n";
            return true;
    }
}

bool courseInterface(CourseData& courseData){
    int choice;
    std::cout << "1: CREATE\n2: READ\n3: UPDATE\n4: DELETE\n5: LIST\n6: QUIT" << std::endl;
    std::cin >> choice;
    switch (choice) {
        case 1:
            courseData.create();
            return true;
        case 2:
            courseData.read();
            return true;
        case 3:
            courseData.update();
            return true;
        case 4:
            courseData.remove();
            return true;
        case 5:
            courseData.print();
            return true;
        case 6:
            return false;
        default:
            std::cout << "Wrong choice\n";
            return true;
    }
}

bool courseAssignmentInterface(CourseData& courseData, FacultyData& facultyData, CourseAssignmentData& courseAssignmentData){
    int choice;
    std::cout << "1: CREATE\n2: READ\n3: UPDATE\n4: DELETE\n5: LIST\n6: QUIT" << std::endl;
    std::cin >> choice;
    switch (choice) {
        case 1:
            courseAssignmentData.create(courseData, facultyData);
            return true;
        case 2:
            courseData.read();
            return true;
        case 3:
            courseData.update();
            return true;
        case 4:
            courseData.remove();
            return true;
        case 5:
            courseData.print();
            return true;
        case 6:
            return false;
        default:
            std::cout << "Wrong choice\n";
            return true;
    }
}

int main() {
    FacultyData facultyData;
    CourseData courseData;
    CourseAssignmentData courseAssignmentData
    while(true) {
        int choice;
        std::cout << "1 For Faculty List\n2 For Course List\n3 For Assignment" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                while(facultyInterface(facultyData));
                break;
            case 2:
                while(courseInterface(courseData));
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
