#include <iostream>
#include <string>

// import linked list file
#include "LinkedLists.h"

int main()
{
    // create a new pokemon
    PokemonNode *pikachu = new PokemonNode;
    pikachu->name = "Pikachu";
    pikachu->type = "Electric";
    pikachu->ability = "Static";
    pikachu->next = nullptr;

    // create a new player
    PlayerNode *ash = new PlayerNode;
    ash->name = "Ash";
    ash->pokemons.push_back(*pikachu);
    ash->next = nullptr;

    // create a new pokedex entry
    PokeDexEntry *pokedex = new PokeDexEntry;
    pokedex->pokemonsPtr = pikachu;
    pokedex->playerPtr = ash;

    // list players
    pokedex->listPlayers();
}