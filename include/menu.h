#ifndef MENU_H
#define MENU_H
#pragma once
#include <SFML/Graphics.hpp>
#define max_num 2
class menu
{
    public:
        menu(float width,float hight);
        void draw(sf::RenderWindow & window);
        void moveup();
        void movedown();
        int menupressed()
        {
            return mainmenuselected;
        }

        virtual ~menu();

    protected:

    private:
        int mainmenuselected ;
        sf::Font font1;
   // font1.loadFromFile("arial - Copy.ttf");
    sf::Text text1 [max_num];
//text1.setFont(font1);
//text1.setCharacterSize(40);
};

#endif // MENU_H
