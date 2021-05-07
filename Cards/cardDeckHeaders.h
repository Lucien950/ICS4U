#ifndef CODE_CARDDECKHEADERS_H
#define CODE_CARDDECKHEADERS_H

class DeckOfCards{
public:
    Card *deck;
    int currentCard;
    const int SIZE_OF_DECK;

    explicit DeckOfCards(Card[], int deckSize);
    DeckOfCards();
    void shuffle() const;

    Card dealCard();
    bool moreCards() const;
};

#endif //CODE_CARDDECKHEADERS_H
