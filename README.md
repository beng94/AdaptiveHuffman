# AdaptiveHuffman
This is a demo Adaptive Huffman encoder and decoder for educational puposes written in C++.

Adaptive Huffman coding is an adaptive coding technique based on Huffman coding. It permits building the code as the symbols are being transmitted, having no initial knowledge of source distribution, that allows one-pass encoding and adaptation to changing conditions in data.
The benefit of one-pass procedure is that the source can be encoded in real time.

# Usage
- Compile the program using `make`. It will generate a binary in build/OUT.
- Modify `test.txt` according to the text to be encoded.
- Execute the program, by running `./OUT`.
- Encoded text will be written to `encoded.txt`, the decoded one will be available in `decoded.txt`.

# Example

# Reference
- https://en.wikipedia.org/wiki/Adaptive_Huffman_coding
- https://www.cs.duke.edu/csed/curious/compression/adaptivehuff.html
- https://www.youtube.com/watch?v=JjRDCdoOfqk&t=2s
- https://www.youtube.com/watch?v=mv8ON4jUmDE
