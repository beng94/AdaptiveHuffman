all:
	g++ -std=c++11 \
		-g io/input_reader.cpp  \
		huffman/huffman.cpp huffman/huffman_encoder.cpp huffman/huffman_decoder.cpp \
		tree/binary_tree.cpp tree/node.cpp tree/nyt_node.cpp \
		main.cpp -o build/OUT
