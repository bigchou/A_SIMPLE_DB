
#include "database.h"
using namespace std;

ostream& operator << (ostream& os, const Database &db){
    for(int i=0;i<db.size_;i++)
        os << db.students_[i];
    return os;
}

void Database::Add(const Student& stu){
    students_[size_++] = stu;
}

bool Database::ReadFile(string filename){
    Student temp;
    ifstream ifile(filename);
    if(ifile){
        size_ = 0;//Reset the size of the Database
        while(ifile){
            if(isFull()){
                cout << "The database is full. ";
                return false;
            }
            temp.Input(ifile);
            if(ifile)
                Add(temp);
        }
        ifile.close();
        return true;
    }else{
        return false;
    }
}

void Database::sort(){
    stable_sort(this->students_,this->students_+size_);
}

void Database::Search(string name)const{
    int result_ind[DB_MAX_SIZE] = {0};
    int count = 0;
    for(int i=0;i<size_;++i){
        if( name == this->students_[i].GetName() )
            result_ind[count++] = i;
    }
    cout << endl << "There is/are " << count << " \"" << name << "\"" << endl << endl;
    for(int i=0;i<count;++i)
        cout << this->students_[result_ind[i]];
}

bool Database::OutputFile(string filename)const{
    ofstream ofile(filename);
    if(ofile){
        ofile << (*this);
        ofile.close();
        return true;
    }else{
        return false;
    }
}
