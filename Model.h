#ifndef SRC_HEADER_qwe
#define SRC_HEADER_qwe
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>

class Model{
    private:
        struct Lexem {
            Lexem():type_(0),operation_(0),priority_(0),number_(0) {};
            Lexem(bool type, char operation, int16_t priority, double number) : type_(type), operation_(operation), priority_(priority),number_(number) {};
            ~Lexem() {};
            bool type_;  // 1 is digit, 0 is operator
            char operation_;
            int16_t priority_;
            double number_;
        };

        /**
         * @brief adds sum of two values to stack
         * 
         * @param st stack
         * @param a value 1
         * @param b value 2
         */
        static void Sum(std::stack<double>& st, const double& a, const double& b);

        /**
         * @brief adds multiply of two values to stack
         * 
         * @param st stack
         * @param a value 1
         * @param b value 2
         */
        static void Mult(std::stack<double>& st, const double& a, const double& b);

        /**
         * @brief adds subtraction of two values to stack
         * 
         * @param st - stack
         * @param a  - value 1
         * @param b  - value 2
         */

        static void Div(std::stack<double>& st, const double& a, const double& b);

        /**
         * @brief adds subtraction of two values to stack
         * 
         * @param st stack
         * @param a value 1
         * @param b value 2
         */
        static void Sub(std::stack<double>& st, const double& a, const double& b);

        /**
         * @brief adds mod of two values to stack
         * 
         * @param st stack
         * @param a value 1
         * @param b value 2
         */
        static void Mod(std::stack<double>& st, const double& a, const double& b);

        /**
         * @brief adds exponentiation of two values to stack
         * 
         * @param st stack
         * @param a value 1
         * @param b value 2
         */
        static void Pow(std::stack<double>& st, const double& a, const double& b);

        /**
         * @brief adds sin of value to stack
         * 
         * @param st stack
         * @param a value
         */
        static void Sin(std::stack<double>& st, const double& a);

        /**
         * @brief adds cos of value to stack
         * 
         * @param st stack
         * @param a value
         */
        static void Cos(std::stack<double>& st, const double& a);

        /**
         * @brief adds tan of value to stack
         * 
         * @param st stack
         * @param a value
         */
        static void Tan(std::stack<double>& st, const double& a);

        /**
         * @brief adds asin of value to stack
         * 
         * @param st stack
         * @param a value
         */
        static void Asin(std::stack<double>& st, const double& a);

        /**
         * @brief adds acos of value to stack
         * 
         * @param st stack
         * @param a value
         */
        static void Acos(std::stack<double>& st, const double& a);

        /**
         * @brief adds atan of value to stack
         * 
         * @param st stack
         * @param a value
         */
        static void Atan(std::stack<double>& st, const double& a);

        /**
         * @brief adds square root of value to stack
         * 
         * @param st stack
         * @param a value
         */
        static void Sqrt(std::stack<double>& st, const double& a);

        /**
         * @brief adds log.10 of value to stack
         * 
         * @param st stack
         * @param a value
         */
        static void Ln(std::stack<double>& st, const double& a);

        /**
         * @brief adds log.e of value to stack
         * 
         * @param st stack
         * @param a value
         */
        static void Log(std::stack<double>& st, const double& a);

        /**
         * @brief adds value to stack
         * 
         * @param st stack
         * @param a value
         */
        static void Unary_Sum(std::stack<double>& st, const double& a);

        /**
         * @brief adds reciprocal of value to stack
         * 
         * @param st stack
         * @param a value
         */
        static void Unary_Sub(std::stack<double>& st, const double& a);

        // #############################################################################

        /**
         * @brief gets values from stack and calculate
         * 
         * @param stack stack
         * @param fn funciton pointer
         */
        void UnaryCalculator(std::stack<double>& stack, void (*fn)(std::stack<double>& st, const double& a));

        /**
         * @brief gets values from stack and calculate
         * 
         * @param stack stack
         * @param fn funciton pointer
         */
        void BinCalculator(std::stack<double>& stack, void (*fn)(std::stack<double>& st, const double& a, const double& b));

        /**
         * @brief fills lexem value
         * 
         * @param iter string iterator
         * @param lex lexem to be filled
         * @param len current position in string
         */
        void LongFnToLexem(std::string::iterator& iter,Model::Lexem& lex, size_t& len) noexcept;

        /**
         * @brief parses string and fills lexem
         * 
         * @param iter string iterator
         * @param lex lexem to be filled
         * @param i amount of string symbols which represents one lexem
         */
        void FnToLex(std::string::iterator& iter,Lexem& lex, size_t& i) noexcept;

        /**
         * @brief Checks if lexem is an operator or number(x)
         * 
         * @param lex lexem
         * @return true 
         * @return false 
         */
        bool CheckIfFn(const Lexem& lex);

        /**
         * @brief Deixtra algorithm
         * 
         * @param stack stack we have
         * @param lex lexem we processing
         * @param que queue we have
         */
        void LexProcessor(std::stack<Lexem>& stack, Lexem& lex, std::queue<Lexem>& que);

        /**
         * @brief adds values to stack according to the data from queue
         * 
         * @param que queue
         * @param st stack
         */
        void CalculateQueue(std::queue<Lexem>& que, std::stack<double>& st);

        /**
         * @brief return calculated value from queue
         * 
         * @param que queue
         * @return double  
         */
        double QueueToNumber(std::queue<Lexem>& que);

        /**
         * @brief checks if "+" or "-" is unary or binary operator
         * 
         * @param stack stack
         * @param it iterator
         * @param is_unary bool flague
         */
        void UnaryChecker(const std::stack<Lexem>& stack, const std::string::iterator& it, const bool& is_unary);

