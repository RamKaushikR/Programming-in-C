#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100
#define N      100

struct entry {
  int number;
  char name[MAXLEN];
};
typedef struct entry Entry;

int read_entries (Entry* e[]);
Entry* get_node (char* name, char* number);
void print_entries (Entry* e[], int n);
int write_entries (Entry* e[], int n);

int main ()
{
  Entry* telephones[N];
  int n;
  char line[MAXLEN];
  char choice;
  char name[MAXLEN];
  int number;
  
  n = read_entries (telephones);
  //print_entries (telephones, n);
  while (1) {
    printf ("? ");
    fgets (line, MAXLEN, stdin);
    choice = line[0];
    switch (choice) {
    case 's':
      sscanf (line+1, "%d", &number);
      printf ("%d\n", number);
      break;
    case 'i':
      sscanf (line+1, "%d%s", &number, name);
      printf ("%d,%s\n", number, name);
      break;
    case 'd':
      sscanf (line+1, "%d", &number);
      printf ("%d\n", number);
      break;
    case 'q':
      write_entries(telephones, n);
      return 0;
    }
  }
  return 0;
}

void print_entries (Entry* e[], int n)
{
  for (int i = 0; i < n; i++)
    printf ("%d,%s,%d\n", i, e[i]->name, e[i]->number);
}

int read_entries (Entry* e[])
{
  FILE* fp;
  int i;
  char line[MAXLEN];
  char* name;
  char* number;
  
  fp = fopen ("telephone.in", "r");
  for (i = 0; fgets(line, MAXLEN, fp) != NULL; i++) {
    name = strtok (line, "|");
    number = strtok (NULL, "|");
    e[i] = get_node (name, number);
  }
  fclose(fp);
  return i;
}

Entry* get_node (char* name, char* number)
{
  Entry* t = (Entry*) malloc (sizeof(Entry));
  strcpy(t->name, name);
  t->number = atoi(number);
  return t;
}

int write_entries (Entry* e[], int n)
{
  int i;
  FILE* fp;

  fp = fopen ("telephone2.in", "w");
  for (i = 0; i < n; i++)
    fprintf(fp, "|%s|%d|\n", e[i]->name, e[i]->number);
  fclose (fp);
}
