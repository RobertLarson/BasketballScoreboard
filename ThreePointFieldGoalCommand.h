/*
 * ThreePointFieldGoalCommand.h
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#ifndef THREEPOINTFIELDGOALCOMMAND_H_
#define THREEPOINTFIELDGOALCOMMAND_H_

#include "Command.h"

class BasketballScoreboardTeam;

class ThreePointFieldGoalCommand : public Command {
public:
	ThreePointFieldGoalCommand(BasketballScoreboardTeam * team);
	virtual ~ThreePointFieldGoalCommand();

	virtual void Execute();
	virtual void Undo();

private:
	BasketballScoreboardTeam * m_pTeam;};

#endif /* THREEPOINTFIELDGOALCOMMAND_H_ */
