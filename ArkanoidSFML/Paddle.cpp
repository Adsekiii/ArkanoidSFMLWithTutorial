#include "Paddle.h"

Paddle::Paddle(sf::Vector2f pos, sf::Color col) {
	this->paddle.setSize({ this->paddleWidth,this->paddleHeight });
	this->paddle.setOrigin({ this->paddle.getPosition().x + this->paddleWidth / 2,this->paddle.getPosition().y + this->paddleHeight / 2 });
	this->paddle.setPosition(pos);
	this->paddle.setFillColor(col);

	this->paddleVelocity = {0, 0};

}
void Paddle::updatePaddle(float dt) {
	this->movePaddle();
	this->paddle.setPosition({ this->paddle.getPosition().x + this->paddleVelocity.x * this->paddleSpeed * dt,
							   this->paddle.getPosition().y + this->paddleVelocity.y * this->paddleSpeed * dt });


}
void Paddle::movePaddle() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->leftSide() > 0) {
		this->paddleVelocity.x = -1;
	} 
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->rightSide() < windowWidth) 
	{
		this->paddleVelocity.x = 1;
	}
	else 
	{
		this->paddleVelocity.x = 0;
	}
}
float Paddle::leftSide() {
	return this->paddle.getPosition().x - this->paddleWidth / 2;
}
float Paddle::rightSide() {
	return this->paddle.getPosition().x + this->paddleWidth / 2;
}
float Paddle::topSide() {
	return this->paddle.getPosition().y - this->paddleHeight / 2;
}
float Paddle::bottomSide() {
	return this->paddle.getPosition().y + this->paddleHeight / 2;
}

