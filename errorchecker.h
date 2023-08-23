#include <string>

bool StringValidator(std::string& str) {
    const std::string comparer = ".,0123456789+-*/^()sincotalgmdqrxe";
    for(const char& sym : str) {
        if (comparer.find(sym) == std::string::npos) return false;
    }
    return true;
}

bool TwoAndMorePointsChecker(std::string& str, uint16_t& len) {
    for(uint16_t i = 0; i < len; i++) {
        if (str[i] == '.' || str[i] == ',') {
            if (i == len - 1 || i == 0) return false;
            if (!isdigit(str[i-1])) return false;
            if (!isdigit(str[++i])) return false;
            while(isdigit(str[i])) {
                if (i != len - 1) i++;   
            }
            std::string comparer = "+-*/^)m0123456789";
            if (comparer.find(str[i]) == std::string::npos) return false;
        }
    }
    return true;
}

bool OperatorChecker(std::string& str, uint16_t& len) {
    std::string comparer = "(0123456789mctlsax";
    for(uint16_t i = 0; i < len; i++) {
        if (str[i] == '+' || str[i] == '+' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
            if (comparer.find(str[i+1]) == std::string::npos) return false;
        }
    }
    return true;
}


bool BeginChecker(std::string& str) {
    std::string begin_comparer = " (0123456789cstalx+-";
    if (begin_comparer.find(str[0]) == std::string::npos) return false;
    return true;
}

bool EndChecker(std::string& str, uint16_t& len) {
    std::string end_comparer = " 0123456789)x";
    if (end_comparer.find(str[len-1]) == std::string::npos) return false;
    return true;
}

bool DigitChecker(std::string& str, uint16_t& len) {
    std::string comparer = "0123456789ctmsal+-*/^.,)";
    for(uint16_t i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            if (i == len - 1) return true;
            if (comparer.find(str[i+1]) == std::string::npos) return false;
        }
    }
    return true;
}

bool BracketParser(std::string& str, uint16_t& len) {
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

bool FnChecker(std::string& str, uint16_t& len) {
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
                } else if (str[++i] == 'c') {
                    if (!(str[++i] == 'o' && str[++i] == 's')) return false;
                } if (str[++i] == 't') {
                    if (!(str[++i] == 'a' && str[++i] == 'n')) return false;
                }
                break;
        }
    }
    return true;
}

bool Errorchecker (std::string& str) {
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

bool XIsDouble(std::string& str) {
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

void InsertXVal(std::string& str,std::string& xval) {
    const uint16_t x = str.find('x');
    const uint16_t len = str.length();
    const std::string after_x = str.substr(x+1,len - 1);

    str = str.substr(0,x);
    str += xval;
    str += after_x;
}

bool StrContainsX(std::string& str) {
    return (str.find('x') == std::string::npos) ? false : true;
}