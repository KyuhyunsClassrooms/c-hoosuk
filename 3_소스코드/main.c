#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    1. [설계]
*/
int playerTotal = 0;
int dealerTotal = 0;


/*
    2. 함수 선언
*/
int drawCard();            // 카드 뽑기
void playerTurn();         // 플레이어 턴
void dealerTurn();         // 딜러 턴
void checkWinner();        // 승패 판정


int main() {

    printf("--- C언어 미니 프로젝트 시작! ---\n");
    printf("====== 블랙잭 게임 (21 규칙) ======\n\n");

    srand(time(NULL)); // 랜덤 초기화

    playerTurn();
    dealerTurn();
    checkWinner();

    return 0;
}


/* -----------------------------
       기능 함수 구현부
--------------------------------*/

// 카드 뽑기 (1~11)
int drawCard() {
    return (rand() % 11) + 1;
}


// 플레이어 턴
void playerTurn() {
    int choice;

    printf("[플레이어 턴]\n");

    while (1) {
        int card = drawCard();
        playerTotal += card;

        printf("당신이 뽑은 카드: %d   | 현재 합: %d\n", card, playerTotal);

        // 21 초과 → 즉시 패배
        if (playerTotal > 21) {
            printf("Bust! (21 초과)\n");
            return;
        }

        printf("카드를 더 뽑습니까? (1: 계속 / 0: 그만): ");
        scanf("%d", &choice);

        if (choice == 0) break;
    }
}


// 딜러 턴
void dealerTurn() {

    printf("\n[딜러 턴]\n");

    while (dealerTotal < 17) {  
        int card = drawCard();
        dealerTotal += card;

        printf("딜러가 뽑은 카드: %d   | 현재 합: %d\n", card, dealerTotal);

        if (dealerTotal > 21) {
            printf("딜러 Bust! (21 초과)\n");
            return;
        }
    }
}


// 승자 판정
void checkWinner() {

    printf("\n======== 최종 결과 ========\n");
    printf("플레이어 합: %d\n", playerTotal);
    printf("딜러 합: %d\n\n", dealerTotal);

    // Bust 판정 먼저
    if (playerTotal > 21 && dealerTotal > 21) {
        printf("둘 다 Bust! 무승부!\n");
        return;
    }
    if (playerTotal > 21) {
        printf("플레이어 Bust → 딜러 승리!\n");
        return;
    }
    if (dealerTotal > 21) {
        printf("딜러 Bust → 플레이어 승리!\n");
        return;
    }

    // 정상 비교
    if (playerTotal > dealerTotal) {
        printf("플레이어 승리!\n");
    } else if (playerTotal < dealerTotal) {
        printf("딜러 승리!\n");
    } else {
        printf("무승부!\n");
    }
}
