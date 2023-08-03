#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
struct Lexem {
    Lexem() = default;
    bool type;  // 1 is digit, 0 is operator
    char operation;
    int16_t priority;
    double number;
};

void CalculateQueue(std::queue<Lexem>& que, std::stack<double>& st);

void BinCalculator(std::stack<double>& stack, void (*fn)(std::stack<double>& st, double a, double b) ){
    double a = stack.top();
    stack.pop();
    double b = stack.top();
    stack.pop();
    fn(stack,a,b);
}

void Sum(std::stack<double>& st, double a, double b) {
    st.push(b+a);
}

void Mult(std::stack<double>& st, double a, double b) {
    st.push(b*a);
}

void Div(std::stack<double>& st, double a, double b) {
    st.push(b/a);
}

void Sub(std::stack<double>& st, double a, double b) {
    st.push(b-a);
}

void Mod(std::stack<double>& st, double a, double b) {
    st.push(std::fmod(b,a));
}

void Pow(std::stack<double>& st, double a, double b) {
    st.push(std::pow(b,a));
}

// #############################################################################


void UnaryCalculator(std::stack<double>& stack, void (*fn)(std::stack<double>& st, double a)) {
    double a = stack.top();
    stack.pop();
    fn(stack,a);
}

void Sin(std::stack<double>& st, double a) {
    st.push(std::sin(a));
}

void Cos(std::stack<double>& st, double a) {
    st.push(std::cos(a));
}

void Tan(std::stack<double>& st, double a) {
    st.push(std::tan(a));
}

void Asin(std::stack<double>& st, double a) {
    st.push(std::asin(a));
}

void Acos(std::stack<double>& st, double a) {
    st.push(std::acos(a));
}


void Atan(std::stack<double>& st, double a) {
    st.push(std::atan(a));
}

void Sqrt(std::stack<double>& st, double a) {
    st.push(std::sqrt(a));
}

void Ln(std::stack<double>& st, double a) {
    st.push(std::log10(a));
}

void Log(std::stack<double>& st, double a) {
    st.push(std::log(a));   
}

void Unary_Sum(std::stack<double>& st, double a) {
    st.push(a);
}

void Unary_Sub(std::stack<double>& st, double a) {
    st.push(-a);
}

// ()                       5
// +                        1
// -                        1
// *                        2
// /                        2
// ^                        3
// mod                      2 m

// unary +-                 5 # ~

// cos(x)                   4 c
// sin(x)                   4 s
// tan(x)                   4 t 
// atan(x)                  4 a
// asin(x)                  4 i
// acos(x)                  4 o
// sqrt(x)                  4 q
// ln(x)                    4 l
// log(x)                   4 g