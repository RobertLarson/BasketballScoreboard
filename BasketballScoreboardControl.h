/*
 * BasketballScoreboardControl.h
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#ifndef BASKETBALLSCOREBOARDCONTROL_H_
#define BASKETBALLSCOREBOARDCONTROL_H_

#include <map>
#include <deque>
#include "BasketballScoreboardButtonId.h"

class Command;

class BasketballScoreboardControl {
public:
	BasketballScoreboardControl();
	virtual ~BasketballScoreboardControl();

	void SetCommand(BasketballScoreboardButtonId buttonId,
	   Command * command);

	void ButtonPressed(BasketballScoreboardButtonId buttonId);
	void UndoLastButtonPress();

private:
	std::map<BasketballScoreboardButtonId, Command *> m_commandMap;
	std::deque<Command *> m_commandHistory;
};

#endif /* BASKETBALLSCOREBOARDCONTROL_H_ */
