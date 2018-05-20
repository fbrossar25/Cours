#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#include "fa.h"

static struct fa fsm;

void destroy_fsm()
{
	fa_destroy(&fsm);
	if(!fa_is_empty(&fsm))
	{
		fprintf(stderr, "Echec de la destruction de l'automate.\n");
		exit(EXIT_FAILURE);
	}
}

void choice_destroy()
{
	printf("\nDestruction de l'automate...\n");
	destroy_fsm();
	printf("Automate detruit avec succes.\n");
}

void choice_exit()
{
	if(!fa_is_empty(&fsm)) choice_destroy();
	exit(EXIT_SUCCESS);
}

void choice_create()
{
	if(!fa_is_empty(&fsm))
	{
		char c;
		printf("\nAutomate deja cree. Suppression requise, continuer [o/n] ? ");
		scanf("%c",&c);
		getchar();
		if(c == 'n' || c == 'N')
		{
			printf("\nCreation interrompue, automate non detruit.\n");
			return;
		}
		else if(c == 'o' || c == 'O')
		{
			choice_destroy();
		}
		else
		{
			printf("\nSaisie invalide, automate non detruit.\n");
			return;
		}
	}
	size_t nb_etats, nb_lettres;
	printf("\nNombre de d'etats : ");
	scanf("%zu",&nb_etats);
	getchar();
	printf("\nNombre de de lettres : ");
	scanf("%zu",&nb_lettres);
	getchar();
	printf("\nCreation de l'automate...\n");
	fa_create(&fsm, nb_lettres, nb_etats);
	if(fa_is_empty(&fsm))
	{
		fprintf(stderr, "Erreur lors de la creation de l'automate.\n");
		exit(EXIT_FAILURE);
	}
	printf("Automate cree avec succes.\n");
}

void choice_create_example()
{
	if(!fa_is_empty(&fsm))
	{
		char c;
		printf("\nAutomate deja cree. Suppression requise, continuer [o/n] ? ");
		scanf("%c",&c);
		getchar();
		if(c == 'n' || c == 'N')
		{
			printf("\nCreation interrompue, automate non detruit.\n");
			return;
		}
		else if(c == 'o' || c == 'O')
		{
			choice_destroy();
		}
		else
		{
			printf("\nSaisie invalide, automate non detruit.\n");
			return;
		}
	}
	printf("\nCreation de l'automate...\n");
	fa_create(&fsm, 2, 5);
	fa_set_state_initial(&fsm,0);
	fa_set_state_initial(&fsm,1);
	fa_set_state_final(&fsm,1);
	fa_set_state_final(&fsm,4);
	fa_add_transition(&fsm,0,'a',1);
	fa_add_transition(&fsm,0,'a',2);
	fa_add_transition(&fsm,0,'a',3);
	fa_add_transition(&fsm,1,'b',3);
	fa_add_transition(&fsm,2,'a',3);
	fa_add_transition(&fsm,2,'b',4);
	fa_add_transition(&fsm,3,'a',3);
	fa_add_transition(&fsm,3,'b',4);
	fa_add_transition(&fsm,4,'a',4);
	if(fa_is_empty(&fsm))
	{
		fprintf(stderr, "\nErreur lors de la creation de l'automate\n");
		exit(EXIT_FAILURE);
	}
	printf("\nAutomate cree avec succes\n");	
}

void choice_define_state_property()
{
	char c;
	size_t state;
	printf("\nEtat a definir : ");
	scanf("%zu",&state);
	getchar();
	if(state >= fsm.state_count)
	{
		printf("Etat inexistant.\n");
		return;
	}
	printf("\nEtat initial [o/n] ? ");
	scanf("%c",&c);
	getchar();
	if(c != 'o' && c != 'O' && c != 'n' && c != 'N')
	{
		printf("\nErreur de saisie.\n");
		return;
	}
	if(c == 'o' || c == 'O') fa_set_state_initial(&fsm,state);
	else fa_unset_state_initial(&fsm,state);
	printf("\nEtat final [o/n] ? ");
	scanf("%c",&c);
	getchar();
	if(c != 'o' && c != 'O' && c != 'n' && c != 'N')
	{
		printf("\nErreur de saisie.\n");
		return;
	}
	if(c == 'o' || c == 'O') fa_set_state_final(&fsm,state);
	else fa_unset_state_final(&fsm,state);
	printf("\nDefinition terminee.\n");
}

