#include "./libft.h"

size_t calcuate_words(char const *s, char c){
    size_t  tot;
    tot = 0;
    unsigned char prev_is_sep = 1;

    while (*s)
    {
        if(*s == c){
            prev_is_sep = 1;
        }else if(*s != c && prev_is_sep){
            prev_is_sep = 0;
            tot++;
        }
        s++;
    }
    return tot;
}

char **ft_split(char const *s, char c){
    
    size_t 	words_size;
    char	**spliced;
	size_t 	i;
	size_t 	j;

    i=0;
    j=0;

    words_size = calcuate_words(s, c);
    
    // printf("number of pointers: %zu\n", words_size);

    spliced = calloc(words_size + 1, sizeof(char *));

    if(!spliced){
        return NULL;
    }

    while(s[j] && i < words_size){
		size_t word_len;

        // printf("i:%zu, j:%zu\n", i, j);

		while(s[j] && s[j] == c){
			j++;
		}

		word_len = 0;
		size_t k = j;

		while(s[k] && s[k] != c){
            // printf("%zu\n", k);
			word_len++;
            k++;
		}
        
		spliced[i] = malloc(word_len + 1);
		if(!spliced[i]){
            return NULL;
		}
		ft_strlcpy(spliced[i], s + j, word_len + 1);
        j = k;

        
        printf("word_len_%zu: %zu: , word: %s\n",i, word_len, spliced[i]);
		i++;
	}
    
    printf("final_i: %zu:", i);
    spliced[i] = NULL;

    return spliced;
}

int main(){
    char **spliced = ft_split("a b c d e", ' ');

    // size_t i = 0;

    while(*spliced){
        printf("'%s', ", *spliced);
        spliced++;
    }
}