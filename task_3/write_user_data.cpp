#include <iostream>
#include <fstream>
#include <string>

void write_user_data(std::string name, int attempt_number) {
  const std::string high_scores_filename = "high_scores.txt";

  std::ofstream fso{high_scores_filename, std::ios_base::app};

  if (!fso.is_open()) {
		std::cout << "Невозможно открыть файл на запись: " << high_scores_filename << "!" << std::endl;
		exit(-1);
	}

  fso << name << ' ';
	fso << attempt_number;
	fso << std::endl;

  fso.close();
}