# blokus project
Play blokus with computer, which will be smarter as more work put into it

# development stage
## stage 1
each color plays purely random 
## stage 2
use Monte Carlo Tree search to find the best move every time
## stage 3
generate large amount of game play data and train classfier (Neural network, etc.) on good / bad move
## stage 4
reinforcement learning --> smarter AI in while playing (memory-based recurrent neural network)
## stage 5
algorithmic game theory based AI --> could form team / foe with different colors, collaborating or sabataging collaboration of AI agents
## stage 6
deploy game on server using Heroku
## stage 7
do some other projects (such as flying Alexa networks with emotion detection [already purchased hardware])

# development tasks 
## stage 1
AI agent - DONE

human player interface - NOT STARTED

Refactor code for future dev - NOT STARTED

# how to run
g++ -std=c++11 -Wall -Werror -pedantic -Wextra -Wconversion -O3 main.cpp grid.cpp shape.cpp player.cpp game.cpp -o blokus && ./blokus


