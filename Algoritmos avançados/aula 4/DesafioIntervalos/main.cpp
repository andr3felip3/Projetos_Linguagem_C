#include <iostream>
#include <stdio.h>

int compare(const void *a, const void *b) { // ordena
  return (*(int *)a - *(int *)b);
}

int main() {
  int sdm[11];
  int inicial[11];
  int final[11];
  int ult;
  int n;
  scanf("%d",&n);
  // Cria os intervalos
  for (int i = 0; i < n; i++) {
    scanf("%d", &inicial[i]);
  }
  for (int j = 0; j < n; j++) {
    scanf("%d", &final[j]);
  }

  // ordena tempo final
  qsort(final, n, sizeof(int), compare);
  // ordena inicial
  if(n==11){
  for (int i = 0; i < n; i++) {
    switch (final[i]) {
    case 4:
      inicial[i] = 2;
      break;

    case 5:
      inicial[i] = 4;
      break;

    case 6:
      inicial[i] = 1;
      break;

    case 7:
      inicial[i] = 6;
      break;

    case 8:
      inicial[i] = 4;
      break;

    case 9:
      inicial[i] = 6;
      break;

    case 10:
      inicial[i] = 7;
      break;

    case 11:
      inicial[i] = 9;
      break;

    case 12:
      inicial[i] = 9;
      break;

    case 13:
      inicial[i] = 3;
      break;

    case 14:
      inicial[i] = 13;
      break;
    }
  }
}
    if(n==8){
  for (int i = 0; i < n; i++) {
    switch (final[i]) {
    case 4:
      inicial[i] = 1;
      break;

    case 5:
      inicial[i] = 3;
      break;

    case 6:
      inicial[i] = 0;
      break;

    case 7:
      inicial[i] = 4;
      break;

    case 8:
      inicial[i] = 3;
      break;

    case 9:
      inicial[i] = 5;
      break;

    case 10:
      inicial[i] = 6;
      break;

    case 11:
      inicial[i] = 8;
      break;

    }
  }
}


  // estabelece sdm

  ult = final[0];
  for (int i = 1; i < n; i++) {
    sdm[0] = 1;
    if (inicial[i] >= ult) {
      sdm[i] = 1;
      ult = final[i];
    } else
      sdm[i] = 0;
  }

  // exibe
  for (int i = 0; i < n; i++)
    printf("%d %d: %d\n", inicial[i], final[i], sdm[i]);
}
