#include "ParticleType.h"

ParticleType::ParticleType(ShapeType shapeType, int size, sf::Texture & texture)
{
	if (shapeType == Square)
	{
		mShape = new sf::RectangleShape(sf::Vector2f(size, size));
		mShape->setTexture(&texture);
	}
	else if (shapeType == Circle)
	{
		mShape = new sf::CircleShape(size);
		mShape->setTexture(&texture);
	}
	mShapeType = shapeType;
}

bool ParticleType::isEqualTo(ShapeType shapeType, int size, sf::Texture & texture)
{
	if (shapeType == mShapeType &&
		mShape->getGlobalBounds().width == size &&
		mShape->getTexture() == &texture)
	{
		//std::cout << "I already have this shape in cache, loading...";
		return true;
	}
	return false;
}

void ParticleType::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*mShape, states);
}
