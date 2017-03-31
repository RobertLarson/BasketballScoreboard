/*
 * FreeThrowCommand.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#include "FreeThrowCommand.h"

#include "BasketballScoreboardTeam.h"

FreeThrowCommand::FreeThrowCommand(BasketballScoreboardTeam * team)
: m_pTeam(team)
{
}

FreeThrowCommand::~FreeThrowCommand() {
}

void FreeThrowCommand::Execute()
{
   m_pTeam->FreeThrowMade();
}


void FreeThrowCommand::Undo()
{
   m_pTeam->WaiveOffFreeThrow();
}
