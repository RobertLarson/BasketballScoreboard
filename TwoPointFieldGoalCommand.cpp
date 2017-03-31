/*
 * TwoPointFieldGoalCommand.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#include "TwoPointFieldGoalCommand.h"

#include "BasketballScoreboardTeam.h"

TwoPointFieldGoalCommand::TwoPointFieldGoalCommand(BasketballScoreboardTeam * team)
: m_pTeam(team)
{
}

TwoPointFieldGoalCommand::~TwoPointFieldGoalCommand() {
}


void TwoPointFieldGoalCommand::Execute()
{
   m_pTeam->TwoPointFieldGoalMade();
}


void TwoPointFieldGoalCommand::Undo()
{
   m_pTeam->WaiveOffTwoPointFieldGoalMade();
}
