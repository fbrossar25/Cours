#include "str.h"

size_t str_length(const char *str) {
  if(str == NULL) return 0;
  size_t res = 0;
  while(str[res] != '\0')
  {
  	res++;
  }

  return res;
}

int str_compare(const char *str1, const char *str2) {
  int i=0,res=0;
  while(str1[i] != '\0' && str2[i] != '\0')
  {
  	res = str1[i] - str2[i];
    if(res != 0)
    {
      return res;
    }
  	i++;
  }
  return 0;
}

const char *str_search(const char *haystack, const char *needle) {
	size_t i = 0;
  if(haystack == NULL || needle == NULL)
  {
    return NULL;
  }
	while(haystack[i] != '\0')
	{
		size_t j = 0;
		while(needle[j] && haystack[i+j] && needle[j] == haystack[i+j])
		{
			j++;
		}
		if(needle[j] == '\0')
		{
			return haystack + i;
		}
		i++;
	}
	return NULL;
}
