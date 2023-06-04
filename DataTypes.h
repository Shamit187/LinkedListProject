#ifndef LINKEDLISTPROJECT_DATATYPES_H
#define LINKEDLISTPROJECT_DATATYPES_H

#include <string>
#include <vector>

#define MAX_TIME_SLOT 8

struct Faculty {
    std::string id;
    std::string name;
    std::string designation;
    std::string email;
    int ext;
    int room;
    std::string phone;
    std::vector<std::string> assignedCourse;
    int active_credit;

    bool operator==(const Faculty& obj) const{
        return  id == obj.id;
    }

    bool operator==(const std::string& objID) const{
        return id == objID;
    }
};

std::ostream& operator<<(std::ostream &o, const Faculty& p){
    o << "generatedID: " << p.id
    << "\nName: " << p.name
    << "\nDesignation: " << p.designation
    << "\nEmail: " << p.email
    << "\nEXT: " << p.ext
    << "\nRoom: " << p.room
    << "\nPhone: " << p.phone
    << std::endl;
    return o;
}

struct Course {
    std::string code;
    std::string title;
    std::string type;
    int credits;
    std::vector<std::string> preReqCourse;

    bool operator==(const Course& obj) const{
        return code == obj.code;
    }

    bool operator==(const std::string& objCode) const{
        return code == objCode;
    }

};

std::ostream& operator<<(std::ostream& o, const Course& c) {
    o << "Code: " << c.code
      << "\nTitle: " << c.title
      << "\nType: " << c.type
      << "\nCredits: " << c.credits
      << "\nPrerequisite Courses: ";
    if (!c.preReqCourse.empty()) {
        for (const auto& course : c.preReqCourse) {
            o << course << " ";
        }
    }

    o << std::endl;
    return o;
}

struct CourseAssignmentInfo {
    std::string FacultyId;
    std::string CourseCode;
    int timeslot;
};

#endif
