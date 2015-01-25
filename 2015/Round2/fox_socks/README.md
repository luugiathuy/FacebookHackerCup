Fox Socks

45 points

Mr. Fox sure loves his socks! He stores his many indistinguishable socks in a set of N bins, which are arranged in a circle and numbered in clockwise order. For every 1 ≤ i < N, the next bin clockwise of bin i is bin i+1, and the next bin clockwise of bin N is bin 1. Initially, the ith bin contains Si socks.

Never being quite satisfied with his sock collection, Mr. Fox would like to perform M operations on it, one after another. Each operation i may be of one of the following 4 types, determined by the value of Oi:

Given integers Ai, Bi, Ci, and Di, add Ci + 0*Di socks to bin Ai, add Ci + 1*Di socks to the next bin clockwise of bin Ai, add Ci + 2*Di to the next bin clockwise of that one, and so on until this has been done for Bi bins. Determine the total number of socks added in this process.

Given integers Ai, Bi, and Ci, remove all of the socks from bin Ai and then add Ci socks to it. Do the same for the next bin clockwise of Ai, and so on until this has been done for Bi bins. Determine the sum of two values: the total number of socks removed in this process, and the total number of socks added in this process.

Given integers Ai and Bi, count the number of socks in bin Ai (without removing them), the number of socks in the next bin clockwise of Ai, and so on until the socks in Bi bins have been counted. Determine the total number of socks counted in this process.

Given integers Ai and Bi, check if bin Ai contains an odd number of socks. Do the same for the next bin clockwise of Ai, and so on until this has been done for Bi bins. Determine the total number of these bins that contain an odd number of socks.

Can you help Mr. Fox keep track of his socks? Note the value calculated during each of the M operations as they're performed, and then output the sum of all M of the values modulo 109.

Input

Input begins with an integer T, the number of sock collections Mr. Fox has. For each sock collection, there are 7 lines containing the following space-separated integers:

    N M
    S1 S2 XS YS ZS
    O1 O2 XO YO ZO
    A1 A2 XA YA ZA
    B1 B2 XB YB ZB
    C1 C2 XC YC ZC
    D1 D2 XD YD ZD

The first two elements of each sequence of integers (S, O, A, B, C, and D) are given, and the rest are computed with the following pseudorandom generators:

    Si = (XS*Si-2 + YS*Si-1 + ZS) modulo 109, for 3 ≤ i ≤ N
    Oi = ((XO*Oi-2 + YO*Oi-1 + ZO) modulo 4) + 1, for 3 ≤ i ≤ M
    Ai = ((XA*Ai-2 + YA*Ai-1 + ZA) modulo N) + 1, for 3 ≤ i ≤ M
    Bi = ((XB*Bi-2 + YB*Bi-1 + ZB) modulo N) + 1, for 3 ≤ i ≤ M
    Ci = (XC*Ci-2 + YC*Ci-1 + ZC) modulo 109, for 3 ≤ i ≤ M
    Di = (XD*Di-2 + YD*Di-1 + ZD) modulo 109, for 3 ≤ i ≤ M

Output

For the ith sock collection, print a line containing "Case #i: " followed by the sum of all values calculated during each operation, modulo 109.

Constraints

    1 ≤ T ≤ 20 
    2 ≤ N ≤ 1,000,000 
    2 ≤ M ≤ 1,000,000 
    0 ≤ Si < 109 
    1 ≤ Oi ≤ 4 
    1 ≤ Ai ≤ N 
    1 ≤ Bi ≤ N 
    0 ≤ Ci < 109 
    0 ≤ Di < 109 
    0 ≤ XS, XO, XA XB, XC, XD < 109 
    0 ≤ YS, YO, YA YB, YC, YD < 109 
    0 ≤ ZS, ZO, ZA ZB, ZC, ZD < 109 

Explanation of Sample

The first collection has 5 bins that all have 0 socks. None of the operations involve any socks at all, so the answer is 0.

The second collection has 5 bins with 1, 2, 3, 4, and 5 socks. Mr. Fox performs the operations 1, 2, 3, and 4 in order. For each operation, A = 1, B = 5, C = 0, D = 0. He first adds 0 socks to the bins, then removes all 15 socks, then counts the 0 remaining socks, and then counts 0 odd bins, for a total of 15.

The third collection also has 5 bins with 1, 2, 3, 4, and 5 socks. Mr. Fox performs the same operations, but this time C and D take on the values 1, 2, 3, and 4 in that order. He adds 15 socks to the bins, then removes all 30 socks and adds 2 socks to each bin, then counts those 10 socks, and then counts 0 odd bins. The total is then 15 + 30 + 10 + 10 = 65.

Example input

    5
    5 4
    0 0 0 0 0
    1 2 0 1 0
    1 1 0 0 0
    1 1 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    5 4
    1 2 0 1 1
    1 2 0 1 0
    1 1 0 0 0
    5 5 0 1 4
    0 0 0 0 0
    0 0 0 0 0
    5 4
    1 2 0 1 1
    1 2 0 1 0
    1 1 0 0 0
    5 5 0 1 4
    1 2 0 1 1
    1 2 0 1 1
    5 2
    1 2 0 1 1
    4 4 0 0 0
    1 1 0 0 0
    5 5 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    100 100
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5

Example output

    Case #1: 0
    Case #2: 15
    Case #3: 65
    Case #4: 6
    Case #5: 505274484
