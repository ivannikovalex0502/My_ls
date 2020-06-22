
NAME = libmx.a
INC = libmx.h

SRC = printchar \
atoi \
printstr \
strlen \
swap_char \
str_reverse \
strnew \
del_strarr \
strdel \
get_char_index \
strndup \
strncpy \
strcpy \
strcat \
strstr \
get_substr_index \
count_substr \
count_words \
strtrim \
del_extra_spaces \
nbr_to_hex \
itoa \
print_strarr \
strsplit \
strjoin \
file_to_str \
replace_substr \
memset \
memcpy \
memccpy \
memchr \
memrchr \
memmem \
memmove \
memcmp \
quicksort \
strcmp \
create_node \
push_front \
pop_front \
push_back \
pop_back \
list_size \
sort_list \
realloc \
read_line \
print_unicode \
pow \
hex_to_nbr \
foreach \
binary_search \
bubble_sort \
printint \
sqrt \
strdup \

SRCS = $(addsuffix .c, $(addprefix mx_, $(SRC)))
OBJO = $(SRCS:.c=.o)

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@mkdir -p obj
	@cp $(addprefix src/, $(SRCS)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLAGS) -c $(SRCS)
	@ar -rc $(NAME) $(OBJO)
	@mv $(OBJO) ./obj
	@mv $(SRCS) ./obj
	
uninstall:
	@rm -rf $(NAME)
	@rm -rf $(INC)

clean:
	@rm -rf $(INC)
	@rm -rf $(SRCS)
	@rm -rf ./obj

reinstall: uninstall all
