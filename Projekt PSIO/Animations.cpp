#include "Animations.h"

Animations::Animations(sf::Sprite& sprite_, sf::Texture& texture_, int maxFrame_, float maxTime_,
	sf::IntRect firstFrame_, int priority_, int rectStep_)
	: sprite(sprite_), texture(texture_), maxFrame(maxFrame_), maxFrameTime(maxTime_),
	firstFrame(firstFrame_), priority(priority_), rectStep(rectStep_)
{
	this->currentFrame = firstFrame_;
	this->frameCounter = 0;
	this->animationTime = 0;
}
Animations::~Animations()
{
}
void Animations::makeAnimation(const float& dt)
{
	this->animationTime += 100.f * dt;
	if (this->animationTime >= this->maxFrameTime)
	{
		this->frameCounter++;
		if (this->frameCounter >= this->maxFrame)
		{
			this->frameCounter = 0;
			this->currentFrame = this->firstFrame;
		}
		else
		{
			this->currentFrame.left += this->rectStep;
		}
		this->sprite.setTextureRect(this->currentFrame);
		this->animationTime = 0;
	}
}

bool Animations::isDone() const
{
	return this->frameCounter >= this->maxFrame;
}

int Animations::getPriority() const
{
	return this->priority;
}