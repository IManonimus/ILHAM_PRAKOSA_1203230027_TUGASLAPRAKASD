#include <stdio.h>
#include <string.h>

void print_cards(int n, char cards[], int swap_count) {
    printf("Pertukaran %d: ", swap_count);
    for (int i = 0; i < n; i++) {
        printf("%c ", cards[i]);
    }
    printf("\n");
}

int min_swaps(int n, char cards[]) {
    
    int swaps = 0;

    
    for (int i = 0; i < n && swaps < 5; i++) {
        int correct = i;
        for (int j = i + 1; j < n; j++) {
            
            if (cards[j] < cards[correct]) {
                correct = j;
            }
        }

        
        if (correct != i) {
            swaps++;
            
            char temp = cards[i];
            cards[i] = cards[correct];
            cards[correct] = temp;

            
            if (swaps < 5) {
                print_cards(n, cards, swaps);
            } else {
                print_cards(n, cards, 5);
            }
        }
    }

    return swaps; 
}

int main() {
    int n;
    scanf("%d", &n);

    char cards[n];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &cards[i]);
    }

    int swaps = min_swaps(n, cards);
    printf("%d\n", swaps);

    return 0;
}
