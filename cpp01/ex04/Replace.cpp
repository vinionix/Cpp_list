#include "Replace.hpp"

void	ft_replace(std::string &str, std::string oldword, std::string replace)
{
	size_t	pos = 0;
	std::string	copy_str;
	while((pos = str.find(oldword)) && pos != std::string::npos)
	{
		copy_str.assign(&str[pos + oldword.length()]);
		str.insert(pos, replace);
		pos = pos + replace.length();
		str.erase(pos);
		str.append(copy_str);
	}
}
