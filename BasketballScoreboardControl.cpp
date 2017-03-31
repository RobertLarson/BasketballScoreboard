/*
 * BasketballScoreboardControl.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#include "BasketballScoreboardControl.h"
#include "Command.h"

#include <iostream>

BasketballScoreboardControl::BasketballScoreboardControl() {
}

BasketballScoreboardControl::~BasketballScoreboardControl() {
}

void BasketballScoreboardControl::SetCommand(BasketballScoreboardButtonId buttonId,
   Command * command)
{
	std::map<BasketballScoreboardButtonId, Command *>::iterator commandIter;

	if((commandIter = m_commandMap.find(buttonId)) == m_commandMap.end())
	{
		m_commandMap.
		  insert(std::pair<BasketballScoreboardButtonId, Command *>(buttonId,
				                                                    command));
	}
	else
	{
		std::cout << "buttonId " << buttonId << " map entry already exists.\n";
	}
}


void BasketballScoreboardControl::ButtonPressed
    (BasketballScoreboardButtonId buttonId)
{
	std::map<BasketballScoreboardButtonId, Command *>::iterator commandIter;

	if((commandIter = m_commandMap.find(buttonId)) != m_commandMap.end())
	{
       Command * command = commandIter->second;

       command->Execute();

       m_commandHistory.push_front(command);
	}
}

void BasketballScoreboardControl::UndoLastButtonPress()
{
    if(!m_commandHistory.empty())
    {
    	Command * command = m_commandHistory.front();

    	command->Undo();

    	m_commandHistory.pop_front();
    }
    else
    {
    	std::cout << "no previous button press to undo!\n";
    }
}
