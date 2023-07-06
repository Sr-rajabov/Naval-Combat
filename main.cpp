#include "Battle.h"

int main() {
    Battlefield field(12,24);
    field.print();
    auto * player1 = new Player;
    auto * player2 = new Player;
    cout << player1->getName() << " deploy your one-deck ships!\n";
    field.print();
    player1->deploy(field, ONE_DECK, one_deck);
    cout << player1->getName() << " deploy your two-deck ships!\n";
    player1->deploy(field, TWO_DECK, two_deck);
    cout << player1->getName() << " deploy your three-deck ships!\n";
    player1->deploy(field, THREE_DECK, three_deck);
    cout << player1->getName() << " deploy your four-deck ship!\n";
    player1->deploy(field, FOUR_DECK, four_deck);
    field.print();
    cout << player2->getName() << " deploy your one-deck ships!\n";
    player2->deploy(field, ONE_DECK, one_deck);
    cout << player2->getName() << " deploy your two-deck ships!\n";
    player2->deploy(field, TWO_DECK, two_deck);
    cout << player2->getName() << " deploy your three-deck ships!\n";
    player2->deploy(field, THREE_DECK, three_deck);
    cout << player2->getName() << " deploy your four-deck ship!\n";
    player2->deploy(field, FOUR_DECK, four_deck);
    cout << "The shootout has begun!\n";
    Battlefield cover_field(12,24);
    cover_field.print();
    Battle(field, cover_field, player1, player2);
    cout << newline << "Well played!\n";
    return 0;
}
