from enum import Enum
from typing import List

# enums for pokemon types
class PokemonTypes(Enum):
    NORMAL = "Normal"
    FIRE = "Fire"
    WATER = "Water"
    ELECTRIC = "Electric"
    GRASS = "Grass"
    ICE = "Ice"
    FIGHTING = "Fighting"
    POISON = "Poison"
    GROUND = "Ground"
    FLYING = "Flying"
    PSYCHIC = "Psychic"
    BUG = "Bug"
    ROCK = "Rock"
    GHOST = "Ghost"
    DRAGON = "Dragon"
    DARK = "Dark"
    STEEL = "Steel"
    FAIRY = "Fairy"


# enums for pokemon abilities
class PokemonAbilities(Enum):
    BLAZE = "Blaze"
    TORRENT = "Torrent"
    OVERGROW = "Overgrow"
    SWARM = "Swarm"
    CHLOROPHYLL = "Chlorophyll"
    SOLAR_POWER = "Solar Power"
    LEAF_GUARD = "Leaf Guard"
    FLASH_FIRE = "Flash Fire"
    SHED_SKIN = "Shed Skin"
    RUN_AWAY = "Run Away"
    KEEN_EYE = "Keen Eye"
    INNER_FOCUS = "Inner Focus"
    HYPER_CUTTER = "Hyper Cutter"
    SHEER_FORCE = "Sheer Force"
    GUTS = "Guts"
    STURDY = "Sturdy"
    ROCK_HEAD = "Rock Head"
    HEAVY_METAL = "Heavy Metal"
    LIGHT_METAL = "Light Metal"
    CLEAR_BODY = "Clear Body"
    WHITE_SMOKE = "White Smoke"
    SOUNDPROOF = "Soundproof"
    SWIFT_SWIM = "Swift Swim"
    WATER_ABSORB = "Water Absorb"
    WATER_VEIL = "Water Veil"
    STATIC = "Static"
    THUNDERBOLT = "Thunderbolt"
    THUNDER = "Thunder"
    THUNDER_WAVE = "Thunder Wave"
    THUNDER_SHOCK = "Thunder Shock"
    FLAMETHROWER = "Flamethrower"
    FIRE_SPIN = "Fire Spin"
    VINE_WHIP = "Vine Whip"
    WATER_GUN = "Water Gun"
    HYDRO_PUMP = "Hydro Pump"
    HYDRO_CANNON = "Hydro Cannon"
    LIGHTNING_ROD = "Lightning Rod"


# Linked List
class PokeDex:
    def __init__(self):
        self.PlayerHead = None
        self.PokemonHead = None

        self.PokemonCache = {}
        self.PlayerCache = {}

    def listPlayers(self):
        current = self.PlayerHead
        while current:
            print(repr(current))
            current = current.next

    def listPokemon(self):
        current = self.PokemonHead
        while current:
            print(repr(current))
            current = current.next

    def DisplayPlayerDetails(self, name):
        if name in self.PlayerCache:
            print(self.PlayerCache[name])
            return

        current = self.PlayerHead
        while current:
            if current.data["name"] == name:
                self.PlayerCache[name] = current
                print(current)
                return
            current = current.next

    def DisplayPokemonDetails(self, name):
        if name in self.PokemonCache:
            print(self.PokemonCache[name])
            return

        current = self.PokemonHead
        while current:
            if current.data["name"] == name:
                self.PokemonCache[name] = current
                print(current)
                return
            current = current.next

    def addPlayer(self, playerNode):
        if self.PlayerHead is None:
            self.PlayerHead = playerNode
        else:
            current = self.PlayerHead
            while current.next:
                current = current.next
            current.next = playerNode

    def addPokemon(self, pokemonNode):
        if self.PokemonHead is None:
            self.PokemonHead = pokemonNode
        else:
            current = self.PokemonHead
            while current.next:
                current = current.next
            current.next = pokemonNode


# Node for Pokemon
class PokemonNode:
    def __init__(
        self, name: str, type: List[PokemonTypes], ability: List[PokemonAbilities]
    ):
        self.data = {"name": name, "types": type, "abilities": ability}
        self.next = None

    def pokemeta(self):
        # get only the str of the type and ability
        type = [x.value for x in self.data["types"]]
        ability = [x.value for x in self.data["abilities"]]

        return {"Name": self.data["name"], "Types": type, "Abilities": ability}

    def __repr__(self):
        return f"Name : {self.data['name']}, Type : {self.pokemeta()['Types']}"

    def __str__(self):
        out = ""
        for key, value in self.pokemeta().items():
            out += f"{key.title()}: {value}\n"

        return out

    def findPokemon(pokeDex: PokeDex, name: str):
        if name in pokeDex.PokemonCache:
            return pokeDex.PokemonCache[name]

        current = pokeDex.PokemonHead
        while current:
            if current.data["name"] == name:
                return current
            current = current.next
        return None


# Node for Player
class PlayerNode:
    def __init__(self, name: str):
        self.data = {"name": name, "pokemon": [], "pokemons": 0}
        self.next = None

    def __str__(self):
        d = []
        for pokemon in self.data["pokemon"]:
            d.append(pokemon.pokemeta())
        return f"Trainer: {self.data['name']}\nPokemons: {d}"

    def __repr__(self) -> str:
        return f"Trainer: {self.data['name']}, Pokemons: {self.data['pokemons']}"

    def findPlayer(pokeDex: PokeDex, name: str):
        if name in pokeDex.PlayerCache:
            return pokeDex.PlayerCache[name]

        current = pokeDex.PlayerHead
        while current:
            if current.data["name"] == name:
                return current
            current = current.next
        return None

    def AddPokemonToPlayer(self, pokeDex: PokeDex, pokemon: PokemonNode or str) -> None:
        if isinstance(pokemon, str):
            pokemon = PokemonNode.findPokemon(pokeDex, pokemon)

        if pokemon is None:
            print("Pokemon not found")
            return

        self.data["pokemon"].append(pokemon)
        self.data["pokemons"] += 1
