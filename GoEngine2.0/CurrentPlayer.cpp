#include "CurrentPlayer.h"

CurrentPlayer& CurrentPlayer::getCurrentPlayer()
{
    static CurrentPlayer* player = new CurrentPlayer;
    return *player;
}

void CurrentPlayer::setTracker(bool _tracker)
{
    tracker = _tracker;
}

void CurrentPlayer::flipTracker()
{
    tracker = !tracker;
}

bool CurrentPlayer::isWhite()
{
    return tracker;
}

CurrentPlayer::CurrentPlayer()
{
    tracker = true;
}
