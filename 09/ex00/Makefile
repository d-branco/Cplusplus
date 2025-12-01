#  **************************************************************************  #
#                                           ::::::::    ::::::::   :::::::::   #
#    Makefile                             :+:    :+:  :+:    :+:  :+:          #
#                                              +:+         :+:   :+:           #
#    github.com/d-branco                    +#+         +#+      +#+#+#+       #
#                                        +#+         +#+              +#+      #
#    Created: 2025/07/08 21:04:23      #+#         #+#      +#+        #+#     #
#    Updated: 2025/12/01 14:04:43     #########  #########  ###      ###       #
#                                                             ########         #
#  **************************************************************************  #

NAME			:= btc
#NAME-BONUS		:= $(NAME)_bonus

FORMATABLE		= $(HEADERS) $(SRCS)

TEST_RUN		= $(NAME) $(DATABASE)
DATABASE		= ../cpp_09/data.csv
LINK			= https://cdn.intra.42.fr/document/document/40966/cpp_09.tgz

$(DATABASE):
	@\
	cd .. 																&& \
	echo "$(GRAY)Download link:$(COR)	$(LINK)"						; \
	wget --quiet --show-progress $(LINK) 								&& \
	echo "$(GRAY)Extract files:$(COR)	$(DATABASE)"					; \
	tar -xzf cpp_09.tgz													; \
	rm -f cpp_09.tgz													; \
	cd - > /dev/null ;
########################################################## Objects and Headers #
HEADERS			:=															\
	BitcoinExchange.hpp

SRCS			:=															\
	BitcoinExchange.cpp														\
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
DEBUG_FLAGS		+= -DDEBUG
########################################################### Intermediate steps #
RM				:= rm -f
AR				:= ar rcs
###################################################################### Targets #
all: $(NAME)

$(NAME): $(OBJS)
	@\
	echo "$(GRAY)Compiled with:$(COR)	$(CC)"							; \
	echo "$(GRAY)Compile flags:$(COR)	$(CFLAGS)"						; \
	$(CC) $(OBJS) $(INCLUDES)   $(CFLAGS) -o $(NAME)					&&	\
	echo "$(GRAY)File compiled:$(COR)	./$(NAME)"
#	echo "$(GRAY)Linking flags:$(COR)	$(INCLUDES)"					; \

$(BUILD_DIR)/%.o: /%.cpp
	@mkdir -p $(dir $@)
	@\
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@								&&	\
	echo "$(GRAY)File compiled:$(COR)	$<"

#bonus: $(NAME-BONUS)
#
#$(NAME-BONUS): $(OBJS-BONUS)
#	@\
#	echo "$(GRAY)Compiler:     $(COR)	$(CC)"							; \
#	echo "$(GRAY)Compile flags:$(COR)	$(CFLAGS)"						; \
#	$(CC) $(OBJS-BONUS) $(INCLUDES)   $(CFLAGS) -o $(NAME-BONUS)		&&	\
#	echo "$(GRAY)File compiled:$(COR)	./$(NAME-BONUS)"
#	echo "$(GRAY)Linking flags:$(COR)	$(INCLUDES)"					; \

clean:
	@\
	$(RM) -r $(BUILD_DIR)												; \
	rm -fr *.o *.gch 							 						; \
	echo "$(GRAY)Files cleaned.$(COR)"

fclean: clean
	@\
	$(RM) $(NAME) $(NAME-BONUS)											&&	\
	echo "$(GRAY)File fcleaned:$(COR)	./$(NAME)"

re: fclean all
	@echo "$(GRAY)redone$(COR)"

.PHONY: all clean fclean re headers clang-check line
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
	make headers --silent 												; \
	\
	clang-format -i $(NAME).cpp $(NAME).hpp								; \
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

format: headers .clang-format
	@\
	for file in $(FORMATABLE); do 											\
		if ! clang-format "$$file" | diff -q "$$file" - > /dev/null 2>&1; then \
			clang-format -i "$$file" 									&&	\
			echo "$(GRAY)File formated:$(COR)	$$file"; 					\
		fi; 																\
	done; 																	\
	rm -f .clang-format

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
	  -modernize-redundant-void-arg,\n\
	  -modernize-use-nullptr,\n\
	  cppcoreguidelines-*\n\
	  -cppcoreguidelines-avoid-magic-numbers,\n\
	  -cppcoreguidelines-pro-type-member-init,\n\
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
	clang-format --verbose --dry-run $(FORMATABLE)						; \
	clang-tidy --quiet -extra-arg=-std=c++98 $(FORMATABLE)				\
	-- $(CFLAGS)														; \
	rm -f .clang-format .clang-tidy										; \
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

clang-check:
	@\
	clang-check --analyze $(FORMATABLE) -- $(CFLAGS)					; \
	rm -f *.plist
