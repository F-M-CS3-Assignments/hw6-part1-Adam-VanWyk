all:
	g++ -Wall -g RedBlackTree.cpp RedBlackTreeTests.cpp -o RBT

run:
	./RBT

try: all run 