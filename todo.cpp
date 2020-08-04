#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* const argv[])
{
	std::string todoFilePath = std::string(getenv("HOME")) + "/.todo.db";
	std::vector<std::string> todos;
	std::fstream todoFileStream;
	todoFileStream.open(todoFilePath, std::ios::in);
	if (todoFileStream.is_open())
	{
		std::string todo;
		while (std::getline(todoFileStream, todo))
		{
			todos.push_back(todo);
		}
		todoFileStream.close();
	}

	if (argc > 2 && argv[1] == std::string("add"))
	{
		std::ostringstream todoStream;
		for (int i = 2; i < argc; i++)
		{
			todoStream << argv[i] << ' ';
		}
		std::string todo = todoStream.str();
		todo.pop_back();
		todos.push_back(todo);
	}
	else if (argc == 3 && argv[1] == std::string("done"))
	{
		std::istringstream idArg(argv[2]);
		size_t id;
		if (idArg >> id && idArg.eof() && id > 0 && id < todos.size() + 1)
		{
			todos.erase(todos.begin() + id - 1);
		}
	}

	todoFileStream.open(todoFilePath, std::ios::out | std::ios::trunc);
	if (todoFileStream.fail())
	{
		std::cout << "Couldn't open " + todoFilePath << std::endl;
		return EXIT_FAILURE;
	}

	for (size_t i = 0; i < todos.size(); i++)
	{
		todoFileStream << todos.at(i) << std::endl;
		std::cout << i + 1 << ": " << todos.at(i) << std::endl;
	}
	todoFileStream.close();

	return EXIT_SUCCESS;
}
