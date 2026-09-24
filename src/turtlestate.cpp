#include <cmath>
#include <stack>
#include "../include/turtlestate.hpp"

/// TODO: Resolver a questão da conversão de graus para radianos.

double TurtleState::deg_to_rad(double this_angle) { return this_angle * (pi / 180); }

void TurtleState::update_position(const double& angle) { this->position = {position.x + l * std::cos(angle), position.y + l * std::sin(angle)}; }

void TurtleState::rotate(const char side) {
	if (side == '+') {
		this->angle -= gamma;
	} else if (side == '-') {
		this->angle += gamma;
	}
}

void TurtleState::create_branch(char savepoint) {
	//* A ideia é percorrer toda a string, se achar [
	// a função começa e só termina se achar ].
	std::stack<char> branch;
}

