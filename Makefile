# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 14:11:57 by gpouyat           #+#    #+#              #
#*   Updated: 2016/12/01 11:50:27 by gpouyat          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

GPU			=
OS			=
CC			=	clang
NAME		=	fractol
FLAGS		=	-Wall -Wextra -Werror
LIBDIR		=	libft
LIBLINK		=	-L $(LIBDIR) -lft
LIB 		=	$(LIBDIR)/libft.a

INCLUDES	= 	-I ./includes
INCLUDE		=	./includes

OBJDIR		=	objs
SRCDIR		=	srcs
SRC			=	main.c\
				useful.c\
				init_opencl.c\
				key_press.c\
				mouse_events.c\
				int_rgb_converter.c\
				palette1.c\
				load_opencl.c\
				fractales.c\
				choose_cpu_or_gpu.c\
				init_structs.c\
				do_fractol.c\
				put_image_mlx.c\
				move_julia.c\
				init_limits_fractales.c\
				free.c\
				key_loop.c\
				palette3.c\
				palette2.c\
				calc_fractales.c

OBJ			= $(SRC:.c=.o)
SRCS		=	$(addprefix $(SRCDIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))


all: directory $(NAME)

$(NAME): $(OBJDIR) $(LIB) $(OBJS) $(INCLUDE)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L minilibx/el_capitan/ -lmlx -framework OpenGL -framework AppKit -framework OpenCL $(LIBLINK)

$(LIB):
	@make -C $(LIBDIR)

ifeq ($(GPU), yes)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -D DO_GPU $(FLAGS) -c $^ -o $@ $(INCLUDES)
else
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ $(INCLUDES)
endif

directory: $(OBJDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBDIR) clean
	@rm -rf $(OBJDIR)
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: clean all re fclean directory
