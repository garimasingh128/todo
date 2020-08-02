#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* const argv[]) {
	std::string todoDbPath = std::string(getenv("HOME")) + "/.todo.db";
	std::vector<std::string> todos;
	std::fstream todoDb;
	todoDb.open(todoDbPath, std::ios::in);
	if (todoDb.is_open()) {
		std::string dbTodo;
		while (std::getline(todoDb, dbTodo)) {
			todos.push_back(dbTodo);
		}
		todoDb.close();
	}

	if (argc > 2 && argv[1] == std::string("add")) {
		std::ostringstream todoStream;
		for (int i = 2; i < argc; i++) {
			todoStream << argv[i] << ' ';
		}
		std::string todo = todoStream.str();
		todo.pop_back();
		todos.push_back(todo);
	} else if (argc == 3 && argv[1] == std::string("done")) {
		std::istringstream in(argv[2]);
		size_t id;
		if (in >> id && in.eof() && id > 0 && id < todos.size() + 1)
		{
			todos.erase(todos.begin() + id - 1);
		}
	}

	todoDb.open(todoDbPath, std::ios::out | std::ios::trunc);
	for (size_t i = 0; i < todos.size(); i++) {
		todoDb << todos.at(i) << std::endl;
		std::cout << i + 1 << ": " << todos.at(i) << std::endl;
	}
	todoDb.close();

	return EXIT_SUCCESS;
}
