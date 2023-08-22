# ifndef BST_STUDENT_H
# define BST_STUDENT_H
# include <iostream>
using namespace std ;

class Student {
private:
    int Id{} ;
    double GPA{} ;
    string Name, department ;

public:
    explicit Student() = default;

    void setId(int id) {
        Id = id;
    }

    Student(int id, double gpa, string name, string department) : Id(id),
    GPA(gpa), Name(std::move(name)), department(std::move(department)) {}

    [[nodiscard]] double getGpa() const {
        return GPA ;
    }

    void setGpa(double gpa) {
        GPA = gpa;
    }

    void setName(const string &name) {
        Name = name;
    }

    [[nodiscard]] string getName() const {
        return Name;
    }

    [[nodiscard]] string getDepartment() const{
        return department;
    }

    [[nodiscard]] int getId() const {
        return Id;
    }

    void setDepartment(const string & Department) {
        department = Department ;
    }

    friend ostream & operator << (ostream &os,const Student &s){
        os << "["<< s.Id << ", " << s.Name << ", " << s.GPA << ", " << s.department << "]\n" ;
        return os;
    }
};

#endif //BST_STUDENT_H