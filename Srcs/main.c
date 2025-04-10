#include "game.h"

/*
 * Le jeu de base doit s'arrêter automatiquement en cas de "bust" (score > 21)
 * ou lorsque le joueur décide de rester.
 */

void print_menu() {
    printf("=== Blackjack CLI ===\n");
    printf("1. Tirer une carte (Hit)\n");
    printf("2. Rester (Stand)\n");
    printf("0. Quitter\n");
    printf("Votre choix: ");
}

int main() {
    Game game;
    int choice;

    // Initialisation du jeu de base
    init_game(&game);
    display_game(&game);

    do {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Entrée invalide, veuillez entrer un chiffre.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                    player_hit(&game);
            display_game(&game);
            if (compute_score(game.player_cards, game.player_card_count) > 21) {
                printf("\n>>> 🚫 BUSTED : Vous avez dépassé 21 ! Vous avez perdu.\n");
                choice = 0;
            }
            break;
            case 2:
                dealer_play(&game);
            display_game(&game);
            // TODO: Comparer les scores du joueur et du croupier pour déterminer le gagnant du jeu de base
            // TODO: Afficher un message de victoire/défaite en fonction du résultat
            choice = 0;  // Fin de la partie après que le joueur a choisi de rester
            break;
            case 0:
                printf("Merci d'avoir joué.\n");
            break;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
            // TODO: Proposer de redemander le choix si l'entrée est invalide
        }
    } while (choice != 0);

    // TODO: Ajouter une option pour redémarrer une nouvelle partie de Blackjack
    return 0;
}
