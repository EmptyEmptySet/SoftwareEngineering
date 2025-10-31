#include <iostream>
#include <set>
using namespace std;

struct Date{
    int year;
    int month;
    int day;
    bool operator<(const Date& other) const { 
        if (year != other.year) return year < other.year;  
        else if (month != other.month) return month < other.month;
        else return day < other.day;
    }
}; 

class Record{
private:
    char otherInfo[20];
    char password[20];
    bool isHidden;
public:
    int ID;
    double amount;
    struct Date time;
    bool isPayment;
    Record() {};
    Record(int id, double amounnt,struct Date time,char* otherInfo, bool isPayment);
    void showRecordSimply();
    void hideRecord();
    void showRecord();
    bool operator<(const Record& other) const {
        return time < other.time;  
    }

};

class RecordManger{
private:
    int ID;
public:
    RecordManger(int ID);
    map<int, Record> records;
    void showRecords();
    void insertRecord();
    void deleteRecord();
    void hideRecord();
    void showRecord();
};
