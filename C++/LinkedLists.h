// linked list

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

struct PokemonNode
{
    string name;
    string type;
    string ability;
    PokemonNode *next;

    PokemonNode()
    {
        this->name = "";
        this->type = "";
        this->ability = "";
        this->next = nullptr;
    }

    PokemonNode(string name, string type, string ability)
    {
        this->name = name;
        this->type = type;
        this->ability = ability;
        this->next = nullptr;
    }

    // operator for mapping
    bool operator<(const PokemonNode &other) const
    {
        return this->name < other.name;
    }
};

struct PlayerNode
{
    string name;
    // Map of pokemons and their count
    map<PokemonNode, int> pokemons;
    PlayerNode *next;

    PlayerNode()
    {
        this->name = "";
        this->next = nullptr;
    }

    PlayerNode(string name)
    {
        this->name = name;
        this->next = nullptr;
    }
};

struct PokeDex
{
    PokemonNode *pokemonsPtr;
    PlayerNode *playerPtr;

    PokeDex()
    {
        pokemonsPtr = nullptr;
        playerPtr = nullptr;
    }

    PokeDex(PokemonNode *pokemons, PlayerNode *players)
    {
        this->pokemonsPtr = pokemons;
        this->playerPtr = players;
    }
};

// pokemon functions
PokemonNode *findPokemon(PokeDex *pokedex, string name)
{
    PokemonNode *current = pokedex->pokemonsPtr;
    while (current != nullptr)
    {
        if (current->name == name)
            return current;
        current = current->next;
    }
    return current;
}

PokemonNode *newPokemonNode(string name, string type, string ability)
{
    PokemonNode *pokemon = new PokemonNode(name, type, ability);
    // pokemon->name = name;
    // pokemon->type = type;
    // pokemon->ability = ability;
    return pokemon;
}

void addPokemonToList(PokeDex *pokedex, string name, string type, string ability)
{
    // check if pokemon exists
    PokemonNode *pokemon = findPokemon(pokedex, name);
    if (pokemon != nullptr)
    {
        return;
    }
    pokemon = newPokemonNode(name, type, ability);

    PokemonNode *current = pokedex->pokemonsPtr;
    if (current == nullptr)
        pokedex->pokemonsPtr = pokemon;
    else
    {
        while (current->next != nullptr)
            current = current->next;
        current->next = pokemon;
    }
}

// Player functions
PlayerNode *findPlayer(PokeDex *pokedex, string name)
{
    PlayerNode *current = pokedex->playerPtr;
    while (current != nullptr)
    {
        if (current->name == name)
        {
            return current;
        }
        current = current->next;
    }
    return current;
}

void addPlayerToList(PokeDex *pokedex, string name)
{
    // check if player node already exists
    PlayerNode *player = findPlayer(pokedex, name);
    if (player != nullptr)
    {
        return;
    }

    player = new PlayerNode(name);
    PlayerNode *current = pokedex->playerPtr;
    if (current == nullptr)
    {
        // add player to the list
        cout << "Adding player to the list" << endl;
        pokedex->playerPtr = player;
    }
    else
    {
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = player;
    }
}

PlayerNode *newPlayerNode(string name)
{
    PlayerNode *player = new PlayerNode(name);
    return player;
}

void addPokemonToPlayer(PokeDex *pokedex, string playerName, string pokemonName)
{
    PlayerNode *player = findPlayer(pokedex, playerName);
    if (player == nullptr)
    {
        cout << "Player does not exist" << endl;
        return;
    }

    // check if pokemon exists
    PokemonNode *pokemon = findPokemon(pokedex, pokemonName);
    if (pokemon == nullptr)
    {
        cout << "Pokemon does not exist" << endl;
        return;
    }

    // check if player already has pokemon
    // iterate through map and check if pokemon exists
    // map<PokemonNode, int>::iterator it = player->pokemons.find(*pokemon);
    if (player->pokemons.find(*pokemon) != player->pokemons.end())
    {
        cout << "Player already has pokemon" << endl;
        // increment count
        player->pokemons[*pokemon]++;
        return;
    }

    player->pokemons.insert(pair<PokemonNode, int>(*pokemon, 1));
}

// // pokedex functions
void listPlayers(PokeDex *pokedex)
{
    PlayerNode *current = pokedex->playerPtr;
    while (current != nullptr)
    {
        cout << "Player Name: " << current->name << endl;
        current = current->next;
    }
}

void listPokemons(PokeDex *pokedex)
{
    PokemonNode *current = pokedex->pokemonsPtr;
    while (current != nullptr)
    {
        cout << "Pokemon Name: " << current->name << endl;
        current = current->next;
    }
}

void displayPlayerDetails(PokeDex *pokedex, string playerName)
{
    PlayerNode *player = findPlayer(pokedex, playerName);

    if (player == nullptr)
    {
        cout << "Player not found" << endl;
        return;
    }

    while (player != nullptr)
    {
        if (player->name == playerName)
        {
            cout << "Player Name: " << player->name << endl;
            cout << "Player Pokemon(s) :" << endl;
            // loop over map of pokemons (pokemon, count)
            for (auto pokemon : player->pokemons)
            {
                cout << pokemon.first.name << " " << pokemon.second << endl;
            }
        }
        player = player->next;
    }
}

void displayPokemonDetails(PokeDex *pokedex, string pokemonName)
{
    PokemonNode *pokemon = findPokemon(pokedex, pokemonName);
    if (pokemon == nullptr)
    {
        cout << "Pokemon not found" << endl;
        return;
    }

    while (pokemon != nullptr)
    {
        if (pokemon->name == pokemonName)
        {
            cout << "Pokemon Name: " << pokemon->name << endl;
            cout << "Pokemon Type: " << pokemon->type << endl;
            cout << "Pokemon Ability: " << pokemon->ability << endl;
        }
        pokemon = pokemon->next;
    }
}