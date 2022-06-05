#include "header.h"
//returns 0 if caster's attack against enemy went well, 1 if not
int atkSt(Fighter caster, Fighter enemy) {
	int valid = 1;
	if (enemy.hp <= 0) {
		printf("La cible est morte \n");
		return valid;
	}
	enemy.hp -= caster.atk - enemy.def;
	valid = 0;
	return valid;
}

//caster's attack, reduces target's health
void atk(Fighter caster, Team team) {	
	int valid = 1, target = 0;
	while(valid != 0) {
		while(target < 1 || target > 4) {
			printf("Sélectionner cible \n1 \n2 \n3 \n4 \n");
			scanf("%d", &target);
		}
		if (target == 1) {
			valid = atkSt(caster, team[target-1]);
		}
		if (target == 2) {
			valid = atkSt(caster, team[target - 1]);
		}
		if (target == 3) {
			valid = atkSt(caster, team[target - 1]);
		}
		if (target == 4) {
			valid = atkSt(caster, team[target - 1]);
		}
	}
}

//caster's attack, reduces target's health, noob difficulty
void atkNoob(Fighter caster, Team team) {
	int valid = 1, target = 0;
	srand(time(NULL));
	while (valid != 0) {
		target = rand()%3 + 1;
		if (target == 1) {
			valid = atkSt(caster, team[0]);
		}
		if (target == 2) {
			valid = atkSt(caster, team[1]);
		}
		if (target == 3) {
			valid = atkSt(caster, team[2]);
		}
		if (target == 4) {
			valid = atkSt(caster, team[3]);
		}
	}
}

//target gets healed by caster
void heal(Fighter caster, Fighter target) {
	target.hp += target.hpMax * (caster.speSkill.healValue / 100);
	if (target.hp > target.hpMax) {
		target.hp = target.hpMax;
	}
}

//target gets an atk buff
void buffAtk(Fighter target) {
	target.atk += target.baseAtk * 1.5;
	target.speSkill.atkChange.buffDuration = target.speSkill.atkChange.buffDurationMax;
}

//target gets an atk debuff
void debuffAtk(Fighter target) {
	target.atk -= target.baseAtk * 1.5;
	target.speSkill.atkChange.debuffDuration = target.speSkill.atkChange.debuffDurationMax;
}

//target gets a def buff
void buffDef(Fighter target){
	target.def += target.baseDef * 1.6;
	target.speSkill.defChange.buffDuration = target.speSkill.defChange.buffDurationMax;
}

//target gets a def debuff
void debuffDef(Fighter target){
	target.def -= target.baseDef * 1.75;
	target.speSkill.defChange.debuffDuration = target.speSkill.defChange.debuffDurationMax;
}

//target gets a spd buff
void buffSpd(Fighter target){
	target.spd += target.baseSpd * 1.3;
	target.speSkill.spdChange.buffDuration = target.speSkill.spdChange.buffDurationMax; 
}

//target gets a spd debuff
void debuffSpd(Fighter target){
	target.spd -= target.baseSpd * 1.3;
	target.speSkill.spdChange.debuffDuration = target.speSkill.spdChange.debuffDurationMax ;
}

//target gets an agi buff
void buffAgi(Fighter target){
	target.agi += target.baseAgi + 50;
	target.speSkill.agiChange.buffDuration = target.speSkill.spdChange.buffDurationMax;
}

//target gets an atkbar buff
void buffAtkBar(Fighter caster, Fighter target) {
	target.atkBar += caster.speSkill.atkBarValue;
}

//target gets an atkbar debuff
void debuffAtkBar(Fighter caster, Fighter target) {
	target.atkBar -= caster.speSkill.atkBarValue;
	if (target.atkBar < 0) {
		target.atkBar = 0;
	}
}

//returns the fighter alive with the least hp remaining
Fighter minHp(Team team) {
	Fighter min = team[0];
	for (int i = 1 ; i < 4 ; i++) {
		if (min.hp == 0) {
			min = team[i];
		}
	}
	int i;
	for (int j = i ; j < 4 ; j++) {
		if ((min.hp > team[j].hp) && (team[i].hp > 0)) {
			min = team[j];
		}
	}
	return min;
}

//change ally's stats
void effectAllySt(Fighter caster, Fighter target) {
	if (caster.speSkill.heal == 1) {
		heal(caster, target);
	}
	if (caster.speSkill.atkChange.change == 1){
		buffAtk(target);
	}
	if (caster.speSkill.defChange.change == 1){
		buffDef(target);
	}
	if (caster.speSkill.spdChange.change == 1){
		buffSpd(target);
	}
	if (caster.speSkill.agiChange.change == 1){
		buffAgi(target);
	}
	if (caster.speSkill.atkBarChange == 1) {
		buffAtkBar(caster, target);
	}
}

