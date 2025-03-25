#include <SFML/Graphics.hpp>
#include <iostream>
#include <assert.h>
class Metak {
public:
	sf::RectangleShape oblik;
	sf::Vector2f brzina;


	//a - dimenzije kvadrata
	//x,y - pozicije
	//vx,vy - brzine
	Metak(float a, float x, float y, float vx, float vy) {
		oblik.setSize(sf::Vector2f(a, a));
		oblik.setPosition(sf::Vector2f(x, y));
		brzina = { vx, vy };
	}

	//default konstruktor
	Metak() {
		oblik.setSize(sf::Vector2f(50, 50));
		oblik.setPosition(sf::Vector2f(0, 0));
		brzina = { 0, 0 };
	}

	void idiDesno() {
		oblik.move(0.1, 0);
	}
	void idiLevo() {
		oblik.move(-0.1, 0);
	}



};