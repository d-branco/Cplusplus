#  **************************************************************************  #
#                                           ::::::::    ::::::::   :::::::::   #
#    Makefile                             :+:    :+:  :+:    :+:  :+:          #
#                                              +:+         :+:   :+:           #
#    github.com/d-branco                    +#+         +#+      +#+#+#+       #
#                                        +#+         +#+              +#+      #
#    Created: 2025/07/08 21:04:23      #+#         #+#      +#+        #+#     #
#    Updated: 2025/11/22 11:07:55     #########  #########  ###      ###       #
#                                                             ########         #
#  **************************************************************************  #

NAME			:= shrubbery.out
#NAME-BONUS		:= $(NAME)_bonus

FORMATABLE		= $(HEADERS) $(SRCS)

TEST_RUN		:= $(NAME)
########################################################## Objects and Headers #
HEADERS			:=															\
	Bureaucrat.hpp															\
	AForm.hpp																\
	PresidentialPardonForm.hpp												\
	RobotomyRequestForm.hpp													\
	ShrubberyCreationForm.hpp												\

SRCS			:=															\
	Bureaucrat.cpp															\
	AForm.cpp																\
	PresidentialPardonForm.cpp												\
	RobotomyRequestForm.cpp													\
	ShrubberyCreationForm.cpp												\
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

.PHONY: all clean fclean re headers
######################################################################## Class #
class: .clang-format
	@if [ -z "$(NAME)" ]; then 												\
		echo "Usage: make class NAME=ClassName"; 							\
		exit 0; 															\
	fi; 																	\
	if [ -f $(NAME).hpp ] || [ -f $(NAME).cpp ]; then 						\
		echo "$(YELLOW)$(NAME).hpp or $(NAME).cpp already exists$(COR)"; 	\
		exit 0; 															\
	fi; 																	\
	if ! echo "$(NAME)" | grep -qE '^[A-Z][a-zA-Z0-9]*$$'; then 			\
		echo "$(YELLOW)Class name must be in CamelCase$(COR)"; 				\
		exit 0; 															\
	fi; 																	\
																			\
	echo "#ifndef $(shell echo $(NAME) | tr a-z A-Z)_HPP" 	> $(NAME).hpp; \
	echo "#define $(shell echo $(NAME) | tr a-z A-Z)_HPP" 	>> $(NAME).hpp; \
	echo "" 												>> $(NAME).hpp; \
	echo "class $(NAME)" 									>> $(NAME).hpp; \
	echo "{" 												>> $(NAME).hpp; \
	echo "  private:" 										>> $(NAME).hpp; \
	echo "  public:" 										>> $(NAME).hpp; \
	echo "" 												>> $(NAME).hpp; \
	echo "	/////////////////////////////////////////////////"\
	" Canonical Orthodox Form //"							>> $(NAME).hpp; \
	echo "	$(NAME)();" 									>> $(NAME).hpp; \
	echo "	$(NAME)(const $(NAME) &other);" 				>> $(NAME).hpp; \
	echo "	$(NAME) &operator=(const $(NAME) &other);" 		>> $(NAME).hpp; \
	echo "	~$(NAME)();" 									>> $(NAME).hpp; \
	echo "" 												>> $(NAME).hpp; \
	echo "	/////////////////////////////////////////////////"\
	"//////////////// Getters //"							>> $(NAME).hpp; \
	echo "	/////////////////////////////////////////////////"\
	"//////////////// Setters //"							>> $(NAME).hpp; \
	echo "	/////////////////////////////////////////////////"\
	"////////////// Functions //"							>> $(NAME).hpp; \
	echo "};" 												>> $(NAME).hpp; \
	echo "" 												>> $(NAME).hpp; \
	echo "#endif" 											>> $(NAME).hpp; \
																			\
	echo "#include \"$(NAME).hpp\"" 						> $(NAME).cpp; \
	echo "" 												>> $(NAME).cpp; \
	echo "/////////////////////////////////////////////////////"\
	" Canonical Orthodox Form //"							>> $(NAME).cpp; \
	echo "$(NAME)::$(NAME)()" 								>> $(NAME).cpp; \
	echo "{" 												>> $(NAME).cpp; \
	echo "}" 												>> $(NAME).cpp; \
	echo "" 												>> $(NAME).cpp; \
	echo "$(NAME)::$(NAME)(const $(NAME) &other)" 			>> $(NAME).cpp; \
	echo "{" 												>> $(NAME).cpp; \
	echo "	*this = other;" 								>> $(NAME).cpp; \
	echo "}" 												>> $(NAME).cpp; \
	echo "" 												>> $(NAME).cpp; \
	echo "$(NAME) &$(NAME)::operator=(const $(NAME) &other)" >> $(NAME).cpp; \
	echo "{" 												>> $(NAME).cpp; \
	echo "	if (this == &other)" 							>> $(NAME).cpp; \
	echo "	{" 												>> $(NAME).cpp; \
	echo "		return (*this);" 							>> $(NAME).cpp; \
	echo "	}" 												>> $(NAME).cpp; \
	echo "" 												>> $(NAME).cpp; \
	echo "	return (*this);" 								>> $(NAME).cpp; \
	echo "}" 												>> $(NAME).cpp; \
	echo "" 												>> $(NAME).cpp; \
	echo "$(NAME)::~$(NAME)()" 								>> $(NAME).cpp; \
	echo "{" 												>> $(NAME).cpp; \
	echo "}" 												>> $(NAME).cpp; \
	echo "" 												>> $(NAME).cpp; \
	echo "/////////////////////////////////////////////////////"\
	"//////////////// Getters //"							>> $(NAME).cpp; \
	echo "/////////////////////////////////////////////////////"\
	"//////////////// Setters //"							>> $(NAME).cpp; \
	echo "/////////////////////////////////////////////////////"\
	"////////////// Functions //"							>> $(NAME).cpp; \
	echo "$(GRAY)Class created:$(COR) $(NAME)" ; 							\
	\
	make headers --silent 												;	\
	\
	clang-format -i $(NAME).cpp $(NAME).hpp								;	\
	rm -f .clang-format
