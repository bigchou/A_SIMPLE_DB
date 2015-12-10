#include "student.h"
using namespace std;

ostream& operator << (std::ostream& os, const Student &stu){
    os << stu.name_ << " " << stu.gender_ << " ";
    if(os == cout){
        os << "(" << stu.age_ << ")";
    }else{
        os << stu.age_;
    }
    for(int i=0;i<stu.score_num_;i++)
        os << " " << stu.scores_[i];
    os << endl;
    return os;
}

void Student::Input(istream& is){
    if(is == cin){
        cout << "Name: ";
        is >> name_;
        cout << "Gender(M/F): ";
        is >> gender_;
        cout << "Age: ";
        is >> age_;
        cout << score_num_ << " Scores:";
        for(int i=0;i<score_num_;i++)
            is >> scores_[i];
    }else{
        is >> name_ >> gender_ >> age_ ;
        for(int i=0;i<score_num_;i++)
            is >> scores_[i];
    }
}

const char* Student::GetName() const{
    return name_;
}

bool Student::operator < (const Student &rhs) const {
    string s1 = name_;
    string s2 = rhs.name_;
    return s1 < s2;
}
