#pragma once

#include <iostream>

class Brain {
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain &other);
		~Brain();
		void setIdeas(std::string ideas[100]);
		std::string getIdeas(int index);
};

