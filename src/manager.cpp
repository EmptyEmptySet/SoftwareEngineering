#include <bits/stdc++.h>
#include <conio.h>
#include <stdlib.h>
#include "manager.h"
#include "ui.h"
using namespace std;

//一些关于Record的成员函数
Record::Record(int ID, double amount, Date time, char* otherInfo ,bool isPayment, bool Cvaild){
    this->ID = ID;
    this->amount = amount;
    this->time = time;
    strcpy(this->otherInfo, otherInfo);
    this->isPayment = isPayment;
    this->isHidden = false;
    this->CID = 0;
    this->Cvaild = Cvaild;
    
}

void Record::showRecordSimply(char* category){
    if(this->isHidden == true) printf("ID:%d    Hidden\n",this->ID);
    else printf("ID:%d  category:%s  amount:%lf  payment:%s\n",this->ID, category, this->amount, (this->isPayment)?"yes":"no");
}

void Record::hideRecord(){
    if(this->isHidden == true) return;
    printf("Please set password:");
    scanf("%s",this->password);
    this->isHidden = true;
}

void Record::showRecord(){
    clear();
    printf("Button q: quit\n");
    if(this->isHidden == true){
        printf("Please input password:");
        char tempPassword[20];
        scanf("%s", tempPassword);
        if(strcmp(tempPassword, this->password) != 0){
            printf("Wrong password.\n");
        }
        else{
            printf("ID:%d    Date:%d-%d-%d\n", this->ID, this->time.year, this->time.month, this->time.day);
            printf("amount:%lf\n", this->amount);
            printf("payment:%s\n",  (this->isPayment)?"yes":"no");
            printf("info:%s\n", this->otherInfo);
        }
    }
    else{
        printf("ID:%d    Date:%d-%d-%d\n", this->ID, this->time.year, this->time.month, this->time.day);
        printf("amount:%lf\n", this->amount);
        printf("payment:%s\n",  (this->isPayment)?"yes":"no");
        printf("info:%s\n", this->otherInfo);
    }
    while(1){
        char c = getch();
        if(c == 'q') return;
    }
}
//一些关于Category的成员函数
Category::Category(int CID, char* name){
    this->CID = CID;
    strcpy(this->name ,name);
    this->Cvaild = true;
}

void Category::setVaild(Record* record){
    if(record->CID == this->CID) record->Cvaild = true;
}

void Category::setUnvaild(Record* record){
    if(record->CID == this->CID) record->Cvaild = false;
}
//

Filter::Filter(Date startTime, Date endTime, double lowAmount, double highAmount){
    this->startTime = startTime;
    this->endTime = endTime;
    this->lowAmount = lowAmount;
    this->highAmount = highAmount;
}

void Filter::setStartTime(){
    clear();
    printf("Button q: quit\n");
    Date time;
    printf("Please set start time of filter:");
    scanf("%d%d%d",&(time.year), &(time.month), &(time.day));
    this->startTime = time;
    while(1){
        char c = getch();
        if(c == 'q') return;
    }
}
void Filter::setEndTime(){
    clear();
    printf("Button q: quit\n");
    Date time;
    printf("Please set end time of filter:");
    scanf("%d%d%d",&(time.year), &(time.month), &(time.day));
    this->endTime = time;
    while(1){
        char c = getch();
        if(c == 'q') return;
    }
}

void Filter::setLowAmount(){
    clear();
    printf("Button q: quit\n");
    double amount;
    printf("Please set low amount of filter:");
    scanf("%lf",&amount);
    this->lowAmount = amount;
    while(1){
        char c = getch();
        if(c == 'q') return;
    }
}
void Filter::setHighAmount(){
    clear();
    printf("Button q: quit\n");
    double amount;
    printf("Please set high amount of filter:");
    scanf("%lf",&amount);
    this->highAmount = amount;
    while(1){
        char c = getch();
        if(c == 'q') return;
    }
}

bool Filter::check(Record* record){
    return this->startTime < record->time  && record->time < this->endTime && record->amount >= this->lowAmount && record->amount <= this->highAmount;
}

void Filter::showFilter(){
    printf("Filter\n");
    printf("Start Time: %d-%d-%d    End Time: %d-%d-%d\n", this->startTime.year, this->startTime.month, this->startTime.day, this->endTime.year, this->endTime.month, this->endTime.day);
    printf("Low Amount: %lf    High Amount: %lf\n", this->lowAmount, this->highAmount);    
}


//一些关于RecordManger的成员函数
RecordManger::RecordManger(int ID){
    this->ID = ID;
    this->CID = 0;
    char name[20] = {'o','t','h','e','r'};
    categorys[0] = Category(0, name);
    Date time;
    time.year = 2025;
    time.month = 1;
    time.day = 1;
    this->filter = Filter(time, time, 0, 2000);
}

