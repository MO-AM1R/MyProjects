# ifndef BST_DATA_H
# define BST_DATA_H
# include <iostream>
# include <map>
# include <vector>
# include <fstream>
# include "Student.h"

using namespace std ;

class Data {
private:
    map<int, Student> student_map ;
    map<string, int> department_map ;

public:
    bool addStudent(const Student & s){
        if (!student_map.contains(s.getId())) {
            student_map.insert({s.getId(), s});
            string Dep = s.getDepartment();

            transform(Dep.begin(), Dep.end(), Dep.begin(), [](char c) { return std::toupper(c);});
            student_map[s.getId()].setDepartment(Dep) ;

            if (!department_map.contains(Dep)){
                department_map.insert({Dep, 1}) ;
            }
            else{
                ++department_map[Dep] ;
            }
        }
        else{
            return false ;
        }
        return true ;
    }

    void removeStudent(int Id){
        if (student_map.contains(Id)) {
            if (department_map[student_map[Id].getDepartment()] != 1){
                --department_map[student_map[Id].getDepartment()] ;
            }
            else{
                department_map.erase(student_map[Id].getDepartment());
            }
            student_map.erase(Id);
            return;
        }
    }

    void printStudent(int Id){
        cout << student_map[Id] ;
    }

    void printDepartments(){
        cout << "\nstudent_map per department_map:\n" ;
        for (const auto & iterator : department_map) {
            cout << iterator.second << ' ' << iterator.first << " Students\n" ;
        }
    }

    int getStudentsNumber(){
        return (int)student_map.size() ;
    }

    map<int, Student> getStudents(){
        return student_map ;
    }
};


#endif //BST_DATA_H