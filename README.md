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

test.txt:
`Hello world!`

encoded.txt in binary:
```
00000000: 10100100 00101100 10100101 10110010 11001011 01111110  .,...~
00000006: 01001000 00100010 11101111 01010010 11100101 01110010  H".R.r
0000000c: 11001001 10001001 00001011 00100001 01000000           ...!@
```

decoded.txt:
```
Hello world!
ool
```
The garbage at the end is due to the extra bits in the last byte, that is not used by the encoder.


# Reference
- https://en.wikipedia.org/wiki/Adaptive_Huffman_coding
- https://www.cs.duke.edu/csed/curious/compression/adaptivehuff.html
- https://www.youtube.com/watch?v=JjRDCdoOfqk&t=2s
- https://www.youtube.com/watch?v=mv8ON4jUmDE
