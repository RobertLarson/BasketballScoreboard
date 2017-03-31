/*
 * BasketballScoreboard.h
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#ifndef BASKETBALLSCOREBOARD_H_
#define BASKETBALLSCOREBOARD_H_

#include "BasketballScoreboardTeamObserver.h"

class BasketballScoreboardTeam;

class BasketballScoreboard : public BasketballScoreboardTeamObserver {
public:
	BasketballScoreboard
	    (BasketballScoreboardTeam * awayTeam,
	     BasketballScoreboardTeam * homeTeam);

	virtual ~BasketballScoreboard();

	virtual void TeamUpdate();

	void DisplayScore();

private:
	BasketballScoreboardTeam * m_pAwayTeam;
	BasketballScoreboardTeam * m_pHomeTeam;
};

#endif /* BASKETBALLSCOREBOARD_H_ */
