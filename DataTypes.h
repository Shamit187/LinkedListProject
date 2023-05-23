#ifndef LINKEDLISTPROJECT_DATATYPES_H
#define LINKEDLISTPROJECT_DATATYPES_H

#include <string>
#include <vector>

#define MAX_TIME_SLOT 8

struct Faculty {
    std::string id;
    std::string name;
    std::string department;
    std::string designation;
    int age;
    std::string email;
    std::string phone;
    std::vector<std::string> assignedCourse;
    int active_credit;
    bool time_slots[MAX_TIME_SLOT];

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

struct CourseAssignmentInfo {
    std::string FacultyId;
    std::string CourseCode;
    int timeslot;
};

#endif
