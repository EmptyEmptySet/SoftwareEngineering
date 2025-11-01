#include <bits/stdc++.h>
#include <conio.h>
#include <stdlib.h>
#include "manager.h"
#include "ui.h"

RecordManger recordManger(1000);

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
    recordManger.showRecordSimply();
}

void categoryUIshow(){
    clear();
    printf("Category Management\n");    
    printf("Button i: insert category\n");
    printf("Button d: delete category\n");
    printf("Button v: set category vaild or unvaild\n");
    printf("Button s: show record\n");
    printf("Button c: converse record\n");
    printf("Button q: quit\n");
    recordManger.showRecordCategory();
}

void filterUIshow(){
    clear();
    printf("Filter Management\n");    
    printf("Button h: set high amount\n");
    printf("Button l: set low amount\n");
    printf("Button s: set start time\n");
    printf("Button e: set end time\n");
    printf("Button q: quit\n");
    recordManger.showFilter();
    recordManger.showRecordFilter();
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
    int showFlag = 1;
    while(1){
        if(showFlag) categoryUIshow();
        int button = getch();
        switch(button){
            case 'i': recordManger.insertCategory(); showFlag = 1; break;
            case 'd': recordManger.deleteCategory(); showFlag = 1; break;
            case 'v': recordManger.vaildCategory(); showFlag = 1; break;
            case 's': recordManger.showCategory(); showFlag = 1; break;
            case 'c': recordManger.converseCategory(); showFlag = 1; break;
            case 'q': return; break;
            default: showFlag = 0; 
        }
    } 
}

void filterUI(){
    int showFlag = 1;
    while(1){
        if(showFlag) filterUIshow();
        int button = getch();
        switch(button){
            case 'l': recordManger.setLowAmountFilter(); showFlag = 1; break;
            case 'h': recordManger.setHighAmountFilter(); showFlag = 1; break;
            case 's': recordManger.setStartTimeFilter(); showFlag = 1; break;
            case 'e': recordManger.setEndTimeFilter(); showFlag = 1; break;
            case 'q': return; break;
            default: showFlag = 0; 
        }
    } 
}

