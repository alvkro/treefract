cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto com base no diretório/executável visível
project(TreeSystem)

# Define o padrão C++ (C++17 é recomendado, mas pode ser ajustado conforme a necessidade)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Indica ao CMake onde encontrar os ficheiros .hpp
include_directories(include)

# Agrupa todos os ficheiros .cpp localizados na pasta src/
set(SOURCES
    src/main.cpp
    src/lsystem.cpp
    src/runningopt.cpp
    src/turtlestate.cpp # Nome inferido a partir de turtlesta... visível na imagem
)

# Cria o executável final com o nome do projeto utilizando os ficheiros fonte
add_executable(${PROJECT_NAME} ${SOURCES})
