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

struct song_node * insert_order(struct song_node * front, char * new_name, char * artist)
{
  struct song_node* insertPoint = front;
  struct song_node* pointBefore = NULL;
  while (insertPoint != NULL){
    if (strcmp(artist, insertPoint->artist) <= 0){
      if (strcmp(new_name, insertPoint->name) <= 0){
        insertPoint = insert_front(insertPoint, new_name, artist);
        break;
      }
    }
    pointBefore = insertPoint;
    insertPoint = insertPoint->next;
  }
  if (insertPoint == NULL){
    insertPoint = insert_front(insertPoint, new_name, artist);
    pointBefore->next = insertPoint
  }
  else if (pointBefore){
    pointBefore->next = insertPoint;
  }
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

int main(){
  struct song_node *head = (struct song_node*)malloc(sizeof(struct song_node)); //allocates memory
  struct song_node song = {"Bohemian Rhapsody", "Queen", NULL};
  print_list(head);
  return 0;
}
