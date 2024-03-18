#include <stdio.h>
#include <stdlib.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    // Menginisialisasi papan catur dengan nilai awal 0
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            *(chessBoard + row * size + col) = 0;
        }
    }

    // Mengatur nilai 1 pada posisi yang mungkin dilalui oleh bidak kuda
    int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    for (int move = 0; move < 8; move++) {
        int newRow = i + moves[move][0];
        int newCol = j + moves[move][1];
        if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
            *(chessBoard + newRow * size + newCol) = 1;
        }
    }

    // Output nilai di setiap baris dan kolom dari array berukuran 8 × 8
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%d ", *(chessBoard + row * size + col));
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);

    // Membuat papan catur berukuran 8x8
    int size = 8;
    int *chessBoard = (int *)malloc(size * size * sizeof(int));

    // Memanggil fungsi untuk menentukan posisi yang dapat dicapai oleh bidak kuda
    koboImaginaryChess(i, j, size, chessBoard);

    // Membebaskan memori yang dialokasikan untuk papan catur
    free(chessBoard);

    return 0;
}
