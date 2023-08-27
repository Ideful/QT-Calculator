#ifndef SRC_HEADER_H
#define SRC_HEADER_H
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include "errorchecker.h"

struct Lexem {
    // Lexem():type_(0),operation_(0),priority_(0),number(0) {};
    Lexem() = default;
    bool type_;  // 1 is digit, 0 is operator
    char operation_;
    int16_t priority_;
    long double number_;
};


void Sum(std::stack<double>& st, double& a, double& b) {
    st.push(b+a);
}

void Mult(std::stack<double>& st, double& a, double& b) {
    st.push(b*a);
}

void Div(std::stack<double>& st, double& a, double& b) {
    st.push(b/a);
}

void Sub(std::stack<double>& st, double& a, double& b) {
    st.push(b-a);
}

void Mod(std::stack<double>& st, double& a, double& b) {
    st.push(std::fmod(b,a));
}

void Pow(std::stack<double>& st, double& a, double& b) {
    st.push(std::pow(b,a));
}

// #############################################################################


void UnaryCalculator(std::stack<double>& stack, void (*fn)(std::stack<double>& st, double& a)) {
    double a = stack.top();
    stack.pop();
    fn(stack,a);
}

void Sin(std::stack<double>& st, double& a) {
    st.push(std::sin(a));
}

void Cos(std::stack<double>& st, double& a) {
    st.push(std::cos(a));
}

void Tan(std::stack<double>& st, double& a) {
    st.push(std::tan(a));
}

void Asin(std::stack<double>& st, double& a) {
    st.push(std::asin(a));
}

void Acos(std::stack<double>& st, double& a) {
    st.push(std::acos(a));
}


void Atan(std::stack<double>& st, double& a) {
    st.push(std::atan(a));
}

void Sqrt(std::stack<double>& st, double& a) {
    st.push(std::sqrt(a));
}

void Ln(std::stack<double>& st, double& a) {
    st.push(std::log(a));
}

void Log(std::stack<double>& st, double& a) {
    st.push(std::log10(a));   
}

void Unary_Sum(std::stack<double>& st, double& a) {
    st.push(a);
}

void Unary_Sub(std::stack<double>& st, double& a) {
    st.push(-a);
}

Lexem LongFnToLexem(std::string::iterator& iter, size_t& len) {
    switch (*iter) {
        case 'm':       // mod
            ++iter;
            if ( *iter == 'o') {
                len = 3;
                return {false, 'm',2,0};
            }
            break;
        case 'c':       // cos
            if ( *(++iter) == 'o') {
                len = 3;
                return {false, 'c',2,0};
            }
            break;
        case 's':       // sin s
        ++iter;
            if ( *iter == 'i' ) {
                len = 3;
                return {false, 's',4,0};
            } else {    // sqrt q   
                len = 4;
                return {false, 'q',4,0};
            }    
            break;  
        case 't':       // tan t
            len = 3;
            return {false, 't',4,0};
            break;
        case 'a':
            ++iter;
            if (*iter == 'c') {     // acos
                len = 4; 
                return {false, 'o',4,0};
            }    
            else if (*iter == 's') {    // asin
                len = 4;
                return {false, 'i',4,0};
            }    
            else if (*iter == 't') {    // atan
                len = 4;
                return {false, 'a',4,0};
            }    
            break;
        case 'l':
            ++iter;
            if ( *iter == 'n') {                 // ln l
                len = 2;
                return {false, 'l',4,0};
            } else {                                 // log g
                len = 3;    
                return {false, 'g',4,0};
            }    
            break;  
    }
    return {};
}


void FnToLex(std::string::iterator& iter,Lexem& lex, size_t& i) {   // add unary
    switch (*iter) {
        case '+':
            lex.operation_ = '+';
            lex.priority_ = 1;
            i = 1;
            break;
        case '-':
            lex.operation_= '-';
            lex.priority_  = 1;  
            i = 1;   
            break;   
        case '#':
            lex.operation_ = '#';
            lex.priority_ = 5;
            i = 1;
            break;
        case '~':
            lex.operation_= '~';
            lex.priority_  = 5;  
            i = 1;   
            break;  
        case '*':
            lex.operation_= '*';
            lex.priority_  = 2;
            i = 1;
            break;   
        case '/':
            lex.operation_= '/';
            lex.priority_  = 2;
            i = 1;
            break;
        case '^':
            lex.operation_= '^';
            lex.priority_  = 3;
            i = 1;
            break;
        case '(':
            lex.operation_= '(';
            lex.priority_  = 0;
            i = 1;
            break;
        case ')':
            lex.operation_= ')';
            lex.priority_  = 0;
            i = 1;
            break;
        default:
            lex = LongFnToLexem(iter,i);
    }
    lex.type_ = false;
    lex.number_ = 0;
}

