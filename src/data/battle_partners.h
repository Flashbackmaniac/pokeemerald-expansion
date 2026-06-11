//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file see expansion PR #7154
//

#line 1 "src/data/battle_partners.party"

#line 1
    [DIFFICULTY_NORMAL][PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_PIC_BRENDAN,
#line 5
        .gender = TRAINER_GENDER_MALE,
#line 6
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 0
        .multiTeamSize = MULTI_TEAM_SIZE_FULL,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
    [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
    {
#line 9
        .trainerName = _("Steven"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_PIC_STEVEN,
#line 12
        .gender = TRAINER_GENDER_MALE,
#line 13
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14
        .aiFlags = AI_FLAG_BASIC_TRAINER,
#line 0
        .multiTeamSize = MULTI_TEAM_SIZE_FULL,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 16
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 16
            .heldItem = ITEM_CHESTO_BERRY,
#line 21
            .ev = TRAINER_PARTY_EVS(0, 0, 252, 0, 0, 252),
#line 20
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 19
            .ability = ABILITY_STURDY,
#line 18
            .lvl = 66,
            .ball = POKEBALL_COUNT,
#line 17
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 22
                MOVE_STEEL_WING,
                MOVE_DRILL_PECK,
                MOVE_SPIKES,
                MOVE_REST,
            },
            },
            {
#line 27
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 27
            .heldItem = ITEM_QUICK_CLAW,
#line 32
            .ev = TRAINER_PARTY_EVS(252, 252, 0, 6, 0, 0),
#line 31
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 30
            .ability = ABILITY_ROCK_HEAD,
#line 29
            .lvl = 66,
            .ball = POKEBALL_COUNT,
#line 28
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 33
                MOVE_ROCK_SLIDE,
                MOVE_IRON_HEAD,
                MOVE_DRAGON_CLAW,
                MOVE_PROTECT,
            },
            },
            {
#line 38
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 38
            .heldItem = ITEM_METAGROSSITE,
#line 42
            .ev = TRAINER_PARTY_EVS(252, 252, 0, 6, 0, 0),
#line 41
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 40
            .lvl = 66,
            .ball = POKEBALL_COUNT,
#line 39
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 43
                MOVE_HAMMER_ARM,
                MOVE_ZEN_HEADBUTT,
                MOVE_METEOR_MASH,
                MOVE_PROTECT,
            },
            },
        },
    },
