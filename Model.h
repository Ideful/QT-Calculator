#include "header.h"

class Model {
    public:
        std::string calc_string_;
        std::string calc_string_with_x_;
        double x_val_;
        double result_;
        double result_with_x_;
        Model() {};
        ~Model() {};
        bool CheckForErrors() {
            return Errorchecker(calc_string_);
        }
        void Calculate() {
            result_ = Calculator(calc_string_);
        } 
        void GetXString() {
            calc_string_with_x_ = InsertXVal(calc_string_,x_val_);
        }
        void CalculateWithX() {
            result_with_x_ = Calculator(calc_string_with_x_);
        }
};
