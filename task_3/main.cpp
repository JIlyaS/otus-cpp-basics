#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

// #include "read_user_data.hpp"
// #include "write_user_data.hpp"
#include "process_play.h"
#include "get_arguments.h"

#include "get_table_records.h"


int main(int argc, char* argv[]) {
    std::cout << "Добро пожаловать в игру 'Угадай число'." << std::endl;

    ReturnParam param = get_arguments(argc, argv);

    process_play(param.min, param.max);
    
    while (true) {

        std::string answer;

        std::cout << "Хотите сыграть снова? (yes | no)" << std::endl;
        std::cin >> answer;

        if (answer == "yes") {
          process_play(param.min, param.max);
        } else if (answer == "no") {
          break;
        } else {
            std::cout << "Не понял ответ! Значит играем снова?" << std::endl;
        }

        answer = "";
    }
}