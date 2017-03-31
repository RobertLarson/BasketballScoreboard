/*
 * TwoPointFieldGoalCommand.h
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#ifndef TWOPOINTFIELDGOALCOMMAND_H_
#define TWOPOINTFIELDGOALCOMMAND_H_

#include "Command.h"

class BasketballScoreboardTeam;

class TwoPointFieldGoalCommand : public Command {
public:
	TwoPointFieldGoalCommand(BasketballScoreboardTeam * team);
	virtual ~TwoPointFieldGoalCommand();

	virtual void Execute();
	virtual void Undo();

private:
	BasketballScoreboardTeam * m_pTeam;
};

#endif /* TWOPOINTFIELDGOALCOMMAND_H_ */
