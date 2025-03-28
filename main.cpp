#include <SFML/Graphics.hpp>
#include <iostream>
#include <assert.h>
#include <math.h>
#include "Blok.h"
#include <SFML/Audio.hpp>
#include <filesystem>
int main()
{



	sf::RenderWindow prozor(sf::VideoMode(500, 1000), "TETRIS");
	int korak = 50;
	T T(50, 50, 100, 100);
	sf::Clock sat;
	int Trot = 0;
	int xk = 0;
	int yk = 0;




	int Mapa[20][10];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 10; j++)
		{
			Mapa[i][j] = 0;
		}





	while (prozor.isOpen()) {
		sf::Event dogadjaj;
		while (prozor.pollEvent(dogadjaj)) {
			if (dogadjaj.type == sf::Event::Closed)
			{
				prozor.close();
			}
			if (dogadjaj.type == sf::Event::KeyPressed && dogadjaj.key.code == sf::Keyboard::Down)
			{
				T.y = T.y + korak;
				if (T.y > prozor.getSize().y - T.b)
				{
					T.y = prozor.getSize().y - T.b;
				}
			}
			if (dogadjaj.type == sf::Event::KeyPressed && dogadjaj.key.code == sf::Keyboard::Right)
			{
				T.x = T.x + korak;
				if (T.x > prozor.getSize().x - T.a)
				{
					T.x = prozor.getSize().x - T.a;
				}
			}
			if (dogadjaj.type == sf::Event::KeyPressed && dogadjaj.key.code == sf::Keyboard::Left)
			{
				T.x = T.x - korak;
				if (T.x < 0)
				{
					T.x = 0;
				}
			}
			if (dogadjaj.type == sf::Event::KeyPressed && dogadjaj.key.code == sf::Keyboard::Z)
			{
				Trot++;
				if (Trot == 4)
					Trot = 0;
			}
			

		}
		int matrica[4][4] = {
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0}
		};

		int mat0[4][4] = {
			{0, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		};

		int mat1[4][4] = {
			{0, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		};

		int mat2[4][4] = {
			{0, 1, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};

		int mat3[4][4] = {
			{0, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		};

		switch (Trot)
		{
		case 0:
			memcpy(matrica, mat0, sizeof(mat0));
			break;
		case 1:
			memcpy(matrica, mat1, sizeof(mat1));
			break;
		case 2:
			memcpy(matrica, mat2, sizeof(mat2));
			break;
		case 3:
			memcpy(matrica, mat3, sizeof(mat3));
			break;
		}


		
		prozor.clear(sf::Color::Black);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				
				if ( matrica[i][j] == 1)
				{
					//sf::RectangleShape T;
					T.oblik.setFillColor(sf::Color::Green);
					T.oblik.setSize(sf::Vector2f(50, 50));
					T.oblik.setPosition(sf::Vector2f(T.x+j*50, T.y+i*50));				
					prozor.draw(T.oblik);
					std::cout << "x = " << xk << std::endl;
					std::cout << "y = " << yk << std::endl;
					
				}
				
			}
		
		}

		memcpy(Mapa, matrica, sizeof(matrica));
	
		
		
		
		 
		prozor.setPosition(sf::Vector2i(750, -5));
		//prozor.clear(sf::Color::Black);
		prozor.draw(T.oblik);
		prozor.display();

	}
	for (int i = 0; i < 20; i++)
	{


		for (int j = 0; j < 10; j++)
		{
			std::cout << Mapa[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
