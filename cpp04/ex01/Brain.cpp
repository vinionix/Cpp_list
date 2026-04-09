#include "Brain.hpp"

Brain::Brain(){ std::cout << "Brain builder" << std::endl; }

Brain::Brain(const Brain& copy) : ideas(copy.ideas){ std::cout << "Brain copy builder" << std::endl; }

Brain& Brain::operator=(const Brain& other){
	if (this != &other){
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = ideas[i];
		}
	}
	return *this;
}

Brain::~Brain(){ std::cout << "Brain destroyer" << std::endl; }

void Brain::setIdeas(std::string ideas[100]) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = ideas[i];
	}
}

std::string Brain::getIdeas(int index) {
	return (this->ideas[index]);
}
