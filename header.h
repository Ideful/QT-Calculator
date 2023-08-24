#ifndef SRC_HEADER_H
#define SRC_HEADER_H
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <regex>
#include "errorchecker.h"
// #define digit true 
// #define operation false

struct Lexem {
    // Lexem():type(0),operation(0),priority(0),number(0) {};
    Lexem() = default;
    bool type;  // 1 is digit, 0 is operator
    char operation;
    int16_t priority;
    long double number;
};


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
    st.push(std::log(a));
}

void Log(std::stack<double>& st, double a) {
    st.push(std::log10(a));   
}

void Unary_Sum(std::stack<double>& st, double a) {
    st.push(a);
}

void Unary_Sub(std::stack<double>& st, double a) {
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
        case 't':       // tan t
            len = 3;
            return {false, 't',4,0};
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
            lex.operation = '+';
            lex.priority = 1;
            i = 1;
            break;
        case '-':
            lex.operation= '-';
            lex.priority  = 1;  
            i = 1;   
            break;   
        case '#':
            lex.operation = '#';
            lex.priority = 5;
            i = 1;
            break;
        case '~':
            lex.operation= '~';
            lex.priority  = 5;  
            i = 1;   
            break;  
        case '*':
            lex.operation= '*';
            lex.priority  = 2;
            i = 1;
            break;   
        case '/':
            lex.operation= '/';
            lex.priority  = 2;
            i = 1;
            break;
        case '^':
            lex.operation= '^';
            lex.priority  = 3;
            i = 1;
            break;
        case '(':
            lex.operation= '(';
            lex.priority  = 0;
            i = 1;
            break;
        case ')':
            lex.operation= ')';
            lex.priority  = 0;
            i = 1;
            break;
        default:
            lex = LongFnToLexem(iter,i);
    }
    lex.type = false;
    lex.number = 0;
}

bool CheckIfFn(Lexem& lex) {
    std::string fn = "(cstaioqlg";
    return (fn.find(lex.operation) == std::string::npos) ? false : true;
}

void LexProcessor(std::stack<Lexem>& stack, Lexem& lex, std::queue<Lexem>& que) {
    // Prints(stack,lex);
    if (CheckIfFn(lex)) stack.push(lex);  // lex is function
    else if (lex.operation == ')') {  // lex is '('
        while(stack.top().operation != '(') { 
                que.push(stack.top());
                stack.pop();
        }
        stack.pop();
    } else { // lex is operator
        while(stack.size() > 0 && (lex.priority < stack.top().priority || (lex.priority == stack.top().priority && lex.operation != '^'))) {
            que.push(stack.top());
            stack.pop();
        }
        stack.push(lex);
    } 
}


void BinCalculator(std::stack<double>& stack, void (*fn)(std::stack<double>& st, double a, double b) ){
    double a = stack.top();
    stack.pop();
    double b = stack.top();
    stack.pop();
    fn(stack,a,b);
}



void CalculateQueue(std::queue<Lexem>& que, std::stack<double>& st) {
    if (que.front().operation == '+') BinCalculator(st,Sum);
    else if (que.front().operation == '-') BinCalculator(st,Sub);
    else if (que.front().operation == '*') BinCalculator(st,Mult);
    else if (que.front().operation == '/') BinCalculator(st,Div);
    else if (que.front().operation == 'm') BinCalculator(st,Mod);
    else if (que.front().operation == '^') BinCalculator(st,Pow);

    else if (que.front().operation == '#') UnaryCalculator(st,Unary_Sum);
    else if (que.front().operation == '~') UnaryCalculator(st,Unary_Sub);
    else if (que.front().operation == 'c') UnaryCalculator(st,Cos);
    else if (que.front().operation == 's') UnaryCalculator(st,Sin);
    else if (que.front().operation == 't') UnaryCalculator(st,Tan);
    else if (que.front().operation == 'a') UnaryCalculator(st,Atan);
    else if (que.front().operation == 'i') UnaryCalculator(st,Asin);
    else if (que.front().operation == 'o') UnaryCalculator(st,Acos);
    else if (que.front().operation == 'q') UnaryCalculator(st,Sqrt);
    else if (que.front().operation == 'l') UnaryCalculator(st,Ln);
    else if (que.front().operation == 'g') UnaryCalculator(st,Log);
}

double QueueToNumber(std::queue<Lexem>& que) {
    std::stack<double> st;
    while (!que.empty()) {
        if (que.front().type == true) { // digit
            st.push(que.front().number);
        } else {
            CalculateQueue(que,st);
        }
        que.pop();
    }
    return st.top();
}

void UnaryChecker(std::stack<Lexem>& stack, std::string::iterator& it, bool& is_unary) {
    if (is_unary) {
        if (*it == '+') *it = '#';
        else *it = '~';
    } 
    else {
        if (!stack.empty()) {
            if (stack.top().operation == '(') {
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


double Calculator(std::string str) {
    Lexem lex;
    std::string::iterator str_it = str.begin();
    std::queue<Lexem> que;
    std::stack<Lexem> st;
    bool unary_sign(true);
    while(str_it != str.end()) {
        SkipSpace(str,str_it);
        size_t i = 0;
        if (isdigit(*str_it)) {
            lex.number = std::stold(str,&i);
            lex.type = true;
            lex.operation = 0;
            lex.priority = 0;
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
    // std::cout<<QueueToNumber(que);
    // std::cout<<sin(cos(pow(10, 2)))*43.1+sqrt(625)*(sin(4)+43.143*log10(100)-asin(0.4243))/log(sin(14.03))*sqrt(0.1)/pow(0.009, -3)*(std::fmod(12.34,62))<<"\n\n\n";
    return QueueToNumber(que);;
}


// void PrintQ(std::queue<Lexem> que) {
//     while (!que.empty()) {
//         if (que.front().type) {
//             std::cout<<que.front().number<<" ";
//         } else {
//             std::cout<<que.front().operation<<" ";
//         }
//         que.pop();
//     }
//     std::cout<<'\n';
// }

// void Prints(std::stack<Lexem> st, Lexem lex) {
//     std::cout<<"curr "<<lex.operation<<" "<<std::endl;
//     while (!st.empty()) {
//         std::cout<<st.top().operation<<" " <<std::endl;
//         st.pop();
//     }
// }

// void Printqwe(std::stack<Lexem> st) {
//     while (!st.empty()) {
//         std::cout<<st.top().operation<<" " <<std::endl;
//         st.pop();
//     }
// }

// void PrintQS(std::queue<Lexem> que, std::stack<double> st) {
//     while (!que.empty()) {
//         if (que.front().type) {
//             std::cout<<que.front().number<<" ";
//         } else {
//             std::cout<<que.front().operation<<" ";
//         }
//         que.pop();
//     }
//     std::cout<<"        "<<st.top();
//     std::cout<<'\n';
// }

// void Printsa(std::stack<Lexem> st, Lexem lex) {
//     while (!st.empty()) {
//         std::cout<<"__"<<st.top().operation<<" " <<std::endl;
//         st.pop();
//     }
//     std::cout<<'\n';
// }





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