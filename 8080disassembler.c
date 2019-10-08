/* 
 * Disassmebles a stream of 8080 hex code back into assembly language source. 
 */


/*
 * codebuffer is a valid pointer to 8080 assembly code
 * pc is the current offset into the code
 * 
 * returns the number of bytes of the op
 */
int dissasemble_8080( unsigned char *codebuffer, int pc)
{
    // Read the code into a buffer
    unsigned char* code = &codebuffer[pc];

    int opbytes = 1;
    printf ("%04x", pc);

    switch (*code)
    {
        // NOP - No Op
        case 0x00: printf("NOP"); break;
        // LXI RP - Load register pair immediate
        case 0x01: printf("LXI    B,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
        // STAX RP - Store A in register pair
        case 0x02: printf("STAX   B"); break;
        // INX RP - Increment register pair
        case 0x03: printf("INX    B"); break;
        // INR - Increment register
        case 0x04: printf("INR    B"); break;
        // DCR - Decrement register
        case 0x05: printf("DCR    B"); break;
        // MVI - Move imediate to register
        case 0x06: printf("MVI    B,#$%02x", code[1]); opbytes = 2; break;
        // RLC - Rotate A left
        case 0x07: printf("RLC"); break;
        // NOP - No Op
        case 0x08: printf("NOP"); break;
        // DAD RP - Add register pair to HL
        case 0x09: printf("DAD    B"); break;
        // LDAX RP - Load A with register pair
        case 0x0a: printf("LDAX   B"); break;
        // DCX RP - Decrement register pair
        case 0x0b: prinf("DCX     B"); break;
        // INR - Increment register
        case 0x0c: printf("INR    C"); break;
    }

}

