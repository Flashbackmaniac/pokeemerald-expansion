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
        .encounterMusic_gender =
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7
        .trainerBackPic = TRAINER_BACK_PIC_BRENDAN,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 9
    [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
    {
#line 10
        .trainerName = _("Steven"),
#line 11
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 12
        .trainerPic = TRAINER_PIC_STEVEN,
        .encounterMusic_gender =
#line 14
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 16
        .aiFlags = AI_FLAG_BASIC_TRAINER,
#line 15
        .trainerBackPic = TRAINER_BACK_PIC_STEVEN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 18
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 18
            .heldItem = ITEM_CHESTO_BERRY,
#line 23
            .ev = TRAINER_PARTY_EVS(0, 0, 252, 0, 0, 252),
#line 22
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 21
            .ability = ABILITY_STURDY,
#line 20
            .lvl = 66,
#line 19
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 24
                MOVE_STEEL_WING,
                MOVE_DRILL_PECK,
                MOVE_SPIKES,
                MOVE_REST,
            },
            },
            {
#line 29
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 29
            .heldItem = ITEM_QUICK_CLAW,
#line 34
            .ev = TRAINER_PARTY_EVS(252, 252, 0, 6, 0, 0),
#line 33
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 32
            .ability = ABILITY_ROCK_HEAD,
#line 31
            .lvl = 66,
#line 30
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 35
                MOVE_ROCK_SLIDE,
                MOVE_IRON_HEAD,
                MOVE_DRAGON_CLAW,
                MOVE_PROTECT,
            },
            },
            {
#line 40
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 40
            .heldItem = ITEM_METAGROSSITE,
#line 44
            .ev = TRAINER_PARTY_EVS(252, 252, 0, 6, 0, 0),
#line 43
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 42
            .lvl = 66,
#line 41
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 45
                MOVE_HAMMER_ARM,
                MOVE_ZEN_HEADBUTT,
                MOVE_METEOR_MASH,
                MOVE_PROTECT,
            },
            },
        },
    },
