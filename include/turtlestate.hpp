#include "../include/vector2d.hpp"

class TurtleState {
private:
	constexpr static double pi = 3.14159265358979323846;
	const double gamma = 25; // Quanto o ramo vai girar (isso pode ser modificado...)
	Vector2D position {0.0, 0.0}; // posição atual da "tartaruga"
	const double l {10.0}; // esse valor muda, é quanto F anda no plano. Mudar para diminuir conforme a necessidade!
	float angle {0.0}; // descrito em radianos 
public:
	TurtleState() {
		this->angle = deg_to_rad(angle);
	}

	double deg_to_rad(double this_angle);
	void update_position(const double& angle);
	void rotate(const char side);
	void create_branch(char savepoint);
};
