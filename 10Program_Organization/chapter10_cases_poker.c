/********************************************************************************
* @author: mason shi
* @date: 2023/7/9 22:09
* @version: 1.0
* @description: 手牌分类案例
********************************************************************************/
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

#define NUM_RANKS 13
#define NUM_SITE 4
#define NUM_CARDS 5

/*external variables*/
int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SITE];
bool straight, flush, four, three;
int pairs;

/*prototypes*/
void read_cards(void);

void analyze_hands(void);

void print_result(void);

/**
 * main:Calls read_cards,analyze_hand,and print_result
 * @return
 */
//int main(void) {
//    for (;;) {
//        read_cards();
//        analyze_hands();
//        print_result();
//    }
//
//}


/**
 * read_cards: Reads the cards into the external variable num_in_rank and
 *             num_in_suit;checks for bad cards and duplicate cards.
 */
void read_cards() {
    bool card_exists[NUM_RANKS][NUM_SITE];
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;
    for (rank = 0; rank < NUM_RANKS; rank++) {
        num_in_rank[rank] = 0;
        for (suit = 0; suit < NUM_SITE; suit++) {
            card_exists[rank][suit] = false;

        }
    }
    for (suit = 0; suit < NUM_SITE; suit++)
        num_in_suit[suit] = 0;
    while (cards_read < NUM_CARDS) {
        rank_ch = getchar();
        switch (rank_ch) {
            case '0':
                exit(EXIT_SUCCESS);
            case '2':
                rank = 0;
                break;
            case '3':
                rank = 1;
                break;
            case '4':
                rank = 2;
                break;
            case '5':
                rank = 3;
                break;
            case '6':
                rank = 4;
                break;
            case '7':
                rank = 5;
                break;
            case '8':
                rank = 6;
                break;
            case '9':
                rank = 7;
                break;
            case 't':
            case 'T':
                rank = 8;
                break;
            case 'j':
            case 'J':
                rank = 9;
                break;
            case 'q':
            case 'Q':
                rank = 10;
                break;
            case 'k':
            case 'K':
                rank = 11;
                break;
            case 'a':
            case 'A':
                rank = 12;
                break;
            default:
                bad_card = true;
        }
        suit_ch = getchar();
        switch (suit_ch) {
            case 'c':
            case 'C':
                suit = 0;
                break;
            case 'd':
            case 'D':
                suit = 1;
                break;
            case 'h':
            case 'H':
                suit = 2;
                break;
            case 's':
            case 'S':
                suit = 3;
                break;
            default:
                bad_card = true;

        }
        while ((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;

        if (bad_card)
            printf("Bad card; ignored.\n");
        else if (card_exists[rank][suit])
            printf("Duplicate card;ignored.\n");
        else {
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            card_exists[rank][suit] = true;
            cards_read++;

        }
    }
}


/**
 * analyze_hands:Determines whether the hand contains
 * a straight,a flush,four-of-a-kind,and/or three-of-a-kind;
 * determines the number of pairs; stores the results into
 * the external variables straight,flush,
 * four,three,and pairs.
 */
void analyze_hands() {
    int num_consec = 0;
    int rank, suit;
    straight = false;
    four = false;
    three = false;
    pairs = 0;
    /*check for flush*/
    for (suit = 0; suit < NUM_SITE; suit++)
        if (num_in_suit[suit] == NUM_CARDS)
            flush = true;
    /*check for straight*/
    rank = 0;
    while (num_in_rank[rank] == 0) rank++;
    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
        num_consec++;
    if (num_consec == NUM_CARDS) {
        straight = true;
        return;
    }
    /*check for 4-of-a-kind,3-of-a-kind,and pairs*/
    for (rank = 0; rank < NUM_RANKS; rank++) {
        if (num_in_rank[rank] == 4) four = true;
        if (num_in_rank[rank] == 3) three = true;
        if (num_in_rank[rank] == 2) pairs++;

    }

}

/**
 * print_result:prints the classification of the hand,based on the values the external
 * variables straight,flush,four,three,and pairs.
 */
void print_result() {
    if (straight && flush) printf("Straight flush");
    else if (four) printf("Four of a kind");
    else if (three && pairs == 1) printf("Full house");
    else if (flush) printf("Flush");
    else if (straight) printf("Straight");
    else if (three) printf("Three of kind");
    else if (pairs = 2) printf("two pairs");
    else if (pairs = 1) printf("pair");
    else printf("High card");
    printf("\n");
}







