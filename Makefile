NAME	= epil
GCC	= g++
RM	= rm -f

CFLAGS	= -W -Wall -Wextra -Werror -std=c++0x
INC_P	= . Modules Modules/Actions Utils
INC	= $(foreach d, $(INC_P), -Iheaders/$d)

SRCS	= $(shell find src/ \( -iname "*.cpp" \))
OBJS	= $(subst src,obj,$(SRCS:.cpp=.o))

all	: $(NAME)
$(NAME)	: $(OBJS)
	$(GCC) -o $@ $^
obj/%.o	: src/%.cpp
	$(GCC) $(CFLAGS) $(INC) -o $@ -c $<
clean	:
	$(RM) $(OBJS)
fclean	: clean
	$(RM) $(NAME)
re	: fclean all
.PHONY	: all clean fclean re
