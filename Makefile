NAME	= epil
LNAME	= epil.a
GCC	= g++
RM	= rm -f

CFLAGS	= -W -Wall -Wextra -Werror -std=c++0x

SDIR	= main Modules Modules/Actions
ODIR	= obj/ $(addprefix obj/, $(SDIR))
HDIR	= . Modules Modules/Actions Utils Exceptions
LDIR	= lib
BDIR	= bin

SRCS	= $(shell find src/ \( -iname "*.cpp" \))
OBJS	= $(subst src,obj,$(SRCS:.cpp=.o))
INCS	= $(foreach d, $(HDIR), -Iheaders/$d)
HDRS	= $(shell find headers/ \( -iname "*.hpp" -iname "*.hh" -iname "*.h" \))

all		: $(NAME)
lib		: $(LNAME)
$(LNAME)	: $(OBJS)
		ar rc $(LDIR)/$@ $^
		ranlib $(LDIR)/$@

$(NAME)		: $(OBJS)
		@mkdir -p $(BDIR)
		$(GCC) -o $(BDIR)/$@ $^
$(OBJS)		: | $(ODIR)
$(ODIR) 	:
		@mkdir -p $(ODIR)
obj/%.o		: src/%.cpp
		$(GCC) $(CFLAGS) $(INC) -o $@ -c $<

clean		:
		$(RM) $(OBJS)
		$(RM) -r $(ODIR)
fclean		: clean
		$(RM) $(BDIR)/$(NAME)
re		: fclean all

.PHONY		: all bin clean fclean re