void choice_add_transition()
{
	size_t from, to;
	char alpha;
	printf("\nEtat de depart : ");
	scanf("%zu",&from);
	getchar();
	if(fsm.state_count <= from)
	{
		printf("\nSaisie de l'etat de depart invalide.\n");
		return;
	}
	printf("\nLettre : ");
	scanf("%c",&alpha);
	getchar();
	if(fsm.alpha_count <= (size_t)(alpha - 'a'))
	{
		printf("\nSaisie de la lettre invalide.\n");
		return;
	}
	printf("\nEtat d'arrive : ");
	scanf("%zu",&to);
	getchar();
	if(fsm.state_count <= to)
	{
		printf("\nSaisie de l'etat d'arrive invalide.\n");
		return;
	}
	printf("\nAjout de la transition...\n");
	fa_add_transition(&fsm,from,alpha,to);
	if(state_set_search(&(fsm.transitions[from][(size_t)(alpha-'a')]), to) >= state_set_size(&(fsm.transitions[from][(size_t)(alpha-'a')])))
	{
		fprintf(stderr, "Erreur lors de la creation de la transition.\n");
		destroy_fsm();
		exit(EXIT_FAILURE);
	}
	printf("Transition creee avec succes.\n");
}

void choice_remove_transition()
{
	size_t from, to;
	char alpha;
	printf("\nEtat de depart : ");
	scanf("%zu",&from);
	getchar();
	if(from >= fsm.state_count)
	{
		printf("\nSaisie de l'etat de depart invalide.\n");
		return;
	}
	printf("\nLettre : ");
	scanf("%c",&alpha);
	getchar();
	if((size_t)(alpha - 'a') >= fsm.alpha_count)
	{
		printf("\nSaisie de la lettre invalide.\n");
		return;
	}
	printf("\nEtat d'arrive : ");
	scanf("%zu",&to);
	getchar();
	if(to >= fsm.state_count)
	{
		printf("\nSaisie de l'etat d'arrive invalide.\n");
		return;
	}
	if(state_set_search(&(fsm.transitions[from][(size_t)(alpha-'a')]), to) >= state_set_size(&(fsm.transitions[from][(size_t)(alpha-'a')])))
	{
		printf("\nTransition inexistante.\n");
		return;
	}
	printf("\nSuppression de la transition...\n");
	fa_remove_transition(&fsm,from,alpha,to);
	if(state_set_search(&(fsm.transitions[from][(size_t)(alpha-'a')]), to) < state_set_size(&(fsm.transitions[from][(size_t)(alpha-'a')])))
	{
		fprintf(stderr, "Erreur lors de la suppression de la transition.\n");
		destroy_fsm();
		exit(EXIT_FAILURE);
	}
	printf("Transition supprimee avec succes.\n");
}

void choice_merge_states()
{
	size_t s1, s2;
	printf("\nEtat 1 : ");
	scanf("%zu",&s1);
	getchar();
	size_t state_count = fsm.state_count;
	if(s1 >= state_count)
	{
		printf("Etat inexistant(%zu >= %zu).\n",s2,state_count);
		return;
	}
	printf("\nEtat 2 : ");
	scanf("%zu",&s2);
	getchar();
	if(s2 >= state_count)
	{
		printf("Etat inexistant(%zu >= %zu).\n",s2,state_count);
		return;
	}
	printf("\nFusion des etats...\n");
	fa_merge_states(&fsm,s1,s2);
	if(state_count != fsm.state_count + 1)
	{
		fprintf(stderr, "Erreur lors de la fusion des etats\n");
		destroy_fsm();
		exit(EXIT_FAILURE);
	}
	printf("\nEtats fusionnes avec succes.\n");
}

void choice_remove_state()
{
	size_t target;
	printf("\nEtat cible : ");
	scanf("%zu",&target);
	getchar();
	size_t state_count = fsm.state_count;
	if(target >= state_count)
	{
		printf("\nEtat inexistant.\n");
	}
	printf("\nSuppression de l'etat...\n");
	fa_remove_state(&fsm,target);
	if(state_count != fsm.state_count + 1)
	{
		fprintf(stderr, "Erreur lors de la suppression de l'etat.\n");
		destroy_fsm();
		exit(EXIT_FAILURE);
	}
	printf("Etat supprime avec succes.\n");
}

void choice_make_complete()
{
	if(fa_is_complete(&fsm))
	{
		printf("\nL'automate est deja complet.\n");
		return;
	}
	printf("\nCompletion de l'automate...\n");
	fa_make_complete(&fsm);
	if(!fa_is_complete(&fsm))
	{
		fprintf(stderr, "Erreur durant la completion de l'automate.\n");
		exit(EXIT_FAILURE);
	}
	printf("Completion terminee avec succes.\n");
}

