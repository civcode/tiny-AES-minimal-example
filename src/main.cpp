#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstring>

#include "aes.hpp"


using std::cout;
using std::endl;

void PrintData(uint8_t data[], uint8_t len) {
    printf("0x");
    for (int i=0; i<len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {

    uint8_t aes_key[16] = {0xf0, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
                           0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

    const char *seed_phrase = "This is my seed!";
    uint8_t seed_phrase_size = strlen(seed_phrase);
    
    uint8_t uds_seed[16] = {0, 16};

    for (int i=0; i<sizeof(uds_seed); i++) {
        if (i<seed_phrase_size) {
            uds_seed[i] = *(seed_phrase+i);
        }

    }    

    /* print data */
    cout << "AES key (128 bit):" << endl;
    PrintData(aes_key, sizeof(aes_key));
    cout << endl;

    cout << "seed:" << endl;
    cout << "seed_phrase = \"" << seed_phrase << "\"" << endl;
    cout << "seed_size = " << static_cast<int>(seed_phrase_size) << " bytes" << endl;
    cout << "uds_seed:" << endl;
    PrintData(uds_seed, sizeof(uds_seed));
    cout << endl;

    /* encrypt data */ 
    struct AES_ctx ctx;
    AES_init_ctx(&ctx, aes_key);
    AES_ECB_encrypt(&ctx, uds_seed); 

    cout << "encrypted uds_seed (= UDS Key):" << endl;
    PrintData(uds_seed, sizeof(uds_seed));
    cout << endl;

    /* decrypt data */
    AES_ECB_decrypt(&ctx, uds_seed);

    cout << "decrypted UDS key (must match uds_seed):" << endl;
    PrintData(uds_seed, sizeof(uds_seed));
    cout << endl;

    return 0;
}