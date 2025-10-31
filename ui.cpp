#include <bits/stdc++.h>
#include <conio.h>
#include <stdlib.h>
#include "record.h"
#include "ui.h"

RecordManger recordManger(1234);

void clear(){
    system("clear");
}

void mainUIshow(){
    clear();
    printf("Hello, welcome to Ledger!\n");   
    printf("Here are some buttons, You can press the corresponding keys on the keyboard to perform the respective operations.\n");   
    printf("Button r: record management\n");
    printf("Button c: category management\n");
    printf("Button f: filter management\n");
    printf("Button q: quit\n");
}

void recordUIshow(){
    clear();
    printf("Record Management\n");    
    printf("Button i: insert record\n");
    printf("Button d: delete record\n");
    printf("Button h: hide record\n");
    printf("Button s: show record\n");
    printf("Button q: quit\n");
    recordManger.showRecords();
}

void mainUI(){
    int showFlag = 1;
    while(1){
        if(showFlag) mainUIshow();
        int button = getch();
        switch(button){
            case 'r': recordUI(); showFlag = 1; break;
            case 'c': categoryUI(); showFlag = 1; break;
            case 'f': filterUI(); showFlag = 1; break;
            case 'q': return; break;
            default: showFlag = 0; 
        }
    } 
}

void recordUI(){
    int showFlag = 1;
    while(1){
        if(showFlag) recordUIshow();
        int button = getch();
        switch(button){
            case 'i': recordManger.insertRecord(); showFlag = 1; break;
            case 'd': recordManger.deleteRecord(); showFlag = 1; break;
            case 'h': recordManger.hideRecord(); showFlag = 1; break;
            case 's': recordManger.showRecord(); showFlag = 1; break;
            case 'q': return; break;
            default: showFlag = 0; 
        }
    } 
}

void categoryUI(){
    clear();
    printf("Hello, welcome to C!\n");    
    while(1){
        int c = getch();
        switch(c){
            case 'q': return;
        }
    }
}

void filterUI(){
    clear();
    printf("Hello, welcome to filterUI!\n");    
    while(1){
        int c = getch();
        switch(c){
            case 'q': return;
        }
    }
}


int main(){
    mainUI();
    clear();
    return 0;
}