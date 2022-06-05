#include "header.h"

//clears memory buffer
void clearBuffer(){
    int chara = 0;
    while (chara != '\n' && chara != EOF)
    {
        chara = getchar();
    }
}

// replaces scanf to read a string from the fgets function
int read(char *chain, int lenght){ 
  char* positionEntree = NULL;
  if (fgets(chain, lenght, stdin) != NULL){
    positionEntree = strchr(chain, '\n');
    if (positionEntree != NULL){
      *positionEntree = '\0';
    }
    else
    {
      clearBuffer();
    }
    return 1;
  }
    else
    {
      clearBuffer();
      return 0;
    }
}

// replaces scanf to read a string from the fgets function from a .txt file
int readfile(char *chain, int lenght, FILE * file){ 
  char* positionEntree = NULL;
  if (fgets(chain, lenght, file) != NULL){
    positionEntree = strchr(chain, '\n');
    if (positionEntree != NULL){
      *positionEntree = '\0';
    }
    else
    {
      clearBuffer();
    }
    return 1;
  }
    else
    {
      clearBuffer();
      return 0;
    }
}

//gets the atkChange of a skill from a file
StatChange getAtkChange(Skill skill, StatChange atkchge, FILE *fsc)
{
	if (skill.changepath == 1)
	{
		fsc = fopen("statchange/1.txt","r");
	}
	if (skill.changepath == 2)
	{
		fsc = fopen("statchange/2.txt","r");
	}
	if (skill.changepath == 3)
	{
		fsc = fopen("statchange/3.txt","r");
	}
	if (skill.changepath == 4)
	{
		fsc = fopen("statchange/4.txt","r");
	}
	if (skill.changepath == 5)
	{
		fsc = fopen("statchange/5.txt","r");
	}
	if (skill.changepath == 6)
	{
		fsc = fopen("statchange/6.txt","r");
	}
	if (skill.changepath == 7)
	{
		fsc = fopen("statchange/7.txt","r");
	}
	if (skill.changepath == 8)
	{
		fsc = fopen("statchange/8.txt","r");
	}
	fscanf(fsc,"%d %d %d %d %d", &atkchge.change, &atkchge.buffDurationMax, &atkchge.buffDuration, &atkchge.debuffDurationMax, &atkchge.debuffDuration);
	skill.atkChange = atkchge;
	return atkchge;
}

//gets the defChange of a skill from a file
StatChange getDefChange(Skill skill, StatChange defchge, FILE *fsc)
{
	if (skill.changepath == 1)
	{
		fsc = fopen("statchange/1.txt","r");
	}
	if (skill.changepath == 2)
	{
		fsc = fopen("statchange/2.txt","r");
	}
	if (skill.changepath == 3)
	{
		fsc = fopen("statchange/3.txt","r");
	}
	if (skill.changepath == 4)
	{
		fsc = fopen("statchange/4.txt","r");
	}
	if (skill.changepath == 5)
	{
		fsc = fopen("statchange/5.txt","r");
	}
	if (skill.changepath == 6)
	{
		fsc = fopen("statchange/6.txt","r");
	}
	if (skill.changepath == 7)
	{
		fsc = fopen("statchange/7.txt","r");
	}
	if (skill.changepath == 8)
	{
		fsc = fopen("statchange/8.txt","r");
	}
	fscanf(fsc,"%d %d %d %d %d", &defchge.change, &defchge.buffDurationMax, &defchge.buffDuration, &defchge.debuffDurationMax, &defchge.debuffDuration);
	skill.defChange = defchge;
	return defchge;
}

//gets the spdChange of a skill from a file
StatChange getSpdChange(Skill skill, StatChange spdchge, FILE *fsc)
{
	if (skill.changepath == 1)
	{
		fsc = fopen("statchange/1.txt","r");
	}
	if (skill.changepath == 2)
	{
		fsc = fopen("statchange/2.txt","r");
	}
	if (skill.changepath == 3)
	{
		fsc = fopen("statchange/3.txt","r");
	}
	if (skill.changepath == 4)
	{
		fsc = fopen("statchange/4.txt","r");
	}
	if (skill.changepath == 5)
	{
		fsc = fopen("statchange/5.txt","r");
	}
	if (skill.changepath == 6)
	{
		fsc = fopen("statchange/6.txt","r");
	}
	if (skill.changepath == 7)
	{
		fsc = fopen("statchange/7.txt","r");
	}
	if (skill.changepath == 8)
	{
		fsc = fopen("statchange/8.txt","r");
	}
	fscanf(fsc,"%d %d %d %d %d", &spdchge.change, &spdchge.buffDurationMax, &spdchge.buffDuration, &spdchge.debuffDurationMax, &spdchge.debuffDuration);
	skill.spdChange = spdchge;
	return spdchge;
}

//gets the agiChange of a skill from a file
StatChange getAgiChange(Skill skill, StatChange agichge, FILE *fsc)
{
	if (skill.changepath == 1)
	{
		fsc = fopen("statchange/1.txt","r");
	}
	if (skill.changepath == 2)
	{
		fsc = fopen("statchange/2.txt","r");
	}
	if (skill.changepath == 3)
	{
		fsc = fopen("statchange/3.txt","r");
	}
	if (skill.changepath == 4)
	{
		fsc = fopen("statchange/4.txt","r");
	}
	if (skill.changepath == 5)
	{
		fsc = fopen("statchange/5.txt","r");
	}
	if (skill.changepath == 6)
	{
		fsc = fopen("statchange/6.txt","r");
	}
	if (skill.changepath == 7)
	{
		fsc = fopen("statchange/7.txt","r");
	}
	if (skill.changepath == 8)
	{
		fsc = fopen("statchange/8.txt","r");
	}
	fscanf(fsc,"%d %d %d %d %d", &agichge.change, &agichge.buffDurationMax, &agichge.buffDuration, &agichge.debuffDurationMax, &agichge.debuffDuration);
	skill.agiChange = agichge;
	return agichge;
}

