# Google Chrome Simulation

## Description
The purpsose of this program is to simulate how google chrome works behind the GUI a user sees. The program supports some of the most
common tasks (see section _Options_).<br/>
Written in C, Ubuntu 16.04.3 LTS.

## Options
After the program starts, user has to press one of the following number to execute the corresponding command:
1. *New session*: the first tab opens the opening address
2. *New tab*: adds a new tab in the current session. Tab opens the default opening address. The new tab is the current tab.
3. *Tab show*: Prints the address of the current site of the current tab
4. *Next tab*: current tab is the next tab, if exists
5. *Previous tab*: current tab is the previous tab, if exists
6. *Move left current tab*: swaps the current tab with the one in the left of the current tab, if exists
7. *Move right current tab*: swaps the current tab with the one in the right of the current tab, if exists
8. *Change opening address*: changes the default opening address
9. *Show opening address*: prints the opening address
10. *Next site*: goes to the next site of current tab's list (browser's right arrow button)
11. *Previous site*: goes to the previous site of current tab's list (browser's left arrow button)
12. *Show site address*: prints the address of the current site
13.*Close tab*: closes current tab
14. *Close session*: closes the browser (all the tabs)
15. *Type new address*: type new address in the current tab. As a result, the forward/right button is disabled 
16. *Exit*: closes the program

## Makefile
 - `make` to compile
 - `make clean` to delete the object files and the executable
 - `make run` to execute the program
 - `make check` to run valgrind to check for memory leaks
