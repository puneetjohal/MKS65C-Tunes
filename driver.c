#include <stdio.h>
#include "ll.c"

int main(){
  struct song_node *head = (struct song_node*)malloc(sizeof(struct song_node)); //allocates memory
  struct song_node song = {"Bohemian Rhapsody", "Queen", NULL};
  head = &song;
  printf("Adding first song and printing list...\n");
  print_list(head);
  head = insert_order(head, "Space Oddidity", "David Bowie");
  head = insert_order(head, "The Photograph", "Ghost Quartet");
  head = insert_order(head, "Another One Bites the Dust", "Queen");
  printf("Testing insert_order...\n");
  print_list(head);
  printf("Finding Space Oddidity...\n");
  struct song_node * temp = find(head,"Space Oddidity", "David Bowie");
  printf("%s by %s\n", temp->name, temp->artist);
  return 0;
}
