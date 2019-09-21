#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Particle : public sf::Transformable, public sf::Drawable, public sf::NonCopyable
{

public:

	void			update(float dt);

	void			setTexture(const sf::Texture& tex);

	void			attachChild(Particle* child, sf::Vector2f offset = sf::Vector2f(0,0));
	//Particle*		detachChild(Particle* child);

protected:
	Particle(int speed, sf::Vector2f direction, sf::Shape* shape);

private:
	Particle();
	void	draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// math helper function to normalize a vector
	sf::Vector2f normalize(const sf::Vector2f & v);


private:
	int mSpeed;
	sf::Vector2f mDirection;
	sf::Vector2f mLocalPosition;

	sf::Shape* mShape; // move outside?

	Particle*						mParent;
	std::vector<Particle*>			mChildren;
};