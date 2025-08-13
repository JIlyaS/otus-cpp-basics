#include <iostream>
#include <string>

#include "write_user_data.h"

int generate_random_value(int max) {
    std::srand(std::time(nullptr));

    int min = 0;
    int random_number = min + (std::rand() % (max - min + 1));
    return random_number;
}

void process_play(int min, int max) {

    int random_value{generate_random_value(max)};
    int user_number;
    int attempt_number = 0;
    std::string name;

    std::cout << "Давайте познакомимся. Напишите, как вас зовут (можно никнейм): ";
    std::cin >> name;

    std::cout << "Введите предыдущий ваш рекорд в игре: ";
    std::cin >> attempt_number;

    write_user_data(name, attempt_number);

    std::cout << "Введите число " << "(от " << min << " до " << max << "): ";

      while (true) {
        std::cin >> user_number;
        
        if (user_number == random_value) {
          std::cout << "Вы победили! Количество попыток = " << attempt_number << std::endl;
          write_user_data(name, attempt_number);
          break;
        }

        if (user_number > random_value) {
          std::cout << "Меньше чем " << user_number << std::endl;
        }

        if (user_number < random_value) {
          std::cout << "Больше чем " << user_number << std::endl;
        }

        attempt_number++;
    }
}