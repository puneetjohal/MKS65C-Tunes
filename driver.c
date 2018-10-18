#include <stdio.h>
#include "ll.c"

int main(){
  struct song_node *head = (struct song_node*)malloc(sizeof(struct song_node)); //allocates memory
  struct song_node song = {"Bohemian Rhapsody", "Queen", NULL};
  head = &song;
  print_list(head);
  head = insert_front(head, "Space Oddidity", "David Bowie");
  //head = insert_order(head, "The Photograph", "Ghost Quartet");
  //head = insert_order(head, "Paranoid Android", "Radiohead");
  print_list(head);
  return 0;
}
