##
## Makefile for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation
## 
## Made by Lucas Merlette
## Login   <lucas@epitech.net>
## 
## Started on  Mon Feb 24 23:44:12 2014 Lucas Merlette
## Last update Wed Feb 26 14:03:04 2014 Lucas Merlette
##

NAME	= epil
GCC	= g++
RM	= rm -f
OBJS	= $(SRCS:.cpp=.o)
SRCS_P	= sources/
MAIN_P	= main/
SRCS	= $(MAIN_P)main.cpp	\
	$(SRCS_P)Epil.cpp	\
	$(SRCS_P)UI/Profile.cpp	\
	$(SRCS_P)Modules/Block.cpp
INC_P	= -Iheaders/
INC	= $(INC_P) \
	$(INC_P)UI \
	$(INC_P)Modules
CFLAGS	= -W -Wall -Wextra -Werror -std=c++0x

all	: $(NAME)
$(NAME)	: $(OBJS)
	$(GCC) $(INC) $(OBJS) -o $(NAME) $(CFLAGS)
%.o	: %.cpp
	$(GCC) -c $(INC) $(CFLAGS) -o $@ $<
clean	:
	$(RM) $(OBJS)
fclean	: clean
	$(RM) $(NAME)
re	: fclean all
.PHONY	: all clean fclean re