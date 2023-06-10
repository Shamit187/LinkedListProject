#ifndef LINKEDLISTPROJECT_COURSEASSIGNMENTDATA_H
#define LINKEDLISTPROJECT_COURSEASSIGNMENTDATA_H

#include "LinkedList.h"
#include "DataTypes.h"
#include "CourseData.h"
#include "FacultyData.h"
#include <algorithm>

class CourseAssignmentData{
private:
    LinkedList<CourseAssignmentInfo> mainData;
    int uniqueID;
    static bool caseInsensitiveEquals(const std::string& a, const std::string& b)
    {
        return std::equal(a.begin(), a.end(),
                          b.begin(), b.end(),
                          [](char a, char b) {
                              return tolower(a) == tolower(b);
                          });
    }


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
            return;
        }

        int total_credit_hour = courseData.get(courseCode)->credits;
        for(int i = 1; i <= total_credit_hour; i ++){
            std::cout << "Selecting class time for " << i << " credit." << std::endl;
            std::cout << "Select Date >> " ;
            std::string day_string;
            int day;
            std::cin >> day_string;
            if(caseInsensitiveEquals(day_string, std::string("Saturday"))){
                day = 0;
            }else if(caseInsensitiveEquals(day_string, std::string("Sunday"))){
                day = 1;
            }else if(caseInsensitiveEquals(day_string, std::string("Monday"))){
                day = 2;
            }else if(caseInsensitiveEquals(day_string, std::string("Tuesday"))){
                day = 3;
            }else if(caseInsensitiveEquals(day_string, std::string("Wednesday"))){
                day = 4;
            }else if(caseInsensitiveEquals(day_string, std::string("Thursday"))){
                day = 5;
            }else if(caseInsensitiveEquals(day_string, std::string("Friday"))){
                day = 6;
            }else{
                std::cout << "Invalid Day, Choose again." << std::endl;
                i--;
                continue;
            }

            std::cout << "Select Class Time >> " ;
            int classTime;
            std::cin >> classTime;
            if(classTime < 8 || classTime > 17){
                std::cout << "Wrong Time(Must be between 8 and 17" << std::endl;
                i--;
                continue;
            }
            classTime -= 8;
            int timeslot = classTime + 10 * day;

            if(!facultyData.get(facultyID)->freeSlots[timeslot]){
                std::cout << "Faculty unavailable that time" << std::endl;
                i--;
                continue;
            }

            facultyData.get(facultyID)->freeSlots[timeslot] = false;
            CourseAssignmentInfo courseAssignmentInfo;
            courseAssignmentInfo.FacultyId = facultyID;
            courseAssignmentInfo.CourseCode = courseCode;
            courseAssignmentInfo.id = ++uniqueID;
            courseAssignmentInfo.timeslot = timeslot;

            mainData.add(courseAssignmentInfo);

            std::cout << "New Course Assignment entry added\n" << courseAssignmentInfo << std::endl;
        }

        facultyData.get(facultyID)->active_credit -= courseData.get(courseCode)->credits;
        facultyData.get(facultyID)->assignedCourse.push_back(courseCode);

    }

    void read(){
        std::string id;
        CourseAssignmentInfo* searchedAssignment;
        std::cout << "Enter Assignment ID:" << std::endl;
        std::cin >> id;
        searchedAssignment = mainData.search(id);
        if(searchedAssignment == nullptr){
            std::cout << "Course id unavailable\n";
            return;
        }
        std::cout << "Searched Course:" << *(searchedAssignment);
    }

    void remove() {
        std::string id;
        CourseAssignmentInfo* searchedAssignment;
        std::cout << "Enter Assignment ID:" << std::endl;
        std::cin >> id;
        searchedAssignment = mainData.search(id);
        if(searchedAssignment == nullptr){
            std::cout << "Course id unavailable\n";
            return;
        }
        std::cout << "Searched Course:" << *(searchedAssignment);
        std::cout << "Deleting Entry";
        mainData.remove(id);
    }

    void print(){
        mainData.print();
    }

    std::vector<std::vector<std::tuple<std::string, std::string>>> returnAllSlots(){
        std::vector<std::vector<std::tuple<std::string, std::string>>> time_slots(MAX_SLOT);
        for(int i = 0; i < uniqueID; i++){
            CourseAssignmentInfo* searchedAssignment = mainData.index_get(i);
            time_slots[searchedAssignment->timeslot].push_back(std::make_tuple(searchedAssignment->FacultyId, searchedAssignment->CourseCode));
        }

        return time_slots;
    }


};

#endif //LINKEDLISTPROJECT_COURSEASSIGNMENTDATA_H
