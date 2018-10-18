#include "ll.c"

struct song_node * add_node(struct song_node * table, struct song_node * title, char * artist);
struct song_node * find_song(struct song_node * table, char * title, char * artist);
struct song_node * find_by_artist(struct song_node * table, char * artist);
void print_letter(struct song_node * table, char c);
void print_artist(struct song_node * table, char * name);
void print_all();
void shuffle();
void deleter();
void clear();
