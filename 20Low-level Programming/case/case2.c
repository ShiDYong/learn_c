/********************************************************************************
* @author: mason shi
* @date: 2023/9/17 21:08
* @version: 1.0
* @description: 在C语言中位使用的领域简单介绍，具体可以根据对应的领域进行拓展
********************************************************************************/
int main(void) {
    /*  In the C language, bits are fundamental units of information and are used for various purposes, including low-level hardware manipulation,
     * data compression, encoding, and more. Here are some main uses of bits in C, along with examples to illustrate their applications:
     1. Bitwise Operations:
      Bitwise operations, including AND (&), OR (|), XOR (^), NOT (~), left shift (<<), and right shift (>>), are commonly used for manipulating
      individual bits within integers. These operations are often used in low-level programming and embedded systems.
       Example: Setting, clearing, and toggling bits.
  */
    unsigned int data = 0x0A;  // Binary: 00001010
    // Set the 3rd bit
    data |= (1 << 3);  // Binary: 00011010
    // Clear the 2nd bit
    data &= ~(1 << 2);  // Binary: 00011000
    // Toggle the 4th bit
    data ^= (1 << 4);  // Binary: 00111000
    /*2.Flags and State Representation:
       Bits are often used to represent flags or states within a data structure. Each bit can represent a specific attribute,
       setting, or state, allowing for efficient storage and retrieval of information.
       Example: Storing file attributes using bits.
     * */
#define READ_PERMISSION  (1 << 0)  // 00000001
#define WRITE_PERMISSION (1 << 1)  // 00000010
#define EXECUTE_PERMISSION (1 << 2)  // 00000100

    unsigned char fileAttributes = 0;
    fileAttributes |= READ_PERMISSION;
    fileAttributes |= WRITE_PERMISSION;
    /*
     * 3.Data Compression:
     * Bits are used in data compression algorithms to represent data more efficiently, reducing storage space or transmission
     * bandwidth. Techniques like Huffman coding and Run-Length Encoding rely on manipulating bits to achieve com
     * */
    struct HuffmanNode {
        char data;
        unsigned int frequency;
        struct HuffmanNode *left;
        struct HuffmanNode *right;
    };
    /*4.Data Encryption:
     * Cryptographic algorithms often manipulate bits to encrypt and decrypt data securely. XOR operations, bit rotations,
     * and substitutions are commonly used in encryption algorithms.
      Example: XOR-based encryption.
     * */
    char plaintext = 'A';  // Binary: 01000001
    char key = 'K';        // Binary: 01001011
    char encrypted = plaintext ^ key;  // Binary: 00001010 (encrypted)
    char decrypted = encrypted ^ key;  // Binary: 01000001 (decrypted)
    /*5.Bitboards:
        In chess programming and board games, a bitboard is a data structure that uses bits to represent the positions
        of pieces on a chessboard efficiently. Bitwise operations are used to manipulate these boards quickly.
        Example: Representing a chessboard using bitboards.
     * */
    unsigned long long whitePawns = 0x000000000000FF00ULL;
    unsigned long long blackPawns = 0x00FF000000000000ULL;
    /*6.Device Control and I/O:
        In embedded systems and device control, bits are used to interact with hardware registers.
        Manipulating bits in these registers allows you to control peripherals such as GPIO pins, timers, and serial communication.
        Example: Configuring a GPIO pin as an output in an embedded system.
     * */
    // Register address for GPIO control
    //volatile uint64_t* GPIO_CTRL = (volatile uint64_t*)0x40020000;
    // Bitmask for setting the pin as an output
#define GPIO_OUTPUT_PIN (1 << 3)
    // Configure pin 3 as an output
    //  *GPIO_CTRL |= GPIO_OUTPUT_PIN;

}

void volatile_test() {
    //In C, the volatile keyword is used to indicate that a variable's value can be changed at any time,
    // without any action being taken by the code. This is typically used for variables that are subject to change
    // by external factors not controlled by the program itself. Common use cases for volatile variables include hardware
    // registers, memory-mapped I/O, and shared variables in multithreaded programs.
    //具体查看：https://en.wikipedia.org/wiki/Volatile_(computer_programming)

}