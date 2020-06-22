SRC = read_dir \
num_file \
check_control_char \
columns \
print_file \
print_to_file \
head_size \
get_result \
size_all \
read_link \
sort_file \
get_time \
get_ino \
get_link \
get_uid \
get_gid \
get_blocks \
get_law \
get_flag_l \
get_size_bytes \
get_dev \
get_rdev \
get_minmaj \
get_acl \
isspecial \
islink \
print_l \
sort_my_list \
print_spase \
printstr_update \
control_char_name \
itoa_sp \
full_path \
sort_revers \
sort_all \
get_data \
sort_size \
read_flags \
count_flags_in_str \
dir_arr \
printerr \
print_error \
check_flags \
basic_flags \
flags_for_sort \
other_flags \
printerr_char \
flags_into_arr \
get_is \
creat_list \
sort_time \
get_file_col \

INC = uls.h
INCMX = libmx.h

SRCS = $(addsuffix .c, $(addprefix mx_, $(SRC)))
OBJO = $(SRCS:.c=.o)
FILE = uls
LIBL = libmx.a
NAME = uls.a
SRCM = main.c
DEL = libmx.h.gch 

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean 

install:
	@cd libmx && make -f Makefile install 
	@mkdir -p obj
	@cp $(addprefix src/, $(SRCM)) .
	@cp $(addprefix src/, $(SRCS)) .
	@cp $(addprefix inc/, $(INC)) .
	@cp $(addprefix libmx/inc/, $(INCMX)) .	
	@cp $(addprefix libmx/, $(LIBL)) .
	@clang $(CFLAGS) -c $(SRCS) $(INCMX)
	@ar -rc $(NAME) $(OBJO)
	@clang $(CFLAGS) -o $(FILE) $(SRCM) $(NAME) $(LIBL)
	@mv $(SRCM) ./obj
	@mv $(OBJO) ./obj
	@mv $(SRCS) ./obj

uninstall:
	@rm -rf $(FILE) 
	@cd libmx && make -f Makefile uninstall

clean:
	@cd libmx && make -f Makefile clean
	@rm -rf obj
	@rm -rf $(INCMX) $(INC) $(SRCM) $(LIBL) $(NAME) $(DEL) $(SRCS) 

reinstall: uninstall all
