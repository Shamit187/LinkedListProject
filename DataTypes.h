#ifndef LINKEDLISTPROJECT_DATATYPES_H
#define LINKEDLISTPROJECT_DATATYPES_H

#include <string>
#include <vector>
#include <map>

#define MAX_SLOT 69
#define MAX_CREDIT 11

std::map<int, std::string> slotTimeMap {
        {0, "8:00 - 9:00 Saturday"},
        {1, "9:00 - 10:00 Saturday"},
        {2, "10:00 - 11:00 Saturday"},
        {3, "11:00 - 12:00 Saturday"},
        {4, "12:00 - 13:00 Saturday"},
        {5, "13:00 - 14:00 Saturday"},
        {6, "14:00 - 15:00 Saturday"},
        {7, "15:00 - 16:00 Saturday"},
        {8, "16:00 - 17:00 Saturday"},
        {9, "17:00 - 18:00 Saturday"},
        {10, "8:00 - 9:00 Sunday"},
        {11, "9:00 - 10:00 Sunday"},
        {12, "10:00 - 11:00 Sunday"},
        {13, "11:00 - 12:00 Sunday"},
        {14, "12:00 - 13:00 Sunday"},
        {15, "13:00 - 14:00 Sunday"},
        {16, "14:00 - 15:00 Sunday"},
        {17, "15:00 - 16:00 Sunday"},
        {18, "16:00 - 17:00 Sunday"},
        {19, "17:00 - 18:00 Sunday"},
        {20, "8:00 - 9:00 Monday"},
        {21, "9:00 - 10:00 Monday"},
        {22, "10:00 - 11:00 Monday"},
        {23, "11:00 - 12:00 Monday"},
        {24, "12:00 - 13:00 Monday"},
        {25, "13:00 - 14:00 Monday"},
        {26, "14:00 - 15:00 Monday"},
        {27, "15:00 - 16:00 Monday"},
        {28, "16:00 - 17:00 Monday"},
        {29, "17:00 - 18:00 Monday"},
        {30, "8:00 - 9:00 Tuesday"},
        {31, "9:00 - 10:00 Tuesday"},
        {32, "10:00 - 11:00 Tuesday"},
        {33, "11:00 - 12:00 Tuesday"},
        {34, "12:00 - 13:00 Tuesday"},
        {35, "13:00 - 14:00 Tuesday"},
        {36, "14:00 - 15:00 Tuesday"},
        {37, "15:00 - 16:00 Tuesday"},
        {38, "16:00 - 17:00 Tuesday"},
        {39, "17:00 - 18:00 Tuesday"},
        {40, "8:00 - 9:00 Wednesday"},
        {41, "9:00 - 10:00 Wednesday"},
        {42, "10:00 - 11:00 Wednesday"},
        {43, "11:00 - 12:00 Wednesday"},
        {44, "12:00 - 13:00 Wednesday"},
        {45, "13:00 - 14:00 Wednesday"},
        {46, "14:00 - 15:00 Wednesday"},
        {47, "15:00 - 16:00 Wednesday"},
        {48, "16:00 - 17:00 Wednesday"},
        {49, "17:00 - 18:00 Wednesday"},
        {50, "8:00 - 9:00 Thursday"},
        {51, "9:00 - 10:00 Thursday"},
        {52, "10:00 - 11:00 Thursday"},
        {53, "11:00 - 12:00 Thursday"},
        {54, "12:00 - 13:00 Thursday"},
        {55, "13:00 - 14:00 Thursday"},
        {56, "14:00 - 15:00 Thursday"},
        {57, "15:00 - 16:00 Thursday"},
        {58, "16:00 - 17:00 Thursday"},
        {59, "17:00 - 18:00 Thursday"},
        {60, "8:00 - 9:00 Friday"},
        {61, "9:00 - 10:00 Friday"},
        {62, "10:00 - 11:00 Friday"},
        {63, "11:00 - 12:00 Friday"},
        {64, "12:00 - 13:00 Friday"},
        {65, "13:00 - 14:00 Friday"},
        {66, "14:00 - 15:00 Friday"},
        {67, "15:00 - 16:00 Friday"},
        {68, "16:00 - 17:00 Friday"},
        {69, "17:00 - 18:00 Friday"}
};



struct Faculty {
    std::string id;
    std::string name;
    std::string designation;
    std::string email;
    int ext;
    int room;
    std::string phone;
    std::vector<std::string> assignedCourse;
    std::vector<bool>freeSlots;

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
    int id;
    std::string FacultyId;
    std::string CourseCode;
    int timeslot;
};

#endif
