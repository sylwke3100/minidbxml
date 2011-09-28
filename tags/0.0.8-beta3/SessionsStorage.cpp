#include "SessionsStorage.h"

SessionsStorage::SessionsStorage()
{
    srand(time(0));
    Session = (rand ()%10000000000)+1;
}
bool SessionsStorage::CheckSession(SessionsStorage& Session2)
{
    if (Session2.GetSessionID() == Session)
        return true;
    else return false;
}
int SessionsStorage::StatusSession()
{
   return IsLocked;
}
int SessionsStorage::GetSessionID()
{
    return Session;
}
void SessionsStorage::ConvertToSession(string Session2,SessionsStorage& S)
{
    int i;
    istringstream s(Session2);
    S.SetSession(i);
}
void SessionsStorage::LockSession()
{
    IsLocked = 1;
}
void SessionsStorage::UnlockSession()
{
    IsLocked = 0;
}
void SessionsStorage::SetSession(int Id)
{
    Session = Id;
}
