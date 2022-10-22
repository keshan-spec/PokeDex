from pokedex import PokeDex, PokemonNode, PlayerNode, PokemonTypes, PokemonAbilities

pokedex = PokeDex()

# Add some pokemon
pokedex.addPokemon(
    PokemonNode(
        "Pikachu",
        [PokemonTypes.ELECTRIC, PokemonTypes.FIGHTING],
        [PokemonAbilities.STATIC, PokemonAbilities.LIGHTNING_ROD],
    )
)

pokedex.addPokemon(
    PokemonNode("Charmander", [PokemonTypes.FIRE], [PokemonAbilities.BLAZE])
)

pokedex.addPokemon(
    PokemonNode(
        "Bulbasaur",
        [PokemonTypes.GRASS, PokemonTypes.POISON],
        [PokemonAbilities.OVERGROW],
    )
)

# Create some players
ash = PlayerNode("Ash")
misty = PlayerNode("Misty")
brock = PlayerNode("Brock")

# Add players to pokedex
pokedex.addPlayer(ash)
pokedex.addPlayer(misty)
pokedex.addPlayer(brock)

# Add some pokemon to players
ash.AddPokemonToPlayer(pokedex, "Pikachu")
ash.AddPokemonToPlayer(pokedex, "Charmander")

misty.AddPokemonToPlayer(pokedex, "Bulbasaur")

# Print out the pokedex
pokedex.listPlayers()
print("\n")
pokedex.listPokemon()

print("\n")
# Print out the player details
pokedex.DisplayPlayerDetails("Ash")
pokedex.DisplayPlayerDetails("Misty")

print("\n")
# Print out the pokemon details
pokedex.DisplayPokemonDetails("Pikachu")
pokedex.DisplayPokemonDetails("Charmander")
