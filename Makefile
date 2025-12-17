NAME := libftprintf.a

FILE := ft_print_args	\
	ft_printf	\
	ft_count_len	\
	ft_write_flags	\
	ft_write_number	\

FILE_LIBFT :=\
	libft/ft_is_something.c	\
	libft/ft_strlen.c		\
	libft/ft_memset.c		\
	libft/ft_bzero.c		\
	libft/ft_memcpy.c		\
	libft/ft_memmove.c		\
	libft/ft_strlcpy.c		\
	libft/ft_strlcat.c		\
	libft/ft_toelse.c		\
	libft/ft_strchr.c		\
	libft/ft_strrchr.c		\
	libft/ft_strncmp.c		\
	libft/ft_memchr.c		\
	libft/ft_memcmp.c		\
	libft/ft_strnstr.c		\
	libft/ft_atoi.c			\
	libft/ft_calloc.c		\
	libft/ft_strdup.c		\
	libft/ft_substr.c		\
	libft/ft_strjoin.c		\
	libft/ft_strtrim.c		\
	libft/ft_split.c		\
	libft/ft_itoa.c			\
	libft/ft_strmapi.c		\
	libft/ft_striteri.c		\
	libft/ft_putchar_fd.c	\
	libft/ft_putstr_fd.c	\
	libft/ft_putendl_fd.c	\
	libft/ft_putnbr_fd.c	\
	libft/ft_lstnew_bonus.c				\
    libft/ft_lstadd_front_bonus.c		\
    libft/ft_lstsize_bonus.c			\
    libft/ft_lstlast_bonus.c			\
    libft/ft_lstadd_back_bonus.c		\
    libft/ft_lstdelone_bonus.c			\
    libft/ft_lstclear_bonus.c			\
	libft/ft_lstiter_bonus.c			\
	libft/ft_lstmap_bonus.c			\

OBJSDIR := .objs
DEPSDIR := .deps

SRCS := $(addsuffix .c, $(FILE))
OBJS := $(addprefix $(OBJSDIR)/, $(addsuffix .o, $(FILE)))
OBJS_LIBFT := $(patsubst %.c, %.o, $(FILE_LIBFT))
DEPS := $(addprefix $(DEPSDIR)/, $(patsubst %.o, %.d, $(OBJS)))
DEPS_LIBFT := libft/.deps/*.d

CC := cc
CFLAGS := -Wall -Wextra -Werror
CINCLUDES := -Iinclude

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : ft_printf.h libft/libft.h $(OBJS_LIBFT) $(OBJS)
	ar rcs $@ $^

$(OBJSDIR)/%.o : %.c | $(OBJSDIR) $(DEPSDIR)
	$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@ -MD -MP -MF $(patsubst $(OBJSDIR)/%.o, $(DEPSDIR)/%.d, $@)

$(OBJSDIR) : 
	mkdir -p $(OBJSDIR)

$(DEPSDIR) :
	mkdir -p $(DEPSDIR)

libft/$(OBJSDIR) : 
	cd libft ; mkdir -p $(OBJSDIR)

libft/$(DEPSDIR) : 
	cd libft ; mkdir -p $(DEPSDIR)

bonus : all

clean : 
	rm -rf $(OBJSDIR) $(DEPSDIR)
	rm -rf $(OBJS_LIBFT) $(DEPS_LIBFT)

fclean : clean
	rm -f $(NAME)

re : fclean all

-include $(DEPS) $(DEPS_LIBFT)
