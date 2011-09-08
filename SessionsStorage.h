#ifndef SESSIONSSTORAGE_H
#define SESSIONSSTORAGE_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

class SessionsStorage
{
    public:
        SessionsStorage();
        bool CheckSession(SessionsStorage& Session2);
        int StatusSession();
        int GetSessionID();
        void ConvertToSession(string Session2,SessionsStorage& S);
        void LockSession();
        void UnlockSession();
        void SetSession(int Id);
    private:
        int Session;
        bool IsLocked;
};

#endif // SESSIONSSTORAGE_H