//gets a fighter's skill from a file and give its StatChange variables by using functions getAtkChange, getDefChange, getSpdChange, getAgiChange
Skill getSpell(Fighter fighter, Skill skill, StatChange atkChange, StatChange defChange, StatChange spdChange, StatChange agiChange, FILE* f)
{
	
	if (fighter.path == 1)
	{
		f = fopen("spells/sansSpell.txt","r");
	}
	if (fighter.path == 2)
	{
		f = fopen("spells/dioSpell.txt","r");
	}
	if (fighter.path == 3)
	{
		f = fopen("spells/davidlafargeSpell.txt","r");
	}
	if (fighter.path == 4)
	{
		f = fopen("spells/missjirachiSpell.txt","r");
	}
	if (fighter.path == 5)
	{
		f = fopen("spells/jotaroSpell.txt","r");
	}
	if (fighter.path == 6)
	{
		f = fopen("spells/ibratvSpell.txt","r");
	}
	if (fighter.path == 7)
	{
		f = fopen("spells/snakegaySpell.txt","r");
	}
	if (fighter.path == 8)
	{
		f = fopen("spells/kirby54Spell.txt","r");
	}
	
	readfile(skill.name, 30, f);
	readfile(skill.desc, 150, f);
	fscanf(f,"%d %d %d %d %d %d %d %d %d %d %d %d", &skill.changepath, &skill.cd, &skill.cdMax, &skill.AoE, &skill.AoEBuff, &skill.multi, &skill.effect, &skill.target, &skill.heal, &skill.healValue, &skill.atkBarChange, &skill.atkBarValue);
	fighter.speSkill = skill;
	skill.atkChange = getAtkChange(skill, atkChange, f);
	skill.defChange = getDefChange(skill, defChange, f);
	skill.spdChange = getSpdChange(skill, spdChange, f);
	skill.agiChange = getAgiChange(skill, agiChange, f);
	return skill;
}

//makes a whole team by reading a file with the fighters' stats and stock them into tabs sorted by stats, assign them into Fighter variables and then assign them their respective spells with function getSpell 
void getTeam( FILE * f, Team t, Fighter fighter1, Fighter fighter2, Fighter fighter3, Fighter fighter4, Skill skill1, Skill skill2, Skill skill3, Skill skill4, StatChange atkChange, StatChange defChange, StatChange spdChange, StatChange agiChange)
{
	printf("choisissez un nom pour votre équipe :\n");
	read(t.teamname, 25);;
	clearBuffer(); 
	char Name[SIZE_MAX][15];
	int Hp[SIZE_MAX], Atk[SIZE_MAX], Def[SIZE_MAX], Spd[SIZE_MAX], Atkbar[SIZE_MAX], Agi[SIZE_MAX], path[SIZE_MAX];
	for( int i=0 ; i<6 ; i++ ) 
	{ 
		fscanf(f ,"%s %d %d %d %d %d %d %d", Name[i], &Hp[i], &Atk[i], &Def[i], &Spd[i], &Atkbar[i], &Agi[i], &path[i]); 
	}
	
	t.team[0]=fighter1;
	t.team[1]=fighter2;
	t.team[2]=fighter3;
	t.team[3]=fighter4;
	
	fighter1.name = Name[0]; fighter1.hp = Hp[0]; fighter1.atk = Atk[0]; fighter1.def = Def[0]; fighter1.spd = Spd[0]; fighter1.atkBar = Atkbar[0]; fighter1.agi = Agi[0]; fighter1.path = path[0];
	fighter2.name = Name[1]; fighter2.hp = Hp[1]; fighter2.atk = Atk[1]; fighter2.def = Def[1]; fighter2.spd = Spd[1]; fighter2.atkBar = Atkbar[1]; fighter2.agi = Agi[1]; fighter2.path = path[1];
	fighter3.name = Name[2]; fighter3.hp = Hp[2]; fighter3.atk = Atk[2]; fighter3.def = Def[2]; fighter3.spd = Spd[2]; fighter3.atkBar = Atkbar[2]; fighter3.agi = Agi[2]; fighter3.path = path[2];
	fighter4.name = Name[3]; fighter4.hp = Hp[3]; fighter4.atk = Atk[3]; fighter4.def = Def[3]; fighter4.spd = Spd[3]; fighter4.atkBar = Atkbar[3]; fighter4.agi = Agi[3]; fighter4.path = path[3];
	
	fighter1.speSkill = getSpell(fighter1, skill1, atkChange, defChange,   spdChange, agiChange, f);
	fighter2.speSkill = getSpell(fighter2, skill2,atkChange, defChange, spdChange, agiChange, f);
	fighter3.speSkill = getSpell(fighter3, skill3, atkChange, defChange, spdChange, agiChange, f);
	fighter4.speSkill = getSpell(fighter4, skill4, atkChange, defChange, spdChange, agiChange, f);
	
	fclose(f);
	printf ("\nle nom de votre équipe est : %s\nvotre équipe est composée des fighters suivants :\n%s\n%s\n%s\n%s\n\n", t.teamname, fighter1.name, fighter2.name, fighter3.name, fighter4.name );
}

