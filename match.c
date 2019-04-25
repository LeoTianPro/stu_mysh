#include "stu1459_mysh.h"

int match(const char *str1, char *str2)
{
  if (str1 == NULL || str2 == NULL)
    return -1;
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  if ((len1 < len2) || (len1 == 0 || len2 == 0))
    return -1;
  else if (strcmp(str1, str2) == 0)
  {
    return 1;
  }
  else
    return -1;
}
