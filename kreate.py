# * PROJ
# * Author: Jonas S.
# * Date: 11/07/21
# ! OBJECTIVE
# ? CREATE A BASIC RUNNING PROJECT 
# ? CREATE SIMPLE C OR HEADER FILE WITH HEADERS
# ? CREATE MAKEFILE
# ! NEED COLORAMA AND OS




import colorama
from colorama import Fore, Back


#HARD CODED STUFF
NAME = "Jonas S."
colorama.init()

# ! FILE CREATION
def createFile(fileName, content):
	with open(f"{fileName}", 'w', encoding = 'utf-8') as f:
		f.write(content)

def createHeaderFile(fileName):
	from datetime import datetime
	import os
	from os import mkdir

	now = datetime.now() # current date and time

	content =   (
					"/*\n"
					f"\t* HEADER {fileName.upper()}\n"
					f"\t* Author : {NAME}\n"
					f"\t* Date   : {now.strftime('%d/%m/%Y')}\n"
					"\t! DESCRIPTION\n"
					"*/\n\n"
					f"#ifndef _{fileName.upper()}_H_\n"
					f"#define _{fileName.upper()}_H_\n\n"
					"// DEFINES\n\n"
					"// PROTOTYPE FUNCTIONS\n\n"
					"#endif"
				)

	if not os.path.exists('include'):
		mkdir('include')
	createFile(f"include/{fileName}.h", content)

def createCodeFile(fileName):
	from datetime import datetime
	from datetime import datetime
	import os
	from os import mkdir
	
	now = datetime.now() # current date and time

	content =   (
					"/*\n"
					f"\t* CODE {fileName.upper()}\n"
					f"\t* Author : {NAME}\n"
					f"\t* Date   : {now.strftime('%d/%m/%Y')}\n"
					"\t! DESCRIPTION\n"
					"*/\n\n"
				)

	# add basic printf if main
	if fileName == "main":
		content += "#include <stdio.h>\n\nint main()\n{\n\tprintf(\"ISSOU\\n\");\n\treturn 0;\n}"
	
	if not os.path.exists('src'):
		mkdir('src')
	createFile(f"src/{fileName}.c", content)

def createMakefile():
	content =   (
					"CC       := gcc\n"
					"CC_FLAGS := -Wall -Wextra\n\n"

					"BIN     	:= bin\n"
					"SRC     	:= src\n"
					"INCLUDE 	:= include\n"
					"LIB     	:= lib\n"
					"LIBRARIES   := 		#Library flags like -lm -lncurses\n"
					"EXECUTABLE  := main\n\n"
					
					"all: $(BIN)/$(EXECUTABLE)\n\n"

					"run: clean all\n"
					"	clear\n"
					"	@echo \"🚀 Executing...\"\n"
					"	./$(BIN)/$(EXECUTABLE)\n\n"

					"$(BIN)/$(EXECUTABLE): $(SRC)/*.c\n"
					"	@echo \"🚧 Building...\"\n"
					"	$(CC) $(CC_FLAGS) -I $(INCLUDE) -L $(LIB) $^ -o $@ $(LIBRARIES)\n\n"

					"clean:\n"
					"	@echo \"🧹 Clearing...\"\n"
					"	-rm $(BIN)/*\n\n"

				)
	createFile("Makefile", content)

def createDirStructure():
	import os
	from os import mkdir

	if not os.path.exists('bin'):
		mkdir('bin')
	if not os.path.exists('build'):
		mkdir('build')
	if not os.path.exists('include'):
		mkdir('include')
	if not os.path.exists('src'):
		mkdir('src')

# ! MENU CREATION
def createCompleteProject():
	# Base structure (SRC, BUILD, INCLUDE, BIN)
	createDirStructure()
	print(f"{Fore.GREEN}+ BASIC STRUCTURE CREATED{Fore.RESET}")
	# Makefile
	createMakefile()
	print(f"{Fore.GREEN}+ MAKEFILE CREATED{Fore.RESET}")
	# Main 
	createCodeFile("main")
	print(f"{Fore.GREEN}+ MAIN.C FILE CREATE{Fore.RESET}")

def createCodeHeader(name):
	# Code
	createCodeFile(name)
	print(f"{Fore.GREEN}+ CODE FILE CREATED{Fore.RESET}")
	# Header
	createHeaderFile(name)
	print(f"{Fore.GREEN}+ HEADER FILE CREATED{Fore.RESET}")



# ! MENU
def menu():
	choice = input(
	"1 - COMPLETE PROJECT                 \n"
	"2 - CODE + HEADER                    \n"
	"3 - CODE ONLY                        \n"
	"4 - HEADER ONLY                      \n"
	"5 - MAKEFILE ONLY                    \n"
	"\n"

	)

	# PROJECT
	if choice == '1': 
		print(f"{Fore.BLUE}FULL PROJECT IS BEING CREATED.{Fore.RESET}")
		createCompleteProject()

	# CODE + HEADER
	elif choice == '2':
		print(f"{Fore.BLUE}A CODE AND HEADER FILE ARE BEING CREATED.{Fore.RESET}")
		createCodeHeader(input("WHAT FILE NAME DO YOU WANT : "))		
	
	# CODE 
	elif choice == '3':
		print(f"{Fore.BLUE}A CODE FILE IS BEING CREATED.{Fore.RESET}")
		createCodeFile(input("WHAT FILE NAME DO YOU WANT : "))
		print(f"{Fore.GREEN}+ CODE FILE CREATED{Fore.RESET}")

	# HEADER
	elif choice == '4':
		print(f"{Fore.BLUE}A HEADER FILE IS BEING CREATED.{Fore.RESET}")
		createHeaderFile(input("WHAT FILE NAME DO YOU WANT : "))	
		print(f"{Fore.GREEN}+ CODE FILE CREATED{Fore.RESET}")

	# MAKEFILE
	elif choice == '5':
		print(f"{Fore.BLUE}A HEADER FILE IS BEING CREATED.")
		createMakefile()		
		print(f"{Fore.GREEN}+  MAKEFILE CREATED{Fore.RESET}")

if __name__ == "__main__":
	menu()



