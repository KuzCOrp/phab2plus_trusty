/*
 * Copyright 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TRUSTY_APP_KEYMASTER_TRUSTY_KEYMASTER_CONTEXT_H_
#define TRUSTY_APP_KEYMASTER_TRUSTY_KEYMASTER_CONTEXT_H_

#include <stdlib.h>

#include <UniquePtr.h>

#include <keymaster/keymaster_context.h>

#include "trusty_keymaster_enforcement.h"

namespace keymaster {

class KeyFactory;

static const int kAuthTokenKeySize = 32;

class TrustyKeymasterContext : public KeymasterContext {
  public:
    TrustyKeymasterContext();

    KeyFactory* GetKeyFactory(keymaster_algorithm_t algorithm) const override;
    OperationFactory* GetOperationFactory(keymaster_algorithm_t algorithm,
                                          keymaster_purpose_t purpose) const override;
    keymaster_algorithm_t* GetSupportedAlgorithms(size_t* algorithms_count) const override;

    keymaster_error_t CreateKeyBlob(const AuthorizationSet& key_description,
                                    keymaster_key_origin_t origin,
                                    const KeymasterKeyBlob& key_material, KeymasterKeyBlob* blob,
                                    AuthorizationSet* hw_enforced,
                                    AuthorizationSet* sw_enforced) const override;

    keymaster_error_t ParseKeyBlob(const KeymasterKeyBlob& blob,
                                   const AuthorizationSet& additional_params,
                                   KeymasterKeyBlob* key_material, AuthorizationSet* hw_enforced,
                                   AuthorizationSet* sw_enforced) const override;

    keymaster_error_t AddRngEntropy(const uint8_t* buf, size_t length) const override;

    keymaster_error_t GenerateRandom(uint8_t* buf, size_t length) const override;

    keymaster_error_t GetAuthTokenKey(keymaster_key_blob_t* key) const;

    KeymasterEnforcement* enforcement_policy() /* override */ { return &enforcement_policy_; }

  private:
    bool SeedRngIfNeeded() const;
    bool ShouldReseedRng() const;
    bool ReseedRng();
    bool InitializeAuthTokenKey();
    keymaster_error_t DeriveMasterKey(KeymasterKeyBlob* master_key) const;

    TrustyKeymasterEnforcement enforcement_policy_;

    UniquePtr<KeyFactory> rsa_factory_;
    UniquePtr<KeyFactory> ec_factory_;

    UniquePtr<uint8_t[]> master_key_;
    size_t root_of_trust_size_;
    bool rng_initialized_;
    mutable int calls_since_reseed_;
    uint8_t auth_token_key_[kAuthTokenKeySize];
    bool auth_token_key_initialized_;
};

}  // namespace keymaster

#endif  // TRUSTY_APP_KEYMASTER_TRUSTY_KEYMASTER_CONTEXT_H_
