#include "menu.h"

menu::menu(float width ,float hight)
{
    if(!font1.loadFromFile("minya-nouvelle-bd-it.ttf")){}
    //play
    text1[0].setFont(font1);
    text1[0].setColor(sf::Color::Green);
    text1[0].setString(". Play");
    text1[0].setCharacterSize(120);
    text1[0].setPosition(sf::Vector2f(50,250));
     //option
     text1[1].setFont(font1);
    text1[1].setColor(sf::Color::White);
    text1[1].setString(". Exit");
    text1[1].setCharacterSize(120);
    text1[1].setPosition(sf::Vector2f(50,500));
    //exit

    mainmenuselected =0;

}

menu::~menu()
{
    //dtor
}
//draw
void menu::draw(sf::RenderWindow & window)
{
    for(int p=0;p<2;p++)
    {
        window.draw(text1[p]);
    }
}
//move Down
void menu::movedown()
{
    if(mainmenuselected +1 <= max_num)
    {
        text1[mainmenuselected].setColor(sf::Color::White);
        mainmenuselected++;
        if(mainmenuselected==2)
        {
            mainmenuselected=0;
        }
        text1[mainmenuselected].setColor(sf::Color::Green);
    }
}
//move up
void menu::moveup()
{
    if(mainmenuselected -1 >=-1)
    {
        text1[mainmenuselected].setColor(sf::Color::White);
        mainmenuselected--;
        if(mainmenuselected==-1)
        {
            mainmenuselected=1;
        }
        text1[mainmenuselected].setColor(sf::Color::Green);
    }
}
