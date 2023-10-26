#include "level.h"

level::level(float width1 ,float hight1)
{
    if(!font2.loadFromFile("minya-nouvelle-bd-it.ttf")){}
    //play
    text2[0].setFont(font2);
    text2[0].setColor(sf::Color::Green);
    text2[0].setString(". Easy");
    text2[0].setCharacterSize(120);
    text2[0].setPosition(sf::Vector2f(50,200));
     //option
     text2[1].setFont(font2);
    text2[1].setColor(sf::Color::White);
    text2[1].setString(". Medium");
    text2[1].setCharacterSize(120);
    text2[1].setPosition(sf::Vector2f(50,400));
    //exit
    text2[2].setFont(font2);
    text2[2].setColor(sf::Color::White);
    text2[2].setString(". Hard");
    text2[2].setCharacterSize(120);
    text2[2].setPosition(sf::Vector2f(50,600));
    mainlevelselected =0;


}

level::~level()
{
    //dtor
}

void level::draw(sf::RenderWindow & window)
{
    for(int p=0;p<3;p++)
    {
        window.draw(text2[p]);
    }
}
//move Down
void level::movedown()
{
    if(mainlevelselected +1 <= max_num2)
    {
        text2[mainlevelselected].setColor(sf::Color::White);
        mainlevelselected++;

        if(mainlevelselected==3)
        {
            mainlevelselected=0;
        }
        text2[mainlevelselected].setColor(sf::Color::Green);
    }
}
//move up
void level::moveup()
{
    if(mainlevelselected -1 >=-1)
    {
        text2[mainlevelselected].setColor(sf::Color::White);
        mainlevelselected--;
        if(mainlevelselected==-1)
        {
            mainlevelselected=2;
        }
        text2[mainlevelselected].setColor(sf::Color::Green);
    }
}
