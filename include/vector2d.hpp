struct Vector2D {
	double x {0.0};
	double y {0.0};
	
	// Soma de pares:
	Vector2D operator+(const Vector2D& coordinate) { return {x + coordinate.x, y + coordinate.y}; }
	
	// Soma e atribuição de valores:
	Vector2D& operator+=(const Vector2D& coordinate) {
		x += coordinate.x;
		y += coordinate.y;
		return *this;
	}

	Vector2D operator=(const Vector2D& coordinate) {
		x = coordinate.x;
		y = coordinate.y;
		return *this;
	}

	bool operator==(Vector2D& coordinate) {
		// TODO: Analisar o problema de arredondamento (10.00002)
		if (coordinate.x == x && coordinate.y == y) {
			return true;
		}
		return false;
	}
};
