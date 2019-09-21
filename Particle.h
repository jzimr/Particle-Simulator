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
	Particle(float speed, sf::Vector2f direction, sf::Shape* shape);

private:
	Particle();
	void	draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	float mSpeed;
	sf::Vector2f mDirection;
	sf::Vector2f mLocalPosition;

	sf::Shape* mShape; // move outside

	Particle*						mParent;
	std::vector<Particle*>			mChildren;
};