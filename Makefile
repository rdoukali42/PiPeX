NAME = pipex
NAMEB = pipex_bonus

INCLUDE = -I ./Headers

SRCS 		=	$(shell find ./src_mnd -name "*.c")

SRCS_BONUS 	=	$(shell find ./src_bns -name "*.c")
# BONS		= 	$(addprefix $(BONS_DIR), $(SRCS_BONUS))
BONS 		=	$(SRCS_BONUS:.c=.o)


OBJS 		=	$(SRCS:.c=.o)

CC = gcc

CFLAG = -Wall -Wextra -Werror

%.o : %.c
	@${CC} $(INCLUDE) ${CFLAG} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
		@echo "\033[33m---------------- Compiling ... --------------------"
		@echo " "
		@echo "\033[36m       ██████╗  ██╗ ██████╗  ███████╗ ██╗  ██╗"
		@echo "       ██╔══██╗ ██║ ██╔══██╗ ██╔════╝ ╚██╗██╔╝"
		@echo "       ██████╔╝ ██║ ██████╔╝ █████╗    ╚███╔╝ "
		@echo "       ██╔═══╝  ██║ ██╔═══╝  ██╔══╝    ██╔██╗ "
		@echo "       ██║      ██║ ██║      ███████╗ ██╔╝ ██╗"
		@echo "       ╚═╝      ╚═╝ ╚═╝      ╚══════╝ ╚═╝  ╚═╝"
		@${CC} $(INCLUDE) ${OBJS} -o ${NAME}
		@echo "\033[31m      ----------༺ (\033[31m\033[32mPIPEX Compiled!\033[31m)༻----------\n"

${NAMEB}: ${BONS}
		@echo "\033[33m-------------------- Compiling BONUS... --------------------"
		@echo " "
		@echo "\033[32m       ██████╗  ██╗ ██████╗  ███████╗ ██╗  ██╗"
		@echo "       ██╔══██╗ ██║ ██╔══██╗ ██╔════╝ ╚██╗██╔╝"
		@echo "       ██████╔╝ ██║ ██████╔╝ █████╗    ╚███╔╝ "
		@echo "       ██╔═══╝  ██║ ██╔═══╝  ██╔══╝    ██╔██╗ "
		@echo "       ██║      ██║ ██║      ███████╗ ██╔╝ ██╗"
		@echo "       ╚═╝      ╚═╝ ╚═╝      ╚══════╝ ╚═╝  ╚═╝"
		@${CC} $(INCLUDE) ${BONS} -o ${NAMEB}
		@echo "\033[31m༺ (\033[31m\033[32mPIPEX_BONUS Compiled!\033[31m)༻\n"


bonus: ${NAMEB}

m : ${NAME} ${NAMEB}

clean:
	@echo "\033[33m     Clean  ALL ..."
	@echo " "
	@echo "\033[31m       ██████╗  ██╗ ██████╗  ███████╗ ██╗  ██╗"
	@echo "       ██╔══██╗ ██║ ██╔══██╗ ██╔════╝ ╚██╗██╔╝"
	@echo "       ██████╔╝ ██║ ██████╔╝ █████╗    ╚███╔╝ "
	@echo "       ██╔═══╝  ██║ ██╔═══╝  ██╔══╝    ██╔██╗ "
	@echo "       ██║      ██║ ██║      ███████╗ ██╔╝ ██╗"
	@echo "       ╚═╝      ╚═╝ ╚═╝      ╚══════╝ ╚═╝  ╚═╝"
	@rm -f	$(OBJS) $(BONS)

fclean: clean
	@rm -f	$(NAME) $(NAMEB)
	@echo "\033[36mEverything is cleaned! \033[32m✓\n"

re: fclean all

reb : fclean all bonus

.PHONY: all clean fclean re