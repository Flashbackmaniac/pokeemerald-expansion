.set LOCALID_DAYCARE_MON_0, 25
.set LOCALID_DAYCARE_MON_1, 26
.set LOCALID_XAVIER, 27
.set LOCALID_PIERCE, 28

Route117_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_OnTransition
	.byte 0

Route117_OnTransition:
	call Route117_EventScript_TryMoveDayCareMan
	@ set flags for OW daycare mons
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	getdaycaregfx VAR_OBJ_GFX_ID_0, VAR_OBJ_GFX_ID_1, VAR_TEMP_0, VAR_TEMP_1
	switch VAR_RESULT
	case 2, Route117_EventScript_ShowDaycareMon1
	case 1, Route117_EventScript_ShowDaycareMon0
	end

Route117_EventScript_ShowDaycareMon1:
	@ set pokemon movement type based on compatibility
	special SetDaycareCompatibilityString
	call_if_eq VAR_RESULT, PARENTS_INCOMPATIBLE, Route117_EventScript_DaycareMonIncompatible
	@ Don't do anything if PARENTS_LOW_COMPATIBILITY
	call_if_eq VAR_RESULT, PARENTS_MED_COMPATIBILITY, Route117_EventScript_DaycareMonMedCompatibility
	call_if_eq VAR_RESULT, PARENTS_MAX_COMPATIBILITY, Route117_EventScript_DaycareMonMaxCompatibility
	clearflag FLAG_TEMP_2
Route117_EventScript_ShowDaycareMon0:
	clearflag FLAG_TEMP_1
	end

Route117_EventScript_DaycareMonIncompatible: @ mons never face each other
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT
	return

Route117_EventScript_DaycareMonMedCompatibility: @ down and towards each other
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT
	return

Route117_EventScript_DaycareMonMaxCompatibility: @ facing; walk in place
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	return

Route117_EventScript_TryMoveDayCareMan::
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route117_EventScript_StopMoveDayCareMan
	setobjectxyperm LOCALID_DAYCARE_MAN, 47, 6
Route117_EventScript_StopMoveDayCareMan::
	return

Route117_EventScript_Woman::
	msgbox Route117_Text_ArentTheseFlowersPretty, MSGBOX_NPC
	end

Route117_EventScript_LittleBoy::
	msgbox Route117_Text_AirIsTastyHere, MSGBOX_NPC
	end

Route117_EventScript_Girl::
	msgbox Route117_Text_DayCarePokemonHadNewMove, MSGBOX_NPC
	end

Route117_EventScript_RouteSignVerdanturf::
	msgbox Route117_Text_RouteSignVerdanturf, MSGBOX_SIGN
	end

Route117_EventScript_RouteSignMauville::
	msgbox Route117_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route117_EventScript_DayCareSign::
	msgbox Route117_Text_DayCareSign, MSGBOX_SIGN
	end

Route117_EventScript_Isaac::
	trainerbattle_single TRAINER_ISAAC_1, Route117_Text_IsaacIntro, Route117_Text_IsaacDefeat, Route117_EventScript_RegisterIsaac
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchIsaac
	msgbox Route117_Text_IsaacPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterIsaac::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route117_Text_IsaacRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISAAC_1
	release
	end

Route117_EventScript_RematchIsaac::
	trainerbattle_rematch TRAINER_ISAAC_1, Route117_Text_IsaacRematchIntro, Route117_Text_IsaacRematchDefeat
	msgbox Route117_Text_IsaacPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Lydia::
	trainerbattle_single TRAINER_LYDIA_1, Route117_Text_LydiaIntro, Route117_Text_LydiaDefeat, Route117_EventScript_RegisterLydia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchLydia
	msgbox Route117_Text_LydiaPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterLydia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route117_Text_LydiaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LYDIA_1
	release
	end

Route117_EventScript_RematchLydia::
	trainerbattle_rematch TRAINER_LYDIA_1, Route117_Text_LydiaRematchIntro, Route117_Text_LydiaRematchDefeat
	msgbox Route117_Text_LydiaPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Dylan::
	trainerbattle_single TRAINER_DYLAN_1, Route117_Text_DylanIntro, Route117_Text_DylanDefeat, Route117_EventScript_RegisterDylan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchDylan
	msgbox Route117_Text_DylanPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterDylan::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route117_Text_DylanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DYLAN_1
	release
	end

