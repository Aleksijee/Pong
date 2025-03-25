#include <SFML/Graphics.hpp>
#include <iostream>
#include <assert.h>
class Igrac {
public:
	sf::RectangleShape oblik;
	sf::Vector2f brzina;
	float x, y;


	//a, b - dimenzije pravogaonika
    //x,y - pozicije
    //vy - vertikalna brzina
	Igrac(float a, float b, float x, float y, float vy) {
		oblik.setSize(sf::Vector2f(a, b));
		oblik.setPosition(sf::Vector2f(x, y));
		brzina = { 0, vy };
		this ->x = a;
		this->y = b;
	}
	
	//default konstruktor
	Igrac() {
		oblik.setSize(sf::Vector2f(50, 250));
		oblik.setPosition(sf::Vector2f(0, 0));
		brzina = { 0, 0 };
	}

};