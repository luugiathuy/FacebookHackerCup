Autocomplete Strikes Back

25 points

This morning you woke up with an uncontrollable urge to send a text message made up of K distinct words. But, can you believe it? Your new phone just crashed and all of the words are missing from its dictionary! You used to have N words in there, and you certainly don't have time to add all of them back right now.

Your plan is to just choose K of the N possible words, add them to your phone's dictionary, and then text each of them. To text a certain word, you must either type the word itself, or any nonempty prefix of it which is not a prefix of any other word in the dictionary.

What's the minimum number of letters you must type to send your message of K words?

Input

Input begins with an integer T, the number of test cases. For each test case, there is first a line containing the space-separated integers N and K. Then, N lines follow, each containing a word that used to be in your phone's dictionary.

Output

For the ith test case, print a line containing "Case #i: " followed by the minimum number of characters you need to type to send your text message.

Constraints

    1 ≤ T ≤ 20 
    2 ≤ N ≤ 4,000 
    1 ≤ K ≤ min(N-1, 100) 

The N words will have a total length of no more than 20,000 characters. 

The words are made up of only lower-case alphabetic characters. 

The words are pairwise distinct. 

Explanation of Sample

In the first case, one option is to choose the words "tin", "tinny", "gigantic", and "tilts". You can then text these words by typing "tin", "tinn", "g", and "til", respectively, for a total of `3+4+1+3=11` letters.

Example input

    5
    6 4
    tin
    tiny
    tinny
    gigantic
    tilt
    tilts
    3 2
    apple
    apricot
    cherry
    5 3
    a
    aa
    aaa
    aaaa
    aaaaa
    5 3
    the
    quick
    brown
    fox
    jumped
    8 7
    cork
    work
    card
    ward
    font
    front
    word
    sword

Example output

    Case #1: 11
    Case #2: 2
    Case #3: 6
    Case #4: 3
    Case #5: 13
