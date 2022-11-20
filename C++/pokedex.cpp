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

    // create pokemon nodes
    for (int i = 0; i < pokemonsArr.size(); i++)
    {
        addPokemonToList(pokedex, pokemonsArr[i][0], pokemonsArr[i][1], pokemonsArr[i][2]);
    }

    // add player to pokedex
    addPlayerToList(pokedex, "Ash");
    addPlayerToList(pokedex, "Misty");

    listPlayers(pokedex);
    listPokemons(pokedex);

    // // add pokemons to player
    addPokemonToPlayer(pokedex, "Ash", "Bulbasaur");
    addPokemonToPlayer(pokedex, "Ash", "Charmander");
    addPokemonToPlayer(pokedex, "Ash", "Squirtle");
    addPokemonToPlayer(pokedex, "Ash", "Squirtle");

    addPokemonToPlayer(pokedex, "Misty", "Caterpie");
    addPokemonToPlayer(pokedex, "Misty", "Metapod");
    addPokemonToPlayer(pokedex, "Misty", "Butterfree");

    displayPlayerDetails(pokedex, "Ash");
    displayPlayerDetails(pokedex, "Misty");
    displayPokemonDetails(pokedex, "Bulbasaur");
}