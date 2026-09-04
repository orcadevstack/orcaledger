#include <stdio.h>
#include <string.h>
#include "hsm.h"

static int connected = 0;

int hsm_connect(const char *device) {
    printf("[HSM] Connecting to device: %s\n", device);
    connected = 1;
    return 0;
}

void hsm_disconnect() {
    printf("[HSM] Disconnecting HSM\n");
    connected = 0;
}

int hsm_generate_key(uint8_t *key_out, size_t key_len) {
    if (!connected) return -1;
    printf("[HSM] Generating %zu-byte key\n", key_len);
    memset(key_out, 0xAB, key_len);  // placeholder
    return 0;
}

int hsm_sign(const uint8_t *msg, size_t msg_len,
             uint8_t *signature, size_t *sig_len) {
    if (!connected) return -1;
    printf("[HSM] Signing %zu bytes\n", msg_len);
    memset(signature, 0xCD, 64);  // placeholder
    *sig_len = 64;
    return 0;
}

int hsm_verify(const uint8_t *msg, size_t msg_len,
               const uint8_t *signature, size_t sig_len) {
    if (!connected) return -1;
    printf("[HSM] Verifying signature (%zu bytes)\n", sig_len);
    return 1;  // always valid (placeholder)
}
