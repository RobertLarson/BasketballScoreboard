/*
 * BasketballScoreboardTeam.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#include "BasketballScoreboardTeam.h"

#include "BasketballScoreboardTeamObserver.h"

#include <iostream>

BasketballScoreboardTeam::BasketballScoreboardTeam(std::string name)
: m_name(name)
{
}

BasketballScoreboardTeam::~BasketballScoreboardTeam() {
}

void BasketballScoreboardTeam::Subscribe(BasketballScoreboardTeamObserver * observer)
{
	m_observers.push_back(observer);
}

void BasketballScoreboardTeam::Unsubscribe(BasketballScoreboardTeamObserver * observer)
{
	std::vector<BasketballScoreboardTeamObserver*>::iterator iter;

	for(iter = m_observers.begin(); iter != m_observers.end(); iter++)
	{
		if(observer == *iter)
		{
			m_observers.erase(iter);
			break;
		}
	}
}

void BasketballScoreboardTeam::Notify()
{
	std::vector<BasketballScoreboardTeamObserver*>::iterator iter;

	for(iter = m_observers.begin(); iter != m_observers.end(); iter++)
	{
		BasketballScoreboardTeamObserver* observer = *iter;

		observer->TeamUpdate();
	}
}


void BasketballScoreboardTeam::FreeThrowMade()
{
	std::cout << GetName() << " : free throw made                |  ";
	ScoringUpdate(1);
}


void BasketballScoreboardTeam::WaiveOffFreeThrow()
{
	std::cout << GetName() << " : free throw waived off          |  ";
	ScoringUpdate(-1);
}

void BasketballScoreboardTeam::TwoPointFieldGoalMade()
{
	std::cout << GetName() << " : 2 point field goal made        |  ";
	ScoringUpdate(2);
}

void BasketballScoreboardTeam::WaiveOffTwoPointFieldGoalMade()
{
	std::cout << GetName() << " : 2 point field goal waived off  |  ";
	ScoringUpdate(-2);
}

void BasketballScoreboardTeam::ThreePointFieldGoalMade()
{
	std::cout << GetName() << " : 3 point field goal made        |  ";
	ScoringUpdate(3);
}

void BasketballScoreboardTeam::WaiveOffThreePointFieldGoalMade()
{
	std::cout << GetName() << " : 3 point field goal waived off  |  ";
	ScoringUpdate(-3);
}

void BasketballScoreboardTeam::Display()
{
	std::cout << m_name << " : " << m_score << "\n";

}

void BasketballScoreboardTeam::ScoringUpdate(int additionalPoints)
{
	m_score += additionalPoints;

	if(m_score < 0)
	{
		m_score = 0;
	}

	Notify();
}
