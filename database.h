#ifndef database_HHH
#define database_HHH
#include "student.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
class Database{
    friend std::ostream& operator << (std::ostream& os, const Database &db);
    public:
        void Add(const Student&);
        void Search(std::string)const;
        bool isFull()const{ return (size_ >=DB_MAX_SIZE); }
        bool ReadFile(std::string);
        bool OutputFile(std::string)const;
        int GetSize()const{return size_;};
        void sort();
    private:
        static constexpr int DB_MAX_SIZE = 100;
        Student students_[DB_MAX_SIZE];
        int size_ = 0;
};
std::ostream& operator << (std::ostream& os, const Database &db);
#endif
