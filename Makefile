NAME	= epil
LNAME	= epil.a
GCC	= g++
RM	= rm -f

CFLAGS	= -W -Wall -Wextra -Werror -std=c++0x

SDIR	= main Modules Modules/Actions
ODIR	= obj/ $(addprefix obj/, $(SDIR))
LODIR	= lib/obj/ $(addprefix lib/obj/, $(SDIR))
HDIR	= . Modules Modules/Actions Utils Exceptions
LDIR	= lib
BDIR	= bin

SRCS	= $(shell find src/ \( -iname "*.cpp" \))
LIBSRCS	= $(shell find lib/src/ \( -iname "*.cpp" \))
OBJS	= $(subst src,obj,$(SRCS:.cpp=.o))
LIBOBJS	= $(subst lib/src,lib/obj,$(LIBSRCS:.cpp=.o))
INCS	= $(foreach d, $(HDIR), -Iheaders/$d)
HDRS	= $(shell find headers/ \( -iname "*.hpp" -iname "*.hh" -iname "*.h" \))

all		: $(NAME)
lib		: $(LNAME)

$(NAME)		: $(OBJS)
		@mkdir -p $(BDIR)
		$(GCC) -o $(BDIR)/$@ $^
$(LNAME)	: $(LIBOBJS)
		ar rc $(LDIR)/$@ $^
		ranlib $(LDIR)/$@
$(OBJS)		: | $(ODIR)
$(LIBOBJS)	: | $(LODIR)
$(ODIR) 	:
		@mkdir -p $(ODIR)
$(LODIR)	:
		mkdir -p $(LODIR)
obj/%.o		: src/%.cpp
		echo "IN FIRST TARGET"
		$(GCC) $(CFLAGS) $(INCS) -o $@ -c $<
lib/obj/%.o	: lib/src/%.cpp
		echo "IN SECOND TARGET"
		$(GCC) $(CFLAGS) $(INCS) -o $@ -c $<

clean		:
		$(RM) $(OBJS)
		$(RM) -r $(ODIR)
fclean		: clean
		$(RM) $(BDIR)/$(NAME)
re		: fclean all

.PHONY		: all bin clean fclean re