bool CheckIfFn(Lexem& lex) {
    std::string fn = "(cstaioqlg";
    return (fn.find(lex.operation_) == std::string::npos) ? false : true;
}

void LexProcessor(std::stack<Lexem>& stack, Lexem& lex, std::queue<Lexem>& que) {
    if (CheckIfFn(lex)) stack.push(lex);  // lex is function
    else if (lex.operation_ == ')') {  // lex is '('
        while(stack.top().operation_ != '(') { 
                que.push(stack.top());
                stack.pop();
        }
        stack.pop();
    } else { // lex is operator
        while(stack.size() > 0 && (lex.priority_ < stack.top().priority_ || (lex.priority_ == stack.top().priority_ && lex.operation_ != '^'))) {
            que.push(stack.top());
            stack.pop();
        }
        stack.push(lex);
    } 
}


void BinCalculator(std::stack<double>& stack, void (*fn)(std::stack<double>& st, double& a, double& b) ){
    double a = stack.top();
    stack.pop();
    double b = stack.top();
    stack.pop();
    fn(stack,a,b);
}



void CalculateQueue(std::queue<Lexem>& que, std::stack<double>& st) {
    if (que.front().operation_ == '+') BinCalculator(st,Sum);
    else if (que.front().operation_ == '-') BinCalculator(st,Sub);
    else if (que.front().operation_ == '*') BinCalculator(st,Mult);
    else if (que.front().operation_ == '/') BinCalculator(st,Div);
    else if (que.front().operation_ == 'm') BinCalculator(st,Mod);
    else if (que.front().operation_ == '^') BinCalculator(st,Pow);

    else if (que.front().operation_ == '#') UnaryCalculator(st,Unary_Sum);
    else if (que.front().operation_ == '~') UnaryCalculator(st,Unary_Sub);
    else if (que.front().operation_ == 'c') UnaryCalculator(st,Cos);
    else if (que.front().operation_ == 's') UnaryCalculator(st,Sin);
    else if (que.front().operation_ == 't') UnaryCalculator(st,Tan);
    else if (que.front().operation_ == 'a') UnaryCalculator(st,Atan);
    else if (que.front().operation_ == 'i') UnaryCalculator(st,Asin);
    else if (que.front().operation_ == 'o') UnaryCalculator(st,Acos);
    else if (que.front().operation_ == 'q') UnaryCalculator(st,Sqrt);
    else if (que.front().operation_ == 'l') UnaryCalculator(st,Ln);
    else if (que.front().operation_ == 'g') UnaryCalculator(st,Log);
}

double QueueToNumber(std::queue<Lexem>& que) {
    std::stack<double> st;
    while (!que.empty()) {
        if (que.front().type_ == true) { // digit
            st.push(que.front().number_);
        } else {
            CalculateQueue(que,st);
        }
        que.pop();
    }
    return st.top();
}

void UnaryChecker(std::stack<Lexem>& stack, const std::string::iterator& it, bool& is_unary) {
    if (is_unary) {
        if (*it == '+') *it = '#';
        else *it = '~';
    } 
    else {
        if (!stack.empty()) {
            if (stack.top().operation_ == '(') {
                if (*it == '+') *it = '#';
                else *it = '~';           
            }
        }
    }
}

void SkipSpace(std::string& str, std::string::iterator& str_it) {
    while(*str_it == ' ') str = str.erase(0,1);
    str_it = str.begin();
}

void MultInserter(std::string& str) {
    uint16_t len = str.length();
    for(uint16_t i = 0; i < len - 1; i++) {
        if (std::isdigit(str[i]) && (str[i+1] == 'a' || str[i+1] == 'c' || str[i+1] == 's' || str[i+1] == 't' || str[i+1] == 'l')) {
            std::string tmp_after = str.substr(i+1,len);
            str = str.substr(0,i+1);
            str+='*';
            str+=tmp_after;
        }
    }
}

double Calculator(std::string& str) {
    Lexem lex;
    std::string::iterator str_it = str.begin();
    std::queue<Lexem> que;
    std::stack<Lexem> st;
    bool unary_sign = true;
    MultInserter(str);
    while(str_it != str.end()) {
        SkipSpace(str,str_it);
        size_t i = 0;
        if (isdigit(*str_it)) {
            lex.number_ = std::stold(str,&i);
            lex.type_ = true;
            lex.operation_ = 0;
            lex.priority_ = 0;
            que.push(lex);
        } else {
            if (*str_it == '+' || *str_it == '-') UnaryChecker(st,str_it,unary_sign);
            FnToLex(str_it,lex,i);
            LexProcessor(st,lex,que);
        }
        str = str.erase(0,i);
        str_it = str.begin();
        if (unary_sign) unary_sign = false;
    }
    while (!st.empty()) {
        lex = st.top();
        que.push(lex);
        st.pop();
    }

    return QueueToNumber(que);;
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

#endif // qwe