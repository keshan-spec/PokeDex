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

// Pokemon Node Structure
// @desc - to store pokemon details in nodes for the PokeDex Linked List
// @param name - pokemon name
// @param type - pokemon type
// @param ability - pokemon ability
// @param next - pointer to the next pokemon node
struct PokemonNode
{
    string name;
    string type;
    string ability;
    PokemonNode *next;

    // Constructor when no parameters are passed
    PokemonNode()
    {
        this->name = "";
        this->type = "";
        this->ability = "";
        this->next = nullptr;
    }

    // constructor when all parameters are passed
    PokemonNode(string name, string type, string ability)
    {
        this->name = name;
        this->type = type;
        this->ability = ability;
        this->next = nullptr;
    }

    // @desc - method that allows this struct to be passed as a map key
    // @ return - boolean
    bool operator<(const PokemonNode &other) const
    {
        return this->name < other.name;
    }
};

// Player Node Structure
// @desc - to store player details in nodes for the PokeDex Linked List
// @param name - player name
// @param pokemon - map object that stores the pokemon object and the count of the pokemon
// @param next - pointer to the next player node
struct PlayerNode
{
    string name;
    map<PokemonNode, int> pokemons; // Map of pokemons and their count
    PlayerNode *next;

    // Constructor when no parameters are passed
    PlayerNode()
    {
        this->name = "";
        this->next = nullptr;
    }

    // constructor when all parameters are passed
    PlayerNode(string name)
    {
        this->name = name;
        this->next = nullptr;
    }
};

// PokeDex Linked List Structure
// @desc - to store the heads of the player and pokemon nodes
// @param pokemonHead - head of the pokemon linked list
// @param playerHead - head of the player linked list
struct PokeDex
{
    PokemonNode *pokemonsPtr;
    PlayerNode *playerPtr;

    // Constructor when no parameters are passed
    PokeDex()
    {
        pokemonsPtr = nullptr;
        playerPtr = nullptr;
    }

    // constructor when all parameters are passed
    PokeDex(PokemonNode *pokemons, PlayerNode *players)
    {
        this->pokemonsPtr = pokemons;
        this->playerPtr = players;
    }
};

// HELPER FUNCTIONS FOR POKEMON NODES

// @desc - search for a pokemon in the PokeDex
// @param pokedex - pointer to the PokeDex
// @param pokemonName - name of the pokemon to search for
// @return - pointer to the pokemon node if found, else return nullptr
// @complexity - O(n) where n is the number of pokemon nodes
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

// @desc - creates a new pokemon node
// @param name - name of the pokemon
// @param type - type of the pokemon
// @param ability - ability of the pokemon
// @return - pointer to the new pokemon node
// @complexity - O(1) - constant time
PokemonNode *newPokemonNode(string name, string type, string ability)
{
    PokemonNode *pokemon = new PokemonNode(name, type, ability);
    // pokemon->name = name;
    // pokemon->type = type;
    // pokemon->ability = ability;
    return pokemon;
}

// @desc - inserts a new pokemon node into the PokeDex
// @param pokedex - pointer to the PokeDex
// @param pokemon - pointer to the pokemon node to be inserted
// @complexity - O(1) - constant time
void addPokemonToList(PokeDex *pokedex, string name, string type, string ability)
{
    // check if pokemon exists
    PokemonNode *pokemon = findPokemon(pokedex, name);
    // if pokemon exists in the list, return
    if (pokemon != nullptr)
    {
        cout << "[DEX ALERT] " << name << " already exists in the PokeDex!" << endl;
        return;
    }

    // if pokemon doestn't exist, create a new pokemon node
    pokemon = newPokemonNode(name, type, ability);
    PokemonNode *current = pokedex->pokemonsPtr;
    cout << "[DEX ALERT] > A wild " << name << " has been spotted in the PokeDex!" << endl;

    if (current == nullptr)
        // if the list is empty, make the new pokemon the head
        pokedex->pokemonsPtr = pokemon;
    else
    {
        while (current->next != nullptr)
            current = current->next;
        // add the new pokemon to the end of the list
        current->next = pokemon;
    }
}

// HELPER FUNCTIONS FOR PLAYER NODES

// @desc - search for a player in the PokeDex
// @param pokedex - pointer to the PokeDex
// @param playerName - name of the player to search for
// @return - pointer to the player node if found, else return nullptr
// @complexity - O(n) where n is the number of player nodes
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

