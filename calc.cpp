#include "header.h"
#include "errorchecker.h"
// #define digit true 
// #define operation false

Lexem LongFnToLexem(std::string::iterator& iter, size_t& len) {
    switch (*iter) {
        case 'm':       // mod
            if ( *(++iter) == 'o') {
                len = 3;
                return {false, 'm',2,0};
            }
        case 'c':       // cos
            if ( *(++iter) == 'o') {
                len = 3;
                return {false, 'c',2,0};
            }
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
        case 'l':
            ++iter;
            if ( *iter == 'n') {                 // ln l
                len = 2;
                return {false, 'l',4,0};
            } else {                                 // log g
                len = 3;    
                return {false, 'g',4,0};
            }      
    }
    return {0};
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


// ((s2->priority < prev_priority ||         (s2->priority == prev_priority && s2->data[0] != '^'))

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
    PrintQS(que,st);
}

void UnaryChecker(std::stack<Lexem>& stack, std::string::iterator& it, bool& is_unary) {
    Printqwe(stack);
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



int main() {
    // std::string str = "1e-2";
    std::string str = "sin(cos(10^2))*43.1+sqrt(625)*(sin(4)+43.143*log(100)-asin(0.4243))/ln(sin(14.03))*sqrt(0.1)/0.009^(-3)";
    // if (!Errorchecker(str)) 
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
    // std::cout<<"qqqqqqqq\n";
    // PrintQ(que);
    std::cout<<QueueToNumber(que);
    std::cout<<"\n\n\n"<<sin(cos(pow(10, 2)))*43.1+sqrt(625)*(sin(4)+43.143*log10(100)-asin(0.4243))/log(sin(14.03))*sqrt(0.1)/pow(0.009, -3);
}