#include "Model.h"

class Controller{
    public:
        Controller() {};
        ~Controller() {};
        void InitString(std::string& str) {
            processing_string_ = str;
        }



    std::pair<std::string,double>  method(std::string qwe, std::string asd) {
        return model_.vsya_huyna(qwe,asd);
    }






        std::string processing_string_;
        Model model_;
};
