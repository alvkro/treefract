#include "../include/vector2d.hpp"
#include <stack>

class TurtleState {
private:
	Vector2D start_pos;
	Vector2D end_pos;
	constexpr static double pi = 3.14159265358979323846;
	double gamma = 25; // Quanto o ramo vai girar (isso pode ser modificado...)
	Vector2D position {0.0, 0.0}; // posição atual da "tartaruga"
	double l {10.0}; // esse valor muda, é quanto F anda no plano. Mudar para diminuir conforme a necessidade!
	float angle {0.0}; // descrito em radianos 
public:
	TurtleState() {
		this->angle = deg_to_rad(angle);
	}
	
	Vector2D getPosition() { return position; }
	Vector2D getStartPos() { return start_pos; }
	Vector2D getEndPos() { return end_pos; }

	double deg_to_rad(double this_angle);
	void update_position();
	void rotate(const char side);
	void create_branch(char savepoint);
	void draw(char c, std::stack<TurtleState>& state_stack);
};
