#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstring>

#include "aes.hpp"


using std::cout;
using std::endl;

void PrintData(uint8_t data[], uint8_t len) {
    for (int i=0; i<len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {

    uint8_t key[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
                       0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

    const char *seed_phrase = "This is my seed!";
    uint8_t seed_phrase_size = strlen(seed_phrase);
    
    uint8_t seed[16] = {0, 16};

    for (int i=0; i<sizeof(seed); i++) {
        if (i<seed_phrase_size) {
            seed[i] = *(seed_phrase+i);
        }

    }    

    /* print data */
    cout << "key:" << endl;
    PrintData(key, sizeof(key));
    cout << endl;

    cout << "seed:" << endl;
    cout << "seed_phrase = " << seed_phrase << endl;
    cout << "seed_size = " << static_cast<int>(seed_phrase_size) << endl;
    PrintData(seed, sizeof(seed));
    cout << endl;

    /* encrypt seed */ 
    struct AES_ctx ctx;
    AES_init_ctx(&ctx, key);
    AES_ECB_encrypt(&ctx, seed);

    cout << "encrypted seed (=key):" << endl;
    PrintData(seed, sizeof(seed));
    cout << endl;

    /* decrypt key */
    AES_ECB_decrypt(&ctx, seed);

    cout << "decrypted key (=seed):" << endl;
    PrintData(seed, sizeof(seed));
    cout << endl;

    return 0;
}