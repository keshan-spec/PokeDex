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

    PokemonNode *charmander = new PokemonNode;
    charmander->name = "Charmander";
    charmander->type = "Fire";
    charmander->ability = "Blaze";

    PokemonNode *squirtle = new PokemonNode;
    squirtle->name = "Squirtle";
    squirtle->type = "Water";
    squirtle->ability = "Torrent";
    squirtle->next = nullptr;

    pikachu->next = charmander;
    charmander->next = squirtle;

    // create a new player
    PlayerNode *ash = new PlayerNode;
    ash->name = "Ash";
    ash->addPokemon(*pikachu);
    ash->next = nullptr;

    // create a new pokedex entry
    PokeDex *pokedex = new PokeDex;
    pokedex->pokemonsPtr = pikachu;
    pokedex->playerPtr = ash;

    // list players
    pokedex->listPlayers();
}