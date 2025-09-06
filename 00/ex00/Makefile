#  **************************************************************************  #
#                                           ::::::::    ::::::::   :::::::::   #
#    Makefile                             :+:    :+:  :+:    :+:  :+:          #
#                                              +:+         :+:   :+:           #
#    github.com/d-branco                    +#+         +#+      +#+#+#+       #
#                                        +#+         +#+              +#+      #
#    Created: 2025/07/08 21:04:23      #+#         #+#      +#+        #+#     #
#    Updated: 2025/08/25 18:55:31     #########  #########  ###      ###       #
#                                                             ########         #
#  **************************************************************************  #

NAME			:= megaphone
#NAME-BONUS		:= $(NAME)_bonus

##################################################################### Compiler #
CC				:= c++
CFLAGS			+= -std=c++98
CFLAGS			+= -Wall -Wextra
CFLAGS			+= -Werror

GPROF_FLAGS		+= -pg
DEBUG_FLAGS		+= -g
DEBUG_FLAGS		+= -D DEBUG=1
########################################################### Intermediate steps #
RM				:= rm -f
AR				:= ar rcs
########################################################## Objects and Headers #
#INCLUDES		:= -I./include
BUILD_DIR		:= build
SRCS			:=	\
	megaphone.cpp

OBJS			:= $(SRCS:/%.cpp=$(BUILD_DIR)/%.o)
#SRCS-BONUS		:=
#
#OBJS-BONUS		:= $(SRCS-BONUS:/%.cpp=$(BUILD_DIR)/%.o)
###################################################################### Targets #
all: $(NAME)

$(NAME): $(OBJS)
	@\
	echo "$(GRAY)Compiled with:$(COR)	$(CC)"							;	\
	echo "$(GRAY)Compile flags:$(COR)	$(CFLAGS)"						;	\
	$(CC) $(OBJS) $(INCLUDES)   $(CFLAGS) -o $(NAME)					&&	\
	echo "$(GRAY)File compiled:$(COR)	./$(NAME)"
#	echo "$(GRAY)Linking flags:$(COR)	$(INCLUDES)"					;	\

$(BUILD_DIR)/%.o: /%.cpp
	@mkdir -p $(dir $@)
	@\
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@								&&	\
	echo "$(GRAY)File compiled:$(COR)	$<"

#bonus: $(NAME-BONUS)
#
#$(NAME-BONUS): $(OBJS-BONUS)
#	@\
#	echo "$(GRAY)Compiler:     $(COR)	$(CC)"							;	\
#	echo "$(GRAY)Compile flags:$(COR)	$(CFLAGS)"						;	\
#	$(CC) $(OBJS-BONUS) $(INCLUDES)   $(CFLAGS) -o $(NAME-BONUS)		&&	\
#	echo "$(GRAY)File compiled:$(COR)	./$(NAME-BONUS)"
#	echo "$(GRAY)Linking flags:$(COR)	$(INCLUDES)"					;	\

clean:
	@\
	$(RM) -r $(BUILD_DIR)												;	\
	rm -fr *.o *.gch													;	\
	echo "$(GRAY)Files cleaned.$(COR)"

fclean: clean
	@\
	$(RM) $(NAME) $(NAME-BONUS)											&&	\
	echo "$(GRAY)File fcleaned.$(COR)"

re: fclean all
	@echo "$(GRAY)redone$(COR)"

