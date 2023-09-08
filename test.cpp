#include "Controller.h"
#include <gtest/gtest.h>

TEST(Calc, Default1) {
    std::string expression = "1+1";
    Controller ct;
    double my_result = ct.GetRes(expression,"").second;
    double original_result = 1 + 1;
    EXPECT_DOUBLE_EQ(my_result, original_result);
}

TEST(Calc, Default2) {
    std::string expression = "sin(cos(10^2))*43.1+sqrt(625)*(sin(4)+43.143*log(100)-asin(0.4243))/ln(sin(14.03))*sqrt(0.1)/0.009^(-3)";
    Controller ct;
    double my_result = ct.GetRes(expression,"").second;
    double original_result = sin(cos(pow(10, 2)))*43.1+sqrt(625)*(sin(4)+43.143*log10(100)-asin(0.4243))/log(sin(14.03))*sqrt(0.1)/pow(0.009, -3);
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
    std::string expression = "10mod2";
    Controller ct;
    double my_result = ct.GetRes(expression,"").second;
    double original_result = 10 % 2;
    EXPECT_DOUBLE_EQ(my_result, original_result);
}

TEST(Calc, Exp1) {
    std::string expression = "tan(sqrt(1e3))";
    Controller ct;
    double my_result = ct.GetRes(expression,"").second;
    double original_result = tan(sqrt(1e3));
    EXPECT_DOUBLE_EQ(my_result, original_result);
}

TEST(Calc, Exp2) {
    std::string expression = "1e-3 + 0.1 + 0.1";
    Controller ct;
    double my_result = ct.GetRes(expression,"").second;
    double original_result = 1e-3 + 0.1 + 0.1;
    EXPECT_DOUBLE_EQ(my_result, original_result);
}

// TEST(Calc, Exp3) {
//     std::string expression = "(1e-3+0.1+0.1)^(-1e1)";
//     Controller ct;
//     double my_result = ct.GetRes(expression,"").second;
//     double original_result = pow((1e-3 + 0.1 + 0.1), -1e1);
//     EXPECT_DOUBLE_EQ(my_result, original_result);
// }

TEST(Calc, IncorrectExpression) {
    std::string expression = "(1e-3+0.1+.1)^=--1e1)";
    Controller ct;
    bool is_incorrect = ct.CheckIfInputStringIsOk(expression);
    EXPECT_FALSE(is_incorrect);
}

TEST(Calc, IncorrectExpression2) {
    std::string expression = "sin";
    Controller ct;
    bool is_incorrect = ct.CheckIfInputStringIsOk(expression);
    EXPECT_FALSE(is_incorrect);
}