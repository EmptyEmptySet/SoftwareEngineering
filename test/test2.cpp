#include <gtest/gtest.h>
#include "ui.h" // 引入业务头文件
#include "manager.h"


TEST(IntegrationTest, test1){
    map<int, Record> test_records;
    char s[100] = {'\0'};
    for(int i = 0; i< 10; i++){
        Date test_date{2000+i, 1+i, 2*(1+i)};
        Record test_record(i, 1000*i, test_date, s, true, true);
        test_records[i] = test_record;
    }

    for(int i = 2;i<=6; i++){
        for(int j = i+1;i<=9;i++){
            Filter test_filter({2002, 2, 2}, {2007, 2, 2}, i * 1000, j * 1000);
            for (map<int, Record>::iterator it = test_records.begin(); it != test_records.end(); ++it) {
                if((it->second.isHidden == false) && test_filter.check(&(it->second))){
                    EXPECT_EQ(it->first >= max(2, i) && it->first <= min(6, j), 1);
                }
            }
        }
    }
}

TEST(IntegrationTest, test2){
    map<int, Record> test_records;
    char s[100] = {'0','\0'};
    map<int, Category> test_categorys;

    for(int i = 0; i<5; i++){
        test_categorys[i] = Category(i, s);
        s[0] = s[0] + 1;
        test_categorys[i].Cvaild = true;
    }

    for(int i = 0; i< 10; i++){
        Date test_date{2000+i, 1+i, 2*(1+i)};
        Record test_record(i, 1000*i, test_date, s, true, true);
        test_records[i] = test_record;
        test_records[i].CID = i/2;
        test_records[i].Cvaild = test_categorys[i/2].Cvaild;
    }

    for (map<int, Record>::iterator it = test_records.begin(); it != test_records.end(); ++it) {
        if(it->second.Cvaild == true){
            EXPECT_EQ(it->first / 2 == test_categorys[it->second.CID].name[0] - '0', 1);
        }
        else EXPECT_EQ(0, 1);
    }
}