Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_EventScript_RestWoman::
	lock
	faceplayer
	msgbox Route119_House_Text_WouldYouLikeToRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route119_House_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route119_House_EventScript_DeclineRest
	end

Route119_House_EventScript_Rest::
	msgbox Route119_House_Text_AlrightTakeARest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route119_House_Text_ReadyToGo
	release
	end

Route119_House_EventScript_DeclineRest::
	msgbox Route119_House_Text_ComeBackAnyTime
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "I heard about a cave called the Cave\n"
	.string "Of Origin.\p"
	.string "People rumor that the spirits of\n"
	.string "Pokémon are revived there. Could\l"
	.string "something like that really happen?$"

Route119_House_Text_Wingull:
	.string "Wingull: Pihyoh!$"

Route119_House_Text_WouldYouLikeToRest:
	.string "Hello!\n"
	.string "Thanks for stopping by!\p"
	.string "Would you like to rest up for a bit?$"

Route119_House_Text_AlrightTakeARest:
	.string "Alright, take a rest for as long\n"
	.string "as you need!$"

Route119_House_Text_ComeBackAnyTime:
	.string "Come back any time when you and your\n"
	.string "Pokémon are feeling tired!$"

Route119_House_Text_ReadyToGo:
	.string "Alright! You and your Pokémon look\n"
	.string "ready to go!$"

