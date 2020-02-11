#pragma once
#ifndef __Enemy__
#define __Enemy__

#include "GameObject.h"
#include "TextureManager.h"
#include "Level.h"

#include <string>

using namespace std;

class Enemy : public GameObject
{
private:
	int m_enemyHealth;
	string m_enemyName;
	int m_enemyAtkDmg;
	bool m_enemyDeath;

	void m_checkState();
	void m_checkBounds();

	void m_reset();
	void m_checkArrival();

	// steering behaviours
	void m_seek();
	float m_maxSpeed;
	double m_currentDirection;
	float m_turnSpeed;
	float m_steerForce;
	glm::vec2 m_target;
public:
	Enemy();
	~Enemy();

	Level levelSelect;
	array_type* levelPtr;
	array_type levelArray;

	// Inherited via GameObject
	void draw() override;

	void update() override;

	void clean() override;

	void turnRight();
	void turnLeft();
	void m_move();

	//getters
	glm::vec2 getTarget();
	float getMaxSpeed();

	int getEnemyHealth();
	string getEnemyName();
	int getEnemyAtkDmg();
	bool getEnemyDeath();

	//setters
	void setTarget(glm::vec2 newTarget);
	void setMaxSpeed(float newMaxSpeed);

	void setEnemyHealth(int);
	void setEnemyName(string);
	void setEnemyAtkDmg(int);
	void setEnemyDeath(bool);

};
#endif // defined (__Enemy__)
