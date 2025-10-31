#include <bits/stdc++.h>
#include <conio.h>
#include <stdlib.h>
#include "record.h"
#include "ui.h"
using namespace std;

//一些关于Record的成员函数
Record::Record(int ID, double amount, Date time, char* otherInfo ,bool isPayment){
    this->ID = ID;
    this->amount = amount;
    this->time = time;
    strcpy(this->otherInfo, otherInfo);
    this->isPayment = isPayment;
    this->isHidden = false;
}

void Record::showRecordSimply(){
    if(this->isHidden == true) printf("ID:%d    Hidden\n",this->ID);
    else printf("ID:%d    amount:%lld    payment:%s\n",this->ID, this->amount, (this->isPayment)?"yes":"no");
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
            printf("amount:%lld\n", this->amount);
            printf("payment:%s\n",  (this->isPayment)?"yes":"no");
            printf("info:%s\n", this->otherInfo);
        }
    }
    else{
        printf("ID:%d    Date:%d-%d-%d\n", this->ID, this->time.year, this->time.month, this->time.day);
        printf("amount:%lld\n", this->amount);
        printf("payment:%s\n",  (this->isPayment)?"yes":"no");
        printf("info:%s\n", this->otherInfo);
    }
    while(1){
        char c = getch();
        if(c == 'q') return;
    }
}
//一些关于RecordManger的成员函数
RecordManger::RecordManger(int ID){
    this->ID = ID;
}

void RecordManger::insertRecord(){
    double amount;
    Date time;
    char otherInfo[20];
    char paymentInfo[20];
    bool isPayment;
    printf("Please input amount: ");
    scanf("%lld", &amount);
    printf("Please input date: ");
    scanf("%d%d%d", &(time.year), &(time.month), &(time.day));
    printf("Please input other information: ");
    scanf("%s", otherInfo);
    printf("Is it payment, yes or no?: ");
    scanf("%s", paymentInfo);
    isPayment = (strcmp(paymentInfo, "yes") == 0);
    this->ID ++;
    this->records[ID] = Record(this->ID, amount, time, otherInfo, isPayment);
}

void RecordManger::deleteRecord(){
    int ID;
    printf("Please input ID of the record you want to delete: ");
    scanf("%d", &ID);
    this->records.erase(ID);
}

void RecordManger::showRecords(){
    for (map<int, Record>::iterator it = this->records.begin(); it != this->records.end(); ++it) {
        it->second.showRecordSimply();
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
