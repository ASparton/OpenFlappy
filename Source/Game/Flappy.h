#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Shapes/Rectangle.h"

/**
 * .Represents flappy, the character played by the player.
 *  Manage jump listening to the space bar input.
 */
class Flappy : public Rectangle {

public:
	Flappy(const float x, const float y, const float width, const float height, Texture& texture, GLFWwindow* window, const float weight = 5.5f);
	Flappy(const Vector2D<float> position, const Vector2D<float> size, Texture& texture, GLFWwindow* window, const float weight = 5.5f);
	~Flappy() = default;

	/**
	 * .Apply a kind of gravity on flappy to make it fall.
	 * 
	 * \param jumpHeightReached true if the jump height has just been reached -> continue to glide before falling straight
	 */
	void applyGravity(const bool jumpHeightReached);

	/**
	 * .Make flappy jump.
	 */
	void jump();

	/**
	 * \return true if flappy is jumping, false otherwise.
	 */
	bool isJumping() const;

	/**
	 * \return true if the player has made the first jump, false otherwise.
	 */
	bool firstJumpDone() const;

private:
	GLFWwindow* m_window;	// Need window to listen to keyboard inputs

	float m_weight;
	bool m_firstJumpDone;

	static const int JUMP_HEIGHT = 50;
	float m_nextJumpHeight;
	int m_jumpAccelerationFactor;

	float m_gravityAccelerationFactor;
	int m_jumpHeightEdgeCount;
};

// Fired when a key is pressed or released on the keyboard
void onKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods);