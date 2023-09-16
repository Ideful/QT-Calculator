#include "Model.h"

void Model::Sum(std::stack<double>& st, const double& a, const double& b) {
    st.push(b+a);
}

void Model::Mult(std::stack<double>& st, const double& a, const double& b) {
    st.push(b*a);
}

void Model::Div(std::stack<double>& st, const double& a, const double& b) {
    st.push(b/a);
}

void Model::Sub(std::stack<double>& st, const double& a, const double& b) {
    st.push(b-a);
}

void Model::Mod(std::stack<double>& st, const double& a, const double& b) {
    st.push(std::fmod(b,a));
}

void Model::Pow(std::stack<double>& st, const double& a, const double& b) {
    st.push(std::pow(b,a));
}

// #############################################################################


void Model::UnaryCalculator(std::stack<double>& stack, void (*fn)(std::stack<double>& st, const double& a)) {
    double a = stack.top();
    stack.pop();
    fn(stack,a);
}

void Model::Sin(std::stack<double>& st, const double& a) {
    st.push(std::sin(a));
}

void Model::Cos(std::stack<double>& st, const double& a) {
    st.push(std::cos(a));
}

void Model::Tan(std::stack<double>& st, const double& a) {
    st.push(std::tan(a));
}

void Model::Asin(std::stack<double>& st, const double& a) {
    st.push(std::asin(a));
}

void Model::Acos(std::stack<double>& st, const double& a) {
    st.push(std::acos(a));
}


void Model::Atan(std::stack<double>& st, const double& a) {
    st.push(std::atan(a));
}

void Model::Sqrt(std::stack<double>& st, const double& a) {
    st.push(std::sqrt(a));
}

void Model::Ln(std::stack<double>& st, const double& a) {
    st.push(std::log(a));
}

void Model::Log(std::stack<double>& st, const double& a) {
    st.push(std::log10(a));   
}

void Model::Unary_Sum(std::stack<double>& st, const double& a) {
    st.push(a);
}

void Model::Unary_Sub(std::stack<double>& st, const double& a) {
    st.push(-a);
}

void Model::LongFnToLexem(std::string::iterator& iter,Model::Lexem& lex, size_t& len) noexcept {
    switch (*iter) {
        case 'm':       // mod
            ++iter;
            if ( *iter == 'o') {
                len = 3;
                lex = {false, 'm',2,0.};
            }
            break;
        case 'c':       // cos
            if ( *(++iter) == 'o') {
                len = 3;
                lex = {false, 'c',2,0};
            }
            break;
        case 's':       // sin s
        ++iter;
            if ( *iter == 'i' ) {
                len = 3;
                lex = {false, 's',4,0};
            } else {    // sqrt q   
                len = 4;
                lex = {false, 'q',4,0};
            }    
            break;  
        case 't':       // tan t
            len = 3;
            lex = {false, 't',4,0};
            break;
        case 'a':
            ++iter;
            if (*iter == 'c') {     // acos
                len = 4; 
                lex = {false, 'o',4,0};
            }    
            else if (*iter == 's') {    // asin
                len = 4;
                lex = {false, 'i',4,0};
            }    
            else if (*iter == 't') {    // atan
                len = 4;
                lex = {false, 'a',4,0};
            }    
            break;
        case 'l':
            ++iter;
            if ( *iter == 'n') {                 // ln l
                len = 2;
                lex = {false, 'l',4,0};
            } else {                                 // log g
                len = 3;    
                lex = {false, 'g',4,0};
            }    
            break;  
    }
}


void Model::FnToLex(std::string::iterator& iter,Model::Lexem& lex, size_t& i) noexcept {   // add unary
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
            LongFnToLexem(iter, lex,i);
    }
    lex.type_ = false;
    lex.number_ = 0;
}

bool Model::CheckIfFn(const Model::Lexem& lex) {
    std::string fn = "(cstaioqlg";
    return (fn.find(lex.operation_) == std::string::npos) ? false : true;
}

