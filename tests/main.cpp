#include <gtest/gtest.h>

TEST( TriangleBoundaryValueTest, RobustTest){
    EXPECT_STREQ("Equilateral", triangle(100,100,100));
    EXPECT_STREQ("Isosceles", triangle(1,100,100));
    EXPECT_STREQ("Isosceles", triangle(100,1,100));
    EXPECT_STREQ("Isosceles", triangle(100,100,1));
    EXPECT_STREQ("Isosceles", triangle(2,100,100));
    EXPECT_STREQ("Isosceles", triangle(100,2,100));
    EXPECT_STREQ("Isosceles", triangle(100,100,2));
    EXPECT_STREQ("Isosceles", triangle(199,100,100));
    EXPECT_STREQ("Isosceles", triangle(100,199,100));
    EXPECT_STREQ("Isosceles", triangle(100,100,199));
    EXPECT_STREQ("Not a triangle", triangle(200,100,100));
    EXPECT_STREQ("Not a triangle", triangle(100,200,100));
    EXPECT_STREQ("Not a triangle", triangle(100,100,200));
    EXPECT_STREQ("Not a triangle", triangle(0,100,100));
    EXPECT_STREQ("Not a triangle", triangle(100,0,100));
    EXPECT_STREQ("Not a triangle", triangle(100,100,0));
    EXPECT_STREQ("Exceed upper bound", triangle(201,100,100));
    EXPECT_STREQ("Exceed upper bound", triangle(100,201,100));
    EXPECT_STREQ("Exceed upper bound", triangle(100,100,201));


}
TEST( TriangleEquivalenceClassTest, WeakNormal){
    EXPECT_STREQ("Equilateral", triangle( 5, 5, 5));
    EXPECT_STREQ("Isosceles", triangle( 2, 2, 3));
    EXPECT_STREQ("Scalene", triangle( 3, 4, 5));
    EXPECT_STREQ("Not a triangle", triangle( 4 ,1 ,2));
}
//TEST( TriangleEquivalenceClassTest, WeakRobust){
//}
TEST( TriangleEquivalenceClassTest, StrongNormal){
    EXPECT_STREQ("Not a triangle", triangle( -1, 5, 5));
    EXPECT_STREQ("Not a triangle", triangle( 5, -1, 5));
    EXPECT_STREQ("Not a triangle", triangle( 5, 5, -1));
    EXPECT_STREQ("Exceed upper bound", triangle( 201, 5, 5));
    EXPECT_STREQ("Exceed upper bound", triangle( 5, 201, 5));
    EXPECT_STREQ("Exceed upper bound", triangle( 5, 5, 201));
}
TEST( TriangleEquivalenceClassTest, StrongRobust){
    EXPECT_STREQ("Not a triangle", triangle( -1, 5, 5));
    EXPECT_STREQ("Not a triangle", triangle( 5, -1, 5));
    EXPECT_STREQ("Not a triangle", triangle( 5, 5, -1));
    EXPECT_STREQ("Not a triangle", triangle( -1, -1, 5));
    EXPECT_STREQ("Not a triangle", triangle( 5, -1, -1));
    EXPECT_STREQ("Not a triangle", triangle( -1, 5, -1));
    EXPECT_STREQ("Not a triangle", triangle( -1, -1, -1));
}

//TEST( TriangleEdgeTest, RobustTest){
//}

//TEST( TriangleDecisionTableTest,

