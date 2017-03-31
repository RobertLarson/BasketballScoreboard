
#include <iostream>

#include "BasketballScoreboard.h"
#include "BasketballScoreboardButtonId.h"
#include "BasketballScoreboardControl.h"
#include "BasketballScoreboardTeam.h"
#include "FreeThrowCommand.h"
#include "TwoPointFieldGoalCommand.h"
#include "ThreePointFieldGoalCommand.h"

int main()
{
	std::cout << "Basketball Scoreboard\n";

	BasketballScoreboardTeam * homeTeam =
		new BasketballScoreboardTeam(std::string("Home Team"));
	BasketballScoreboardTeam * awayTeam =
		new BasketballScoreboardTeam(std::string("Away Team"));

	BasketballScoreboard * scoreBoard =
		new BasketballScoreboard(awayTeam, homeTeam);

	FreeThrowCommand * freeThrowCommandHomeTeam =
		new FreeThrowCommand(homeTeam);
	TwoPointFieldGoalCommand * twoPointFieldGoalCommandHomeTeam =
		new TwoPointFieldGoalCommand(homeTeam);
	ThreePointFieldGoalCommand * threePointFieldGoalCommandHomeTeam =
		new ThreePointFieldGoalCommand(homeTeam);

	FreeThrowCommand * freeThrowCommandAwayTeam =
		new FreeThrowCommand(awayTeam);
	TwoPointFieldGoalCommand * twoPointFieldGoalCommandAwayTeam =
		new TwoPointFieldGoalCommand(awayTeam);
	ThreePointFieldGoalCommand * threePointFieldGoalCommandAwayTeam =
		new ThreePointFieldGoalCommand(awayTeam);

	BasketballScoreboardControl * basketballScoreboardControl =
		new BasketballScoreboardControl();

	basketballScoreboardControl->
	    SetCommand(BSCI_HomeTeamFreeThrowButtonId,
			       freeThrowCommandHomeTeam);
	basketballScoreboardControl->
	    SetCommand(BSCI_HomeTeamTwoPointFieldGoalButtonId,
	    		   twoPointFieldGoalCommandHomeTeam);
	basketballScoreboardControl->
	    SetCommand(BSCI_HomeTeamThreePointFieldGoalButtonId,
	    		   threePointFieldGoalCommandHomeTeam);

	basketballScoreboardControl->
	    SetCommand(BSCI_AwayTeamFreeThrowButtonId,
			       freeThrowCommandAwayTeam);
	basketballScoreboardControl->
	    SetCommand(BSCI_AwayTeamTwoPointFieldGoalButtonId,
	    		   twoPointFieldGoalCommandAwayTeam);
	basketballScoreboardControl->
	    SetCommand(BSCI_AwayTeamThreePointFieldGoalButtonId,
	    		   threePointFieldGoalCommandAwayTeam);

	basketballScoreboardControl->ButtonPressed(BSCI_HomeTeamFreeThrowButtonId);
	basketballScoreboardControl->ButtonPressed(BSCI_HomeTeamTwoPointFieldGoalButtonId);
	basketballScoreboardControl->ButtonPressed(BSCI_HomeTeamThreePointFieldGoalButtonId);

	basketballScoreboardControl->UndoLastButtonPress();
	basketballScoreboardControl->UndoLastButtonPress();
	basketballScoreboardControl->UndoLastButtonPress();

	basketballScoreboardControl->ButtonPressed(BSCI_AwayTeamFreeThrowButtonId);
	basketballScoreboardControl->ButtonPressed(BSCI_AwayTeamTwoPointFieldGoalButtonId);
	basketballScoreboardControl->ButtonPressed(BSCI_AwayTeamThreePointFieldGoalButtonId);

	basketballScoreboardControl->UndoLastButtonPress();
	basketballScoreboardControl->UndoLastButtonPress();
	basketballScoreboardControl->UndoLastButtonPress();


	delete basketballScoreboardControl;
	delete homeTeam;
    delete freeThrowCommandHomeTeam;
    delete twoPointFieldGoalCommandHomeTeam;
    delete threePointFieldGoalCommandHomeTeam;
    delete awayTeam;
    delete freeThrowCommandAwayTeam;
    delete twoPointFieldGoalCommandAwayTeam;
    delete threePointFieldGoalCommandAwayTeam;

	return 0;
}
