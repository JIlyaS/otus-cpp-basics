#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct Player {
  std::string name;
  unsigned int count;

  Player(std::string p_name, int p_count)
        : name(std::move(p_name)), count(p_count)
    {}
};

void read_user_data() {
  const std::string high_scores_filename = "high_scores.txt";

  std::ifstream fsi{high_scores_filename};

  if (!fsi.is_open()) {
		std::cerr << "Невозможно открыть файл на чтение: " << high_scores_filename << "!" << std::endl;
		exit(-1);
	}

  std::cout << "Таблица результатов:" << std::endl;

  if (fsi.peek() == std::ifstream::traits_type::eof()) {
	 std::cout << "Таблица результатов пуста." << std::endl;
	 fsi.close();
	 return;
  }

  std::string username;
  int high_score = 0;
  std::vector<Player> players;
  std::vector<Player> view_players;

  while (true) {

	fsi >> username;
	fsi >> high_score;

	players.emplace_back(username, high_score);

	fsi.ignore();

	if (fsi.fail()) {
		break;
	}

	std::cout << username << '\t' << high_score << std::endl;
  }

  for (size_t i = 0; i < players.size(); ++i) {
	auto current_player = std::find_if(view_players.begin(), view_players.end(),
                           [players, i](const Player& p) { return p.name == players[i].name; });

	if (current_player == end(view_players)) {
      view_players.emplace_back(players[i].name, players[i].count);
	} else {
      int position = std::distance(view_players.begin(), current_player);
    
	  // TODO: Не получилась замена значения в векторе с проверкой по count
	 //   view_players.emplace(position, { current_player->name, current_player->count });
	}
  }

  // TODO: Вывод обновленной таблицы результатов
//   for (size_t i = 0; i < view_players.size(); ++i) {
// 	std::cout << view_players[i].name << '\t' << view_players[i].count << std::endl;
//   }

  fsi.close();
}