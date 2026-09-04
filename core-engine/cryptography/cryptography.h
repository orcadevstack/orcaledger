#ifndef ORCA_CRYPTOGRAPHY_H
#define ORCA_CRYPTOGRAPHY_H

#include <stddef.h>
#include <stdint.h>

/* Hashing */
int orca_sha256(const uint8_t *input, size_t len, uint8_t output[32]);

/* Symmetric encryption (AES-256-GCM) */
int orca_encrypt(
    const uint8_t *key,
    const uint8_t *plaintext, size_t plaintext_len,
    uint8_t *ciphertext,
    uint8_t *iv, size_t iv_len,
    uint8_t *tag
);

int orca_decrypt(
    const uint8_t *key,
    const uint8_t *ciphertext, size_t ciphertext_len,
    uint8_t *plaintext,
    const uint8_t *iv, size_t iv_len,
    const uint8_t *tag
);

/* Digital signatures */
int orca_sign(const uint8_t *priv_key, const uint8_t *msg, size_t msg_len,
              uint8_t *signature, size_t *sig_len);

int orca_verify(const uint8_t *pub_key, const uint8_t *msg, size_t msg_len,
                const uint8_t *signature, size_t sig_len);

#endif
