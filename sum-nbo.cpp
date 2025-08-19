#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h> // for htons, htonl

int main(int argc, char* argv[]) {
    uint32_t num;
    uint32_t total = 0;
    FILE *fp;

    for (int i = 1; i < argc; i++) {
        // file open (binary read Mod)
        fp = fopen(argv[i], "rb");
        if (fp == NULL) {
            printf("Error: Could not file open: %s\n", argv[i]);
            return 1;
        }

        // 4byte check
        if (fread(&num, sizeof(num), 1, fp) != 1) {
            printf("Error: Could not 4bytes from file: %s\n", argv[i]);
            fclose(fp);
            return 1;
        }

        // change byte order
        uint32_t host_num = ntohl(num);
        total += host_num;

        // print
        if (i > 1) { printf(" + "); }
        printf("%u(0x%08x)", host_num, host_num);
        fclose(fp);
    }
    printf(" = %u(0x%08x)\n", total, total);
}
