#include <iostream>
#include <string>

// import linked list file
#include "LinkedLists.h"

int main()
{
    // create pokedex
    PokeDex *pokedex = new PokeDex;

    // list of list of pokemons
    vector<vector<string>> pokemonsArr = {
        {"Bulbasaur", "Grass", "Overgrow"},
        {"Charmander", "Fire", "Blaze"},
        {"Squirtle", "Water", "Torrent"},
        {"Caterpie", "Bug", "Shield Dust"},
        {"Metapod", "Bug", "Shed Skin"},
        {"Butterfree", "Bug", "Compound Eyes"},
        {"Beedrill", "Bug", "Swarm"},
        {"Pidgey", "Normal", "Keen Eye"},
        {"Rattata", "Normal", "Run Away"},
        {"Ekans", "Poison", "Intimidate"},
        {"Pikachu", "Electric", "Static"},
        {"Sandslash", "Ground", "Sand Veil"},
        {"Nidoran", "Poison", "Poison Point"},
        {"Clefairy", "Fairy", "Cute Charm"}};

    // add pokemons to pokedex
    for (int i = 0; i < pokemonsArr.size(); i++)
    {
        PokemonNode *pokemon = newPokemonNode(pokemonsArr[i][0], pokemonsArr[i][1], pokemonsArr[i][2]);
    }

    // addPokemonToList(*pokedex, "Pikachu", "Electric", "Static");

    // list pokemons
    listPokemons(pokedex);
}