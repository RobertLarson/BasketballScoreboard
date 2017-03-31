/*
 * Command.h
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#ifndef COMMAND_H_
#define COMMAND_H_

class Command
{
public:
	virtual void Execute() = 0;
	virtual void Undo ()   = 0;
};


#endif /* COMMAND_H_ */