void Model::LexProcessor(std::stack<Model::Lexem>& stack, Model::Lexem& lex, std::queue<Model::Lexem>& que) {
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


void Model::BinCalculator(std::stack<double>& stack, void (*fn)(std::stack<double>& st, const double& a, const double& b) ){
    double a = stack.top();
    stack.pop();
    double b = stack.top();
    stack.pop();
    fn(stack,a,b);
}



void Model::CalculateQueue(std::queue<Model::Lexem>& que, std::stack<double>& st) {
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

double Model::QueueToNumber(std::queue<Model::Lexem>& que) {
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

void Model::UnaryChecker(const std::stack<Model::Lexem>& st, const std::string::iterator& it, const bool& is_unary) {
    if (is_unary) {
        if (*it == '+') *it = '#';
        else *it = '~';
    } 
    else {
        if (!st.empty()) {
            if (st.top().operation_ == '(') {
                if (*it == '+') *it = '#';
                else *it = '~';           
            }
        }
    }
}

void Model::SkipSpace(std::string& str, std::string::iterator& str_it) noexcept {
    while(*str_it == ' ') str = str.erase(0,1);
    str_it = str.begin();
}

void Model::MultInserter(std::string& str) {
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

void Model::ClearStackAddtoQueue(std::stack<Model::Lexem>& st, std::queue<Model::Lexem>& que){
    while(!st.empty()) {
        que.push(st.top());
        st.pop();
    }
}

double Model::Calculator(std::string& str) {
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
    ClearStackAddtoQueue(st,que);
    return QueueToNumber(que);
}

bool Model::StringValidator(const std::string& str) noexcept {
    const std::string comparer = ".0123456789+-*/^()sincotalgmdqrxe ";
    for(const char& sym : str) {
        if (comparer.find(sym) == std::string::npos) return false;
    }
    return true;
}

bool Model::TwoAndMorePointsChecker(const std::string& str, const uint16_t& len) noexcept {
    for(uint16_t i = 0; i < len; i++) {
        if (str[i] == '.' || str[i] == ',') {
            if (i == len - 1 || i == 0) return false;
            if (!isdigit(str[i+1]) && str[i+1] != 'x') return false;
            if (!isdigit(str[i-1])) return false;
            i++;
            while(i != len - 1 && isdigit(str[i])) i++;   
            std::string comparer = "0123456789+-*/m^) ";
            if (comparer.find(str[i]) == std::string::npos) return false;
        }
    }
    return true;
}

bool Model::OperatorChecker(const std::string& str, const uint16_t& len) noexcept {
    std::string comparer = " (0123456789mctlsax";
    for(uint16_t i = 0; i < len; i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
            if (comparer.find(str[i+1]) == std::string::npos) return false;
        }
    }
    return true;
}


bool Model::BeginChecker(const std::string& str) noexcept {
    std::string begin_comparer = " (0123456789cstalx+-";
    if (begin_comparer.find(str[0]) == std::string::npos) return false;
    return true;
}

bool Model::EndChecker(const std::string& str, const uint16_t& len) noexcept {
    std::string end_comparer = " 0123456789)x";
    if (end_comparer.find(str[len-1]) == std::string::npos) return false;
    return true;
}

// bool Model::DigitChecker(const std::string& str, const uint16_t& len) {
//     std::string comparer = "0123456789ctmsal+-*/^.,)";
//     for(uint16_t i = 0; i < len; i++) {
//         if (isdigit(str[i])) {
//             if (i == len - 1) return true;
//             if (comparer.find(str[i+1]) == std::string::npos) return false;
//         }
//     }
//     return true;
// }

bool Model::BracketParser(const std::string& str, const uint16_t& len) noexcept {
    uint8_t open = 0;
    uint8_t close = 0;
    for (uint16_t i = 0; i < len; i++) {
        if (str[i] == '(') {
            open++;
            uint16_t cnt = i+1;
            bool f = false;
            while(str[cnt] != ')') {
                if (isdigit(str[cnt]) || str[cnt] == 'x') f = true; 
                cnt++;
            }
            if (f == false) return false;
        }
        if (str[i] == ')') close++;
        if (close > open) return false;
    }

    return open == close? true : false;
}

bool Model::FnChecker(const std::string& str, const uint16_t& len) noexcept {
    for(uint16_t i = 0; i < len; i++) {
        switch (str[i]){
            case 'm':
                if (!(str[++i] == 'o' && str[++i] == 'd')) return false;
                break;
            case 'c':
                if (!(str[++i] == 'o' && str[++i] == 's')) return false;
                break;
            case 's':
                if (str[++i] == 'q') {
                    if (!(str[++i] == 'r' && str[++i] == 't')) return false;
                } else if (str[i] == 'i') {
                    if (str[++i] != 'n') return false;
                } else return false;
                break;
            case 't':
                if (!(str[++i] == 'a' && str[++i] == 'n')) return false;
                break;
            case 'l':
                if (str[++i] == 'o') {
                    if (!(str[++i] == 'g')) return false;
                } else if (str[i] != 'n') return false;
                break;
            case 'a':
                if (str[++i] == 's') {
                    if (!(str[++i] == 'i' && str[++i] == 'n')) return false;
                } else if (str[i] == 'c') {
                    if (!(str[++i] == 'o' && str[++i] == 's')) return false;
                } else if (str[i] == 't') {
                    if (!(str[++i] == 'a' && str[++i] == 'n')) return false;
                }
                break;
        }
    }
    return true;
}

bool Model::Errorchecker (const std::string& str) noexcept {
    uint16_t len = str.length();
    if (len > 255) return false;
    if (!StringValidator(str)) return false;
    if (!BeginChecker(str)) return false;
    if (!EndChecker(str,len)) return false;
    if (!TwoAndMorePointsChecker(str,len)) return false;
    if (!OperatorChecker(str,len)) return false;
    if (!FnChecker(str,len)) return false;
    if (!BracketParser(str,len)) return false;
    return true;
}

bool Model::IsDouble(const std::string& str) noexcept {
    uint16_t len = str.length();
    uint8_t dotcounter = 0;
    if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-') return false;
    for(uint16_t i = 1; i < len; i++) {
        if (str[i] == '.') dotcounter++;
        if (!isdigit(str[i]) && str[i] != '.') return false; 
    }
    if (dotcounter > 1) return false;
    return true;
}

std::string Model::InsertXVal(std::string str,const double& xval) {
    uint8_t xc = 0;
    for(const auto& tmp: str) {
        if (tmp == 'x') xc++;
    }
    while(xc) {
        const uint64_t x = str.find('x');
        if (x != std::string::npos) {
            const std::string after_x = str.substr(x+1,str.length() - 1);
            const std::string xvalstr = std::to_string(xval);
            bool mult = (std::isdigit(str[x-1]))? 1 : 0;
            str = str.substr(0,x);
            if (mult) str += "*(";
            else str+= '(';
            str += xvalstr;
            str += ')';
            str += after_x;
        }
        xc--;
    }
    return str;
}

bool Model::StrContainsX(const std::string& str) {
    return (str.find('x') == std::string::npos) ? false : true;
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
