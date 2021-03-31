#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <cmath>
using namespace sf;

const int H = 99;
const int W = 102;
bool game = true;
bool death = false;
int gx, gy;

float offset_x = 0, offset_y = 0;

String Map[H] = {
"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t   T   t   t  g",
"g                                                                                                    g",
"g   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t    g",
"g                                                                                                    g",
"g t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t  g",
"g                                                                                                    g",
"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg",

};

void random_pumpkin_generate() // generates 5 pumpkins at the beginning of a game
{
	int rand_x = 0;
	int rand_y = 0;
	srand(time(0));
	int count = 7;

	while (count > 0)
	{
		rand_x = 1 + rand()%(W - 1);
		rand_y = 1 + rand()%(H - 1);

		if (Map[rand_y][rand_x]==' ')
		{
			Map[rand_y][rand_x] = 'p';
			count--;
		}
	}


}

void random_main_grave_generate() // generates a finish spot
{
	int rand_x = 0;
	int rand_y = 0;

	rand_x = 1 + rand()%(W-1);
	rand_y = 1 + rand()%(H-1);

	if (Map[rand_y][rand_x]=='t' || Map[rand_y][rand_x]=='T')
	{
		Map[rand_y][rand_x] = 'G';
		gx = rand_x;
		gy = rand_y;
	}
	else 
		random_main_grave_generate();
}

void random_mouse_generate() // generates an amount of enemies per few seconds (remove and make an ai for bots)
{
	int rand_x = 0;
	int rand_y = 0;

	rand_x = 1 + rand()%(W - 1);
	rand_y = 1 + rand()%(H - 1);

	if (Map[rand_y][rand_x]==' ')
	{
		Map[rand_y][rand_x] = 'm';
	}
}

class ghost {

public:

float dx, dy;
FloatRect rect;
Sprite sprite;
	ghost(Texture &image)
	{
		sprite.setTexture(image);
		rect = FloatRect(160,160,32,32);
		dx=dy=0;
	}

void update(float time)
{
	rect.left += dx * time;

	collision(0);

	rect.top += dy * time;

	collision(1);

	sprite.setPosition(rect.left - offset_x, rect.top - offset_y);
	
	dx = 0;
	dy = 0;
}

void collision(int dir)
{
	for (int i=rect.top/32; i<(rect.top + rect.height)/32; i++)
	{
		for (int j = rect.left/32; j < (rect.left + rect.width)/32; j++)
		{
			if (Map[i][j]=='g' || Map[i][j]=='t' || Map[i][j]=='T')
			{
				if ((dx>0) && (dir==0)) rect.left = j*32 - rect.width;
				if ((dx<0) && (dir==0)) rect.left = j*32 + 32;
				if ((dy>0) && (dir==1)) rect.top = i*32 - rect.height;
				if ((dy<0) && (dir==1)) rect.top = i*32 + 32;
			}

			else if (Map[i][j]=='p')
			{
				if (abs(gx-j) > abs(gy-i))
				{
					if (gx>j)
						Map[i][j] = 'r';
					else
						Map[i][j] = 'l';
				}

				else
				{
					if (gy>i)
						Map[i][j] = 'd';
					else
						Map[i][j] = 'u';
				}  
			}

			else if (Map[i][j]=='G')
			{
				game = false;
			}
			else if (Map[i][j]=='m')
			{
				death = true;
			}
		}
	}
}
};