void choice_export_graphviz()
{
	char *filename = "fsm.gv";
	printf("\nLe fichier seras sauvegarde dans le dossier de l'executable sous le nom de '%s'.\n",filename);
	FILE *out = fopen(filename,"w+");
	if(out == NULL)
	{
		fprintf(stderr, "Ouverture du fichier '%s' impossible.\n",filename);
		destroy_fsm();
		exit(EXIT_FAILURE);
	}
	printf("\nExportation en cours...\n");
	fa_dot_print(&fsm,out);
	printf("\nExportation terminee...\n");
	fclose(out);
}

void choice_export_png()
{
	printf("\nLe fichier seras sauvegarde dans le dossier de l'executable sous le nom de 'fsm.png'.\n");
	char c;
	printf("\nLe fichier 'fsm.gv' est requis, voulez-vous exporter l'automate au format graphviz [o/n] ? ");
	scanf("%c",&c);
	getchar();
	if(c == 'n' || c == 'N')
	{
		printf("\nExportation annule.\n");
		return;
	}
	else if(c == 'o' || c == 'O')
	{
		choice_export_graphviz();
	}
	else
	{
		printf("\nSaisie invalide, exportation annule.\n");
		return;
	}
	if(fork() == 0)
	{
		printf("Exportation en cours...\n");
		execlp("dot","dot","-Tpng","-ofsm.png","fsm.gv",NULL);
		fprintf(stderr, "Erreur lors de l'exportation avec le programme dot.\n");
		destroy_fsm();
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	printf("\nExportation terminee...\n");
}

void print_menu()
{
	printf("Choix :\n");
	printf("\t1) Creer automate\n");
	printf("\t2) Creer automate exemple\n");
	if(!fa_is_empty(&fsm)) printf("\t3) Definir proprietes d'un etat (final, initial)\n");
	if(!fa_is_empty(&fsm)) printf("\t4) Ajouter transition\n");
	if(!fa_is_empty(&fsm)) printf("\t5) Supprimer transition\n");
	if(!fa_is_empty(&fsm)) printf("\t6) Fusionner etat\n");
	if(!fa_is_empty(&fsm)) printf("\t7) Supprimer etat\n");
	if(!fa_is_empty(&fsm)) printf("\t8) Afficher automate\n");
	if(!fa_is_empty(&fsm)) printf("\t9) Automate deterministe ?\n");
	if(!fa_is_empty(&fsm)) printf("\t10) Automate complet ?\n");
	if(!fa_is_empty(&fsm)) printf("\t11) Completer l'automate\n");
	if(!fa_is_empty(&fsm)) printf("\t12) Detruire automate\n");
	if(!fa_is_empty(&fsm)) printf("\t13) Exporter automate au format graphviz\n");
	if(!fa_is_empty(&fsm)) printf("\t14) Exporter automate au format png\n");
	printf("\t0) Quitter\n");
	printf("Votre Choix ? ");
}

int main(int argc, char *argv[])
{
	size_t choix;
	while(1)
	{
		print_menu();
		scanf("%zu",&choix);
		getchar();
		printf("\n");
		switch(choix)
		{
			case 0:
			{
				choice_exit();
			}
			break;

			case 1:
			{
				choice_create();
			}
			break;

			case 2:
			{
				choice_create_example();
			}
			break;

			case 3:
			{
				choice_define_state_property();
			}
			break;

			case 4:
			{
				choice_add_transition();
			}
			break;

			case 5:
			{
				choice_remove_transition();
			}
			break;

			case 6:
			{
				choice_merge_states();
			}
			break;

			case 7:
			{
				choice_remove_state();
			}
			break;

			case 8:
			{
				fa_pretty_print(&fsm);
			}
			break;

			case 9:
			{
				printf("Automate %sdeterministe.\n",fa_is_deterministic(&fsm) ? "" : "non ");
			}
			break;

			case 10:
			{
				printf("Automate %scomplet.\n",fa_is_complete(&fsm) ? "" : "in");
			}
			break;

			case 11:
			{
				choice_make_complete();
			}
			break;

			case 12:
			{
				choice_destroy();
			}
			break;

			case 13:
			{
				choice_export_graphviz();
			}
			break;

			case 14:
			{
				choice_export_png();
			}
			break;

			default:
			{
				printf("\nChoix invalide.\n");
			}
		}
	}
	return EXIT_SUCCESS;
}

//execlp("dot","dot","-Tpng","-ofsm.png",filename,NULL);