        /**
         * @brief just skip spaces in initial string
         * 
         * @param str string
         * @param str_it iterator
         */
        void SkipSpace(std::string& str, std::string::iterator& str_it) noexcept;

        /**
         * @brief inserts "*" in a string if required
         * 
         * @param str string
         */
        void MultInserter(std::string& str);

        void ClearStackAddtoQueue(std::stack<Lexem>& stack, std::queue<Lexem>& q);

        /**
         * @brief Calculation function
         * 
         * @param str string to be calculated
         * @return double 
         */
        double Calculator(std::string& str);



//  ############################################################

        /**
         * @brief checks if start string symbol is valid
         * 
         * @param str string
         * @return true 
         * @return false 
         */
        bool BeginChecker(const std::string& str) noexcept;

        /**
         * @brief checks if end symbol of string is valid
         * 
         * @param str string
         * @param len string length
         * @return true 
         * @return false 
         */
        bool EndChecker(const std::string& str, const uint16_t& len) noexcept;

        // /**
        //  * @brief checks validity of string
        //  * 
        //  * @param str string
        //  * @param len string length
        //  * @return true 
        //  * @return false 
        //  */
        // bool DigitChecker(const std::string& str, const uint16_t& len) noexcept;

        /**
         * @brief checks if everything is ok with brackets
         * 
         * @param str string
         * @param len  string length
         * @return true 
         * @return false 
         */
        bool BracketParser(const std::string& str, const uint16_t& len) noexcept;

        /**
         * @brief checks validity of string
         * 
         * @param str string
         * @param len string length
         * @return true 
         * @return false 
         */
        bool FnChecker(const std::string& str, const uint16_t& len) noexcept;
       
        /**
         * @brief checks validity of string
         * 
         * @param str string
         * @return true 
         * @return false 
         */
        bool StringValidator(const std::string& str) noexcept;

        /**
         * @brief checks if everything is ok with dots
         * 
         * @param str string
         * @param len string length
         * @return true 
         * @return false 
         */
        bool TwoAndMorePointsChecker(const std::string& str,const  uint16_t& len ) noexcept;

        /**
         * @brief checks if everything is ok with oeprators
         * 
         * @param str string
         * @param len string length
         * @return true 
         * @return false 
         */
        bool OperatorChecker(const std::string& str, const uint16_t& len) noexcept;


//  ############################################################

        /**
         * @brief inserts x value in string
         * 
         * @param str string
         * @param xval x value
         * @return std::string 
         */
        std::string InsertXVal(std::string str,const double& xval);

        /**
         * @brief checks if string contains x
         * 
         * @param str string
         * @return true 
         * @return false 
         */
        bool StrContainsX(const std::string& str);


        /**
         * @brief checks if string literal could be converted to double
         * 
         * @param str string to be checked
         * @return true 
         * @return false 
         */
        bool IsDouble(const std::string& str) noexcept;

    public:
        explicit Model() {};
        ~Model() {};

        /**
         * @brief checks if there is a input mistake in string
         * 
         * @param str string to be checked
         * @return true 
         * @return false 
         */
        bool Errorchecker (const std::string& str) noexcept;


        /**
         * @brief checks if min/max of x/y values are OK
         * 
         * @param edgesval vector of 4 doubles to be filled
         * @param edges vector of 4 strings to be checked
         * @return std::vector<std::string> 
         */
        std::vector<std::string> EdgesChecker(std::vector<double>& edgesval, const std::vector<std::string>& edges) {
            std::vector<std::string> tmp;
            for(int i = 0; i < 4; i++) {
                if (edges[i] != "") {
                    if (IsDouble(edges[i]) == false ) {
                        if (i == 0) tmp.push_back("wrong Xmin input");
                        if (i == 1) tmp.push_back("wrong XMax input");
                        if (i == 2) tmp.push_back("wrong Ymin input");
                        if (i == 3) tmp.push_back("wrong Ymax input");
                    } 
                    else edgesval[i] = std::stod(edges[i]);
                }
            }
            if (edgesval[0] >= edgesval[1]) tmp.push_back("Xmax should be > Xmin");
            if (edgesval[2] >= edgesval[3]) tmp.push_back("Ymax should be > Ymin");
            return tmp;
        }

        /**
         * @brief returns a pair of error/no error as a string; and calculation result as double
         * 
         * @param str calculation string
         * @param xstr x value string
         * @return std::pair<std::string,double> 
         */

        std::pair<std::string,double> GetRes(std::string& str, std::string& xstr ) {
            if (Errorchecker(str) == false) return {"wrong input string",0};
            if (!StrContainsX(str)) return {"",Calculator(str)};
            else {
                if (xstr == "" || IsDouble(xstr) == false) return {"wrong x input",0};
                else {
                    str = InsertXVal(str,std::stod(xstr));
                    return {"",Calculator(str)};
                }
            }
        }
        /**
         * @brief fills x and y vectors
         * 
         * @param x x vector
         * @param y y vector
         * @param edgesval values for step
         * @param str calculation string
         * @param i step
         */
        void CreateGraphVectors(std::vector<double>& x,std::vector<double>& y, std::vector<double>& edgesval, std::string& str, double& i) {
            bool xval = StrContainsX(str) ? true : false;
            for(double yval = 0, prevyval = 0; i <= edgesval[1]; i+= (edgesval[1]-edgesval[0]) / 80000) {
                std::string tmp = xval? InsertXVal(str,i) : str;
                yval = Calculator(tmp);
                if (yval - prevyval < -1000) {
                    i+= (edgesval[1]-edgesval[0]) / 80000;
                    return;
                } else {
                    x.push_back(i);
                    y.push_back(yval);
                }
                prevyval = yval;
            }
        }

//                                  P R I O R I T Y   T A B L E
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