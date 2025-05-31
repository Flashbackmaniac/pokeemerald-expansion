.set LOCALID_JOKE_MOVE_TUTOR, 2

FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

MoveRelearner_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_SeeYouLater
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_SeeYouLater
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_SeeYouLater
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_SeeYouLater::
	msgbox FallarborTown_MoveRelearnersHouse_Text_SeeYouLater, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor::
	lockall
	applymovement LOCALID_JOKE_MOVE_TUTOR, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_2, FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_MoveList
	msgbox FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_Introduction, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_MoveList
	end

FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_MoveList::
	msgbox FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_HaveALook, MSGBOX_DEFAULT
	call FallarborTown_MoveRelearnersHouse_Multichoice_JokeMoveTutor_MoveList
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Multichoice_JokeMoveTutor_MoveList::
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, FallarborTown_MoveRelearnersHouse_Multichoice_JokeMoveTutor_Text_Celebrate, FallarborTown_MoveRelearnersHouse_Multichoice_JokeMoveTutor_Text_Hold_Hands, FallarborTown_MoveRelearnersHouse_Multichoice_JokeMoveTutor_Text_Splash, FallarborTown_MoveRelearnersHouse_Multichoice_JokeMoveTutor_Text_Cancel
	switch VAR_RESULT
	case 0, FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_Celebrate
	case 1, FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_Hold_Hands
	case 2, FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_Splash
	case 3, FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_Cancel
	compare VAR_RESULT 127
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_Cancel
	return

FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_Celebrate::
	msgbox FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_WhichMonToTeach, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_CELEBRATE
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, 0, FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_MoveList
	msgbox FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_SeeYouLater
	releaseall
	end

FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_Hold_Hands::
	msgbox FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_WhichMonToTeach, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_HOLD_HANDS
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, 0, FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_MoveList
	msgbox FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_SeeYouLater
	releaseall
	end

FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_Splash::
	msgbox FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_WhichMonToTeach, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SPLASH
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, 0, FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_MoveList
	msgbox FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_SeeYouLater
	releaseall
	end

FallarborTown_MoveRelearnersHouse_EventScript_JokeMoveTutor_Cancel::
	msgbox FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_SeeYouLater, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "I'm the Move Tutor.\p"
	.string "I know all the moves that Pokémon\n"
	.string "learn--every one of them--and I can\l"
	.string "teach Pokémon those moves.\p"
	.string "I can teach a move to a Pokémon\n"
	.string "of yours if you'd like.$"

FallarborTown_MoveRelearnersHouse_Text_WantMeToTeachMove:
	.string "Let me guess, you want me to teach\n"
	.string "a move?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Which Pokémon needs tutoring?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Which move should I teach?$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that Pokémon.$"

FallarborTown_MoveRelearnersHouse_Text_SeeYouLater:
	.string "Alright, see you later. Come back if your\n"
	.string "Pokémon need to learn a move.$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an Egg.$"

FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_Introduction:
	.string "That Move Relearner has gotten\n"
	.string "better with his services as of late.\p"
	.string "I'm not going to let myself get\n"
	.string "caught in the dust, no sirree!\p"
	.string "Hey, you! So you want your Pokémon\n"
	.string "to learn a move?$"

FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_HaveALook:
	.string "Feast your eyes on these\n"
	.string "truly exquisite moves!$"

FallarborTown_MoveRelearnersHouse_Multichoice_JokeMoveTutor_Text_Celebrate:
	.string "Celebrate$"

FallarborTown_MoveRelearnersHouse_Multichoice_JokeMoveTutor_Text_Hold_Hands:
	.string "Hold Hands$"

FallarborTown_MoveRelearnersHouse_Multichoice_JokeMoveTutor_Text_Splash:
	.string "Splash$"

FallarborTown_MoveRelearnersHouse_Multichoice_JokeMoveTutor_Text_Cancel:
	.string "Cancel$"

FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_WhichMonToTeach:
	.string "Which Pokémon should learn this move?$"

FallarborTown_MoveRelearnersHouse_Text_JokeMoveTutor_SeeYouLater:
	.string "Okay, see you later. Return if your\n"
	.string "Pokémon needs some top-notch moves.$"

