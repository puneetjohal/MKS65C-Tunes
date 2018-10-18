#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"


void print_list(struct song_node * link)
{
  while (link) //while the pointer points somewhere
    {
      printf("%s by %s\n", link->name, link->artist); //print it + arrow
      link = link->next; //go to the next val
    }
}

struct song_node * insert_front(struct song_node * link, char * new_name, char * artist)
{
  struct song_node * ptr = malloc(sizeof(struct song_node));
  //allocate memory for a new struct
  strcpy(ptr->name, new_name); //put the name in its place
  strcpy(ptr->artist, artist); //put the artist in its place
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

struct song_node * insert_order(struct song_node * head, char * new_name, char * artist)
{
  struct song_node* curr = insert_front(head, new_name, artist);
  struct song_node* prev = NULL;
  struct song_node* front = curr;
  struct song_node* next = head;
  int firstRun = 1; //keeps track of which run this is for front assignment

  //sort by artist
  while (next != NULL && strcmp(artist, next->artist) > 0){
    if (firstRun){
      prev = next;
      curr->next = prev->next;
      prev->next = curr;
      front = prev; //in the case the newly added node is not the new front
      firstRun = 0; //not first run anymore
    }
    else {
      prev->next = next;
      curr->next = next->next;
      next->next = curr;
      prev = next;
      next = curr->next;
    }
  }

  /*sort song title
  while (next != NULL && (strcmp(artist, next->artist) == 0) && strcmp(new_name, next->name) > 0) {
    prev->next = next;
    curr->next = next->next;
    next->next = curr;
  }*/

  return front;
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
