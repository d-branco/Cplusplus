#  **************************************************************************  #
#                                           ::::::::    ::::::::   :::::::::   #
#    Makefile                             :+:    :+:  :+:    :+:  :+:          #
#                                              +:+         :+:   :+:           #
#    github.com/d-branco                    +#+         +#+      +#+#+#+       #
#                                        +#+         +#+              +#+      #
#    Created: 2025/07/08 21:04:23      #+#         #+#      +#+        #+#     #
#    Updated: 2025/10/28 16:08:27     #########  #########  ###      ###       #
#                                                             ########         #
#  **************************************************************************  #

NAME			:= bureaucrat.out
#NAME-BONUS		:= $(NAME)_bonus

FORMATABLE		= $(HEADERS) $(SRCS)

TEST_RUN		:= $(NAME)
########################################################## Objects and Headers #
HEADERS			:=															\
	Bureaucrat.hpp															\

SRCS			:=															\
	Bureaucrat.cpp															\
	\
	main.cpp

OBJS 			:= $(SRCS:/%.cpp=$(BUILD_DIR)/%.o)
#SRCS-BONUS		:=
#
#OBJS-BONUS		:= $(SRCS-BONUS:/%.cpp=$(BUILD_DIR)/%.o)

#INCLUDES		:= -I./include

BUILD_DIR		:= build
##################################################################### Compiler #
CC				:= c++
CFLAGS			+= -std=c++98
CFLAGS			+= -Wall -Wextra
CFLAGS			+= -Werror
CFLAGS			+= -Wshadow
#CFLAGS			+= -Wno-shadow

GPROF_FLAGS		+= -pg
DEBUG_FLAGS		+= -g
DEBUG_FLAGS		+= -D DEBUG=1
########################################################### Intermediate steps #
RM				:= rm -f
AR				:= ar rcs
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
	rm -fr *.o *.gch 							 						;	\
	echo "$(GRAY)Files cleaned.$(COR)"

fclean: clean
	@\
	$(RM) $(NAME) $(NAME-BONUS)											&&	\
	echo "$(GRAY)File fcleaned.$(COR)"

re: fclean all
	@echo "$(GRAY)redone$(COR)"

.PHONY: all clean fclean re ad
###################################################################### Headers #
addendum:
	@for file in $$(find . -name "Makefile"); do 							\
		if [ -f "$$file" ]; then 											\
			first_line=$$(head -n 1 "$$file"); 								\
			if [ "$$first_line" != "#  ************************************"\
	"**************************************  #" ]; then 					\
				echo "    File lacks a header:  $$file"; 					\
				echo "#  ************************************"\
	"**************************************  #" > temp.txt ; 				\
				echo "#                                      "\
	"     ::::::::    ::::::::   :::::::::   #" >> temp.txt ; 				\
				echo "#    Makefile                          "\
	"   :+:    :+:  :+:    :+:  :+:          #" >> temp.txt ; 				\
				echo "#                                      "\
	"        +:+         :+:   :+:           #" >> temp.txt ; 				\
				echo "#    github.com/d-branco               "\
	"     +#+         +#+      +#+#+#+       #" >> temp.txt ; 				\
				echo "#                                      "\
	"  +#+         +#+              +#+      #" >> temp.txt ; 				\
				echo "#    Created: $$(date '+%Y/%m/%d %H:%M:%S')      "\
	"#+#         #+#      +#+        #+#     #" >> temp.txt ; 				\
				echo "#    Updated: $$(date '+%Y/%m/%d %H:%M:%S')     #"\
	"########  #########  ###      ###       #" >> temp.txt ; 				\
				echo "#                                      "\
	"                       ########         #" >> temp.txt ; 				\
				echo "#  ************************************"\
	"**************************************  #" >> temp.txt ; 				\
				echo "" >> temp.txt ; 										\
				cat $$file >> temp.txt; 									\
				cat temp.txt > $$file; 										\
				rm -f temp.txt; 											\
				echo "    File goten a header:  $$file"; 					\
			else 															\
				echo "    $(GRAY)File has header:      $$file$(COR)"; 		\
																			\
				header_date=$$(sed -n '8p' "$$file" | 						\
					sed 's/.*Updated: \([0-9/: ]*\).*/\1/'); 				\
				echo "        Header date:  $$header_date" ; 				\
																			\
																			\
				header_epoch=$$(date -d "$$header_date" \
						+%s 2>/dev/null || echo 0); \
				echo "        Header epoch: $$header_epoch" ; 				\
																			\
				file_epoch=$$(stat -c %Y "$$file"); 						\
				echo "        Update date:  $$file_epoch" ; 				\
																			\
				if [ $$file_epoch -gt $$header_epoch ]; then 				\
					echo "        Updating header date in $$file"; 			\
					update_date=$$(date '+%Y/%m/%d %H:%M:%S'); 				\
					sed -i "8s|.*|#    Updated: $$update_date"\
	"     #########  #########  ###      ###       #|" "$$file"; 			\
				echo "#    Updated: 20XX/XX/XX XX:XX:XX     #"				\
					>> temp.txt ; 											\
				else \
					echo "        $$file unchanged since last update"; 		\
				fi; 														\
																			\
			fi; 															\
		fi; 																\
	done