int main()
{
	random_main_grave_generate();
	random_pumpkin_generate();

	sf::RenderWindow window( sf::VideoMode(400, 400), "if you have ghosts, you have everything");
	
	Font font;
	font.loadFromFile("18839.otf");
	Text text ("", font, 25);
	text.setFillColor(Color::Red);

	Texture t;
	t.loadFromFile("main.png");

	Texture tumb;
	tumb.loadFromFile("grave1.png");

	Sprite stumb;
	stumb.setTexture(tumb);

	Texture Tumb;
	Tumb.loadFromFile("grave2.png");

	Sprite sTumb;
	sTumb.setTexture(Tumb);

	Texture gate;
	gate.loadFromFile("gate.png");

	Sprite sgate;
	sgate.setTexture(gate);

	Texture road;
	road.loadFromFile("road.png");

	Sprite sroad;
	sroad.setTexture(road);

	Texture pumpkin;
	pumpkin.loadFromFile("pumpkin.png");

	Sprite spumpkin;
	spumpkin.setTexture(pumpkin);

	Texture mgrave;
	mgrave.loadFromFile("mgrave.png");

	Sprite smgrave;
	smgrave.setTexture(mgrave);
	
	Texture left;
	left.loadFromFile("left.png");

	Sprite sleft;
	sleft.setTexture(left);

	Texture right;
	right.loadFromFile("right.png");

	Sprite sright;
	sright.setTexture(right);

	Texture up;
	up.loadFromFile("up.png");

	Sprite sup;
	sup.setTexture(up);

	Texture down;
	down.loadFromFile("down.png");

	Sprite sdown;
	sdown.setTexture(down);

	Sprite s;
	s.setTexture(t);

	s.setPosition(50,100);

	Texture mouse;
	mouse.loadFromFile("mmm.png");

	Sprite s1;
	s1.setTexture(mouse);
	
	ghost g(t);

	Music music;
	if (!music.openFromFile("C.ogg"))
		return -1;
	music.play();

	Clock clock;

	RectangleShape rectangle(sf::Vector2f(32.f, 32.f));
	
	while(window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		
		time = time/400;

		int random = rand()%(101);

		if (random % 43 == 0 && game)
			random_mouse_generate();
	
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{	
				window.close();
			}
		}
		
		if (game)
		{	
			if (Keyboard::isKeyPressed(Keyboard::Left) && game)
			{
				g.dx = - 0.1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right) && game)
			{
				g.dx = 0.1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Up) && game)
			{
				g.dy = -0.1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down) && game)
			{
				g.dy = 0.1;
			}
		
			g.update(time);
	
			offset_x = g.rect.left - 200;
			offset_y = g.rect.top - 200;
	
			window.clear();
			
			for (int i = 0; i<H; i++)
				for (int j = 0; j<W; j++)
				{
					if (Map[i][j]=='g')
					{
						sgate.setPosition(j*32 - offset_x, i*32 - offset_y);
						window.draw(sgate);
					};
					if (Map[i][j]=='t')
					{
						stumb.setPosition(j*32 - offset_x, i*32 - offset_y);
						window.draw(stumb);
					}
					if (Map[i][j]=='p')
					{
						spumpkin.setPosition(j*32 - offset_x, i*32 - offset_y);
						window.draw(spumpkin);
					}
					if (Map[i][j]=='T')
					{
						sTumb.setPosition(j*32 - offset_x, i*32 - offset_y);
						window.draw(sTumb);
					}
					if (Map[i][j]==' ')
					{
						sroad.setPosition(j*32 - offset_x, i*32 - offset_y);
						window.draw(sroad);
					}
					if (Map[i][j]=='G')
					{
						smgrave.setPosition(j*32 - offset_x, i*32 - offset_y);
						window.draw(smgrave);
					}
					if (Map[i][j]=='l')
					{
						sleft.setPosition(j*32 - offset_x, i*32 - offset_y);
						window.draw(sleft);
					}
					if (Map[i][j]=='r')
					{
						sright.setPosition(j*32 - offset_x, i*32 - offset_y);
						window.draw(sright);
					}
					if (Map[i][j]=='u')
					{
						sup.setPosition(j*32 - offset_x, i*32 - offset_y);
						window.draw(sup);
					}
					if (Map[i][j]=='d')
					{
						sdown.setPosition(j*32 - offset_x, i*32 - offset_y);
						window.draw(sdown);
					}
					if (Map[i][j]=='m')
					{
						s1.setPosition(j*32 - offset_x, i*32 - offset_y);
						window.draw(s1);
					}
				}
			window.draw(g.sprite);

			if (!game && !death)
			{
				text.setString("Welcome to the gRAVE party!");
				text.setPosition(50, 100);
				window.draw(text);
			}
			else if (game && death)
			{
				g.sprite.setColor(Color::Red);
				text.setString("Game Over");
				text.setPosition(150, 100);
				game = false;
				window.draw(text);
			}
			window.display();
		}
	}

	return 0;
}

