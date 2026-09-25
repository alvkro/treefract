#include "../include/lsystem.hpp"
#include "..//include/runningopt.hpp"
#include "../include/turtlestate.hpp"
#include <stack>
#include <iostream>

/// TODO: receber um arquivo com os axiomas
int main(int argc, char* argv[]) {
	std::string output;
	LSystem lsystem;
	RunningOptions run_opt;
	TurtleState turtlestate;
	std::stack<TurtleState> state_stack;

	run_opt.validate_arguments(argc, argv);
	lsystem.setAxiom("X");
	lsystem.addRule('F', "FF");
	lsystem.addRule('X', "F[+X]");
	output = lsystem.generate(run_opt.n_iterations);
	
	for (auto i : output) {
		turtlestate.draw(i, state_stack);
		std::cout << turtlestate.getPosition().x << ", " << turtlestate.getPosition().y << "\n";
	}
}
