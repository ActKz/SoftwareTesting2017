#include <gtest/gtest.h>
#include "nextDate.h"

TEST( NextDateBoundaryTest, NormalTest){
    EXPECT_STREQ("1900/6/16", NextDate(1900,6,15));
    EXPECT_STREQ("1901/6/16", NextDate(1901,6,15));
    EXPECT_STREQ("1962/6/16", NextDate(1962,6,15));
    EXPECT_STREQ("2024/6/16", NextDate(2024,6,15));
    EXPECT_STREQ("2025/6/16", NextDate(2025,6,15));
    EXPECT_STREQ("1962/6/2", NextDate(1962,6,1));
    EXPECT_STREQ("1962/6/3", NextDate(1962,6,2));
    EXPECT_STREQ("1962/7/1", NextDate(1962,6,30));
    EXPECT_STREQ("Invalid date", NextDate(1962,6,31));
    EXPECT_STREQ("1962/1/16", NextDate(1962,1,15));
    EXPECT_STREQ("1962/2/16", NextDate(1962,2,15));
    EXPECT_STREQ("1962/11/16", NextDate(1962,11,15));
    EXPECT_STREQ("1962/12/16", NextDate(1962,12,15));
}

TEST( NextDateEquivalenceClassTest, WeakNormal){
    EXPECT_STREQ("2000/6/15", NextDate( 2000, 6, 14));
    EXPECT_STREQ("1996/7/30", NextDate( 1996, 7, 29));
    EXPECT_STREQ("Invalid date", NextDate( 2002, 2, 30));
    EXPECT_STREQ("Invalid date", NextDate( 2000, 6, 31));
}
TEST( NextDateEquivalenceClassTest, WeakRobust){
    EXPECT_STREQ("1962/6/16", NextDate(1962,6,15));
    EXPECT_STREQ("Invalid date", NextDate(1962,-1,15));
    EXPECT_STREQ("Invalid date", NextDate(1962,13,15));
    EXPECT_STREQ("Invalid date", NextDate(1962,6,-1));
    EXPECT_STREQ("Invalid date", NextDate(1962,6,32));
    EXPECT_STREQ("Invalid date", NextDate(1899,6,15));
    EXPECT_STREQ("Invalid date", NextDate(2026,6,15));
}
TEST( NextDateEquivalenceClassTest, StrongNormal){
    EXPECT_STREQ("2000/6/15", NextDate( 2000, 6, 14));
    EXPECT_STREQ("1996/6/15", NextDate( 1996, 6, 14));
    EXPECT_STREQ("2002/6/15", NextDate( 2002, 6, 14));
    EXPECT_STREQ("2000/6/30", NextDate( 2000, 6, 29));
    EXPECT_STREQ("1996/6/30", NextDate( 1996, 6, 29));
    EXPECT_STREQ("2002/6/30", NextDate( 2002, 6, 29));
    EXPECT_STREQ("2000/7/1", NextDate( 2000, 6, 30));
    EXPECT_STREQ("1996/7/1", NextDate( 1996, 6, 30));
    EXPECT_STREQ("2002/7/1", NextDate( 2002, 6, 30));
    EXPECT_STREQ("Invalid date", NextDate( 2000, 6, 31));
    EXPECT_STREQ("Invalid date", NextDate( 1996, 6, 31));
    EXPECT_STREQ("Invalid date", NextDate( 2002, 6, 31));
    EXPECT_STREQ("2000/7/15", NextDate( 2000, 7, 14));
    EXPECT_STREQ("1996/7/15", NextDate( 1996, 7, 14));
    EXPECT_STREQ("2002/7/15", NextDate( 2002, 7, 14));
    EXPECT_STREQ("2000/7/30", NextDate( 2000, 7, 29));
    EXPECT_STREQ("1996/7/30", NextDate( 1996, 7, 29));
    EXPECT_STREQ("2002/7/30", NextDate( 2002, 7, 29));
    EXPECT_STREQ("2000/7/31", NextDate( 2000, 7, 30));
    EXPECT_STREQ("1996/7/31", NextDate( 1996, 7, 30));
    EXPECT_STREQ("2002/7/31", NextDate( 2002, 7, 30));
    EXPECT_STREQ("2000/8/1", NextDate( 2000, 7, 31));
    EXPECT_STREQ("1996/8/1", NextDate( 1996, 7, 31));
    EXPECT_STREQ("2002/8/1", NextDate( 2002, 7, 31));
    EXPECT_STREQ("2000/2/15", NextDate( 2000, 2, 14));
    EXPECT_STREQ("1996/2/15", NextDate( 1996, 2, 14));
    EXPECT_STREQ("2002/2/15", NextDate( 2002, 2, 14));
    EXPECT_STREQ("2000/3/1", NextDate( 2000, 2, 29));
    EXPECT_STREQ("1996/3/1", NextDate( 1996, 2, 29));
    EXPECT_STREQ("Invalid date", NextDate( 2002, 2, 29));
    EXPECT_STREQ("Invalid date", NextDate( 2000, 2, 30));
    EXPECT_STREQ("Invalid date", NextDate( 1996, 2, 30));
    EXPECT_STREQ("Invalid date", NextDate( 2002, 2, 30));
    EXPECT_STREQ("Invalid date", NextDate( 2000, 6, 31));
    EXPECT_STREQ("Invalid date", NextDate( 1996, 6, 31));
    EXPECT_STREQ("Invalid date", NextDate( 2002, 6, 31));
}
TEST( NextDateEquivalenceClassTest, StrongRobust){
    EXPECT_STREQ("Invalid date", NextDate( 1900, -1, 15 ));
    EXPECT_STREQ("Invalid date", NextDate( 1900, 6, -1));
    EXPECT_STREQ("Invalid date", NextDate( 1800, 6, 15));
    EXPECT_STREQ("Invalid date", NextDate( 1900, -1, -1));
    EXPECT_STREQ("Invalid date", NextDate( 1800, 6, -1));
    EXPECT_STREQ("Invalid date", NextDate( 1800, -1, 15));
    EXPECT_STREQ("Invalid date", NextDate( 1800, -1, -1));
}

