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

    // public:
    //     void addPokemon(PokemonNode &pokemon)
    //     {
    //         this->pokemons.push_back(pokemon);
    //     }
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
PokemonNode newPokemonNode(string name, string type, string ability);
void addPokemonToList(PokeDex *pokedex, PokemonNode *pokemon);
PokemonNode findPokemon(PokeDex *pokedex, string name);

newPokemonNode(string name, string type, string ability)
{
    // check if pokemon node already exists
    PokemonNode *pokemon = findPokemon(pokedex, name);
    if (pokemon != nullptr)
    {
        cout << "Pokemon already exists" << endl;
        return nullptr;
    }
    else
    {
        // create a new pokemon
        PokemonNode *newPokemon = new PokemonNode;
        newPokemon->name = name;
        newPokemon->type = type;
        newPokemon->ability = ability;
        newPokemon->next = nullptr;
        return *pokemon;
    }
}

addPokemonToList(PokeDex *pokedex, PokemonNode *pokemon)
{
    // check if pokemon node already exists
    PokemonNode *existingPokemon = findPokemon(pokedex, pokemon->name);
    if (existingPokemon != nullptr)
    {
        cout << "Pokemon already exists" << endl;
        return;
    }
    else
    {
        // add pokemon to the end of the list
        PokemonNode *current = pokedex->pokemonsPtr;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = pokemon;
    }
}

// player functions
PlayerNode newPlayerNode(PlayerNode *player, string name);
void addPlayer(PokeDex *pokedex, PlayerNode *player);
PlayerNode findPlayer(PokeDex *pokedex, string name);
void addPokemonToPlayer(PokeDex *pokedex, string playerName, PokemonNode *pokemon);

// pokedex functions
void listPlayers(PokeDex *pokedex);
void listPokemons(PokeDex *pokedex);
void displayPlayerDetails(PokeDex *pokedex, string playerName);
void displayPokemonDetails(PokeDex *pokedex, string pokemonName);

listPlayers(PokeDex *pokedex)
{
    PlayerNode *current = pokedex->playerPtr;
    while (current != nullptr)
    {
        cout << "Player Name: " << current->name << endl;
        current = current->next;
    }
}

listPokemons(PokeDex *pokedex)
{
    PokemonNode *current = pokedex->pokemonsPtr;
    while (current != nullptr)
    {
        cout << "Pokemon Name: " << current->name << endl;
        current = current->next;
    }
}

displayPlayerDetails(string playerName)
{
    PlayerNode *current = playerPtr;
    while (current != nullptr)
    {
        if (current->name == playerName)
        {
            cout << "Player Name: " << current->name << endl;
            cout << "Player Pokemon(s) :" << endl;
            for (auto pokemon : current->pokemons)
            {
                cout << "\tName: " << pokemon.name << endl;
                cout << "\tType: " << pokemon.type << endl;
                cout << "\tAbility: " << pokemon.ability << endl;
            }
        }
        current = current->next;
    }
}

displayPokemonDetails(string pokemonName)
{
    PokemonNode *current = pokemonsPtr;
    while (current != nullptr)
    {
        if (current->name == pokemonName)
        {
            cout << "Pokemon Name: " << current->name << endl;
            cout << "Pokemon Type: " << current->type << endl;
            cout << "Pokemon Ability: " << current->ability << endl;
        }
        current = current->next;
    }
}