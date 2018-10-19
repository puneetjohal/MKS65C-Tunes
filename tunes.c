#include <stdio.h>
#include "ll.c"
#include "tunes.h"

struct song_node * add_node(struct song_node * table, char * title, char * artist)
{
  char c = artist[0];
  struct song_node * head;
  if (c >= 'a' && c <= 'z')
    head = &table[artist[0] - 'a'];
  else if (c >= 'A' && c <= 'Z')
    head = &table[artist[0] - 'A'];
  else
    head = &table[26];
  return insert_order(head,title,artist);
}

struct song_node * find_song(struct song_node * table, char * title, char * artist){
  struct song_node * head;
  char c = artist[0];
  if (c >= 'a' && c <= 'z')
    head = &table[artist[0] - 'a'];
  else if (c >= 'A' && c <= 'Z')
    head = &table[artist[0] - 'A'];
  else
    head = &table[26];
  return find(head,title,artist);
}

struct song_node * find_by_artist(struct song_node * table, char * artist){
  struct song_node * head;
  char c = artist[0];
  if (c >= 'a' && c <= 'z')
    head = &table[artist[0] - 'a'];
  else if (c >= 'A' && c <= 'Z')
    head = &table[artist[0] - 'A'];
  else
    head = &table[26];
  return by_artist(head,artist);
}

void print_letter(struct song_node * table, char c){
  if (c >= 'a' && c <= 'z')
    print_list(&(table[c - 'a']));
  else if (c >= 'A' && c <= 'Z')
    print_list(&(table[c - 'A']));
  else
    print_list(&(table[26]));
}

void print_artist(struct song_node * table, char * name){
  struct song_node * curr = find_by_artist(table, name);
  while (! strcmp(curr->artist, name))
    {
      printf("%s by %s", curr->name, curr->artist);
      curr = curr->next;
    }
}

void print_all(struct song_node * table[27]){
  int i;
  for (i = 0; i <= 26 + 1; i++)
    {
      print_list(table[i]);
    }
}

void shuffle(){

}

void deleter(){

}

void clear(){

}
