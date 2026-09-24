#ifndef RUNNING_OPT_HPP
#define RUNNING_OPT_HPP

struct RunningOptions {
	int n_iterations {0};
	void validate_arguments(int& argc, char* argv[]);
};

#endif