Route117_EventScript_RematchDylan::
	trainerbattle_rematch TRAINER_DYLAN_1, Route117_Text_DylanRematchIntro, Route117_Text_DylanRematchDefeat
	msgbox Route117_Text_DylanPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Maria::
	trainerbattle_single TRAINER_MARIA_1, Route117_Text_MariaIntro, Route117_Text_MariaDefeat, Route117_EventScript_RegisterMaria
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchMaria
	msgbox Route117_Text_MariaPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterMaria::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route117_Text_MariaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MARIA_1
	release
	end

Route117_EventScript_RematchMaria::
	trainerbattle_rematch TRAINER_MARIA_1, Route117_Text_MariaRematchIntro, Route117_Text_MariaRematchDefeat
	msgbox Route117_Text_MariaPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK, Route117_Text_DerekIntro, Route117_Text_DerekDefeat
	msgbox Route117_Text_DerekPostBattle, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Anna::
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaIntro, Route117_Text_AnnaDefeat, Route117_Text_AnnaNotEnoughMons, Route117_EventScript_RegisterAnna
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchAnna
	msgbox Route117_Text_AnnaPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterAnna::
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANNA_AND_MEG_1
	release
	end

Route117_EventScript_RematchAnna::
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaRematchIntro, Route117_Text_AnnaRematchDefeat, Route117_Text_AnnaRematchNotEnoughMons
	msgbox Route117_Text_AnnaPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Meg::
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegIntro, Route117_Text_MegDefeat, Route117_Text_MegNotEnoughMons, Route117_EventScript_RegisterMeg
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchMeg
	msgbox Route117_Text_MegPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterMeg::
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANNA_AND_MEG_1
	release
	end

Route117_EventScript_RematchMeg::
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegRematchIntro, Route117_Text_MegRematchDefeat, Route117_Text_MegRematchNotEnoughMons
	msgbox Route117_Text_MegPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Melina::
	trainerbattle_single TRAINER_MELINA, Route117_Text_MelinaIntro, Route117_Text_MelinaDefeat
	msgbox Route117_Text_MelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Brandi::
	trainerbattle_single TRAINER_BRANDI, Route117_Text_BrandiIntro, Route117_Text_BrandiDefeat
	msgbox Route117_Text_BrandiPostBattle, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Aisha::
	trainerbattle_single TRAINER_AISHA, Route117_Text_AishaIntro, Route117_Text_AishaDefeat
	msgbox Route117_Text_AishaPostBattle, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_XavierEncounter::
	goto_if_set FLAG_TEMP_3, Route117_EventScript_XavierBattleAgain
	goto_if_set FLAG_TEMP_4, Route117_EventScript_XavierChangedMind
	setflag FLAG_TEMP_4
	applymovement LOCALID_XAVIER, Common_Movement_FacePlayer
	msgbox Route117_Text_XavierAskToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_BattleXavier
	msgbox Route117_Text_XavierComeBackAnyTime, MSGBOX_DEFAULT
	releaseall
	end
	
Route117_EventScript_BattleXavier::
	msgbox Route117_Text_XavierAlrightLetsDoThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_XAVIER, Route117_Text_XavierDefeat
	setflag FLAG_TEMP_3
	clearflag FLAG_TEMP_4
	msgbox Route117_Text_XavierWantToContinue, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_BattleXavier
	msgbox Route117_Text_XavierComeBackAnyTime, MSGBOX_DEFAULT
	releaseall
	end
	
Route117_EventScript_XavierChangedMind::
	applymovement LOCALID_XAVIER, Common_Movement_FacePlayer
	msgbox Route117_Text_XavierChangedMind, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_BattleXavier
	msgbox Route117_Text_XavierComeBackAnyTime
	releaseall
	end
	
	
Route117_EventScript_XavierBattleAgain::
	applymovement LOCALID_XAVIER, Common_Movement_FacePlayer
	msgbox Route117_Text_XavierBattleAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_BattleXavier
	msgbox Route117_Text_XavierComeBackAnyTime, MSGBOX_DEFAULT
	releaseall
	end

