#include "../include/lsystem.hpp"
#include "..//include/runningopt.hpp"
#include <iostream>


/// TODO: receber argumentos CLI para valores em generate
int main(int argc, char* argv[]) {
	std::string output;
	LSystem lsystem;
	RunningOptions run_opt;

	run_opt.validate_arguments(argc, argv);
	lsystem.setAxiom("X");
	lsystem.addRule('F', "FF");
	lsystem.addRule('X', "F[+X]");
	output = lsystem.generate(run_opt.n_iterations);
	std::cout << output << "\n";
}
