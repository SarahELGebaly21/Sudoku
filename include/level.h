#ifndef LEVEL_H
#define LEVEL_H
#pragma once
#include<SFML/Graphics.hpp>
#define max_num2 3

class level
{
    public:
        level(float width1,float hight1);
         void draw(sf::RenderWindow & window);
        void moveup();
        void movedown();
        int menupressed()
        {
            return mainlevelselected;
        }
        virtual ~level();

    protected:

    private:
         int mainlevelselected ;

        sf::Font font2;
    sf::Text text2 [max_num2];

};

#endif // MENU_H
