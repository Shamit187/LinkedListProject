#ifndef LINKEDLISTPROJECT_COURSEASSIGNMENTDATA_H
#define LINKEDLISTPROJECT_COURSEASSIGNMENTDATA_H

#include "LinkedList.h"
#include "DataTypes.h"
#include "CourseData.h"
#include "FacultyData.h"

class CourseAssignmentData{
private:
    LinkedList<CourseAssignmentInfo> mainData;
    int uniqueID;

public:
    CourseAssignmentData()
        :uniqueID{0} {}

    ~CourseAssignmentData() = default;

    void create(CourseData& courseData, FacultyData& facultyData){
        std::string facultyID, courseCode;
        fflush(stdin);
        std::cout << "Enter Faculty id:" << std::endl;
        std::getline(std::cin, facultyID);
        if(!facultyData.search(facultyID)){
            std::cout << "Faculty unavailable" << std::endl;
            return;
        }
        fflush(stdin);
        std::cout << "Enter Course code:" << std::endl;
        std::getline(std::cin, courseCode);
        if(!courseData.search(courseCode)){
            std::cout << "Course unavailable" << std::endl;
            return;
        }
        if(MAX_CREDIT - facultyData.get(facultyID)->active_credit < courseData.get(courseCode)->credits){
            std::cout << "Faculty can not take this course due to credit violation" << std::endl;
        }
        CourseAssignmentInfo courseAssignmentInfo;
        courseAssignmentInfo.FacultyId = facultyID;
        courseAssignmentInfo.CourseCode = courseCode;
        courseAssignmentInfo.id = ++uniqueID;


        std::cout << "Select Date";
    }

};

#endif //LINKEDLISTPROJECT_COURSEASSIGNMENTDATA_H