.PHONY: all clean fclean re
#################################################################### formatter #
.clang-format:
	@echo "\
	Language: Cpp\n\
	\n\
	AlignConsecutiveDeclarations:\n\
	  Enabled: true\n\
	  AcrossEmptyLines: false\n\
	  AcrossComments: false\n\
	  AlignCompound: false\n\
	  AlignFunctionPointers: false\n\
	  PadOperators: true\n\
	AlignEscapedNewlinesLeft: true\n\
	AllowAllParametersOfDeclarationOnNextLine: false\n\
	AllowShortBlocksOnASingleLine: false\n\
	AllowShortFunctionsOnASingleLine: None\n\
	AlwaysBreakAfterReturnType: None\n\
	AlwaysBreakBeforeMultilineStrings: false\n\
	BinPackArguments: true\n\
	BinPackParameters: true\n\
	BreakBeforeBraces: Allman\n\
	BreakBeforeTernaryOperators: false\n\
	ColumnLimit: 80\n\
	IndentWidth: 4\n\
	KeepEmptyLinesAtTheStartOfBlocks: false\n\
	MaxEmptyLinesToKeep: 1\n\
	PointerAlignment: Right\n\
	PenaltyBreakBeforeFirstCallParameter: 1\n\
	PenaltyBreakString: 1\n\
	PenaltyExcessCharacter: 0\n\
	SpaceAfterCStyleCast: true\n\
	SpaceBeforeAssignmentOperators: true\n\
	SpaceBeforeParens: ControlStatements\n\
	SpaceInEmptyParentheses: false\n\
	SpacesInCStyleCastParentheses: false\n\
	SpacesInParentheses: false\n\
	SpacesInSquareBrackets: false\n\
	TabWidth: 4\n\
	UseTab: Always\n\
	" > .clang-format

style: .clang-format
	@\
	clang-format --verbose --dry-run *.cpp								;	\
	rm -f .clang-format													;	\
	echo "\
	Checks: 'readability-*,bugprone-*,performance-*,modernize-*,\n\
	         -modernize-use-trailing-return-type'\n\
	CheckOptions:\n\
	  - key: readability-identifier-naming.ClassCase\n\
	    value: CamelCase\n\
	" > .clang-tidy														;	\
	clang-tidy --quiet *.cpp -- -std=c++98 -Wall -Wextra -Werror		;	\
	rm -f .clang-tidy

format: .clang-format
	@\
	clang-format -i *.cpp												&&	\
	echo "formatted"													;	\
	rm -f .clang-format

####################################################################### Colors #
COR		:= \033[0m# COlor Remove
PURPLE	:= \033[1;35m# purple
GRAY	:= \033[1;90m# gray
YELLOW	:= \033[1;93m# yellow
BLUE	:= \033[1;96m# blue
######################################################################### Test #
test: CFLAGS += $(DEBUG_FLAGS)
test: fclean $(NAME)
	@\
	echo "\
	$(COR)$(GRAY)========================================== $(NAME) START\
	$(COR)" && \
	\
	valgrind																\
		--track-fds=yes														\
		--show-error-list=yes												\
		--leak-check=full													\
		--show-leak-kinds=all												\
		--track-origins=yes													\
		--max-stackframe=4200000											\
	\
		./$(NAME)														;	\
	\
	echo "\
	$(COR)$(GRAY)========================================== $(NAME) END\n\
	$(COR)RETURN VALUE: $$?"											;	\
	clang-format --dry-run *.cpp										;	\
	rm -f $(NAME)

valgrind: $(NAME)
	@\
	valgrind																\
		--track-fds=yes														\
		--show-error-list=yes												\
		--leak-check=full													\
		--show-leak-kinds=all												\
		--track-origins=yes													\
		--max-stackframe=4200000											\
	\
		./$(NAME)														;	\
	rm -f $(NAME)

exe: fclean $(NAME)
	@\
	./$(NAME)															;	\
	rm -f $(NAME)

run: $(NAME)
	@\
	./$(NAME)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean $(NAME)
	@\
	./$(NAME)															;	\
	rm -f $(NAME)

gprof: CFLAGS += $(GPROF_FLAGS)
gprof: fclean $(NAME)
	@\
	./$(NAME)															;	\
	gprof $(NAME) gmon.out > gmon-ignoreme.txt							;	\
	cat gmon-ignoreme.txt												;	\
	rm -f gmon-ignoreme.txt gmon.out									;	\
	rm -f $(NAME)
