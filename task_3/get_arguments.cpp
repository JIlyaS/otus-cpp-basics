#include <iostream>
#include <string>

#include "get_table_records.h"
#include "clear_table_records.h"

struct ReturnParam {
  int min = 0;
  int max = 100;
};

ReturnParam get_arguments(int argc, char *argv[]) {
    std::string arg1_value;
    int max_params = 0;
    ReturnParam param;

    if (argc >= 2) {
        arg1_value = argv[1];

        if (arg1_value == "-max") {
          if (argc == 3) {
            param.max = std::stoi(argv[2]);
          }
        }

        if (arg1_value == "-table") {
          get_table_records();
        }

        if (arg1_value == "-clear") {
          clear_table_records();
        }
    }

    // if (argc == 3) {

    //   if (strcmp(argv[0], "-max") == 0) {
    //     std::cout << std::stoi(argv[1]);
    //   }
    // }


    //   for (int i{0}; i < argc; ++i) {
    //     // argv[i]. == "-max"
    //    if(strcmp(argv[i], "-max") == 0) {
    //       max = std::stoi(argv[i + 1]);

    //       std::cout << max;
    //    }
    // }

    return param;
}
