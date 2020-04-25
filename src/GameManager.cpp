#include "GameManager.h"
#include "DataManager.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <set>

bool GameManager::quit_game_flag = false;
int key_pressed;
enum MenuItems {NewGame = 1, TopTen, Close} itm;

bool GameManager::InitManager()
{
    std::cout << "Choose one of below items: " << std::endl;
    std::cout << " 1. New Game" << std::endl;
    std::cout << " 2. Top ten" << std::endl;
    std::cout << " 3. Close" << std::endl;
    std::cout << "# ";

    while (!(std::cin >> key_pressed))
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
        std::cout << "Please enter 1, 2 or 3! ";
    }
    if ((key_pressed < 1) || (key_pressed > 3))
    {
        std::cout << "you pressed : " << key_pressed << std::endl;
        std::cout << "Please enter 1, 2 or 3! " << std::endl << std::endl;
        return false;
    }

    switch (key_pressed)
    {
        case NewGame:
        {
            return true;
        };
        break;

        case TopTen:
        {
            DataManager dm;
            std::map<string, int> recorded_players;
            recorded_players = dm.ReadGameHistoryMap();
            if (recorded_players.size() > 0)
            {
                dm.DisplaySortedPlayers(recorded_players);
            }
            else
            {
                std::cout << "There is not history file.!" << std::endl;
            }
            return false;
        };
        break;

        case Close:
        {
            std::cout << "The game is closed." << std::endl;
            quit_game_flag = true;
        };

        return false;
    }
}

void GameManager::ManageNewPlayer(Player *p)
{
    p->SetPlayerName();
}

void GameManager::DumpDataToFile(Player *p)
{
    std::cout << "player ::  " << p->GetPlayerName() << " :: " << p->GetPlayerScore() << " :: " << p->GetPlayerGameTime() << std::endl;
}

void GameManager::temp_print_vector_of_object_pointers(vector<Player *> v_player)
{
    int v_player_size = v_player.size();
    for (int i = 0; i < v_player_size; i++)
    {
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "player vector::  " << v_player[i]->GetPlayerName() << std::endl;
    }
}
