#pragma once

#include "IShape.h"

/**
 * .Represents a rectangle that has :
 *		- a position
 *		- a size
 *		- a color (white by default)
 *		- a texture (not mandatory)
 */
class Rectangle : public IShape
{
public:

	#pragma region Constructors using Vector2D

	Rectangle(const Vector2D<float>& position, const Vector2D<float>& size, 
		const AnchorPointLocation location = AnchorPointLocation::BOTTOM_LEFT);
	Rectangle(const Vector2D<float>& position, const Vector2D<float>& size, const Color& color, 
		const AnchorPointLocation location = AnchorPointLocation::BOTTOM_LEFT);
	Rectangle(const Vector2D<float>& position, const Vector2D<float>& size, Texture& texture, 
		const AnchorPointLocation location = AnchorPointLocation::BOTTOM_LEFT);
	Rectangle(const Vector2D<float>& position, const Vector2D<float>& size, const Color& color, Texture& texture, 
		const AnchorPointLocation location = AnchorPointLocation::BOTTOM_LEFT);

	#pragma endregion
	#pragma region Constructors using floats

	Rectangle(const float x, const float y, const float width, const float height, 
		const AnchorPointLocation location = AnchorPointLocation::BOTTOM_LEFT);
	Rectangle(const float x, const float y, const float width, const float height, const Color& color, 
		const AnchorPointLocation location = AnchorPointLocation::BOTTOM_LEFT);
	Rectangle(const float x, const float y, const float width, const float height, Texture& texture, 
		const AnchorPointLocation location = AnchorPointLocation::BOTTOM_LEFT);
	Rectangle(const float x, const float y, const float width, const float height, const Color& color, Texture& texture, 
		const AnchorPointLocation location = AnchorPointLocation::BOTTOM_LEFT);

	#pragma endregion
	~Rectangle() = default;

	/**
	 * .Determine wether the given rectangle is colliding with this rectangle.
	 *
	 * \param rectangle the other rectangle
	 * \return true if the given rectangle is colliding with this rectangle, false otherwise
	 */
	bool isColliding(const Rectangle& rectangle) const;

	// Setters
	void setAnchorPoint(const AnchorPointLocation location = AnchorPointLocation::BOTTOM_LEFT) final;
	void setPosition(const Vector2D<float>& position) final;
	void setPosition(const float x, const float y) final;
	void setSize(const Vector2D<float>& size) final;
	void setSize(const float width, const float height) final;
	void setRotation(const float rotation) final;

	void setColor(const Color& color) final;
	void setTexture(Texture& texture) final;

	// Getters
	AnchorPointLocation getAnchorPoint() const final;
	Vector2D<float> getPosition() const final;
	Vector2D<float> getSize() const final;
	float getRotation() const final;

	Color getColor() const final;
	Texture* getTexture() const final;

protected:
	AnchorPointLocation m_anchorPoint;
	Vector2D<float> m_position;
	Vector2D<float> m_size;
	float m_rotation;

	Color m_color;
	Texture* m_texture;
};