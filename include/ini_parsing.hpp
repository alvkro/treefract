#ifndef INI_PARSING_HPP
#define INI_PARSING_HPP

#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <sstream>

#include "../include/lsystem.hpp"
#include "..//include/runningopt.hpp"
#include "../include/turtlestate.hpp"
#include "../include/svg_exporter.hpp"

std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\r\n\"");
    size_t end   = s.find_last_not_of(" \t\r\n\"");
    return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

void LSystem::save_rules_ini(std::string& str) {
    char symbol = str[0];
    std::string rule;
    size_t pos = str.find(',');
    if (pos != std::string::npos) {
        rule = str.substr(pos + 1);
    }
    rule = trim(rule);
    addRule(symbol, rule);
}

void TurtleState::parse_config(int argc, char* argv[], LSystem& lsystem) {
    std::map<std::string, std::map<std::string, std::string>> config;
    if (argc < 3)
        throw std::runtime_error("Erro: Arquivo .ini não encontrado ou inválido.");
    std::ifstream file(argv[2]);
    if (!file.is_open())
        throw std::runtime_error("Erro: Arquivo não pôde ser aberto.");

    std::string section, line;
    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == ';' || line[0] == '#') continue;
        if (line[0] == '[') {
            section = line.substr(1, line.find(']') - 1);
        } else {
            size_t eq = line.find('=');
            if (eq == std::string::npos) continue;
            config[section][trim(line.substr(0, eq))] = trim(line.substr(eq + 1));
        }
    }

    // Settings
    this->gamma = deg_to_rad(std::stod(config.at("Settings").at("gamma")));
    this->angle = deg_to_rad(std::stod(config.at("Settings").at("angle")));
    this->l = std::stod(config.at("Settings").at("l"));

    // Formation
    lsystem.setAxiom(config.at("Formation").at("axiom"));
    for (auto i {0}; i < config.at("Formation").size() - 1; ++i) {
        std::string current_rule = config.at("Formation").at("rule" + std::to_string(i));
        lsystem.save_rules_ini(current_rule);
    }
}

#endif INI_PARSING_HPP