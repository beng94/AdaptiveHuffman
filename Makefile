all:
	g++ -std=c++11 -g \
		io/binary_reader.cpp io/char_reader.cpp io/binary_writer.cpp io/char_writer.cpp \
		huffman/huffman.cpp huffman/huffman_encoder.cpp huffman/huffman_decoder.cpp \
		tree/binary_tree.cpp tree/node.cpp tree/nyt_node.cpp \
		data/data.cpp \
		main.cpp -o build/OUT
