#pragma once

#include "Vector2D.h"
#include "../Color.h"
#include "../Texture.h"
#include "../IGraphicShape.h"

/**
 * .The possible locations for a shape anchor point.
 */
enum class AnchorPointLocation
{
	TOP_LEFT, TOP_RIGHT,
	BOTTOM_LEFT, BOTTOM_RIGHT,
	CENTER
};

/**
 * .Represents a shape that has a position, a size, a color and a possible texture.
 */
class IShape
{
public:
	
	/**
	 * .Set the anchor point, the (0;0) point on the shape.
	 * 
	 * \param location the anchor point location, BOTTOM_LEFT by default.
	 */
	virtual void setAnchorPoint(const AnchorPointLocation location = AnchorPointLocation::BOTTOM_LEFT) = 0;

	/**
	 * .Set a new position for the shape.
	 * 
	 * \param position the new position of the shape
	 */
	virtual void setPosition(const Vector2D<float>& position) = 0;

	/**
	 * .Set a new position for the shape.
	 *
	 * \param x the new position on the x axis
	 * \param y the new position on the y axis
	 */
	virtual void setPosition(const float x, const float y) = 0;


	/**
	 * .Set a new size for the shape.
	 *
	 * \param size the new size of the shape
	 */
	virtual void setSize(const Vector2D<float>& size) = 0;

	/**
	 * .Set a new size for the shape.
	 *
	 * \param width the new width of the shape
	 * \param width the new height of the shape
	 */
	virtual void setSize(const float width, const float height) = 0;
	
	/**
	 * .Set the rotation of the shape in degree (< 0 -> clockwise && > 0 -> anticlockwise).
	 * 
	 * \param rotation the rotation angle in degree.
	 */
	virtual void setRotation(const float rotation) = 0;


	/**
	 * .Set a new color for the shape.
	 * 
	 * \param color the new color of the shape
	 */
	virtual void setColor(const Color& color) = 0;

	/**
	 * .Set a new texture for the shape.
	 *
	 * \param color the new texture of the shape
	 */
	virtual void setTexture(Texture& texture) = 0;

	
	/**
	 * \return the anchor point, the (0;0) location of the shape.
	 */
	virtual AnchorPointLocation getAnchorPoint() const = 0;

	/**
	 * \return the position of the shape.
	 */
	virtual Vector2D<float> getPosition() const = 0;

	/**
	 * \return the size of the shape.
	 */
	virtual Vector2D<float> getSize() const = 0;

	/**
	 * \return the angle of rotation of the shape in degree.
	 */
	virtual float getRotation() const = 0;


	/**
	 * \return the color of the shape.
	 */
	virtual Color getColor() const = 0;

	/**
	 * \return the texture of the shape.
	 */
	virtual Texture* getTexture() const = 0;
};