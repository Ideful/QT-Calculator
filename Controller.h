#include "Model.h"

class Controller{
    public:
        Controller() {};
        ~Controller() {};
        void InitString(std::string& str) {
            processing_string_ = str;
        }
        std::string processing_string_;
        Model model_;
};
