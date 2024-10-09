# ChessBot
Learning about chess engines, and performance/optimization. Goal to eventually set my bot up with a lichess bot account and see its rating.

### Notes
- UCI command line interface should be compatible with most UCI GUIs (tested with cutechess)
- BitBoard internal representation
- Magic BitBoard move generation
- 110 byte lightweight board state
- copy/make move making scheme
- using `pthreads.h` so the bot must run in a POSIX environment like linux or macOS, for windows you will need a compatibility layer
- testing with cutechess (integration testing), and custom tests (unit testing)

### TODO
- improve makefiles


### References
#### These are a list of inspirations and resources I have learned from
- https://github.com/SebLague/Chess-Coding-Adventure (UCI interface, Magic Bitboards)
- https://www.chessprogramming.org/Main_Page (various)
- https://github.com/jhonnold/berserk (navigating the idiosyncrasies of the C programming language)
