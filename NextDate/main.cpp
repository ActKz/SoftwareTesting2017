#include <gtest/gtest.h>
#include "nextDate.h"
#include <string>
class TestCase{
    public:
        int year, month, day;
        string output;
        TestCase(int y, int m, int d, string result){
            year = y;
            month = m;
            day = d;
            output = result;
        }
};
TestCase bva_WN[] = {
    TestCase(1900,6 ,15,"1900/6/16"),
    TestCase(1901,6 ,15,"1901/6/16"),
    TestCase(1962,6 ,15,"1962/6/16"),
    TestCase(2024,6 ,15,"2024/6/16"),
    TestCase(2025,6 ,15,"2025/6/16"),
    TestCase(1962,1 ,15,"1962/1/16"),
    TestCase(1962,2 ,15,"1962/2/16"),
    TestCase(1962,11,15,"1962/11/16"),
    TestCase(1962,12,15,"1962/12/16"),
    TestCase(1962,6 ,1 ,"1962/6/2"),
    TestCase(1962,6 ,2 ,"1962/6/3"),
    TestCase(1962,6 ,30,"1962/7/1"),
    TestCase(1962,6 ,31,"Invalid date"),
};
TestCase bva_SN[] = {
    TestCase(1900,6 ,15,"1900/6/16"),
    TestCase(1962,1 ,15,"1962/1/16"),
    TestCase(1962,6 ,1 ,"1962/6/2"),
    TestCase(1900,1 ,15,"1900/1/16"),
    TestCase(1900,6 ,1 ,"1900/6/2"),
    TestCase(1962,1 ,1 ,"1962/1/2"),
    TestCase(1900,1 ,1 ,"1900/1/2"),
};
TestCase bva_WR[] = {
    TestCase(1899,6 ,15,"Out of range value"),
    TestCase(1900,6 ,15,"1900/6/16"),
    TestCase(1901,6 ,15,"1901/6/16"),
    TestCase(1962,6 ,15,"1962/6/16"),
    TestCase(2024,6 ,15,"2024/6/16"),
    TestCase(2025,6 ,15,"2025/6/16"),
    TestCase(2026,6 ,15,"Out of range value"),
    TestCase(1962,0 ,15,"Out of range value"),
    TestCase(1962,1 ,15,"1962/1/16"),
    TestCase(1962,2 ,15,"1962/2/16"),
    TestCase(1962,11,15,"1962/11/16"),
    TestCase(1962,12,15,"1962/12/16"),
    TestCase(1962,13,15,"Out of range value"),
    TestCase(1962,6 ,0 ,"Out of range value"),
    TestCase(1962,6 ,1 ,"1962/6/2"),
    TestCase(1962,6 ,2 ,"1962/6/3"),
    TestCase(1962,6 ,30,"1962/7/1"),
    TestCase(1962,6 ,31,"Invalid date"),
    TestCase(1962,6 ,32,"Out of range value"),
};
TestCase bva_SR[] = {
    TestCase(1899,6 ,15,"Out of range value"),
    TestCase(1962,0 ,15,"Out of range value"),
    TestCase(1962,6 ,0 ,"Out of range value"),
    TestCase(1899,0 ,15,"Out of range value"),
    TestCase(1899,6 ,0 ,"Out of range value"),
    TestCase(1962,0 ,0 ,"Out of range value"),
    TestCase(1899,0 ,0 ,"Out of range value"),
};
TestCase ect_WN[] = {
    TestCase(2000,6 ,14,"2000/6/15"),
    TestCase(1996,7 ,29,"1996/7/30"),
    TestCase(2002,2 ,30,"Invalid date"),
    TestCase(2000,6 ,31,"Invalid date"),
};
TestCase ect_SN[] = {
    TestCase(2000,6 ,14,"2000/6/15"),
    TestCase(1996,6 ,14,"1996/6/15"),
    TestCase(2002,6 ,14,"2002/6/15"),
    TestCase(2000,6 ,29,"2000/6/30"),
    TestCase(1996,6 ,29,"1996/6/30"),
    TestCase(2002,6 ,29,"2002/6/30"),
    TestCase(2000,6 ,30,"2000/7/1"),
    TestCase(1996,6 ,30,"1996/7/1"),
    TestCase(2002,6 ,30,"2002/7/1"),
    TestCase(2000,6 ,31,"Invalid date"),
    TestCase(1996,6 ,31,"Invalid date"),
    TestCase(2002,6 ,31,"Invalid date"),
    TestCase(2000,7 ,14,"2000/7/15"),
    TestCase(1996,7 ,14,"1996/7/15"),
    TestCase(2002,7 ,14,"2002/7/15"),
    TestCase(2000,7 ,29,"2000/7/30"),
    TestCase(1996,7 ,29,"1996/7/30"),
    TestCase(2002,7 ,29,"2002/7/30"),
    TestCase(2000,7 ,30,"2000/7/31"),
    TestCase(1996,7 ,30,"1996/7/31"),
    TestCase(2002,7 ,30,"2002/7/31"),
    TestCase(2000,7 ,31,"2000/8/1"),
    TestCase(1996,7 ,31,"1996/8/1"),
    TestCase(2002,7 ,31,"2002/8/1"),
    TestCase(2000,2 ,14,"2000/2/15"),
    TestCase(1996,2 ,14,"1996/2/15"),
    TestCase(2002,2 ,14,"2002/2/15"),
    TestCase(2000,2 ,29,"2000/3/1"),
    TestCase(1996,2 ,29,"1996/3/1"),
    TestCase(2002,2 ,29,"Invalid date"),
    TestCase(2000,2 ,30,"Invalid date"),
    TestCase(1996,2 ,30,"Invalid date"),
    TestCase(2002,2 ,30,"Invalid date"),
    TestCase(2000,2 ,31,"Invalid date"),
    TestCase(1996,2 ,31,"Invalid date"),
    TestCase(2002,2 ,31,"Invalid date"),
};
TestCase edg_SR[] = {
    TestCase(1899,1 ,1 ,"Out of range value"),
    TestCase(1900,0 ,1 ,"Out of range value"),
    TestCase(1900,1 ,0 ,"Out of range value"),
    TestCase(1899,0 ,1 ,"Out of range value"),
    TestCase(1899,1 ,0 ,"Out of range value"),
    TestCase(1900,0 ,0 ,"Out of range value"),
    TestCase(1899,0 ,0 ,"Out of range value"),
    TestCase(1900,1 ,1 ,"1900/1/2"),
    TestCase(1901,1 ,1 ,"1901/1/2"),
    TestCase(2024,1 ,1 ,"2024/1/2"),
    TestCase(2025,1 ,1 ,"2025/1/2"),
    TestCase(1900,2 ,1 ,"1900/2/2"),
    TestCase(1901,2 ,1 ,"1901/2/2"),
    TestCase(2024,2 ,1 ,"2024/2/2"),
    TestCase(2025,2 ,1 ,"2025/2/2"),
    TestCase(1900,11,1 ,"1900/11/2"),
    TestCase(1901,11,1 ,"1901/11/2"),
    TestCase(2024,11,1 ,"2024/11/2"),
    TestCase(2025,11,1 ,"2025/11/2"),
    TestCase(1900,12,1 ,"1900/12/2"),
    TestCase(1901,12,1 ,"1901/12/2"),
    TestCase(2024,12,1 ,"2024/12/2"),
    TestCase(2025,12,1 ,"2025/12/2"),
    TestCase(1900,1 ,2 ,"1900/1/3"),
    TestCase(1901,1 ,2 ,"1901/1/3"),
    TestCase(2024,1 ,2 ,"2024/1/3"),
    TestCase(2025,1 ,2 ,"2025/1/3"),
    TestCase(1900,2 ,2 ,"1900/2/3"),
    TestCase(1901,2 ,2 ,"1901/2/3"),
    TestCase(2024,2 ,2 ,"2024/2/3"),
    TestCase(2025,2 ,2 ,"2025/2/3"),
    TestCase(1900,11,2 ,"1900/11/3"),
    TestCase(1901,11,2 ,"1901/11/3"),
    TestCase(2024,11,2 ,"2024/11/3"),
    TestCase(2025,11,2 ,"2025/11/3"),
    TestCase(1900,12,2 ,"1900/12/3"),
    TestCase(1901,12,2 ,"1901/12/3"),
    TestCase(2024,12,2 ,"2024/12/3"),
    TestCase(2025,12,2 ,"2025/12/3"),
    TestCase(1900,1 ,30,"1900/1/31"),
    TestCase(1901,1 ,30,"1901/1/31"),
    TestCase(2024,1 ,30,"2024/1/31"),
    TestCase(2025,1 ,30,"2025/1/31"),
    TestCase(1900,2 ,30,"Invalid date"),
    TestCase(1901,2 ,30,"Invalid date"),
    TestCase(2024,2 ,30,"Invalid date"),
    TestCase(2025,2 ,30,"Invalid date"),
    TestCase(1900,11,30,"1900/12/1"),
    TestCase(1901,11,30,"1901/12/1"),
    TestCase(2024,11,30,"2024/12/1"),
    TestCase(2025,11,30,"2025/12/1"),
    TestCase(1900,12,30,"1900/12/31"),
    TestCase(1901,12,30,"1901/12/31"),
    TestCase(2024,12,30,"2024/12/31"),
    TestCase(2025,12,30,"2025/12/31"),
    TestCase(1900,1 ,31,"1900/2/1"),
    TestCase(1901,1 ,31,"1901/2/1"),
    TestCase(2024,1 ,31,"2024/2/1"),
    TestCase(2025,1 ,31,"2025/2/1"),
    TestCase(1900,2 ,31,"Invalid date"),
    TestCase(1901,2 ,31,"Invalid date"),
    TestCase(2024,2 ,31,"Invalid date"),
    TestCase(2025,2 ,31,"Invalid date"),
    TestCase(1900,11,31,"Invalid date"),
    TestCase(1901,11,31,"Invalid date"),
    TestCase(2024,11,31,"Invalid date"),
    TestCase(2025,11,31,"Invalid date"),
    TestCase(1900,12,31,"1901/1/1"),
    TestCase(1901,12,31,"1902/1/1"),
    TestCase(2024,12,31,"2025/1/1"),
    TestCase(2025,12,31,"2026/1/1"),
};
TestCase dtt[] = {
    TestCase(2001,4 ,15,"2001/4/16"),
    TestCase(2001,4 ,28,"2001/4/29"),
    TestCase(2001,4 ,29,"2001/4/30"),
    TestCase(2001,4 ,30,"2001/5/1"),
    TestCase(2001,4 ,31,"Invalid date"),
    TestCase(2001,1 ,15,"2001/1/16"),
    TestCase(2001,1 ,28,"2001/1/29"),
    TestCase(2001,1 ,29,"2001/1/30"),
    TestCase(2001,1 ,31,"2001/2/1"),
    TestCase(2001,12,15,"2001/12/16"),
    TestCase(2001,12,28,"2001/12/29"),
    TestCase(2001,12,29,"2001/12/30"),
    TestCase(2001,12,31,"2002/1/1"),
    TestCase(2001,2 ,15,"2001/2/16"),
    TestCase(2004,2 ,28,"2004/2/29"),
    TestCase(2001,2 ,28,"2001/3/1"),
    TestCase(2004,2 ,29,"2004/3/1"),
    TestCase(2001,2 ,29,"Invalid date"),
    TestCase(2001,2 ,30,"Invalid date"),
    TestCase(2001,2 ,31,"Invalid date"),
};
TEST( NextDate, BoundaryValueTest){
    int size = sizeof(bva_WN)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(NextDate(bva_WN[i].year, bva_WN[i].month, bva_WN[i].day), bva_WN[i].output );
    }
    size = sizeof(bva_SN)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(NextDate(bva_SN[i].year, bva_SN[i].month, bva_SN[i].day), bva_SN[i].output );
    }
    size = sizeof(bva_WR)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(NextDate(bva_WR[i].year, bva_WR[i].month, bva_WR[i].day), bva_WR[i].output );
    }
    size = sizeof(bva_SR)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(NextDate(bva_SR[i].year, bva_SR[i].month, bva_SR[i].day), bva_SR[i].output );
    }
}
TEST( NextDate, EquivalenceClassTest){
    int size = sizeof(ect_WN)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(NextDate(ect_WN[i].year, ect_WN[i].month, ect_WN[i].day), ect_WN[i].output );
    }
    size = sizeof(ect_SN)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(NextDate(ect_SN[i].year, ect_SN[i].month, ect_SN[i].day), ect_SN[i].output );
    }
}
TEST( NextDate, EdgeTest){
    int size = sizeof(edg_SR)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(NextDate(edg_SR[i].year, edg_SR[i].month, edg_SR[i].day), edg_SR[i].output );
    }
}
TEST( NextDate, DecisionTableTest){
    int size = sizeof(dtt)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(NextDate(dtt[i].year, dtt[i].month, dtt[i].day), dtt[i].output );
    }
}
