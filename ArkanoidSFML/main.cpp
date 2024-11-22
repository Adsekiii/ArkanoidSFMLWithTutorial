#include "Main.h"

int main() {
	sf::RenderWindow  window({windowWidth,windowHeight}, "Arkanoid");
	sf::Clock clock;
	sf::Time dt;

	constexpr int countBlocksX{ 8 };
	constexpr int countBlocksY{ 4 };

	Paddle player({windowWidth/2,windowHeight-50}, sf::Color::Red);
	Ball ball({ windowWidth / 2,windowHeight - 100 }, sf::Color::Blue);

	std::vector<Brick> bricks;

	for (int iX{ 0 }; iX < countBlocksX; ++iX) {
		for (int iY{ 0 }; iY < countBlocksY; ++iY) {
			bricks.emplace_back(sf::Vector2f((iX + 1) * (brickWidth + 50) - 50, (iY + 2) * (brickHeight + 30)));
		}
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		dt = clock.restart();

		///////////////////////

		player.updatePaddle(dt.asSeconds());
		ball.updateBall(dt.asSeconds());
		collisionHandling(player,ball);
		for (auto& brick : bricks) collisionHandling(brick, ball);

		bricks.erase(std::remove_if(std::begin(bricks), std::end(bricks), [](const Brick& mBrick) {return mBrick.isDestroyed; }), std::end(bricks));
		///////////////////////

		window.clear();
		window.draw(player.paddle);
		window.draw(ball.ball);
		for (auto& brick : bricks) window.draw(brick.brick);
		window.display();
	}

	return EXIT_SUCCESS;
}


void collisionHandling(Paddle& paddle, Ball& ball)
{
	if (!areIntersecting(paddle, ball)) {  return; }
	ball.velocity.y = -ball.ballVelocity;
}

void collisionHandling(Brick& brick, Ball& ball)
{
	if (!areIntersecting(brick, ball)) { return; }
	float overlapLeft{ball.rightSide() - brick.leftSide()};
	float overlapRight{ brick.rightSide() - ball.leftSide()};
	float overlapBottom{ brick.bottomSide() - ball.topSide() };
	float overlapTop{ ball.bottomSide() - brick.topSide() };

	bool hitLeft(abs(overlapLeft) < abs(overlapRight));
	bool hitTop(abs(overlapTop) < abs(overlapBottom));

	float minimalOverlapX{hitLeft ? overlapLeft: overlapRight};
	float minimalOverlapY{ hitTop ? overlapTop : overlapBottom };

	brick.isDestroyed = true;

	if (abs(minimalOverlapX) < abs(minimalOverlapY)) 
	{
		ball.velocity.x = hitLeft ? -ball.ballVelocity : ball.ballVelocity;
	}
	else
	{
		ball.velocity.y = hitTop ? -ball.ballVelocity : ball.ballVelocity;

	}
}



template<class T1, class T2> bool areIntersecting(T1& A, T2& B) {
	return (A.rightSide() >= B.leftSide() && A.leftSide() <= B.rightSide() && A.topSide() <= B.bottomSide() && A.bottomSide() >= B.topSide());
}