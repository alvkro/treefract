#include "../include/lsystem.hpp"
#include "..//include/runningopt.hpp"
#include "../include/turtlestate.hpp"
#include "../include/svg_exporter.hpp"
#include <iostream>
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
	lsystem.setAxiom("X");
	lsystem.addRule('F', "FF");
	lsystem.addRule('X', "F-[[X]+X]+F[+FX]-X");
	output = lsystem.generate(run_opt.n_iterations);
	
	for (auto i : output) {
		turtlestate.draw(i, state_stack);
		if (i == 'F') {
			lines.push_back({turtlestate.getStartPos(), turtlestate.getEndPos()});
		}
	}
	if (SVGExporter::save(lines, "arvores.svg")) {
		std::cout << "Imagem salva" << "\n";
	}
}
