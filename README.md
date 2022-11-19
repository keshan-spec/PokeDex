# Code

Use Linked List to store the pokedex

Feature Requirements

1. A `Pokedex` struct holding the `ptr` for the `Pokemon Node` and the `Player Node`
2. Pokedex struct should be created and passed onto function to make operations.
3. Pokemons and Players should be a LinkedList. 
4. Pokemon Node should store a pokemons' (name, type, primary abilities)
5. Create functions to add, create, find nodes (by pokemon name).
6. Pokemon Functions:
    - [x] newPokemonNode(name, type, ability) -> ptr*Pokemon Node
    - [x] addPokemonToList(*pokedex, name, type, ability) -> void
    - [x] findPokemon(pokedex, name) -> ptr*Pokemon Node
7. Player Functions:
    - [x] newPlayerNode(name) -> ptr*Player Node
    - [x] addPlayerToList(*pokedex, name) -> void
    - [x] findPlayer(pokedex, name) -> ptr*Player Node
    - [ ] addPokemonToPlayer(pokedex, playerName, pokemonName) -> void (adds pokemon if not found else increment it count)

8. Pokedex Functions:
    - [x] displayPokemonDetails(pokedex, name) -> void (displays all details )
    - [x] displayPlayerDetails(pokedex, name) -> void (displays all details along the details of the pokemons owned)
    - [x] listPokemons(pokedex) -> void  (displays list of names)
    - [x] listPlayers(pokedex) -> void (displays list of names)

# Report
1. Created structs/classes.
2. Types of lists chosen (array, list, etc).
3. Memory location and pointers
4. Explain the `DisplayPlayerDetails()` function.








