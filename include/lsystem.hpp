#ifndef LSYSTEM_HPP
#define LSYSTEM_HPP

#include <string>
#include <unordered_map>
using value_type = unsigned long long;

class LSystem {
public:
    void setAxiom(const std::string& axiom);
    void addRule(char symbol, const std::string& rule);
    std::string generate(value_type iterations);
    std::string parse_axiom(std::string& current_axiom); 

    std::string getAxiom();
    std::unordered_map<char, std::string> getRules();

private:
    std::string axiom;
    std::unordered_map<char, std::string> rules;
};

#endif

