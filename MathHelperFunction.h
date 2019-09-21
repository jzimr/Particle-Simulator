#pragma once
namespace HelperFunc
{
	float getLength(const sf::Vector2f& v)
	{
		return sqrtf(pow(v.x, 2) + pow(v.y, 2));
	}

	sf::Vector2f normalize(const sf::Vector2f& v)
	{
		float vLength = getLength(v);

		return sf::Vector2f(v.x / vLength, v.y / vLength);
	}
}
