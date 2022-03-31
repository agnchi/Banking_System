#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <time.h> 
#include "User.h"

using namespace std;

class Administrator
{
public:
    void Admin_manu();
    void Add();
    void Modify();
    int Modify_menu();
    void Delete();
    string GenerateNum();
    string Gen_CheckNum();
    User findUser(string info);
    bool ID_check(string info);
};
