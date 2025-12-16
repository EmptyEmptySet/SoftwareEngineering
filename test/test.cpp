#include <gtest/gtest.h>
#include "ui.h" // 引入业务头文件
#include "manager.h"

//日期比较
TEST(DateTest, test1){
    Date d1{2025, 12, 16};
    Date d2{2025, 12, 16};
    EXPECT_EQ((d1 < d2),0);
}

TEST(DateTest, test2){
    Date d1{2025, 11, 16};
    Date d2{2025, 12, 16};
    EXPECT_EQ((d1 < d2),1);
}

TEST(DateTest, test3){
    Date d1{2025, 12, 16};
    Date d2{2025, 11, 16};
    EXPECT_EQ((d1 < d2),0);
}

TEST(DateTest, test4){
    Date d1{2022, 11, 16};
    Date d2{2025, 12, 16};
    EXPECT_EQ((d1 < d2),1);
}

TEST(DateTest, test5){
    Date d1{2025, 1, 16};
    Date d2{2025, 12, 16};
    EXPECT_EQ((d1 < d2),1);
}

TEST(DateTest, test6){
    Date d1{2025, 12, 6};
    Date d2{2025, 12, 16};
    EXPECT_EQ((d1 < d2),1);
}

TEST(DateTest, test7){
    Date d2{2022, 11, 16};
    Date d1{2025, 12, 16};
    EXPECT_EQ((d1 < d2),0);
}

TEST(DateTest, test8){
    Date d2{2025, 1, 16};
    Date d1{2025, 12, 16};
    EXPECT_EQ((d1 < d2),0);
}

TEST(DateTest, test9){
    Date d2{2025, 12, 6};
    Date d1{2025, 12, 16};
    EXPECT_EQ((d1 < d2),0);
}

TEST(DateTest, test10){
    Date d1{1000, 12, 6};
    Date d2{2025, 12, 16};
    EXPECT_EQ((d1 < d2),1);
}

TEST(DateTest, test11){
    Date d1{10000, 12, 6};
    Date d2{2025, 12, 16};
    EXPECT_EQ((d1 < d2),0);
}

//日期筛选

// Filter(Date startTime, Date endTime, double lowAmount, double highAmount);
//Record(int id, double amount,struct Date time,char* otherInfo, bool isPayment, bool Cvaild);
TEST(CheckTest, test1){
    Date d1{2000, 1, 1};
    Date d2{2025, 12, 31};
    Date d{2010, 6, 6};
    char s[100] = {'\0'};

    Filter test_filter(d1, d2, 0, 10000); 
    Record test_record(1000, 1000, d, s, true, true);
    EXPECT_EQ(test_filter.check(&test_record), 1);
}

TEST(CheckTest, test2){
    Date d1{2000, 1, 1};
    Date d2{2025, 12, 31};
    Date d{2010, 6, 6};
    char s[100] = {'\0'};

    Filter test_filter(d1, d2, 0, 10000);
    Record test_record(1000, 10000, d, s, true, true);
    EXPECT_EQ(test_filter.check(&test_record), 1);
}

TEST(CheckTest, test3){
    Date d1{2000, 1, 1};
    Date d2{2025, 12, 31};
    Date d{2010, 6, 6};
    char s[100] = {'\0'};

    Filter test_filter(d1, d2, 0, 10000);
    Record test_record(1000, 9999, d, s, true, true);
    EXPECT_EQ(test_filter.check(&test_record), 1);
}

TEST(CheckTest, test4){
    Date d1{2000, 1, 1};
    Date d2{2025, 12, 31};
    Date d{2010, 6, 6};
    char s[100] = {'\0'};

    Filter test_filter(d1, d2, 0, 10000);
    Record test_record(1000, 0, d, s, true, true);
    EXPECT_EQ(test_filter.check(&test_record), 1);
}

TEST(CheckTest, test5){
    Date d1{2000, 1, 1};
    Date d2{2025, 12, 31};
    Date d{2010, 6, 6};
    char s[100] = {'\0'};

    Filter test_filter(d1, d2, 0, 10000);
    Record test_record(1000, 1, d, s, true, true);
    EXPECT_EQ(test_filter.check(&test_record), 1);
}

TEST(CheckTest, test6){
    Date d1{2000, 1, 1};
    Date d2{2025, 12, 31};
    Date d{2000, 1, 1};
    char s[100] = {'\0'};

    Filter test_filter(d1, d2, 0, 10000);
    Record test_record(1000, 1000, d, s, true, true);
    EXPECT_EQ(test_filter.check(&test_record), 0);
}

TEST(CheckTest, test7){
    Date d1{2000, 1, 1};
    Date d2{2025, 12, 31};
    Date d{2000, 1, 2};
    char s[100] = {'\0'};

    Filter test_filter(d1, d2, 0, 10000);
    Record test_record(1000, 1000, d, s, true, true);
    EXPECT_EQ(test_filter.check(&test_record), 1);
}

TEST(CheckTest, test8){
    Date d1{2000, 1, 1};
    Date d2{2025, 12, 31};
    Date d{2025, 12, 31};
    char s[100] = {'\0'};

    Filter test_filter(d1, d2, 0, 10000);
    Record test_record(1000, 1000, d, s, true, true);
    EXPECT_EQ(test_filter.check(&test_record), 0);
}

TEST(CheckTest, test9){
    Date d1{2000, 1, 1};
    Date d2{2025, 12, 31};
    Date d{2025, 12, 30};
    char s[100] = {'\0'};

    Filter test_filter(d1, d2, 0, 10000);
    Record test_record(1000, 1000, d, s, true, true);
    EXPECT_EQ(test_filter.check(&test_record), 1);
}


TEST(CheckTest, test10){
    Date d1{2000, 1, 1};
    Date d2{2025, 12, 31};
    Date d{2010, 6, 6};
    char s[100] = {'\0'};

    Filter test_filter(d1, d2, 0, 10000);
    Record test_record(1000, 12000, d, s, true, true);
    EXPECT_EQ(test_filter.check(&test_record), 0);
}

