#include "../include/lsystem.hpp"
#include "..//include/runningopt.hpp"
#include "../include/turtlestate.hpp"
#include "../include/ini_parsing.hpp"
#include "../include/svg_exporter.hpp"
#include <stack>
#include <vector>

/// TODO: receber um arquivo com os axiomas
int main(int argc, char* argv[]) {
	std::string output;
	LSystem lsystem;
	RunningOptions run_opt;
	TurtleState turtlestate;
	std::stack<TurtleState> state_stack;
	std::vector<LineSegment> lines;

	run_opt.validate_arguments(argc, argv);
	turtlestate.parse_config(argc, argv, lsystem);
	output = lsystem.generate(run_opt.n_iterations);
	
	for (auto i : output) {
		turtlestate.draw(i, state_stack);
		if (i == 'F'|| i == 'G') {
			lines.push_back({turtlestate.getStartPos(), turtlestate.getEndPos()});
		}
	}
	if (SVGExporter::save(lines, "arvores.svg")) {
		std::cout << "Imagem salva" << "\n";
	}
}
