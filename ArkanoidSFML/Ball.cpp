#include "ball.h"

Ball::Ball(sf::Vector2f pos, sf::Color col) {
	this->ball.setSize({ this->ballWidth,this->ballHeight });
	this->ball.setOrigin({ this->ball.getPosition().x + this->ballWidth / 2,this->ball.getPosition().y + this->ballHeight / 2 });
	this->ball.setPosition(pos);
	this->ball.setFillColor(col);

	this->velocity = { -1, -1 };

}
void Ball::updateBall(float dt) {
	this->moveBall();
	this->ball.setPosition({ this->ball.getPosition().x + this->velocity.x * this->ballSpeed * dt,
							 this->ball.getPosition().y + this->velocity.y * this->ballSpeed * dt });


}
void Ball::moveBall() 
{
	if (this->leftSide() <= 0) {
		this->velocity.x = this->ballVelocity;
	}
	if (this->rightSide() >= windowWidth) {
		this->velocity.x = -this->ballVelocity;
	}
	if (this->topSide() <= 0) {
		this->velocity.y = this->ballVelocity;
	}
	if (this->bottomSide() >= windowHeight) {
		this->velocity.y = -this->ballVelocity;
	}

}


float Ball::leftSide() {
	return this->ball.getPosition().x - this->ballWidth / 2;
}
float Ball::rightSide() {
	return this->ball.getPosition().x + this->ballWidth / 2;
}
float Ball::topSide() {
	return this->ball.getPosition().y - this->ballHeight / 2;
}
float Ball::bottomSide() {
	return this->ball.getPosition().y + this->ballHeight / 2;
}

