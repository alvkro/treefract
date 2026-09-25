#ifndef SVG_EXPORTER_HPP
#define SVG_EXPORTER_HPP

/// Isso aqui foi vibecodado, tenho paciencia nao.........

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include "vector2d.hpp"

// Representa um segmento de reta desenhado pela tartaruga
struct LineSegment {
    Vector2D start;
    Vector2D end;
};

class SVGExporter {
public:
    // Exporta um vetor de segmentos para um arquivo SVG com enquadramento automático (Bounding Box)
    static bool save(const std::vector<LineSegment>& lines, 
                     const std::string& filename, 
                     double width = 800.0, 
                     double height = 800.0, 
                     double padding = 40.0) {
        
        if (lines.empty()) {
            std::cerr << "[SVGExporter] Aviso: Nenhum segmento para exportar.\n";
            return false;
        }

        // 1. Encontra os limites (Bounding Box) de todas as linhas para centralizar a imagem
        double min_x = lines[0].start.x, max_x = lines[0].start.x;
        double min_y = lines[0].start.y, max_y = lines[0].start.y;

        for (const auto& line : lines) {
            min_x = std::min({min_x, line.start.x, line.end.x});
            max_x = std::max({max_x, line.start.x, line.end.x});
            min_y = std::min({min_y, line.start.y, line.end.y});
            max_y = std::max({max_y, line.start.y, line.end.y});
        }

        double box_width = (max_x - min_x) + 2 * padding;
        double box_height = (max_y - min_y) + 2 * padding;

        if (box_width <= 0) box_width = width;
        if (box_height <= 0) box_height = height;

        // 2. Abre o arquivo para escrita
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "[SVGExporter] Erro ao abrir arquivo: " << filename << "\n";
            return false;
        }

        // 3. Escreve o cabeçalho do SVG (viewBox garante escala perfeita)
        file << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
             << "viewBox=\"0 0 " << box_width << " " << box_height << "\" "
             << "width=\"" << width << "\" height=\"" << height << "\" "
             << "style=\"background-color: #121218;\">\n";

        file << "  <g stroke=\"#4CAF50\" stroke-width=\"1.5\" stroke-linecap=\"round\">\n";

        // 4. Escreve cada segmento (Invertendo o eixo Y para corresponder ao plano cartesiano)
        for (const auto& line : lines) {
            double sx = (line.start.x - min_x) + padding;
            double sy = box_height - ((line.start.y - min_y) + padding);
            double ex = (line.end.x - min_x) + padding;
            double ey = box_height - ((line.end.y - min_y) + padding);

            file << "    <line x1=\"" << sx << "\" y1=\"" << sy 
                 << "\" x2=\"" << ex << "\" y2=\"" << ey << "\" />\n";
        }

        file << "  </g>\n";
        file << "</svg>\n";

        file.close();
        return true;
    }
};

#endif

