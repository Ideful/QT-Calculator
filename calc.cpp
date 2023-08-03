#include <iostream>
#include <stack>
#include <queue>

// #define digit true 
// #define operation false


struct Lexem {
    Lexem() = default;
    bool type;  // 1 is digit, 0 is operator
    char operation;
    int16_t priority;
    double number;
};

void CalculateQueue(std::queue<Lexem>& que, std::stack<double>& st);


Lexem LongFnToLex(std::string::iterator& iter, size_t& len) {
    switch (*iter) {
        case 'm':       // mod
            if ( *(++iter) == 'o' && *(++(++iter)) == 'd') {
                len = 3.;
                return {false, 'm',2,0};
            }
        case 'c':       // cos
            if ( *(++iter) == 'o' && *(++(++iter)) == 'd') {
                len = 3.;
                return {false, 'c',2,0};
            }
        case 's':       // sin s
            if ( *(++iter) == 'i' ) {
                len = 3.;
                return {false, 's',4,0};
            } else {    // sqrt q   
                len = 4.;
                return {false, 'q',4,0};
            }      
        case 't':       // tan t
            len = 3.;
            return {false, 'q',4,0};
        case 'a':
            if (*(++iter) == 'c') {     // acos
                len = 4.; 
                return {false, 'a',4,0};
            }    
            else if (*(++iter) == 's') {    // asin
                len = 4.;
                return {false, 'i',4,0};
            }    
            else if (*(++iter) == 't') {    // atan
                len = 4.;
                return {false, 'n',4,0};
            }    
        case 'l':
            if ( *(++iter) == 'n') {                 // ln l
                len = 2.;
                return {false, 'l',4,0};
            } else {                                 // log g
                len = 3.;    
                return {false, 'g',4,0};
            }      
    }
    return {0,0};
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
            lex.priority  = 5;
            i = 1;
            break;
        case ')':
            lex.operation= ')';
            lex.priority  = 5;
            i = 1;
            break;
        default:
            lex = LongFnToLex(iter,i);
    }
    lex.type = false;
    lex.number = 0;
}

void LexToStack(std::stack<Lexem>& stack, Lexem& lex, std::queue<Lexem>& que) {
    if (stack.empty()) stack.push(lex);
    else {
        if (stack.top().priority > lex.priority) {
            que.push(stack.top());
            stack.pop();
            stack.push(lex);
        } else {
            stack.push(lex);
        }
    }

}

void PrintQ(std::queue<Lexem>& que) {
    while (!que.empty()) {
        std::cout<<que.front().type<<" "<<que.front().operation<<" " << que.front().priority << " " << que.front().number<<std::endl;
        que.pop();
    }
}

double QueueToNumber(std::queue<Lexem> que) {
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
    if (que.front().operation == '+') {
        double a = st.top();
        st.pop();
        double b = st.top();
        st.pop();
        st.push(b+a);
    }
        else if (que.front().operation == '*') {
        double a = st.top();
        st.pop();
        double b = st.top();
        st.pop();
        st.push(b*a);
    }
}

int main() {
    // std::cout<<"hi"<<std::endl;
    std::string str = "2.7*3.2+4.6";
    Lexem lex;
    std::string::iterator st_it = str.begin();
    std::queue<Lexem> que;
    std::stack<Lexem> st;
    while(st_it != str.end()) {
        while (*st_it == ' ') {
            str.erase(0,1); // zamenit na fn s counterom probelov
            st_it = str.begin();
        }
        size_t i = 0;
        // int f(0);
        if (isdigit(*st_it)) {
            lex.number = std::stod(str,&i);
            lex.type = true;
            lex.operation = 0;
            lex.priority = 0;
            que.push(lex);
            // f = 1;
        } else {
            FnToLex(st_it,lex,i);
            LexToStack(st,lex,que);
        }
        str = str.erase(0,i);
        st_it = str.begin();
    }
    while (!st.empty()) {
        lex = st.top();
        que.push(lex);
        st.pop();
    }
    // PrintQ(que);
    std::cout<<QueueToNumber(que);

}