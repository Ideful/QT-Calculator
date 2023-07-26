#include <iostream>
#include <stack>
#include <queue>
// #define std::pair<char, int> lex_w_priority

std::pair<char, double> LongFnToPair(std::string::iterator& iter, size_t& len) {
    switch (*iter) {
        case 'm':       // mod
            if ( *(++iter) == 'o' && *(++(++iter)) == 'd') {
                len = 3.;
                return std::pair<char,double>{'m',2};
            }
        case 'c':       // cos
            if ( *(++iter) == 'o' && *(++(++iter)) == 'd') {
                len = 3.;
                return std::pair<char,double>{'m',2};
            }
        case 's':       // sin s
            if ( *(++iter) == 'i' ) {
                len = 3.;
                return std::pair<char,double>{'s',4};
            } else {    // sqrt q   
                len = 4.;
                return std::pair<char,double>{'q',4};
            }      
        case 't':       // tan t
            len = 3.;
            return std::pair<char,double>{'q',4};
        case 'a':
            if (*(++iter) == 'c') {
                len = 4.; 
                return std::pair<char,double>{'a',4};   // acos a 
            }    
            else if (*(++iter) == 's') {
                len = 4.;
                return std::pair<char,double>{'i',4};   // asin i  
            }    
            else if (*(++iter) == 't') {
                len = 4.;
                return std::pair<char,double>{'n',4};   // atan n         
            }    
        case 'l':
            if ( *(++iter) == 'n') {                 // ln l
                len = 2.;
                return std::pair<char,double>{'l',4};
            } else {                                 // log g
                len = 3.;    
                return std::pair<char,double>{'g',4};
            }      
    }
    return {0,0};
}


void FnToPair(std::string::iterator& iter,std::pair<char, double>& duo, size_t& i) {
    switch (*iter) {
        case '+':
            duo.first = '+';
            duo.second = 1;
            i = 1;
            break;
    std::cout<<duo.first<<'\n';
        case '-':
            duo.first = '-';
            duo.second = 1;  
            i = 1;   

            break;   
        case '*':
            duo.first = '*';
            duo.second = 2;
            i = 1;
            break;   
        case '/':
            duo.first = '/';
            duo.second = 2;
            i = 1;
            break;
        case '^':
            duo.first = '^';
            duo.second = 3;
            i = 1;
            break;
        case '(':
            duo.first = '(';
            duo.second = 5;
            i = 1;
            break;
        case ')':
            duo.first = ')';
            duo.second = 5;
            i = 1;
            break;
        default:
            duo = LongFnToPair(iter,i);
    }
}

void PairToStack(std::stack<std::pair<char,double>>& stack, std::pair<char,double>& duo,
                            std::queue<std::pair<char,double>>& que) {
    if ( !(stack.empty()) ) {
        if (duo.second < stack.top().second) {
            que.push(duo);
        } else {
            stack.push(duo);
        }
    } else que.push(duo);

}



int main() {
    // std::cout<<"hi"<<std::endl;
    std::string str = "2*3+4";
    std::pair<char,double> duo(0,0);
    std::string::iterator st_it = str.begin();
    std::queue<std::pair<char,double>> que;
    std::stack<std::pair<char,double>> st;
    while(st_it != str.end()) {
        while (*st_it == ' ') {
            str.erase(0,1); // zamenit na fn s counterom probelov
            st_it = str.begin();
        }
        // std::cout<<str<<"  "<<a<<"\n";
        size_t i = 0;
        int f(0);
        if (isdigit(*st_it)) {
            duo.first = 0;
            duo.second = std::stod(str,&i);
            que.push(duo);
            f = 1;
        } else {
            FnToPair(st_it,duo,i);
            PairToStack(st,duo,que);
        }
        str = str.erase(0,i);
        st_it = str.begin();
    }
    while (!que.empty()) {
        std::cout<<que.front().first<<" "<<que.front().second<<'\n';
        que.pop();
    }

}