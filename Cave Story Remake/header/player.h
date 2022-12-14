#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "globals.h"
#include "slope.h"
#include "door.h"
#include "level.h"

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics &graphics, Vector2 spawnPoint);
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	/* void moveLeft
	 * Moves the player left by -dx
	 */
	void moveLeft();

	/* void moveRight
	 * Moves the player right by dx
	 */
	void moveRight();

	/* void stopMoving
	 * Stops moving the player
	 */
	void stopMoving();

	/* void jump
	 * Starts jumping
	 */

	/* void lookUp
	 * The player looks up
	 */
	void lookUp();

	/* void stopLookingUp
	 * The player stops looking up
	 */
	void stopLookingUp();

	/* void lookDown
	 * The player looks down OR interacts (turns around)
	 */
	void lookDown();

	/* void stopLookingDown
	 * The player stops looking down or interacting
	 */
	void stopLookingDown();

	void jump();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

	void handleTileCollisions(std::vector<Rectangle> &others);
	void handleSlopeCollisions(std::vector<Slope> &others);
	void handleDoorCollision(std::vector<Door> &others, Level &level, Graphics &graphics);

	const float getX() const;
	const float getY() const;

private:
	float _dx, _dy;

	Direction _facing;

	bool _grounded;

	bool _lookingUp = false;
	bool _lookingDown = false;
};

#endif