###################################################################### Headers #
headers:
	@for file in $$(find . -name "Makefile"); do 							\
		if [ -f "$$file" ]; then 											\
			first_line=$$(head -n 1 "$$file"); 								\
			if [ "$$first_line" != "#  ************************************"\
	"**************************************  #" ]; then 					\
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
				echo "$(GRAY)Header create:$(COR) $$file"; 					\
			else 															\
				header_date=$$(sed -n '8p' "$$file" | 						\
					sed 's/.*Updated: \([0-9/: ]*\).*/\1/'); 				\
																			\
				header_epoch=$$(date -d "$$header_date" \
						+%s 2>/dev/null || echo 0); \
																			\
				file_epoch=$$(stat -c %Y "$$file"); 						\
																			\
				if [ $$file_epoch -gt $$header_epoch ]; then 				\
					echo "$(GRAY)Header update:$(COR) $$file"; 				\
					update_date=$$(date '+%Y/%m/%d %H:%M:%S'); 				\
					sed -i "8s|.*|#    Updated: $$update_date"\
	"     #########  #########  ###      ###       #|" "$$file"; 			\
				fi; 														\
																			\
			fi; 															\
		fi; 																\
	done;																	\
																			\
	for file in $$(find . -name "*.cpp" -o -name "*.hpp"); do 				\
		if [ -f "$$file" ]; then 											\
			first_line=$$(head -n 1 "$$file"); 								\
			if [ "$$first_line" != "/* ************************************"\
	"************************************** */" ]; then 					\
				echo "/* ************************************"\
	"************************************** */" > temp.txt ; 				\
				echo "/*                                     "\
	"     ::::::::    ::::::::   :::::::::  */" >> temp.txt ; 				\
				printf "/*   %-36.36s :+:    :+:  :+:    :+:  :+:         */\n"\
					"$$(basename $$file)" >> temp.txt; \
				echo "/*                                     "\
	"        +:+         :+:   :+:          */" >> temp.txt ; 				\
				echo "/*   github.com/d-branco               "\
	"     +#+         +#+      +#+#+#+      */" >> temp.txt ; 				\
				echo "/*                                     "\
	"  +#+         +#+              +#+     */" >> temp.txt ; 				\
				echo "/*   Created: $$(date '+%Y/%m/%d %H:%M:%S')      "\
	"#+#         #+#      +#+        #+#    */" >> temp.txt ; 				\
				echo "/*   Updated: $$(date '+%Y/%m/%d %H:%M:%S')     #"\
	"########  #########  ###      ###      */" >> temp.txt ; 				\
				echo "/*                                     "\
	"                       ########        */" >> temp.txt ; 				\
				echo "/* ************************************"\
	"************************************** */" >> temp.txt ; 				\
				echo "" >> temp.txt ; 										\
				cat $$file >> temp.txt; 									\
				cat temp.txt > $$file; 										\
				rm -f temp.txt; 											\
				echo "$(GRAY)Header create:$(COR) $$file"; 					\
			else 															\
				header_date=$$(sed -n '8p' "$$file" | 						\
					sed 's/.*Updated: \([0-9/: ]*\).*/\1/'); 				\
																			\
																			\
				header_epoch=$$(date -d "$$header_date" \
						+%s 2>/dev/null || echo 0); \
																			\
				file_epoch=$$(stat -c %Y "$$file"); 						\
																			\
				if [ $$file_epoch -gt $$header_epoch ]; then 				\
					echo "$(GRAY)Header update:$(COR) $$file"; 				\
					update_date=$$(date '+%Y/%m/%d %H:%M:%S'); 				\
					sed -i "8s|.*|/*   Updated: $$update_date"\
	"     #########  #########  ###      ###      */|" "$$file"; 			\
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
	  -cppcoreguidelines-avoid-const-or-ref-data-members\n\
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
# COlor Remove
COR		:= \033[0m
PURPLE	:= \033[1;35m
GRAY	:= \033[1;90m
YELLOW	:= \033[1;93m
BLUE	:= \033[1;96m
######################################################################### Test #
test: CFLAGS += $(DEBUG_FLAGS)
test: fclean headers $(NAME)
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

exe: headers fclean $(NAME)
	@\
	./$(TEST_RUN)

run: headers $(NAME)
	@\
	./$(TEST_RUN)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean headers $(NAME)
	@\
	./$(TEST_RUN)

gprof: CFLAGS += $(GPROF_FLAGS)
gprof: fclean headers $(NAME)
	@\
	./$(TEST_RUN)														;	\
	gprof $(NAME) gmon.out > gmon-ignoreme.txt							;	\
	cat gmon-ignoreme.txt												;	\
	rm -f gmon-ignoreme.txt gmon.out

homerun: headers $(NAME)
	@\
	mv ./$(NAME) ~/$(NAME)												&&	\
	chmod +x ~/$(NAME)													;	\
	~/$(TEST_RUN)														;	\
	rm -f ~/$(NAME)

homedebug: CFLAGS += $(DEBUG_FLAGS)
homedebug: fclean headers $(NAME)
	@\
	mv ./$(NAME) ~/$(NAME)												&&	\
	chmod +x ~/$(NAME)													;	\
	~/$(TEST_RUN)														;	\
	rm -f ~/$(NAME)