Route117_EventScript_PierceEncounter::
	goto_if_set FLAG_TEMP_5, Route117_EventScript_PierceWantToLevelUpSomeMore
	goto_if_set FLAG_TEMP_6, Route117_EventScript_PierceBackWantToBattle
	setflag FLAG_TEMP_6
	applymovement LOCALID_PIERCE, Common_Movement_FacePlayer
	msgbox Route117_Text_PierceAskToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_BattlePierce
	msgbox Route117_Text_PierceAlwaysBeHere, MSGBOX_DEFAULT
	releaseall
	end
	
Route117_EventScript_BattlePierce::
	msgbox Route117_Text_PierceOkayCommence, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PIERCE, Route117_Text_PierceDefeat
	setflag FLAG_TEMP_5
	clearflag FLAG_TEMP_6
	msgbox Route117_Text_PierceKeepGoing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_BattlePierce
	msgbox Route117_Text_PierceAlwaysBeHere, MSGBOX_DEFAULT
	releaseall
	end
	
Route117_EventScript_PierceBackWantToBattle::
	applymovement LOCALID_PIERCE, Common_Movement_FacePlayer
	msgbox Route117_Text_PierceBackWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_BattlePierce
	msgbox Route117_Text_PierceAlwaysBeHere
	releaseall
	end
	
	
Route117_EventScript_PierceWantToLevelUpSomeMore::
	applymovement LOCALID_PIERCE, Common_Movement_FacePlayer
	msgbox Route117_Text_PierceWantToLevelUpSomeMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_BattlePierce
	msgbox Route117_Text_PierceAlwaysBeHere, MSGBOX_DEFAULT
	releaseall
	end

Route117_Text_DayCarePokemonHadNewMove:
	.string "I left my Pokémon at the Day Care.\p"
	.string "When I got it back, it had a new move\n"
	.string "that I didn't teach it.\l"
	.string "I was really, really surprised.$"

Route117_Text_ArentTheseFlowersPretty:
	.string "What do you think?\n"
	.string "Aren't these flowers pretty?\p"
	.string "I planted them all!$"

Route117_Text_AirIsTastyHere:
	.string "The air is tasty here!$"

Route117_Text_RouteSignVerdanturf:
	.string "Route 117\n"
	.string "{LEFT_ARROW} Verdanturf Town$"

Route117_Text_RouteSignMauville:
	.string "Route 117\n"
	.string "{RIGHT_ARROW} Mauville City$"

Route117_Text_DayCareSign:
	.string "Pokémon Day Care\n"
	.string "“Let us raise your Pokémon.”$"
		
Route117_Text_XavierAskToBattle:
	.string "Hey, there! Do you want to\n"
	.string "battle me for some experience?$"
	
Route117_Text_XavierAlrightLetsDoThis:
	.string "Alright, let's do this!$"
	
Route117_Text_XavierDefeat:
	.string "...And that should do it!$"
	
Route117_Text_XavierWantToContinue:
	.string "Want to battle again?$"
	
Route117_Text_XavierComeBackAnyTime:
	.string "Come back if you need some\n"
	.string "experience!$"
	
Route117_Text_XavierChangedMind:
	.string "Oh? Did you change your mind?$"
	
Route117_Text_XavierBattleAgain:
	.string "Hey, you're back! I presume\n"
	.string "you want to battle me again?$"
	
Route117_Text_PierceAskToBattle:
	.string "I've got Pokémon that can help\n"
	.string "with leveling up. Wanna battle?$"
	
Route117_Text_PierceOkayCommence:
	.string "Okay, let the leveling commence!$"
	
Route117_Text_PierceDefeat:
	.string "Nicely done!$"
	
Route117_Text_PierceKeepGoing:
	.string "My Pokémon can still battle. Keep going?$"
	
Route117_Text_PierceAlwaysBeHere:
	.string "Alright, I'll always be here if\n"
	.string "you need me.$"
	
Route117_Text_PierceBackWantToBattle:
	.string "Ah, you're back. Do you want to battle?$"
	
Route117_Text_PierceWantToLevelUpSomeMore:
	.string "You've returned. Do you want to\n"
	.string "level up some more?$"