####################################################################### Colors #
# COlor Remove
COR		:= \033[0m
PURPLE	:= \033[1;35m
GRAY	:= \033[1;90m
YELLOW	:= \033[1;93m
BLUE	:= \033[1;96m
######################################################################### Time #
time: $(NAME)
	time -f "  Total time: %E " ./$(TEST_RUN)

define TIMED_RUN
time -f "==CRONO== Total time: %E " 
endef
##################################################################### Valgrind #
valgrind: $(NAME)
	@\
	echo "$(GRAY)Executing arg:$(COR)	time valgrind ./$(TEST_RUN)"		; \
	$(TIMED_RUN) $(VALGRIND_CMD) ./$(TEST_RUN) $(VALGRIND_FILTER)


VALGRIND_CMD = valgrind \
	--track-fds=yes \
	--show-error-list=yes \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--max-stackframe=4200000

define VALGRIND_FILTER
2>&1 | while IFS= read -r line; do \
	case "$$line" in \
		*==DEBUG==*) printf '\033[33m%-80s \033[0m\n' "$$line" ;; \
		*==*[Cc]opyright*) ;; \
		*==*freed*--*no*leaks*) printf '\033[1;30m\033[102m%-80s \033[0m\n' "$$line" ;; \
		*==*ERROR*SUMMARY:*0*errors*from*0*contexts*) printf '\033[1;30m\033[102m%-80s \033[0m\n' "$$line" ;; \
		*==*[Ii]nvalid*) printf '\033[1;30m\033[101m%-80s \033[0m\n' "$$line" ; sleep 1 ;; \
		*==*[Uu]ninitialised*) printf '\033[1;30m\033[101m%-80s \033[0m\n' "$$line" ; sleep 1 ;; \
		*==*[Cc]onditional*) printf '\033[1;30m\033[101m%-80s \033[0m\n' "$$line" ; sleep 1 ;; \
		*==*[Ll]ost*bytes*) printf '\033[1;30m\033[101m%-80s \033[0m\n' "$$line" ; sleep 1 ;; \
		*==*definitely*lost*) printf '\033[1;30m\033[101m%-80s \033[0m\n' "$$line" ; sleep 1 ;; \
		*==*indirectly*lost*) printf '\033[1;30m\033[101m%-80s \033[0m\n' "$$line" ; sleep 1 ;; \
		*==*possibly*lost*) printf '\033[1;30m\033[101m%-80s \033[0m\n' "$$line" ; sleep 1 ;; \
		*==*still*reachable*) printf '\033[1;30m\033[101m%-80s \033[0m\n' "$$line" ; sleep 1 ;; \
		*==*[Mm]ismatch*) printf '\033[1;30m\033[101m%-80s \033[0m\n' "$$line" ; sleep 1 ;; \
		*==*Process*terminating*) printf '\033[1;30m\033[101m%-80s \033[0m\n' "$$line" ; sleep 1 ;; \
		*==*) printf '\033[32m%-80s \033[0m\n' "$$line" ;; \
		*) printf "$$line\n" ;;\
	esac; \
done
endef

######################################################################### Test #
test: CFLAGS += $(DEBUG_FLAGS)
test: check-guards clang-check fclean headers $(NAME) $(DATABASE)
	@\
	echo "\
	$(COR)$(GRAY)========================================== $(NAME) START\
	$(COR)" && \
	\
	make valgrind --silent												; \
	\
	echo "\
	$(COR)$(GRAY)========================================== $(NAME) END\n\
	$(COR)RETURN VALUE: $$?"											; \
	make style --silent


exe: headers format fclean $(NAME) $(DATABASE)
	@\
	echo "$(GRAY)Executing arg:$(COR)	time ./$(TEST_RUN)"				; \
	$(TIMED_RUN) ./$(TEST_RUN)

run: $(NAME)
	@\
	echo "$(GRAY)Executing arg:$(COR)	./$(TEST_RUN)"					; \
	./$(TEST_RUN)

define DEBUG_FILTER
2>&1 | while IFS= read -r line; do \
	case "$$line" in \
		*==DEBUG==*) printf '\033[33m%-80s \033[0m\n' "$$line" ;; \
		*) printf "$$line\n" ;;\
	esac; \
done
endef

debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean headers format $(NAME) $(DATABASE)
	@\
	echo "$(GRAY)Executing arg:$(COR)	time ./$(TEST_RUN)"				; \
	$(TIMED_RUN) ./$(TEST_RUN) $(DEBUG_FILTER)

