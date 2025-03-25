#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    //------------------------INITIALISE---------------------------------//
    sf::RenderWindow prozorcic(sf::VideoMode(1500, 900), "Igrica");
    //oblici (napravili smo igraca dimenzije 50x250 i mrezu (5x900) i metak 50x50)
    sf::RectangleShape igrac(sf::Vector2f(50, 250));
    igrac.setFillColor(sf::Color::White);

    sf::RectangleShape mreza(sf::Vector2f(4, 900));
    igrac.setFillColor(sf::Color::White);

    sf::RectangleShape metak(sf::Vector2f(50, 50));
    igrac.setFillColor(sf::Color::White);
    int* x = new int(0);
    //brzina
    float brzinaMetka = 300;
    float brzinaIgraca = 200;

    //oblici 
    bool tacno = 0;
    sf::Clock c;
    float klikCounter = 0;
    int y1 = 0;
    int y2 = 0;
    float pozicijaMetka = 725;
    float pozicijaIgraca1 = 300;
    float pozicijaIgraca2 = 300;
    bool MetakIdeDesno = true;
    bool Opseg = true;
    bool desno = false;

    //------------------------INITIALISE---------------------------------//
    while (prozorcic.isOpen())
    {
        //-----------------------UPDATE-------------------------------//
        sf::Event dogadjaj;
        while (prozorcic.pollEvent(dogadjaj))
        {

            if (dogadjaj.type == sf::Event::Closed)
            {
                prozorcic.close();
                std::cout << "Zatvorili ste prozorcic!" << std::endl;
                std::cout << "Vasa brzina klikovanja je " << klikCounter / c.getElapsedTime().asSeconds() << " klika pri sekundi!" << std::endl;;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            y1--;
            std::cout << "y1 =" << y1 << std::endl;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            y1++;
            std::cout << "y1 =" << y1 << std::endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            std::cout << "pritisnuo je dugme gore" << std::endl;
            y2--;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            std::cout << "pritisnuo je dugme Dole" << std::endl;
            y2++;

        }

        //ogranicavamo vrednosti y1 i y2
        if (y1 < -300)
            y1 = -300;
        if (y2 < -300)
            y2 = -300;
        if (y1 > 350)
            y1 = 350;
        if (y2 > 350)
            y2 = 350;
        pozicijaIgraca1 = 300 + y1;
        pozicijaIgraca2 = 300 + y2;


        //kretanje metka
        float vreme = c.getElapsedTime().asSeconds();  // Prošlo vreme u sekundama
        pozicijaMetka = pozicijaMetka + vreme * brzinaMetka
        if ((pozicijaMetka < 1350 && pozicijaMetka >= 150) && vreme = -2c) {            
            Opseg = true;
            if (MetakIdeDesno) {
                pozicijaMetka = 150 + vreme * brzinaMetka;
            }
            else
            {
                pozicijaMetka = 1300 - vreme * brzinaMetka;
            }
            if (pozicijaMetka > 1300 && (pozicijaIgraca2 < 450 && pozicijaIgraca2 > 150)) {
                MetakIdeDesno = false;
                c.restart();
            }
            else if (pozicijaMetka < 150) {
                MetakIdeDesno = true;
                c.restart();
            }
           
        }
        if (pozicijaMetka >= 1350 && Opseg == true)
        {
            Opseg = false;
            c.restart();
            desno = true;            
        }
        if (!Opseg && desno) {
            pozicijaMetka = 1350 + vreme * brzinaMetka;
        }
        if (pozicijaMetka < 150 && Opseg == true)
        {
            Opseg = false;
            c.restart();
            desno = false;
        }
        if (!Opseg && !desno) {
            pozicijaMetka = 150 - vreme * brzinaMetka;
        }



        std::cout << "Opseg: " << Opseg << std::endl;
        std::cout << "Vreme: " << vreme << std::endl;
        std::cout << "pozicijaMetka: " << pozicijaMetka << std::endl;

        //-----------------------UPDATE-------------------------------//
       
        //-----------------------DRAW--------------------------------//
        prozorcic.clear(sf::Color::Black);
        igrac.setPosition(100, pozicijaIgraca1);
        prozorcic.draw(igrac);
        igrac.setPosition(1350, pozicijaIgraca2);
        prozorcic.draw(igrac);
        mreza.setPosition(748, 0);
        prozorcic.draw(mreza);
        metak.setPosition((pozicijaMetka), 400);
        prozorcic.draw(metak);
    
        prozorcic.display();
        //-----------------------DRAW--------------------------------//
    }
    delete x;
    return 0; 
}