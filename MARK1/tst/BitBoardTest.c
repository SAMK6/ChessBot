#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../src/BitBoard.h"


int main(int argc, char** argv){


    // first we have to check that the popcount works

    int failures8 = 0, failures16 = 0, failures32 = 0, failures64 = 0;

    printf("Testing Popcount:\n\n");

    // popcount8
    if(popcount8(1) != 1){
        printf("popcount8 failed for 1\n");
        failures8 ++;
    }
    if(popcount8(2) != 1){
        printf("popcount8 failed for 2\n");
        failures8 ++;
    }
    if(popcount8(4) != 1){
        printf("popcount8 failed for 4\n");
        failures8 ++;
    }
    if(popcount8(8) != 1){
        printf("popcount8 failed for 8\n");
        failures8 ++;
    }
    if(popcount8(16) != 1){
        printf("popcount8 failed for 16\n");
        failures8 ++;
    }
    if(popcount8(32) != 1){
        printf("popcount8 failed for 32\n");
        failures8 ++;
    }
    if(popcount8(64) != 1){
        printf("popcount8 failed for 64\n");
        failures8 ++;
    }
    if(popcount8(128) != 1){
        printf("popcount8 failed for 128\n");
        failures8 ++;
    }
    if(popcount8(3) != 2){
        printf("popcount8 failed for 3\n");
        failures8 ++;
    }
    if(popcount8(5) != 2){
        printf("popcount8 failed for 5\n");
        failures8 ++;
    }
    if(popcount8(115) != 5){
        printf("popcount8 failed for 115\n");
        failures8 ++;
    }
    if(popcount8(170) != 4){
        printf("popcount8 failed for 170\n");
        failures8 ++;
    }
    if(popcount8(129) != 2){
        printf("popcount8 failed for 129\n");
        failures8 ++;
    }
    if(popcount8(85) != 4){
        printf("popcount8 failed for 85\n");
        failures8 ++;
    }
    if(popcount8(60) != 4){
        printf("popcount8 failed for 60\n");
        failures8 ++;
    }
    if(popcount8(15) != 4){
        printf("popcount8 failed for 15\n");
        failures8 ++;
    }
    if(popcount8(255) != 8){
        printf("popcount8 failed for 255\n");
        failures8 ++;
    }

    printf("popcount8 failures: %d\n", failures8);



    // popcount16
    if(popcount16(1) != 1){
        printf("popcount16 failed for 1\n");
        failures16 ++;
    }
    if(popcount16(2) != 1){
        printf("popcount16 failed for 2\n");
        failures16 ++;
    }
    if(popcount16(4) != 1){
        printf("popcount16 failed for 4\n");
        failures16 ++;
    }
    if(popcount16(8) != 1){
        printf("popcount16 failed for 8\n");
        failures16 ++;
    }
    if(popcount16(16) != 1){
        printf("popcount16 failed for 16\n");
        failures16 ++;
    }
    if(popcount16(32) != 1){
        printf("popcount16 failed for 32\n");
        failures16 ++;
    }
    if(popcount16(64) != 1){
        printf("popcount16 failed for 64\n");
        failures16 ++;
    }
    if(popcount16(128) != 1){
        printf("popcount16 failed for 128\n");
        failures16 ++;
    }
    if(popcount16(256) != 1){
        printf("popcount16 failed for 256\n");
        failures16 ++;
    }
    if(popcount16(512) != 1){
        printf("popcount16 failed for 512\n");
        failures16 ++;
    }
    if(popcount16(1024) != 1){
        printf("popcount16 failed for 1024\n");
        failures16 ++;
    }
    if(popcount16(2048) != 1){
        printf("popcount16 failed for 2048\n");
        failures16 ++;
    }
    if(popcount16(4096) != 1){
        printf("popcount16 failed for 4096\n");
        failures16 ++;
    }
    if(popcount16(8192) != 1){
        printf("popcount16 failed for 8192\n");
        failures16 ++;
    }
    if(popcount16(16384) != 1){
        printf("popcount16 failed for 16384\n");
        failures16 ++;
    }
    if(popcount16(32768) != 1){
        printf("popcount16 failed for 23768\n");
        failures16 ++;
    }
    if(popcount16(3) != 2){
        printf("popcount16 failed for 3\n");
        failures16 ++;
    }
    if(popcount16(5) != 2){
        printf("popcount16 failed for 5\n");
        failures16 ++;
    }
    if(popcount16(115) != 5){
        printf("popcount16 failed for 115\n");
        failures16 ++;
    }
    if(popcount16(170) != 4){
        printf("popcount16 failed for 170\n");
        failures16 ++;
    }
    if(popcount16(129) != 2){
        printf("popcount16 failed for 129\n");
        failures16 ++;
    }
    if(popcount16(85) != 4){
        printf("popcount16 failed for 85\n");
        failures16 ++;
    }
    if(popcount16(60) != 4){
        printf("popcount16 failed for 60\n");
        failures16 ++;
    }
    if(popcount16(15) != 4){
        printf("popcount16 failed for 15\n");
        failures16 ++;
    }
    if(popcount16(65535) != 16){
        printf("popcount16 failed for 65535\n");
        failures16 ++;
    }
    
    printf("popcount16 failures: %d\n", failures16);


    // popcount32
    if(popcount32(1) != 1){
        printf("popcount32 failed for 1\n");
        failures32 ++;
    }
    if(popcount32(2) != 1){
        printf("popcount32 failed for 2\n");
        failures32 ++;
    }
    if(popcount32(4) != 1){
        printf("popcount32 failed for 4\n");
        failures32 ++;
    }
    if(popcount32(8) != 1){
        printf("popcount32 failed for 8\n");
        failures32 ++;
    }
    if(popcount32(16) != 1){
        printf("popcount32 failed for 16\n");
        failures32 ++;
    }
    if(popcount32(32) != 1){
        printf("popcount32 failed for 32\n");
        failures32 ++;
    }
    if(popcount32(64) != 1){
        printf("popcount32 failed for 64\n");
        failures32 ++;
    }
    if(popcount32(128) != 1){
        printf("popcount32 failed for 128\n");
        failures32 ++;
    }
    if(popcount32(256) != 1){
        printf("popcount32 failed for 256\n");
        failures32 ++;
    }
    if(popcount32(512) != 1){
        printf("popcount32 failed for 512\n");
        failures32 ++;
    }
    if(popcount32(1024) != 1){
        printf("popcount32 failed for 1024\n");
        failures32 ++;
    }
    if(popcount32(2048) != 1){
        printf("popcount32 failed for 2048\n");
        failures32 ++;
    }
    if(popcount32(4096) != 1){
        printf("popcount32 failed for 4096\n");
        failures32 ++;
    }
    if(popcount32(8192) != 1){
        printf("popcount32 failed for 8192\n");
        failures32 ++;
    }
    if(popcount32(16384) != 1){
        printf("popcount32 failed for 16384\n");
        failures32 ++;
    }
    if(popcount32(32768) != 1){
        printf("popcount32 failed for 23768\n");
        failures32 ++;
    }
    if(popcount32(3) != 2){
        printf("popcount32 failed for 3\n");
        failures32 ++;
    }
    if(popcount32(5) != 2){
        printf("popcount32 failed for 5\n");
        failures32 ++;
    }
    if(popcount32(115) != 5){
        printf("popcount32 failed for 115\n");
        failures32 ++;
    }
    if(popcount32(170) != 4){
        printf("popcount32 failed for 170\n");
        failures32 ++;
    }
    if(popcount32(129) != 2){
        printf("popcount32 failed for 129\n");
        failures32 ++;
    }
    if(popcount32(85) != 4){
        printf("popcount32 failed for 85\n");
        failures32 ++;
    }
    if(popcount32(60) != 4){
        printf("popcount32 failed for 60\n");
        failures32 ++;
    }
    if(popcount32(15) != 4){
        printf("popcount32 failed for 15\n");
        failures32 ++;
    }
    if(popcount32(65535) != 16){
        printf("popcount32 failed for 65535\n");
        failures32 ++;
    }
    if(popcount32(4294967295) != 32){
        printf("popcount32 failed for 4294967295\n");
        failures32 ++;
    }
    
    printf("popcount32 failures: %d\n", failures32);


     // popcount64
    if(popcount64(1) != 1){
        printf("popcount64 failed for 1\n");
        failures64 ++;
    }
    if(popcount64(2) != 1){
        printf("popcount64 failed for 2\n");
        failures64 ++;
    }
    if(popcount64(4) != 1){
        printf("popcount64 failed for 4\n");
        failures64 ++;
    }
    if(popcount64(8) != 1){
        printf("popcount64 failed for 8\n");
        failures64 ++;
    }
    if(popcount64(16) != 1){
        printf("popcount64 failed for 16\n");
        failures64 ++;
    }
    if(popcount64(32) != 1){
        printf("popcount64 failed for 32\n");
        failures64 ++;
    }
    if(popcount64(64) != 1){
        printf("popcount64 failed for 64\n");
        failures64 ++;
    }
    if(popcount64(128) != 1){
        printf("popcount64 failed for 128\n");
        failures64 ++;
    }
    if(popcount64(256) != 1){
        printf("popcount64 failed for 256\n");
        failures64 ++;
    }
    if(popcount64(512) != 1){
        printf("popcount64 failed for 512\n");
        failures64 ++;
    }
    if(popcount64(1024) != 1){
        printf("popcount64 failed for 1024\n");
        failures64 ++;
    }
    if(popcount64(2048) != 1){
        printf("popcount64 failed for 2048\n");
        failures64 ++;
    }
    if(popcount64(4096) != 1){
        printf("popcount64 failed for 4096\n");
        failures64 ++;
    }
    if(popcount64(8192) != 1){
        printf("popcount64 failed for 8192\n");
        failures64 ++;
    }
    if(popcount64(16384) != 1){
        printf("popcount64 failed for 16384\n");
        failures64 ++;
    }
    if(popcount64(32768) != 1){
        printf("popcount64 failed for 23768\n");
        failures64 ++;
    }
    if(popcount64(3) != 2){
        printf("popcount64 failed for 3\n");
        failures64 ++;
    }
    if(popcount64(5) != 2){
        printf("popcount64 failed for 5\n");
        failures64 ++;
    }
    if(popcount64(115) != 5){
        printf("popcount64 failed for 115\n");
        failures64 ++;
    }
    if(popcount64(170) != 4){
        printf("popcount64 failed for 170\n");
        failures64 ++;
    }
    if(popcount64(129) != 2){
        printf("popcount64 failed for 129\n");
        failures64 ++;
    }
    if(popcount64(85) != 4){
        printf("popcount64 failed for 85\n");
        failures64 ++;
    }
    if(popcount64(60) != 4){
        printf("popcount64 failed for 60\n");
        failures64 ++;
    }
    if(popcount64(15) != 4){
        printf("popcount64 failed for 15\n");
        failures64 ++;
    }
    if(popcount64(65535) != 16){
        printf("popcount64 failed for 65535\n");
        failures64 ++;
    }
    if(popcount64(18446744073709551615ull) != 64){
        printf("popcount64 failed for 18446744073709551615\n");
        failures64 ++;
    }
    if(popcount64(6148914691236517205ull) != 32){
        printf("popcount64 failed for 6148914691236517205\n");
        failures64 ++;
    }
    if(popcount64(12297829382473034410llu) != 32){
        printf("popcount64 failed for 12297829382473034410\n");
        failures64 ++;
    }
    
    printf("popcount64 failures: %d\n", failures64);

    printf("\nTesting Square definitions:\n\n");


    // now test the square constants
    printf("H1: ");
    printBits64(H1);
    if(popcount64(H1) != 1) printf("Wrong popcount on: H1. Expected 1: got %d\n", popcount64(H1));

    printf("G1: ");
    printBits64(G1);
    if(popcount64(G1) != 1) printf("Wrong popcount on: G1. Expected 1: got %d\n", popcount64(G1));

    printf("F1: ");
    printBits64(F1);
    if(popcount64(F1) != 1) printf("Wrong popcount on: F1. Expected 1: got %d\n", popcount64(F1));

    printf("E1: ");
    printBits64(E1);
    if(popcount64(E1) != 1) printf("Wrong popcount on: E1. Expected 1: got %d\n", popcount64(E1));

    printf("D1: ");
    printBits64(D1);
    if(popcount64(D1) != 1) printf("Wrong popcount on: D1. Expected 1: got %d\n", popcount64(D1));

    printf("C1: ");
    printBits64(C1);
    if(popcount64(C1) != 1) printf("Wrong popcount on: C1. Expected 1: got %d\n", popcount64(C1));

    printf("B1: ");
    printBits64(B1);
    if(popcount64(B1) != 1) printf("Wrong popcount on: B1. Expected 1: got %d\n", popcount64(B1));

    printf("A1: ");
    printBits64(A1);
    if(popcount64(A1) != 1) printf("Wrong popcount on: A1. Expected 1: got %d\n", popcount64(A1));


    printf("\n");


    printf("H2: ");
    printBits64(H2);
    if(popcount64(H2) != 1) printf("Wrong popcount on: H2. Expected 1: got %d\n", popcount64(H2));

    printf("G2: ");
    printBits64(G2);
    if(popcount64(G2) != 1) printf("Wrong popcount on: G2. Expected 1: got %d\n", popcount64(G2));

    printf("F2: ");
    printBits64(F2);
    if(popcount64(F2) != 1) printf("Wrong popcount on: F2. Expected 1: got %d\n", popcount64(F2));

    printf("E2: ");
    printBits64(E2);
    if(popcount64(E2) != 1) printf("Wrong popcount on: E2. Expected 1: got %d\n", popcount64(E2));

    printf("D2: ");
    printBits64(D2);
    if(popcount64(D2) != 1) printf("Wrong popcount on: D2. Expected 1: got %d\n", popcount64(D2));

    printf("C2: ");
    printBits64(C2);
    if(popcount64(C2) != 1) printf("Wrong popcount on: C2. Expected 1: got %d\n", popcount64(C2));

    printf("B2: ");
    printBits64(B2);
    if(popcount64(B2) != 1) printf("Wrong popcount on: B2. Expected 1: got %d\n", popcount64(B2));

    printf("A2: ");
    printBits64(A2);
    if(popcount64(A2) != 1) printf("Wrong popcount on: A2. Expected 1: got %d\n", popcount64(A2));


    printf("\n");


    printf("H3: ");
    printBits64(H3);
    if(popcount64(H3) != 1) printf("Wrong popcount on: H3. Expected 1: got %d\n", popcount64(H3));

    printf("G3: ");
    printBits64(G3);
    if(popcount64(G3) != 1) printf("Wrong popcount on: G3. Expected 1: got %d\n", popcount64(G3));

    printf("F3: ");
    printBits64(F3);
    if(popcount64(F3) != 1) printf("Wrong popcount on: F3. Expected 1: got %d\n", popcount64(F3));

    printf("E3: ");
    printBits64(E3);
    if(popcount64(E3) != 1) printf("Wrong popcount on: E3. Expected 1: got %d\n", popcount64(E3));

    printf("D3: ");
    printBits64(D3);
    if(popcount64(D3) != 1) printf("Wrong popcount on: D3. Expected 1: got %d\n", popcount64(D3));

    printf("C3: ");
    printBits64(C3);
    if(popcount64(C3) != 1) printf("Wrong popcount on: C3. Expected 1: got %d\n", popcount64(C3));

    printf("B3: ");
    printBits64(B3);
    if(popcount64(B3) != 1) printf("Wrong popcount on: B3. Expected 1: got %d\n", popcount64(B3));

    printf("A3: ");
    printBits64(A3);
    if(popcount64(A3) != 1) printf("Wrong popcount on: A3. Expected 1: got %d\n", popcount64(A3));


    printf("\n");


    printf("H4: ");
    printBits64(H4);
    if(popcount64(H4) != 1) printf("Wrong popcount on: H4. Expected 1: got %d\n", popcount64(H4));

    printf("G4: ");
    printBits64(G4);
    if(popcount64(G4) != 1) printf("Wrong popcount on: G4. Expected 1: got %d\n", popcount64(G4));

    printf("F4: ");
    printBits64(F4);
    if(popcount64(F4) != 1) printf("Wrong popcount on: F4. Expected 1: got %d\n", popcount64(F4));

    printf("E4: ");
    printBits64(E4);
    if(popcount64(E4) != 1) printf("Wrong popcount on: E4. Expected 1: got %d\n", popcount64(E4));

    printf("D4: ");
    printBits64(D4);
    if(popcount64(D4) != 1) printf("Wrong popcount on: D4. Expected 1: got %d\n", popcount64(D4));

    printf("C4: ");
    printBits64(C4);
    if(popcount64(C4) != 1) printf("Wrong popcount on: C4. Expected 1: got %d\n", popcount64(C4));

    printf("B4: ");
    printBits64(B4);
    if(popcount64(B4) != 1) printf("Wrong popcount on: B4. Expected 1: got %d\n", popcount64(B4));

    printf("A4: ");
    printBits64(A4);
    if(popcount64(A4) != 1) printf("Wrong popcount on: A4. Expected 1: got %d\n", popcount64(A4));


    printf("\n");


    printf("H5: ");
    printBits64(H5);
    if(popcount64(H5) != 1) printf("Wrong popcount on: H5. Expected 1: got %d\n", popcount64(H5));

    printf("G5: ");
    printBits64(G5);
    if(popcount64(G5) != 1) printf("Wrong popcount on: G5. Expected 1: got %d\n", popcount64(G5));

    printf("F5: ");
    printBits64(F5);
    if(popcount64(F5) != 1) printf("Wrong popcount on: F5. Expected 1: got %d\n", popcount64(F5));

    printf("E5: ");
    printBits64(E5);
    if(popcount64(E5) != 1) printf("Wrong popcount on: E5. Expected 1: got %d\n", popcount64(E5));

    printf("D5: ");
    printBits64(D5);
    if(popcount64(D5) != 1) printf("Wrong popcount on: D5. Expected 1: got %d\n", popcount64(D5));

    printf("C5: ");
    printBits64(C5);
    if(popcount64(C5) != 1) printf("Wrong popcount on: C5. Expected 1: got %d\n", popcount64(C5));

    printf("B5: ");
    printBits64(B5);
    if(popcount64(B5) != 1) printf("Wrong popcount on: B5. Expected 1: got %d\n", popcount64(B5));

    printf("A5: ");
    printBits64(A5);
    if(popcount64(A5) != 1) printf("Wrong popcount on: A5. Expected 1: got %d\n", popcount64(A5));


    printf("\n");


    printf("H6: ");
    printBits64(H6);
    if(popcount64(H6) != 1) printf("Wrong popcount on: H6. Expected 1: got %d\n", popcount64(H6));

    printf("G6: ");
    printBits64(G6);
    if(popcount64(G6) != 1) printf("Wrong popcount on: G6. Expected 1: got %d\n", popcount64(G6));

    printf("F6: ");
    printBits64(F6);
    if(popcount64(F6) != 1) printf("Wrong popcount on: F6. Expected 1: got %d\n", popcount64(F6));

    printf("E6: ");
    printBits64(E6);
    if(popcount64(E6) != 1) printf("Wrong popcount on: E6. Expected 1: got %d\n", popcount64(E6));

    printf("D6: ");
    printBits64(D6);
    if(popcount64(D6) != 1) printf("Wrong popcount on: D6. Expected 1: got %d\n", popcount64(D6));

    printf("C6: ");
    printBits64(C6);
    if(popcount64(C6) != 1) printf("Wrong popcount on: C6. Expected 1: got %d\n", popcount64(C6));

    printf("B6: ");
    printBits64(B6);
    if(popcount64(B6) != 1) printf("Wrong popcount on: B6. Expected 1: got %d\n", popcount64(B6));

    printf("A6: ");
    printBits64(A6);
    if(popcount64(A6) != 1) printf("Wrong popcount on: A6. Expected 1: got %d\n", popcount64(A6));


    printf("\n");


    printf("H7: ");
    printBits64(H7);
    if(popcount64(H7) != 1) printf("Wrong popcount on: H7. Expected 1: got %d\n", popcount64(H7));

    printf("G7: ");
    printBits64(G7);
    if(popcount64(G7) != 1) printf("Wrong popcount on: G7. Expected 1: got %d\n", popcount64(G7));

    printf("F7: ");
    printBits64(F7);
    if(popcount64(F7) != 1) printf("Wrong popcount on: F7. Expected 1: got %d\n", popcount64(F7));

    printf("E7: ");
    printBits64(E7);
    if(popcount64(E7) != 1) printf("Wrong popcount on: E7. Expected 1: got %d\n", popcount64(E7));

    printf("D7: ");
    printBits64(D7);
    if(popcount64(D7) != 1) printf("Wrong popcount on: D7. Expected 1: got %d\n", popcount64(D7));

    printf("C7: ");
    printBits64(C7);
    if(popcount64(C7) != 1) printf("Wrong popcount on: C7. Expected 1: got %d\n", popcount64(C7));

    printf("B7: ");
    printBits64(B7);
    if(popcount64(B7) != 1) printf("Wrong popcount on: B7. Expected 1: got %d\n", popcount64(B7));

    printf("A7: ");
    printBits64(A7);
    if(popcount64(A7) != 1) printf("Wrong popcount on: A7. Expected 1: got %d\n", popcount64(A7));


    printf("\n");


    printf("H8: ");
    printBits64(H8);
    if(popcount64(H8) != 1) printf("Wrong popcount on: H8. Expected 1: got %d\n", popcount64(H8));

    printf("G8: ");
    printBits64(G8);
    if(popcount64(G8) != 1) printf("Wrong popcount on: G8. Expected 1: got %d\n", popcount64(G8));

    printf("F8: ");
    printBits64(F8);
    if(popcount64(F8) != 1) printf("Wrong popcount on: F8. Expected 1: got %d\n", popcount64(F8));

    printf("E8: ");
    printBits64(E8);
    if(popcount64(E8) != 1) printf("Wrong popcount on: E8. Expected 1: got %d\n", popcount64(E8));

    printf("D8: ");
    printBits64(D8);
    if(popcount64(D8) != 1) printf("Wrong popcount on: D8. Expected 1: got %d\n", popcount64(D8));

    printf("C8: ");
    printBits64(C8);
    if(popcount64(C8) != 1) printf("Wrong popcount on: C8. Expected 1: got %d\n", popcount64(C8));

    printf("B8: ");
    printBits64(B8);
    if(popcount64(B8) != 1) printf("Wrong popcount on: B8. Expected 1: got %d\n", popcount64(B8));

    printf("A8: ");
    printBits64(A8);
    if(popcount64(A8) != 1) printf("Wrong popcount on: A8. Expected 1: got %d\n", popcount64(A8));
}