//TEST( NextDateEdgeTest, ){}
TEST( NextDateDecisionTableTest,){
    EXPECT_STREQ( "2001/4/16", NextDate( 2001, 4, 15));
    EXPECT_STREQ( "2001/4/29", NextDate( 2001, 4, 28));
    EXPECT_STREQ( "2001/4/30", NextDate( 2001, 4, 29));
    EXPECT_STREQ( "2001/5/1", NextDate( 2001, 4, 30));
    EXPECT_STREQ( "Invalid date", NextDate( 2001, 4, 31));
    EXPECT_STREQ( "2001/1/16", NextDate( 2001, 1, 15));
    EXPECT_STREQ( "2001/1/29", NextDate( 2001, 1, 28));
    EXPECT_STREQ( "2001/1/30", NextDate( 2001, 1, 29));
    EXPECT_STREQ( "2001/1/31", NextDate( 2001, 1, 30));
    EXPECT_STREQ( "2001/2/1", NextDate( 2001, 1, 31));
    EXPECT_STREQ( "2001/12/16", NextDate( 2001, 12, 15));
    EXPECT_STREQ( "2001/12/29", NextDate( 2001, 12, 28));
    EXPECT_STREQ( "2001/12/30", NextDate( 2001, 12, 29));
    EXPECT_STREQ( "2001/12/31", NextDate( 2001, 12, 30));
    EXPECT_STREQ( "2002/1/1", NextDate( 2001, 12, 31));
    EXPECT_STREQ( "2001/2/16", NextDate( 2001, 2, 15));
    EXPECT_STREQ( "2004/2/29", NextDate( 2004, 2, 28));
    EXPECT_STREQ( "2001/3/1", NextDate( 2001, 2, 28));
    EXPECT_STREQ( "2004/3/1", NextDate( 2004, 2, 29));
    EXPECT_STREQ( "Invalid date", NextDate( 2001, 2, 29));
    EXPECT_STREQ( "Invalid date", NextDate( 2001, 2, 30));
    EXPECT_STREQ( "Invalid date", NextDate( 2001, 2, 31));
}
