all:
	g++ -Wall -g RedBlackTree.cpp RedBlackTreeTestsFirstStep.cpp -o RBT

run:
	./RBT

try: all run 