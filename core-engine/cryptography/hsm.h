#ifndef ORCA_HSM_H
#define ORCA_HSM_H

#include <stddef.h>
#include <stdint.h>

/* Connect to HSM */
int hsm_connect(const char *device);

/* Disconnect */
void hsm_disconnect();

/* Generate key inside HSM */
int hsm_generate_key(uint8_t *key_out, size_t key_len);

/* Sign using HSM private key */
int hsm_sign(const uint8_t *msg, size_t msg_len,
             uint8_t *signature, size_t *sig_len);

/* Verify using HSM public key */
int hsm_verify(const uint8_t *msg, size_t msg_len,
               const uint8_t *signature, size_t sig_len);

#endif
