NAME := libftprintf.a

FILE :=\
	ft_printf		\
	ft_print_args	\
	ft_print_int	\
	ft_print_hexa	\
	ft_print_decay	\
	ft_len_nbr		\
	ft_len_str		\

FILE_LIBFT :=\
	ft_is_something.c		\
	ft_strlen.c		\
	ft_memset.c		\
	ft_bzero.c		\
	ft_memcpy.c		\
	ft_memmove.c		\
	ft_strlcpy.c		\
	ft_strlcat.c		\
	ft_toelse.c		\
	ft_strchr.c		\
	ft_strrchr.c		\
	ft_strncmp.c		\
	ft_memchr.c		\
	ft_memcmp.c		\
	ft_strnstr.c		\
	ft_atoi.c			\
	ft_calloc.c		\
	ft_strdup.c		\
	ft_substr.c		\
	ft_strjoin.c		\
	ft_strtrim.c		\
	ft_split.c		\
	ft_itoa.c			\
	ft_strmapi.c		\
	ft_striteri.c		\
	ft_putchar_fd.c		\
	ft_putstr_fd.c		\
	ft_putendl_fd.c		\
	ft_putnbr_fd.c		\
	ft_lstnew_bonus.c		\
    ft_lstadd_front_bonus.c	\
    ft_lstsize_bonus.c	\
    ft_lstlast_bonus.c	\
    ft_lstadd_back_bonus.c	\
    ft_lstdelone_bonus.c	\
	ft_lstclear_bonus.c	\
	ft_lstiter_bonus.c	\
	ft_lstmap_bonus.c		\

OBJSDIR := .objs
DEPSDIR := .deps
OBJSDIR_LIBFT := .libftobjs
DEPSDIR_LIBFT := .libftdeps

SRCS := $(addsuffix .c, $(FILE))
OBJS := $(addprefix $(OBJSDIR)/, $(addsuffix .o, $(FILE)))
OBJS_LIBFT := $(addprefix $(OBJSDIR_LIBFT)/, $(patsubst %.c, %.o, $(FILE_LIBFT)))
DEPS := $(addprefix $(DEPSDIR_LIBFT)/, $(patsubst %.o, %.d, $(OBJS)))
DEPS_LIBFT := $(addprefix $(DEPSDIR_LIBFT)/, $(patsubst %.c, %.d, $(FILE_LIBFT)))

CC := cc
CFLAGS := -Wall -Wextra -Werror

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : libft/libft.h $(OBJS_LIBFT) $(OBJS)
	ar rcs $@ $^

$(OBJSDIR_LIBFT)/%.o : libft/libft.h libft/%.c | $(OBJSDIR_LIBFT) $(DEPSDIR_LIBFT)
	cd libft ; make $(patsubst $(OBJSDIR_LIBFT)/%.o, %.o, $@)
	mv $(patsubst $(OBJSDIR_LIBFT)/%.o, libft/%.o, $@) $(OBJSDIR_LIBFT)
	cp $(patsubst $(DEPSDIR_LIBFT)/%.o, libft/.deps/%.o, $@) $(DEPSDIR_LIBFT)

$(OBJSDIR)/%.o : %.c ft_printf.h $(OBJS_LIBFT)| $(OBJSDIR) $(DEPSDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -MD -MP -MF $(patsubst $(OBJSDIR)/%.o, $(DEPSDIR)/%.d, $@)

$(OBJSDIR) : 
	mkdir -p $(OBJSDIR)

$(DEPSDIR) :
	mkdir -p $(DEPSDIR)
	
$(OBJSDIR_LIBFT) : 
	mkdir -p $(OBJSDIR_LIBFT)

$(DEPSDIR_LIBFT) :
	mkdir -p $(DEPSDIR_LIBFT)

bonus : all

clean : 
	rm -rf $(OBJSDIR) $(DEPSDIR)
	cd libft ; make fclean
	rm -rf $(OBJSDIR_LIBFT) $(DEPSDIR_LIBFT)

fclean : clean
	rm -f $(NAME)

re : fclean all

-include $(DEPS) $(DEPS_LIBFT)