gprof: CFLAGS += $(GPROF_FLAGS)
gprof: fclean headers $(NAME)
	@\
	echo "$(GRAY)Executing arg:$(COR)	gprof ./$(TEST_RUN)"			; \
	./$(TEST_RUN)														; \
	gprof $(NAME) gmon.out > gmon-ignoreme.txt							; \
	cat gmon-ignoreme.txt												; \
	rm -f gmon-ignoreme.txt gmon.out

######################################################################### Home #
define RUN_IN_HOME
	mv ./$(NAME) ~/$(NAME) && \
	chmod +x ~/$(NAME)
endef

define CLEANUP_HOME
	rm -f ~/$(NAME)
endef
homerun: fclean headers format $(NAME)
	@\
	echo "$(GRAY)Executing arg:$(COR)	time ./$(TEST_RUN)"					; \
	$(RUN_IN_HOME) 														; \
	$(TIMED_RUN)  ~/$(TEST_RUN) 											; \
	$(CLEANUP_HOME)

homedebug: CFLAGS += $(DEBUG_FLAGS)
homedebug: fclean headers format $(NAME)
	@\
	echo "$(GRAY)Executing arg:$(COR)	./$(TEST_RUN)"					; \
	$(RUN_IN_HOME) 														; \
	~/$(TEST_RUN) $(DEBUG_FILTER) 										; \
	$(CLEANUP_HOME)

homevalgrind: fclean headers format $(NAME)
	@\
	echo "$(GRAY)Executing arg:$(COR)	./$(TEST_RUN)"					; \
	$(RUN_IN_HOME) 														; \
	$(VALGRIND_CMD) ~/$(TEST_RUN) $(VALGRIND_FILTER)					; \
	$(CLEANUP_HOME)

######################################################################### Line #
line: CFLAGS += $(DEBUG_FLAGS)
line: fclean format headers $(NAME) $(DATABASE)
	@\
	echo "$(GRAY)Executing arg:$(COR)	time ./$(TEST_RUN)"					; \
	$(TIMED_RUN) $(VALGRIND_CMD) ./$(TEST_RUN) 2>&1 | while IFS= read -r line; do \
		case "$$line" in \
			*==DEBUG==*) printf '\033[33m%-80s \033[0m\n' "$$line" ; sleep 0.01 ;; \
			*==*[Cc]opyright*) ;; \
			*==*freed*--*no*leaks*) printf '\033[1;30m\033[102m%-80s \033[0m\n' "$$line" ; sleep 0.01 ;; \
			*==*ERROR*SUMMARY:*0*errors*from*0*contexts*) printf '\033[1;30m\033[102m%-80s \033[0m\n' "$$line" ; sleep 0.01 ;; \
			*==*[Ii]nvalid* | *==*[Uu]ninitialised* | *==*[Cc]onditional* | *==*[Ll]ost*bytes* | \
			*==*definitely*lost* | *==*indirectly*lost* | *==*possibly*lost* | *==*still*reachable* | \
			*==*[Mm]ismatch* | *==*Process*terminating*) \
				printf '\033[1;30m\033[101m%-80s \033[0m\n' "$$line" ; sleep 1 ;; \
			*==*) printf '\033[32m%-80s \033[0m\n' "$$line" ; sleep 0.01 ;; \
			*) printf "$$line\n" ; sleep 0.042 ;;\
		esac; \
	done

homeline: CFLAGS += $(DEBUG_FLAGS)
homeline: fclean format headers $(NAME)
	@\
	echo "$(GRAY)Executing arg:$(COR)	./$(TEST_RUN)"					; \
	$(RUN_IN_HOME); \
	~/$(TEST_RUN) 2>&1 | while IFS= read -r line; do \
		case "$$line" in \
			*==DEBUG==*) printf '\033[33m%-80s \033[0m\n' "$$line" ; sleep 0.01 ;; \
			*==*[Cc]opyright*) ;; \
			*==*freed*--*no*leaks*) printf '\033[1;30m\033[102m%-80s \033[0m\n' "$$line" ; sleep 0.01 ;; \
			*==*ERROR*SUMMARY:*0*errors*from*0*contexts*) printf '\033[1;30m\033[102m%-80s \033[0m\n' "$$line" ; sleep 0.01 ;; \
			*==*[Ii]nvalid* | *==*[Uu]ninitialised* | *==*[Cc]onditional* | *==*[Ll]ost*bytes* | \
			*==*definitely*lost* | *==*indirectly*lost* | *==*possibly*lost* | *==*still*reachable* | \
			*==*[Mm]ismatch* | *==*Process*terminating*) \
				printf '\033[1;30m\033[101m%-80s \033[0m\n' "$$line" ; sleep 1 ;; \
			*==*) printf '\033[32m%-80s \033[0m\n' "$$line" ; sleep 0.01 ;; \
			*) printf "$$line\n" ; sleep 0.042 ;;\
		esac; \
	done; \
	$(CLEANUP_HOME)
