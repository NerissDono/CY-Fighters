#include "functions.c"
#include "turn.c"

void main(){
	Team t1,t2;
	Fighter f1,f2,f3,f4,f5,f6,f7,f8;
	Skill skill1, skill2, skill3, skill4, skill5, skill6, skill7, skill8;
	StatChange atkChange1, atkChange2, atkChange3, atkChange4, atkChange5, atkChange6, atkChange7,atkChange8;
	StatChange defChange1,  defChange2,  defChange3,  defChange4,  defChange5,  defChange6,  defChange7,  defChange8;
	StatChange spdChange1, spdChange2, spdChange3, spdChange4, spdChange5, spdChange6, spdChange7, spdChange8;
	StatChange agiChange1, agiChange2, agiChange3, agiChange4, agiChange5, agiChange6, agiChange7, agiChange8;
	FILE * ft1 = fopen("team1.txt", "r");
	FILE * ft2 = fopen("team2.txt", "r");
	getTeam(ft1, t1, f1, f2, f3, f4, skill1, skill2, skill3, skill4, atkChange1,defChange1, spdChange1, agiChange1 ); 
	getTeam(ft2, t2, f5, f6, f7, f8, skill5, skill6, skill7, skill8, atkChange2,defChange2, spdChange2, agiChange2);
	int mode = 0, difficulty = 0;
	while(mode < 1 || mode > 2) {
		printf("Sélectionner le mode de jeu : \n1 : Joueur VS Joueur \n2 : Joueur VS IA \n");
		scanf("%d", &mode);
	}
	if (mode == 0) {
		printf("%s remporte le combat", fight(t1,t2).teamname);
	}
	else {
		while (difficulty < 1 || difficulty > 3) {
			printf("Sélectionner la difficulté : \n1 : Noob \n2 : Normal \n3 : Difficile \n");
			scanf("%d", &difficulty);
		}
		if (difficulty == 1) {
			printf("%s remporte le combat", fightNoob(t1,t2).teamname);
		}
		else if (difficulty == 2) {
			printf("%s remporte le combat", fightNormal(t1,t2).teamname);
		}
		else {
			printf("%s remporte le combat", fightDifficile(t1,t2).teamname);
		}
	}
}