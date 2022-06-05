#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#define SIZE_MAX 200

typedef struct{
	int change; //0 : don't affect the stat, 1 : buff the stat, 2 : debuff the stat
	int buffDurationMax; //number of turn(s) the buff will be effective when the skill is used
	int buffDuration; //number of turn(s) the buff is effective
	int debuffDurationMax; //number of turn(s) the debuff will be effective when the skill is used
	int debuffDuration; //number of turn(s) the debuff is effective
}StatChange;

typedef struct{
	char name[26];
	char desc[151]; //skill description
	int cd; //current cooldown
	int cdMax;
	int AoE; //0 : is not an AoE, 1 : is an AoE
	int AoEBuff; //0 : self buff, 1 : team buff
	int multi; //skill multipliers * 100
	int effect; //0 : damage-only skill, 1 : skill has side effect(s)
	int target; //0 : ally, 1 : enemy
	int heal; //0 : don't heal, 1 : heal
	int healValue; //(heal value)% * (ally's hpmax) is the amount of heal received by the ally
	int atkBarChange; //0 : don't affect atkbar, 1 : buff atkbar, 2 : debuff atkbar
	int atkBarValue; //atkbarvalue is the amount of atkbar added to the target's current atkbar
	int changepath; //indicator for funtion getStatChange to open the skill's statChange file
	StatChange atkChange;
	StatChange defChange;
	StatChange spdChange;
	StatChange agiChange;
}Skill;

typedef struct{
	char *name;
	int hpMax; //total health points
	int hp; // current hp
	int baseAtk;
	int atk; //current attack stat
	int baseDef;
	int def; //current defense stat
	int baseSpd;
	int spd; //current speed stat
	int baseAgi;
	int agi; //current dodge stat
	int atkBar; //attack bar 
	Skill speSkill; //special skil
	int path; //indicator for function getSkill to open the fighters' skills files
	
}Fighter;


typedef struct{
	char *teamname;
	Fighter team[5];
	
}Team;

void clearBuffer();
int read(char *chain, int lenght);
int readfile(char *chain, int lenght, FILE * file);
StatChange getAtkChange(Skill skill, StatChange atkchge, FILE *fsc);
StatChange getDefChange(Skill skill, StatChange defchge, FILE *fsc);
StatChange getSpdChange(Skill skill, StatChange spdchge, FILE *fsc);
StatChange getAgiChange(Skill skill, StatChange agichge, FILE *fsc);
Skill getSpell(Fighter fighter, Skill skill, StatChange atkChange, StatChange defChange, StatChange spdChange, StatChange agiChange, FILE* f);
void getTeam( FILE * f, Team t, Fighter fighter1, Fighter fighter2, Fighter fighter3, Fighter fighter4, Skill skill1, Skill skill2, Skill skill3, Skill skill4, StatChange atkChange, StatChange defChange, StatChange spdChange, StatChange agiChange);