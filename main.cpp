#include <SFML/Graphics.hpp>
#include <iostream>
#include<sstream>
#include<ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include "menu.h"
#include"level.h"
using namespace std;
using namespace sf;
int pagenum ;
int pagenum1;
int con;
int winner;
int lose=0;
int again;
int w=48;
void main_menu(RenderWindow &window,Font &font1, Text &textm, Sprite &sprite1)
{

    menu menu1(1200,900);
    while (window.isOpen())
    {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        int x = pos.x /w ;
        int y= pos.y /w  ;
        sf::Event click;
        while(window.pollEvent(click))
        {
            if (click.type == sf::Event::Closed)
            {
                window.close();
            }
            if (click.type ==sf::Event::KeyReleased)
            {
                if(click.key.code ==sf::Keyboard::Up)
                {
                    menu1.moveup();
                    break;
                }
                if(click.key.code==sf::Keyboard::Down)
                {
                    menu1.movedown();
                    break;
                }
                if(click.key.code==sf::Keyboard::Return)
                {

                    if(menu1.menupressed()==0)
                    {
                        window.close();
                        pagenum=0;
                    }

                    if(menu1.menupressed()==1)
                    {
                        window.close();
                        pagenum=1;
                    }


                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(sprite1);
        window.draw(textm);
        menu1.draw(window);
        window.display();

    }
}

void play_menu(RenderWindow &window,Font &font1,Sprite &sprite1,Text &textm)
{
    lose = 0;
    //con = -1;
    winner = -1;
    srand(time(0));
    int ww=0,ddd,ff,arrt[81],arr2 [con],su[9][9]= {0},ii,m,ss[9][9],s,n,d,b,arr3[9][9]= {},tt,r,arr3copy[9][9],e,pp;
    string line;
    vector<string> lines;
    ifstream file("mytext.txt");
    int total_lines=0;
    int a;

    while(getline(file,line))
    {
        total_lines++;
        lines.push_back(line);
    }
    int t1,rr;
    int random_number=rand()%total_lines;
    cout <<lines[random_number];
    cout<<endl;
    char cstr[lines[random_number].size() +1];
    copy(lines[random_number].begin(),lines[random_number].end(),cstr);
    cstr[lines[random_number].size()]='\0';


    int arr[81];
    for( a=0; a<81; a++)
    {
        arrt[a]=cstr[a];
    }
    cout<<endl;

    a=0;
    int arr1[9][9];
    for( r=0; r<9; r++)
    {
        for(t1=0; t1<9; t1++)
        {
            arr1[r][t1]= arrt[a];
            if(arr1[r][t1]>10 &&arr1[r][t1]!=0)
                arr1[r][t1]=(arr1[r][t1]-48);


            cout<<arr1[r][t1];
            a++;
        }
        cout<<endl;
    }
    int arr11 [con] ;
    for( ii=0; ii<con; ii++)
    {
        arr11[ii] = rand()%8+0 ;
        cout<<arr11[ii]<<"  ";
    }
    cout<<endl;
    for( m=0; m<con; m++)
    {
        arr2[m] = rand()%8+0 ;
        cout<<arr2[m]<<"  ";
    }
    ii=0;
    m=0;
    cout<<endl;
    while(ii<con &&m<con)
    {
        r=arr11[ii];
        t1=arr2[m];
        cout<<arr1[r][t1]<<endl;
        ii++;
        m++;
    }
    ii=0;
    m=0;
    while(ii<con&&m<con)
    {
        r=arr11[ii];
        t1=arr2[m];
        rr=arr11[ii];
        tt=arr2[m];
        arr3[rr][tt]=arr1[r][t1];
        ii++;
        m++;
    }
    for(rr=0; rr<9; rr++)
    {
        for(tt=0; tt<9; tt++)
        {
            cout<<arr3[rr][tt];
        }
        cout<<endl;
    }
    rr=0;
    tt=0;
    for(e=0; e<9; e++)
    {
        for(pp=0; pp<9; pp++)
        {
            arr3copy[e][pp]=arr3[e][pp];

            cout<<arr3copy[e][pp];

        }

        cout<<endl;
    }


    ofstream file_;
    file_.open("mytext.txt");
    file_<<"534678912672195348198342567859761423426853791713924856961537284287419635345286179"<<endl;
    file_<<"532986741487215369691437582325174896764398125819562437156823974978641253243759618"<<endl;
    file_<<"812753649943682175675491283154237896369845721287169534521974368438526917796318452"<<endl;
    file_.close();
    sf::RenderWindow window_play (sf::VideoMode(900,900),"SUDOKU GAME",sf::Style::Close);
    float w =70;
    char key;
    int i,j,aaa,z, v,l;
    bool dd=0;
    sf::Texture t;
    t.loadFromFile("tbconsudokusamplefigure0213.GIF");
    sf::Sprite spr (t);
    spr.setTexture(t);
    sf::Texture tt1;
    tt1.loadFromFile("_Cut_1588220347330.PNG");
    sf::Sprite spr1 (tt1);
    spr1.setTexture(tt1);

    sf::Texture tt2;
    tt2.loadFromFile("_Cut_1588220347330 - Copy.PNG");
    sf::Sprite spr2 (tt2);
    spr2.setTexture(tt2);


    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text ;
    text.setFont(font);
    text.setCharacterSize(55);

    while (window_play.isOpen())
    {
        sf::Vector2i pos = sf::Mouse::getPosition(window_play);
        int x = pos.x /w ;
        int y= pos.y /w  ;
        sf::Event event;
        while(window_play.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_play.close();
            }
            window_play.clear();
            window_play.draw(sprite1);
            textm.setString("SUDOKU GAME");
            textm.setCharacterSize(80);
            textm.setPosition(sf::Vector2f(200,50));


            for( i=0; i<9; i++)
            {
                for(j=0; j<9; j++)
                {
                    spr.setTextureRect( sf::IntRect (0,0,w,w));
                    spr.setPosition(sf::Vector2f((i+2)*w,(j+2)*w));
                    window_play.draw(spr);
                }
            }
            for(i=0; i<2; i++)
            {
                int x3=5;
                if(i==1)
                    x3=x3+3;


                spr1.setPosition(sf::Vector2f(x3*w,140));

                window_play.draw(spr1);


            }
            for(i=0; i<2; i++)
            {
                int x4=5;
                if(i==1)
                    x4=x4+3;


                spr2.setPosition(sf::Vector2f(140,x4*w));

                window_play.draw(spr2);


            }

        }
        for( z=0; z<9; z++)
        {
            for( aaa=0; aaa<9; aaa++)
            {
                // Event eventCheck;
                while (window_play.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
            {
                window_play.close();
            }
                    sf::Vector2i pos = sf::Mouse::getPosition(window_play);
                    int x2 = pos.x ;
                    int y2= pos.y   ;
                    if(x2>140&&x2<770&&y2>140&&y2<770)
                    {
                        if(event.type==sf::Event::TextEntered)
                        {
                            if(event.text.unicode >=49 &&event.text.unicode<=57 )
                            {
                                key = (int)event.text.unicode;
                                dd=1;
                                v= pos.x/w;
                                l= pos.y/w;
                                if(arr3copy[l-2][v-2]==0)
                                {
                                    arr3[l-2][v-2]=key;
                                }
                                if(arr3[l-2][v-2]-48 != arr1[l-2][v-2] && arr3copy[l-2][v-2]==0)
                                {
                                    cout<<"error";
                                    lose++;
                                }
                                if(lose==3)
                                {
                                    window_play.close();
                                    winner=2;
                                }
                            }

                        }
                    }
                }
            }



            for( rr=0; rr<9; rr++)
            {
                for( tt=0; tt<9; tt++)
                {
                    if (arr3[rr][tt] !=0  )
                    {
                        su[rr][tt]=arr3[rr][tt];


                        string str=to_string(su[rr][tt]);
                        if(str=="49")
                        {
                            str="1";
                        }
                        else if(str=="50")
                        {
                            str="2";
                        }
                        else if(str=="51")
                        {
                            str="3";
                        }
                        else if(str=="52")
                        {
                            str="4";
                        }
                        else if(str=="53")
                        {
                            str="5";
                        }
                        else if(str=="54")
                        {
                            str="6";
                        }
                        else if(str=="55")
                        {
                            str="7";
                        }
                        else if(str=="56")
                        {
                            str="8";
                        }
                        else if(str=="57")
                        {
                            str="9";
                        }



                        text.setString(str);
                        if(su[rr][tt]>40 )
                        {
                            text.setColor(sf::Color::Black);
                        }
                        if(su[rr][tt]<10)
                        {
                            text.setColor(sf::Color::Red);
                        }

                        text.setPosition(sf::Vector2f( (tt+2)*(w+2),(rr+2)*w));
                        window_play.draw(text);
                    }



                }
            }

            if(dd==1)
            {
                for(int rr=0; rr<9; rr++)
                {
                    for(int tt=0; tt<9; tt++)
                    {
                        if(su[rr][tt]>10 &&su[rr][tt]!=0 )
                            su[rr][tt]=(su[rr][tt]-48);
//if(arr3copy[l-2][v-2]==0)
                        // {
                        //    arr3[l-2][v-2]=key;
                        //}
                        if(rr==arr11[ii] && tt==arr2[m] )
                        {
                            s=arr11[ii];
                            n=arr2[m];
                            ddd=arr11[ii];
                            ff=arr2[m];
                            su[rr][tt]=ss[s][n];
                            cout<<su[rr][tt];
                            ii++;
                            m++;
                        }
                        else
                        {
                            cout<<su[rr][tt]<<" ";
                        }
                    }
                    cout<<endl;

                }
                dd=0;
            }
            if(su[0][0]==arr1[0][0]&&su[0][1]==arr1[0][1]&&su[0][2]==arr1[0][2]&&su[0][3]==arr1[0][3]&&su[0][4]==arr1[0][4]&&su[0][5]==arr1[0][5]&&su[0][6]==arr1[0][6]&&su[0][7]==arr1[0][7]&&su[0][8]==arr1[0][8]&&
                    su[1][0]==arr1[1][0]&&su[1][1]==arr1[1][1]&&su[1][2]==arr1[1][2]&&su[1][3]==arr1[1][3]&&su[1][4]==arr1[1][4]&&su[1][5]==arr1[1][5]&&su[1][6]==arr1[1][6]&&su[1][7]==arr1[1][7]&&su[1][8]==arr1[1][8]&&
                    su[2][0]==arr1[2][0]&&su[2][1]==arr1[2][1]&&su[2][2]==arr1[2][2]&&su[2][3]==arr1[2][3]&&su[2][4]==arr1[2][4]&&su[2][5]==arr1[2][5]&&su[2][6]==arr1[2][6]&&su[2][7]==arr1[2][7]&&su[2][8]==arr1[2][8]&&
                    su[3][0]==arr1[3][0]&&su[3][1]==arr1[3][1]&&su[3][2]==arr1[3][2]&&su[3][3]==arr1[3][3]&&su[3][4]==arr1[3][4]&&su[3][5]==arr1[3][5]&&su[3][6]==arr1[3][6]&&su[3][7]==arr1[3][7]&&su[3][8]==arr1[3][8]&&
                    su[4][0]==arr1[4][0]&&su[4][1]==arr1[4][1]&&su[4][2]==arr1[4][2]&&su[4][3]==arr1[4][3]&&su[4][4]==arr1[4][4]&&su[4][5]==arr1[4][5]&&su[4][6]==arr1[4][6]&&su[4][7]==arr1[4][7]&&su[4][8]==arr1[4][8]&&
                    su[5][0]==arr1[5][0]&&su[5][1]==arr1[5][1]&&su[5][2]==arr1[5][2]&&su[5][3]==arr1[5][3]&&su[5][4]==arr1[5][4]&&su[5][5]==arr1[5][5]&&su[5][6]==arr1[5][6]&&su[5][7]==arr1[5][7]&&su[5][8]==arr1[5][8]&&
                    su[6][0]==arr1[6][0]&&su[6][1]==arr1[6][1]&&su[6][2]==arr1[6][2]&&su[6][3]==arr1[6][3]&&su[6][4]==arr1[6][4]&&su[6][5]==arr1[6][5]&&su[6][6]==arr1[6][6]&&su[6][7]==arr1[6][7]&&su[6][8]==arr1[6][8]&&
                    su[7][0]==arr1[7][0]&&su[7][1]==arr1[7][1]&&su[7][2]==arr1[7][2]&&su[7][3]==arr1[7][3]&&su[7][4]==arr1[7][4]&&su[7][5]==arr1[7][5]&&su[7][6]==arr1[7][6]&&su[7][7]==arr1[7][7]&&su[7][8]==arr1[7][8]&&
                    su[8][0]==arr1[8][0]&&su[8][1]==arr1[8][1]&&su[8][2]==arr1[8][2]&&su[8][3]==arr1[8][3]&&su[8][4]==arr1[8][4]&&su[8][5]==arr1[8][5]&&su[8][6]==arr1[8][6]&&su[8][7]==arr1[8][7]&&su[8][8]==arr1[8][8])
            {
                window_play.close();
                winner=1;
            }

            window_play.draw(text);
            window_play.draw(spr1);
            window_play.display();
            if(winner==1)
            {
                sf::RenderWindow window_play_winner (sf::VideoMode(500,333),"winner",sf::Style::Close);
                sf::Texture win;
                if(!win.loadFromFile("unnamed (1).PNG")) {}
                sf::Sprite winner(win);
                while(window_play_winner.isOpen())
                {
                    sf::Event event;
                    while(window_play_winner.pollEvent(event))
                    {
                        if(event.type==sf::Event::Closed)
                            window_play_winner.close();
                    }
                    window_play_winner.clear(sf::Color::White);
                    window_play_winner.draw(winner);
                    window_play_winner.display();
                }

            }
            if(winner==2)
            {
                sf::RenderWindow window_play_winner (sf::VideoMode(500,333),"loser",sf::Style::Default);
                sf::Texture win;
                if(!win.loadFromFile("unnamed.png")) {}
                sf::Sprite winner(win);
                while(window_play_winner.isOpen())
                {
                    sf::Event event;
                    while(window_play_winner.pollEvent(event))
                    {
                        if(event.type==sf::Event::Closed)
                            window_play_winner.close();
                              if(event.type==sf::Event::KeyReleased)
                        {
                            if(event.key.code==sf::Keyboard::Return)
                            {
                                ///main menu
                            again=1;  //  main_menu(window,font1, textm, sprite1);
                              //  window_play_winner.close();

                            }
                             if(again==1)
            {
                window_play_winner.close();
                main_menu(window,font1, textm, sprite1);


            }
                        }


                    }
                    window_play_winner.clear(sf::Color::White);
                    window_play_winner.draw(winner);
                    window_play_winner.display();

                }




            }
        }

    }

    std::cin.get();
}


int main()
//void menuu(sf::RenderWindow Window,menu menu1(1200,900))
{
    while (true)
    {
        sf::RenderWindow window (sf::VideoMode(900,900),"MENU");
        sf::Font font1;
        font1.loadFromFile("minya-nouvelle-bd-it.ttf");
        sf::Text textm ;
        textm.setFont(font1);
        textm.setCharacterSize(110);
        textm.setPosition(sf::Vector2f(0,100));
        textm.setString("Let's Play Sudoku !");
        textm.setColor(sf::Color::Yellow);

        sf::Texture texture1;
        if(!texture1.loadFromFile("photography-backdrops-Light-coffee-color-wood-wood-brick-wall-backgrounds-for-photo-studio.jpg_640x640q70.JPG"));
        cout<<"error";
        sf::Sprite sprite1(texture1);
        ///main menu
        main_menu(window,font1, textm, sprite1);
        if(pagenum==0)
        {
            level level1(900,900);
            sf::RenderWindow window_level (sf::VideoMode(900,900),"levels");
            sf::Font fontl;
            fontl.loadFromFile("minya-nouvelle-bd-it.ttf");
            sf::Text textl ;
            textl.setFont(fontl);
            textl.setCharacterSize(110);
            textl.setString("Choose Your Level");
            textl.setPosition(sf::Vector2f(0,50));
            textl.setColor(sf::Color::Yellow);

            while (window_level.isOpen())
            {
                sf::Vector2i pos = sf::Mouse::getPosition(window_level);
                int x = pos.x /w ;
                int y= pos.y /w  ;
                sf::Event click;
                while(window_level.pollEvent(click))
                {
                    if (click.type == sf::Event::Closed)
                    {
                        window.close();
                    }
                    if (click.type ==sf::Event::KeyReleased)
                    {
                        if(click.key.code ==sf::Keyboard::Up)
                        {
                            level1.moveup();
                            break;
                        }
                        if(click.key.code==sf::Keyboard::Down)
                        {
                            level1.movedown();
                            break;
                        }
                        if(click.key.code==sf::Keyboard::Return)
                        {

                            if(level1.menupressed()==0 || level1.menupressed()==1||level1.menupressed()==2)
                            {
                                if(level1.menupressed()==0)
                                {
                                    con=65;
                                }
                                if(level1.menupressed()==1)
                                {
                                    con=45;
                                }
                                if(level1.menupressed()==2)
                                {
                                    con=30;
                                }
                                window_level.close();
                                pagenum1=1;

                            }
                        }
                    }
                }
                window_level.clear();
                window_level.draw(sprite1);
                level1.draw(window_level);
                window_level.draw(textl);
                window_level.display();
                if(pagenum1==1)
                {///play
            play_menu(window,font1,sprite1, textm);
        }
}
        }
        if(pagenum==1)
        {//exit
            break;
        }
    }
    return 0;
}
