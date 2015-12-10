#ifndef student_HHH
#define student_HHH
#include <iostream>
#include <string>
class Student{
    friend std::ostream& operator << (std::ostream& os, const Student &stu);
    public:
        bool operator < (const Student &rhs) const;
        void Input(std::istream& = std::cin);
        const char* GetName() const;
    private:
        static constexpr int score_num_ = 3;
        static constexpr int size_name_ = 31;
        char name_[size_name_] = {'\0'};
        char gender_ = 'M';
        int age_ = 0;
        int scores_[score_num_] = {0};
};
std::ostream& operator << (std::ostream& os, const Student &stu);
#endif
