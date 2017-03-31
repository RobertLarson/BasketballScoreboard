/*
 * BasketballScoreboardTeam.h
 *
 *  Created on: Mar 25, 2017
 *      Author: Robert Larson
 */

#ifndef BASKETBALLSCOREBOARDTEAM_H_
#define BASKETBALLSCOREBOARDTEAM_H_

#include <string>
#include <vector>

#include "BasketballScoreboardTeamSubject.h"

class BasketballScoreboardTeam : public BasketballScoreboardTeamSubject {
public:
	BasketballScoreboardTeam(std::string name);
	virtual ~BasketballScoreboardTeam();

	virtual void Subscribe(BasketballScoreboardTeamObserver * observer);
	virtual void Unsubscribe(BasketballScoreboardTeamObserver * observer);
	virtual void Notify();

	std::string  GetName()  const { return m_name; }
	int          GetScore() const { return m_score; }

	void FreeThrowMade();
	void WaiveOffFreeThrow();

	void TwoPointFieldGoalMade();
	void WaiveOffTwoPointFieldGoalMade();

	void ThreePointFieldGoalMade();
	void WaiveOffThreePointFieldGoalMade();

	void Display();

private:
	void ScoringUpdate(int additionalPoints);

	std::string  m_name;
	int m_score;
	std::vector<BasketballScoreboardTeamObserver*> m_observers;
};

#endif /* BASKETBALLSCOREBOARDTEAM_H_ */
