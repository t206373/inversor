/* Data de submissao:17/03/2020
 * Nome: Tony Tian Rui Li
 * RA:206373
 */

#include <stdio.h>
#define tam_buffer 100

typedef struct {
  char dados[tam_buffer];
  int n;
} pilha, *Pilha;

void push(Pilha p, char c) {
/* Insere caractere c na pilha */
  if (p->n < tam_buffer) {
    p->dados[p->n]=c;
    (p->n)++;
  }
}

void pilha_init(Pilha p) {
  p->n = 0;
}

char pop(Pilha p) {
/* Remove caractere do topo da pilha */
  char c;
  if ((p->n)>0) {
    (p->n)--;
    c = p->dados[p->n];
  }
  return c;
}
int main() {
  char buffer[tam_buffer]; pilha p;
  char c;
  fgets(buffer, tam_buffer, stdin);
  pilha_init(&p);
  int i, j,tam_pilha;

   for(i = 0; buffer[i] != '\n';i++){

    if(buffer[i]==' ' || buffer[i+1] == '\n'){
      tam_pilha = p.n;
      if(buffer[i+1] == '\n'){
      	push(&p, buffer[i]);
      }
      for(j = 0; j<tam_pilha;j++){
        c = pop(&p);
        printf("%c",c);
      }
      if(buffer[i+1] == '\n'){
        c = pop(&p);
        printf("%c",c);
      }
      else{ 
      printf(" ");
      p.n = 0;
      }
    }
    else{
      push(&p, buffer[i]);
    }
  }
  printf("\n");
  return 0;
}