// @desc - adds a new player node to the PokeDex
// @param pokedex - pointer to the PokeDex
// @param playerName - name of the player to be added
// @complexity - O(1) - constant time
void addPlayerToList(PokeDex *pokedex, string name)
{
    // check if player node already exists
    PlayerNode *player = findPlayer(pokedex, name);
    // if player exists in the list, return
    if (player != nullptr)
    {
        cout << "[DEX ALERT] " << name << " already exists in the PokeDex!" << endl;
        return;
    }

    // if player doestn't exist, create a new player node
    player = new PlayerNode(name);
    PlayerNode *current = pokedex->playerPtr;

    cout << "[DEX ALERT] > " << name << " has been added to the PokeDex!" << endl;

    if (current == nullptr)
    {
        // if the list is empty, make the new player the head
        pokedex->playerPtr = player;
    }
    else
    {
        while (current->next != nullptr)
        {
            current = current->next;
        }
        // add the new player to the end of the list
        current->next = player;
    }
}

// @desc - creates a new player node
// @param name - name of the player
// @return - pointer to the new player node
// @complexity - O(1) - constant time
PlayerNode *newPlayerNode(string name)
{
    PlayerNode *player = new PlayerNode(name);
    return player;
}

// @desc - adds a pokemon to the player's pokemon map
// @param pokedex - pointer to the PokeDex
// @param playerName - name of the player
// @param pokemonName - name of the pokemon
// @complexity - O(1) - constant time
void addPokemonToPlayer(PokeDex *pokedex, string playerName, string pokemonName)
{
    // check if player exists
    PlayerNode *player = findPlayer(pokedex, playerName);
    if (player == nullptr)
    {
        cout << "[DEX ERROR] " << playerName << " does not exist in the PokeDex!" << endl;
        return;
    }

    // check if pokemon exists
    PokemonNode *pokemon = findPokemon(pokedex, pokemonName);
    if (pokemon == nullptr)
    {
        cout << "[DEX ERROR] " << pokemonName << " does not exist in the PokeDex!" << endl;
        return;
    }

    // check if player already has pokemon
    if (player->pokemons.find(*pokemon) != player->pokemons.end())
    {
        cout << "[DEX WARNING] " << playerName << " already owns " << pokemonName << "!" << endl;
        // increment count
        player->pokemons[*pokemon]++;
        return;
    }

    // add pokemon to player's map
    cout << "[DEX ALERT] > " << playerName << " has captured " << pokemonName << "!" << endl;
    player->pokemons.insert(pair<PokemonNode, int>(*pokemon, 1));
}

// POKDEX HELPER FUNCTIONS

// @desc - prints all the players names in the PokeDex
// @param pokedex - pointer to the PokeDex
// @complexity - O(n) where n is the number of player nodes
void listPlayers(PokeDex *pokedex)
{
    PlayerNode *current = pokedex->playerPtr;
    cout << "[DEX DUMP] Players > " << endl;
    while (current != nullptr)
    {
        cout << "\tName: " << current->name << endl;
        current = current->next;
    }
}

// @desc - prints all the pokemon names in the PokeDex
// @param pokedex - pointer to the PokeDex
// @complexity - O(n) where n is the number of pokemon nodes
void listPokemons(PokeDex *pokedex)
{
    PokemonNode *current = pokedex->pokemonsPtr;
    cout << "[DEX DUMP] Pokemons > " << endl;
    while (current != nullptr)
    {
        cout << "\tName: " << current->name << endl;
        current = current->next;
    }
}

// @desc - prints the players details along with their pokemon and their count
// @param pokedex - pointer to the PokeDex
// @param playerName - name of the player
// @complexity - O(n+m) where n is the number of players (search) and m is the number of pokemon (print)
void displayPlayerDetails(PokeDex *pokedex, string playerName)
{
    PlayerNode *player = findPlayer(pokedex, playerName);

    if (player == nullptr)
    {
        cout << "[DEX ERROR] " << playerName << " does not exist in the PokeDex!" << endl;
        return;
    }

    cout << "[DEX DUMP] " << playerName << " > " << endl;
    cout << "Player Name: " << player->name << endl;
    cout << "Player Pokemon(s) :" << endl;

    // loop over map of pokemons (pokemon, count)
    for (auto pokemon : player->pokemons)
    {
        cout << "\t" << pokemon.second << "x " << pokemon.first.name << endl;
    }
}

// @desc - prints the pokemon's name, type and ability
// @param pokdex - pointer to the PokeDex
// @param pokemonName - name of the pokemon
// @complexity - O(n) where n is the number of pokemon nodes (searching for pokemon)
void displayPokemonDetails(PokeDex *pokedex, string pokemonName)
{
    // check if pokemon exists
    PokemonNode *pokemon = findPokemon(pokedex, pokemonName);
    if (pokemon == nullptr)
    {
        cout << "[DEX ERROR] " << pokemonName << " does not exist in the PokeDex!" << endl;
        return;
    }

    cout << "[DEX DUMP] Pokemon Details > " << endl;
    cout << "\tName: " << pokemon->name << endl;
    cout << "\tType: " << pokemon->type << endl;
    cout << "\tAbility: " << pokemon->ability << endl;

    return;
}