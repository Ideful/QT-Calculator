#include <iostream>
#include <stack>
#include <queue>
std::pair<char, int> LongFnToPair(std::string::iterator& iter, int& len) {
    switch (*iter) {
        case 'm':       // mod
            if ( *(++iter) == 'o' && *(++(++iter)) == 'd') {
                len = 3;
                return std::pair<char,int>{'m',2};
            }
        case 'c':       // cos
            if ( *(++iter) == 'o' && *(++(++iter)) == 'd') {
                len = 3;
                return std::pair<char,int>{'m',2};
            }
        case 's':       // sin s
            if ( *(++iter) == 'i' ) {
                len = 3;
                return std::pair<char,int>{'s',4};
            } else {    // sqrt q   
                len = 4;
                return std::pair<char,int>{'q',4};
            }       
        case 't':       // tan t
            len = 3;
            return std::pair<char,int>{'q',4};
        case 'a':
            if (*(++iter) == 'c') {
                len = 4; 
                return std::pair<char,int>{'a',4};   // acos a 
            }    
            else if (*(++iter) == 's') {
                len = 4;
                return std::pair<char,int>{'i',4};   // asin i  
            }    
            else if (*(++iter) == 't') {
                len = 4;
                return std::pair<char,int>{'n',4};   // atan n         
            }    
        case 'l':
            if ( *(++iter) == 'n') {                 // ln l
                len = 2;
                return std::pair<char,int>{'l',4};
            } else {                                 // log g
                len = 3;    
                return std::pair<char,int>{'g',4};
            }      
    }
    return {0,0};
}


void FnToPair(std::string::iterator& iter,std::pair<char, int>& duo, int& i) {
    switch (*iter) {
        case '+':
            duo.first = '+';
            duo.second = 1;
            i = 1;
        case '-':
            duo.first = '-';
            duo.second = 1;  
            i = 1;      
        case '*':
            duo.first = '*';
            duo.second = 2;
            i = 1;
        case '/':
            duo.first = '/';
            duo.second = 2;
            i = 1;
        case '^':
            duo.first = '^';
            duo.second = 3;
            i = 1;
        case '(':
            duo.first = '(';
            duo.second = 5;
            i = 1;
        case ')':
            duo.first = ')';
            duo.second = 5;
            i = 1;
        default:
            duo = LongFnToPair(iter,i);
    }
}

void AddFnToStack(std::stack<std::pair<char,int>>& stack, std::pair<char,int>& duo, std::queue<std::pair<char,int>> queue) {
    if ( !(stack.empty()) ) {
        if (duo.second < stack.top().second ) {
            queue.push(duo);
        } else {
            stack.push(duo);
        }     
    }
}


int main() {
    std::cout<<"hi"<<std::endl;
    std::string str = "2 * 3 + 4";
    // std::pair<char,int> duo = FnToPair();

}