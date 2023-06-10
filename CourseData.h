#ifndef LINKEDLISTPROJECT_COURSEDATA_H
#define LINKEDLISTPROJECT_COURSEDATA_H

#include <sstream>
#include "LinkedList.h"
#include "DataTypes.h"

class CourseData{
private:
    LinkedList<Course> mainData;
    int uniqueID;

    std::vector<std::string> parsePrerequisiteCourses(const std::string& prerequisiteCourses) {
        std::vector<std::string> courses;
        std::stringstream ss(prerequisiteCourses);
        std::string course;
        while (std::getline(ss, course, ',')) {
            courses.push_back(trim(course));
        }
        return courses;
    }
    std::string trim(const std::string& str) {
        const auto strBegin = str.find_first_not_of(" \t");
        if (strBegin == std::string::npos)
            return ""; // Empty string

        const auto strEnd = str.find_last_not_of(" \t");
        const auto strRange = strEnd - strBegin + 1;

        return str.substr(strBegin, strRange);
    }

public:
    CourseData()
        :uniqueID{0}
    {}

    ~CourseData()=default;

    //CRUD operation
    void create(){
        Course newCourse;
        fflush(stdin);
        std::cout << "Enter Course code:" << std::endl;
        std::getline(std::cin, newCourse.code);

        fflush(stdin);
        std::cout << "Enter Course title:" << std::endl;
        std::getline(std::cin, newCourse.title);

        std::cout << "Enter Course type >>";
        std::getline(std::cin, newCourse.type);

        std::cout << "Enter Credit >>";
        std::cin >> newCourse.credits;

        int prereqCourseNumber;
        std::string prereqCourseCode;

        std::cout << "Enter number of prerequisite CourseNeeded >>";
        std::cin >> prereqCourseNumber;
        std::cout << std::endl;

        for(int i = 0; i < prereqCourseNumber; i++){
            std::cout << "Enter prerequisite Course " << i + 1 << ": ";
            std::cin >> prereqCourseCode;
            fflush(stdin);
            newCourse.preReqCourse.push_back(prereqCourseCode);
            prereqCourseCode.clear();
            std::cout << std::endl;
        }

        mainData.add(newCourse);
        std::cout << "New Course entry added\n" << newCourse << std::endl;
   }

    void read(){
        std::string code;
        Course* searchedCourse;
        std::cout << "Enter Course code:" << std::endl;
        std::cin >> code;
        searchedCourse = mainData.search(code);
        if(searchedCourse == nullptr){
            std::cout << "Course id unavailable\n";
            return;
        }
        std::cout << "Searched Course:" << *(searchedCourse);
    }

    bool search(std::string& code){
        Course* searchedCourse;
        searchedCourse = mainData.search(code);
        if(searchedCourse == nullptr){
            return false;
        }
        return true;
    }

    Course* get(std::string& code){
        Course* searchedCourse;
        searchedCourse = mainData.search(code);
        return searchedCourse;
    }

    void update() {
        std::string code;
        Course* searchedCourse;
        std::cout << "Enter Course code:" << std::endl;
        std::cin >> code;
        searchedCourse = mainData.search(code);
        if (searchedCourse == nullptr) {
            std::cout << "Course code unavailable\n";
            return;
        }
        std::cout << "Searched Course:" << *(searchedCourse);
        int choice;
        std::cout << "1: Title\n2: Type\n3: Credits\n4: Prerequisite courses\n";
        std::cin >> choice;
        fflush(stdin);

        switch (choice) {
            case 1:
                std::cout << "Enter Course title:" << std::endl;
                std::getline(std::cin, searchedCourse->title);
                break;
            case 2:
                std::cout << "Enter Course type >>";
                std::cin >> searchedCourse->type;
                break;
            case 3:
                std::cout << "Enter Credits >>";
                std::cin >> searchedCourse->credits;
                break;
            case 4:
                std::cout << "Enter Prerequisite Courses (comma-separated) >>";
                fflush(stdin);
                {
                    std::string prerequisiteCourses;
                    std::getline(std::cin, prerequisiteCourses);
                    searchedCourse->preReqCourse = parsePrerequisiteCourses(prerequisiteCourses);
                }
                break;
            default:
                std::cout << "Wrong choice\n";
                return;
        }
        mainData.update(code, *searchedCourse);
    }

    void remove() {
        std::string code;
        Course* searchedCourse;
        std::cout << "Enter Course code:" << std::endl;
        std::cin >> code;
        searchedCourse = mainData.search(code);
        if (searchedCourse == nullptr) {
            std::cout << "Course code unavailable\n";
            return;
        }
        std::cout << "Searched Course:" << *(searchedCourse);
        std::cout << "Deleting Entry";
        mainData.remove(code);
    }

    void print(){
        mainData.print();
    }

};

#endif
