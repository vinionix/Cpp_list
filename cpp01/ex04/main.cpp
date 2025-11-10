#include "Replace.hpp"

int	main(int argc, char **argv)
{
	if (argc < 4 || argc > 4)
		return (0);
	std::ifstream	file(argv[1]);
	std::string		line;
	if (!file)
		return (1);
	std::string		name_file_out = std::string(argv[1]) + ".replace";
	std::ofstream	file_out(name_file_out.c_str());
	while (std::getline(file, line))
	{
		ft_replace(line, argv[2], argv[3]);
		file_out << line << std::endl;
	}
	file.close();
	std::ifstream	file_print_out(name_file_out.c_str());
	while (std::getline(file_print_out, line))
		std::cout << line << std::endl;
	file_print_out.close();
}
