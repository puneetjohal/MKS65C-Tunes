#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"


void print_list(struct song_node * link)
{
  while (link) //while the pointer points somewhere
  {
    printf("%s by %s", link->name, link->artist); //print it + arrow
    link = link->next; //go to the next val
  }
}
struct song_node * insert_front(struct song_node * link, char * new_name)
{
  struct song_node * ptr = malloc(sizeof(struct song_node));
  //allocate memory for a new struct
  strcpy(ptr->name, new_name); //put the name in its place
  ptr->next = link; //put the pointer to the next node in its place
  return ptr; //return new front
}
struct song_node * free_list(struct song_node * front)
{
  if (front->next) //if this isn't the last node
    free_list(front->next); //free the next one
  free(front); //then free itself
  return NULL; //i don't think I used this properly/at all
}

//what we need to write

struct song_node * insert_order(struct song_node * front, char * new_name, char * artist)
{
  return NULL;
}
struct song_node * find(char * title, char * artist)
{
  return NULL;
}
struct song_node * random_song()
{
  return NULL;
}
struct song_node * by_artist(char * artist)
{
  return NULL;
}
struct song_node * remove_song(char * title, char * artist)
{
  return NULL;
}
