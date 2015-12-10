
#include "database.h"
using namespace std;
enum Option{Add = 1, Show, Search, OutputFile, InputFile, Exit};
int main(){
    int opt = 0;
    char select = '\0';
    Database db;
    Student stu;
    string name;
    do{
        cout << "A simple database program" << endl << endl
            << "(1)Add a record" << endl
            << "(2)Show all records" << endl
            << "(3)Search student(s) by name" << endl
            << "(4)Output records to a text file" << endl
            << "(5)Input records from a text file" << endl
            << "(6)Exit the program" << endl << endl;
        cout << "Please select a function...>";
        cin >> opt;
        system("pause");
        system("cls");
        switch(opt){
            case Add:
                cout << "Please input the required values:" << endl << endl;
                if(db.isFull()){
                    cout << "The database is full, so you can't add more records.";
                }else{
                    stu.Input();
                    db.Add(stu);
                }
                break;
            case Show:
                if(db.GetSize() > 1)
                    cout << "There are " << db.GetSize() << " records:" ;
                else
                    cout << "There is " << db.GetSize() << " record:" ;
                cout << endl << endl << db;
                break;
            case Search:
                cout << "Please input the name of the student...>";
                cin >> name;
                db.Search(name);
                break;
            case OutputFile:
                cout << "Out all records to a text file." << endl << endl
                    << "Note that the original data in the file will be lost after writing to the file. "
                    << "Are you sure that you want to continue? (Y/N)...>";
                cin >> select;
                cout << endl;
                if(toupper(select) == 'Y'){
                    cout << "Please input the name of the file...>";
                    cin >> name;
                    if(!db.OutputFile(name))
                        cout << "failure to output file." << endl;
                }
                break;
            case InputFile:
                cout << "Read in records from a text file." << endl << endl
                    << "Note that current data in the program will be lost after reading. "
                    << "Are you sure that you want to continue? (Y/N)...>";
                cin >> select;
                cout << endl;
                if(toupper(select) == 'Y'){
                    cout << "Please input the name of the file...>";
                    cin >> name;
                    if(!db.ReadFile(name))
                        cout << "failure to input file." << endl;
                }
                break;
            case Exit:
                return 0;
            default:
                cout << "Invalid Command";
        }
        db.sort();
        cout << endl << endl << "Press ENTER to continue.";
        system("pause");
        system("cls");
    }while(1);
    return 0;
}
