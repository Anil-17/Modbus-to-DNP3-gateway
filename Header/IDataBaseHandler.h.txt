#pragma once

#include<string.h>
#include<iostream>
#include<unordered_map>
#include<opendnp3/outstation/DatabaseConfig.h>
#include<fstream>
#include<vector>
#include <sstream>

using namespace std;
using namespace opendnp3;

class DataMap{
    public:
    unordered_map<int,pair<int,string>> A_O;
    unordered_map<int,pair<int,string>> A_I;
    unordered_map<int,int> B_I;
    unordered_map<int,int> B_O;
    unordered_map<int,int> R_C;
    unordered_map<int,int> F_C;
    unordered_map<int,int> D_I;
    DatabaseConfig ReadFile(string);
    void LineHandle(string,DatabaseConfig&);
    vector<string> LineRead(string);
};