void RecordManger::insertRecord(){
    double amount;
    Date time;
    char otherInfo[20];
    char paymentInfo[20];
    bool isPayment;
    bool Cvaild;
    printf("Please input amount: ");
    scanf("%lf", &amount);
    printf("Please input date: ");
    scanf("%d%d%d", &(time.year), &(time.month), &(time.day));
    printf("Please input other information: ");
    scanf("%s", otherInfo);
    printf("Is it payment, yes or no?: ");
    scanf("%s", paymentInfo);
    isPayment = (strcmp(paymentInfo, "yes") == 0);
    Cvaild = this->categorys[0].Cvaild;
    this->ID ++;
    this->records[ID] = Record(this->ID, amount, time, otherInfo, isPayment, Cvaild);
}

void RecordManger::deleteRecord(){
    int ID;
    printf("Please input ID of the record you want to delete: ");
    scanf("%d", &ID);
    this->records.erase(ID);
}

void RecordManger::showRecordSimply(){
    for (map<int, Record>::iterator it = this->records.begin(); it != this->records.end(); ++it) {
        it->second.showRecordSimply(this->categorys[it->second.CID].name);
    }
}

void RecordManger::hideRecord(){
    int ID;
    printf("Please input ID of the record you want to hide: ");
    scanf("%d", &ID);
    this->records[ID].hideRecord();
}

void RecordManger::showRecord(){
    int ID;
    printf("Please input ID of the record you want to show: ");
    scanf("%d", &ID);
    this->records[ID].showRecord();
}

void RecordManger::insertCategory(){
    char name[20];
    printf("Please input name: ");
    scanf("%s", &name);
    this->CID ++;
    this->categorys[CID] = Category(CID, name);
}

void RecordManger::deleteCategory(){
    int CID;
    printf("Please input ID of the category you want to delete: ");
    scanf("%d", &CID);
    if(CID == 0) return;
    bool vaild = this->categorys[0].Cvaild;
    this->categorys.erase(CID);
    for (map<int, Record>::iterator it = this->records.begin(); it != this->records.end(); ++it) {
        if(it->second.CID == CID) {
            it->second.CID = 0;
            it->second.Cvaild = vaild;
        }
    }
}

void RecordManger::vaildCategory(){
    int CID;
    printf("Please input ID of the category you want to set vaild or unvaild: ");
    scanf("%d", &CID);
    bool vaild = this->categorys[CID].Cvaild;
    if(vaild == false){
        this->categorys[CID].Cvaild = true;
        for (map<int, Record>::iterator it = this->records.begin(); it != this->records.end(); ++it) {
            this->categorys[CID].setVaild(&(it->second));
        }
    }
    else{
        this->categorys[CID].Cvaild = false;
        for (map<int, Record>::iterator it = this->records.begin(); it != this->records.end(); ++it) {
            this->categorys[CID].setUnvaild(&(it->second));
        }
    }
}

void RecordManger::showRecordCategory(){
    for (map<int, Record>::iterator it = this->records.begin(); it != this->records.end(); ++it) {
        if(it->second.Cvaild == true) it->second.showRecordSimply(this->categorys[it->second.CID].name);
    }
}

void RecordManger::converseCategory(){
    int CID;
    int ID;
    printf("Please input ID of the record and ID of the category: ");
    scanf("%d%d", &ID, &CID);
    this->records[ID].CID = CID;
    this->records[ID].Cvaild = this->categorys[CID].Cvaild;
}

void RecordManger::showCategory(){
    clear();
    printf("Button q: quit\n");
    for (map<int, Category>::iterator it = this->categorys.begin(); it != this->categorys.end(); ++it) {
        printf("%d -- %s  --Vaild:%s\n", it->first, it->second.name, (it->second.Cvaild)?"Yes":"No");
    }
    while(1){
        char c = getch();
        if(c == 'q') return;
    }
}

void RecordManger::showFilter(){
    this->filter.showFilter();
}

void RecordManger::setStartTimeFilter(){
    this->filter.setStartTime();
}

void RecordManger::setEndTimeFilter(){
    this->filter.setEndTime();    
}

void RecordManger::setLowAmountFilter(){
    this->filter.setLowAmount();
}

void RecordManger::setHighAmountFilter(){
    this->filter.setHighAmount();
}

void RecordManger::showRecordFilter(){
    double allAmount = 0;
    int recordNum = 0;
    for (map<int, Record>::iterator it = this->records.begin(); it != this->records.end(); ++it) {
        if((it->second.isHidden == false) && this->filter.check(&(it->second))){
            it->second.showRecordSimply(this->categorys[it->second.CID].name);
            allAmount += it->second.amount;
            recordNum ++;
        }
    }
    if(recordNum != 0) printf("All amount is %lf, average amount is %lf.\n", allAmount, allAmount/recordNum);
}