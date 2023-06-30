#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

// Function to reverse a string.
static void Swap(char* start, char* end) {
    while (start < end) {

        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

// TODO: implement this function
static void ReverseWords(char* string)
{
    int length = strlen(string);

    char* ptr = string;
    char* ptr2 = string + length - 1;

    // Swap the whole string
    Swap(ptr, ptr2);

    ptr = string;

    int wordLength = 1;

    do {
        // Check if the string itself is null
        if (!*ptr) {
            return;
        }

        ptr++;

        char* wordStart = ptr - wordLength;
        char* wordEnd = ptr - 1;

        // Check if it's the end of the string
        if (*ptr == NULL) {
            //Swap the word
            Swap(wordStart, wordEnd);
        }

        //Check if there's whitespace
        if (*ptr == ' ' || *ptr == '\n') {
            // Swap the word
            Swap(wordStart, wordEnd);
            wordLength = 0;
        }
        else {
            wordLength++;
        }
    } while (*ptr);
}

int main()
{
    /*
    Implement the function ReverseWords() which reverses the words in a sentence.

    input: a character string consisting of words separated by whitespace
    output: the same string, with the words reversed

    Example:
    (input) "The quick brown fox jumps over the lazy dog"
    (output) "dog lazy the over jumps fox brown quick The"


    Note: when implementing, please consider other inputs other than the example string provided.
    */
    char string[] = "The quick brown dog";
    printf("Original String: %s\n", string);

    ReverseWords(string);
    printf("Reversed String: %s\n\n\n", string);

    printf("\nPress any key to continue...");
    char c;
    scanf("%c", &c);
}