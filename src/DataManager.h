#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <set>

using std::string;
using std::vector;

class DataManager
{

public:
    DataManager();
    ~DataManager();
    std::map<string, int> ReadGameHistoryMap();
    void WriteGameHistoryMapSorted(std::map<string, int> aux_map);
    void WriteGameHistoryMap(std::map<string, int> players_map);
    void DisplaySortedPlayers(std::map<string, int> aux_map);
};