#include "Controller.h"
#include <gtest/gtest.h>

TEST(Calc, Default1) {
    std::string expression = "1+1";
    Controller ct;
    double my_result = ct.GetRes(expression,"").second;
    double original_result = 2;
    EXPECT_DOUBLE_EQ(my_result, original_result);
}

TEST(Calc, Default2) {
    std::string expression = "sin(cos(-10^2))*43.1+sqrt(625)*(sin(4)+43.143*log(100)-asin(0.4243))/ln(sin(14.03))*sqrt(0.1)/0.009^(-3)";
    Controller ct;
    double my_result = ct.GetRes(expression,"").second;
    double original_result = sin(cos(pow(-10, 2)))*43.1+sqrt(625)*(sin(4)+43.143*log10(100)-asin(0.4243))/log(sin(14.03))*sqrt(0.1)/pow(0.009, -3);
    EXPECT_DOUBLE_EQ(my_result, original_result);
}

TEST(Calc, Default3) {
    std::string expression = "sin(cos(10^2))*43.1+sqrt(625)*(sin(4)+43.143*log(100)-asin(0.4243))/ln(sin(14.03))*sqrt(0.1)";
    Controller ct;
    double my_result = ct.GetRes(expression,"").second;
    double original_result = sin(cos(pow(10, 2)))*43.1+sqrt(625)*(sin(4)+43.143*log10(100)-asin(0.4243))/log(sin(14.03))*sqrt(0.1);
    EXPECT_DOUBLE_EQ(my_result, original_result);
}

TEST(Calc, Default4) {
    std::string expression = "atan(acos(0.1mod50))";
    Controller ct;
    double my_result = ct.GetRes(expression,"").second;
    double original_result = atan(acos(std::fmod(0.1,50)));
    EXPECT_DOUBLE_EQ(my_result, original_result);
}

TEST(Calc, Default5) {
    std::string expression = "+1+10mod2";
    Controller ct;
    double my_result = ct.GetRes(expression,"").second;
    double original_result = 1+10 % 2;
    EXPECT_DOUBLE_EQ(my_result, original_result);
}

TEST(Calc, Exp1) {
    std::string expression = "-2tan(sqrt(1e3))";
    Controller ct;
    double my_result = ct.GetRes(expression,"").second;
    double original_result = -2*tan(sqrt(1e3));
    EXPECT_DOUBLE_EQ(my_result, original_result);
}

TEST(Calc, Exp2) {
    std::string expression = "1e-3 + 0.1 + 0.1";
    Controller ct;
    double my_result = ct.GetRes(expression,"").second;
    double original_result = 1e-3 + 0.1 + 0.1;
    EXPECT_DOUBLE_EQ(my_result, original_result);
}


TEST(Calc, IncorrectExpression) {
    std::string expression = "(1e-3+0.1+.1)^=--1e1)";
    Controller ct;
    bool is_incorrect = ct.CheckIfInputStringIsOk(expression);
    EXPECT_FALSE(is_incorrect);
}

TEST(Calc, IncorrectExpression2) {
    std::string expression = "sss(3)";
    std::string expression2 = "acss(3)";
    std::string expression3 = "atss(3)";
    Controller ct;
    bool is_incorrect = ct.CheckIfInputStringIsOk(expression);
    bool is_incorrect2 = ct.CheckIfInputStringIsOk(expression2);
    bool is_incorrect3 = ct.CheckIfInputStringIsOk(expression3);
    EXPECT_FALSE(is_incorrect);
    EXPECT_FALSE(is_incorrect2);
    EXPECT_FALSE(is_incorrect3);
}

TEST(Calc, IncorrectExpression3) {
    std::string str = "sin(3x)";
    std::string x = "";
    Controller ct;
    ct.GetRes(str,x);
    std::string str2 = "sin(3x)";
    std::string x2 = "4";
    ct.GetRes(str2,x2);
}

TEST(Calc, IncorrectEdges) {
    Controller ct;
    std::vector<double> vector(4);
    std::vector<std::string> edges(4);
    edges[0] = "1";
    edges[1] = "1";
    edges[2] = "1";
    edges[3] = "1.a";
    std::vector<std::string> vec = ct.ValidateGraphEdges(vector,edges);
    double qwe = vector[0];
    EXPECT_EQ(qwe,1);
}

TEST(Calc, GraphMaker) {
    Controller ct;
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> ev = {1,2,3,4};
    std::string str = "tan(x)";
    double i = ev[0];
    ct.MakeGraph(x,y,ev,str,i);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}