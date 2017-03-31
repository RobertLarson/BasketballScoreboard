/*
 * ThreePointFieldGoalCommand.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#include "ThreePointFieldGoalCommand.h"

#include "BasketballScoreboardTeam.h"


ThreePointFieldGoalCommand::ThreePointFieldGoalCommand(BasketballScoreboardTeam * team)
: m_pTeam(team)
{
}

ThreePointFieldGoalCommand::~ThreePointFieldGoalCommand() {
}


void ThreePointFieldGoalCommand::Execute()
{
   m_pTeam->ThreePointFieldGoalMade();
}


void ThreePointFieldGoalCommand::Undo()
{
   m_pTeam->WaiveOffThreePointFieldGoalMade();
}
