#include <SFML/Graphics.hpp>
#include <iostream>
#include <assert.h>
#include <math.h>
#include <SFML/Audio.hpp>
#include <filesystem>
class T {
public:
	int a, b, x, y, xk, yk;
	sf::RectangleShape oblik;


	
	T(int a, int b, int x, int y)
	{
		oblik.setSize(sf::Vector2f(a, b));
		oblik.setPosition(sf::Vector2f(x, y));
		this->a = a;
		this->b = b;
		this->x = x;
		this->y = y;
	}
	void updatePositionBloka() {
		oblik.setPosition(x, y);
	}

	


};