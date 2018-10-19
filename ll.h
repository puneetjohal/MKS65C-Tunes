#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LL
#define LL

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node * link);
struct song_node * insert_front(struct song_node * link, char * new_name, char * artist);
struct song_node * free_list(struct song_node * front);
struct song_node * insert_order(struct song_node * front, char * new_name, char * artist);
struct song_node * find(struct song_node * head, char * title, char * artist);
struct song_node * random_song(struct song_node * head);
struct song_node * by_artist(struct song_node * head, char * artist);
struct song_node * remove_song(struct song_node * head, char * title, char * artist);

#endif
