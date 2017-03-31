/*
 * BasketballScoreboard.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#include "BasketballScoreboard.h"

#include "BasketballScoreboardTeam.h"

#include <iostream>

BasketballScoreboard::BasketballScoreboard
   (BasketballScoreboardTeam * awayTeam,
    BasketballScoreboardTeam * homeTeam)
  : m_pAwayTeam(awayTeam),
    m_pHomeTeam(homeTeam)
{
	m_pAwayTeam->Subscribe(this);
	m_pHomeTeam->Subscribe(this);
}

BasketballScoreboard::~BasketballScoreboard() {
}

void BasketballScoreboard::TeamUpdate()
{
   DisplayScore();
}

void BasketballScoreboard::DisplayScore()
{
   std::cout << "Score : "
		     << m_pAwayTeam->GetName() << " " << m_pAwayTeam->GetScore() << ", "
		     << m_pHomeTeam->GetName() << " " << m_pHomeTeam->GetScore() << "\n";
}

