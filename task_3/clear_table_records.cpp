#include <iostream>
#include <fstream>
#include <string>

void clear_table_records() {
  const std::string high_scores_filename = "high_scores.txt";
  std::ofstream ofs;
  ofs.open(high_scores_filename, std::ofstream::out | std::ofstream::trunc);
  ofs.close();

  std::cout << "Таблица результатов очищена."; 

  exit(0);
}