// linked list

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>

using namespace std;

struct PokemonNode
{
    string name;
    string type;
    string ability;
    PokemonNode *next;
};

struct PlayerNode
{
    string name;
    list<PokemonNode> pokemons;
    PlayerNode *next;
};

struct PokeDexEntry
{
    PokemonNode *pokemonsPtr;
    PlayerNode *playerPtr;

    PokeDexEntry()
    {
        pokemonsPtr = nullptr;
        playerPtr = nullptr;
    }

    PokeDexEntry(PokemonNode *pokemons, PlayerNode *players)
    {
        this->pokemonsPtr = pokemons;
        this->playerPtr = players;
    }

    // list players
    void listPlayers()
    {
        PlayerNode *current = playerPtr;
        while (current != nullptr)
        {
            cout << "Player Name" << current->name << endl;
            cout << "Player Pokemon :" << endl;
            for (auto pokemon : current->pokemons)
            {
                cout << "Name: " << pokemon.name << endl;
                cout << "Type: " << pokemon.type << endl;
                cout << "Ability: " << pokemon.ability << endl;
            }
            current = current->next;
        }
    }

    // list pokemons
    void listPokemons()
    {
        PokemonNode *current = pokemonsPtr;
        while (current != nullptr)
        {
            cout << current->name << endl;
            current = current->next;
        }
    }
};