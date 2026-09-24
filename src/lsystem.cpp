#include "../include/lsystem.hpp"

using value_type = unsigned long long;

/// Formato semelhante ao das anotações: 
/// F -> FF
/// x -> F[+X]
void LSystem::setAxiom(const std::string& new_axiom) { axiom = new_axiom; }

void LSystem::addRule(char symbol, const std::string& rule) { rules[symbol] = rule; }

std::string LSystem::generate(value_type iterations) {
	std::string current = axiom;
	for (int i = 0; i < iterations; i++) {
		current = parse_axiom(current);
	}
	return current; 
}

std::string LSystem::parse_axiom(std::string& current_axiom) {
	/// Sugestão: salvar o axiom em uma var current
	std::string temp_string;
	for (auto i : current_axiom) {
		if (rules.find(i) != rules.end()) {
			temp_string += rules.at(i);
		} else {
			temp_string.push_back(i);
		}
	}
	axiom = temp_string;
	temp_string.clear();
	return axiom;
}

std::string LSystem::getAxiom() { return axiom; }
std::unordered_map<char, std::string> LSystem::getRules() { return rules; }



