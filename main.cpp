#include <SFML/Graphics.hpp>
#include <iostream>
#include <assert.h>
#include <math.h>
#include "Metak.h"
#include "Igrac.h"
#include <SFML/Audio.hpp>
#include <filesystem>
int main()
{

    //------------------------INITIALISE---------------------------------//
    sf::RenderWindow prozorcic(sf::VideoMode(1500, 900), "Igrica");

    float prozorX = prozorcic.getSize().x;
    float prozorY = prozorcic.getSize().y;


    //oblici (napravili smo igraca dimenzije 50x250 i mrezu (5x900) i metak 50x50)
    sf::RectangleShape igrac(sf::Vector2f(50, 250));
    igrac.setFillColor(sf::Color::White);

    Igrac igrac1(50, 250, 100, 300, 1);
    Igrac igrac2(50, 250, 1350, 300, 1);
    Metak metak(50.f, 725.f, 450.f, -10.f, 0.f);

    sf::SoundBuffer soundo;
    sf::SoundBuffer soundi;
   // soundo.loadFromFile("C:/Users/Aleksije/Desktop/n.wav");
   // soundi.loadFromFile("C:/Users/Aleksije/Desktop/m.wav");

    sf::Music muzika;
  //  muzika.openFromFile("C:/Users/Aleksije/Desktop/The Prodigy, Pendulum - Voodoo People - Pendulum Mix.flac");
  //  muzika.play();
  //  muzika.setLoop(true);
    float pic = 1;
    float vol = 1;
  //  float glasnoca = muzika.getVolume();

    sf::Sound sound;
    sf::Sound soumd;
  //  sound.setBuffer(soundo);
   // soumd.setBuffer(soundi);


    int i1 = 0;
    int i2 = 0;



    sf::Text tekst1;
    sf::Text tekst2;
    sf::Text tekstPobednik;
    sf::Font sevenseg;
    sevenseg.loadFromFile("C:/Users/Aleksije/Desktop/Seven Segment.ttf");
    tekst1.setPosition(sf::Vector2f(700, 0));
    tekst1.setFont(sevenseg);
    tekst1.setCharacterSize(100);
    tekst1.setFillColor(sf::Color::White);

    tekst2.setPosition(sf::Vector2f(750 + 8, 0));
    tekst2.setFont(sevenseg);
    tekst2.setCharacterSize(100);
    tekst2.setFillColor(sf::Color::White);

    tekstPobednik.setPosition(sf::Vector2f(0, 0));
    tekstPobednik.setFont(sevenseg);
    tekstPobednik.setCharacterSize(100);
    tekstPobednik.setFillColor(sf::Color::White);



    //  Igrac igrac2(50, 250, 1350, 300, 1);





    sf::RectangleShape mreza(sf::Vector2f(4, 900));
    igrac.setFillColor(sf::Color::White);

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
    bool smer = true;
    bool sudar = false;
    float pPozicijaMetka;

    // prozorcic.setPosition(sf::Vector2i(150, 0));



    std::cout << "igrac 1 ima: 0 poena!" << std::endl;
    std::cout << "igrac 2 ima: 0 poena!" << std::endl;


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
                if (i1 > i2)
                    std::cout << std::endl << "Pobednik je igrac broj 1!!!" << std::endl;
                else if (i2 > i1)
                    std::cout << std::endl << "Pobednik je igrac broj 2!!!" << std::endl;
                else
                    std::cout << std::endl << "It's a tie!" << std::endl;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sf::Vector2f pozicijaIgr1 = igrac1.oblik.getPosition();
            igrac1.oblik.setPosition(pozicijaIgr1 - sf::Vector2f(igrac1.brzina));

            if (pozicijaIgr1.y < 0)
                igrac1.oblik.setPosition(sf::Vector2f(igrac1.oblik.getPosition().x, 0)); //hardcodovane vrednosti pazi se

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sf::Vector2f pozicijaIgr1 = igrac1.oblik.getPosition();
            igrac1.oblik.setPosition(pozicijaIgr1 + sf::Vector2f(igrac1.brzina));

            if (pozicijaIgr1.y > (prozorcic.getSize().y - igrac1.oblik.getSize().y))
                igrac1.oblik.setPosition(sf::Vector2f(igrac1.oblik.getPosition().x, (prozorY - igrac1.oblik.getSize().y))); //hardcodovane vrednosti pazi se

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sf::Vector2f pozicijaIgr2 = igrac2.oblik.getPosition();
            igrac2.oblik.setPosition(pozicijaIgr2 - sf::Vector2f(igrac2.brzina));

            if (pozicijaIgr2.y < 0)
                igrac2.oblik.setPosition(sf::Vector2f(igrac2.oblik.getPosition().x, 0)); //hardcodovane vrednosti pazi se

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sf::Vector2f pozicijaIgr2 = igrac2.oblik.getPosition();
            igrac2.oblik.setPosition(pozicijaIgr2 + sf::Vector2f(igrac2.brzina));

            if (pozicijaIgr2.y > (prozorY - igrac2.oblik.getSize().y))
                igrac2.oblik.setPosition(sf::Vector2f(igrac2.oblik.getPosition().x, (900 - igrac2.oblik.getSize().y))); //hardcodovane vrednosti pazi se

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            igrac2.oblik.setFillColor(sf::Color::Green);
            igrac2.oblik.setSize(sf::Vector2f(50, 50)); //hardcodovane vrednosti pazi se

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        {
            igrac2.brzina.y = abs(igrac2.brzina.y) - 0.001; //hardcodovane vrednosti pazi se
            
        }



        metak.oblik.move(metak.brzina.x, metak.brzina.y);

        sf::Vector2f pozicijaM = metak.oblik.getPosition();
        if ((pozicijaM.x <= 150 && pozicijaM.x >= 145) && (igrac1.oblik.getPosition().y < (pozicijaM.y + metak.oblik.getSize().y) && igrac1.oblik.getPosition().y >(pozicijaM.y - igrac1.oblik.getSize().y))) {

            float l = igrac1.oblik.getPosition().y - pozicijaM.y + (igrac1.oblik.getSize().y / 2 - metak.oblik.getSize().y / 2);
            metak.brzina.y = metak.brzina.x * tan(asin(l / 281.25));
            metak.brzina.x = -metak.brzina.y / tan(asin(l / 281.25));
            sound.play();

        }
        /*   if ((pozicijaM.y < (igrac1.oblik.getPosition().y + igrac1.oblik.getSize().y)) &&
               (pozicijaM.y > (igrac1.oblik.getPosition().y + igrac1.oblik.getSize().y - 5))
                && (pozicijaM.x < (igrac1.oblik.getPosition().x + igrac1.oblik.getSize().x) - 5) && (pozicijaM.x >= igrac1.oblik.getPosition().x)
               ) {
               metak.brzina.x = metak.brzina.x;
               metak.brzina.y = -metak.brzina.y;
               sound.play();
           }
           */


        if ((pozicijaM.x >= 1300 && pozicijaM.x <= 1305) && (igrac2.oblik.getPosition().y < (pozicijaM.y + metak.oblik.getSize().y) && igrac2.oblik.getPosition().y >(pozicijaM.y - igrac2.oblik.getSize().y))) {
            float l = igrac2.oblik.getPosition().y - pozicijaM.y + (igrac2.oblik.getSize().y / 2 - metak.oblik.getSize().y / 2);
            metak.brzina.y = -metak.brzina.x * tan(asin(l / 381.25)); //181.25
            metak.brzina.x = metak.brzina.y / tan(asin(l / 381.25));
            soumd.play();
        }

        if (pozicijaM.y <= 0)
        {
            metak.brzina.x = metak.brzina.x;
            metak.brzina.y = -metak.brzina.y;
        }

        if (pozicijaM.y >= prozorY - metak.oblik.getSize().y)
        {
            metak.brzina.x = metak.brzina.x;
            metak.brzina.y = -metak.brzina.y;
        }

        if (pozicijaM.x >= prozorX) {
            metak.oblik.setPosition(725, 450);
            metak.brzina.y = 0;
            metak.brzina.x = 1 + 0.1 * (i1 + i2);
            igrac1.oblik.setPosition(sf::Vector2f(100, 300));
            igrac2.oblik.setPosition(sf::Vector2f(1350, 300));
            igrac1.brzina.y = igrac1.brzina.y + 0.1;
            igrac2.brzina.y = igrac2.brzina.y + 0.1;
           // pic = pic + 0.01;
            vol = vol + 1;

            //   prozorcic.setPosition(sf::Vector2i(450, 0));


            std::cout << "\033[1;1H" << "igrac 1 ima: " << ++i1 << " poena!";
        }
        if (pozicijaM.x <= -50) {
            metak.oblik.setPosition(725, 450);
            metak.brzina.y = 0;
            igrac1.oblik.setPosition(sf::Vector2f(100, 300));
            igrac2.oblik.setPosition(sf::Vector2f(1350, 300));
            igrac1.brzina.y = igrac1.brzina.y + 0.1;
            igrac2.brzina.y = igrac2.brzina.y + 0.1;
            metak.brzina.x = -1 - 0.1 * (i1 + i2);
           // pic = pic + 0.01;
            vol = vol + 1;

            //  prozorcic.setPosition(sf::Vector2i(0, 0));

            std::cout << "\033[2;1H" << "igrac 2 ima: " << ++i2 << " poena!";
        }


        //      if ((pozicijaM.x <= (igrac1.oblik.getPosition().x + igrac1.oblik.getSize().x)) && (pozicijaM.x >= igrac1.oblik.getPosition().x - metak.oblik.getSize().x) &&
          //        (pozicijaM.y >= igrac1.oblik.getPosition().y + igrac1.oblik.getSize().y)) {
            //      metak.brzina.x = metak.brzina.x;
            //      metak.brzina.y = -metak.brzina.y;
           //   }

            //if ((pozicijaM.x <= (igrac1.oblik.getPosition().x + igrac1.oblik.getSize().x)) && (pozicijaM.x >= igrac1.oblik.getPosition().x - metak.oblik.getSize().x))
            //  {
            //      std::cout << "Nigga!" << std::endl;
             // }
              // std::cout << igrac1.oblik.getPosition().y << std::endl;


          //   std::cout << igrac2.brzina.y << std::endl;
        tekst1.setString(std::to_string(i1));
        tekst2.setString(std::to_string(i2));



        sf::FloatRect nigga = tekst1.getLocalBounds();
        tekst1.setPosition(sf::Vector2f(750 - nigga.getSize().x - 20, 0));

       muzika.setPitch(pic);
       muzika.setVolume(vol);

       std::cout << glasnoca << std::endl;




        //-----------------------UPDATE-------------------------------//

        //-----------------------DRAW--------------------------------//
        prozorcic.clear(sf::Color::Black);
        prozorcic.draw(igrac1.oblik);
        prozorcic.draw(igrac2.oblik);
        mreza.setPosition(748, 0);
        prozorcic.draw(mreza);
        //metak.setPosition((pozicijaMetka), 400);
        prozorcic.draw(metak.oblik);
        // prozorcic.draw(metko.oblik);
        prozorcic.draw(tekst1);
        prozorcic.draw(tekst2);
        prozorcic.display();
        //-----------------------DRAW--------------------------------//
    }
    delete x;
    return 0;
}
