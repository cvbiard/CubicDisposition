#include "Bomb.h"

Bomb::Bomb()
{
	this->initBomb();
}
Bomb::~Bomb()
{

}
void Bomb::initBomb()
{
	this->explode = false;
	this->dropped = false;
	this->damage = false;
	this->dealt = false;
	this->visual.setSize(Vector2f(playerYSize * 1.4, playerXSize * 1.4));
	this->visual.setOrigin(Vector2f(this->visual.getGlobalBounds().width / 2, this->visual.getGlobalBounds().height / 2));
	this->visual.setFillColor(Color(255, 0, 0, 0));

	this->updateEffects();
}
void Bomb::updateBomb(float dt, int framerate)
{
	if (this->dropped == true)
	{
		this->visual.setPosition(Vector2f(Mouse::getPosition()));
		this->visual.setFillColor(Color(255, 0, 0, 255));
		this->updateEffects();
		this->explode = true;
		this->count = 0;
		this->dropped = false;
	}
	if (this->explode == true)
	{
		
		this->count = this->count + 1;
		
		this->visual.setOrigin(Vector2f(this->visual.getGlobalBounds().width / 2, this->visual.getGlobalBounds().height / 2));
		this->visual.setFillColor(Color(255, (127 + (126 * sin((1.0 / (framerate / 4)) * ((float)this->count)))), (127 + (126 * sin((1.0 / (framerate / 4)) * ((float)this->count)))), this->visual.getFillColor().a));
		this->updateEffects();
		if (this->count > framerate)
		{
			if (this->BombSound.getStatus() != Sound::Playing)
			{
				this->BombSound.play();
			}
			this->damage = true;
			this->visual.setSize(this->visual.getSize() + (Vector2f(3*dt, 3*dt)));
			if (this->visual.getFillColor().a >= 1)
			{
				this->visual.setFillColor(Color(this->visual.getFillColor().r, this->visual.getFillColor().g, this->visual.getFillColor().b, (this->visual.getFillColor().a - (3 * dt))));
			}
			else
			{
				this->visual.setFillColor(Color(this->visual.getFillColor().r, this->visual.getFillColor().g, this->visual.getFillColor().b, 0));
			}
			
			this->visual.setRotation((this->visual.getRotation()+5*dt));

			this->square1.setRotation((this->square1.getRotation() + 5*dt));
			this->square2.setRotation((this->square2.getRotation() + 6*dt));
			this->square3.setRotation((this->square3.getRotation() + 7*dt));
			this->square4.setRotation((this->square4.getRotation() + 10*dt));
			this->updateEffects();
		}
		if (this->count >= framerate *2)
		{
			this->damage = false;
				this->visual.setFillColor(Color(255, 0, 0, 0));
				this->visual.setSize(Vector2f(playerYSize * 1.4, playerXSize * 1.4));
				this->visual.setOrigin(Vector2f(this->visual.getGlobalBounds().width / 2, this->visual.getGlobalBounds().height / 2));
				this->updateEffects();

				this->visual.setRotation(0);
				this->square1.setRotation(0);
				this->square2.setRotation(0);
				this->square3.setRotation(0);
				this->square4.setRotation(0);

				this->dealt = false;
				this->explode = false;
				this->count = 0;
			
			
		}
	}
}
void Bomb::updateEffects()
{

	this->square1.setFillColor(this->visual.getFillColor());
	this->square2.setFillColor(this->visual.getFillColor());
	this->square3.setFillColor(this->visual.getFillColor());
	this->square4.setFillColor(this->visual.getFillColor());

	this->square1.setSize(this->visual.getSize());
	this->square2.setSize(this->visual.getSize());
	this->square3.setSize(this->visual.getSize());
	this->square4.setSize(this->visual.getSize());

	this->square1.setPosition(this->visual.getPosition());
	this->square2.setPosition(this->visual.getPosition());
	this->square3.setPosition(this->visual.getPosition());
	this->square4.setPosition(this->visual.getPosition());


	this->square1.setOrigin(Vector2f(this->square1.getGlobalBounds().width / 2, this->square1.getGlobalBounds().height / 2));
	this->square2.setOrigin(Vector2f(this->square2.getGlobalBounds().width / 2, this->square2.getGlobalBounds().height / 2));
	this->square3.setOrigin(Vector2f(this->square3.getGlobalBounds().width / 2, this->square3.getGlobalBounds().height / 2));
	this->square4.setOrigin(Vector2f(this->square4.getGlobalBounds().width / 2, this->square4.getGlobalBounds().height / 2));

}
