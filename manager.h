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
public:
    int ID;
    int CID;
    bool isHidden;
    bool Cvaild;
    double amount;
    struct Date time;
    bool isPayment;
    Record() {};
    Record(int id, double amount,struct Date time,char* otherInfo, bool isPayment, bool Cvaild);
    void showRecordSimply(char* category);
    void hideRecord();
    void showRecord();
    bool operator<(const Record& other) const {
        return time < other.time;  
    }

};

class Category{
private:
public:
    int CID;
    bool Cvaild;
    char name[20];
    Category() {};
    Category(int id, char* name);
    void setVaild(Record* record);
    void setUnvaild(Record* record);
};

class Filter{
private:
    Date startTime;
    Date endTime;
    double lowAmount;
    double highAmount;
public:
    Filter() {};
    Filter(Date startTime, Date endTime, double lowAmount, double highAmount);
    void setStartTime();
    void setEndTime();
    void setLowAmount();
    void setHighAmount();
    void showFilter();
    bool check(Record* record);
};

class RecordManger{
private:
    int ID;
    int CID;
    map<int, Record> records;
    map<int, Category> categorys;
    Filter filter;
public:
    RecordManger(int ID);
    void showRecordSimply();
    void insertRecord();
    void deleteRecord();
    void hideRecord();
    void showRecord();

    void insertCategory();
    void deleteCategory();
    void vaildCategory();
    void showRecordCategory();
    void converseCategory();
    void showCategory();

    void showFilter();
    void setStartTimeFilter();
    void setEndTimeFilter();
    void setLowAmountFilter();
    void setHighAmountFilter();
    void showRecordFilter();
};

