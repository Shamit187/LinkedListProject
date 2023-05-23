#ifndef LINKEDLISTPROJECT_DATATYPES_H
#define LINKEDLISTPROJECT_DATATYPES_H

#include <string>
#include <vector>

struct Faculty {
    std::string id;
    std::string name;
    std::string department;
    std::string designation;
    int age;
    std::string email;
    std::string phone;

    bool operator==(const Faculty& obj) const{
        return  id == obj.id;
    }

    bool operator==(const std::string& objID) const{
        return id == objID;
    }

};

struct Course {
    std::string code;
    std::string name;
    std::string department;
    int credits;
    int capacity;
    int enrolled;

    bool operator==(const Course& obj) const{
        return code == obj.code;
    }

    bool operator==(const std::string& objCode) const{
        return code == objCode;
    }

};


#endif
