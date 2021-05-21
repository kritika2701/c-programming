#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  char * outName=malloc((strlen(inputName)+7)*sizeof(*outName));
  strcpy(outName, inputName);
  outName=realloc(outName,(strlen(inputName)+10)*sizeof(*outName));
  strcat(outName, ".counts");
  return outName;
}
