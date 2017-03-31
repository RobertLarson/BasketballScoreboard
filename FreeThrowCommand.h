/*
 * FreeThrowCommand.h
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#ifndef FREETHROWCOMMAND_H_
#define FREETHROWCOMMAND_H_

#include "Command.h"

class BasketballScoreboardTeam;

class FreeThrowCommand : public Command {
public:
	FreeThrowCommand(BasketballScoreboardTeam * team);
	virtual ~FreeThrowCommand();

	virtual void Execute();
	virtual void Undo();

private:
	BasketballScoreboardTeam * m_pTeam;
};

#endif /* FREETHROWCOMMAND_H_ */
