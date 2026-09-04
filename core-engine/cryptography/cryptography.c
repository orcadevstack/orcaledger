#include <stdio.h>
#include <string.h>
#include "cryptography.h"

/* SHA256 stub */
int orca_sha256(const uint8_t *input, size_t len, uint8_t output[32]) {
    printf("[CRYPTO] SHA256 hashing %zu bytes\n", len);
    memset(output, 0, 32);  // placeholder
    return 0;
}

/* AES-256-GCM encryption stub */
int orca_encrypt(
    const uint8_t *key,
    const uint8_t *plaintext, size_t plaintext_len,
    uint8_t *ciphertext,
    uint8_t *iv, size_t iv_len,
    uint8_t *tag
) {
    printf("[CRYPTO] Encrypting %zu bytes\n", plaintext_len);
    memcpy(ciphertext, plaintext, plaintext_len);  // placeholder
    memset(tag, 0, 16);
    return 0;
}

/* AES-256-GCM decryption stub */
int orca_decrypt(
    const uint8_t *key,
    const uint8_t *ciphertext, size_t ciphertext_len,
    uint8_t *plaintext,
    const uint8_t *iv, size_t iv_len,
    const uint8_t *tag
) {
    printf("[CRYPTO] Decrypting %zu bytes\n", ciphertext_len);
    memcpy(plaintext, ciphertext, ciphertext_len);  // placeholder
    return 0;
}

/* Digital signature stub */
int orca_sign(const uint8_t *priv_key, const uint8_t *msg, size_t msg_len,
              uint8_t *signature, size_t *sig_len) {
    printf("[CRYPTO] Signing %zu bytes\n", msg_len);
    memset(signature, 0, 64);  // placeholder
    *sig_len = 64;
    return 0;
}

/* Signature verification stub */
int orca_verify(const uint8_t *pub_key, const uint8_t *msg, size_t msg_len,
                const uint8_t *signature, size_t sig_len) {
    printf("[CRYPTO] Verifying signature (%zu bytes)\n", sig_len);
    return 1;  // always valid (placeholder)
}
