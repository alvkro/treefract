# 🌳 TreeFract

> Gerador de plantas e estruturas fractais em C++ utilizando L-Systems (Lindenmayer Systems) e interpretação geométrica 2D.

## Introdução

O **TreeFract** é um projeto desenvolvido em **C++** focado na geração e visualização de geometrias fractais orgânicas através de **Sistemas-L (Lindenmayer Systems)**. 

Criados originalmente pelo biólogo Aristid Lindenmayer em 1968, os L-Systems são gramáticas formais que aplicam regras recursivas de substituição de caracteres sobre uma string inicial (*axioma*). A partir dessas regras simples, emergem padrões complexos e autorreferenciados que simulam o crescimento natural de plantas, como algas, arbustos, árvores e flores.

## Implementação

O projeto está dividido em duas etapas principais:

### 1. Motor do L-System (Geração de Texto)
- **Substituição de Cadeias:** Aplicação recursiva de regras de produção sobre a string para simular iterações de crescimento.

### 2. Interpretador 2D (Gráficos de Tartaruga / Turtle Graphics)
A conversão da string em geometria visual é realizada através de um autômato de estado (*Turtle Graphics*):
- **`TurtleState`:** Gerencia o estado atual da tartaruga em tempo de execução, incluindo posição \\((x, y)\\) e ângulo de direção mantido nativamente em radianos.
- **`Vector2D`:** Estrutura de matemática vetorial customizada com sobrecarga de operadores (`+`, `+=`, `==` com tolerância de precisão `epsilon` de 2 casas decimais) para calcular deslocamentos trigonométricos \\((\Delta x = L \cdot \cos\theta, \Delta y = L \cdot \sin\theta)\\).
- **Gerenciamento de Ramificações (`std::stack`):** Uso de uma pilha de estados para salvar (`[`) e restaurar (`]`) as coordenadas e o ângulo da tartaruga, permitindo desenhar galhos paralelos e estruturas ramificadas.

## Mapeamento da Gramática

| Símbolo | Ação da Tartaruga |
| :---: | :--- |
| **`F`** | Avança uma distância \\(L\\) e desenha um segmento de reta |
| **`+`** | Gira a tartaruga em \\(+\gamma\\) graus (sentido anti-horário) |
| **`-`** | Gira a tartaruga em \\(-\gamma\\) graus (sentido horário) |
| **`[`** | **Push:** Empilha o estado atual `(posição, ângulo)` para criar uma ramificação |
| **`]`** | **Pop:** Desempilha e restaura o último estado salvo para retornar à bifurcação |


