#ifndef LINKEDLISTPROJECT_FACULTYDATA_H
#define LINKEDLISTPROJECT_FACULTYDATA_H

#include "LinkedList.h"
#include "DataTypes.h"

class FacultyData {
private:
    LinkedList<Faculty> mainData;
    int uniqueID;

public:
    //constructor and destructor
    FacultyData()
        :uniqueID{0}
    {}

    ~FacultyData()= default;

    //CRUD operation
    void create(){
        Faculty newFaculty;
        std::cout << "Enter Faculty name:" << std::endl;
        std::getline(std::cin, newFaculty.name);

        std::cout << "Enter Designation >>";
        std::cin >> newFaculty.designation;

        std::cout << "Enter Email >>";
        std::cin >> newFaculty.email;

        std::cout << "Enter EXT >> ";
        std::cin >> newFaculty.ext;

        std::cout << "Enter Room Number >>";
        std::cin >> newFaculty.room;

        std::cout << "Enter Mobile Number >>";
        std::cin >> newFaculty.phone;

        std::cout << "New Faculty entry added\n" << newFaculty;
    }
    void read(){}
    void update(){}
    void remove(){}

};


#endif //LINKEDLISTPROJECT_FACULTYDATA_H
