NAME := libft.a

NAME_BON := .bonus

FILE :=\
	ft_is_something	\
	ft_strlen	\
	ft_memset	\
	ft_bzero	\
	ft_memcpy	\
	ft_memmove	\
	ft_strlcpy	\
	ft_strlcat	\
	ft_toelse	\
	ft_strchr	\
	ft_strrchr	\
	ft_strncmp	\
	ft_memchr	\
	ft_memcmp	\
	ft_strnstr	\
	ft_atoi		\
	ft_calloc	\
	ft_strdup	\
	ft_substr	\
	ft_strjoin	\
	ft_strtrim	\
	ft_split	\
	ft_itoa		\
	ft_strmapi	\
	ft_striteri	\
	ft_putchar_fd	\
	ft_putstr_fd	\
	ft_putendl_fd	\
	ft_putnbr_fd	\

FILE_BON := ft_lstnew		\
	    ft_lstadd_front	\
	    ft_lstsize		\
	    ft_lstlast		\
	    ft_lstadd_back	\
	    ft_lstdelone	\
	    ft_lstclear		\
	    ft_lstiter		\
	    ft_lstmap		\

CC := cc
CFLAGS := -Wall -Wextra -Werror

OBJSDIR := .objs
DEPSDIR := .deps

SRCS := $(addsuffix .c, $(FILE))
#OBJS := $(patsubst %.c, %.o, $(SRCS))
OBJS := $(addprefix $(OBJSDIR)/, $(patsubst %.c, %.o, $(SRCS)))
DEPS := $(addprefix $(DESPDIR)/, $(addsuffix .d, $(FILE)))

SRCS_BON := $(addsuffix _bonus.c, $(FILE_BON))
#OBJS_BON := $(patsubst %.c, %.o, $(SRCS_BON))
OBJS_BON := $(addprefix $(OBJSDIR)/, $(patsubst %.c, %.o, $(SRCS_BON)))
DEPS_BON := $(addprefix $(DEPSDIR)/, $(patsubst %.c, %.d, $(SRCS_BON)))

.PHONY : clean fclean re all bonus

all : $(NAME)

$(NAME) : libft.h $(OBJS)
	ar rcs $@ $^

#%.o : %.c libft.h | $(DEPSDIR) $(OBJSDIR)
#	$(CC) $(CFLAGS) -Iincludes -c $< -o $@ -MD -MP -MF $(patsubst %.o, $(DEPSDIR)/%.d, $@)

$(OBJSDIR)/%.o : %.c libft.h | $(DEPSDIR) $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -MD -MP -MF $(patsubst $(OBJSDIR)/%.o, $(DEPSDIR)/%.d, $@)

$(DEPSDIR) :
	mkdir -p $(DEPSDIR)

$(OBJSDIR) : 
	mkdir -p $(OBJSDIR)

bonus : $(NAME_BON)

$(NAME_BON) : $(OBJS_BON) $(OBJS)
	touch $@
	ar rcs $(NAME) $^

clean : 
	rm -rf $(OBJSDIR) $(DEPSDIR)

fclean : clean
	rm -rf $(NAME) $(NAME_BON)

re : fclean all

-include $(DEPS)
