#include "Model.h"

class Controller{
    public:
        explicit Controller() noexcept {};
        ~Controller() {};

/**
 * @brief returns a pair of errorcode<str> and calculated value <double>
 * 
 * @param calcs_tring string
 * @param x_string x value
 * @return std::pair<std::string,double> 
 */
        std::pair<std::string,double> GetRes(std::string calcs_tring, std::string x_string) {
            return model_.GetRes(calcs_tring,x_string);
        }

/**
 * @brief returns true if string has no input errors, false if it has
 * 
 * @param calc_str string to be checked
 * @return true 
 * @return false 
 */
        bool CheckIfInputStringIsOk(std::string& calc_str) {
            return model_.Errorchecker(calc_str);
        }

/**
 * @brief returns errors code in a vector<str> and fills value of vector with edges values
 * 
 * @param edgesval string values of edges
 * @param edges double value of edges
 * @return std::vector<std::string> 
 */
        std::vector<std::string> ValidateGraphEdges(std::vector<double>& edgesval, std::vector<std::string>& edges) {
            return model_.EdgesChecker(edgesval,edges);
        }

/**
 * @brief fills x and y vectors
 * 
 * @param x x vector
 * @param y y vector
 * @param edgesval values for step incrementation
 * @param str calulation string
 * @param i step
 */
        void MakeGraph(std::vector<double>& x,std::vector<double>& y, std::vector<double>& edgesval, std::string& str, double& i) {
            model_.CreateGraphVectors(x,y,edgesval,str,i);
        }

    private:
        Model model_;
};
