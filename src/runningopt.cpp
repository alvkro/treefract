#include "../include/runningopt.hpp"
#include <stdexcept>

void RunningOptions::validate_arguments(int& argc, char* argv[]) {
	n_iterations = std::stoull(argv[1]);
}
