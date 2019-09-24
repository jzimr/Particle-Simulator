#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ParticleType : sf::Drawable
{
public:
	enum ShapeType
	{
		Square,
		Circle,
		SHAPE_COUNT
	};

public:
	ParticleType(ShapeType shapeType, int size, sf::Texture& texture);
	bool isEqualTo(ShapeType shapeType, int size, sf::Texture& texture);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
private:
	friend class Particle;		// share private data only with Particle class
	ShapeType mShapeType;
	sf::Shape* mShape;
};