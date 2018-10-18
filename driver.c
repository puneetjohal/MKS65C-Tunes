#include <stdio.h>
#include "ll.c"
//test
int main(){
  printf("LINKED LIST TESTS\n");
  printf("====================================\n");
  struct song_node *head = (struct song_node*)malloc(sizeof(struct song_node)); //allocates memory
  struct song_node song = {"Bohemian Rhapsody", "Queen", NULL};
  head = &song;
  printf("\nTesting insert_front and print_list...\n");
  head = insert_front(head, "Space Oddidity", "David Bowie");
  print_list(head);

  head = insert_order(head, "The Photograph", "Ghost Quartet");
  head = insert_order(head, "Another One Bites the Dust", "Queen");
  head = insert_order(head, "Heart-Shaped Box", "Nirvana");
  printf("\nTesting insert_order...\n");
  print_list(head);

  printf("\nFinding Space Oddidity by David Bowie...\n");
  struct song_node * temp = find(head, "Space Oddidity", "David Bowie");
  printf("%s by %s\n", temp->name, temp->artist);

  printf("\nFinding first song by Queen...\n");
  temp = by_artist(head, "Queen");
  printf("%s by %s\n", temp->name, temp->artist);

  printf("\nFinding a random song...\n");
  temp = random_song(head);
  printf("%s by %s\n", temp->name, temp->artist);

  printf("\nRemoving The Photograph by Ghost Quartet...\n");
  head = remove_song(head, "The Photograph", "Ghost Quartet");
  print_list(head);

  return 0;
}
