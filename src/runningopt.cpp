#include "../include/runningopt.hpp"
void RunningOptions::validate_arguments(int& argc, char* argv[]) {
	n_iterations = std::stoull(argv[1]);
}