//change allies' stats
void effectAllyAoE(Fighter caster, Team team) {
	effectAllySt(caster, caster);
	if (team[0].hp > 0) {
		effectAllySt(caster, team[0]);
	}
	if (team[1].hp > 0) {
		effectAllySt(caster, team[1]);
	}
	if (team[2].hp > 0) {
		effectAllySt(caster, team[2]);
	}
	if (team[3].hp > 0) {
		effectAllySt(caster, team[3]);
	}
}

//change enemy's stats
void effectEnemy(Fighter caster, Fighter target) {
	if (caster.speSkill.atkChange.change == 2){
		debuffAtk(target);
	}
	if (caster.speSkill.defChange.change == 2){
		debuffDef(target);
	}
	if (caster.speSkill.spdChange.change == 2){
		debuffSpd(target);
	}
	if (caster.speSkill.atkBarChange == 2) {
		debuffAtkBar(caster, target);
	}
}

//returns 0 if caster's special attack against enemy went well, 1 if not
int atkSpeSt(Fighter caster, Fighter enemy) {
	int valid = 1;
	if (enemy.hp <= 0) {
		printf("La cible est morte \n");
		return valid;
	}
	enemy.hp -= caster.atk * (caster.speSkill.multi / 100) - enemy.def;
	if (caster.speSkill.effect == 1) {
		if (caster.speSkill.target == 0) {
			if (caster.speSkill.AoEBuff == 0) {
				effectAllySt(caster, caster);
			}
		}
		else {
			effectEnemy(caster, enemy);
		}
	}
	valid = 0;
	return valid;
}

//caster's special attack against opponent team
void atkSpeAoE(Fighter caster, Team team) {
	if (team[0].hp > 0) {
		atkSpeSt(caster, team[0]);
	}
	if (team[1].hp > 0) {
		atkSpeSt(caster, team[1]);
	}
	if (team[2].hp > 0) {
		atkSpeSt(caster, team[2]);
	}
	if (team[3].hp > 0) {
		atkSpeSt(caster, team[3]);
	}
}

//caster's special attack
void atkSpe(Fighter caster, Team team) {
	int valid = 1, target = 0;
	if (caster.speSkill.AoE == 0) {
		while (valid != 0) {
			while (target < 1 || target > 4) {
				printf("Sélectionner cible \n1 \n2 \n3 \n4 \n");
				scanf("%d", &target);
			}
			if (target == 1) {
				valid = atkSpeSt(caster, team[0]);
			}
			if (target == 2) {
				valid = atkSpeSt(caster, team[1]);
			}
			if (target == 3) {
				valid = atkSpeSt(caster, team[2]);
			}
			if (target == 4) {
				valid = atkSpeSt(caster, team[3]);
			}
		}
	}
	else {
		atkSpeAoE(caster, team);
	}
}

//returns 0 if the caster's special attack against enemy went well, 1 if not, normal difficulty
int atkSpeNormalSt(Fighter caster, Fighter enemy) {
	int valid = 1;
	if (enemy.hp <= 0) {
		return valid;
	}
	enemy.hp -= caster.atk * (caster.speSkill.multi / 100) - enemy.def;
	if (caster.speSkill.effect == 1) {
		if (caster.speSkill.target == 0) {
			if (caster.speSkill.AoEBuff == 0) {
				effectAllySt(caster, caster);
			}
		}
		else {
			effectEnemy(caster, enemy);
		}
	}
	valid = 0;
	return valid;
}

//caster's special attack against opponent team
void atkSpeNormalAoE(Fighter caster, Team team) {
	atkSpeNormalSt(caster, team[0]);
	atkSpeNormalSt(caster, team[1]);
	atkSpeNormalSt(caster, team[2]);
	atkSpeNormalSt(caster, team[3]);
}

//caster's special attack, normal difficulty
void atkSpeNormal(Fighter caster, Team team) {
	int valid = 1, target = 0;
	if (caster.speSkill.AoE == 0) {
		while (valid != 0) {
			srand(time(NULL));
			target = rand() % 3 + 1;
			if (target == 1) {
				valid = atkSpeNormalSt(caster, team[0]);
			}
			if (target == 2) {
				valid = atkSpeNormalSt(caster, team[1]);
			}
			if (target == 3) {
				valid = atkSpeNormalSt(caster, team[2]); 
			}
			if (target == 4) {
				valid = atkSpeNormalSt(caster, team[3]);
			}
		}
	}
	else {
		atkSpeNormalAoE(caster, team);
	}
}

