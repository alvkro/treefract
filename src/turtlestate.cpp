#include <cmath>
#include <stack>
#include "../include/turtlestate.hpp"

double TurtleState::deg_to_rad(double this_angle) { return this_angle * (pi / 180); }

void TurtleState::update_position() { this->position = {position.x + l * std::cos(this->angle), position.y + l * std::sin(this->angle)}; }

void TurtleState::rotate(const char side) {
	if (side == '+') {
		this->angle -= gamma;
	} else if (side == '-') {
		this->angle += gamma;
	}
}

void TurtleState::draw(char c, std::stack<TurtleState>& state_stack) {
	if (c == 'F') {
		start_pos = this->position;
		update_position();
		end_pos = this->position;
	} else if (c == '+' || c == '-') {
		rotate(c);
	} else if (c == '[') {
		state_stack.push(*this);
	} else if(c == ']') {
		*this = state_stack.top();
		state_stack.pop();
	}

}

