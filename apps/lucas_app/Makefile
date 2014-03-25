NAME	= lucas_app
GCC	= g++
RM	= rm -f

SRCS_P	= src/
SRCS	+= $(shell find $(SRCS_P) \( -iname "*.cpp" \))
OBJS	= $(subst src,obj,$(SRCS:.cpp=.o))
SDIR	= main UI
ODIR	= obj/ $(addprefix obj/, $(SDIR))

INC_F	= . UI Utils Exceptions
INC	= $(foreach d, $(INC_F), -Iheaders/$d)
CFLAGS	= -W -Wall -Wextra -Werror -std=c++0x

all		: $(NAME)
$(NAME)		: $(OBJS)
		$(GCC) -o $@ $^
$(OBJS)		: | $(ODIR)
$(ODIR)		:
		mkdir -p $(ODIR)
obj/%.o		: src/%.cpp
		$(GCC) -o $@ -c $< $(INC) $(CFLAGS)
$(NAME).pdf	: $(SRCS)
		a2ps -o - $(SRCS) | ps2pdf - $(NAME).pdf
clean		:
		$(RM) $(OBJS)
		$(RM) -r $(ODIR)
fclean		: clean
		$(RM) $(NAME)
re		: fclean all
.PHONY		: all clean fclean re