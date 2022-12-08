#pragma once
#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "sprite.h"
#include "globals.h"
#include <vector>
#include <map>
#include <string>

class Graphics;

// holds the code for animating all sprites

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();

	AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
		float posX, float posY, float timeToUpdate);
	
	//play the animation if the animation isn't already playing
	void playAnimation(std::string animation, bool once = false);
	
	//updates the animated sprite timer
	void update(int elapsedTime);
	
	//draws the sprite to the screen
	void draw(Graphics &graphics, int x, int y);

	

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	//add the animation to the map of animations sprite
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);
	
	//reset all animations associated with a sprite
	void resetAnimations();

	//stops the current animation
	void stopAnimation();

	//changes animation
	void setVisible(bool visible);

	//logic for anything happens is finished
	virtual void animationDone(std::string currentAnimation) = 0;

	//required function that sets all sprite animations
	virtual void setupAnimations() = 0;

private:

	std::map<std::string, std::vector<SDL_Rect>> _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed = 0;
	bool _visible;
};

#endif // !ANIMATED_SPRITE_H
