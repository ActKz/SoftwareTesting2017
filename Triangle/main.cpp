#include "triangle.h"
#include <gtest/gtest.h>
#include <string.h>
#include <vector>
using namespace std;
class TestCase{
    public:
        float a,b,c;
        string output;
        TestCase(float aa, float bb, float cc, string result){
            a = aa;
            b = bb;
            c = cc;
            output = result;
        }
};
TestCase bva_WN[] = {
    TestCase(100,100,100,"Equilateral"),
    TestCase(1  ,100,100,"Isosceles"  ),
    TestCase(100,1  ,100,"Isosceles"  ),
    TestCase(100,100,1  ,"Isosceles"  ),
    TestCase(2  ,100,100,"Isosceles"  ),
    TestCase(100,2  ,100,"Isosceles"  ),
    TestCase(100,100,2  ,"Isosceles"  ),
    TestCase(199,100,100,"Isosceles"  ),
    TestCase(100,199,100,"Isosceles"  ),
    TestCase(100,100,199,"Isosceles"  ),
    TestCase(200,100,100,"Not a triangle"),
    TestCase(100,200,100,"Not a triangle"),
    TestCase(100,100,200,"Not a triangle")
};
TestCase bva_SN[] = {
    TestCase(1  ,100,100,"Isosceles"),
    TestCase(100,1  ,100,"Isosceles"),
    TestCase(100,100,1  ,"Isosceles"),
    TestCase(1  ,1  ,100,"Not a triangle"),
    TestCase(1  ,100,1  ,"Not a triangle"),
    TestCase(100,1  ,1  ,"Not a triangle"),
    TestCase(1  ,1  ,1  ,"Equilateral"),
    TestCase(200,100,100,"Not a triangle"),
    TestCase(100,200,100,"Not a triangle"),
    TestCase(100,100,200,"Not a triangle"),
    TestCase(200,200,100,"Isosceles"),
    TestCase(200,100,200,"Isosceles"),
    TestCase(100,200,200,"Isosceles"),
    TestCase(200,200,200,"Equilateral"),
};
TestCase bva_WR[] = {
    TestCase(0  ,100,100,"Out of range value"),
    TestCase(1  ,100,100,"Isosceles"),
    TestCase(2  ,100,100,"Isosceles"),
    TestCase(100,100,100,"Equilateral"),
    TestCase(199,100,100,"Isosceles"),
    TestCase(200,100,100,"Not a triangle"),
    TestCase(201,100,100,"Out of range value"),
    TestCase(100,0  ,100,"Out of range value"),
    TestCase(100,1  ,100,"Isosceles"),
    TestCase(100,2  ,100,"Isosceles"),
    TestCase(100,199,100,"Isosceles"),
    TestCase(100,200,100,"Not a triangle"),
    TestCase(100,201,100,"Out of range value"),
    TestCase(100,100,0  ,"Out of range value"),
    TestCase(100,100,1  ,"Isosceles"),
    TestCase(100,100,2  ,"Isosceles"),
    TestCase(100,100,199,"Isosceles"),
    TestCase(100,100,200,"Not a triangle"),
    TestCase(100,100,201,"Out of range value"),
};
TestCase bva_SR[] = {
    TestCase(0  ,100,100,"Out of range value"),
    TestCase(100,0  ,100,"Out of range value"),
    TestCase(100,100,0  ,"Out of range value"),
    TestCase(0  ,0  ,100,"Out of range value"),
    TestCase(0  ,100,0  ,"Out of range value"),
    TestCase(100,0  ,0  ,"Out of range value"),
    TestCase(0  ,0  ,0  ,"Out of range value"),
    TestCase(201,100,100,"Out of range value"),
    TestCase(100,201,100,"Out of range value"),
    TestCase(100,100,201,"Out of range value"),
    TestCase(201,201,100,"Out of range value"),
    TestCase(201,100,201,"Out of range value"),
    TestCase(100,201,201,"Out of range value"),
    TestCase(201,201,201,"Out of range value"),
};
TestCase ect_WN[] = {
    TestCase(3  ,3  ,3  ,"Equilateral"),
    TestCase(2  ,2  ,3  ,"Isosceles"),
    TestCase(3  ,4  ,5  ,"Scalene"),
    TestCase(1  ,1  ,2  ,"Not a triangle"),
};
TestCase ect_WR[] = {
    TestCase(0  ,3  ,3  ,"Out of range value"),
    TestCase(3  ,0  ,3  ,"Out of range value"),
    TestCase(3  ,3  ,0  ,"Out of range value"),
    TestCase(201,3  ,3  ,"Out of range value"),
    TestCase(3  ,201,3  ,"Out of range value"),
    TestCase(3  ,3  ,201,"Out of range value"),
};
TestCase ect_SR[] = {
    TestCase(0  ,3  ,3  ,"Out of range value"),
    TestCase(3  ,0  ,3  ,"Out of range value"),
    TestCase(3  ,3  ,0  ,"Out of range value"),
    TestCase(0  ,0  ,3  ,"Out of range value"),
    TestCase(0  ,3  ,0  ,"Out of range value"),
    TestCase(3  ,0  ,0  ,"Out of range value"),
    TestCase(0  ,0  ,0  ,"Out of range value"),
};
TestCase edg_SR[] = {
    TestCase(0 ,60 ,131,"Out of range value"),
    TestCase(1 ,60 ,131,"Not a triangle"),
    TestCase(2 ,60 ,131,"Not a triangle"),
    TestCase(59,60 ,131,"Not a triangle"),
    TestCase(0 ,61 ,131,"Out of range value"),
    TestCase(1 ,61 ,131,"Not a triangle"),
    TestCase(2 ,61 ,131,"Not a triangle"),
    TestCase(59,61 ,131,"Not a triangle"),
    TestCase(0 ,129,131,"Out of range value"),
    TestCase(1 ,129,131,"Not a triangle"),
    TestCase(2 ,129,131,"Not a triangle"),
    TestCase(59,129,131,"Scalene"),
    TestCase(0 ,130,131,"Out of range value"),
    TestCase(1 ,130,131,"Not a triangle"),
    TestCase(2 ,130,131,"Scalene"),
    TestCase(59,130,131,"Scalene"),
    TestCase(0 ,60 ,199,"Out of range value"),
    TestCase(1 ,60 ,199,"Not a triangle"),
    TestCase(2 ,60 ,199,"Not a triangle"),
    TestCase(59,60 ,199,"Not a triangle"),
    TestCase(0 ,61 ,199,"Out of range value"),
    TestCase(1 ,61 ,199,"Not a triangle"),
    TestCase(2 ,61 ,199,"Not a triangle"),
    TestCase(59,61 ,199,"Not a triangle"),
    TestCase(0 ,129,199,"Out of range value"),
    TestCase(1 ,129,199,"Not a triangle"),
    TestCase(2 ,129,199,"Not a triangle"),
    TestCase(59,129,199,"Not a triangle"),
    TestCase(0 ,130,199,"Out of range value"),
    TestCase(1 ,130,199,"Not a triangle"),
    TestCase(2 ,130,199,"Not a triangle"),
    TestCase(59,130,199,"Not a triangle"),
    TestCase(0 ,60 ,200,"Out of range value"),
    TestCase(1 ,60 ,200,"Not a triangle"),
    TestCase(2 ,60 ,200,"Not a triangle"),
    TestCase(59,60 ,200,"Not a triangle"),
    TestCase(0 ,61 ,200,"Out of range value"),
    TestCase(1 ,61 ,200,"Not a triangle"),
    TestCase(2 ,61 ,200,"Not a triangle"),
    TestCase(59,61 ,200,"Not a triangle"),
    TestCase(0 ,129,200,"Out of range value"),
    TestCase(1 ,129,200,"Not a triangle"),
    TestCase(2 ,129,200,"Not a triangle"),
    TestCase(59,129,200,"Not a triangle"),
    TestCase(0 ,130,200,"Out of range value"),
    TestCase(1 ,130,200,"Not a triangle"),
    TestCase(2 ,130,200,"Not a triangle"),
    TestCase(59,130,200,"Not a triangle"),
    TestCase(0 ,60 ,201,"Out of range value"),
    TestCase(1 ,60 ,201,"Out of range value"),
    TestCase(2 ,60 ,201,"Out of range value"),
    TestCase(59,60 ,201,"Out of range value"),
    TestCase(0 ,61 ,201,"Out of range value"),
    TestCase(1 ,61 ,201,"Out of range value"),
    TestCase(2 ,61 ,201,"Out of range value"),
    TestCase(59,61 ,201,"Out of range value"),
    TestCase(0 ,129,201,"Out of range value"),
    TestCase(1 ,129,201,"Out of range value"),
    TestCase(2 ,129,201,"Out of range value"),
    TestCase(59,129,201,"Out of range value"),
    TestCase(0 ,130,201,"Out of range value"),
    TestCase(1 ,130,201,"Out of range value"),
    TestCase(2 ,130,201,"Out of range value"),
    TestCase(59,130,201,"Out of range value"),
};
TestCase dtt[] = {
    TestCase(4  ,1  ,2  ,"Not a triangle"),
    TestCase(1  ,4  ,2  ,"Not a triangle"),
    TestCase(1  ,2  ,4  ,"Not a triangle"),
    TestCase(5  ,5  ,5  ,"Equilateral"),
    TestCase(2  ,2  ,3  ,"Isosceles"),
    TestCase(2  ,3  ,2  ,"Isosceles"),
    TestCase(3  ,2  ,2  ,"Isosceles"),
    TestCase(3  ,4  ,5  ,"Scalene"),
};
TEST( Triangle, BoundaryValueTest){
    int size = sizeof(bva_WN)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(triangle(bva_WN[i].a, bva_WN[i].b, bva_WN[i].c ), bva_WN[i].output);
    }
    size = sizeof(bva_SN)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(triangle(bva_SN[i].a, bva_SN[i].b, bva_SN[i].c ), bva_SN[i].output);
    }
    size = sizeof(bva_WR)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(triangle(bva_WR[i].a, bva_WR[i].b, bva_WR[i].c ), bva_WR[i].output);
    }
    size = sizeof(bva_SR)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(triangle(bva_SR[i].a, bva_SR[i].b, bva_SR[i].c ), bva_SR[i].output);
    }
}
TEST( Triangle, EquivalenceClassTest){
    int size = sizeof(ect_WN)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(triangle(ect_WN[i].a, ect_WN[i].b, ect_WN[i].c ), ect_WN[i].output);
    }
    size = sizeof(ect_WR)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(triangle(ect_WR[i].a, ect_WR[i].b, ect_WR[i].c ), ect_WR[i].output);
    }
    size = sizeof(ect_SR)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(triangle(ect_SR[i].a, ect_SR[i].b, ect_SR[i].c ), ect_SR[i].output);
    }
}
TEST( Triangle, EdgeTest){
    int size = sizeof(edg_SR)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(triangle(edg_SR[i].a, edg_SR[i].b, edg_SR[i].c ), edg_SR[i].output);
    }
}
TEST( Triangle, DecisionTableTest){
    int size = sizeof(dtt)/sizeof(TestCase);
    for(int i = 0; i < size; i++){
        EXPECT_EQ(triangle(dtt[i].a, dtt[i].b, dtt[i].c ), dtt[i].output);
    }
}
