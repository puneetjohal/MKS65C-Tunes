#include <stdio.h>

#ifndef TUNEZ
#define TUNEZ

#include "ll.c"
#include "ll.h"

struct song_node * add_node(struct song_node * table[27], char * title, char * artist);
struct song_node * find_song(struct song_node * table[27], char * title, char * artist);
struct song_node * find_by_artist(struct song_node * table[27], char * artist);
void print_letter(struct song_node * table[27], char c);
void print_artist(struct song_node * table[27], char * name);
void print_all(struct song_node * table[27]);
void shuffle(struct song_node * table[27]);
void deleter();
void clear();
#endif
