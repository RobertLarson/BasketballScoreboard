/*
 * TeamSubject.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Robert Larson
 */

#ifndef BASKETBALLSCOREBOARDTEAMSUBJECT_H_
#define BASKETBALLSCOREBOARDTEAMSUBJECT_H_

class BasketballScoreboardTeamObserver;

class BasketballScoreboardTeamSubject
{
public:
	virtual void Subscribe(BasketballScoreboardTeamObserver * observer)   = 0;
	virtual void Unsubscribe(BasketballScoreboardTeamObserver * observer) = 0;
	virtual void Notify() = 0;
};

#endif /* TEAMSUBJECT_H_ */