####################################################################### Format #
.clang-format:
	@echo "\
	Language: Cpp\n\
	\n\
	AlignConsecutiveDeclarations:\n\
	  Enabled: true\n\
	  AcrossEmptyLines: true\n\
	  AcrossComments: true\n\
	  AlignCompound: true\n\
	  AlignFunctionPointers: false\n\
	  PadOperators: true\n\
	AlignConsecutiveMacros:\n\
	  Enabled: true\n\
	  AcrossEmptyLines: false\n\
	  AcrossComments: false\n\
	  AlignCompound: false\n\
	  PadOperators: true\n\
	AlignAfterOpenBracket: Align\n\
	AlignConsecutiveAssignments: true\n\
	AlignEscapedNewlinesLeft: true\n\
	AllowAllConstructorInitializersOnNextLine: false\n\
	AllowAllParametersOfDeclarationOnNextLine: false\n\
	AllowShortBlocksOnASingleLine: false\n\
	AllowShortIfStatementsOnASingleLine: false\n\
	AllowShortFunctionsOnASingleLine: None\n\
	AlwaysBreakAfterReturnType: None\n\
	AlwaysBreakBeforeMultilineStrings: false\n\
	BinPackArguments: false\n\
	BinPackParameters: false\n\
	BreakBeforeBraces: Allman\n\
	BreakBeforeBinaryOperators: All\n\
	BreakBeforeTernaryOperators: false\n\
	BreakConstructorInitializers: AfterColon\n\
	PackConstructorInitializers: CurrentLine\n\
	ColumnLimit: 80\n\
	ConstructorInitializerIndentWidth: 4\n\
	IndentPPDirectives: AfterHash\n\
	IndentWidth: 4\n\
	KeepEmptyLinesAtTheStartOfBlocks: false\n\
	MaxEmptyLinesToKeep: 1\n\
	PointerAlignment: Right\n\
	PenaltyBreakBeforeFirstCallParameter: 100\n\
	PenaltyBreakString: 100\n\
	PenaltyExcessCharacter: 1000000\n\
	PPIndentWidth: 1\n\
	RemoveBracesLLVM: false\n\
	SeparateDefinitionBlocks: Always\n\
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

format: .clang-format
	@\
	clang-format -i $(FORMATABLE)										&&	\
	echo "formatted"													;	\
	rm -f .clang-format

# Consider removing
#	  -cppcoreguidelines-avoid-magic-numbers
.clang-tidy:
	@\
	echo "\
	Checks: |\n\
	  readability-*,\n\
	  -readability-magic-numbers,\n\
	  bugprone-*,\n\
	  performance-*,\n\
	  clang-analyzer-*,\n\
	  modernize-*,\n\
	  -modernize-use-trailing-return-type,\n\
	  cppcoreguidelines-*\n\
	  -cppcoreguidelines-pro-type-member-init,\n\
	  -cppcoreguidelines-avoid-magic-numbers\n\
	\n\
	CheckOptions:\n\
	  - key:   readability-identifier-naming.ClassCase\n\
	    value: CamelCase\n\
	  - key:   readability-identifier-naming.FunctionCase\n\
	    value: lower_case\n\
	  - key:   readability-identifier-naming.PrivateMemberSuffix\n\
	    value: '_'\n\
	\n\
	HeaderFilterRegex: '.*'\n\
	" > .clang-tidy

style: .clang-format .clang-tidy
	@\
	clang-format --verbose --dry-run $(FORMATABLE)						;	\
	clang-tidy --quiet -extra-arg=-std=c++98 $(FORMATABLE)					\
	-- $(CFLAGS)														;	\
	rm -f .clang-format .clang-tidy										;	\
	make check-guards --silent

check-guards:
	@fail=0; \
	for file in $$(find . -name "*.hpp"); do \
		filename=$$(basename $$file); \
		guard=$$(echo $$filename | tr 'a-z' 'A-Z' | sed 's/\./_/g'); \
		if ! grep -q "#ifndef $$guard" $$file\
			|| ! grep -q "#define $$guard" $$file; then \
			echo "$(YELLOW)$$file  is missing header guard:$(COR)\
			\n#ifndef $$guard\n#define $$guard\n\n#endif"; \
			fail=1; \
		fi; \
	done;
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
	make valgrind --silent												;	\
	\
	echo "\
	$(COR)$(GRAY)========================================== $(NAME) END\n\
	$(COR)RETURN VALUE: $$?"											;	\
	make style --silent

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
		./$(TEST_RUN)

exe: fclean $(NAME)
	@\
	./$(TEST_RUN)

run: $(NAME)
	@\
	./$(TEST_RUN)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean $(NAME)
	@\
	./$(TEST_RUN)

gprof: CFLAGS += $(GPROF_FLAGS)
gprof: fclean $(NAME)
	@\
	./$(TEST_RUN)														;	\
	gprof $(NAME) gmon.out > gmon-ignoreme.txt							;	\
	cat gmon-ignoreme.txt												;	\
	rm -f gmon-ignoreme.txt gmon.out
