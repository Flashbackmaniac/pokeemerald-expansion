RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.string "Every Pokémon has an Ability\n"
	.string "that it can use.\p"
	.string "Some Abilities take affect in battle,\n"
	.string "while others can have effects outside\n"
	.string "of battle.$"

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.string "I've heard that Pokémon can also have\n"
	.string "what's known as Hidden Abilities.\p"
	.string "What makes them hidden, anyway?\n"
	.string "Pokémon are such strange creatures.$"

