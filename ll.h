#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node * link);
struct song_node * insert_front(struct song_node * link, char * new_name, char * artist);
struct song_node * free_list(struct song_node * front);
struct song_node * insert_order(struct song_node * front, char * new_name, char * artist);
struct song_node * find(char * title, char * artist);
struct song_node * random_song();
struct song_node * by_artist(char * artist);
struct song_node * remove_song(char * title, char * artist);