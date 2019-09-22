#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ParticleState.h"

class Particle : public sf::Transformable, public sf::Drawable, public sf::NonCopyable
{
	/*
	Memento Pattern implementation
	*/
public:
	class Memento
	{
	public:
		Memento(ParticleState state);

	private:
		ParticleState getSavedState();

	private:
		friend class Particle;		// Gives "Particle" class access to private fields
		ParticleState mState;
	};

	Memento saveToMemento();
	void restoreFromMemento(Memento memento);


	/*
	Particle methods/fields
	*/
public:
	int				getId();
	void			update(float dt);

	void			setTexture(const sf::Texture& tex);

	void			attachChild(Particle* child, sf::Vector2f offset = sf::Vector2f(0,0));
	void			setPosition(float x, float y);
	void			setPosition(const sf::Vector2f position);

	int				getWidth();

	~Particle();

protected:
	Particle(int speed, sf::Vector2f direction, sf::Shape* shape);

private:
	Particle();
	void	draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// math helper function to normalize a vector
	sf::Vector2f normalize(const sf::Vector2f & v);


private:
	int mId;
	int mSpeed;
	sf::Vector2f mDirection;
	sf::Vector2f mLocalPosition;

	sf::Shape* mShape;

	Particle*						mParent;
	std::vector<Particle*>			mChildren;

	static int counter;			// IDs for objects
};