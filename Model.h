#ifndef SRC_HEADER_qwe
#define SRC_HEADER_qwe
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
// #include "errorchecker.h"
#include <string>


class Model{
    private:
        struct Lexem {
            // Lexem():type_(0),operation_(0),priority_(0),number(0) {};
            Lexem() = default;
            bool type_;  // 1 is digit, 0 is operator
            char operation_;
            int16_t priority_;
            long double number_;
        };


        static void Sum(std::stack<double>& st, double& a, double& b);

        static void Mult(std::stack<double>& st, double& a, double& b);

        static void Div(std::stack<double>& st, double& a, double& b);

        static void Sub(std::stack<double>& st, double& a, double& b);

        static void Mod(std::stack<double>& st, double& a, double& b);

        static void Pow(std::stack<double>& st, double& a, double& b);

        // #############################################################################


        void UnaryCalculator(std::stack<double>& stack, void (*fn)(std::stack<double>& st, double& a));

        static void Sin(std::stack<double>& st, double& a);

        static void Cos(std::stack<double>& st, double& a);

        static void Tan(std::stack<double>& st, double& a);

        static void Asin(std::stack<double>& st, double& a);

        static void Acos(std::stack<double>& st, double& a);

        static void Atan(std::stack<double>& st, double& a);

        static void Sqrt(std::stack<double>& st, double& a);

        static void Ln(std::stack<double>& st, double& a);

        static void Log(std::stack<double>& st, double& a);

        static void Unary_Sum(std::stack<double>& st, double& a);

        static void Unary_Sub(std::stack<double>& st, double& a);

        Lexem LongFnToLexem(std::string::iterator& iter, size_t& len);

        void FnToLex(std::string::iterator& iter,Lexem& lex, size_t& i);

        bool CheckIfFn(Lexem& lex);

        void LexProcessor(std::stack<Lexem>& stack, Lexem& lex, std::queue<Lexem>& que);

        void BinCalculator(std::stack<double>& stack, void (*fn)(std::stack<double>& st, double& a, double& b));

        void CalculateQueue(std::queue<Lexem>& que, std::stack<double>& st);

        double QueueToNumber(std::queue<Lexem>& que);

        void UnaryChecker(std::stack<Lexem>& stack, const std::string::iterator& it, bool& is_unary);

        void SkipSpace(std::string& str, std::string::iterator& str_it);

        void MultInserter(std::string& str);

        double Calculator(std::string str);

        bool StringValidator(const std::string& str);

        bool TwoAndMorePointsChecker(const std::string& str,const  uint16_t& len);

        bool OperatorChecker(const std::string& str, const uint16_t& len);

//  ############################################################

        bool BeginChecker(const std::string& str);

        bool EndChecker(const std::string& str, const uint16_t& len);

        bool DigitChecker(const std::string& str, const uint16_t& len);

        bool BracketParser(const std::string& str, const uint16_t& len);

        bool FnChecker(const std::string& str, const uint16_t& len);

        bool Errorchecker (const std::string& str);


//  ############################################################

        std::string InsertXVal(std::string& str,const double& xval);

        bool StrContainsX(const std::string& str);

        bool IsDouble(const std::string& str);
        
        std::string calc_string_;
        double x_val_;

    public:
        void SetString(std::string str) {
            calc_string_ = str;
        }   // 

        bool CheckForErrors() {
            return Errorchecker(calc_string_);
        }   //

        bool StringContainsX() {
            return StrContainsX(calc_string_);
        }   //


        bool XValueValidator(std::string& str) {
            return IsDouble(str);
        } 

        void SetXValue(double x) {
            x_val_ = x;
        }

        double Calculate() {
            return Calculator(calc_string_);
        }

        double CalculateWithX() {
            return Calculator(InsertXVal(calc_string_,x_val_));
        }

        std::pair<std::string,double> vsya_huyna(std::string& str, std::string& xstr ) {
            if (Errorchecker(str) == false) return {"wrong input string",0};
            if (!StrContainsX(str)) return {"",Calculator(str)};
            else {
                if (xstr == "" || IsDouble(xstr) == false) return {"wrong x input",0};
                else {
                    InsertXVal(str,std::stod(xstr));
                    return {"",Calculator(str)};
                }
            }
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

};

#endif // qwe