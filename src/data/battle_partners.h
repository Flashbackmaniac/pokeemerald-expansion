//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//

#line 1 "src/data/battle_partners.party"

#line 1
    [PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
    [PARTNER_STEVEN] =
    {
#line 9
        .trainerName = _("Steven"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender = 
#line 13
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15
            .heldItem = ITEM_CHESTO_BERRY,
#line 20
            .ev = TRAINER_PARTY_EVS(0, 0, 252, 0, 0, 252),
#line 19
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 18
            .ability = ABILITY_STURDY,
#line 17
            .lvl = 66,
#line 16
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 21
                MOVE_STEEL_WING,
                MOVE_DRILL_PECK,
                MOVE_SPIKES,
                MOVE_REST,
            },
            },
            {
#line 26
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 26
            .heldItem = ITEM_QUICK_CLAW,
#line 31
            .ev = TRAINER_PARTY_EVS(252, 252, 0, 6, 0, 0),
#line 30
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 29
            .ability = ABILITY_ROCK_HEAD,
#line 28
            .lvl = 66,
#line 27
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 32
                MOVE_ROCK_SLIDE,
                MOVE_IRON_HEAD,
                MOVE_DRAGON_CLAW,
                MOVE_PROTECT,
            },
            },
            {
#line 37
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 37
            .heldItem = ITEM_METAGROSSITE,
#line 41
            .ev = TRAINER_PARTY_EVS(252, 252, 0, 6, 0, 0),
#line 40
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 39
            .lvl = 66,
#line 38
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 42
                MOVE_HAMMER_ARM,
                MOVE_ZEN_HEADBUTT,
                MOVE_METEOR_MASH,
                MOVE_PROTECT,
            },
            },
        },
    },
