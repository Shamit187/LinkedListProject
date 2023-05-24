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
        fflush(stdin);
        std::cout << "Enter Faculty name:" << std::endl;
        std::getline(std::cin, newFaculty.name);

        std::cout << "Enter Designation >>";
        std::cin >> newFaculty.designation;

        std::cout << "Enter Email >>";
        std::cin >> newFaculty.email;

        std::cout << "Enter EXT >>";
        std::cin >> newFaculty.ext;

        std::cout << "Enter Room Number >>";
        std::cin >> newFaculty.room;

        std::cout << "Enter Mobile Number >>";
        std::cin >> newFaculty.phone;

        newFaculty.id = std::to_string(++uniqueID);
        mainData.add(newFaculty);
        std::cout << "New Faculty entry added\n" << newFaculty;
    }
    void read(){
        int id;
        Faculty* searchedFaculty;
        std::cout << "Enter Faculty id:" << std::endl;
        std::cin >> id;
        searchedFaculty = mainData.search(std::string(std::to_string(id)));
        if(searchedFaculty == nullptr){
            std::cout << "Faculty id unavailable\n";
            return;
        }
        std::cout << "Searched Faculty:" << *(searchedFaculty);
    }
    void update(){
        int id;
        Faculty* searchedFaculty;
        std::cout << "Enter Faculty id:" << std::endl;
        std::cin >> id;
        searchedFaculty = mainData.search(std::string(std::to_string(id)));
        if(searchedFaculty == nullptr){
            std::cout << "Faculty id unavailable\n";
            return;
        }
        std::cout << "Searched Faculty:" << *(searchedFaculty);
        int choice;
        std::cout << "1: name\n2: designation\n3: email\n4: ext\n5: room\n6: phone\n";
        std::cin >> choice;
        fflush(stdin);
        switch (choice) {
            case 1:
                std::cout << "Enter Faculty name:" << std::endl;
                std::getline(std::cin, searchedFaculty->name);
                break;
            case 2:
                std::cout << "Enter Designation >>";
                std::cin >> searchedFaculty->designation;
                break;
            case 3:
                std::cout << "Enter Email >>";
                std::cin >> searchedFaculty->email;
                break;
            case 4:
                std::cout << "Enter EXT >>";
                std::cin >> searchedFaculty->ext;
                break;
            case 5:
                std::cout << "Enter Room Number >>";
                std::cin >> searchedFaculty->room;
                break;
            case 6:
                std::cout << "Enter Mobile Number >>";
                std::cin >> searchedFaculty->phone;
                break;
            default:
                std::cout << "Wrong choice\n";
                return;
        }
        mainData.update(std::to_string(id), *searchedFaculty);
    }
    void remove(){
        int id;
        Faculty* searchedFaculty;
        std::cout << "Enter Faculty id:" << std::endl;
        std::cin >> id;
        searchedFaculty = mainData.search(std::string(std::to_string(id)));
        if(searchedFaculty == nullptr){
            std::cout << "Faculty id unavailable\n";
            return;
        }
        std::cout << "Searched Faculty:" << *(searchedFaculty);
        std::cout << "Deleting Entry";
        mainData.remove(std::to_string(id));
    }

};


#endif //LINKEDLISTPROJECT_FACULTYDATA_H