//caster's special attack against enemy, hard difficulty
void atkSpeDifficileSt(Fighter caster, Fighter enemy) {
	enemy.hp -= caster.atk * (caster.speSkill.multi / 100) - enemy.def;
	if (caster.speSkill.effect == 1) {
		if (caster.speSkill.target == 0) {
			if (caster.speSkill.AoEBuff == 0) {
				effectAllySt(caster, caster);
			}
		}
		else {
			effectEnemy(caster, enemy);
		}
	}
}

//special skill form caster on enemy team, hard difficulty
void atkSpeDifficileAoE(Fighter caster, Team team) {
	if (team[0].hp > 0) {
		atkSpeDifficileSt(caster, team[0]);
	}
	if (team[1].hp > 0) {
		atkSpeDifficileSt(caster, team[1]);
	}
	if (team[2].hp > 0) {
		atkSpeDifficileSt(caster, team[2]);
	}
	if (team[3].hp > 0) {
		atkSpeDifficileSt(caster, team[3]);
	}
}

//caster's special attack, hard difficulty
void atkSpeDifficile(Fighter caster, Team team) {
	if (caster.speSkill.AoE == 0 {
		atkSpeDifficileSt(caster, minHp(team));
	}
	else {
		atkSpeDifficileAoE(caster, team);
	}
}

//caster's turn
void turn(Fighter caster, Team team1, Team team2) {
	int atkType = 0, valid = 1;
	while (valid != 0) {
		while (atkType < 1 || atkType > 2) {
		printf("Sélectionner attaque \n1 : Attaque Basique \n 2 : Attaque Spéciale \n");
		scanf("%d", &atkType);
		}
		if (atkType == 2) {
			if (caster.speSkill.cd <= 0) {
				valid = 0;
			}
			else {
				printf("Attaque Spéciale en cooldown \n");
			}
		}
		else {
			valid = 0;
		}
	}
	if (atkType == 1) {
		atk(caster, team2);
	}
	else {
		atkSpe(caster, team2);
		if (caster.speSkill.effect == 1) {
			if (caster.speSkill.target == 0) {
				if (caster.speSkill.AoEBuff == 1) {
					effectAllyAoE(caster, team1);
				}
			}
		}
		caster.speSkill.cd = caster.speSkill.cdMax;
	}
	caster.speSkill.cd -= 1;
	caster.speSkill.atkChange.buffDuration -= 1;
	if (caster.speSkill.atkChange.buffDuration == 0) {
		caster.atk -= caster.baseAtk * 1.5;
	}
	caster.speSkill.atkChange.debuffDuration -= 1;
	if (caster.speSkill.atkChange.debuffDuration == 0) {
		caster.atk += caster.baseAtk * 1.5;
	}
	caster.speSkill.defChange.buffDuration -= 1;
	if (caster.speSkill.defChange.buffDuration == 0) {
		caster.def -= caster.baseDef * 1.6;
	}
	caster.speSkill.defChange.debuffDuration -= 1;
	if (caster.speSkill.defChange.debuffDuration == 0) {
		caster.def += caster.baseDef * 1.75;
	}
	caster.speSkill.spdChange.buffDuration -= 1;
	if (caster.speSkill.spdChange.buffDuration == 0) {
		caster.spd -= caster.baseSpd * 1.3;
	}
	caster.speSkill.spdChange.debuffDuration -= 1;
	if (caster.speSkill.spdChange.debuffDuration == 0) {
		caster.spd += caster.baseSpd * 1.3;
	}
	caster.speSkill.agiChange.buffDuration -= 1;
	if (caster.speSkill.agiChange.buffDuration == 0) {
		caster.agi -= 50;
	}
}

//caster's turn, noob difficulty
void turnNoob(Fighter caster, Team team) {
	atkNoob(caster, team); 
}

//caster's turn, normal difficulty
void turnNormal(Fighter caster, Team team1, Team team2) {
	int atkType = 0, valid = 1;
	while(valid != 0) {
		srand(time(NULL));
		atkType = rand()%1 + 1;
		if (atkType == 2) {
			if (caster.speSkill.cd <= 0) {
				valid = 0;
			}
		}
		else {
			valid = 0;
		}
	}
	if (atkType == 1) {
		atkNoob(caster, team2);
	}
	else {
		atkSpeNormal(caster, team2);
		if (caster.speSkill.effect == 1) {
			if (caster.speSkill.target == 0) {
				if (caster.speSkill.AoEBuff == 1) {
					effectAllyAoE(caster, team1);
				}
			}
		}
		caster.speSkill.cd = caster.speSkill.cdMax;
	}
	caster.speSkill.cd -= 1;
	caster.speSkill.atkChange.buffDuration -= 1;
	if (caster.speSkill.atkChange.buffDuration == 0) {
		caster.atk -= caster.baseAtk * 1.5;
	}
	caster.speSkill.atkChange.debuffDuration -= 1;
	if (caster.speSkill.atkChange.debuffDuration == 0) {
		caster.atk += caster.baseAtk * 1.5;
	}
	caster.speSkill.defChange.buffDuration -= 1;
	if (caster.speSkill.defChange.buffDuration == 0) {
		caster.def -= caster.baseDef * 1.6;
	}
	caster.speSkill.defChange.debuffDuration -= 1;
	if (caster.speSkill.defChange.debuffDuration == 0) {
		caster.def += caster.baseDef * 1.75;
	}
	caster.speSkill.spdChange.buffDuration -= 1;
	if (caster.speSkill.spdChange.buffDuration == 0) {
		caster.spd -= caster.baseSpd * 1.3;
	}
	caster.speSkill.spdChange.debuffDuration -= 1;
	if (caster.speSkill.spdChange.debuffDuration == 0) {
		caster.spd += caster.baseSpd * 1.3;
	}
	caster.speSkill.agiChange.buffDuration -= 1;
	if (caster.speSkill.agiChange.buffDuration == 0) {
		caster.agi -= 50;
	}
}

//caster's turn, hard difficulty
void turnDifficile(Fighter caster, Team team1, Team team2) {
	int atkType = 0;
	if (caster.speSkill.cd <= 0) {
		atkType = 2;
	}
	else {
		atkType = 1;
	}
	if (atkType == 1) {
		atkDifficile(caster, team2);
	}
	else {
		atkSpeDifficile(caster, team2) 
		if (caster.speSkill.effect == 1) {
			if (caster.speSkill.target == 0) {
				if (caster.speSkill.AoEBuff == 1) {
					effectAllyAoE(caster, team1);
				}
			}
		}
		caster.speSkill.cd = caster.speSkill.cdMax;
	}
	caster.speSkill.cd -= 1;
	caster.speSkill.atkChange.buffDuration -= 1;
	if (caster.speSkill.atkChange.buffDuration == 0) {
		caster.atk -= caster.baseAtk * 1.5;
	}
	caster.speSkill.atkChange.debuffDuration -= 1;
	if (caster.speSkill.atkChange.debuffDuration == 0) {
		caster.atk += caster.baseAtk * 1.5;
	}
	caster.speSkill.defChange.buffDuration -= 1;
	if (caster.speSkill.defChange.buffDuration == 0) {
		caster.def -= caster.baseDef * 1.6;
	}
	caster.speSkill.defChange.debuffDuration -= 1;
	if (caster.speSkill.defChange.debuffDuration == 0) {
		caster.def += caster.baseDef * 1.75;
	}
	caster.speSkill.spdChange.buffDuration -= 1;
	if (caster.speSkill.spdChange.buffDuration == 0) {
		caster.spd -= caster.baseSpd * 1.3;
	}
	caster.speSkill.spdChange.debuffDuration -= 1;
	if (caster.speSkill.spdChange.debuffDuration == 0) {
		caster.spd += caster.baseSpd * 1.3;
	}
	caster.speSkill.agiChange.buffDuration -= 1;
	if (caster.speSkill.agiChange.buffDuration == 0) {
		caster.agi -= 50;
	}
}

//return team's fighter with the highest atkbar
Fighter atkBarMaxTeam(Team team) {
	Fighter max = team[0];
	for (int i = 1 ; i < 4 ; i++) {
		if (max.atkBar <= team[i].atkBar) {
			max = team[i];
		}
	}
	return max;
}

//increases each team's fighters' atkbar depending of their speed until at least one fighter has an atkbar higher than 100
void turnOrder(Team team1, Team team2) {
	while (team1[0].atkBar < 100 && team1[1].atkBar < 100 && team1[2].atkBar < 100 && team1[3].atkBar < 100 && team2[0].atkBar < 100 && team2[1].atkBar < 100 && team2[2].atkBar < 100 && team2[3].atkBar < 100) {
		for (int i = 0 ; i < 4 ; i++){
			team1[i].atkBar += team1[i].spd / 100;
			team2[i].atkBar += team2[i].spd / 100;
		}
	}
}

//fight of team1 against team2
Team fight(Team team1, Team team2) {
	Fighter maxTeam1, maxTeam2;
	while ((team1[0].hp <= 0 && team1[1].hp <= 0 && team1[2].hp <= 0 && team1[3].hp <= 0)||(team2[0].hp <= 0 && team2[1].hp <= 0 && team2[2].hp <= 0 && team2[3].hp <= 0)) {
		turnOrder(team1, team2);
		maxTeam1 = atkBarMaxTeam(team1);
		maxTeam2 = atkBarMaxTeam(team2);
		if (maxTeam1.atkBar > maxTeam2.atkBar) {
			maxTeam1.atkBar = 0;
			turn(maxTeam1, team1[0], team1[1], team1[2], team1[3], team2[0], team2[1], team2[2], team2[3]);
		}
		else {
			maxTeam2.atkBar = 0;
			turn(maxTeam2, team2[0], team2[1], team2[2], team2[3], team1[0], team1[1], team1[2], team1[3]);
		}	
	}
}

//fight of team1 against team2, team2 being controlled by a noob difficulty IA
Team fightNoob(Team team1, Team team2) {
	Fighter maxTeam1, maxTeam2;
	while ((team1[0].hp <= 0 && team1[1].hp <= 0 && team1[2].hp <= 0 && team1[3].hp <= 0)||(team2[0].hp <= 0 && team2[1].hp <= 0 && team2[2].hp <= 0 && team2[3].hp <= 0)) {
		turnOrder(team1, team2);
		maxTeam1 = atkBarMaxTeam(team1);
		maxTeam2 = atkBarMaxTeam(team2);
		if (maxTeam1.atkBar > maxTeam2.atkBar) {
			maxTeam1.atkBar = 0;
			turn(maxTeam1, team1[0], team1[1], team1[2], team1[3], team2[0], team2[1], team2[2], team2[3]);
		}
		else {
			maxTeam2.atkBar = 0;
			turnNoob(maxTeam2, team2[0], team2[1], team2[2], team2[3], team1[0], team1[1], team1[2], team1[3]);
		}	
	}
}

//fight of team1 against team2, team2 being controlled by a normal difficulty IA
Team fightNormal(Team team1, Team team2) {
	Fighter maxTeam1, maxTeam2;
	while ((team1[0].hp <= 0 && team1[1].hp <= 0 && team1[2].hp <= 0 && team1[3].hp <= 0)||(team2[0].hp <= 0 && team2[1].hp <= 0 && team2[2].hp <= 0 && team2[3].hp <= 0)) {
		turnOrder(team1, team2);
		maxTeam1 = atkBarMaxTeam(team1);
		maxTeam2 = atkBarMaxTeam(team2);
		if (maxTeam1.atkBar > maxTeam2.atkBar) {
			maxTeam1.atkBar = 0;
			turn(maxTeam1, team1[0], team1[1], team1[2], team1[3], team2[0], team2[1], team2[2], team2[3]);
		}
		else {
			maxTeam2.atkBar = 0;
			turnNormal(maxTeam2, team2[0], team2[1], team2[2], team2[3], team1[0], team1[1], team1[2], team1[3]);
		}	
	}
}

//fight of team1 against team2, team2 being controlled by a hard difficulty IA
Team fightDifficile(Team team1, Team team2) {
	Fighter maxTeam1, maxTeam2;
	while ((team1[0].hp <= 0 && team1[1].hp <= 0 && team1[2].hp <= 0 && team1[3].hp <= 0)||(team2[0].hp <= 0 && team2[1].hp <= 0 && team2[2].hp <= 0 && team2[3].hp <= 0)) {
		turnOrder(team1, team2);
		maxTeam1 = atkBarMaxTeam(team1);
		maxTeam2 = atkBarMaxTeam(team2);
		if (maxTeam1.atkBar > maxTeam2.atkBar) {
			maxTeam1.atkBar = 0;
			turn(maxTeam1, team1[0], team1[1], team1[2], team1[3], team2[0], team2[1], team2[2], team2[3]);
		}
		else {
			maxTeam2.atkBar = 0;
			turnDifficile(maxTeam2, team2[0], team2[1], team2[2], team2[3], team1[0], team1[1], team1[2], team1[3]);
		}	
	}
}

